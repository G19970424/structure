#include "contains.cpp"
#include "linkElem.cpp"

typedef struct LNode
{
    /* data */
    LinkElem date;
    struct LNode *next;
}LNode ,*LinkList;

/**
 * 在单链线性表L中查询第i个元素并且赋值给e
*/
Status GetElem_L(LinkList L,int i,LinkElem &e){
    //L为带头节点的单链表头指针
    //当第i个元素存在时，其值赋值给e并返回OK，否则返回Error
    //初始化，令p指向第一个结点，j为计数器
    LNode *p = L->next;
    int j = 1;
    //顺着指针向后查找
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    e = p->date;
    return OK;
}

/**
 * 在单链线性表L中第i个位置前插入元素e
*/
Status ListInsert_L(LinkList &L,int i,LinkElem e){
    //在带头结点的单链线性表L中第i个位置之前插入元素e
    LNode *p = L->next;
    int j =0;
    //寻找第i-1结点
    while(p && j<i-1){
        p = p->next;
        j++;
    } 
    //i小于1或者大于表长+1
    if(!p || j>i-1)return ERROR;
    //创建新结点s
    LinkList s = (LinkList)malloc(sizeof(LNode));
    //将结点插入L中
    s->date = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * 
*/
Status ListDelete_L(LinkList L,int i,LinkElem e){
    LNode *p = L->next;
    int j = 0;
    while(p && j<i){
        p = p->next;
        j++;
    }

    if(!p || j<i)return ERROR;

    LNode *q = p->next;
    p->next = q->next;
    e = q->date;
    free(q);
    return OK;
}

/**
 * 
*/
Status CreatList_L(LinkList &L,int n){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    for(int i=n;i>0;--i){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        LinkElem s;
        int age;
        char *name;
        printf("用户年龄为：");
        scanf("%d",&age);

        printf("用户名称为：");
        scanf("%11s",name);

        s.setAge(age);
        s.setName(name);

        p->date = s;
        p->next = L->next;
        L->next = p;
    }

    return OK;
}

void print_L(LinkList &L){
    LinkList q = L;
    
    if(!q){
        printf("对象不存在");
    }

    LNode *p = L->next;
    LinkElem e;
    while(p){
        e = p->date;
        printf("用户年龄为：%d,姓名：%s \n",e.getAge(),e.getName());
        p = p->next;
    }
}
int main(){
    LinkList L;

    CreatList_L(L,2);

    print_L(L);
    return OK;
}

