#include "string.h"

void String::__init(const char*str){
    if(0==strlen(str)){
        data_=nullptr;
        size_=0;
    }
    else
    {
        size_=strlen(str);
        data_=new char [size_+1];
        strcpy(data_,str);
    }
}
void String::__clean(){
    if(data_==nullptr||size_==0)return;
    delete[] data_;
    size_=0;
}
void String::__swap(String&other){
    // std::swap(size_,other.size_);
    // std::swap(data_,other.data_);
    int temp_i=size_;
    size_=other.size_;other.size_=temp_i;
    char* temp_c=data_;
    data_=other.data_;
    other.data_=temp_c;
}
String::String():data_(nullptr),size_(0){
    std::cout<<"default"<<std::endl;
}
String::String(const char*str){
    __init(str);
}
String::String(const String&other){
    __init(other.data_);
}


std::ostream& operator<<(std::ostream&out,const String&other)
{
    
}