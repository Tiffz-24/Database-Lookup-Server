#include <stdio.h>
#include "mylist.h"
#include <stdlib.h>

struct Node *addFront(struct List *list, void *data){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); //create new node
        if(!newNode){
                return NULL;
        }

        newNode -> data = data; //set data of node to data pointer
        newNode -> next = list -> head; //make new node point to current list head as next node
        list -> head = newNode; //make new node new head of list
        return newNode;
}

void traverseList(struct List *list, void (*f)(void *)){
        struct Node *node = list -> head;
        while(node){
                f(node -> data);
                node = node -> next;
        }

}

struct Node *findNode(struct List *list, const void *dataSought,
        int (*compar)(const void *, const void *)){
        struct Node *node = list -> head;
        while(node){
                if(compar(dataSought, node -> data) == 0)
                        return node;
                node = node -> next;
        }
        return NULL;
}

void flipSignDouble(void *data){
        *(double*)data *= -1;
}

int compareDouble(const void *data1, const void *data2){
        if(*(double*)data1 == *(double*)data2){
                return 0;
        }
        else{
                return 1;
        }
}

void *popFront(struct List *list){
        if(isEmptyList(list)){
                return NULL;
        }
        struct Node* node = list -> head;//store first node in another variable
        list -> head = node -> next;//remove it from the list
        void* data = node -> data; //store data pointer in another variable

        free(node);
        return data;//return pointer

}

void removeAllNodes(struct List *list){
        while(!isEmptyList(list)){
                popFront(list); //pop front node until nodes are all gone
        }
}

struct Node *addAfter(struct List *list,
        struct Node *prevNode, void *data){
        if(!prevNode){
                return addFront(list, data);
        }

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode -> next = prevNode -> next; //set new node before the next
        prevNode -> next = newNode; //put the node after prevNode
        newNode -> data = data;
        return newNode;
}

void reverseList(struct List *list){
        struct Node *prv = NULL;
        struct Node *cur = list -> head;
        struct Node *nxt;

        while (cur){
                nxt = cur -> next; //store next node
                cur -> next = prv; //reverse pointer direction
                prv = cur; //make current node previous
                cur = nxt; //move to next pointer
        }
        list -> head = prv;

}

