#ifndef _leetcode_algorithm_00068_h_
#define _leetcode_algorithm_00068_h_
#include "basic_headers.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        size_t start = 0;
        vector<string> result;
        while (start < words.size()) {
            result.push_back(string());
            start = lineEndWord(words, start, maxWidth, result.back());
        }
        return result;
    }

    size_t lineEndWord(const vector<string>& words, size_t start, int maxWidth, string& line) {
        int num = 0;
        size_t wordLength = 0;

        while (start + num < words.size()) {
            wordLength += words[start + num].size();
            if (wordLength > maxWidth - num) {
                wordLength -= words[start + num].size();
                --num;
                break;
            }
            ++num;
        }

        if (start + num >= words.size())
            --num;
       
        int blankNum = maxWidth - wordLength;
        if (num == 0) {
            //only one word 
            line.append(words[start]);
            line.append(blankNum, ' ');
        }
        else {
            //more than one word
            if (start + num == words.size() - 1) {
                //last line, special
                int pos = start;
                while (pos < words.size()) {
                    line.append(words[pos]);
                    if (line.size() < maxWidth)
                        line.append(1, ' ');
                    ++pos;
                }
                if (line.size() < maxWidth)
                    line.append(maxWidth - line.size(), ' ');
            }
            else {
                //common
                int gapWidth = blankNum / num;
                int remain = blankNum % num;
                int pos = start;
                while (pos < start + num) {
                    line.append(words[pos]);
                    line.append(gapWidth, ' ');
                    if (remain > 0) {
                        line.append(1, ' ');
                        --remain;
                    }
                    ++pos;
                }
                line.append(words[pos]);
            }
        }
        return start + num + 1;
    }
};

#endif /*_leetcode_algorithm_00068_h_*/
