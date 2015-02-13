//
//  queue.cpp
//  GraphApplication
//
//  Created by Shiv chandra Kumar on 11/30/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#include "queue.h"
#include <stddef.h>
#include <iostream>
using namespace std;

Queue::Queue(void){
    head = 0;
    tail = 0;
}

//code for dequeue from the queue
coordinates Queue::dequeue(){
    coordinates c;
    if(this->isEmpty()){
        cout<<"QUEUE IS EMPTY!! CANNOT POP"<<endl;
        return c;
    }
    node n = *head;
    c = n.value;
    if(n.ptr == 0){
        head = 0;
        tail = 0;
    } else{
        head = n.ptr;
    }
    return c;
}

//code for enqueue in the queue
void Queue::enqueue(int x, int y){
    coordinates c;
    c.Xval = x;
    c.Yval = y;
    node* n = new node;
    n->value = c;
    if(tail != 0){
        tail->ptr = n;
    }
    tail = n;
    if(head == 0){
        head = n;
    }
}

void Queue::print(){
    node *a = head;
    while(a != 0){
        cout<<a->value.Xval<<"|"<<a->value.Yval<<endl;
        a = a->ptr;
    }
}

bool Queue::isEmpty() const{
    return (head == 0);
}

