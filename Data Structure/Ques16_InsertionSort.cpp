#include<iostream>
#define SIZE 100
using namespace std;


int insertion(int[],int);

int main()
{
int ar[SIZE],n,i;
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
   cout<<"\n\nInsertion sort initiated..\n";

   insertion(ar,n); 

   cout<<"\n\nPress 'Y' to sort another array. Press 'T' to terminate: ";
   cin>>ch;
}while(ch=='y'||ch=='Y');

return 0;
}

int insertion(int ar[], int n)
{
 int i,j,k,temp;
 for(i=0;i<n;i++)
 {  
   temp=ar[i];
   j=i-1;
   
  while(j>=0&&ar[j]>temp)
  {
   ar[j+1]=ar[j];
   j--;
  }
  ar[j+1]=temp;
 cout<<"\nArray after iteration "<<i<<":  ";
 for(k=0;k<n;k++)
 cout<<ar[k]<<"    ";
}

cout<<"\nArray after iteration "<<n<<",Sorted array:  ";
for(i=0;i<n;i++)
cout<<ar[i]<<"    ";  

return 0;
}
