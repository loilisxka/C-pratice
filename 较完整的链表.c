#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}linknode;

linknode *crealink(linknode*head,int num);
void triplink(linknode *head);
void freelink(linknode *head);
linknode *deletlink(linknode *head,int num,int loop);
linknode *findlink(linknode *head,int num,int loop);
linknode *addtolink(linknode *head,int num,int pos,int loop);

int main(){
    linknode *head = NULL;
    int loop,num,count;
    
    printf("请问你要存入几个数：\n");
    scanf("%d",&loop);
    count = loop;
    printf("请输入：\n");
    while(count>0){
        scanf("%d",&num);
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
    linknode *p;
    linknode *last=head;
    p=(linknode*)malloc(sizeof(linknode));
    
    p -> value = num;
    p -> next = NULL;
    
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next=p;
    }else{
        head=p;
    }
    return head;
}

void triplink(linknode *head){
    linknode *begin=head;
    if(begin){
        for(;begin;begin=begin->next){
            printf("%d ",begin->value);
        }
        printf("\n");
    }else{
        printf("好像并没有存进\n");
    }
}

linknode *deletlink(linknode *head,int num,int loop){
    linknode *go,*before,*temp;
    switch(num){
        case 1:
        temp = head;
        head = head->next;
        free(temp);break;
        default:
        go = findlink(head,num,loop);
        before = findlink(head,num-1,loop);
        if(go){
            before->next = go->next;
            free(go);
        }
    }
    return head;
}

linknode *findlink(linknode *head,int num,int loop){
    linknode *find=head;
    if(num<=loop){
        while(find&&num>1){
            find = find->next;
            num--;
        }
    }else{
        find = NULL;
    }
    return find;
}

linknode *addtolink(linknode *head,int num,int pos,int loop){
    linknode *go,*after,*before;
    go = (linknode*)malloc(sizeof(linknode));
    go->value=num;
    go->next=head;
    if(pos==1){
        head=go;
    }else if(pos>1&&pos<=loop){
        after=findlink(head,pos,loop);
        before=findlink(head,pos-1,loop);
        go->next=after;
        before->next=go;
    }
    return head;
}

void freelink(linknode *head){
    linknode *temp;
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("清理完毕\n");
}
