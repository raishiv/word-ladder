//
//  Graphs.cpp
//  GraphApplication
//
//  Created by Shiv chandra Kumar on 11/30/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#include "Graphs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
bool found_ladder = false;
int count_number = 0;

Graphs::Graphs(){
    max_count = 0;
}


//Formation of graph is done here. Method used is Adjacency list
void Graphs::form_graph(vector<string> wordlist, int word_count){
    count_of_words = word_count;
    graph_node node;
    for(int i =0; i< count_of_words; i++){
        node.data = wordlist[i];
        node.visited = false;
        graph.push_back(node);
    }
    string word1;
    string word2;
    int diff = 0;
    for( int j =0; j< count_of_words ; j++){
        vector<graph_node*> adj_nodes ;
        for(int k = 0; k< count_of_words; k++){
            if(j != k){
                word1 = graph[j].data;
                word2 = graph[k].data;
                
                diff = word_distance(word1, word2);
                if(diff == 1){
                    adj_nodes.push_back(&graph[k]);
                    
                }
            }
        }
        graph[j].next = adj_nodes;
        
        
    }
    //print_graph();
    return;
}



//printing graph for experimental usage
void Graphs::print_graph(){
    for(int l =0 ; l < count_of_words; l++){
        cout<<graph[l].data<<"---->";
        for( int m =0; m < graph[l].next.size(); m++){
            cout<<graph[l].next[m]->data<<",";
        }
        cout<<endl;
        
    }
    
}




//calculate difference between words and send the difference. we are looking for words with difference 1.
int Graphs::word_distance(string word1, string word2 ){
    int diff = 0;
    for( int i = 0; i < word1.length( ); i++ ){
        if( word1[i] != word2[i] )
            diff++;
    }

    return diff;
}




//Using breadth first search for traversing through the graph. Stop when the destination is reached
void Graphs::BFS(string word1,string word2){
    graph_node* node1;
    graph_node* node2;
    bool found1 = false;
    bool found2 = false;
    max_count = int(word1.length());
    
    
    for(int i = 0 ; i < count_of_words ; i++){
        if(graph[i].data == word1){
            node1 = &(graph[i]);
            found1 = true;
        }
        else if(graph[i].data == word2){
            node2 = &(graph[i]);
            found2 = true;
        }
    }
    if(found1 && found2){
        queue<graph_node*> queue_graph;
        queue_graph.push(node1);
        node1->visited = true;
        graph_node* cur_node;
        graph_node* found_node;
        string current = node1->data;
        while(!(queue_graph.empty())){
            cur_node = queue_graph.front();
            queue_graph.pop();
            bool got = false;
            for(int j = 0; j< cur_node->next.size(); j++){
                if(cur_node->next[j]->data == node2->data){
                    cur_node->next[j]->pred = cur_node;
                    found_node = cur_node->next[j];
                    got = true;
                    break;
                }
            }
            if(got){
                check_limit_count(found_node,current);
                if(count_number <= max_count){
                    cout<<"Word Ladder is as follows:"<<endl;
                    cout<<found_node->data<<endl;
                    print_word_ladder(found_node, current);
                }
                else{
                    cout<<"Cannot Convert. It is taking more than "<<max_count<<" steps"<<endl;
                }
                break;
               
            }
            
            for(int j = 0; j< cur_node->next.size(); j++){
                 if(cur_node->next[j]->visited == false){
                    queue_graph.push(cur_node->next[j]);
                    cur_node->next[j]->pred = cur_node;
                    cur_node->next[j]->visited = true;
                }
                
            }
        
        }
        reset_visit_flag();
        
    }
    else{
        cout<<"Atleast one of the words is not found in the list of input words. Please check your input"<<endl;
    }
}





//reset all the visited flag and count of the number after one iteration of finding source to destination
void Graphs::reset_visit_flag(){
    for(int i = 0; i< count_of_words ; i++){
        graph[i].visited = false;
    }
    count_number = 0;
}







//print the word lader
void Graphs::print_word_ladder(graph_node* node , string source){
    cout<<node->pred->data<<endl;
    if(node->pred->data != source){
        print_word_ladder(node->pred,source);
    }
    
    return;
}



//check the limit of K. if it takes more than K steps to convert it should not
//print result an dprint cannot convert
int Graphs::check_limit_count(graph_node* node , string source){
    count_number++;
    if(node->pred->data != source){
        
        check_limit_count(node->pred,source);
    }

    return count_number;
}



