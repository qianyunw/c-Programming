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
		{	cout.put(con);					//��ʾ�ַ�
			cin.putback(con);			  //�Ż��ַ�
			cin>>y>>m>>d;
			cout<<y<<" "<<m<<" "<<d<<endl;
			cin.clear();						//������뻺����
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
	}while(con!=27);
	return 0;
}