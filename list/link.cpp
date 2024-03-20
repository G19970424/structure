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
 * 时间复杂度：O(n)
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
 * 时间复杂度：O(n)
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
 * 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
 * 时间复杂度：O(n)
*/
Status ListDelete_L(LinkList L,int i,LinkElem e){
    //获取L指针
    LNode *p = L;
    //计数器 j
    int j = 0;
    //顺序向后遍历，获取第i个值
    while(p && j<i){
        p = p->next;
        j++;
    }
    //判断L中是否存在第i个元素
    if(!p || j<i)return ERROR;

    //从单链线性表中将第i个元素移除
    LNode *q = p->next;
    p->next = q->next;
    //通过e获取第i个元素
    e = q->date;
    //释放指针q
    free(q);
    return OK;
}

/**
 * 头插法创建单链线性表
 * 时间复杂度：O(b)
*/
Status CreatList_L(LinkList &L,int n){
    //逆位序输入n个元素的值，建立带表头结点的单链线性表L

    //初始化L表头空间
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    //循环创建结点
    for(int i=n;i>0;--i){
        //生成新结点
        LinkList p = (LinkList)malloc(sizeof(LNode));
        //输入元素值
        LinkElem s;
        int age;
        char name[12];
        printf("用户年龄为：");
        scanf("%d",&age);

        printf("用户名称为：");
        scanf("%11s",name);

        s.setAge(age);
        s.setName(name);

        //插入到表头
        p->date = s;
        p->next = L->next;
        L->next = p;
    }

    return OK;
} 

/**
 * 合并有序单链线性表La、Lb，将元素有序合并到Lc中
*/
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
    LNode *a = La->next,*b = Lb->next;
    LNode *c;
    Lc = c = La;
    while(a && b){
        if(a->date.getAge() <= b->date.getAge()){
            c->next = a;
            c = a;
            a = a->next;
        }else{
            c->next = b;
            c = b;
            b = b->next;
        }
    }
    c->next = a?a:b;
    free(Lb);
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
    // LinkList L;

    // CreatList_L(L,3);
    // print_L(L);
    // LinkElem e = LinkElem(15,"ge");
    // cout<<"=========="<<endl;
    // ListInsert_L(L,1,e);
    // print_L(L);
    // cout<<"=========="<<endl;
    // ListDelete_L(L,1,e);
    // print_L(L);


    LinkList La,Lb,Lc;
    CreatList_L(La,3);
    CreatList_L(Lb,3);
    MergeList_L(La,Lb,Lc);

    print_L(Lc);
    return OK;
}

