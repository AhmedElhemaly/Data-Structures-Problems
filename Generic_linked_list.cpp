#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct node
{
    T data;
    node *next;
};
template <typename T>
class linked_list
{
private:
    node<T> *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(T n) // O(1) same push_back
    {
        node<T> *tmp = new node<T>;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void push_front(char n) // O(1)
    {
        node<T> *temp= new node<T>;
        temp->data=n;
        temp->next=head;
        head= temp;
        if(tail==NULL)
            tail=head;
    }
    void push_back(char n) // O(1)
    {
        node<T> *tmp = new node<T>;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void pop_front() // O(1)
    {
        if(head==NULL)
        {
            cout<<"Error list is empty !"<<endl;
            return;
        }
        head= head->next;
        if(head==NULL)
        {
            tail=NULL;
        }
    }
    void pop_back() // O(n)
    {
        if(head==NULL)
        {
            cout<<"Error list is empty !"<<endl;
            return;
        }
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            node<T> *tmp = head;
            while(tmp->next->next!=NULL)
            {
                tmp = tmp->next;
            }
            tmp->next=NULL;
            tail = tmp;
        }
    }
    T top() // O(1)
    {
        return head->data;
    }
    T last() // O(1)
    {
        return  tail->data;
    }
    bool isEmpty() // O(1)
    {
        return head==NULL;
    }
    void erase(T n)
    {
        node<T> *temp = head,*prev;
        if(temp!=NULL && temp->data==n)
        {
            head = temp->next;
            return;
        }
        while(temp!=NULL && temp->data!=n)
        {
            prev=temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            cout<<n<<" is not found in list"<<endl;
            return;
        }
        prev->next=temp->next;
    }
    void printList() // O(n)
    {
        if(head==NULL)
        {
            cout<<"Empty List";
        }
        node<T> *temp= new node<T>;
        temp->next=head;
        for ( ; head; head = head->next )
        {
            cout << head->data << " ";
        }
        head = temp->next;
        cout<<"\n=========================\n";
    }

};
int main()
{
    linked_list<int> a;      // list :
    a.add_node(2);      // list : 2
    a.push_front(1);    // list : 1 2
    a.push_back(3);     // list : 1 2 3
    a.printList();
    a.erase(2);         // list : 1 3
    a.printList();
    a.pop_back();       // list : 1
    a.printList();
    a.push_back(2);     // list : 1 2
    a.printList();
    a.pop_front();      // list : 2
    a.printList();
    a.pop_back();       // list :
    a.printList();
    a.pop_back();       // Error Message : "Error list is empty !"
    if(a.isEmpty())
    {
        cout<<"It is empty list !"<<endl;
    }
    return 0;
}
