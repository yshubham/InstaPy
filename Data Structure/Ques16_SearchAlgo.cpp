#include<iostream>
#define SIZE 100
using namespace std;

int binary(int ar[], int size,int ele)
{
    int i,mid,min=0, max=size-1,found=0;

    while(min<=max)
    {
        mid=(min+max)/2;

        if(ar[mid]==ele)
        {
            found=1;
            break;
        }

        else if(ele<ar[mid])
            max=mid-1;

        else
            min=mid+1;

    }

    return found;

}

int linear(int ar[],int size,int ele)
{
    int i,found=0;
    for(i=0; i<size; i++)
    {
        if(ele==ar[i])
            break;
        found++;
    }
    if(found<size)
        return found;

    return -1;
}


int main()
{
    int n,i,ch,ele,pos;
    int ar[SIZE];

    do
    {
        cout<<"\nMenu::\n1)Implement Linear Search.\n2)Implement Binary search.\n3)Exit.\n";

        cout<<"\nSelect: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the size of the array: ";
            cin>>n;

            cout<<"\n\nEnter the array::";
            for(i=0; i<n; i++)
            {
                cout<<"\nar["<<i<<"]= ";
                cin>>ar[i];
            }
            cout<<"\nEnter the element to search: ";
            cin>>ele;
            pos=linear(ar,n,ele);
            if(pos)cout<<"\nElement found at index: "<<pos<<endl;
            else if(pos==-1) cout<<"\nElement not found!!";
            break;

        case 2:
            cout<<"\nEnter the size of the array: ";
            cin>>n;
            cout<<"\n\nEnter the array:: (Must be Sorted).";
            for(i=0; i<n; i++)
            {
                cout<<"\nar["<<i<<"]= ";
                cin>>ar[i];
            }
            cout<<"\nEnter the element to search: ";
            cin>>ele;
            if(binary(ar,n,ele))cout<<"\nElement found!\n";
            else cout<<"\nElement not found!!";
            break;
        case 3:
            return 0;
        }
    }
    while(true);

    return 0;
}