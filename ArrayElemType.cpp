#include<iostream>
using namespace std;

class LinkElemType{
    private:
        int mAge;
        char *mName;
    public:
        LinkElemType();
        LinkElemType(int age,char *name);
        void setAge(int age);
        void setName(char *name);
        int getAge();
        char *getName();
};

LinkElemType::LinkElemType(){

}

LinkElemType::LinkElemType(int age,char *name){
    mAge = age;
    mName = name;
}

void LinkElemType::setAge(int age){
    mAge = age;
}
void LinkElemType::setName(char *name){
    mName = name; 
}
int LinkElemType::getAge(){
    return mAge;
}
char *LinkElemType::getName(){
    return mName;
}