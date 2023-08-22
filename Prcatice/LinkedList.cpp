#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtBeginning(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void inserAt(int idx, int val)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid";
            return;
        }
        else if (idx == 0)
            insertAtBeginning(val);
        else if (idx == size)
            insertAtEnd(val);
        else
        {
            Node *t = new Node(val);
            Node *temp = head;
            for (int i = 1; i <= idx - 1; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }
    int getElementAtIdx(int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid Index";
            return -1;
        }
        else if (idx == 0)
            return head->val;
        else if (idx == size - 1)
            return tail->val;
        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx; i++)
            {
                temp = temp->next;
            }
            return temp->val;
        }
    }
    int deleteAtHead()
    {
        if (size == 0)
        {
            cout << "Invalid List is empty!!";
            return -1;
        }
        else
        {
            head = head->next;
            size--;
        }
    }
    void removeAtIdx(int idx)
    {
        if (size <= 0)
            cout << "LinkedList is empty";
        else if (size > 0 && idx < size - 1)
        {
            Node *temp = head;
            Node *t = new Node(NULL);
            for (int i = 1; i <= idx - 1; i++)
            {
                temp = temp->next;
            }
            size--;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    // ll.insertAtEnd(40);
    // ll.display();
    ll.insertAtEnd(50);
    ll.inserAt(3, 40);
    ll.display();
    cout << ll.getElementAtIdx(3) << endl;
    // ll.removeAtIdx(2);
    ll.deleteAtHead();
    ll.display();
    return 0;
}