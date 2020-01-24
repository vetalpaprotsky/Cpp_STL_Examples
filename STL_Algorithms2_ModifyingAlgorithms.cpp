#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

template<typename T>
void Output(const vector<T>& vec)
{
    for (const T& el : vec)
        cout << el << " ";
    cout << endl;
}

template<typename T>
void Set(vector<T>& vec, T value)
{
    fill(vec.begin(), vec.end(), value);
}

void Copy()
{
    vector<int> v1 = { 9, 60, 70, 8, 45, 87, 90 };
    vector<int> v2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    copy(v1.begin(), v1.end(), v2.begin());
    Output(v2);
    Set(v2, 0);

    copy_if(v1.begin(), v1.end(), v2.begin(), [](int x) { return x > 80; });
    Output(v2);
    Set(v2, 0);

    copy_n(v1.begin(), 4, v2.begin());
    Output(v2);
    Set(v2, 0);

    copy_backward(v1.begin(), v1.end(), v2.end());
    Output(v2);
    Set(v2, 0);
}

// If move semantics are defined for the element type, elements are moved over,
// otherwise they are copied over with copy constructor, just like copy().
void Move()
{
    vector<string> v1 = { "apple", "orange", "pear", "grape" };
    vector<string> v2 = { "", "", "", "", "", "" };

    move(v1.begin(), v1.end(), v2.begin());
    Output(v1);
    Output(v2);
    cout << v1.size() << " " << v2.size() << endl;

    vector<string> v3 = { "apple", "orange", "pear", "grape" };
    vector<string> v4 = { "", "", "", "", "", "" };

    move_backward(v3.begin(), v3.end(), v4.end());
    Output(v3);
    Output(v4);
    cout << v3.size() << " " << v4.size() << endl;
}

void Transform()
{
    vector<int> v1 = { 9, 60, 70, 8, 45, 87, 90 };
    vector<int> v2 = { 9, 60, 70, 8, 45, 87, 90 };
    vector<int> v3 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    transform(v1.begin(), v1.end(), v3.begin(), [](int x) { return x - 1; });
    Output(v3);
    Set(v3, 0);

    // Add items from v1 and v2 and save in v3.
    // v3[0] = v1[0] + v2[0]
    // v3[1] = v1[1] + v2[1]
    // ...
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),
        [](int x, int y) { return x + y; });

    Output(v3);
}

// Two way copy.
void Swap()
{
    vector<int> v1 = { 9, 60, 70, 8, 45, 87, 90 };
    vector<int> v2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    swap_ranges(v1.begin(), v1.end(), v2.begin());
    Output(v1);
    Output(v2);
}

void Fill()
{
    vector<int> v = { 0, 0, 0, 0, 0 };

    fill(v.begin(), v.end(), 9);
    Output(v);
    Set(v, 0);

    fill_n(v.begin(), 3, 9);
    Output(v);
    Set(v, 0);

    generate(v.begin(), v.end(), rand);
    Output(v);
    Set(v, 0);

    generate_n(v.begin(), 3, rand);
    Output(v);
}

void Replace()
{
    vector<int> v1 = { 9, 60, 70, 9, 60, 85 };
    vector<int> v2 = { 0, 0, 0, 0, 0, 0 };

    replace(v1.begin(), v1.end(), 60, 100);
    Output(v1);

    replace_if(v1.begin(), v1.end(), [](int x) { return x > 80; }, 200);
    Output(v1);

    // v1 doesn't get changed.
    replace_copy(v1.begin(), v1.end(), v2.begin(), 9, 1000);
    Output(v1);
    Output(v2);

    // Generalized form: replace_copy_if.
}

void Remove()
{
    vector<int> v1 = { 9, 60, 70, 9, 60, 85, 20 };
    vector<int> v2 = { 0, 0, 0, 0, 0, 0 };

    auto newEnd = remove(v1.begin(), v1.end(), 9);
    v1.erase(newEnd, v1.end());
    Output(v1);

    newEnd = remove_if(v1.begin(), v1.end(), [](int x) { return x > 65; });
    v1.erase(newEnd, v1.end());
    Output(v1);

    // http://www.cplusplus.com/reference/algorithm/remove_copy/
    // https://stackoverflow.com/questions/11928115/why-doesnt-stdremove-copy-if-actually-remove

    // remove_copy doesn't actually remove elements from v1.
    // It just copies all elements from v1 to v2 which aren't 60 and that's it.

    // v1 doesn't get changed.
    // It's just a bad name.
    // This function works like replace_copy and unique_copy (source doesn't get changed).
    remove_copy(v1.begin(), v1.end(), v2.begin(), 60);
    Output(v1);
    Output(v2);

    // Generalized form: remove_copy_if.
}

// Removes duplicates.
void Unique()
{
    vector<int> v1 = { 1, 2, 2, 2, 3, 3, 4, 3, 2 };
    vector<int> v2 = { 1, 5, 10, 20, 10, 5, 1 };
    vector<int> v3 = { 1, 2, 2, 2, 3, 3, 4, 3, 2 };
    vector<int> v4 = { 0, 0, 0, 0, 0, 0, 0 };

    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    Output(v1);

    v2.erase(unique(v2.begin(), v2.end(), greater<int>()), v2.end());
    Output(v2);

    // v3 doesn't get changed.
    unique_copy(v3.begin(), v3.end(), v4.begin());
    Output(v3);
    Output(v4);
}

void Reverse()
{
    vector<int> v1 = { 9, 60, 70, 9, 60, 85, 20 };
    vector<int> v2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    reverse(v1.begin(), v1.end());
    Output(v1);

    // v1 doesn't get changed.
    reverse_copy(v1.begin(), v1.end(), v2.begin());
    Output(v1);
    Output(v2);
}

void Rotate()
{
    vector<int> v1 = { 9, 60, 70, 9, 60, 85, 20 };
    vector<int> v2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    rotate(v1.begin(), v1.begin() + 1, v1.end());
    Output(v1);

    // v1 doesn't get changed.
    rotate_copy(v1.begin(), v1.begin() + 1, v1.end(), v2.begin());
    Output(v1);
    Output(v2);
}

void Permute()
{
    vector<int> v = { 1, 2, 3, 4 };

    next_permutation(v.begin(), v.end());
    Output(v);

    prev_permutation(v.begin(), v.end());
    Output(v);
}

int myrandom(int i) { return std::rand() % i; }

void Shuffle()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6 };

    random_shuffle(v.begin(), v.end());
    Output(v);

    random_shuffle(v.begin(), v.end(), myrandom);
    Output(v);

    // C++ 11
    // Better random number generation.
    shuffle(v.begin(), v.end(), default_random_engine());
    Output(v);
}

int main()
{
    Copy();
    Move();
    Transform();
    Swap();
    Fill();
    Replace();
    Remove();
    Unique();

    Reverse();
    Rotate();
    Permute();
    Shuffle();

    return 0;
}
