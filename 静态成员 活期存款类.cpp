#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

# define bank_clerk  1
# define client 0

class date
{
private:
    int year,month;
    static int day;
public:
    date(int dyear,int dmonth)
    {
        year=dyear;
        month=dmonth;
    }
    void show()
    {
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
    void godate()
    {
        if(month<=12)
            month++;
        else
        {
            month=1;
            year++;
        }
    }
    int dyear()
    {
        return year;
    }
    int dmonth()
    {
        return month;
    }
};

class deposit
{
private:
    static int num;
    int selfnum;
    string name;
    string password;
    double money;
    double realmoney;
    static double rate;
    date selfdate;
public:
    deposit(string dname,string dpassword,double dmoney,int dyear,int dmonth):selfdate(dyear,dmonth)
    {
        name=dname;
        password=dpassword;
        money=dmoney;
        realmoney=dmoney;
        num++;
        selfnum=num;
    }

    deposit():selfdate(0,0)
    {
        name="0";
        password="0";
        money=0;
        num=0;
    }

    void judge()
    {
        int i=1;
        string jpassword;
        cout<<"Please enter your password:\n";
        cin>>jpassword;
        while(jpassword!=password&&i!=3)
        {
            cout<<"your password is wrong, you only have "<<3-i<<" chance(s)";
            cin>>jpassword;
            i++;
        }
        if(i!=3||jpassword==password)
        {
            cout<<"account number:\tname:\tmoney:\t\trate:\topen time\n";
            cout<<"   "<<selfnum<<"\t"<<setw(13)<<name<<setw(11)<<fixed<<setprecision(2)<<money+0.005<<"\t"<<rate*100<<"%"<<"\t";
            selfdate.show();
            cout<<endl;
        }
        else
        {
            cout<<"Sorry, your password is wrong, we can't show your information\n";
        }
    }

    void gomoney()
    {
            money=money+money*rate;
    }

    void initialmoney(int nowyear,int nowmonth)
    {
        int i,n;
        n=(nowyear-selfdate.dyear())*12+(nowmonth-selfdate.dmonth());
        for(i=1;i<=n;i++)
        {
            money=money+money*rate;
        }
    }


    void setrate(double newrate)
    {
        rate=newrate;
    }

    void show()
    {
        cout<<"   "<<selfnum<<"\t"<<setw(13)<<name<<setw(11)<<fixed<<setprecision(2)<<money+0.005<<"\t"<<rate*100<<"%"<<"\t";
        selfdate.show();
        cout<<endl;
    }
};

int deposit::num=0;
double deposit::rate=0.005;
int date::day=1;

int main()
{
    char option;
    deposit p[100];
    int all=0;
    int nownum=0;

    int nowyear,nowmonth;
    cout<<"Please enter this year and month:\t";
    cin>>nowyear>>nowmonth;
    date nowdate(nowyear,nowmonth);

    # if bank_clerk

	p[1]=deposit("Zhangsan","123456",10000,2010,3);
	p[2]=deposit("Lisi","112233",20000,2010,2);
	p[3]=deposit("Wangwu","111111",15000,2010,5);
	p[4]=deposit("Zhaoliu","222222",58000,2010,7);
	p[5]=deposit("Zhouqi","888888",50000,2010,3);

	int i;

	for(i=1;i<=5;i++)
    {
        p[i].initialmoney(nowyear,nowmonth);
    }

	do
    {
        cout<<"please enter your option:\n";
        cout<<"1-adjust the rate\n";
        cout<<"2-check all the clients\n";
        cout<<"3-exit this month\n";
        cout<<"4-exit all\n";

        cin>>option;

        if(option!='3')
        {
            nowdate.show();

            if(option=='1')
            {
                double newrate;
                cout<<"Please enter your new rate:\t";
                cin>>newrate;
                p[1].setrate(newrate);
            }
            if(option=='2')
            {
                int i;
                cout<<"account number:\tname:\tmoney:\t\trate:\topen time\n";
                for(i=1;i<=5;i++)
                {
                    p[i].show();
                }
            }
        }
        else
        {
            nowdate.godate();
            for(i=1;i<=5;i++)
            {
                p[i].gomoney();
            }
        }

    }while(option=='1'||option=='2'||option=='3');
    # endif

    # if client
	do
    {
        cout<<"please enter your option:\n";
        cout<<"1-open a new account\n";
        cout<<"2-check your account\n";
        cout<<"3-exit this month\n";
        cout<<"4-exit all\n";

        cin>>option;

        if(option!='3')
        {
            nowdate.show();
            if(option=='1')
            {
                string name;
                string password;
                double money;
                int year,month;
                nownum++;
                cout<<"Please enter your name, password, money and your open time:\n";
                cin>>name>>password>>money>>year>>month;
                p[nownum]=deposit(name,password,money,year,month);
                cout<<"please remember your account number and password\n";
                p[nownum].show();
                p[nownum].initialmoney(nowyear,nowmonth);
                all++;
            }
            if(option=='2')
            {
                int selfnum;
                cout<<"Please enter your account number:\t";
                cin>>selfnum;
                p[selfnum].judge();
            }
        }
        else
        {
            nowdate.godate();
            int i;
            for(i=1;i<=all;i++)
            {
                p[i].gomoney();
            }
        }

    }while(option=='1'||option=='2'||option=='3');

   #endif

    return 0;
}
