// cpp11_demo.cpp

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ---------- Feature 1: auto & decltype ----------
auto add(int a, int b) -> int
{ // trailing return type (C++11)
    return a + b;
}

decltype(42) get_forty_two()
{ // decltype deduces int
    return 42;
}

void demo_auto_decltype()
{
    std::cout << "\n=== auto & decltype ===\n";
    auto x = add(3, 4);      // auto = int
    decltype(3.14) y = 3.14; // double
    decltype(x) z = x;

    std::cout << "auto x = " << x << "\n";
    std::cout << "decltype(3.14) y = " << y << "\n";
    std::cout << "decltype(x) z = " << z << "\n";
}

// ---------- Feature 2: range-based for loops ----------
void demo_range_for()
{
    std::cout << "\n=== range-based for loops ===\n";

    std::vector<int> vec{1, 2, 3, 4, 5};
    int sum = 0;

    // Clean iteration (no iterators!)
    for (int val : vec) {
        sum += val;
    }
    std::cout << "sum = " << sum << "\n";

    // Modifiable refs
    for (int &val : vec) {
        ++val;
    }
    std::cout << "vec now: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// ---------- Feature 3: lambda expressions ----------
void demo_lambda()
{
    std::cout << "\n=== lambda expressions ===\n";

    int factor = 10;
    std::vector<int> vec{1, 2, 3};

    // Capture by value/reference
    auto multiply = [factor](int x) { return x * factor; }; // [=] or [&] for all
    for (int val : vec) {
        std::cout << "multiply(" << val << ") = " << multiply(val) << "\n";
    }
}

// ---------- Feature 4: nullptr ----------
void demo_nullptr()
{
    std::cout << "\n=== nullptr ===\n";

    int *ptr = nullptr; // type-safe null (not 0)
    std::cout << "ptr == nullptr: " << (ptr == nullptr) << "\n";
}

// ---------- Feature 5: smart pointers ----------
struct DemoObj
{
    int value;
    DemoObj(int v)
        : value(v)
    {
        std::cout << "DemoObj(" << v << ") created\n";
    }
    ~DemoObj() { std::cout << "~DemoObj() destroyed\n"; }
};

void demo_smart_ptrs()
{
    std::cout << "\n=== smart pointers ===\n";

    // unique_ptr: exclusive ownership
    {
        auto up = std::make_unique<DemoObj>(
            1); // C++14 make_unique, but unique_ptr raw new ok in C++11
        std::cout << "unique_ptr value: " << up->value << "\n";
        // auto-destroys on scope exit
    } // destroyed here

    // shared_ptr: shared ownership
    std::shared_ptr<DemoObj> sp1 = std::make_shared<DemoObj>(2);
    {
        std::shared_ptr<DemoObj> sp2 = sp1; // refcount=2
        std::cout << "shared_ptr value: " << sp2->value << "\n";
    } // refcount=1
    // sp1 destroyed after main
}

// ---------- Feature 6: constexpr & static_assert ----------
constexpr int factorial(int n)
{
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

void demo_constexpr_assert()
{
    std::cout << "\n=== constexpr & static_assert ===\n";

    static_assert(factorial(5) == 120, "factorial(5) must be 120");
    std::cout << "factorial(5) = " << factorial(5) << "\n"; // compile-time computable
}

// ---------- main ----------
int main()
{
    std::cout << "C++11 feature tour\n";

    demo_auto_decltype();
    demo_range_for();
    demo_lambda();
    demo_nullptr();
    demo_smart_ptrs();
    demo_constexpr_assert();

    std::cout << "\nDone.\n";
    return 0;
}
