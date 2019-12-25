#include<iostream>
using namespace std;

class CMoney
{
public:
    CMoney();
    CMoney(int nyuan, int njiao, int nfen);
    CMoney(CMoney &c);
    ~CMoney();
    void SetValue(int nyuan,int njiao,int nfen)
    {
        yuan=nyuan;
        jiao=njiao;
        fen=nfen;
    }
    void Show()
    {
        cout<<yuan<<"$"<<jiao<<"$"<<fen<<"$"<<endl;
    }
    int GetYuan()
    {
        return yuan;
    }
    int GetJiao()
    {
        return jiao;
    }
    int GetFen()
    {
        return fen;
    }
private:
    int yuan,jiao,fen;
};

CMoney::CMoney(){
    yuan=0;
    jiao=0;
    fen=0;
    cout<<"calling the parameterless constructor."<<endl;
}
CMoney::CMoney(int nyuan, int njiao, int nfen){
    yuan=nyuan;
    jiao=njiao;
    fen=nfen;
    while(fen>=10){
        fen-=10;
        jiao++;
    }
    while(jiao>=10){
        jiao-=10;
        yuan++;
    }
    cout<<"calling the parameter constructor."<<endl;
}
CMoney::CMoney(CMoney &c){
    yuan=c.yuan;
    jiao=c.jiao;
    fen=c.fen;
    cout<<"calling the copy constructor."<<endl;
}
CMoney::~CMoney(){
    cout<<"calling the destructor ."<<endl;
}

int main()
{
    int yuan,jiao,fen,i;
    cin>>yuan>>jiao>>fen;
    cout<<"ordinary variables:"<<endl;
    CMoney m1;
    m1.Show();
    m1.~CMoney();
    CMoney m2(yuan,jiao,fen);
    m2.Show();
    m2.~CMoney();
    CMoney m3(m2);
    m3.Show();
    m3.~CMoney();
    cout<<endl;

    cout<<"pointer variables:"<<endl;
    CMoney *p1=new CMoney;
    p1->Show();
    p1->~CMoney();
    CMoney *p2=new CMoney (yuan,jiao,fen);
    p2->Show();
    p2->~CMoney();
    CMoney *p3=new CMoney(*p2);
    p3->Show();
    p3->~CMoney();
    delete p1;
    delete p2;
    delete p3;
    cout<<endl;

    cout<<"array variables:"<<endl;
    CMoney money1[3];
    for(i=0;i<3;i++){
        money1[i].Show();
        money1[i].~CMoney();
    }
    CMoney money2[3];
    for(i=0;i<3;i++){
        money2[i]=CMoney(yuan,jiao,fen);
        money2[i].Show();
        money2[i].~CMoney();
    }
    CMoney money3[3];
    for(i=0;i<3;i++){
        money3[i]=CMoney(money2[i]);
        money3[i].Show();
        money3[i].~CMoney();
    }
    cout<<endl;
    return 0;
}
