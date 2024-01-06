
#include <iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
bool validateNumber(char *str)
{
    if(str==NULL)
        return 0;
    else
    {
        while(*str)
        {
        if(!isdigit(*str))
            return false;
        str++;
        }
    return true;
    }
}
bool validateIPAddress(char *str)
{
    char *token;
    int num;
    int dot=0;
    if(str==NULL)
        return 0;
    else
    {
        token = strtok(str,".");
        if(token==NULL)
            return 0;
        while(token)
        {
            if(!validateNumber(token))
                return 0;
            num = atoi(token);
            if(num>=0 && num<=255)
            {
                token =strtok(NULL,".");
                if(token!=NULL)
                   ++dot;
            }
            else
                return 0;
        }
        if(dot!=3)
            return 0;
        else
            return 1;
    }
}
int main()
{
    cout<<"Hello World";
    char ip[]="123.23.23.";
   /* cout<<"\n is 23 a number : "<<validateNumber("23")<<endl;
    cout<<"\n is 23C a number : "<<validateNumber("23C")<<endl;
    cout<<"\n is AB a number : "<<validateNumber("AB")<<endl;
    */
    cout<<"\n 123.23.23.124 is valid IP address : "<<validateIPAddress(ip)<<endl;
    
    return 0;
}
