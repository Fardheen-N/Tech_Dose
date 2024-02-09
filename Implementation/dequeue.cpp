#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *next,*prev;

    Node(int val){
        this->val=val;
        next=NULL,prev=NULL;
    }
};


class Deque{
    public:
    Node *head,*tail;
    Deque(){
        head=new Node(0);
        tail=new Node(0);
        head->next=tail;
        tail->prev=head;
    }

    void push_front(int val){
        Node* nn=new Node(val);

        nn->prev=head;
        nn->next=head->next;
        head->next->prev=nn;
        head->next=nn;
    }

    void push_back(int val){
        Node *nn=new Node(val);

        nn->next=tail;
        nn->prev=tail->prev;
        tail->prev->next=nn;
        tail->prev=nn;
    }

    void pop_front(){
        Node *temp=head->next;
        if(temp!=tail){
            temp->next->prev=head;
            head->next=temp->next;
        }
    }
    void pop_back(){
        Node *temp=tail->prev;
        if(temp!=head){
            tail->prev=temp->prev;
            temp->prev->next=tail;
        }
    }
    void display(){
        Node *temp=head->next;
        while(temp!=tail){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


int main(){

    Deque l1;
    l1.push_front(10);
    l1.push_front(20);
    l1.push_front(30);
    l1.push_back(100);
    l1.push_back(200);
    l1.push_back(300);

    l1.display();

    l1.pop_back();
    l1.pop_front();;

    l1.display();
}
