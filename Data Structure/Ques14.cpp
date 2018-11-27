#include<iostream>
#include<cstdlib>
using namespace std;

class IntOSLLNode{

 public:
  int info;
  IntOSLLNode *next;

IntOSLLNode(){
info=0;
next=NULL;
}

IntOSLLNode(int val,IntOSLLNode* ptr){
info=val;
next=ptr;
}

};


class IntOSLL{

IntOSLLNode* head=NULL;
IntOSLLNode* tail=NULL;

public:

int search(int var){

IntOSLLNode* p=head;
int count1=0;
while(p!=NULL){
    count1++;
	if(p->info==var)return count1;
	p=p->next;
	}

return -1;

}


void traverse(){

IntOSLLNode* p=head;
cout<<"\nList-> ";
if(p!=NULL){

	while(p!=tail->next){
	cout<<p->info<<"  ";
	p=p->next;
	}
}
else cout<<"Empty";
}


void del(int);
void add(int);
void mergeList(IntOSLL);

};

void IntOSLL::del(int val){
	if(head==NULL)cout<<"\nNo element deleted.";
	else if(head==tail){
		if(head->info==val){
		delete head;
 		head=NULL;
		tail=NULL;
		}
	}
	else{
	IntOSLLNode* cur=head;
	IntOSLLNode* prev=head;
	while(cur!=NULL&&cur->info!=val){
		if(cur!=prev)prev=prev->next;
		cur=cur->next;
	}

	if(cur==NULL)cout<<"No element is equal to "<<val<<" in the list!\n";
	else if(cur==head){
        	head=head->next;
		delete cur;
		cur=NULL;
	}
	else if(cur==tail){
        	delete tail;
        	tail=prev;

	}
	else{
		prev->next=cur->next;
		delete cur;
	    }
	}
}


void IntOSLL::add(int val){

IntOSLLNode* node=new IntOSLLNode(val,NULL);

if(head==NULL)
   head=tail=node;

else if(head!=NULL){

IntOSLLNode* p=head;

if(node->info<=head->info){
 	node->next=head;
	head=node;
}
else if(node->info > tail->info){
	tail->next=node;
	tail=node;
	}
else{
    IntOSLLNode* q=p->next;
	while(q!=NULL){

		if(node->info >= p->info && node->info < q->info){
			node->next=q;
 			p->next=node;
            break;
		}
        p=p->next;
        q=q->next;
	}
}

}
}

void IntOSLL::mergeList(IntOSLL list2){
     IntOSLL list3;
     IntOSLLNode *p1=head, *p2=list2.head;

     while(p1!=NULL&&p2!=NULL){
        if(p1->info>=p2->info){list3.add(p1->info); p1=p1->next; }
        else {list3.add(p2->info); p2=p2->next; }
     }

     if(p1!=NULL){
        while(p1!=NULL){
          list3.add(p1->info);
          p1=p1->next;
        }
     }

      if(p2!=NULL){
         while(p2!=NULL){
            list3.add(p2->info);
            p2=p2->next;
        }
     }

     cout<<"\nMerged sorted list is: \n";
     list3.traverse();
}


int main(){

IntOSLL list,list2;
int ele,pos,ch1,num,i;

do{
	cout<<"\nMENU::\n1)Add Element.\n2)Delete Element.\n3)Merge two list.\n4)Traverse.\n5)search element.\n6)Exit.\n";
	cout<<"\nEnter your choice: ";
	cin>>ch1;
	switch(ch1){
		case 1: cout<<"\nEnter element to add: ";
	                  cin>>ele;
	        	  list.add(ele);
	        	  list.traverse();
	 		  break;
		case 2: cout<<"\nEnter element to delete: ";
	                  cin>>ele;
	                  list.del(ele);
	                  list.traverse();
	 		  break;

	 	case 3:cout<<"\nEnter the number of elements in another list: ";
            cin>>num;
            for(i=0; i<num; i++){
                cout<<"\nEnter ele: ";
                cin>>ele;
                list2.add(ele);
            }
            list.mergeList(list2);
            break;

		case 4:list.traverse();
			  break;

		case 5:cout<<"\nEnter ele to search: ";
		          cin>>ele;
		          pos=list.search(ele);
		          if(pos!=-1)cout<<"\nElement found at position: "<<pos;
		          else cout<<"\nElement not found.";
			  break;
		case 6:exit(0);

		default: cout<<"\nWrong choice!!";

		}
}while(true);

return 0;

}
