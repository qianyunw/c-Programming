// ´«Öµ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x,y,z,t;
	cin>>x>>y>>z;
		if(x>y){
		t=x;x=y;y=t;
	}
	if(y>z){
		t=y;y=z;z=t;
	}
	if(x>y){
		t=x;x=y;y=t;
	}
	cout<<x<<" "<<y<<" "<<z<<"\n";
	return 0;
}
