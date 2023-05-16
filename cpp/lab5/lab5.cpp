#include<iostream>
using namespace std;

class Node{
public:
    int Data;
    Node *next;

    Node(int data = 0, Node *next = nullptr)
    {
        Data = data;
        this->next = next;
    }
};

class CircularLinkedList
{
private:
    Node *Head;

public:
    CircularLinkedList()
    {
        Head = nullptr;
    }

    int GetData(Node *node)
    {
        return node->Data;
    }

    void SetData(Node *node, int data)
    {
        node->Data = data;
    }

    Node *GetNext(Node *node)
    {
        return node->next;
    }

    void SetNext(Node *node, Node *next)
    {
        node->next = next;
    }

    void Add(int data)
    {

        Node *newNode = new Node(data);

        if (Head == nullptr)
        {

            Head = newNode;
            Head->next = Head;
        }
        else
        {

            Node *current = Head;
            
            while (current->next != Head)
            {
                current = current->next;
                cout <<"x" <<newNode->Data;
            }
            cout << endl;
            current->next = newNode;
            newNode->next = Head;
        }
    }

    void Display()
    {
        if (Head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = Head;
        do
        {
            cout << current->Data << " ";
            current = current->next;
        } while (current != Head);
        cout << endl;
    }
};

int main()
{

    CircularLinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(3);

    list.Display();
    return 0;
}
