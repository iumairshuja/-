#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void bubbleSort()
    {
        if (head == nullptr)
            return;

        bool shift;
        Node *current;
        Node *lastPtr = nullptr;

        do
        {
            shift = false;
            current = head;

            while (current->next != lastPtr)
            {
                if (current->data > current->next->data)
                {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    shift = true;
                }
                current = current->next;
            }
            lastPtr = current;

        } while (shift);
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList d;

    d.insert(97);
    d.insert(12);
    d.insert(1);
    d.insert(5);
  

    cout << "Initial doubly linked list: ";

    d.display();

    d.bubbleSort();

    cout << "Doubly Linked List after applying bubble sort: ";
    d.display();

    return 0;
}