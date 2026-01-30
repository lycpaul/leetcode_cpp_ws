// c++14_demo.cpp

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ---------- Feature 1: auto return type deduction ----------
auto add(int a, int b) -> int
{ // trailing return (C++11), but auto deduced
    return a + b;
}

auto compute_sum(const std::vector<int> &vec)
{ // C++14: auto deduces return type
    int sum = 0;
    for (int v : vec)
        sum += v;
    return sum; // deduces int
}

void demo_auto_return()
{
    std::cout << "\n=== auto return type deduction ===\n";
    std::cout << "add(3, 4) = " << add(3, 4) << "\n";

    std::vector<int> vec{1, 2, 3};
    std::cout << "sum(vec) = " << compute_sum(vec) << "\n";
}

// ---------- Feature 2: generic lambdas ----------
void demo_generic_lambda()
{
    std::cout << "\n=== generic lambdas ===\n";

    // C++14: auto parameters make lambda templated
    auto generic_max = [](auto a, auto b) { return (a > b ? a : b); };

    std::cout << "max(5, 3) = " << generic_max(5, 3) << "\n";
    std::cout << "max(2.7, 3.1) = " << generic_max(2.7, 3.1) << "\n";
    std::cout << "max(std::string(\"abc\"), std::string(\"def\")) = "
              << generic_max(std::string("abc"), std::string("def")) << "\n";
}

// ---------- Feature 3: lambda capture initializers ----------
void demo_lambda_capture()
{
    std::cout << "\n=== lambda capture initializers ===\n";

    int offset = 10;

    // C++14: capture with initializer (even if 'offset' not in scope later)
    auto adder = [offset = 100](int x) { return x + offset; };

    std::cout << "adder(5) = " << adder(5) << "\n"; // 105

    // Mutable capture example
    auto counter = [count = 0]() mutable { return ++count; };
    std::cout << "counter() = " << counter() << "\n"; // 1
    std::cout << "counter() = " << counter() << "\n"; // 2
}

// ---------- Feature 4: decltype(auto) ----------
int get_value()
{
    return 42;
}
int &get_ref()
{
    static int val = 0;
    return val;
}

void demo_decltype_auto()
{
    std::cout << "\n=== decltype(auto) ===\n";

    auto val1 = get_value();           // int (copy)
    decltype(auto) val2 = get_value(); // int (copy, but exact decltype)

    auto ref1 = get_ref();           // int& -> int (copy! loses ref)
    decltype(auto) ref2 = get_ref(); // int& (preserves reference)

    ref2 = 99;
    std::cout << "get_ref() after ref2=99: " << get_ref() << "\n"; // 99
}

// ---------- Feature 5: std::make_unique ----------
class DemoObj
{
public:
    int value;
    DemoObj(int v)
        : value(v)
    {
        std::cout << "DemoObj(" << v << ") created\n";
    }
    ~DemoObj() { std::cout << "DemoObj destroyed\n"; }
};

void demo_make_unique()
{
    std::cout << "\n=== std::make_unique ===\n";

    // C++14: safe unique_ptr factory (no exception leak risk)
    auto ptr = std::make_unique<DemoObj>(42);
    std::cout << "ptr->value = " << ptr->value << "\n";

    // Goes out of scope: auto-destroyed
}

// ---------- Feature 6: digit separators & binary literals ----------
void demo_literals()
{
    std::cout << "\n=== digit separators & binary literals ===\n";

    auto big_num = 1'000'000'000ULL; // easier to read
    std::cout << "1 billion = " << big_num << "\n";

    auto mask = 0b10101010'11110000; // binary literal + separator
    std::cout << "binary mask = " << std::hex << mask << std::dec << "\n";
}

// ---------- main ----------
int main()
{
    std::cout << "C++14 feature tour\n";

    demo_auto_return();
    demo_generic_lambda();
    demo_lambda_capture();
    demo_decltype_auto();
    demo_make_unique();
    demo_literals();

    std::cout << "\nDone.\n";
    return 0;
}
