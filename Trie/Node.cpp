#include <string>
#include "Node.h"
using namespace std;


Node::Node(){
    validWord = false;

    // Initialize the node pointer array to nullptr
    for(int i = 0; i < 26; i++){
        list[i] = nullptr;
    }
}

Node::Node(const Node& other){
    validWord = other.validWord;

    // Copy array over
    for(int i = 0; i < 26; i++){
        if(other.list[i] != nullptr){
            list[i] = new Node(*(other.list[i]));
        }else{
            list[i] = nullptr;
        }
    }
}

Node::~Node(){
    // Delete allocated memory
    for(int i = 0; i < 26; i++){
        if(list[i] != nullptr){
            delete list[i];
        }
    }
}

Node& Node::operator=(Node other){
    swap(validWord, other.validWord);
    swap(list, other.list);
    return *this;
}



void Node::addWord(string word){
    // Get index of first character of word
    int index = word[0]-97;

    // Check to see if a branch has already been made, if not create one.
    if(list[index] == nullptr){
        list[index] = new Node;
    }

    // Check to see if word size is greater than 1, if so then pass word to next node
    if(word.size() > 1){
        list[index]->addWord(word.substr(1));
    }else{
        // Make the node of the final character a valid word
        list[index]->validWord = true;
    }
    


}

bool Node::isWord(string word){
    // Get index of first character of word
    int index = word[0]-97;

    if(list[index] == nullptr){
        return false;
    }else{
        if(word.size() > 1){
            return list[index]->isWord(word.substr(1));
        }else{
            return list[index]->validWord;
        }
    }
}

vector<string>* Node::allWordsStartingWithPrefix(string prefix){
    // Get index of first character of word
    int index = prefix[0]-97;

    if(prefix == ""){
        vector<string>* returnList = new vector<string>();
        return getAllWordsDownward(returnList, "");
    }

    if(prefix[0] == '?'){
        vector<string>* empty = new vector<string>();
        return empty;
    }

    // This prefix doesn't match any words so it should return an empty list
    if(list[index] == nullptr){
        // cout << "# No words with prefix found:" << " " << prefix << endl;
        vector<string>* emptyListOfWords = new vector<string>();
        return emptyListOfWords;
    }else{
        // Go to the end of the prefix before getting all words with that prefix
        if(prefix.size() > 1){
            // cout << "# Prefix is still greater than 1:" << prefix << " " << index << endl; 
            return list[index]->allWordsStartingWithPrefix(prefix.substr(1));
        }else{
            // cout << "# Time to get all words from here downward" << endl;
            // Get all words now from this node downward
            vector<string>* returnList = new vector<string>();
            return list[index]->getAllWordsDownward(returnList, "");
        }
    }
}

vector<string>* Node::getAllWordsDownward(vector<string>* stringList, string wordMade){

    // cout << "# Getting all words downward - listSize " << stringList->size() << " wordMade: " << wordMade << endl;

    if(validWord){
        // cout << "# Valid word found: " << wordMade << endl;
        stringList->push_back(wordMade);
        // cout << "# Valid word added: " << wordMade << endl;
    }

    for(int i = 0; i < 26; i++){
        if(list[i] != nullptr){
            char addedChar = i+97;
            // cout << "# Char is not null: " << addedChar << " added to "<< wordMade << endl;
            string alteredWord = wordMade;
            alteredWord.push_back(addedChar);
            // cout << "# Altered word is: " << alteredWord << endl;
            //cin.get();
            stringList = list[i]->getAllWordsDownward(stringList, alteredWord);
        }
    }

    return stringList;

}
