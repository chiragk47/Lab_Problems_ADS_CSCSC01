#include <iostream>
#include <stack>
using namespace std;

class Two_Stacks
{
  public:
  int *arr;
  int size;
  int top1;
  int top2;

  
    Two_Stacks(int size)
{
      this-> size = size;
      top1 = -1;
      top2 = size;
      arr = new int(size);
}

  void push1(int num)
{
    if(top2-top1 > 1)
    {
      top1++;
      arr[top1] = num;
    }
    else{
      cout<<"Stack Overflow"<<endl;
    }
}

  void push2(int num)
{
    if(top2-top1 > 1)
    {
      top2--;
      arr[top2] = num;
    }
    else{
      cout<<"Stack Overflow"<<endl;
    }
}

  int pop1()
{
    if(top1>=0)
    {
      int answer = arr[top1];
      top1--;
    }
    else{
      cout<<"Stack Underflow"<<endl;
    }
}

  int pop2()
{
    if(top2<=size)
    {
      int answer = arr[top2];
      top2++;
    }
    else{
      cout<<"Stack Underflow"<<endl;
    }
}

  int peek1()
{
    if(top1>=0)
      return arr[top1];
    else
    {
      cout<<"Stack is Empty"<<endl;
      return -1;
    }
}

  int peek2()
{
    if(top2<=size)
      return arr[top2];
    else
    {
      cout<<"Stack is Empty"<<endl;
      return -1;
    }
}
  
};


int main()
{
  
  Two_Stacks st(5);

  st.push1(1);
  cout<<st.peek1()<<endl;
  st.push1(2);
  cout<<st.peek1()<<endl;
  st.push1(3);
  cout<<st.peek1()<<endl;

  
  st.push2(10);
  cout<<st.peek2()<<endl;
  st.push2(15);
  cout<<st.peek2()<<endl;

  st.push1(4);

  
}

