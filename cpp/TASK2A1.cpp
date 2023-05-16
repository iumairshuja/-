#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(int newData)
    {
        Node *newNode = new Node();
        newNode->data = newData;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else{
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteMiddle()
    {
        Node *temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        if (count == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        temp = head;
        for (int i = 1; i < count / 2; i++)
        {
            temp = temp->next;
        }

        if (count % 2 == 0)
        {
            Node *del = temp->next;
            Node *del2 = temp->next->next;
            temp->next = temp->next->next; //THE CODE DELETES temp->next-> and temp->next->next 
            delete del;
            delete del2;
        }
        else
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<< endl;
    }
};

int main()
{
    LinkedList list;
    int n;

    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0;i < n; i++) {
        int data;
        cin >> data;
        list.push(data);
    }

    cout << "Input Linked List: ";
    list.display();

    list.deleteMiddle();

    cout << "Output Linked List: ";
    list.display();

    return 0;
}