#include<iostream>
using namespace std;

class LinkElem{
    private:
        int mAge;
        char *mName;
    public:
        LinkElem();
        LinkElem(int age,char *name);
        void setAge(int age);
        void setName(char *name);
        int getAge();
        char *getName();
};

LinkElem::LinkElem(){

}

LinkElem::LinkElem(int age,char *name){
    mAge = age;
    mName = name;
}

void LinkElem::setAge(int age){
    mAge = age;
}
void LinkElem::setName(char *name){
    mName = name; 
}
int LinkElem::getAge(){
    return mAge;
}
char *LinkElem::getName(){
    return mName;
}