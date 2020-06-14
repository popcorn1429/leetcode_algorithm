#pragma once
#include "basic_headers.h"

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;

        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "+") {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            }
            else if (ops[i] == "D") {
                scores.push_back(2 * scores[scores.size() - 1]);
            }
            else if (ops[i] == "C") {
                scores.pop_back();
            }
            else {
                scores.push_back(stoi(ops[i]));
            }
        }

        int total = 0;
        for (int i = 0; i < scores.size(); ++i) {
            total += scores[i];
        }

        return total;
    }
};