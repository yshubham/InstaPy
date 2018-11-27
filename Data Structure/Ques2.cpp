#include <iostream>

using namespace std;

int power(int b,int r){
    if(r!=0)
        return (b*power(b,r-1));
    else 
        return 1;
}

int main()
{
    int b,r;
    cout<<"Enter base"<<endl;
    cin>>b;
    cout<<"Enter Power raised "<<endl;
    cin>>r;
    cout<<"b^r = "<<power(b,r);
}
