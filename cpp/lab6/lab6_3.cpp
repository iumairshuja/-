#include<iostream>
using namespace std;

class ArrayQueue
{
protected:
    int front, rear, maxsize;
    int* list;

public:
    ArrayQueue(int capacity = 5)
    {
        maxsize = capacity;
        front = rear = -1;
        list = new int[maxsize];
    }

    ArrayQueue(const ArrayQueue& other)
    {
        maxsize = other.maxsize;
        front = other.front;
        rear = other.rear;
        list = new int[maxsize];
        for (int i = 0; i < maxsize; i++)
            list[i] = other.list[i];
    }

    ~ArrayQueue()
    {
        delete[] list;
    }

    void enqueue(int val);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

void ArrayQueue::enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        rear = (rear + 1) % maxsize;
        list[rear] = val;
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
        int data = list[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % maxsize;
        return data;
    }
}

bool ArrayQueue::isEmpty()
{
    return (front == -1);
}

bool ArrayQueue::isFull()
{
    return ((rear + 1) % maxsize == front);
}

void ArrayQueue::display()
{
    cout << "Queue: ";
    if (!isEmpty()) {
        for (int i = front; i != rear; i = (i + 1) % maxsize)
            cout << list[i] << " ";
        cout << list[rear];
    }
    cout << endl;
}

class myQueue : public ArrayQueue
{
public:
    myQueue(int capacity = 5) : ArrayQueue(capacity) {}
    myQueue(const myQueue& other) : ArrayQueue(other) {}
};

int main()
{
    int capacity, choice, value;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    myQueue queue(capacity);

    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Check if Full\n4. Check if Empty\n5. Display Queue\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;

        case 2:
            cout << "Dequeued: " << queue.dequeue() << endl;
            break;

        case 3:
            if (queue.isFull())
                cout << "Queue is full" << endl;
            else
                cout << "Queue is not full" << endl;
            break;

        case 4:
            if (queue.isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
            break;

        case 5:
            queue.display();
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}