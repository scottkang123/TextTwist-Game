// File name: TrieNode.cpp
// Author: scott kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: #10
// Description: Contains code for function methods mentioned in TrieNode.h
// Honor statement: I have not given or received unauthorized aid on this assignment
// Last Changed: 2019 12/5

#include <cstddef>
#include <stdexcept>
#include "TrieNode.h"
#include <iostream>

// Class Constructor

TrieNode::TrieNode(char c, bool b) : item(c), end(b) {
    for(size_t i = 0; i < numAlphabet; i++){
        nextNode[i] = nullptr;
    }
}

// Copy Constructor
// pre:  Class object, rhs, exists
// post: Object is initialized to be a copy of the parameter

TrieNode::TrieNode(const TrieNode &rhs): item(rhs.item), end(rhs.end) {

    for (size_t i = 0; i < numAlphabet; i++) {
        if (rhs.nextNode[i] != nullptr) {
            nextNode[i] = rhs.nextNode[i];
        }else{
            nextNode[i] = nullptr;
        }
    }
}

// Class Destructor
// Destroys a TrieNode
// pre:  Class object exists
// post: Class object does not exist
TrieNode::~TrieNode() {
    for(size_t i = 0; i < numAlphabet; i++) {
        delete nextNode[i];
        nextNode[i] = nullptr;
    }
}

// Assignment operator
// Assigns a TrieNode to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const TrieNode &TrieNode::operator=(const TrieNode &rhs) {

    if (this != &rhs) {
        TrieNode temp(rhs);
        std::swap(item, temp.item);
        std::swap(end, temp.end);
        for (size_t i = 0; i < numAlphabet; i++) {
            std::swap(nextNode[i], temp.nextNode[i]);
        }
    }
    return *this;
}

// insert
// Insert str starting with the given TrieNode. Create new TrieNodes as needed and be sure to set the boolean
// flag on the last node to true.
// pre:  Trie exists
void TrieNode::insert(const std::string &str) {

    if (!str.empty()) {

        size_t index = str[0] - 'a';

        if(item == str[0] &&  str.size() == 1){
            end = true;
        }else if(item == str[0]){
            index = str[1] - 'a';
            if (nextNode[index] == nullptr) {
                nextNode[index] = new TrieNode(str[1], false);
            }
            (*nextNode[index]).insert(str.substr(1));
        }else if (item == ' ') {
            if (nextNode[index] == nullptr) {
                nextNode[index] = new TrieNode(str[0], false);
            }
            (*nextNode[index]).insert(str);
        }
    }

}

// isWord
// Returns true if str is in the sub-Trie starting at the given TrieNode, else returns false
// pre:  Trie exists and string parameter is passed
// post: Returns true if there is the word in the trie
bool TrieNode::isWord(const std::string &str) const {

    if (str.empty()) {
        return false;
    }

    size_t index = str[0] - 'a';

    if (item == ' ') {
        if (nextNode[index] != nullptr) {
            return nextNode[index]->isWord(str);
        } else {
            return false;
        }
    }

    if(item == str[0] && end && str.size() == 1){
        return true;
    }else if(item == str[0]){
        index = str[1] - 'a';
        if (nextNode[index] != nullptr) {
            return (*nextNode[index]).isWord(str.substr(1));
        }else{
            return false;
        }
    }
    return false;

}


// isPrefix
// Returns true if pre is a prefix of a word in the sub-Trie starting at the given TrieNode, else returns false
// pre:  Trie exists
// post: Returns true or false
//       was already empty, throws an std::underflow_error exception.
bool TrieNode::isPrefix(const std::string &pre) const {

    if (pre.empty()) {
        return true;
    }

    size_t index = pre[0] - 'a';

    if (item == ' ') {
        if (nextNode[index] != nullptr) {
            return (*nextNode[index]).isPrefix(pre);
        } else {
            return false;
        }
    }

    if(item == pre[0] && pre.size() == 1){
        return true;
    }else if(item == pre[0]){
        index = pre[1] - 'a';
        if (nextNode[index] != nullptr) {
            return (*nextNode[index]).isPrefix(pre.substr(1));
        } else {
            return false;
        }
    }

    return false;
}

// print
// Prints all words starting at the given TrieNode. The parameter string str stores the letters of all previous
// TrieNode objects up to the node currently being processed
// pre:  Trie exists
void TrieNode::print(const std::string &str) const {

    if (item == ' ') {
        for (auto i : nextNode) {
            if (i != nullptr) {
                i->print(str);
            }
        }
    }else{
        if (end) {
            std::cout << str + item + " " << std::endl;
        }
        for (auto i : nextNode) {
            if (i != nullptr) {
                i->print(str + item);
            }
        }
    }
}

// wordCount
// Returns a count all the nodes in the sub-Trie that end a word.
// pre: Trie exists
// post: returns the number of nodes
size_t TrieNode::wordCount() const {
    size_t num = 0;
    if (end) {
        num++;
    }
    for (auto i : nextNode) {
        if (i != nullptr) {
            num += i->wordCount();
        }
    }
    return num;
}


