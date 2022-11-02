// File name: Trie.h
// Author: Scott Kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: #10
// Description: This class will provide support for Trie
// Honor statement: I have not given or received unauthorized aid on this assignment
// Last Changed: 2019 12/5

#ifndef PROJECT10_TRIE_H
#define PROJECT10_TRIE_H

#include <string>
#include "TrieNode.h"

class Trie
{
private:

    TrieNode root;

public:
    // The default constructor
    Trie();

    // insert
    // Insert the parameter word into the Trie
    // pre:  A Trie exists and the parameter contains a lowercase valid word
    void insert (const std::string& str);

    // loadFromFile
    // Insert all words in the specified file into the Trie.
    // Throws a std::invalid_argument exception if the specified file cannot be opened.
    // pre: file is valid and contains string
    void loadFromFile (const std::string& filename);

    // isWord
    // checks if the word is in the Trie
    // pre:  A Trie exists
    // post: Returns true if word is in the Trie, else returns false
    bool isWord (const std::string& str) const;

    // isPrefix
    // Returns true if pre is a prefix of a word in the Trie, else returns false
    // pre:  A Trie exists
    // post: Returns true if pre is a prefix of a word in the Trie, else returns false
    bool isPrefix (const std::string& pre) const;

    // print
    // Print all words in the Trie, one per line. Print in alphabetical order.
    // pre:  Trie exists.
    void print () const;

    // wordCount
    // Returns a count all the words in the Trie
    // pre: Trie exists
    size_t wordCount ( ) const;

};

#endif //PROJECT10_TRIE_H

