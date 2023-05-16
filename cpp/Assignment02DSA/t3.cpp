// Umair Shuja
//  L1F21BSSE0396

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class CircularDoublyLinkedList
{
public:
    Node *head;

    CircularDoublyLinkedList()
    {
        head = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            newNode->next = newNode->prev = newNode;
            head = newNode;
        }
        else
        {
            Node *last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void removeDuplicates()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *current = head;
        do // 1 2 1 3
        {
            Node *innerCurrent = current->next;
            while (innerCurrent != head)
            {
                if (current->data == innerCurrent->data)
                {
                    innerCurrent->prev->next = innerCurrent->next;
                    innerCurrent->next->prev = innerCurrent->prev;

                    Node *temp = innerCurrent;
                    innerCurrent = innerCurrent->next;
                    delete temp;
                }
                else
                {
                    innerCurrent = innerCurrent->next;
                }
            }
            current = current->next;
        } while (current != head);
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    CircularDoublyLinkedList c1;

    c1.insert(4);
    c1.insert(5);
    c1.insert(4);
    c1.insert(2);
    c1.insert(2);
    c1.insert(4);
    c1.insert(5);

    cout << "Original Circular Doubly Linked List: ";
    c1.display();

    c1.removeDuplicates();

    cout << "Circular Doubly Linked List after removing duplicates: ";
    c1.display();

    return 0;
}