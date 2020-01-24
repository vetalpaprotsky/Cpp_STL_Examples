#include <algorithm>
#include <forward_list>
#include <iterator>
#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

bool isOdd(int i)
{
    return i % 2;
}

void Output(const vector<int>& vec)
{
    for (const auto& el : vec) cout << el << " ";
    cout << endl;
}

void Iterators()
{
    // 1. Random access iterators: vector, deque, array.
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7 };
    auto itr = vec.begin();
    itr = itr + 5;
    itr = itr - 4;

    auto itr1 = vec.begin();
    auto itr2 = vec.end();

    if (itr1 > itr2)
    {
        cout << "itr1 > itr2" << endl;
    }

    ++itr; // Faster then itr++.
    --itr;
    itr++;
    itr--;

    // 2. Bidirectional itetators: list, set/multiset, map/multimap.
    list<int> list = { 1, 2, 3 };
    auto it = list.begin();
    ++it;
    --it;

    // 3. Forward iterators: forward_list.
    // Unordered containers provide "at least" forward iterators.
    forward_list<int> forw_list = { 1, 2, 3 };
    auto i = forw_list.begin();
    ++i;

    // 4. Input and output iterators.
    int x = *i; // Input iterator property.
    *i = 100; // Output iterator property.
}

void ConstIterators()
{
    set<int> myset = { 2, 5, 5, 1, 9, 7, 3, 5, 0 };
    for (set<int>::const_iterator citr = myset.cbegin(); citr != myset.cend(); ++citr)
    {
        cout << *citr << " ";
        // *citr = 5; Error because of const_iterator.
    }
    cout << endl;

    for_each(myset.cbegin(), myset.cend(), [](auto a) { cout << a << " "; });
    cout << endl;
}

void AdvanceAndDistance()
{
    set<int> myset = { 2, 5, 5, 1, 9, 7, 3, 5, 0 };
    set<int>::iterator set_itr1 = myset.begin(), set_itr2 = myset.begin();

    // It works for non random access iterators as well.
    advance(set_itr1, 3);
    cout << *set_itr1 << endl;
    cout << distance(set_itr2, set_itr1) << endl;
}

void InsertIterators()
{
    vector<int> vec1 = { 4, 5 };
    vector<int> vec2 = { 12, 14, 16, 18 };
    vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
    insert_iterator<vector<int>> i_itr(vec2, it);

    copy(vec1.begin(), vec1.end(), i_itr);
    for (const auto& el : vec2) cout << el << " ";
    cout << endl;

    // Other insert iterators: back_insert_iterator, front_insert_iterator.
    // There also is inserter() function which is easier in use.
    // https://en.cppreference.com/w/cpp/iterator/inserter
}

void StreamIterators()
{
    vector<string> vec = { "Hello", "World", "\n" };
    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, " "));

    // Insert from keyboard to vec3.
    // copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(vec));

    // Insert from keyboard to cout(console).
    // copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, " "));
}

void ReverseIterators()
{
    vector<int> vec = { 4, 5, 6, 7 };
    reverse_iterator<vector<int>::iterator> ritr;
    for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
        cout << *ritr << " ";
    cout << endl;
}

void Algorithms()
{
    vector<int> vec = { 4, 2, 5, 1, 3, 9 };
    vector<int>::iterator itr = min_element(vec.begin(), vec.end());

    // Algorithms always process ranges in a half-open way.
    sort(vec.begin(), itr);  // 2 4 5 1 3 9
    reverse(itr, vec.end()); // 2 4 5 9 3 1

    cout << *itr << endl;
    Output(vec);

    vector<int> vec2(3);
    // vec2 needs to have at least space for 3 elements.
    // If it doesn't, then behavior is undefined.
    copy(vec.begin(), itr, vec2.begin());
    Output(vec2);

    vector<int> vec3;
    // Inserting instead of overwriting because of insert iterator.
    // It is returned by back_inserter() function.
    // Not efficient, because it inserts elements one by one.
    copy(vec.begin(), itr, back_inserter(vec3));
    Output(vec3);

    // More efficient and safe because of insert member function.
    vec3.insert(vec3.end(), itr, vec.end());
    Output(vec3);

    vector<int>::iterator it = find_if(vec.begin(), vec.end(), isOdd);
    cout << *it << endl;

    int arr[4] = { 6, 4, 7, 3 };
    // This function works as well because iterators behave like pointers.
    sort(arr, arr + 4);
}

int main()
{
    Iterators();
    ConstIterators();
    AdvanceAndDistance();

    InsertIterators();
    StreamIterators();
    ReverseIterators();

    Algorithms();

    return 0;
}
