#include <iostream>

using namespace std;

#define SIZE 10

template<class X>
class Queue{

X Q[SIZE];
int first,last;

public:
Queue(){
first=last=-1;
}

void Clear(){
first=last=-1;
}

bool isFull(){
  if((first==0&&last==SIZE-1)||(first==last+1) ) return true;
  else return false;
}

bool isEmpty(){
  if(first==-1)return true;
  else return false;
}

void enqueue(X);
X dequeue();

void display(){
  int i;

  if(!isEmpty()){
    cout<<"\nQueue: ";

    for(i=first;i!=last;i=((i+1)%SIZE))
        cout<<Q[i]<<"  ";
      cout<<Q[last];
  }
   cout<<endl;
}

};

template<class X>
void Queue<X>::enqueue(X ele){
    if(!isFull()){
        if(last==-1){first=last=0;}
        else if(last==SIZE-1){last=0;}
        else last++;

        Q[last]=ele;
        display();

    }
    else cout<<"\nQueue is Full!!\n";
}

template<class X>
X Queue<X>::dequeue(){

   if(!isEmpty()){
      X temp= Q[first];

     if(first==last){
        first=last=-1;
        display();
     }
     else if(first==SIZE-1){
         first=0;
         display();
     }
     else {
        first++;
        display();
     }
       return temp;
   }
   else cout<<"\nQueue is Empty!!\n";
    return Q[0];
}

int main()
{
  cout<<"Queue Using Circular Array\n";
  Queue<int> Q1;
  Q1.enqueue(10);
  Q1.enqueue(20);
  Q1.enqueue(20);
  Q1.enqueue(50);
  Q1.dequeue();
  Q1.dequeue();
  Q1.enqueue(15);
  Q1.enqueue(25);
  Q1.enqueue(90);
  Q1.enqueue(60);
  Q1.enqueue(70);
  Q1.enqueue(55);
  Q1.enqueue(35);
  Q1.dequeue();
  Q1.enqueue(45);
  Q1.enqueue(15);
  Q1.enqueue(40);

}
