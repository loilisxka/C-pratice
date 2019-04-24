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
    printf("��ջֻ�ܴ�10����\n");
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
        printf("�Ѿ���ջ��\n");
    }
}

void pop(stack *s){
    if(s->top!=-1){
        printf("ɾ������:%d\n",s->arr[s->top]);
        s->top--;
    }else{
        printf("�Ѿ��ǿ�ջ��\n");
    }
}

void stacktraverse(stack *s){
    if(s->top!=-1){
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->arr[i]);
        }
        printf("\n");
    }else{
        printf("Ϊ��ջ�޷�����\n");
    }
}
