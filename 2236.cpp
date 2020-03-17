#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node, * LinkList;
//type: Node
//memory address(pointer): LinkList

void init_list(LinkList &L, int n);
void josephus(int n, int m);

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    //input n, m
    josephus(n, m);
}

void init_list(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(Node));
    L -> data = 1;
    L -> next = NULL;
    //init head node L with value of 1

    LinkList cll = L;
    for(int i = 2; i <= n; i++){
        LinkList p = (LinkList)malloc(sizeof(Node));
        p -> data = i;
        p -> next = NULL;
        //init p with value of i(start from 2 to n)
        cll -> next = p;
        cll = cll -> next;
        //insert p
    }
    cll -> next = L;
    //form a circle
}

void josephus(int n, int m){
    LinkList L;
    init_list(L, n);
    //init circular-linked-list L

    LinkList pre;
    //the previous node for delete operation

    while(L->next != L){
        for(int i = 1; i < m; i++){
            //count from 1 to m
            pre = L;
            L = L -> next;
        }
        pre -> next = L -> next;
        //current node is out of L

        printf("%d ", L -> data);
        //output the value of current node

        free(L);
        L = pre -> next;
        //let L point to the next position as its index use
    }

    printf("%d ", L -> data);
    //output the last one
    free(L);
}