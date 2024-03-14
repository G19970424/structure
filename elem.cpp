#include<iostream>
using namespace std;

class ElemType {
    private:
        char *mName;
        int mAge;
    public:
        ElemType();
        ElemType(int age);
        ElemType(char *name,int age);
        void setName(char *name);
        void setAge(int age);
        char *getName();
        int getAge();
        void print();
};

ElemType::ElemType(){
    mName = (char*)"null";
    mAge = -1;
}

ElemType::ElemType(char *name,int age){
    mName = name;
    mAge = age;
}

void ElemType::setName(char *name){
    mName = name;
}

void ElemType::setAge(int age){
    mAge = age;
}

char *ElemType::getName(){
    return mName;
}

int ElemType::getAge(){
    return mAge;
}

void ElemType::print(){
    cout<< "姓名:" << mName <<",年龄："<< mAge <<endl;
}

