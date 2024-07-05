//
// Created by Bob on 5/27/2024.
//

#include "service.h"
#include <algorithm>

vector<Document> Service::getDocuments() {
    vector <Document> documentList = this -> repo.getDocuments();

    sort(documentList.begin(), documentList.end(), [](Document a, Document b)->bool{
        return a.getName() > b.getName();
    });

    return documentList;
}

vector<Document> Service::getMatchingStrings(string name) {
    vector <Document> documentList;

    for(auto document : this -> repo.getDocuments()){
        if(document.getName().find(name) != -1 || document.getKeyWords().find(name) != -1){
            documentList.push_back(document);
        }
    }
    return documentList;
}

Document Service::getBestMatch(string name) {
    Document bestMatchDocument = Document("" ,"", "");

    float matchingPrecentage, maxMatching = 0;

    for(auto document : this -> repo.getDocuments()){
        if(document.getName().find(name) != -1) {
            matchingPrecentage = 1.0 * name.size() / document.getName().length();

            if (matchingPrecentage > maxMatching) {
                maxMatching = matchingPrecentage;
                bestMatchDocument = document;
            }
        }
    }
    return bestMatchDocument;
}
