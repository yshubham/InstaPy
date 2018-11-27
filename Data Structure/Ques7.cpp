#include <iostream>
#include<string>

using namespace std;

#define SIZE 100

template<class X>
class Stack{


    int top;
    X stck[SIZE];

    public:
    Stack(){top=-1;}

    void push(X);
    void pop();
    X topel();
    void Clear(){top=-1;}
    bool isEmpty(){if(top==-1)return true; else return false;}

    bool isFull(){if(top==SIZE-1)return true; else return false;}

    void display(){cout<<"\n    Stack is::";
            cout<<"\n\nTop-->  ";
          for(int i=top;i>=0;i--)cout<<stck[i]<<endl<<"\t";
     }
     int gettopindex(){return top;}

};

template<class X>
void Stack<X>::push(X ele){

  if(!isFull())
   stck[++top]=ele;
   else
    cout<<"Stack overflow\n";
}

template<class X>
void Stack<X>::pop(){

   if(!isEmpty()){
    top--;
   }
   else
        cout<<"Stack underflow\n";
}

template<class X>
X Stack<X>::topel(){

    if(!isEmpty())
        return stck[top];
    else {
       return stck[0];
       }
    }

template<class X>
Stack<X> add2int(Stack<X> &st1,Stack<X> &st2){
    Stack<X> st3;
    int carry=0;
    while(!st1.isEmpty()&&!st2.isEmpty()){
        st3.push((st1.topel()+st2.topel()+carry)%10);
        carry=(st1.topel()+st2.topel()+carry)/10;
        st1.pop();
        st2.pop();
    }

    if(!st1.isEmpty()){
        while(!st1.isEmpty()){
            st3.push((st1.topel()+carry)%10);
            carry=(st1.topel()+carry)/10;
            st1.pop();

        }
    }

     if(!st2.isEmpty()){
        while(!st2.isEmpty()){
            st3.push((st2.topel()+carry)%10);
            carry=(st2.topel()+carry)/10;
            st2.pop();

        }
    }
    if(carry!=0)
     st3.push(carry);
   return st3;

}

int main()
{
   Stack<int> st1,st2,st3,st4;

   char ch='y';

   while (ch=='y'||ch=='Y')
   {
        st1.Clear();
        st2.Clear();
        st3.Clear();
        st4.Clear();
        int num;
       
        cout<<"Press y/Y to continue ? \n";
        cin>>ch;

        cout<<"\nPush first number in stack (press 'enter' for next digit and press 'any 2 digit number' when you are done.): ";
        cin>>num;

        while(num>=0&&num<=9){

        st1.push(num);
         cin>>num;
        }

       cout<<"\nPush Second number in stack (press 'enter' for next digit and press 'any 2 digit number' when you are done.): ";
       cin>>num;

       while(num>=0&&num<=9){

        st2.push(num);
        cin>>num;
      }

        st3= add2int(st1,st2);
         cout<<"\nSum of two numbers is ";
         while(!st3.isEmpty()){
          cout<<st3.topel();
         st3.pop();
      }
   }
}
