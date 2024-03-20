#include "linkElem.cpp"

#define MAXSIZE 1000
typedef struct{
    int data;
    int cur;
}component,SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList s,int e){
    int i = s[0].cur;
    while (i && s[i].data != e){
        i = s[i].cur;
    }

    return i;
}

void InitSpace_SL(SLinkList &space){
    for(int i=0;i<MAXSIZE-1;i++) space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;
}

int Malloc_SL(SLinkList &space){
    int i = space[0].cur;
    if(space[0].cur){
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free_SL(SLinkList &space,int k){
    space[k].cur = space[0].cur;
    space[0].cur = k;
}


void Difference(SLinkList &space,int &s){
    InitSpace_SL(space);
    s = Malloc_SL(space);

    int r = s;
    int m,n;
    scanf("%d",m);
    scanf("%d",n);
    for(int j=1;j<=m;++j){
        int i = Malloc_SL(space);
        scanf("%d",space[i].data);
        space[r].cur = i;
        r = i;
    }
    space[r].cur = 0;

    for(int j=1;j<=n;++j){
        int b;
        scanf("%d",b);
        int p = s;
        int k = space[s].cur;
        while(k != space[r].cur && space[k].data != b){
            p = k;
            k = space[k].cur;
        }

        if(k== space[r].cur){
            int i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[i].cur = i;
        }else{
            space[p].cur = space[k].cur;
            Free_SL(space,k);
            if(r == k ) r = p;
        }
    }

}