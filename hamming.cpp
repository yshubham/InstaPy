#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std ;

int main() {
    int a,b,c[30],d,r=0,d1;
    cout<<"Enter number of DataWords"<<endl;
    cin>>a;

    while(a+r+1>pow(2,r)){  // Calculate no of parity bits 
        r++;
    }
    
    cout<<"No of parity bits\t"<<r<<endl<<"Total bits\t"<<a+r<<endl;
    cout<<"Enter data bits one by one "<<endl;
    for(int i=1;i<=a;++i) {
        cin>>c[i];
    }

    cout<<"\nData Words Enteredt";
    for(int i=1;i<=a;++i)
        cout<<c[i]<<" ";
    
    cout<<endl;

    int data[a+r];
     d=0,d1=1;

    for(int i=1;i<=a+r;++i){
        if((i)==pow(2,d)){
            data[i]=7;
            ++d;
        }
        else {
            data[i]=c[d1];
            ++d1;
        }
    }
    cout<<"\nDataWord with Parity(7) \t";
    for(int i=1;i<=a+r;++i)
        cout<<data[i]<<" ";
    
    int min,max=0,parity,s,j;
    d1=0;

    for(int i=1;i<=a+r;i=pow(2,d1)) {
        ++d1;
        parity=0;
        j=i;
        s=i;
        min=1;
        max=i;
        for(j;j<=a+r;) {
            for(s=j;min <= max && s<=a+r;++min,++s){
                if(data[s]==1)
                    parity++ ;}
                j=s+i;
                min=1;
            }
            if(parity%2==0)
                data[i]=0;
            else 
                data[i]=1;
        }
    cout<<endl<<"Hamming code for given data word is   ";
    for(int i=1;i<=a+r;++i)
        cout<<data[i]<<" ";
    return 0;
}
