// File name: TrieNode.h
// Author: Scott Kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: #10
// Description: This class will provide support for TrieNode, which is a node of the Trie
// Honor statement: I have not given or received unauthorized aid on this assignment
// Last Changed: 2019 12/04

#ifndef PROJECT10_TRIENODE_H
#define PROJECT10_TRIENODE_H

#include <cstddef>   // make gcc & CLion happy
#include <stdexcept>

const size_t numAlphabet = 26;

class TrieNode
{
private:

    char item;
    bool end;
    TrieNode* nextNode[numAlphabet];

public:
    // Class Constructor
    TrieNode(char c, bool b);

    // Copy Constructor
    // pre:  Class object, rhs, exists
    // post: Object is initialized to be a copy of the parameter
    TrieNode(const TrieNode& rhs);

    // Class Destructor
    // Destroys a TrieNode
    // pre:  Class object exists
    // post: Class object does not exist
    ~TrieNode();

    // Assignment operator
    // Assigns a TrieNode to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const TrieNode& operator= (const TrieNode& rhs);

    // insert
    // Insert str starting with the given TrieNode. Create new TrieNodes as needed and be sure to set the boolean
    // flag on the last node to true.
    // pre:  Trie exists
    void insert (const std::string& str);

    // isWord
    // Returns true if str is in the sub-Trie starting at the given TrieNode, else returns false
    // pre:  Trie exists and string parameter is passed
    // post: Returns true if there is the word in the trie
    bool isWord (const std::string& str) const;

    // isPrefix
    // Returns true if pre is a prefix of a word in the sub-Trie starting at the given TrieNode, else returns false
    // pre:  Trie exists
    // post: Returns true or false
    //       was already empty, throws an std::underflow_error exception.
    bool isPrefix (const std::string& pre) const;

    // print
    // Prints all words starting at the given TrieNode. The parameter string str stores the letters of all previous
    // TrieNode objects up to the node currently being processed
    // pre:  Trie exists
    void print (const std::string& str) const;

    // wordCount
    // Returns a count all the nodes in the sub-Trie that end a word.
    // pre: Trie exists
    // post: returns the number of nodes
    size_t wordCount ( ) const;

};

#endif //PROJECT10_TRIENODE_H
