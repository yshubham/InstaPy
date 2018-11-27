#include<iostream>
#include<cstdlib>
using namespace std;

class IntSLLNode
{

public:
    int coeff,exp;
    IntSLLNode *next,*prev;

    IntSLLNode()
    {
        coeff=0;
        next=NULL;
        prev=NULL;
    }

};


class Polynomial
{


    IntSLLNode* head=NULL;
    IntSLLNode* tail=NULL;
    int degree;

public:

    void addition(Polynomial eqn1,Polynomial eqn2)
    {

        if(eqn1.degree>=eqn2.degree) degree=eqn1.degree;
        else degree= eqn2.degree;

        IntSLLNode* p1=eqn1.tail, *p2=eqn2.tail;

        while(p1!=NULL && p2!=NULL)
        {

            IntSLLNode *node = new IntSLLNode();

            if(p1->exp==p2->exp)
            {

                if(p1->coeff+p2->coeff == 0)
                {
                    p1=p1->prev;
                    p2=p2->prev;
                    delete node;
                    continue;
                }

                node->coeff=p1->coeff+p2->coeff;
                node->exp=p1->exp;
                p1=p1->prev;
                p2=p2->prev;
            }
            else if(p1->exp>p2->exp)
            {
                node->coeff=p2->coeff;
                node->exp=p2->exp;
                p2=p2->prev;
            }
            else if(p1->exp<p2->exp)
            {
                node->coeff=p1->coeff;
                node->exp=p1->exp;
                p1=p1->prev;
            }

            if(head==NULL)
                head=tail=node;
            else
            {
                head->prev=node;
                node->next=head;
                head=node;
            }

        }

        if(p1!=NULL)
        {
            while(p1!=NULL)
            {
                IntSLLNode *node = new IntSLLNode();
                node->coeff=p1->coeff;
                node->exp=p1->exp;
                if(head==NULL)
                    head=tail=node;
                else
                {
                    head->prev=node;
                    node->next=head;
                    head=node;
                }
                p1=p1->prev;
            }
        }

        if(p2!=NULL)
        {
            while(p2!=NULL)
            {
                IntSLLNode *node = new IntSLLNode();
                node->coeff=p2->coeff;
                node->exp=p2->exp;
                if(head==NULL)
                    head=tail=node;
                else
                {
                    head->prev=node;
                    node->next=head;
                    head=node;
                }
                p2=p2->prev;
            }
        }


    }

    void input()
    {

        int coeff,exp;
        cout<<"\nEnter the degree: ";
        cin>>degree;

        for(int i=degree; i>=0; i--)
        {
            cout<<"\nEnter the coeffcient of x^"<<i<<": ";
            cin>>coeff;
            if(coeff!=0)
            {
                IntSLLNode *node = new IntSLLNode();
                node->exp=i;
                node->coeff=coeff;
                if(tail==NULL)
                    head=tail=node;
                else
                {
                    tail->next=node;
                    node->prev=tail;
                    tail=node;
                }
            }

        }

    }

    void traverse()
    {

        IntSLLNode* p=head;

        cout<<"\nEquation: ";
        if(p!=NULL)
        {
            cout<<p->coeff<<"x^"<<p->exp;
            p=p->next;
        }
        else cout<<" Empty";

        if(p!=NULL)
        {
            while(p!=NULL)
            {
                cout<<" + "<<p->coeff<<"x^"<<p->exp;
                p=p->next;
            }
            cout<<endl;
        }

    }

};


int main()
{

    Polynomial eqn1,eqn2,eqn3;

    cout<<"\nEnter polynomial equation 1::";
    eqn1.input();
    eqn1.traverse();
    cout<<"\n\nEnter polynomial equation 2::";
    eqn2.input();
    eqn2.traverse();

    cout<<"\n\nSum of the polynomial equations::";
    eqn3.addition(eqn1,eqn2);
    eqn3.traverse();


}
