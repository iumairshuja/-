#include <iostream>
using namespace std;

template <class Type>
class AbstractClass
{
public:
    AbstractClass() {}
    virtual void addElement(Type) = 0;
    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
};

template <class Type>
class MyList : public AbstractClass<Type>
{
public:
    MyList(int maxSize = 10)
    {
        arr = new Type[maxSize];
        this->maxSize = maxSize;
        currentSize = 0;
    }

    MyList(const MyList &obj)
    {
        this->maxSize = obj.maxSize;
        arr = new Type[maxSize];
        for (int i = 0; i < obj.currentSize; i++)
        {
            arr[i] = obj.arr[i];
        }
        currentSize = obj.currentSize;
    }

    ~MyList()
    {
        delete[] arr;
    }

    bool empty()
    {
        return (currentSize == 0);
    }

    bool full()
    {
        return (currentSize == maxSize);
    }

    int size()
    {
        return currentSize;
    }

    bool insertAt(int index, Type value)
    {
        if (index < 0 || index >= currentSize || currentSize == maxSize)
        {
            return false;
        }
        for (int i = currentSize - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        currentSize++;
        return true;
    }

    Type last()
    {
        return arr[currentSize - 1];
    }

    void addElement(Type element)
    {
        arr[currentSize] = element;
        currentSize++;
    }

    void addElementAtFirstIndex(Type element)
    {
        for (int i = currentSize - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = element;
        currentSize++;
    }

    void addElementAtLastIndex(Type element)
    {
        arr[maxSize - 1] = element;
    }

private:
    Type *arr;
    int maxSize;
    int currentSize;
};

int main()
{
    MyList<int> myList(5);
    cout << "Is the list empty? " << myList.empty() << endl;
    cout << "Is the list full? " << myList.full() << endl;
    cout << "List size: " << myList.size() << endl;

    myList.addElementAtFirstIndex(5);
    myList.addElement(10);
    myList.addElement(20);
    myList.addElement(30);
    myList.addElementAtLastIndex(40);

    cout << "Is the list empty? " << myList.empty() << endl;
    cout << "Is the list full? " << myList.full() << endl;
    cout << "List size: " << myList.size() << endl;

    if (myList.insertAt(2, 15))
    {
        cout << "Value inserted at index 2" << endl;
    }
    else
    {
        cout << "Failed to insert value at index 2" << endl;
    }

    cout << "Last element: " << myList.last() << endl;

    return 0;
}
