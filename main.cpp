//
//  main.cpp
//  reverseLL
//
//  Created by hambarkh on 29/03/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#include <iostream>

#define N 10
using namespace std;

typedef struct node{
    int val;
    struct node *next;
}Node;

void createLL(Node &aInNode);
void printLL(Node lNode);
Node *reverseLL(Node &head);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Node head;
    //create LL
    createLL(head);
    printf("Printing LL\n");
    printLL(head);
    Node *RevHead = reverseLL(head);
    printf("Printing Reversed LL\n");
    printLL(*RevHead);
    return 0;
}

Node *reverseLL(Node &aInHead)
{
    Node *l,*r,*i;
    i = &aInHead;
    l = NULL;
    r = aInHead.next;
    while (r != NULL) {
        //cout << "i val = " << i->val << endl;
        i->next = l;
        l = i;
        i = r;
        r = r->next;
    }
    i->next = l;
    return i;
    
}


void createLL(Node &aInNode)
{
    int i;
    //aInNode = *(Node*)malloc(sizeof(Node));
    aInNode.val = 10;
    Node *lNode;
    lNode = &aInNode;
    for (i=1; i<N; i++) {
        lNode->next = (Node *)malloc(sizeof(Node));
        lNode = lNode->next;
        //lNode is now new Node
        lNode->val = 3*i;
   //     cout << "i = " << i << endl;
        lNode->next = NULL;
    }
    std::cout << "In createLL\n";
}

void printLL(Node aInNode)
{
    //int i=0;
    Node *lNode = &aInNode;
    while(lNode != NULL){
        std::cout /*<< "i = " <<i << "Node Val= "*/<< lNode->val << "\t";
        //i++;
        lNode = lNode->next;
    }
    std::cout << std::endl;
}
