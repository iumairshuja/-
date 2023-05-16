#include<iostream>
#include<stack>
using namespace std;


struct Node
{
    int data;
    Node* next;
};

class ArrayQueue
{
private:
    int front, rear, capacity;
    int* queue;

public:
    ArrayQueue(int capacity)
    {
        this->capacity = capacity;
        front = rear = -1;
        queue = new int[capacity];
    }

    void enqueue(int val);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};



class LinkedListQueue
{
private:
    Node* front;
    Node* rear;

public:
    LinkedListQueue() :front(nullptr), rear(nullptr)
    {}

    void enqueue(int val);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

void LinkedListQueue::enqueue(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (rear == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int LinkedListQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    else
    {
        Node* temp = front;
        int data = temp->data;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        return data;
    }
}

bool LinkedListQueue::isEmpty()
{
    return (front == nullptr);
}

bool LinkedListQueue::isFull()
{
    return false; 
}

int LinkedListQueue::size()
{
    int count = 0;
    Node* temp = front;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void LinkedListQueue::display()
{
    cout << "Queue: ";
    Node* temp = front;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void ArrayQueue::enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        rear = (rear + 1) % capacity;
        queue[rear] = val;
        if (front == -1)
            front = 0;
    }
}

int ArrayQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    else
    {
        int data = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        return data;
    }
}

bool ArrayQueue::isEmpty()
{
    return (front == -1);
}

bool ArrayQueue::isFull()
{
    return ((rear + 1) % capacity == front);
}

int ArrayQueue::size()
{
    if (isEmpty())
        return 0;
    else if (front <= rear)
        return rear - front + 1;
    else
        return (capacity - front) + (rear + 1);
}

void ArrayQueue::display()
{
    cout << "Queue: ";
    if (!isEmpty()) {
        for (int i = front; i != rear; i = (i + 1) % capacity)
            cout << queue[i] << " ";
        cout << queue[rear];
    }
    cout << endl;
}



int main()
{
    ArrayQueue arrayQueue(5);
    LinkedListQueue linkedListQueue;

    arrayQueue.enqueue(1);
    arrayQueue.enqueue(2);
    arrayQueue.enqueue(3);
    arrayQueue.enqueue(4);
    arrayQueue.enqueue(5);

    linkedListQueue.enqueue(1);
    linkedListQueue.enqueue(2);
    linkedListQueue.enqueue(3);
    linkedListQueue.enqueue(4);
    linkedListQueue.enqueue(5);

    arrayQueue.display();
    linkedListQueue.display();

    cout << "Array Queue Dequeue: " << arrayQueue.dequeue() << endl;
    cout << "Linked List Queue Dequeue: " << linkedListQueue.dequeue() << endl;

    arrayQueue.display();
    linkedListQueue.display();

    return 0;
}