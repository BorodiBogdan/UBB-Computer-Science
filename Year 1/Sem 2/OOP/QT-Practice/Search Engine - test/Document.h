//
// Created by Bob on 5/27/2024.
//

#ifndef EQUATIONS_DOCUMENT_H
#define EQUATIONS_DOCUMENT_H
using namespace std;
#include <string>

class Document {
private:
    string name, keyWords, content;
public:
    Document(string name, string keyWords, string content);
    string getName();
    string getKeyWords();
    string getContent();
};


#endif //EQUATIONS_DOCUMENT_H
