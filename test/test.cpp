#include<iostream>
using namespace std;
int main(){
     char* s=new char[10];
    // s="hello";
    cin>>s;
    char* s1=new char[10];
    cin>>s1;
    cout<<s[2];//可以下标？
    s1=nullptr;
    cout<<s1<<"->55";
    // 
}