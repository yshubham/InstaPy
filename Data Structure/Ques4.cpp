//Perform Push , Pop , CLear using linked list 
#include<iostream>
#include<cstdlib>
using namespace std;

class StackNode
{

public:

    int info;
    StackNode *next;

    StackNode()
    {
        info=0;
        next=NULL;
    }

    StackNode(int val,StackNode* ptr)
    {
        info=val;
        next=ptr;
    }

};


class Stack
{
    StackNode* top=NULL;

public:

    void push()
    {   
        int info;
        cout<<"\nEnter the info: ";
        cin>>info;
        StackNode *node = new StackNode(info,NULL);
        if(top==NULL)
            top=node;
        else
        {
            node->next=top;
            top=node;
        }
    }

    void pop()
    {
        StackNode* temp=top;
        if(top==NULL)cout<<"\nCannot delete, Stack is Empty.";
        else
        {
            top=top->next;
            delete temp;
        }
    }

    /**  Search In Stack
     int search(int var)
    {
        StackNode* p=top;
        int count1=0;
        while(p!=NULL)
        {
            count1++;
            if(p->info==var)return count1;
            p=p->next;
        }
        return -1;
    }
    **/
    
    void traverse()
    {
        StackNode* p=top;
        cout<<"\nTop-> ";
        if(p!=NULL)
        {
            while(p!=NULL)
            {
                cout<<p->info<<"  ";
                p=p->next;
            }
        }
        else cout<<"Empty\n";
    }
    

    void clearStack(){
     int len=0;
     StackNode* p=top;
     while(p!=NULL){
        len++;
        p=p->next;
     }

     while(len--)
        pop();

      return;
    }   

};

int main()
{
    Stack stack1;
    char ch;
    int ele,pos;
    cout<<"STACK Using Linked list\n";
    do
    {
        cout<<"\n\nMENU::\n1)Push an element.\n2)Pop an element.\n";
        cout<<"3)Clear the Stack.\n4)Exit.\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case '1':
            stack1.push();
            cout<<"\nElement added.\n";
            stack1.traverse();
            break;
        case '2':
            stack1.pop();
            cout<<"\nElement deleted.\n";
            stack1.traverse();
            break;
        case '3':
           stack1.clearStack();
                  stack1.traverse();
                  break;
        case '4':
            exit(0);
        default:
            cout<<"\nWrong choice!!";

        }
    }
    while(true);
    return 0;
}
