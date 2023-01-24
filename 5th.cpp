#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }
    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
    void InsertAtHead(int value)
    {
        node *newNode = CreateNewNode(value);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void Traverse()
    {
        node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    int getSize()
    {
        node *current = head;
        if (current == NULL)
        {
            return 0;
        }
        else
        {
            int size = 0;
            while (current != NULL)
            {
                size++;
                current = current->next;
            }
            return size;
        }
    }
    int getValue(int index)
    {
        node *current = head;
        int countIndex = 0;
        while (current != NULL)
        {
            if (countIndex == index)
            {
                return current->data;
            }
            current = current->next;
            countIndex++;
        }
        return -1;
    }
    void swapFirst()
    {
        if (getSize() <= 1)
        {
            return;
        }
        else
        {
            node *current = head;
            node *temp_reference, *next_head = current->next;
            temp_reference = current->next->next;
            current->next->next = current;
            current->next = temp_reference;
            head = next_head;
        }
    }
    void printReverse()
    {
        printReverse(head);
    }

    void printReverse(node *current)
    {
        if (current == NULL)
        {
            return;
        }
        printReverse(current->next);
        cout << current->data << " ";
    }
};
int main()
{
    LinkedList l;
    cout << l.getSize() << "\n";
    l.InsertAtHead(5);
    cout << l.getSize() << "\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout << l.getSize() << "\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout << l.getValue(2) << "\n";

    cout << l.getValue(6) << "\n";

    l.printReverse();
    cout << endl;
    l.Traverse();
    cout << endl;
    l.swapFirst();
    l.Traverse();
    cout << endl;
    l.printReverse();

    return 0;
}