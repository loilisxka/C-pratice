#include <stdio.h>
#include <stdlib.h>

typedef struct nodestack{
    int data;
    struct nodestack* next;
}stack;                                             //创建结构

stack *creatstack(stack*head);                      //创建栈结构，进行压栈
void printfstack(stack *head);                      //输出栈中的数字，按照出栈顺序来输出
void freestack(stack *head);                        //清空栈

int main(){
    stack *head=(stack*)malloc(sizeof(stack));      //创建头节点，方便输出节点
    head->next = NULL;                              //将头节点的下个节点置为空
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
    stack *p = (stack*)malloc(sizeof(stack));       //创建要压栈操作的节点
    stack *last = head;
    int index;
    scanf("%d",&index);                             //输出数据
    
    p->data=index;
    p->next=NULL;
    if(last->next){                                 //条件为若头节点的指针不为空
        p->next=last->next;
        last->next=p;
    }else{
        head->next=p;                               //若头节点的指针为空，则使指针指向创建的节点
    }
    return head;
}

void printfstack(stack *head){
    stack *p=head->next;                            //由于头节点不存数据，所以直接抓取数据
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
    stack *p=head->next;                            //这里的p指针相当于，交换两数据时的temp变量，用来临时储存的
    while(head){
        p=head;
        head=head->next;
        free(p);
    }
    printf("射完了\n");
}




