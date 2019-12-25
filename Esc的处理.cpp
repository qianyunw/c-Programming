#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;
int main()
{	int y,m,d;
	char con;
	do
	{	cout<<"Please input Year Month Day:";
		con=getch();
		if(con==27)
			cout<<"Esc\n";
		else
		{	cout.put(con);					//显示字符
			cin.putback(con);			  //放回字符
			cin>>y>>m>>d;
			cout<<y<<" "<<m<<" "<<d<<endl;
			cin.clear();						//清空输入缓冲区
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
	}while(con!=27);
	return 0;
}