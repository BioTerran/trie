#include <string>
#include <vector>
using namespace std;

class Node{
private:
    // Array of node pointers
    Node *list[26];
    // Whether or not up to the current node is a valid word
    bool validWord;

public:

    // Default constructor
    Node();
    // Copy constructor
    Node(const Node& other);
    // Destructor
    ~Node();

    // Deep copy overrided equal operator
    Node& operator=(Node other);

    // Method to add a word
    void addWord(string word);
    // Method to check if the given word is a valid word
    bool isWord(string word);

    // Get all words starting with prefix
    vector<string>* allWordsStartingWithPrefix(string prefix);
    // Get all words downward
    vector<string>* getAllWordsDownward(vector<string>* stringList, string wordMade = "");
};