#include "contains.cpp"
#include "elem.cpp"
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMENT 10    //线性表存储空间的非配增量

typedef struct
{
    /* data */
    ArrayElemType *elem;      //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
}SqList;

/**
 * 线性表的顺序表示和实现，用一组连续的存储单元依次存储线性表的数据元素
*/
Status InitList_Sq(SqList &L){
    //构造一个空线性表
    cout<< "====== init start ======" << endl;
    L.elem = (ArrayElemType *)malloc(LIST_INIT_SIZE*sizeof(ArrayElemType));
    //存储分配失败
    if( !L.elem ) exit(OVERFLOW);  
    //空表长度为0
    L.length = 0;                  
    L.listsize = LIST_INIT_SIZE;
    cout<< "====== init end ======" << endl;
    return OK;
}

/**
 * ListInsert_Sq ：线性顺序表的第i个位置上插入元素e
 * 时间复杂度：O(n)
*/
Status ListInsert_Sq(SqList &L,int i ,ArrayElemType e){
    //在顺序线性表的第i个位置上插入元素e
    if(i<1 || i > L.length+1 ) return ERROR;
    if(L.length >= L.listsize){
        //当前长度大于等于最大容量，进行扩容
        ArrayElemType *newbase = (ArrayElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ArrayElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    // cout<<"姓名:" << e.getName() <<",年龄："<< e.getAge() << endl;
    ArrayElemType *q = &(L.elem[i-1]);
    for(ArrayElemType *p= &(L.elem[L.length-1]) ;p >= q; --p ) *(p+1) = *p;
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

/**
 * 在线性表中查询满足第一个与e满足compare()函数的元素位序
*/
int LocateElem_Sq(SqList L,ArrayElemType e,Status(*compare)(ArrayElemType,ArrayElemType)){
    //在线性表L中查找第一个与e满足compare()的元素位序
    int i = 1;
    ArrayElemType *p = L.elem;
    while(i<=L.length && !(compare(*p++,e))) ++i;
    if(i <=L.length) return i;
    else return 0;
}
/**
 * 定义compare函数
*/
Status compare(ArrayElemType e1,ArrayElemType e2){
    if(e1.getName() == e2.getName() ){
        return OK;
    }
    return False;
}
/**
 * ListDelete_Sq :在线性顺序表中删除第i个元素
 * 时间复杂度：O(n)
*/
Status ListDelete_Sq(SqList &L,int i ,ArrayElemType &e){
    //在线性表L中删除第i个元素，并用e返回其值

    //判断i值是否合法
    if(i<1 || i>L.length) return ERROR;
    //p为被删除元素位置
    ArrayElemType *p = &(L.elem[i-1]);
    //被删除元素赋值给e
    e = *p;
    //获取表尾元素位置
    ArrayElemType *q = L.elem + L.length -1; 
    //被删除元素后左移
    for(++p;p<=q;++p) *(p-1) = *p;
    --L.length;
    return OK;
}

/**
 * 将第i个元素赋值给e
*/
void List_GetElem(SqList L,int i, ArrayElemType &e){
    if(i<1 || i>L.length) return;

    e = L.elem[i-1];
}

int ListLength(SqList L){
    cout << L.length <<endl;
    return L.length;
}
/**
 * ListUnion_Sq:将顺序线性表Lb中不存在的元素 添加到La中
*/
void ListUnion_Sq(SqList &La,SqList Lb){
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);

    for(int i=1;i<=Lb.length;i++){
        ArrayElemType e;
        List_GetElem(Lb,i,e);
        if(!(LocateElem_Sq(La,e,compare))) ListInsert_Sq(La,++La_len,e);
    }
}

/**
 * MergeList：合并有序顺序象形表La、Lb到Lc中 并按从达到小排列
 * 时间复杂度：O(ListLength(La)+ListLength(Lb))
*/
void MergeList(SqList La,SqList Lb,SqList &Lc){
    InitList_Sq(Lc);
    int i=1,j=1,k=0;
    int La_len = ListLength(La),Lb_len = ListLength(Lb);

    ArrayElemType ai;
    ArrayElemType bi;

    while((i<=La_len) && (j<=Lb_len)){
        
        List_GetElem(La,i,ai);
        List_GetElem(Lb,j,bi);
        if(ai.getAge() <= bi.getAge() ){
            ListInsert_Sq(Lc,++k,ai);
            ++i;
        }else{
            ListInsert_Sq(Lc,++k,bi);
            ++j;
        }
    }

    while(i<=La_len){
        List_GetElem(La,i++,ai);
        ListInsert_Sq(Lc,++k,ai);
    }

    while(j<=Lb_len){
        List_GetElem(Lb,j++,bi);
        ListInsert_Sq(Lc,++k,bi);
    }
}

int main(){
    // SqList a;
    // InitList_Sq(a);
    // ArrayElemType e1 = ArrayElemType((char*)"dawda",14);
    // ListInsert_Sq(a,1,e1);
    // SqList_Print(a);
    // cout<< "顺序线性表初始化成功！"<<endl;
    // ListInsert_Sq(a,1,ArrayElemType());
    // ListInsert_Sq(a,1,ArrayElemType((char*)"gege",17));
    // ListInsert_Sq(a,1,ArrayElemType((char*)"11",14));
    // ListInsert_Sq(a,1,ArrayElemType((char*)"123",19));
    // ListInsert_Sq(a,1,ArrayElemType((char*)"412",63));
    // SqList_Print(a);
    // cout<< "顺序线性表插入成功" <<endl;
    // ArrayElemType e2 = ArrayElemType((char*)"dawd",14);
    // Status s = LocateElem_Sq(a,e2,compare);
    // cout<< "顺序线性表compare函数执行成功" << endl;
    
    // ArrayElemType re;
    // ListDelete_Sq(a,3,re);
    // re.print();
    // // 单顺序线性表示例结束
    // cout<< "=== 单顺序线性表示例结束 ===" <<endl;
    SqList La,Lb;
    InitList_Sq(La);
    InitList_Sq(Lb);
    ListInsert_Sq(La,1,ArrayElemType((char*)"2",11));
    ListInsert_Sq(La,2,ArrayElemType((char*)"3",12));
    ListInsert_Sq(La,3,ArrayElemType((char*)"5",31));
    ListInsert_Sq(La,4,ArrayElemType((char*)"7",33));
    SqList_Print(La);
    ListInsert_Sq(Lb,1,ArrayElemType((char*)"1",8));
    ListInsert_Sq(Lb,2,ArrayElemType((char*)"4",14));
    ListInsert_Sq(Lb,3,ArrayElemType((char*)"6",32));
    ListInsert_Sq(Lb,4,ArrayElemType((char*)"8",99));
    SqList_Print(Lb);
    // ListUnion_Sq(La,Lb);
    SqList Lc;
    MergeList(La,Lb,Lc);
    SqList_Print(Lc);
}