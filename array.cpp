#include "contains.cpp"
#include "elem.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMENT 10    //线性表存储空间的非配增量

typedef struct
{
    /* data */
    ElemType *elem;      //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
}SqList;

/**
 * 线性表的顺序表示和实现，用一组连续的存储单元依次存储线性表的数据元素
*/
Status InitList_Sq(SqList &L){
    //构造一个空线性表
    cout<< "====== init start ======" << endl;
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    //存储分配失败
    if( !L.elem ) exit(OVERFLOW);  
    //空表长度为0
    L.length = 0;                  
    L.listsize = LIST_INIT_SIZE;
    cout<< "====== init end ======" << endl;
    return OK;
}

Status ListInsert_Sq(SqList &L,int i ,ElemType e){
    //在顺序线性表的第i个位置上插入元素e
    if(i<1 || i > L.length+1 ) return ERROR;
    if(L.length >= L.listsize){
        //当前长度大于等于最大容量，进行扩容
        ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    // cout<<"姓名:" << e.getName() <<",年龄："<< e.getAge() << endl;
    ElemType *q = &(L.elem[i-1]);
    for(ElemType *p= &(L.elem[L.length-1]) ;p >= q; --p ) *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
}

/**
 * 打印顺序线性表
*/
void SqList_Print(SqList &L){
    if(L.length == 0){
        cout<< "线性表为空"<<endl;
    }

    for(int i=0;i<L.length;i++){
        cout <<"第"<< i <<"个元素为：姓名：" << L.elem[i].getName() <<"，年龄："<< L.elem[i].getAge() << endl;
    }
}

int LocateElem_Sq(SqList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    //在线性表L中查找第一个与e满足compare()的元素位序
    int i = 1;
    ElemType *p = L.elem;
    while(i<=L.length && !(compare(*p++,e))) ++i;
    if(i <=L.length) return i;
    else return 0;
}
/**
 * 定义compare函数
*/
Status compare(ElemType e1,ElemType e2){
    if(e1.getName() == e2.getName() ){
        return OK;
    }
    return False;
}

Status ListDelete_Sq(SqList &L,int i ,ElemType &e){
    //在线性表L中删除第i个元素，并用e返回其值

    //判断i值是否合法
    if(i<1 || i>L.length+1) return ERROR;
    //p为被删除元素位置
    ElemType *p = &(L.elem[i-1]);
    //被删除元素赋值给e
    e = *p;
    //获取表尾元素位置
    ElemType *q = L.elem + L.length -1; 
    //被删除元素后左移
    for(++p;p<=q;++q) *(p-1) = *p;
    --L.length;
    return OK;
}

int main(){
    SqList a;
    InitList_Sq(a);
    ElemType e1 = ElemType((char*)"dawda",14);
    ListInsert_Sq(a,1,e1);
    SqList_Print(a);
    cout<< "顺序线性表初始化成功！"<<endl;
    ListInsert_Sq(a,1,ElemType());
    ListInsert_Sq(a,1,ElemType((char*)"gege",17));
    ListInsert_Sq(a,1,ElemType((char*)"11",14));
    ListInsert_Sq(a,1,ElemType((char*)"123",19));
    ListInsert_Sq(a,1,ElemType((char*)"412",63));
    SqList_Print(a);
    cout<< "顺序线性表插入成功" <<endl;
    ElemType e2 = ElemType((char*)"dawd",14);
    Status s = LocateElem_Sq(a,e2,compare);
    cout<< "顺序线性表compare函数执行成功" << endl;
    
    ElemType re;
    ListDelete_Sq(a,3,re);
    re.print();
}