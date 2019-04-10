#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}linknode;                                  //创建链表结构

linknode *crealink(linknode*head,int num);  //创建函数
void triplink(linknode *head);              //输出链表中的数
void freelink(linknode *head);              //重置链表所占内存空间
linknode *deletlink(linknode *head,int num,int loop);//删除指定位置的数
linknode *findlink(linknode *head,int num,int loop);//寻找对应位置的链表
linknode *addtolink(linknode *head,int num,int pos,int loop);//在制定位置插入指定的数

int main(){
    linknode *head = NULL;                  //先创建一个指向链表的指针
    int loop,num,count;
    
    printf("请问你要存入几个数：\n");
    scanf("%d",&loop);
    count = loop;//保证loop不被消耗
    printf("请输入：\n");
    while(count>0){
        scanf("%d",&num);                   //每读入一个数，就创建一个链表
        head=crealink(head,num);
        count--;
    }
    printf("您存入的数是：\n");
    triplink(head);
    printf("想删除第几个数？\n");
    scanf("%d",&num);
    head=deletlink(head,num,loop);
    triplink(head);
    printf("请输入要插入的数(从最末端插入)：\n");
    scanf("%d",&num);
    head = crealink(head,num);
    triplink(head);
    printf("请输入要插入的数，以及插入的位置：\n");
    int pos;
    scanf("%d%d",&num,&pos);
    head=addtolink(head,num,pos,loop);
    triplink(head);
    freelink(head);
    return 0;
}

linknode *crealink(linknode*head,int num){
    linknode *p;                            //创建指针
    linknode *last=head;                    //创建指向最后一项的指针
    p=(linknode*)malloc(sizeof(linknode));  //创建一个链表，并把链表地址赋给p
    
    p -> value = num;                       //进行赋值
    p -> next = NULL;                       //把指向下一节点的指针赋值为零
    
    if(last){                               //若head指针不为空
        while(last->next){                  //当last指针指向下一个节点的指针不为空
            last=last->next;
        }
        last->next=p;                       //把p变为最后一个节点
    }else{
        head=p;                             //如果head为空，那么p为第一个节点
    }
    return head;                            //返回head
}

void triplink(linknode *head){
    linknode *begin=head;                   //为了不改变head值，把head赋值给begin
    if(begin){
        for(;begin;begin=begin->next){      //遍历节点
            printf("%d ",begin->value);     //输出值
        }
        printf("\n");
    }else{
        printf("好像并没有存进\n");          //报错
    }
}

linknode *deletlink(linknode *head,int num,int loop){
    linknode *go,*before,*temp;
    switch(num){
        case 1:                             //如果要删第一个节点
        temp = head;
        head = head->next;
        free(temp);break;
        default:
        go = findlink(head,num,loop);       //找到要删除的节点位置
        before = findlink(head,num-1,loop); //找到要删除节点前的一个节点
        if(go){                             //防止要删除的位置不存在
            before->next = go->next;        //前一节点指针指向下一节点指针所指节点
            free(go);
        }else{
            printf("越界警告\n");
        }
    }
    return head;
}

linknode *findlink(linknode *head,int num,int loop){
    linknode *find=head;
    if(num<=loop){                          //防止越界
        while(find&&num>1){                 //防止链表为空
            find = find->next;
            num--;
        }
    }else{                                  //为防越界返回空指针
        find = NULL;
    }
    return find;
}

linknode *addtolink(linknode *head,int num,int pos,int loop){
    linknode *go,*after,*before;
    go = (linknode*)malloc(sizeof(linknode));
    go->value=num;
    go->next=head;                          //先把创建的链表指针指向head
    if(pos==1){
        head=go;
    }else if(pos>1&&pos<=loop){
        after=findlink(head,pos,loop);      //找到插入的节点
        before=findlink(head,pos-1,loop);   //找到插入的前一节点
        go->next=after;                     //把插入的链表的指针指向插入位置的指针，使之变成下一个
        before->next=go;                    //把前一节点的指针，指向插入的链表
    }
    return head;
}

void freelink(linknode *head){
    linknode *temp;
    while(head){                            //遍历链表
        temp = head;                        //暂存head所指区域
        head = head->next;
        free(temp);                         //释放temp所占内存空间
    }
    printf("清理完毕\n");
}
