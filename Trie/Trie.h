#include <string>
#include <vector>
#include "Node.h"

using namespace std;

/* Trie class that can create a trie from added words. */
class Trie{
private:
    // Main root node
    Node *rootNode;

public:
    // Basic constructor
    Trie();
    // Copy Constructor
    Trie(const Trie& other);
    // Destructor
    ~Trie();

    // Deep copy equal operator
    Trie& operator=(Trie other);

    // Method used to add words to trie
    void addWord(string word);
    // Method used to check if word is valid word in trie
    bool isWord(string word);

    // Gets all words starting from certain prefix
    vector<string> allWordsStartingWithPrefix(string prefix);
    // Gets all words with prefix where question marks are wildcards
    vector<string> wordsWithWildcardPrefix(string word);
    // Helper method that gets all words possibilities from wildcards in words
    vector<string> getAllWordPossibilities(string word, int index);
};