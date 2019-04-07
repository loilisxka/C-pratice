#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct link {
    int prime;
    struct link *next;
}cprime;

cprime *crealinkl(cprime *head,int x);
void printflink(cprime *head);
void freelink(cprime *head);

int main() {
    int x, y, count1 = 0;
    scanf("%d%d", &x, &y);
    cprime *head = NULL;

    for(; x <= y; x++) {
            int flag = 1;
        if(x != 2 && x != 1) {
            for(int i = 2; i < sqrt(x)+1; i++) {
                if(x%i == 0) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                head = crealinkl(head,x);
                count1 += 1;
            }
        }else if(x == 2) {
            head = crealinkl(head,x);
            count1 += 1;
        }
    }
    printf("%d\n", count1);
    printflink(head);
    freelink(head);
    return 0;
}

cprime *crealinkl(cprime *head,int x){
    cprime *p = (cprime*)malloc(sizeof(cprime));
    p -> prime = x;
    p -> next = NULL;
    cprime *last = head;
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next = p;
    }else{
        head = p;
    }
    return head;
}

void printflink(cprime *head){
    for(;head;head = head -> next){
        printf("%d",head -> prime);
        if(head -> next){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

void freelink(cprime *head){
    cprime *vice;
    while(head){
        vice = head;
        head = head->next;
        free(vice);
    }
}
