//
// Created by Bob on 5/27/2024.
//

#include "Document.h"

Document::Document(string name, string keyWords, string content) {
    this -> name = name;
    this -> keyWords = keyWords;
    this -> content = content;
}

string Document::getName() {
    return this -> name;
}

string Document::getKeyWords() {
    return this -> keyWords;
}

string Document::getContent() {
    return this -> keyWords;
}
