#include <stdio.h>
#include <stdlib.h>

typedef struct linkqueue{
    int data;
    struct linkqueue* next;
}queue;

queue *creatqueue1();                                   //创建一个节点
int creatqueue(queue*head,int num);                     //创建一个队列
int putintoqueue(queue*head,int ele);                   //入队
void freequeue(queue*head);                             //释放队列空间
void printqueue(queue*head);                            //输出队列内的元素
void putoutqueue(queue*head);                           //出队

int main(){
    queue* head = creatqueue1();                        //头节点
    int length;
    int status=0;
    printf("请设置队列长度：");
    scanf("%d",&length);
    creatqueue(head,length);                            //先创建一个队列
    printqueue(head);
    printf("请选择接下来的操作,1继续插入,2第一个出队,3删除队列\n");
    scanf("%d",&status);                                //通过输入的命令，来进行操作
    switch(status){
        case 1:creatqueue(head,1);printqueue(head);break;
        case 2:putoutqueue(head);break;
        case 3:break;
    }
    freequeue(head);                                    //清空队列，这里其实有改进空间
    free(head);                                         //可以把头节点连着一起清除掉的
    return 0;
}

queue *creatqueue1(){
    queue* p=(queue*)malloc(sizeof(queue));
    p->next=NULL;
    return p;
}

int creatqueue(queue*head,int num){
    int flag=0;                                         //这里设置flag的目的是，方便询问是否正常入队
    int ele=0;
    queue *op=head;
    for(int i=0;i<num;i++){
        scanf("%d",&ele);
        flag=putintoqueue(op,ele);                      //调用入队函数，进行入队操作
    }
    return flag;
}

int putintoqueue(queue*head,int ele){
    int flag=0;
    queue*op=head;
    queue*p=creatqueue1();                              //创建一个节点
    p->data=ele;
    if(op->next){
        while(op->next){                                //我是设置，第一个为队头，每次入队都到最后入队
            op=op->next;
        }
        op->next=p;
        flag=1;                                         //如果入队成功，flag赋值为1
    }else{
        op->next=p;
        flag=1;
    }
    return flag;
}

void freequeue(queue*head){
    queue*p=head->next;
    queue*temp;                                         //清理队列
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
        printf("%d ",p->next->data);                    //这里是选用头节点开始遍历，头节点没有存数据，所以要输出，下一个的数据
        p = p->next;
    }
    printf("\n");
}

void putoutqueue(queue*head){
    queue*temp;
    if(head->next){                                     //用temp进行出队
        temp = head;
        head = head->next;
        free(temp);
    }else{
        printf("队列为空！\n");
    }
}
