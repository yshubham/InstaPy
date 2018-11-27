#include <iostream>
#include <string.h>
 
using namespace std ;
void reverse(char [], int, int);
int main()
{
    char str1[20];
    int size;
 
    cout<<"Enter a string to reverse: "<<endl;
    cin>>str1;
    size = strlen(str1);
    reverse(str1, 0, size - 1);
    cout<<"The string after reversing is:"<<endl<<str1<<endl;
    return 0;
}
 
void reverse(char str1[], int index, int size)
{
    char temp;
    temp = str1[index];
    str1[index] = str1[size - index];
    str1[size - index] = temp;
    if (index == size / 2)
    {
        return;
    }
    reverse(str1, index + 1, size);
}