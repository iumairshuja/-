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
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void getMiddle()
    {
        Node *temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        temp = head;
        for (int i = 1; i < count / 2; i++)
        {
            temp = temp->next;
        }

        if (count % 2 == 0)
        {
            cout << ((temp->data) + (temp->next->data)) / 2.0 << endl;//3+4/2 =3.5
        }
        else
        {
            temp = temp->next;
            cout << temp->data << endl;
        }
    }
};

int main()
{
    LinkedList list;
    int n;

    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        list.push(data);
    }

    cout << "Output: ";
    list.getMiddle();

    return 0;
}