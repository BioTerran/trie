#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

void addWordsToTrie(Trie& trie, char **argv){
    // Initialize stream
    ifstream inputFile;
    // Open file to be read from
    inputFile.open(argv[1]);
    // Check to make sure file opened properly
    if(!inputFile.is_open()){
        cout << "Could not open " << argv[1] << " properly." << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }

    string word;
    // Add all words to trie
    while(getline(inputFile, word)){
        trie.addWord(word);
    }

    // Close input file
    inputFile.close();
}

void checkWordsInTrie(Trie& trie, char **argv){
    // Initialize stream
    ifstream inputFile;
    // Open file to be read from
    inputFile.open(argv[2]);
    // Check to make sure file opened properly
    if(!inputFile.is_open()){
        cout << "Could not open " << argv[2] << " properly." << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }

    string word;
    // Add all words to trie
    while(getline(inputFile, word)){
        if(trie.isWord(word)){
            cout << word << " is found" << endl;
        }else{
            cout << word << " is not found, did you mean:" << endl;
            vector<string> results = trie.allWordsStartingWithPrefix(word);
            if(results.size() > 0){
                for(auto otherWord: results){
                    cout << "   " << otherWord << endl;
                }
            }else{
                cout << "   no alternatives found" << endl;
            }
        }
    }

    // Close input file
    inputFile.close();
}

int main(int argc, char **argv){

    // Should only be three argument: this files name, filename of words to add to trie,
    // and filename of words to be tested.
    if(argc != 3){
        cout << "Incorrect amount of arguments. Please enter two arguments." << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }

    Trie trie;
    
    // Add all the words in the first file to the trie
    addWordsToTrie(trie, argv);

    // Check if the test words are in the trie
    checkWordsInTrie(trie, argv);

    // Trie copy;

    // copy = trie;
    // checkWordsInTrie(copy, argv);

    // Trie copy2;

    // copy2 = copy;
    // checkWordsInTrie(copy2, argv);

    // vector<string> list = copy2.wordsWithWildcardPrefix("c????");
    // for(string word: list){
    //     cout << word << endl;
    // }
    
}

