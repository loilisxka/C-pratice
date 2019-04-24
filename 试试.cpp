#include <stdio.h>

typedef struct node{
    int arr[10];
    int top;
}stack;

void Destory(stack *s);
int empty(stack *s);
int length(stack *s);
void push(stack *s,int ele);
void pop(stack *s);
void stacktraverse(stack *s);

int main(){
    stack s;
    s.top=-1;
    int count=0,ele;
    printf("该栈只能存10个数\n");
    while(count<10){
        scanf("%d",&ele);
        push(&s,ele);
        count++;
    }
    stacktraverse(&s);
    return 0;
}

void Destory(stack *s){
    s->top=-1;
}

int empty(stack *s){
    int falg=1;
    if(s->top==-1){
        falg=0;
    }
    return falg;
}

int length(stack *s){
    int len;
    if(s->top!=-1){
        len = s->top+1;
    }else{
        len = 0;
    }
    return len;
}

void push(stack *s,int ele){
    if(s->top<=9){
        s->top++;
        s->arr[s->top]=ele;
    }else{
        printf("已经满栈了\n");
    }
}

void pop(stack *s){
    if(s->top!=-1){
        printf("删除的是:%d\n",s->arr[s->top]);
        s->top--;
    }else{
        printf("已经是空栈了\n");
    }
}

void stacktraverse(stack *s){
    if(s->top!=-1){
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->arr[i]);
        }
        printf("\n");
    }else{
        printf("为空栈无法遍历\n");
    }
}
