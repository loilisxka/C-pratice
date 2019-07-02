#include <stdio.h>
#include <stdlib.h>

typedef struct nodestack{
    int data;
    struct nodestack* next;
}stack;

stack* creatstack();                                    //这里将创建节点的功能单独独立出来
stack* putinto(stack*head, int temp);                   //对元素进行压栈操作
void putout(stack *head);                               //这里直接全部弹栈，还有可以改进的空间，还是太简单了
void freenode(stack *head);                             //释放空间

int main(){
    int length=0;
    int temp=0;
    stack* head=creatstack();                           //由于这里使用了头节点，所以每次对栈进行操作，不必再那头节点赋值
    printf("需要压入栈的元素个数:");
    scanf("%d",&length);
    printf("正在准备压栈...\n");
    for(int i=0;i<length;i++){
        scanf("%d",&temp);
        putinto(head,temp);
    }
    printf("正在弹栈...\n");
    putout(head);
    freenode(head);
    return 0;
}

stack *creatstack(){
    stack*p = (stack*)malloc(sizeof(stack));
    p->next = NULL;                                     //直接将指针置为NULL
    return p;
}

stack* putinto(stack*head, int temp){                   //链表常规操作
    stack* p = creatstack();
    stack* zanshi = head;
    p->data = temp;
    if(zanshi->next){
        p->next = zanshi->next;
        zanshi->next = p;
    }else{
        zanshi->next = p;
    }
    
    return head;
}

void putout(stack *head){
    stack *temp;
    while(head->next){
        temp = head->next;
        printf("%d ",temp->data);
        head->next = temp->next;                        //修改头节点的指针指向
        freenode(temp);
    }
    printf("\n");
}

void freenode(stack *head){
    free(head);
}





