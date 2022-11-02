// File name: TextTwist.cpp
// Author: scott kang
// userid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: #10
// Description: contains code for the game TextTwist
// Honor statement: I have not given or received unauthorized aid on this assignment
// Last Changed: 2019 12/5

#include "Trie.h"
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>

const size_t numLetters = 7;

bool isLower(std::string str);
void allWords(std::string letters, const Trie& lexicon, Trie& possibleList, std::string word, bool check[]);

int main() {

    std::string filename = "ospd.txt";

    Trie lexicon;

    std::cout << "Loading valid words. Please wait... \n" << std::endl;
    lexicon.loadFromFile(filename);
    std::cout << "Welcome to the TEXT TWIST SOLVER.\n" << std::endl;

    std::string input;
    std::string choice;

    do {
        std::cout << "Enter the 7 letters of the Text Twist game: ";
        std::cin >> input;

        // as long as the input is not lowercase and not 7 letters long, ask for new input

        while (input.size() != numLetters || !isLower(input)) {
            if(input.size() != numLetters){
                std::cout << "You must enter exactly 7 characters.\n" << std::endl;
                std::cout << "Enter the 7 letters of the Text Twist game: ";
                std::cin >> input;
            }else if(!isLower(input)){
                std::cout << "You must enter only lower case alphabetic characters.\n" << std::endl;
                std::cout << "Enter the 7 letters of the Text Twist game: ";
                std::cin >> input;
            }
        }

        Trie possibleList;

        // create a bool array with the size that is same as the input letters
        // initialize all the index with false value
        // each position will indicate if the letter is used or not.
        // used = true, unused = false

        bool check[numLetters];
        for(bool & i : check){
            i = false;
        }

        //process the letters and find the words
        //put the words into the possibleList
        allWords(input, lexicon, possibleList, "", check);

        //print the list (in alphabetical order)
        possibleList.print();


        std::cout << std::endl;

        std::cout << "\nDo you want to do it again? (Y|N)";
        std::cin >> choice;

    } while (choice.at(0) == 'Y' || choice.at(0) == 'y');

    return 0;
}

//isLower
//checks if the input string contains any uppercase letter
//pre: string input is a valid string with only alphabets
//post:: return true if all the letters are lowercase. Else return false.
bool isLower(std::string input){
    for(char i : input){
        if(isupper(i)){
            return false;
        }
    }
    return true;
}

//allWords
//puts all the valid words into the possibleList
//pre: lexicon contains dictionary words. PossibleList and word are empty.
//letters has a size of numLetters, check is initialized with all false value
//post: possibleList will contain all the words found in lexicon using the combinations of letters
void allWords(std::string letters, const Trie& lexicon, Trie& possibleList, std::string word, bool check[]) {

    for(size_t i = 0; i < letters.size(); i++){

        //if the letter is unused, then add it to the word

        if(!check[i]){
            word += letters[i];

            //if the word is a prefix of the lexicon and it is not already a prefix of possibleList
            //then use recursion to find the next letter to add
            //since the letter is used, it is changed to true

            if(lexicon.isPrefix(word) && !possibleList.isPrefix(word)){
                check[i] = true;
                allWords(letters, lexicon, possibleList, word, check);
            }

            //insert the word into possibleList if it is a word in lexicon and the size is >= 3

            if(lexicon.isWord(word) && word.size() >= 3){
                possibleList.insert(word);
            }

            //change the letter as unused (backtracking)
            //delete the last letter as it wants to explore other options starting with different letter

            check[i] = false;
            if(word.size() == 1){
                word = "";
            }else{
                word = word.substr(0,word.size()-1);
            }
        }
    }
}


