#include<iostream>

using namespace std;

int bubble(int[],int);

int main()
{
int ar[50],n,i;
char ch;

do{
   
   do{ 
      cout<<"\nEnter the no. of elements you want in the array: ";
      cin>>n;
      if(n<=0)cout<<"\nInvalid input. Try Again.\n";  
     }while(n<=0); 
   for(i=0;i<n;i++)
   {
    cout<<"\nEnter Element no. "<<i+1<<": ";
    cin>>ar[i];
   }
   cout<<"\n\nBubble sort initiated..\n";

   bubble(ar,n); 

   cout<<"\n\nPress 'Y' to sort another array. Press 'T' to terminate: ";
   cin>>ch;
}while(ch=='y'||ch=='Y');

return 0;
}

int bubble(int ar[], int n)
{
int i,j,k,temp;

 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
    if(ar[j]>ar[j+1])
    { 
      temp= ar[j];
      ar[j]=ar[j+1];
      ar[j+1]=temp;
    }
  }
 
 cout<<"\nArray after iteration "<<i+1<<":  ";
 for(k=0;k<n;k++)
 cout<<ar[k]<<"    "; 
 }

cout<<"\nArray after iteration "<<n<<", Sorted Array: ";
for(i=0;i<n;i++)
cout<<ar[i]<<"    ";

return 0;
}

