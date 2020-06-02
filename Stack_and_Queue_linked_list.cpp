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
template <typename T>
class Stack
{
private:
    linked_list<T> list_;
    int size_;
public:
    Stack()
    {
        size_=0;
    }
    void push(T c)
    {
        list_.push_front(c);
        size_++;
    }
    void pop()
    {
        if(size_)
        {
            list_.pop_front();
            size_--;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
    }
    T top()
    {
        if(size_)
        {
            return list_.top();
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
        return 0;
    }
    int size()
    {
        return size_;
    }
    bool empty()
    {
        return !size_;
    }
};
template <typename T>
class Queue
{
private:
    linked_list<T> list_;
    int size_;
public:
    Queue()
    {
        size_=0;
    }
    void enqueue(T c)
    {
        list_.push_back(c);
        size_++;
    }
    void dequeue()
    {
        if(size_)
        {
            list_.pop_front();
            size_--;
        }
        else
        {
            cout<<"Queue is empty"<<endl;
        }
    }
    T top()
    {
        if(size_)
        {
            return list_.top();
        }
        else
        {
            cout<<"Queue is empty"<<endl;
        }
        return '.';
    }
    int size()
    {
        return size_;
    }
    bool empty()
    {
        return !size_;
    }
};
int main()
{
    Stack<int> st;
    st.push(5);
    st.push(6);
    st.push(7);
    cout<<"Size of Stack = "<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    if(st.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    cout<<"------------------------------"<<endl;
    Queue<char> qu;
    qu.enqueue('a');
    qu.enqueue('b');
    qu.enqueue('c');
    cout<<"Size of Queue = "<<qu.size()<<endl;
    cout<<qu.top()<<endl;
    qu.dequeue();
    cout<<qu.top()<<endl;
    qu.dequeue();
    cout<<qu.top()<<endl;
    qu.dequeue();
    if(qu.empty())
    {
        cout<<"Queue is empty"<<endl;
    }
}
