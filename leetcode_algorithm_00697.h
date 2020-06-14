#pragma once
#include "basic_headers.h"

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> poses;
        poses.insert(0);

        int max_du = 1;
        vector<int> du(nums.size(), 1);
        vector<int> dis(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[j] == nums[i]) {
                    du[i] = du[j] + 1;
                    dis[i] = dis[j] + (i - j);

                    if (du[i] > max_du) {
                        max_du = du[i];
                        poses.clear();
                        poses.insert(i);
                    }
                    else if (du[i] == max_du) {
                        poses.insert(i);
                    }

                    break;
                }
            }
        }

        int min_dis = nums.size();
        for (set<int>::iterator itr = poses.begin(); itr != poses.end(); ++itr) {
            if (dis[*itr] < min_dis) min_dis = dis[*itr];
        }

        return min_dis;
    }
};