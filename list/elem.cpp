#include<iostream>
using namespace std;

class ArrayElemType {
    private:
        char *mName;
        int mAge;
    public:
        ArrayElemType();
        ArrayElemType(int age);
        ArrayElemType(char *name,int age);
        void setName(char *name);
        void setAge(int age);
        char *getName();
        int getAge();
        void print();
};

ArrayElemType::ArrayElemType(){
    
}

ArrayElemType::ArrayElemType(char *name,int age){
    mName = name;
    mAge = age;
}

void ArrayElemType::setName(char *name){
    mName = name;
}

void ArrayElemType::setAge(int age){
    mAge = age;
}

char *ArrayElemType::getName(){
    return mName;
}

int ArrayElemType::getAge(){
    return mAge;
}

void ArrayElemType::print(){
    cout<< "姓名:" << mName <<",年龄："<< mAge <<endl;
}

