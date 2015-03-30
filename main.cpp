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

/*typedef struct node{
    int val;
    struct node *next;
}Node;*/

class Node{
    int val;
    Node *next;
    
public:
    int getVal(){
        return val;
    }
    Node *getNext(){
        return next;
    }
    void setVal(int aInVal){
        val = aInVal;
    }
    void setNext(Node *aInNext){
        next = aInNext;
    }
};

void createLL(Node *aInNode);
void printLL(Node *aInNode);
Node *reverseLL(Node *head);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Node *head = new Node;
    //create LL
    createLL(head);
    printf("Printing LL\n");
    printLL(head);
    Node *RevHead = reverseLL(head);
    printf("Printing Reversed LL\n");
    printLL(RevHead);
    return 0;
}

Node *reverseLL(Node *aInHead)
{
    Node *l,*r,*i;
    i = aInHead;
    l = NULL;
    r = aInHead->getNext();
    while (r != NULL) {
        //cout << "i val = " << i->val << endl;
        i->setNext(l);
        l = i;
        i = r;
        r = r->getNext();
    }
    i->setNext(l);
    return i;
    
}


void createLL(Node *aInNode)
{
    int i;
    //aInNode = *(Node*)malloc(sizeof(Node));
    aInNode->setVal(10);
    Node *lNode = aInNode;
    //lNode = &aInNode;
    for (i=1; i<N; i++) {
        lNode->setNext(new Node);
        lNode = lNode->getNext();
        //lNode is now new Node
        lNode->setVal(3*i);
   //     cout << "i = " << i << endl;
        lNode->setNext(NULL);
    }
    std::cout << "In createLL\n";
}

void printLL(Node *aInNode)
{
    //int i=0;
    Node *lNode = aInNode;
    while(lNode != NULL){
        std::cout /*<< "i = " <<i << "Node Val= "*/<< lNode->getVal() << "\t";
        //i++;
        lNode = lNode->getNext();
    }
    std::cout << std::endl;
}
