#include<iostream>

using namespace std;

int selection(int[],int);

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
   cout<<"\n\nSelection sort initiated..\n";

   selection(ar,n); 

   cout<<"\n\nPress 'Y' to sort another array. Press 'T' to terminate: ";
   cin>>ch;
}while(ch=='y'||ch=='Y');

return 0;
}

int selection(int ar[], int n)
{
int i,j,k,index,temp;
for(i=0;i<n-1;i++)
{
 index=i;
  for(j=i+1;j<n;j++)
    if(ar[j]<ar[index])
      index=j;   

   temp=ar[i];
   ar[i]=ar[index];
   ar[index]=temp; 
  
 cout<<"\nArray after iteration "<<i+1<<":  ";
 for(k=0;k<n;k++)
 cout<<ar[k]<<"    ";
}

cout<<"\nArray after iteration "<<n<<",Sorted array:  ";
for(i=0;i<n;i++)
cout<<ar[i]<<"    ";
return 0;
}
