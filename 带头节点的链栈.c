#include <stdio.h>
#include <stdlib.h>

typedef struct nodestack{
    int data;
    struct nodestack* next;
}stack;

stack *creatstack(stack*head);
void printfstack(stack *head);
void freestack(stack *head);

int main(){
    stack *head=(stack*)malloc(sizeof(stack));
    head->next = NULL;
    int count;
    
    printf("弹匣的大小:");
    scanf("%d",&count);
    printf("请输入子弹的编号：");
    for(int i=0;i<count;i++){
        head = creatstack(head);
    }
    printf("开始射击！嗒 嗒 嗒 哒\n");
    printfstack(head);
    freestack(head);
    return 0;
}

stack *creatstack(stack*head){
    stack *p = (stack*)malloc(sizeof(stack));
    stack *last = head;
    int index;
    scanf("%d",&index);
    
    p->data=index;
    p->next=NULL;
    if(last->next){
        p->next=last->next;
        last->next=p;
    }else{
        head->next=p;
    }
    return head;
}

void printfstack(stack *head){
    stack *p=head->next;
    if(p){
        for(;p;p=p->next){
            printf("%d ",p->data);
        }
        printf("\n");
    }else{
        printf("没有存进\n");
    }
}

void freestack(stack *head){
    stack *p=head->next;
    while(head){
        p=head;
        head=head->next;
        free(p);
    }
    printf("射完了\n");
}




