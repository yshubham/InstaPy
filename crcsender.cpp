#include<iostream>

using namespace std;

int main() {
	string msg ,crc , encoded="";
	cout<<"Enter the message";	
	getline(cin,msg);
	cout<<"Enter generator polynomial ";
	getline(cin,crc);
	int m=msg.length();
	int n=crc.length();
	encoded=msg+encoded;
	for(int i=m;i<m+n;i++) {
		encoded[i]+='0'; }
	
	for(int i=0;i<encoded.length()-n+1;) {
		for(int j=0;j<n;j++) {
			encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';
		}
		for(;i<encoded.length() && encoded[i]!='0' ; i++);
	}
	cout<<msg+encoded.substr(encoded.length()-n+1);

}

