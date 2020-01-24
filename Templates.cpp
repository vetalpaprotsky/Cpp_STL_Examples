#include <iostream>

using namespace std;

template <typename T>
T square(T x)
{
    return x * x;
}

template <typename T>
class Vector
{
private:
    T arr[1000];
    int size;

public:
    Vector() : size(0) {}
    void Push(T x)
    {
        arr[size++] = x;
    }

    T Get(int i) const
    {
        return arr[i];
    }

    int GetSize() const
    {
        return size;
    }

    void Print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    Vector<T> operator*(const Vector<T>& vector) const
    {
        Vector<T> result;
        for (int i = 0; i < GetSize(); i++)
        {
            result.Push(Get(i) * vector.Get(i));
        }
        return result;
    }
};

int main()
{
    cout << square(5) << endl;
    cout << square(5.5) << endl;

    Vector<int> v1;
    v1.Push(2);
    v1.Push(3);
    v1.Push(4);
    v1.Print();

    Vector<int> v2 = square(v1);
    v2.Print();

    return 0;
}
