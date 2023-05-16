#include <iostream> 
using namespace std;

template <class Type>
class AbstractClass
{
public:
AbstractClass(){}
virtual void addElement(Type) =0;
virtual void addElementAtFirstIndex(Type) = 0;
virtual void addElementAtLastIndex(Type) = 0;
};

template <class Type>
class List : public AbstractClass<Type>
{
public:
void addElement(Type element)
{
    arr[currentSize] = element;
    currentSize++;
}
void addElementAtFirstIndex(Type element)
{

    // for (int i = currentSize - 1; i > 0; i--)
    //     arr[i] = arr[i - 1];
    arr[0] = element;
    currentSize++;
}
void addElementAtLastIndex(Type element)
{
    arr[maxSize - 1] = element;
}
List() {}
List(int maxSize) : maxSize(maxSize)
{
    arr = new int[maxSize];
    currentSize = 0;
}
List(const List &obj)
{
    maxSize = obj.maxSize;
    arr = obj.arr;
    currentSize = obj.currentSize;
}
~List()
{
    delete[] arr;
}

void display()
{
    cout << "List elements: ";
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

private:
Type *arr;
int maxSize;
int currentSize;
};

int main(){
    List<int> obj(5);
    obj.addElementAtFirstIndex(5);
    obj.addElement(10);
    obj.addElement(20);
    obj.addElement(30);
    obj.addElementAtLastIndex(40);
    obj.display();
}