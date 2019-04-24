#include <stdio.h>

typedef struct node{                //创建整数型数组栈
    int arr[10];
    int top;
}stack;

void Destory(stack *s);             //销毁栈
int empty(stack *s);                //检查是否为空
int length(stack *s);               //返回栈的长度，也等于返回top
void push(stack *s,int ele);        //压栈操作
void pop(stack *s);                 //弹栈操作
void stacktraverse(stack *s);       //遍历输出栈中的元素

int main(){
    stack s;                        //创建栈
    s.top=-1;                       //由于是空栈，top先为-1
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
    s->top=-1;                      //直接等于-1，即变为可改写状态
}

int empty(stack *s){
    int falg=1;
    if(s->top==-1){                 //检查top是否为-1
        falg=0;
    }
    return falg;
}

int length(stack *s){
    int len;
    if(s->top!=-1){
        len = s->top+1;             //由于top相当于数组的下标，所以返回长度时加1
    }else{
        len = 0;
    }
    return len;
}

void push(stack *s,int ele){
    if(s->top<=9){
        s->top++;                   //先把游标移动，再进行赋值
        s->arr[s->top]=ele;
    }else{
        printf("已经满栈了\n");
    }
}

void pop(stack *s){
    if(s->top!=-1){                 //判断是否为空栈
        printf("删除的是:%d\n",s->arr[s->top]);
        s->top--;
    }else{
        printf("已经是空栈了\n");
    }
}

void stacktraverse(stack *s){
    if(s->top!=-1){
        for(int i=0;i<=s->top;i++){ //遍历数组中的有效数据
            printf("%d ",s->arr[i]);
        }
        printf("\n");
    }else{
        printf("为空栈无法遍历\n");
    }
}
