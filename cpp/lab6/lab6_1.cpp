
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedListStack
{
private:
    Node* top;
    int stackSize;

public:
    LinkedListStack()
    :top(nullptr), stackSize(0)
    {}

    void push(int val);
    int pop();
    int getTop();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};


class ArrayStack
{
private:
    int top;
    int maxSize;
    int* arr;

public:
    ArrayStack(int size) :top(-1), maxSize(size)
    {
        arr = new int[maxSize];
    }

    void push(int val);
    int pop();
    int getTop();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

void ArrayStack::push(int val)
{
    if (isFull())
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        arr[++top] = val;
    }
}

int ArrayStack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        return arr[top--];
    }
}

int ArrayStack::getTop()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        return arr[top];
    }
}

bool ArrayStack::isEmpty()
{
    return (top == -1);
}

bool ArrayStack::isFull()
{
    return (top == maxSize - 1);
}

int ArrayStack::size()
{
    return (top + 1);
}

void ArrayStack::display()
{
    cout << "Stack: ";
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void LinkedListStack::push(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (top == nullptr)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
    stackSize++;
}

int LinkedListStack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        Node* temp = top;
        int data = temp->data;
        top = top->next;
        delete temp;
        stackSize--;
        return data;
    }
}

int LinkedListStack::getTop()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        return top->data;
    }
}

bool LinkedListStack::isEmpty()
{
    return (top == nullptr);
}

bool LinkedListStack::isFull()
{
    return false; 
}

int LinkedListStack::size()
{
    return stackSize;
}

void LinkedListStack::display()
{
    cout << "Stack: ";
    Node* temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main()
{
    ArrayStack arrStack(5);

    arrStack.push(10);
    arrStack.push(20);
    arrStack.push(30);
    arrStack.push(40);
    arrStack.push(50);

    cout << "Array Based Stack:" << endl;
    arrStack.display();
    cout << "Top element: " << arrStack.getTop() << endl;
    cout << "Stack size: " << arrStack.size() << endl;
    cout << "Is empty: " << arrStack.isEmpty() << endl;
    cout << "Is full: " << arrStack.isFull() << endl;

    arrStack.pop();
    arrStack.pop();
    arrStack.display();

    LinkedListStack llStack;

    llStack.push(60);
    llStack.push(70);
    llStack.push(80);
    llStack.push(90);
    llStack.push(100);

    cout << "Linked List Based Stack:" << endl;
    llStack.display();
    cout << "Top element: " << llStack.getTop() << endl;
    cout << "Stack size: " << llStack.size() << endl;
    cout << "Is empty: " << llStack.isEmpty() << endl;
    cout << "Is full: " << llStack.isFull() << endl;

    llStack.pop();
    llStack.pop();
    llStack.display();

    return 0;
}