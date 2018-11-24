#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
using namespace std;

int out_ip(int a[])
{
    int flag=1;
    for(int i=3;i>=0;i--)
    {
        if(i==3)
        cout<<a[i];
        else
        cout<<"."<<a[i];
    }
    for(int i=0;i<4;i++)
    if(a[i]>255)
    {
        flag=-1;
        cout<<endl<<"The given ip address is invalid"<<endl;
        break;
    }
    return flag;	
}
void convert(char ip[],int a[])
{
    int h=3, g;
    for(int i=0;i<=15;i++)
    {
        g=0;
        if(isdigit(ip[i]))       {
            g=(int)ip[i]-'0';
            a[h]=a[h]*10+g;    
        }
        else {
            h--;
        }
    }
} 

int main()
{
    int *a,l,n,cl,k=1;
    char ch1,ip[15];
        
    a=new int[4];
    cout<<"Enter the dataword in dotted decimal notation"<<endl;
    cin>>ip;
    for(int i=3;i>=0;i--)
    a[i]=0;

    convert(ip,a);
    cout<<"THe given ip address is : ";
    k=out_ip(a);
        if(k==-1)
{
        cout<<endl<<"Enter the dataword in dotted decimal notation"<<endl;
        cin>>ip;
        convert(ip,a);
        cout<<"The given IP Address is : ";
        out_ip(a);
    }
    
    if((a[3]>=0)&&(a[3]<=127))
        {
            cout<<"CLASS A"<<endl;
        }
    else if((a[3]>=128)&&(a[3]<=191))
        {    
            cout<<"CLASS B"<<endl;
        }
    else if((a[3]>=192)&&(a[3]<=223))
        {
            cout<<"CLASS C"<<endl;
        }
    else if((a[3]>=224)&&(a[3]<=239))
        {   
            cout<<"CLASS D"<<endl;
        }
    else{
            cout<<"CLASS E"<<endl;   
        }
return 0;
} 
