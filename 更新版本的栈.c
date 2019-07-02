#include <stdio.h>
#include <stdlib.h>

typedef struct nodestack{
    int data;
    struct nodestack* next;
}stack;

stack* creatstack();
stack* putinto(stack*head, int temp);
void putout(stack *head);
void freenode(stack *head);

int main(){
    int length=0;
    int temp=0;
    stack* head=creatstack();
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
    p->next = NULL;
    return p;
}

stack* putinto(stack*head, int temp){
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
        head->next = temp->next;
        freenode(temp);
    }
    printf("\n");
}

void freenode(stack *head){
    free(head);
}





