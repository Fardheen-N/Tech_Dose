#include <iostream>
#include <vector> 
using namespace std;
class my_stack{
public:
  vector<int> val;
  int top(){
    return val.back();
  }
  void push_to(int x){
    val.push_back(x);
  }
  int pop_from(){
    int x = val.back();
    val.pop_back();
    return x;
  }

};

int main() {
  my_stack s;
  s.push_to(1);
  s.push_to(2);
  s.push_to(3);
  cout<<"Popped: "<<s.pop_from()<<endl;
  cout<<"Top :"<<s.top()<<endl;
}
