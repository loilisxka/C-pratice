#include <stdio.h>
#include <stdlib.h>

typedef struct linkqueue{
    int data;
    struct linkqueue* next;
}queue;

queue *creatqueue1();
int creatqueue(queue*head,int num);
int putintoqueue(queue*head,int ele);
void freequeue(queue*head);
void printqueue(queue*head);
void putoutqueue(queue*head);

int main(){
    queue* head = creatqueue1();
    int length;
    int status=0;
    printf("请设置队列长度：");
    scanf("%d",&length);
    creatqueue(head,length);
    printqueue(head);
    printf("请选择接下来的操作,1继续插入,2第一个出队,3删除队列\n");
    scanf("%d",&status);
    switch(status){
        case 1:creatqueue(head,1);printqueue(head);break;
        case 2:putoutqueue(head);break;
        case 3:break;
    }
    freequeue(head);
    free(head);
    return 0;
}

queue *creatqueue1(){
    queue* p=(queue*)malloc(sizeof(queue));
    p->next=NULL;
    return p;
}

int creatqueue(queue*head,int num){
    int flag=0;
    int ele=0;
    queue *op=head;
    for(int i=0;i<num;i++){
        scanf("%d",&ele);
        flag=putintoqueue(op,ele);
    }
    return flag;
}

int putintoqueue(queue*head,int ele){
    int flag=0;
    queue*op=head;
    queue*p=creatqueue1();
    p->data=ele;
    if(op->next){
        while(op->next){
            op=op->next;
        }
        op->next=p;
        flag=1;
    }else{
        op->next=p;
        flag=1;
    }
    return flag;
}

void freequeue(queue*head){
    queue*p=head->next;
    queue*temp;
    while(p){
        temp = p;
        p = p->next;
        free(temp);
    }
    printf("清理完毕\n");
}

void printqueue(queue*head){
    queue*p=head;
    while(p->next){
        printf("%d ",p->next->data);
        p = p->next;
    }
    printf("\n");
}

void putoutqueue(queue*head){
    queue*temp;
    if(head->next){
        temp = head;
        head = head->next;
        free(temp);
    }else{
        printf("队列为空！\n");
    }
}
