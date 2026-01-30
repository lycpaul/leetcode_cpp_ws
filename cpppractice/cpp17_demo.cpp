// c++17.cpp

#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <variant>

// ---------- Feature 1: std::string_view (cheap string "view") ----------
void print_header(std::string_view title)
{
    std::cout << "\n=== " << title << " ===\n";
}

// ---------- Feature 2: structured bindings ----------
std::map<int, std::string> make_id_name_map()
{
    return {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
}

void demo_structured_bindings()
{
    print_header("Structured bindings");

    auto id_name = make_id_name_map();

    // C++14 style:
    std::cout << "C++14 style:\n";
    for (const auto &elem : id_name) {
        std::cout << "id=" << elem.first << ", name=" << elem.second << "\n";
    }

    // C++17 structured bindings:
    std::cout << "\nC++17 structured bindings style:\n";
    for (const auto &[id, name] : id_name) { // binds key/value directly
        std::cout << "id=" << id << ", name=" << name << "\n";
    }
}

// ---------- Feature 3: std::optional (maybe there is a value) ----------
std::optional<int> find_id_by_name(std::string_view target,
                                   const std::map<int, std::string> &id_name)
{
    for (const auto &[id, name] : id_name) { // reuse structured bindings
        if (name == target) {
            return id; // found
        }
    }
    return std::nullopt; // not found
}

void demo_optional()
{
    print_header("std::optional");

    auto id_name = make_id_name_map();

    for (std::string_view query : {"Alice", "Zoe"}) {
        std::cout << "Looking up: " << query << " ... ";

        // `if (auto id = ...)` uses optional in a natural way
        if (auto id = find_id_by_name(query, id_name)) {
            std::cout << "found id=" << *id << "\n"; // operator*
        } else {
            std::cout << "not found\n";
        }
    }

    // value_or gives a default when empty
    std::optional<double> maybe_value; // empty
    std::cout << "maybe_value.value_or(3.14) = " << maybe_value.value_or(3.14) << "\n";
}

// ---------- Feature 4: std::variant (type‑safe union) ----------
using IntOrString = std::variant<int, std::string>;

IntOrString parse_token(std::string_view token)
{
    // tiny parser: if all digits, treat as int; otherwise string
    bool all_digits = !token.empty();
    for (char c : token) {
        if (c < '0' || c > '9') {
            all_digits = false;
            break;
        }
    }
    if (all_digits) {
        return static_cast<int>(std::stoi(std::string(token)));
    }
    return std::string(token);
}

// C++17 visitor + if constexpr
struct PrettyPrinter
{
    void operator()(int value) const { std::cout << "int{" << value << "}"; }
    void operator()(const std::string &value) const { std::cout << "string{\"" << value << "\"}"; }
};

void demo_variant_and_if_constexpr()
{
    print_header("std::variant + if constexpr");

    IntOrString a = parse_token("123");
    IntOrString b = parse_token("hello");

    auto print_with_if_constexpr = [](const IntOrString &v) {
        // visit + generic lambda + if constexpr
        std::visit(
            [](const auto &x) {
                if constexpr (std::is_same_v<decltype(x), int>) {
                    std::cout << "It's an int, doubled = " << (x * 2) << "\n";
                } else if constexpr (std::is_same_v<decltype(x), std::string>) {
                    std::cout << "It's a string, size = " << x.size() << "\n";
                }
            },
            v);
    };

    std::cout << "Using PrettyPrinter visitor: ";
    std::visit(PrettyPrinter{}, a);
    std::cout << ", ";
    std::visit(PrettyPrinter{}, b);
    std::cout << "\n";

    std::cout << "Using if constexpr visitor:\n";
    print_with_if_constexpr(a);
    print_with_if_constexpr(b);
}

// ---------- main ----------
int main()
{
    std::cout << "C++17 feature tour\n";

    demo_structured_bindings();
    demo_optional();
    demo_variant_and_if_constexpr();

    std::cout << "\nDone.\n";
    return 0;
}
