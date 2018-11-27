#include<iostream>
#include<cstdlib>
using namespace std;

class IntSLLNode
{

public:
    int info;
    IntSLLNode *next;

    IntSLLNode()
    {
        info=0;
        next=NULL;
    }

    IntSLLNode(int val,IntSLLNode* ptr)
    {
        info=val;
        next=ptr;
    }

};


class IntSLL
{


    IntSLLNode* head=NULL;
    IntSLLNode* tail=NULL;

public:

    void addtohead()
    {

        int info;
        cout<<"\nEnter the info: ";
        cin>>info;
        IntSLLNode *node = new IntSLLNode(info,NULL);

        if(head==NULL)
            head=tail=node;
        else
        {
            node->next=head;
            head=node;
        }

        cout<<"\nElement added.";
        traverse();
    }

    void addtotail()
    {
        int info;
        cout<<"\nEnter the info: ";
        cin>>info;
        IntSLLNode *node = new IntSLLNode(info,NULL);

        if(tail==NULL)
            head=tail=node;
        else
        {
            tail->next=node;
            tail=node;
        }
        cout<<"\nElement added.";
        traverse();
    }

    void delfromhead()
    {

        IntSLLNode* temp=head;

        if(head==NULL)cout<<"\nCannot delete, List is Empty.";

        else if(head==tail)
        {
            head=tail=NULL;
            delete temp;
            traverse();
        }
        else if(head!=NULL)
        {
            head=head->next;
            delete temp;
            traverse();
        }

    }

    int search(int var)
    {

        IntSLLNode* p=head;
        int count1=0;

        while(p!=NULL)
        {
            count1++;
            if(p->info==var)return count1;
            p=p->next;
        }
        return -1;
    }

    void delfromtail()
    {

        if(head==NULL)cout<<"\nCannot delete, List is Empty.";

        else if(head==tail)
        {
            delete head;
            head=tail=NULL;
            traverse();
        }
        else
        {

            IntSLLNode* pt=head;
            while(pt->next!=tail)
            {
                pt=pt->next;
            }

            delete tail;
            tail=pt;
            pt->next=NULL;
            traverse();
        }

    }

    void traverse()
    {

        IntSLLNode* p=head;
        cout<<"\nList-> ";

        if(p!=NULL)
        {
            while(p!=NULL)
            {
                cout<<p->info<<"  ";
                p=p->next;
            }
        }
        else cout<<"Empty";

    }

    void addtopos(int);
    void delfrompos(int);
    void reverse();
    IntSLL operator+(IntSLL);
};

void IntSLL::addtopos(int pos)
{

    int info,count1=0;
    IntSLLNode *q,*p=head;
    while(p!=NULL)
    {
        count1++;
        p=p->next;
    }
    if(pos>count1||pos<0)cout<<"\nIndex is not valid.";
    else
    {
        cout<<"\nEnter the info: ";
        cin>>info;
        IntSLLNode *node = new IntSLLNode(info,NULL);
        p=head;
        if(pos==0)
        {
            node->next=head;
            head=node;
        }
        else
        {
            for(int i=0; i<pos-1; i++)
            {
                p=p->next;
            }
            q=p->next;
            node->next=q;
            p->next=node;
        }
        traverse();
    }
}

IntSLL IntSLL::operator+(IntSLL list2)
{
    IntSLLNode *p=list2.head;
    if(p!=NULL)
    {
        if(head==NULL)
        {
            head=tail=p;
            p=p->next;
        }

        while(p!=NULL)
        {
            tail->next=p;
            tail=p;
            p=p->next;
        }
    }
    return *this;
}


void IntSLL::reverse()
{
    IntSLLNode *cur=head,*nextnode=NULL, *prev=NULL;
    while(cur!=NULL)
    {
        nextnode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextnode;
    }
    tail=head;
    head=prev;
}


void IntSLL::delfrompos(int pos)
{

    IntSLLNode *q,*p=head;
    int count1=0;
    while(p!=NULL)
    {
        count1++;
        p=p->next;
    }
    if(pos>=count1||pos<0)cout<<"\nIndex is not valid.";
    else if(head==NULL)cout<<"Can't delete, No element in the list.";
    else
    {
        p=head;
        q=head;
        if(pos==0&&head==tail)
        {
            head=tail=NULL;
            delete p;
        }
        else if(pos==0)
        {
            head=head->next;
            delete p;
        }
        else
        {
            for(int i=0; i<pos; i++)
            {
                if(p!=q)
                    q=q->next;
                p=p->next;
            }
            if(p==tail)
            {
                q->next=NULL;
                delete p;
                tail=q;
            }
            else
            {
                q->next=p->next;
                delete p;
            }
        }
        cout<<"\nElement deleted.";
        traverse();
    }
}


int main()
{
    IntSLL list,list2;
    int ele,pos,ch,num,i;
    do
    {
        cout<<"\n\n MENU::\n1)Add ele to head.\n2)Add ele to tail.\n3)Add ele in a position.\n4)Delete ele from head.\n";
        cout<<"5)Delete ele from tail.\n6)Delete ele from a position.\n7)Traverse.\n8)Reverse the list.\n9)Concatenate two list.\n10)search element.\n11)Exit.\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            list.addtohead();
            break;
        case 2:
            list.addtotail();
            break;
        case 3:
            cout<<"\nEnter the index of the new element: ";
            cin>>pos;
            list.addtopos(pos);
            break;
        case 4:
            list.delfromhead();
            break;
        case 5:
            list.delfromtail();
            break;
        case 6:
            cout<<"\nEnter the index of the element to be deleted: ";
            cin>>pos;
            list.delfrompos(pos);
            break;
        case 7:
            list.traverse();
            break;

        case 8:
            list.reverse();
            cout<<"\nList is reversed\n";
            list.traverse();
            break;

        case 9:
            cout<<"\nEnter the number of elements in another list: ";
            cin>>num;
            for(i=0; i<num; i++)
                list2.addtohead();

            cout<<"\nConcatenated List::";
            list=list+list2;
            list.traverse();
            break;
        case 10:
            cout<<"\nEnter ele to search: ";
            cin>>ele;
            pos=list.search(ele);
            if(pos!=-1)cout<<"\nElement found at index: "<<pos-1<<endl;
            else cout<<"\nElement not found.\n";
            break;
        case 11:
            exit(0);
        default:
            cout<<"\nWrong choice!!";

        }
    }
    while(true);
    return 0;
}
