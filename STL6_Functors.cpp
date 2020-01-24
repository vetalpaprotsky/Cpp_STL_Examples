#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void addVal(int i, int val)
{
    cout << i + val << " ";
}

template<typename T>
void Output(const T container)
{
    for_each(container.begin(), container.end(), [](auto val) { cout << val << " "; });
    cout << endl;
}

double Pow(double a, double b)
{
    return pow(a, b);
}

class X
{
public:
    void operator()(const char* str)
    {
        cout << str << endl;
    }
};

class AddVal
{
private:
    int value;

public:
    AddVal(int val)
    {
        value = val;
    }
    void operator()(int& val)
    {
        val += value;
    }
};

// Last digit sort.
class LdLess
{
public:
    // This kind of function is called predicate.
    // A function of a functor that:
    //   1. Returns a boolean.
    //   2. Does no modify data.
    bool operator()(int a, int b) const
    {
        return a % 10 < b % 10;
    }
};

void Functors()
{
    X x;
    x("Hello World");

    vector<int> vec{ 1,2,3,4 };
    AddVal addVal(2);

    for_each(vec.begin(), vec.end(), addVal);
    for_each(vec.begin(), vec.end(), [](int val) { cout << val << " "; });
    cout << endl;

    // By default set it sorted with less<> predicate.
    // So myset1 == myset2.
    set<int> myset1 = { 3, 1, 25, 7, 12 }; // 1 3 7 12 25
    set<int, less<int>> myset2 = { 3, 1, 25, 7, 12 };
    set<int, LdLess> myset3 = { 3, 1, 25, 7, 12 }; // 1 12 3 25 7

    Output(myset1);
    Output(myset2);
    Output(myset3);
}

void Binding()
{
    set<int> myset = { 2, 3, 4, 5 };
    vector<int> vec;

    int x = multiplies<int>()(3, 4);
    cout << x << endl;

    transform(
        myset.begin(),
        myset.end(),
        back_inserter(vec),
        bind(multiplies<int>(), placeholders::_1, 10)
    );

    Output(vec);
    for_each(vec.begin(), vec.end(), bind(addVal, placeholders::_1, 2));
    cout << endl;

    set<int> st = { 3, 4, 1, 5, 7, 9 };
    deque<int> dq;
    copy_if(
        st.begin(),
        st.end(),
        back_inserter(dq),
        bind(
            logical_and<bool>(),
            bind(less<int>(), placeholders::_1, 20),
            bind(greater<int>(), placeholders::_1, 5)
        )
    );
    Output(dq);

    copy_if(
        st.begin(),
        st.end(),
        back_inserter(dq),
        [](int x) { return (x > 5) && (x < 20); }
    );
    Output(dq);
}

void FunctionToFunctor()
{
    set<double> myset = { 3.0, 4.0, 5.0, 9.0 };
    deque<double> d;
    // Transform Pow to functor f.
    auto f = function<double(double, double)>(Pow);
    // Either Pow or f can be used in this function.
    transform(myset.begin(), myset.end(), back_inserter(d), bind(f, placeholders::_1, 2.0));
    Output(d);
}

int main()
{
    Functors();
    Binding();
    FunctionToFunctor();

    return 0;
}
