// Umair Shuja
// L1F21BSSE0396
#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(char val);
    char pop();
    bool isEmpty();
    void display();
    void checkBalanced();
};

void Stack::push(char val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head; //First In Last Out
        head = newNode;
    }
}

char Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return '\0';
    }
    else
    {
        Node *temp = head;
        char data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }
}

bool Stack::isEmpty()
{
    return (head == nullptr);
}

void Stack::display()
{
    cout << "Data in the stack: ";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack::checkBalanced()
{
    Stack tempStack;
    Node* temp = head;

    while (temp != nullptr)
    {
        if (temp->data == '(')
        {
            tempStack.push(temp->data);
        }
        else if (temp->data == ')')
        {
            if (tempStack.isEmpty())
            {
                cout << "Not Balanced" << endl;
                return;
            }
            else
            {
                char topChar = tempStack.pop();
                if ((temp->data == ')' && topChar != '('))
                {
                    cout << "Not Balanced" << endl;
                    return;
                }
            }
        }
        temp = temp->next;
    }

    if (tempStack.isEmpty())
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
}

int main()
{
    Stack s1, s2, s3, s4;
    char in[10] ={"\0"};
    cout <<"Enter expression" << endl;
    cin>> in;
    int count=0;
    for (int i = 0; in[i] != '\0'; i++)
    {
       count++;
    }
    for(int i = count-1; i>=0; i--) {
        
        s1.push(in[i]);
    }

    cout << "Enter expression" << endl;
    cin >> in;
    count = 0;
    for (int i = 0; in[i] != '\0'; i++)
    {
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
    {

        s2.push(in[i]);
    }

    cout << "Enter expression" << endl;
    cin >> in;
    count = 0;
    for (int i = 0; in[i] != '\0'; i++)
    {
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
    {

        s3.push(in[i]);
    }

    cout << "Enter expression" << endl;
    cin >> in;
    count = 0;
    for (int i = 0; in[i] != '\0'; i++)
    {
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
    {

        s4.push(in[i]);
    }
    s1.display();
    cout << "Expression 1: ";
    s1.checkBalanced();
    s2.display();
    cout << "Expression 2: ";
    s2.checkBalanced();
    s3.display();
    cout << "Expression 3: ";
    s3.checkBalanced();
    s4.display();
    cout << "Expression 4: ";
    s4.checkBalanced();
   
    return 0;
}
