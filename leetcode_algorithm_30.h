#ifndef __leetcode_algorithm_30_h__
#define __leetcode_algorithm_30_h__
#include <string>
#include <vector>
#include <set>
#include<random>    //随机数
using namespace std;

class Solution {
public:
    /*
    vector<int> findSubstring(string s, vector<string>& words) {
        const char* str = s.c_str();
        auto sz = words.size();
        auto len = words[0].size();
        auto sum_length = sz*len;
        if (s.size() < sum_length)
            return vector<int>();

        bool* record = new bool[sz];
        memset(record, 0, sizeof(bool)*sz);

        const char* first_word = words[0].c_str();
        //vector<int> result;
        set<int> all_begins;
        set<int> result;

        int pos = -1;
        while ((pos = find_word(str, first_word, pos)) != -1) {
            memset(record, 0, sizeof(bool)*sz);
            record[0] = true;
            match_all(words, record, sz, str, pos, len, result, all_begins);
        }
        
        vector<int> vecResult;
        for (int i : result) {
            vecResult.push_back(i);
        }
        return vecResult;
    }
    */
    int find_word(const char* str, const char* word, int pos) {
        ++pos;
        while (*(str + pos) != '\0') {
            if (*(str + pos) == *word) {
                int i = 0;
                bool matched = true;
                while (*(word + i) != '\0') {
                    if (*(str + pos + i) != *(word + i)) {
                        matched = false;
                        break;
                    }
                    ++i;
                }

                if (matched) {
                    return pos;
                }
            }
            ++pos;
        }
        return -1;
    }

    void match_all(const vector<string>& words, bool* record, const int sz, const char* str, int pos, const int len, set<int>& result, set<int>& all_begins) {
        if (all_begins.find(pos) == all_begins.end()) {
            if (match_right(words, record, sz, str, pos, len)) {
                result.insert(pos);
            }
            memset(record, 0, sz*sizeof(bool));
            record[0] = true;
            all_begins.insert(pos);
        }

        auto begin_pos = pos - len;
        while (begin_pos >= 0 && (all_begins.find(begin_pos) == all_begins.end()) && match_word(words, record, sz, str, begin_pos, len)) {
            bool *tmp_record = new bool[sz];
            memcpy(tmp_record, record, sz*sizeof(bool));
            if (match_right(words, tmp_record, sz, str, pos, len)) {
                result.insert(begin_pos);
            }
            delete[] tmp_record;
            tmp_record = nullptr;
            all_begins.insert(begin_pos);

            begin_pos -= len;
        }
    }

    bool match_right(const vector<string>& words, bool* record, const int sz, const char* str, int pos, const int len) {
        int right_pos = pos + len;
        while (match_word(words, record, sz, str, right_pos, len)) {
            right_pos += len;
        }

        bool matched_all = true;
        for (int i = 0; i < sz; ++i) {
            if (!record[i]) {
                matched_all = false;
                break;
            }
        }

        return matched_all;
    }

    bool match_word(const vector<string>& words, bool* record, const int sz, const char* str, int pos, const int len) {
        bool matched = false;
        for (int i = 1; i < sz; ++i) {
            if (!record[i]) {
                const char* word = words[i].c_str();
                if (compare(word, str + pos, len)) {
                    matched = true;
                    record[i] = true; //这一个不能再次参与匹配了
                    break;
                }
            }
        }
        return matched;
    }

    bool compare(const char* first, const char* second, const int len) {
        for (int i = 0; i < len; ++i) {
            if (first[i] != second[i])
                return false;
        }
        return true;
    }




    double hash(double f, double code[], string &word) {
        double result = 0.;
        for (auto &c : word) result = result * f + code[c];
        return result;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        uniform_real_distribution<double> unif(0., 1.);
        default_random_engine seed;
        double code[128];
        for (auto &d : code) d = unif(seed);
        double f = unif(seed);// / 5. + 0.8;
        double value = 0;

        // The complexity of the following for loop is O(L.size( ) * nW).
        for (auto &str : L) value += log(hash(f, code, str));
        int unit = 1e9;
        int key = (value - floor(value))*unit;
        int nS = S.size(), nL = L.size(), nW = L[0].size();
        double fn = pow(f, nW - 1.);
        vector<int> result;
        if (nS < nW) return result;
        vector<double> values(nS - nW + 1);
        string word(S.begin(), S.begin() + nW);
        values[0] = hash(f, code, word);

        // Use a moving window to hash every word with length nW in S to a float number, 
        // which is stored in vector values[]
        // The complexity of this step is O(nS).
        for (int i = 1; i <= nS - nW; ++i) values[i] = (values[i - 1] - code[S[i - 1]] * fn)*f + code[S[i + nW - 1]];

        // This for loop will run nW times, each iteration has a complexity O(nS/nW)
        // So the overall complexity is O(nW * (nS / nW)) = O(nS)
        for (int i = 0; i < nW; ++i) {
            int j0 = i, j1 = i, k = 0;
            double sum = 0.;

            // Use a moving window to hash every L.size() continuous words with length nW in S.
            // This while loop will terminate within nS/nW iterations since the increasement of j1 is nW,
            // So the complexity of this while loop is O(nS / nW).
            while (j1 <= nS - nW) {
                sum += log(values[j1]);
                ++k;
                j1 += nW;
                if (k == nL) {
                    int key1 = (sum - floor(sum)) * unit;
                    if (key1 == key) result.push_back(j0);
                    sum -= log(values[j0]);
                    --k;
                    j0 += nW;
                }
            }
        }
        return result;
    }
};
#endif