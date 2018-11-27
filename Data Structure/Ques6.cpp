#include<iostream>
#include<cstdlib>
using namespace std;

class QueueNode
{

public:
    int info;
    QueueNode *next;

    QueueNode()
    {
        info=0;
        next=NULL;
    }

    QueueNode(int val,QueueNode* ptr)
    {
        info=val;
        next=ptr;
    }

};


class Queue
{
    QueueNode* first=NULL;
    QueueNode* last=NULL;

public:

    void enqueue()
    {
        int info;
        cout<<"\nEnter the info: ";
        cin>>info;
        QueueNode *node = new QueueNode(info,NULL);
        if(last==NULL)
            first=last=node;
        else
        {
            last->next=node;
            last=node;
        }
    }

    void dequeue()
    {
        QueueNode* temp=first;
        if(first==NULL)cout<<"\nCannot delete, Queue is Empty.";
        else if(first==last)
        {
            first=last=NULL;
            delete temp;
        }
        else if(first!=NULL)
        {
            first=first->next;
            delete temp;
        }
    }

    void traverse()
    {
        QueueNode* p=first;
        cout<<"\nQueue-> ";
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
};

int main()
{
    Queue queue1;
    char ch;
    int ele,pos;
    cout<<"\nQUEUE Using Linked queue1.";
    do
    {
        cout<<"\n\nMENU::\n1)Enqueue Element.\n2)Dequeue Element.\n";
        cout<<"3)Exit.\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case '1':
            queue1.enqueue();
            cout<<"\nElement added.\n";
            queue1.traverse();
            break;
        case '2':
            queue1.dequeue();
            cout<<"\nElement deleted.\n";
            queue1.traverse();
            break;
        case '3':
            exit(0);
        default:
            cout<<"\nWrong choice!!";

        }
    }while(true);

    return 0;
}
