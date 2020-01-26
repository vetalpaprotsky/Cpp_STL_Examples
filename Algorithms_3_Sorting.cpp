#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Sorting algorithms requires random access iterators:
//     vector, deque, container array, native array.

// list has own sort() member function.

void Output(const vector<int>& v)
{
    for (int el : v)
        cout << el << " ";
    cout << endl;
}

bool LastDigitSort(int a, int b)
{
    return a % 10 < b % 10;
}

bool LessThen10(int a)
{
    return a < 10;
}

void Sort()
{
    vector<int> v = { 9,1,10,2,45,3,90,4,9,5,8 };

    sort(v.begin(), v.end());
    Output(v);

    sort(v.begin(), v.end(), LastDigitSort);
    Output(v);
}

void PartialSort()
{
    vector<int> v = { 9,60,70,8,45,87,90,69,69,55,7 };

    // Find top 5 students according to their test scores.
    partial_sort(v.begin(), v.begin() + 5, v.end(), greater<int>());
    Output(v);

    partial_sort(v.begin(), v.begin() + 5, v.end());
    Output(v);
}

// QUESTION: Why does it sorts whole vector? Just like sort() function.
void NthElement()
{
    vector<int> v = { 9,60,70,8,45,87,90,69,69,55,7 };

    // Find top 5 students according to their test scores (order doesn't matter).
    nth_element(v.begin(), v.begin() + 5, v.end(), greater<int>());
    Output(v);
}

void Partion()
{
    vector<int> v1 = { 9,60,70,8,45,87,90,69,69,55,7 };
    vector<int> v2 = { 9,60,70,8,45,87,90,69,69,55,7 };

    // Move the students whose score is less than 10 to the front.
    partition(v1.begin(), v1.end(), LessThen10);
    Output(v1);

    // Preserve the original order within each partition.
    stable_partition(v2.begin(), v2.end(), LessThen10);
    Output(v2);
}

// Heap:
// 1. First element is always the largest.
// 2. Add/remove takes O(log(n)) time.
void Heap()
{
    vector<int> v = { 9,1,10,2,45,3,90,4,9,5,8 };

    make_heap(v.begin(), v.end());
    Output(v);

    // Remove the largest element.
    pop_heap(v.begin(), v.end()); // Swap v[0] with last item v[size - 1].
    Output(v);                    // Heapify [v.begin(), v.end() - 1].

    // Remove last element (the largest one).
    v.pop_back();
    Output(v);

    // Add new element.
    v.push_back(100);
    push_heap(v.begin(), v.end()); // Heapify last element (newly pushed).
    Output(v);

    // sort_heap can only work on a heap.
    sort_heap(v.begin(), v.end());
    Output(v);
}


int main()
{
    Sort();
    PartialSort();
    NthElement();
    Partion();

    Heap();

    return 0;
}
