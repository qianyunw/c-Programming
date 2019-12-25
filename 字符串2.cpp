#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    int i,num10,sum(0),len;
    char answer;
    string num8;
    cout<<"enter\n";
    cin>>num8;
    len=num8.length();
    for(i=len-1;i>=0;i--){
        sum+=pow(8,len-i-1)*(num8[i]-'0');
    }
    cout<<"("<<num8<<")"<<"8 = ("<<sum<<")"<<"10"<<endl<<"again?\n";
    cin>>answer;
    while(answer=='y'){
        sum=0;
        cout<<"enter\n";
        cin>>num8;
        len=num8.length();
        for(i=len-1;i>=0;i--){
        sum+=pow(8,len-i-1)*(num8[i]-'0');
    }
    cout<<"("<<num8<<")"<<"8 = ("<<sum<<")"<<"10"<<endl<<"again?\n";
    cin>>answer;
    }
    cout<<"Bye!\n";
    return 0;
}
