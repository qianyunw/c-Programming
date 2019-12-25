#include<iostream>
#include<string.h>
#include<math.h>
#include <iomanip>

using namespace std;

int monthday[2][13]={0,31,28,31,30,31,30,31,31,30,31,30,31,0,31,29,31,30,31,30,31,31,30,31,30,31};
string tweekform[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
string weekform[7]={"Su","Mo","Tu","We","Th","Fr","Sa"};

class calender
{
private:
    int year;
    int month;
    int day;
    int yearstart;
    int weekstart;
    int rui;
    string week;
    int monthform[12][5][7];
public:
    void settime(int nyear,int nmonth,int nday);
    void setmonthform();
    void showweek();
    void showmonth();
    void showcalender(int line);
};

void calender::settime(int nyear,int nmonth,int nday)
{
    rui=0;
    year=nyear;
    month=nmonth;
    day=nday;
    if(year%4==0&&year%100!=0||year%400==0)
        rui=1;
}

void calender::setmonthform()
{
    int i,j,tmonth,tday;
    for(tmonth=0;tmonth<12;tmonth++)
        for(i=0;i<5;i++)
            for(j=0;j<7;j++)
                monthform[tmonth][i][j]=0;
    for(tmonth=0;tmonth<12;tmonth++){
        weekstart=(year+(year-1)/4-(year-1)/100+(year-1)/400)%7;
        for(i=1;i<=tmonth;i++){
            weekstart+=monthday[rui][i];
        }
        weekstart=(weekstart)%7;
        monthform[tmonth][0][weekstart]=1;
        for(j=(weekstart+1)%7,tday=2;j<7;tday++,j++){
            monthform[tmonth][0][j]=tday;
        }
        for(i=1;i<5;i++){
            for(j=0;tday<=monthday[rui][tmonth+1]&&j<7;tday++,j++){
            monthform[tmonth][i][j]=tday;
            }
        }
    }
}

void calender::showweek()
{
    int i;
    yearstart=(year+(year-1)/4-(year-1)/100+(year-1)/400)%7;
    for(i=1;i<=month-1;i++){
        yearstart+=monthday[rui][i];
    }
    yearstart=(yearstart+day-1)%7;
    cout<<year<<"-"<<month<<"-"<<day<<"\t"<<tweekform[yearstart];
}

void calender::showmonth()
{
    int i,j;
    cout<<endl<<setw(36)<<year<<"\t"<<month<<endl<<endl<<setw(20)<<" ";
    for(i=0;i<7;i++){
        cout<<weekform[i]<<"  ";
    }
    cout<<endl;
    for(i=0;i<5;i++){
        cout<<setw(20)<<" ";
        for(j=0;j<7;j++){
            if(monthform[month-1][i][j]!=0)
                cout<<setw(2)<<monthform[month-1][i][j]<<"  ";
            else
                cout<<setw(2)<<" "<<"  ";
        }
        cout<<endl;
    }
}

void calender::showcalender(int line)
{
    int dai,daj,i,j,tmonth;
    for(dai=0,tmonth=0;tmonth<12;dai++){
        for(daj=0;daj<line-1;daj++){
            cout<<setw(10)<<" "<<setw(2)<<line*dai+daj+1<<setw(10)<<" ";
        }
        cout<<setw(10)<<" "<<setw(2)<<line*dai+daj+1;
        cout<<endl;
        for(daj=0;daj<line;daj++){
            for(i=0;i<7;i++){
                cout<<weekform[i]<<" ";
            }
            cout<<"  ";
        }
        cout<<endl;
        for(i=0;i<5;i++){
            for(daj=0;daj<line&&tmonth<12;daj++,tmonth++){
                for(j=0;j<7;j++){
                if(monthform[tmonth][i][j]!=0)
                    cout<<setw(2)<<monthform[tmonth][i][j]<<" ";
                else
                    cout<<setw(2)<<" "<<" ";
                }
                cout<<"  ";
            }
            tmonth-=line;
            cout<<endl;
        }
        tmonth+=line;
    }
}

int main()
{
    cout<<"Please input year,month,day:\n";
    int year, month ,day,line;
    cin>>year>>month>>day;
    calender my;
    while(year!=0){
        my.settime(year, month ,day);
        my.setmonthform();
        my.showweek();
        my.showmonth();
        cout<<"Here show year calender of 2010\nHow many months do you want to see in 1 line?(1~3):\n";
        cin>>line;
        my.showcalender(line);
        cout<<"Please input year,month,day:\n";
        cin>>year>>month>>day;
    }
    cout<<"Year value error!\n";
    return 0;
}
