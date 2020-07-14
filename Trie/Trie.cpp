#include <string>
#include <vector>
#include "Trie.h"

using namespace std;

 Trie::Trie() {
    // Create new node on heap
    rootNode = new Node();
 }

 Trie::Trie(const Trie& other){
    // Create other new node on heap
    rootNode = new Node(*(other.rootNode));
 }

 Trie::~Trie(){
    // Delete rootnode
    delete rootNode;
 }

 Trie& Trie::operator=(Trie other){
    swap(rootNode, other.rootNode);
    return *this;
 }

 void Trie::addWord(string word){
    rootNode->addWord(word);
 }

 bool Trie::isWord(string word){
     // If word is an empty string then return false
    if(word.length() == 0){
        return false;
    }

    // Check if trie contains string
    return rootNode->isWord(word);
 }

 vector<string> Trie::allWordsStartingWithPrefix(string prefix){
    // Return list of all valid words with that prefix
    // cout << "# Searching for words starting with " << prefix << endl;
    vector<string>* resultList = rootNode->allWordsStartingWithPrefix(prefix);

    // cout << "# List returned to trie" << endl;

    vector<string> finalList;

    // Loop thru all and add prefix to word
    for(auto word: *resultList){
        finalList.push_back(prefix + word);
    }

    delete resultList;

    return finalList;
}

vector<string> Trie::wordsWithWildcardPrefix(string word){
    vector<string> resultList;

    // Find the indexes where all the wildcards are at.
    vector<int> wildCardList;
    for(unsigned int i = 0; i < word.length(); i++){
        if(word[i] == '?'){
            wildCardList.push_back(i);
            // cout << "Char at " << i << " is a question mark" << endl;
        }
    }

    // cout << wildCardList.size() << " is size of Wildcard List" << endl;

    // Get all string possibilities from question marks
    vector<string> listOfWords;
    // Put in initial word
    listOfWords.push_back(word);        

    for(unsigned int i = 0; i < wildCardList.size(); i++){

        int index = wildCardList[i];

        // cout << "String possibilities list index is at " << index << endl;

        int listSize = listOfWords.size();

        for(int j = 0; j < listSize; j++){
            vector<string> temp = getAllWordPossibilities(listOfWords[j], index);
            listOfWords.insert(listOfWords.end(), temp.begin(), temp.end());
        }
    }


    
    // Get all words starting with all the prefixes
    for(string word: listOfWords){
        vector<string> temp = allWordsStartingWithPrefix(word);
        resultList.insert(resultList.end(), temp.begin(), temp.end());
    }

    // Print out list of wildcard words.
    // cout << "Resulting list of all words with wildcard prefix" << endl;
    // for(string word: resultList){
    //     cout << word << endl;
    // }

    return resultList;
}

vector<string> Trie::getAllWordPossibilities(string word, int index){
    vector<string> possibleWords;

    for(int i = 0; i < 26; i++){
        word[index] = 97 + i;
        // cout << word << endl;
        possibleWords.push_back(word);
    }

    return possibleWords;
}