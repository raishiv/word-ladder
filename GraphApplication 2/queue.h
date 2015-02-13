//
//  queue.h
//  GraphApplication
//
//  Created by Shiv chandra Kumar on 11/30/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#ifndef __GraphApplication__queue__
#define __GraphApplication__queue__

#include <stdio.h>



#include <stddef.h>
//define a struct for taking values of index as coordinates of 2D array
struct coordinates{
    int Xval ;
    int Yval ;
};

/*define a struct for node generation
 whenever a new input is pushed to the queue*/
struct node{
    node() : ptr(0) {}
    coordinates value;
    node *ptr;
};
//define the class
class Queue{
public:
    node *head;
    node *tail;
    void enqueue(int , int);
    void print();
    coordinates dequeue();
    bool isEmpty() const;
    Queue();
};

#endif /* defined(__GraphApplication__queue__) */
