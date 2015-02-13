//
//  main.cpp
//  GraphApplication
//
//  Created by Shiv chandra Kumar on 11/30/14.
//  Copyright (c) 2014 Shiv chandra Kumar. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Graphs.h"
using namespace std;

Graphs graphObj;

//Main function is reading the file from the argument and processing it and sending all
//the words together to form a graph. which will further used in Word ladder creation.
int main(int argc, const char * argv[]) {
    ifstream myfile(argv[1]);
    string line;
    vector<string> wordlist;
    int count_word = 0;
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile, line);
            count_word++;
            wordlist.push_back(line);
        }
    }
    else
        cout<<"could not open the file";
    
    graphObj.form_graph(wordlist, count_word);
    
    string word1;
    string word2;
    do{
    cout<<"Enter Source(enter exit to terminate):"<<endl;
        cin>>word1;
        if(word1 == "exit"){
            cout<<"---End of Word Ladder----"<<endl;
            break;
        }
        cout<<"Enter destination(enter exit to terminate):"<<endl;
        cin>>word2;
        if(word2 == "exit"){
            cout<<"---End of Word Ladder----"<<endl;
            break;
        }
    if(word1.size() != word2.size()){
        cout<<"Error:please enter both word of same size"<<endl;
    }
    else{
        graphObj.BFS(word2, word1);
    }
    }while(word1 != "exit" || word2 != "exit");
    
    return 0;
}




//"/Users/Shiv/Desktop/words"





