//
// Created by Bob on 6/23/2024.
//

#include "utils.h"

bool isDelimiter(char c,vector<char> delimiters) {
    for (auto x: delimiters)
        if (c == x)
            return true;

    return false;

}

vector<string> utils::tokenize(vector<char> &tokens, const string &text) const {
    string word = "";
    vector<string> words;

    for (int i = 0; i < text.size(); i++) {
        if (isDelimiter(text[i], tokens)) {
            words.push_back(word);
            word = "";
        } else {
            word += text[i];
        }
    }

    words.push_back(word);

    return words;
}
