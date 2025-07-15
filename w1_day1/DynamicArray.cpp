
#include <iostream>
using namespace std;
template <class T>

class DynamicArray
{
    T *arr;
    int cap;
    int size;

    void expand()
    {
        cap *= 2;
        T *NewArr = new T[cap];

        for (int i = 0; i < size; i++)
        {

            NewArr[i] = arr[i];
        }
        delete[] arr;
        arr = NewArr;
    }

public:
    DynamicArray()
    {
        cap = 10;
        size = 0;
        arr = new T[cap];
    }

    DynamicArray(int c, int s)
    {
        cap = c;
        size = s;
        arr = new T[cap];
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    void addToFirst(T Element)
    {
        if (size == cap)
        {
            expand();
        }

        for (int i = size - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[0] = Element;
        size++;
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        { 
            cout << arr[i] << "  ";
        }
    }

    void addToLast(T element)
    {

        if (size == cap)
        {
            expand();
        }

        arr[size] = element;
        size++;
    }

    void romoveFromLast()
    {
        if (size != 0)
        {
            size--;
        }
        else
        {
            cout << "Array is Empty" << endl;
        }
    }

    void removeFromFirst()
    {
        if (size == 0)
            return;

        for (int i = 0; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void addToIndex(int index, T element)
    {

        if (size == cap)
        {
            expand();
        }

        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = element;
        size++;
    }

    void removeByIndex(int index)
    {

        if (size == 0)
            return;

        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void clear()
    {
        size = 0;
    }

    int sizeOf()
    {
        return size;
    }

    int front()
    {
        return arr[0];
    }

    int back()
    {
        return arr[size - 1];
    }

    int capacity()
    {
        return cap;
    }

    bool search(T element)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == element)
            {
                return true;
            }
        }

        return false;
    }

    void shrink_to_fit()
    {
        cap = size;
        int *NewArr = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            NewArr[i] = arr[i];
        }

        delete[] arr;
        arr = NewArr;
    }
};

int main()
{
    DynamicArray<int> Array;
    Array.Display();
    Array.addToFirst(10);

    Array.addToFirst(20);
    Array.addToFirst(30);
    Array.Display();

    return 0;
}