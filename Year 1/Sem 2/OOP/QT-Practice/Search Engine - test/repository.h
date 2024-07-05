//
// Created by Bob on 5/27/2024.
//

#ifndef EQUATIONS_REPOSITORY_H
#define EQUATIONS_REPOSITORY_H
#include <vector>
#include "Document.h"

class Repository {
private:
    vector<Document> documentList;
public:
    Repository();
    void readFromFile();
    vector <Document> getDocuments();
};


#endif //EQUATIONS_REPOSITORY_H
