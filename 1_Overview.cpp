#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Print(const vector<int>::iterator& begin, const vector<int>::iterator& end)
{
    for (vector<int>::iterator itr = begin; itr != end; itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(2);

    vector<int>::iterator begin = vec.begin();
    vector<int>::iterator end = vec.end(); // Points to one element after the last element.

    Print(begin, end);
    sort(begin, end);
    Print(begin, end);
}
