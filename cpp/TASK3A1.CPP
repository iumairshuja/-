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

    bool binarySearch(int target)
    {
        int left = 0, right = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            right++;
            temp = temp->next;
        }

        while (left <= right)
        {
            int mid = (left + right) / 2;
            temp = head;
            for (int i = 0; i < mid; i++)
            {
                temp = temp->next;
            }

            if (temp->data == target)
            {
                return true;
            }
            else if (temp->data < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
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

    cout << "Input Linked List: ";
    list.display();

    cout << "Enter value to search for: ";
    int value;
    cin >> value;
    if (list.binarySearch(value)==true)
    {
        cout << "Found " << value <<endl;
    }
    else
    {
        cout << "Not found " << value <<endl;
    }
   

    return 0;
}