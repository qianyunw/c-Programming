
// 5.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
using namespace std;

struct student{
		string xi;
		string ji;
		string sex;
		string name;
	}stu[10];

void printf(int i,string xingming,string xingbie="nan",string jibie="2014",string xibie="jisuanji"){
	stu[i].name=xingming;
	stu[i].xi=xibie;
	stu[i].ji=jibie;
	stu[i].sex=xingbie;
}

int main()
{
	int i,j;
	string xingming,xibie,jibie,xingbie;
	string first;
	for(i=0;i<10;i++){
		cout<<"student information:\n";
		j=1;
		cin>>first;
		while(first=="0"){
			cin>>first;
			j++;
		}
		if(j==1){
			cin>>jibie>>xingbie>>xingming;
			printf(i,xingming,xingbie,jibie,first);
		}
		if(j==2){
			cin>>xingbie>>xingming;
			printf(i,xingming,xingbie,first);
		}
		if(j==3){
			cin>>xingming;
			printf(i,xingming,first);
		}
		if(j==4){
			printf(i,first);
		}
	}
	for(i=0;i<10;i++){
		cout<<stu[i].xi<<endl;
		cout<<stu[i].ji<<endl;
		cout<<stu[i].sex<<endl;
		cout<<stu[i].name<<endl;
	}
	return 0;
}
