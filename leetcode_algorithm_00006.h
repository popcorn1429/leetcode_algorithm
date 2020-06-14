#ifndef _leetcode_algorithm_00006_h_
#define _leetcode_algorithm_00006_h_

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows)
            return s;
        
        if (numRows == 1)
            return s;

        int group_size = 2 * numRows - 2;
        auto total_size = s.size();
        string answer;
        for (int i = 0; i < numRows; ++i) {
            if (i < total_size) {
                answer += s[i];
                int j = 1;
                while (true) {
                    int first_pos = group_size*j - i;
                    int second_pos = first_pos + 2 * i;
                    if (first_pos < total_size) {
                        if (i != numRows - 1)
                            answer += s[first_pos];
                    }
                    else
                        break;

                    if (second_pos < total_size) {
                        if (i != 0)
                            answer += s[second_pos];
                    }
                    else
                        break;

                    ++j;
                }
            }
        }
        return answer;
    }
};

#endif /*_leetcode_algorithm_00006_h_*/
