
// File name: Trie.cpp
// Author: Scott Kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: #10
// Description: This class will provide support for Trie
// Honor statement: I have not given or received unauthorized aid on this assignment
// Last Changed: 2019 12/5

#include <stdexcept>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Trie.h"

//Constructor
Trie::Trie(): root(' ', false){

}

// insert
// Insert the parameter word into the Trie
// pre:  Trie exists
void Trie::insert(const std::string &str) {
    root.insert(str);
}

// loadFromFile
// Insert all words in the specified file into the Trie.
// shows message if the specified file cannot be opened.
// pre: file is valid and contains string
void Trie::loadFromFile(const std::string& filename){

    std:: string str;
    std::ifstream file(filename.c_str());
    if (!file) {
        throw std::invalid_argument("file does not exists");
    }
    while(file >> str){
        root.insert(str);
    }
}


// isWord
// Returns true if word is in the Trie, else returns false
// pre:  Trie exists and string parameter is passed
// post: Returns true if there is the word in the trie
bool Trie::isWord(const std::string &str) const {
    return root.isWord(str);
}


// isPrefix
// Returns true if pre is a prefix of a word in the Trie, else returns false
// pre:  Trie exists
// post: Returns true or false
//       was already empty, throws an std::underflow_error exception.
bool Trie::isPrefix(const std::string &pre) const {
    return root.isPrefix(pre);
}

// print
// Print all words in the Trie, one per line. Print in alphabetical order.
// pre:  Trie exists
void Trie::print() const {
    root.print("");
}

// wordCount
// Returns a count all the words in the Trie
// pre: Trie exists
// post: returns the number of nodes
size_t Trie::wordCount() const {
    return root.wordCount();
}
