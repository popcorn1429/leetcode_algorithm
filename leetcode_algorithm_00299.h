#pragma once
#include "basic_headers.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int duplicated = removeDuplicated(secret, guess);
        int intersected = intersection(secret, guess);

        return to_string(duplicated) + "A" + to_string(intersected) + "B";
    }

    int removeDuplicated(string &secret, string &guess) {
        int duplicated = 0;
        string newSecret, newGuess;
        for (size_t i = 0; i < secret.size() || i < guess.size(); ++i) {
            if (i < secret.size() && i < guess.size()) {
                if (secret[i] != guess[i]) {
                    newSecret += secret[i];
                    newGuess += guess[i];
                }
                else {
                    ++duplicated;
                }
            }
            else {
                if (i < secret.size()) newSecret += secret[i];
                if (i < guess.size()) newGuess += guess[i];
            }
        }

        secret = newSecret;
        guess = newGuess;

        return duplicated;
    }

    int intersection(const string &secret, string &guess) {
        int intersected = 0;
        for (size_t i = 0; i < secret.size(); ++i) {
            for (size_t j = 0; j < guess.size(); ++j) {
                if (secret[i] == guess[j]) {
                    ++intersected;
                    swap(guess[j], guess[guess.size() - 1]);
                    guess.resize(guess.size() - 1);
                    break;
                }
            }
        }
        return intersected;
    }
};