#include<iostream>

using namespace std;

struct lian
{
    int num;
    lian *next;
};

lian *head,*realhead;

int main()
{
    int n,i;
    cin>>n;
    head=new lian;
    realhead=head;
    for(i=0;i<n-1;i++)
    {
        cin>>head->num;
        head->next=new lian;
        head=head->next;
    }
    cin>>head->num;
    head->next=NULL;
    for(i=0;i<n;i++){
        cout<<realhead->num<<" ";
        head=realhead;
        realhead=realhead->next;
        delete head;
    }
    cout<<endl;
    delete realhead;
    delete head;
}
