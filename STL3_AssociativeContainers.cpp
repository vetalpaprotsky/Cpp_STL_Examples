#include <iostream>
#include <map>
#include <set>

using namespace std;

// Fast search: O(log(n)).
// Traversing is slow (compared to vector & deque).
// No random access, no [] operator.
void Set()
{
    set<int> myset;
    multiset<int> mymset;

    // Insert is O(log(n)).
    myset.insert(3); // 3
    myset.insert(1); // 1 3
    myset.insert(7); // 1 3 7

    set<int>::iterator it;
    it = myset.find(7); // Search is O(log(n)).
    // Sequence containers don't even have find() function.

    pair<set<int>::iterator, bool> ret;
    ret = myset.insert(3); // No element inserted.
    cout << *ret.first << " " << ret.second << endl;

    // First paramenter is a hint for insert() which might decrease insertion time.
    myset.insert(it, 9);
    myset.erase(it); // O(1)
    myset.erase(3);  // O(log(n))

    for (const auto& num : myset)
        cout << num << " ";
    cout << endl;

    // set/multiset: value of an element cannot be modified.
}

// Fast search: O(log(n)).
// Traversing is slow (compared to vector & deque).
// No random access, no [] operator.
void Map()
{
    map<char, int> mymap;
    multimap<char, int> mymmap;
    mymap.insert(pair<char, int>('A', 100));
    mymap.insert(make_pair('B', 200));

    map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, make_pair('C', 300)); // "it" is a hint.
    it = mymap.find('D'); // O(log(n))

    if (it == mymap.end())
        cout << "D - not found" << endl;

    for (const auto& pr : mymap)
        cout << pr.first << " => " << pr.second << endl;
    cout << endl;

    for (auto it = mymap.begin(); it != mymap.end(); it++)
        cout << it->first << " => " << it->second << endl;

    // map/multimap: key of an element cannot be modified.
}

int main()
{
    Set();
    Map();

    return 0;
}
