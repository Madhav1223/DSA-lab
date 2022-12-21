#include<iostream>
#include "stack.h"


int main()
{
  Stack<int> st{};
   try{
  for(int i =0;i<5;i++)
  {
    st.push(i);
  }
  for (int i =0;i<6;i++)
  {
    cout<<st.pop()<<endl;
  }
  }
  catch(StackOverFlow)
  {
    cout<<"Stack size exceed";
  }
  catch(StackUnderFlow)
  {
    cout<<"Cannot Pop a Empty Stack";
  }
    return 0;
}