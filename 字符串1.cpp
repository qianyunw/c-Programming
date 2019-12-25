#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i(0),count(0),n;
    string sentence;
    cout<<"enter\n";
    getline(cin,sentence);
    n=sentence.length()-3;
    while(i<n-4){
        if(sentence[i]==' '&&sentence[i+1]=='t'&&sentence[i+2]=='h'&&sentence[i+3]=='e'&&sentence[i+4]==' ')
        {count++;}
        i++;
    }
    cout<<"your input:\n"<<sentence<<endl<<"the number of \"the\" is\n"<<count<<endl;
    return 0;
}
