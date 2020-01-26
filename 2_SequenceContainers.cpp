#include <iostream>
#include <array>
#include <deque>
#include <list> // Doubly linked list.
#include <vector>

using namespace std;

template<typename container>
void Output(const container& cont)
{
    for (const auto& el : cont)
        cout << el << " ";
    cout << endl;
}

// Fast insert/remove at the end.
// Slow insert/remove at the begging or in the middle: O(n).
// Slow search: O(n).
void Vector()
{
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    cout << vec[2] << endl; // No range check.
    cout << vec[2] << endl; // Throw range_error if out of range.

    // Slower then for iteration.
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    // Faster then native for loop.
    for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    // As fast as iteration.
    for (const int& num : vec)
        cout << num << " ";
    cout << endl;

    vec.clear();
    vector<int> vec2{ 1, 2, 3 };
    vec.swap(vec2);

    if (vec2.empty())
        cout << "vec2 is empty now" << endl;

    Output(vec);
}

// Fast insert/remove at any place O(1).
// Slow search: O(n).
// No random access, no [] operator.
void List()
{
    list<int> lst = { 5, 7, 9 };
    lst.push_back(6);  // 5 7 9 6
    lst.push_front(4); // 4 5 7 9 6

    list<int>::iterator itr = find(lst.begin(), lst.end(), 7); // itr -> 7
    // Insert 8 before itr.
    lst.insert(itr, 8); // 4 5 8 7 9 6
    itr++; // itr -> 9
    lst.erase(itr); // 4 5 8 7 6
    Output(lst);

    // splice funtion.
    // http://www.cplusplus.com/reference/list/list/splice/
}

// Fast insert/remove at the begging and the end.
// Slow insert/remove in the middle: O(n).
// Slow search: O(n).
void Deque()
{
    deque<int> deq = { 4, 6, 7 };
    deq.push_back(2);  // 4 6 7 3
    deq.push_front(3); // 2 4 6 7 3
    cout << deq[1] << endl;
}

void PrintArray(array<int, 10> a)
{
    for (const auto& num : a)
        cout << num << " ";
    cout << endl;
}

void Array()
{
    array<int, 10> a = { 1, 2, 3 };
    cout << a.size() << endl;
    PrintArray(a);

    array<int, 20> b;
    b.fill(1);

    // Can not do this. The function accepts a different type.
    // PrintArray(b);
}

int main()
{
    Vector();
    List();
    Deque();
    Array();

    return 0;
}
