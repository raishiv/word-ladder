//
//  Graphs.h
//  GraphApplication
//
//  Created by Shiv chandra Kumar on 11/30/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#ifndef __GraphApplication__Graphs__
#define __GraphApplication__Graphs__

#include <stdio.h>
#include<vector>
#include<string>
#include <queue>
using namespace std;

class Graphs{
public:
    struct graph_node{
        string data;
        vector<graph_node*> next;
        graph_node* pred;
        int number_of_vertices;
        bool visited;
    };
    
    
    vector<graph_node> graph;
    void add_AdjList(graph_node,graph_node);
    void print_graph();
    void BFS(string , string);
    void print_word_ladder(graph_node*,string);
    void form_graph(vector<string>, int);
    int count_of_words;
    int word_distance(string, string);
    int max_count;
    int check_limit_count(graph_node*,string);
    void reset_visit_flag();
    Graphs();
    
    
};

#endif /* defined(__GraphApplication__Graphs__) */
