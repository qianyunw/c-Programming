#include <iostream>
#include<string.h>
#include <windows.h>
#include<iomanip>

using namespace std;

class  clock
{
private:
    int hour, minute, second;
public:
 	void settime(int newh, int newm, int news);
    void showtime();
	void tick();
};

void clock::settime(int newh, int newm, int news)
{
    hour=newh;
    minute=newm;
    second=news;
}

void clock::showtime()
{
    cout.width(2);
    cout.fill('0');
    cout<<hour<<":";
    cout.width(2);
    cout.fill('0');
    cout<<minute<<":";
    cout.width(2);
    cout.fill('0');
    cout<<second;
}

void clock::tick()
{
    if(second!=59)
        second++;
    else if(minute!=59){
        second=0;
        minute++;
    }
    else if(hour!=23){
        second=0;
        minute=0;
        hour++;
    }
    else{
        second=0;
        minute=0;
        hour=0;
    }
}

int main()
{
    cout<<"It starts working!\n";
    char answer('Y');
    while(answer=='Y'){
        cout<<"Enter hour,minute,second:\n";
        clock myclock;
        int hour, minute, second,timeminute,timesecond,time;
        cin>>hour>>minute>>second;
        cout<<"enter time(minute,second)\n";
        cin>>timeminute>>timesecond;
        time=timeminute*60+timesecond;
        myclock.settime(hour, minute, second);
        while(time--){
            myclock.showtime();
            myclock.tick();
            Sleep(1000);
            cout<<"\b\b\b\b\b\b\b\b\b";
        }
        myclock.showtime();
        myclock.tick();
        cout<<"\ncontinute?(Y/N)\n";
        cin>>answer;
    }
    cout<<"Bye!\n";
    return 0;
}
