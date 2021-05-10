/*
 * @Author: 光城
 * @Date: 2021-05-08 11:25:52
 * @LastEditors: 光城
 * @LastEditTime: 2021-05-08 11:26:17
 * @Description:
 * @FilePath: \code\kg\string\string.cpp
 */

// 动态分配的空间也可下标寻址？

#include "string.h"
void String::__init(const char*str)
{
    // 预先分配还是？
    // for(size_=0;*(str+size_)!='\0';++size_);
    data_=new char[size_+1];
    for(int i=0;i<=size_;i++){
        *(data_+i)=*(str+i);
    }
}
void String::__clean(){
    size_=0;
    delete[]data_;
}

// 交换？用于移动构造？
void String::__swap(String& other){
    std::swap(data_,other.data_);
    std::swap(size_,other.size_);
}

String::String():data_(nullptr),size_(0){}
String::String(const char* str){
    for(size_=0;*(str+size_)!='\0';++size_);
    __init(str);
}
String::String(const String&other){
    size_=other.size_;
    __init(other.data_);
}
String& String::operator=(const String&other){
    // 看完这一章在修改
    if(this!=&other){
        char* temp=data_;
        data_=new char[other.size_+1];
        for(int i=0;i<=other.size_;++i){
            *(data_+i)=*(other.data_+i);
        }
        delete[]temp;
        size_=other.size_;
        return *this;
    }
    return *this;
}
String::~String(){
    __clean();
}
bool String::operator==(const String& other){
    if(this==&other)return true;
    if(size_==other.size_){
        int i=0;
        while (*(data_+i)==*(other.data_+i))
        {
           ++i;
        }
        if(i==size_)return true;        
    }
    return false;
}
char& String::operator[](size_t index){
    // check()
    return *(data_+index-1);
}
const char* String::c_str()const{
    return data_;
}
size_t String::length()
{
    return size_;
}
String String::operator+(const String& other){
    String temp;
    temp.size_=size_+other.size_;
    temp.data_=new char[temp.size_+1];
    strcpy(temp.data_,data_);
    strcat(temp.data_,other.data_);
    return temp;
}
// 移动构造？忘辽...
String::String(String&& other)noexcept
{
    data_=other.data_;
    size_=other.size_;
    other.data_=nullptr;
    other.size_=0;
}
// 移动赋值
String& String::operator=(String&& other)noexcept{
    if(this!=&other){
        __clean();//释放资源
        data_=other.data_;//接管资源
        size_=other.size_;
        other.data_=nullptr;
        other.size_=0;
        return *this;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
    out<<str.size_;
    out<<"->";
    if(str.data_!=nullptr)
        out<<str.data_;
    return out;
}
std::istream& operator>>(std::istream& in, String& str){
    in>>str.size_;
    str.data_=new char[str.size_];
    in>>str.data_;
    return in;
}