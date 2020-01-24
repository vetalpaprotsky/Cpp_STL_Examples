#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v1 = { 9,60,90,8,45,87,90,69,69,55,7 };
vector<int> v2 = { 9,60,70,8,45,87 };
vector<int>::iterator i1, i2;
pair<vector<int>::iterator, vector<int>::iterator> pairOfItr;

void Output(const pair<vector<int>::iterator, vector<int>::iterator>& pairOfItr)
{
    cout << *pairOfItr.first << " " << *pairOfItr.second << endl;
}

void Output(const vector<int>::iterator& itr)
{
    cout << *itr << endl;
}

template<typename T>
void Output(const T& el)
{
    cout << el << endl;
}

void Counting()
{
    int n = count(v1.begin(), v1.end(), 69); // 2
    int m = count_if(v1.begin(), v1.end(), [](int x) {return x < 10; }); // 3
    Output(n);
    Output(m);
}

void MinMax()
{
    // Return the first max value.
    i1 = max_element(v1.begin() + 2, v1.end()); // 90
    i2 = max_element(v1.begin(), v1.end(), [](int x, int y) { return x % 10 < y % 10; }); // 9
    Output(i1);
    Output(i2);

    i1 = min_element(v1.begin(), v1.end()); // 7
    Output(i1);

    // Return a pair, which contains the first min and the last max element.
    pairOfItr = minmax_element(v1.begin(), v1.end(), [](int x, int y) { return x % 10 < y % 10; }); // 60 69
    Output(pairOfItr);
}

// Used when data is not sorted.
void LinearSearch()
{
    vector<int> sub = { 45,87,90 };
    vector<int> items = { 87,69,2 };

    // Return the first match.
    i1 = find(v1.begin(), v1.end(), 55);
    Output(i1);
    i1 = find_if(v1.begin(), v1.end(), [](int x) { return x > 80; });
    Output(i1);
    i1 = find_if_not(v1.begin(), v1.end(), [](int x) { return x > 80; });
    Output(i1);

    // Search for 2 consecutive items of 69.
    i1 = search_n(v1.begin(), v1.end(), 2, 69);
    Output(i1);

    // Search for the first subrange.
    i1 = search(v1.begin(), v1.end(), sub.begin(), sub.end());
    Output(i1);

    // Search for the last subrange.
    i1 = find_end(v1.begin(), v1.end(), sub.begin(), sub.end());
    Output(i1);

    // Search for any one of the item in items.
    i1 = find_first_of(v1.begin(), v1.end(), items.begin(), items.end());
    Output(i1);

    // Search for any one of the item in items that satisfy: x == y * 4.
    i1 = find_first_of(v1.begin(), v1.end(), items.begin(), items.end(), [](int x, int y) { return x == y * 4; });
    Output(i1);

    // Find two adjacent items that are the same.
    i1 = adjacent_find(v1.begin(), v1.end());
    Output(i1);

    // Find two adjacent items that satisfy: x + 3 == y.
    i1 = adjacent_find(v1.begin(), v1.end(), [](int x, int y) { return x + 3 == y; });
    Output(i1);
}

void ComparingRanges()
{
    if (!equal(v1.begin(), v1.end(), v2.begin(), v2.end()))
    {
        cout << "v1 != v2" << endl;
    }
    if (!is_permutation(v1.begin(), v1.end(), v2.begin(), v2.end()))
    {
        cout << "v1 and v2 consist of different items" << endl;
    }

    // Find the first difference.
    // pairOfItr.first is iterator of v1.
    // pairOfItr.second is iterator of v2.
    pairOfItr = mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());
    Output(pairOfItr);

    if (!lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
    {
        cout << "v1 > v2" << endl;
    }
    // 1 2 3 5  <  1 2 4 5
    // 1 2      <  1 2 3
}

void CheckAttributes()
{
    if (!is_sorted(v1.begin(), v1.end()))
    {
        cout << "v1 is not sorter" << endl;
    }

    // i1 points to the first place where elements are no longer sorted.
    i1 = is_sorted_until(v1.begin(), v1.end());
    Output(i1);

    // check if v1 patitioned according to the condition (x > 80).
    if (!is_partitioned(v1.begin(), v1.end(), [](int x) { return x > 80; }))
    {
        cout << "v1 is not partitioned to the condition (c > 80)" << endl;
    }

    is_heap(v1.begin(), v1.end());
    i1 = is_heap_until(v1.begin(), v1.end());
    Output(i1);

    if (all_of(v1.begin(), v1.end(), [](int x) { return x > 0; }))
    {
        cout << "All v1 elements are greater then 0" << endl;
    }
    if (any_of(v1.begin(), v1.end(), [](int x) { return x > 80; }))
    {
        cout << "At least one v1 element is greater then 80" << endl;
    }
    if (none_of(v1.begin(), v1.end(), [](int x) { return x > 100; }))
    {
        cout << "None of v1 elements are greater then 100" << endl;
    }
}

// Most algorithms functions have a simple form and a generalized form.
// For example function count() has a generalized function count_if().
// Almost all generalized functions have the same name as simple functions.

int main()
{
    Counting();
    MinMax();
    LinearSearch();
    ComparingRanges();
    CheckAttributes();

    return 0;
}
