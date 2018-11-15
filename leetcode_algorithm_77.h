#ifndef __leetcode_algorithm_77_h__
#define __leetcode_algorithm_77_h__
#include "basic_headers.h"
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        results.push_back(vector<int>());
        results.reserve(k);
        for (int i = 1; i <= k; ++i) {
            results.back().push_back(i);
        }
        
        vector<int> next;
        do {
            next.reserve(k);
            if (getNext(results.back(), n, next)) {
                results.push_back(vector<int>());
                results.back().swap(next);
            }
            else {
                break;
            }
        } while (true);
        return results;
    }

    bool getNext(const vector<int> &current, int n, vector<int> &next) {
        if (current.front() == n - current.size() + 1) {
            return false;
        }

        int pos = current.size() - 1;
        while (n == current[pos] + current.size() - 1 - pos) {
            --pos;
        }

        for (int i = 0; i < pos; ++i) {
            next.push_back(current[i]);
        }
        for (int i = pos; i < current.size(); ++i) {
            next.push_back(current[pos] + 1 + i - pos);
        }
        return true;
    }

    void printCombinations(const vector<vector<int>> &results) {
        cout << "All sequences are: " << endl;
        for (const auto &sequence : results) {
            cout << "[ ";
            for (int i : sequence) {
                cout << setw(2) << i << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }
};
#endif /*__leetcode_algorithm_77_h__*/
