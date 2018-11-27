#include <iostream>

using namespace std;
#define SIZE 100
template<class X>
class Stack
{
    int top;
    X stck[SIZE];
public:
    Stack()
    {
        top=-1;
    }

    void push(X);
    void pop();
    X topel();

    void Clear()
    {
        top=-1;
    }

    bool isEmpty()
    {
        if(top==-1)return true;
        else return false;
    }

    bool isFull()
    {
        if(top==SIZE-1)return true;
        else return false;
    }

    void display()
    {
        cout<<"\nTop-->  ";
        if(top==-1)cout<<"Empty\n";
        else
        for(int i=top; i>=0; i--)cout<<stck[i]<<endl<<"\t";
    }

};

template<class X>
void Stack<X>::push(X ele)
{

    if(!isFull())
        stck[++top]=ele;
    else
        cout<<"Stack overflow\n";
}

template<class X>
void Stack<X>::pop()
{

    if(!isEmpty())
    {
        top--;
    }
    else
        cout<<"Stack underflow\n";
}

template<class X>
X Stack<X>::topel()
{

    if(!isEmpty())
        return stck[top];
    else
    {
        return stck[0];
    }
}

int main()
{
    int op1,ele,num;
    Stack<int> intStack1;

    do
    {
        cout<<"\n\n1) Push element(int).\n2) Pop element(int).\n3) clear Stack.\n4) Display stack.\n5) Exit.\n";
        cout<<"\n\nChoose option: ";
        cin>>op1;
        switch(op1)
        {
        case 1:
            cout<<"\nEnter element: ";
            cin>>ele;
            intStack1.push(ele);
            intStack1.display();
            break;

        case 2:
            intStack1.pop();
            cout<<"\nElement has been removed.";
            intStack1.display();
            break;

        case 3:
            intStack1.Clear();
            cout<<"\nInt Stack has been cleared successfully.\n";
            intStack1.display();
            break;

        case 4:
            intStack1.display();
            break;

        case 5:
            break;

        default:
            cout<<"\nWrong input! ";

        }
    }while(op1!=5);

}
