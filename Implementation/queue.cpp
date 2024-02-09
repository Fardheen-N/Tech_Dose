#include <iostream>
#include <vector> 
using namespace std;
// class my_queue{
//   vector<int> val;
//   public:
//     void enqueue(int x){
//       val.push_back(x);
//     }
//     int dequeue(){
//       int x = val.front();
//       val.erase(val.begin());
//       return x;
//     }
//     int front(){
//       return val.front();
//     }
// };

class node{
  public:
  int data;
  node *next;
    node(int x){
      data = x;
      next = NULL;
    }
};
class l_queue{
node *head;
node *tail;
public:
  l_queue(){
    head = NULL;
    tail = NULL;  
  }
  void push(int x){
    node *temp = new node(x);
    if(head==NULL) {head = tail= temp; return;}
    tail->next = temp; 
    tail = temp;
  }
  void pop(){
    if(head==NULL) cout<<("Empty");
    node *temp = head;
    head = head->next;
    delete temp;
  }
  int front(){
    return head->data;
  }
};
int main() {
  l_queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.pop();
  // q.pop();
  // cout << q.pop() << endl;
  cout << q.front() << endl;
}
