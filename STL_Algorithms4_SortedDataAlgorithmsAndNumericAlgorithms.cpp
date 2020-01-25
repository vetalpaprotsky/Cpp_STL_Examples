#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Sorted data algorithms:
//     binary search, merge and set operations.

// These algorithms required data to sorted.

template<typename T>
void Output(T& container)
{
    for (auto& el : container)
        cout << el << " ";
    cout << endl;
}

void BinarySearch()
{
    vector<int> v = { 8,9,9,9,45,87,90 };
    // Check if 9 is in v.
    bool found = binary_search(v.begin(), v.end(), 9);
    cout << boolalpha << found << endl;

    vector<int> s = { 9,45,66 };
    // Return true if v contains all elements of s.
    // Both v and s must be sorted.
    found = includes(v.begin(), v.end(), s.begin(), s.end());
    cout << boolalpha << found << endl;

    // Find the first position where 9 could be inserted and
    // still keep the sorting valid. It's v[1].
    auto it = lower_bound(v.begin(), v.end(), 9);

    // Find the last position where 9 could be inserted and
    // still keep the sorting valid. It's v[4].
    it = upper_bound(v.begin(), v.end(), 9);

    // Find both the first and the last positions.
    auto pairOfItrs = equal_range(v.begin(), v.end(), 9);
}

void Merge()
{
    vector<int> v1 = { 8,9,9,10 };
    vector<int> v2 = { 7,9,10 };
    vector<int> v3(7);

    // Both v1 and v2 should be sorted.
    // Nothing is left out, all duplicates are kept.
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    Output(v3);

    // Both parts of v4 are already sorted.
    vector<int> v4 = { 1,2,3,4,1,2,3,4,5 };
    // Do one step of merge sort algorithms.
    inplace_merge(v4.begin(), v4.begin() + 4, v4.end());
    Output(v4);
}

void SetOperations()
{
    vector<int> v1 = { 8,9,9,10 };
    vector<int> v2 = { 7,9,10 };
    vector<int> v3(5), v4(5), v5(5), v6(5);

    // There's gonna be two 9's in v3 because there are two of them in v1.
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    Output(v3);

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    Output(v4);

    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
    Output(v5);

    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v6.begin());
    Output(v6);
}

// Numeric algorithms (in <numeric>).

void Accumulate()
{
    vector<int> v = { 1,2,3,4,5 };

    // 10 + v[0] + v[1] + ...
    cout << accumulate(v.begin(), v.end(), 10) << endl;
    // 10 * v[0] * v[1] * ...
    cout << accumulate(v.begin(), v.end(), 10, multiplies<int>()) << endl;
}

void InnerProduct()
{
    vector<int> v = { 1,2,3,4,5,6,7 };
    int x;

    // 10 + v[0]*v[4] + v[1]*v[5] + v[2]*v[6]
    x = inner_product(
        v.begin(),
        v.begin() + 3,
        v.end() - 3,
        10
    );
    cout << x << endl;

    // 10 * (v[0]+v[4]) * (v[1]+v[5]) * (v[2]+v[6])
    x = inner_product(
        v.begin(),
        v.begin() + 3,
        v.end() - 3,
        10,
        multiplies<int>(),
        plus<int>()
    );
    cout << x << endl;
}

void PartialSum()
{
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2(5);

    // v2[0] = v1[0]
    // v2[1] = v1[0] + v1[1]
    // v2[2] = v1[0] + v1[1] + v1[2]
    // ...
    partial_sum(v1.begin(), v1.end(), v2.begin());
    Output(v2);

    // v2[0] = v1[0]
    // v2[1] = v1[0] * v1[1]
    // v2[2] = v1[0] * v1[1] * v1[2]
    // ...
    partial_sum(v1.begin(), v1.end(), v2.begin(), multiplies<int>());
    Output(v2);
}

void AdjacentDifference()
{
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2(5);

    // v2[0] = v1[1]
    // v2[1] = v1[1] - v[0]
    // v2[2] = v1[2] - v[1]
    // ...
    adjacent_difference(v1.begin(), v1.end(), v2.begin());
    Output(v2);

    // v2[0] = v1[1]
    // v2[1] = v1[1] + v[0]
    // v2[2] = v1[2] + v[1]
    // ...
    adjacent_difference(v1.begin(), v1.end(), v2.begin(), plus<int>());
    Output(v2);
}

int main()
{
    BinarySearch();
    Merge();
    SetOperations();

    Accumulate();
    InnerProduct();
    PartialSum();
    AdjacentDifference();

    return 0;
}
