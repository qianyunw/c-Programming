#include<iostream>
#include<string.h>

using namespace std;

struct lian
{
    string name;
    lian *next;
};

lian *head,*realhead;

int main()
{
    int n,i,time,d;
    char answer;
    cout<<"let's start!\n";
    do{
    cout<<"enter n and d:\n";
    cin>>n>>d;
    cout<<"enter people's names:\n";
    head=new lian;
    realhead=head;
    for(i=0;i<n-1;i++)
    {
        cin>>head->name;
        head->next=new lian;
        head=head->next;
    }
    cin>>head->name;
    head->next=realhead;
    head=realhead;
    cout<<"the end\n";
    for(time=1;time<d;time++){
            realhead=head;
            head=head->next;
    }
    cout<<head->name<<" ";
    realhead->next=head->next;
    delete head;
    head=realhead;
    n--;
    while(n!=1){
        for(time=1;time<=d;time++){
            realhead=head;
            head=head->next;
        }
        cout<<head->name<<" ";
        realhead->next=head->next;
        delete head;
        head=realhead;
        n--;
    }
    cout<<head->name<<endl;
    delete head;
    cout<<"continue?\n";
    cin>>answer;
    }while(answer=='Y');
    cout<<"By!";
    return 0;
}
