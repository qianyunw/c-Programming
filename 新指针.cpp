// ĞÂÖ¸Õë.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	void fun(int* x,int* y,int* z);
	int x,y,z;
	cin>>x>>y>>z;
	fun(&x,&y,&z);
	cout<<x<<" "<<y<<" "<<z<<"\n";
	return 0;
}
void fun(int* x,int* y,int* z){
	int t;
	if(*x>*y){
		t=*x;*x=*y;*y=t;
	}
	if(*y>*z){
		t=*y;*y=*z;*z=t;
	}
	if(x>y){
		t=*x;*x=*y;*y=t;
	}
}