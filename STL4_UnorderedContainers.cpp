#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void Foo(const unordered_map<char, string>& m)
{
    cout << m.at('F') << endl;
    // [] operator does not work because of const, that's why at() method is used.
    // cout << m['F'] << endl;
}

// Fastest search/insert: O(1).
// Unordered set/multiset: element value cannot be changed.
// Unordered map/multimap: element key cannot be changed.
void UnorderedSet()
{
    unordered_set<string> myset = { "Red", "Green", "Blue" };
    unordered_set<string>::const_iterator itr = myset.find("Green"); // O(1)

    if (itr != myset.end())
        cout << *itr << endl;

    myset.insert("Yellow"); // O(1)

    vector<string> vec = { "Purple", "Pink" };
    myset.insert(vec.begin(), vec.end());

    // Hash table specific APIs:
    cout << "Load factor = " << myset.load_factor() << endl;
    string x = "Red";
    cout << x << " is in bucket #" << myset.bucket(x) << endl;
    cout << "Total buckets #" << myset.bucket_count() << endl;
}

// Search time is O(1) but it can degrade to O(n).
// unordered_multimap does not have [] operator.
void UnorderedMap()
{
    unordered_map<char, string> day = { {'S',"Sunday"}, {'M',"Monday"} };

    cout << day['S'] << endl;    // No range check.
    cout << day.at('M') << endl; // Has range check.

    vector<int> vec = { 1,2,3 };
    // vec[5] = 5; Runtime error.

    day['W'] = "Wednesday"; // Inserting {'W', "Wednesday"}.
    day.insert(make_pair('F', "Friday")); // Inserting {'F', "Friday"}.

    day.insert(make_pair('M', "MONDAY")); // Fail to mofify element with key 'M'.
    day['M'] = "Monday"; // Succeed to modify element with key 'M'.

    Foo(day);
}

int main()
{
    UnorderedSet();
    UnorderedMap();

    vector<int> vec = { 1,2,3,4 };
    int* p = &vec[2]; // p points to 3.
    vec.insert(vec.begin(), 0); // Vector gets rebuilt after inserting a new element.
    cout << *p << endl; // The value of p is undefined.

    // Array based contaiters(vector, deque) invalidates pointers structure change:
    //     native pointers, iterators, references.

    return 0;
}
