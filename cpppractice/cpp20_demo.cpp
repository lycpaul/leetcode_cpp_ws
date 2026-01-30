// c++cpp20_demo.cpp

#include <algorithm>
#include <chrono>
#include <format>
#include <iostream>
#include <numbers>
#include <ranges>
#include <span>
#include <vector>

// ---------- Feature 1: concepts ----------
template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

template<Numeric T>
T average(const std::span<T> data)
{
    T sum = 0;
    for (T val : data)
        sum += val;
    return sum / static_cast<T>(data.size());
}

void demo_concepts()
{
    std::cout << "\n=== concepts ===\n";

    std::vector<double> doubles{1.1, 2.2, 3.3};
    std::cout << std::format("Average: {:.2f}\n",
                             average(doubles)); // compile error if non-numeric!

    // Fails at compile: average(std::vector<std::string>{"a", "b"})
}

// ---------- Feature 2: ranges (views, filter, transform) ----------
void demo_ranges()
{
    std::cout << "\n=== ranges ===\n";

    std::vector<int> vec{1, 2, 3, 4, 5, 6};

    // Lazy composable views (no copies!)
    auto evens = vec | std::views::filter([](int n) { return n % 2 == 0; })
                 | std::views::transform([](int n) { return n * n; });

    for (int sq : evens) {
        std::cout << sq << " "; // 4 16 36
    }
    std::cout << "\n";

    // reverse order print
    for (const int n : vec | std::views::reverse) {
        std::cout << n << " "; // 6 5 4 3 2 1
    }
}

// ---------- Feature 3: std::format ----------
void demo_format()
{
    std::cout << "\n=== std::format ===\n";

    std::cout << std::format("Pi ≈ {:.3f}, e ≈ {:.3f}\n",
                             std::numbers::pi_v<double>,
                             std::numbers::e_v<double>);

    int x = 42, y = 1234567;
    std::cout << std::format("x={:>5}, y={:,}\n", x, y); // right-align, thousands sep
}

// ---------- Feature 4: std::span (non-owning view) ----------
void print_span(std::span<const int> data)
{
    std::cout << "Span size=" << data.size() << ": [";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << (i + 1 < data.size() ? ", " : "");
    }
    std::cout << "]\n";
}

void demo_span()
{
    std::cout << "\n=== std::span ===\n";

    std::vector<int> vec{10, 20, 30, 40};
    print_span(vec);                          // full
    print_span(std::span{vec}.subspan(1, 2)); // [20, 30]
}

// ---------- Feature 5: chrono calendar (date literals) ----------
void demo_chrono()
{
    std::cout << "\n=== chrono calendar ===\n";

    using namespace std::chrono;
    auto now = sys_days{2026y / January / 29} + 15h + 30min; // C++20 literals
    std::cout << std::format("Vancouver time: {} ({})\n",
                             now,
                             year_month_day{now}); // formatted output
}

// ---------- Feature 6: constinit & consteval ----------
constinit int global_counter = 0; // guaranteed init before main (thread-safe)

consteval int square(int x)
{ // always compile-time
    return x * x;
}

constexpr int arr[] = {square(3), square(4)}; // consteval used here

void demo_const()
{
    std::cout << "\n=== constinit & consteval ===\n";

    std::cout << "arr[0]=" << arr[0] << ", arr[1]=" << arr[1] << "\n";
    std::cout << "global_counter=" << ++global_counter << "\n";
}

// ---------- main ----------
int main()
{
    std::cout << "C++20 feature tour\n";

    demo_concepts();
    demo_ranges();
    demo_format();
    demo_span();
    demo_chrono();
    demo_const();

    std::cout << "\nDone.\n";
    return 0;
}
