#include<iostream>
#include<string.h>
using namespace std ;

int main() {
    string msg, crc;
    cout<<"Enter the Message received ";
    getline(cin,msg);
    int m=msg.length();

    cout<<"Enter crc Polynomial ";
    getline(cin,crc);
    int c=crc.length();

    for(int i=0;i<m-c;){
        for(int j=0;j<c;j++){
            msg[i+j]=msg[i+j]==crc[j]?'0':'1';
        }

        for(;i<m && msg[i]!='1';i++);
    }

    for(char i: msg.substr(m-c)) {
        if(i!='0'){
            cout<<"Error in communication ";
            return 0; }
        else cout<"success ";
    }
       

}
