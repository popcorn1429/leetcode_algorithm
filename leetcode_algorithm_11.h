#ifndef _leetcode_algorithm_11_h_
#define _leetcode_algorithm_11_h_

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
inline const T& getMin(const T& l, const T& r) {
    return l < r ? l : r;
}

//最初的思路：先算最宽的（height[0]与 height[n-1]组成的矩形
//         然后宽度减一，计算 height[0]与height[n-2]的矩形，和 height[1]与height[n-1]的矩形
//         然后宽度再减一，计算三个矩形的面积
//         以此类推。
//         这需要两层循环，首先是循环宽度width，里面需要循环每一个同样宽度的各个矩形[0]&[width],[1]&[width+1],...,[n-width-1]&[n-1]
//         
//这个思路很容易理解但是效率不行，答案虽然正确但是不能通过执行时间限制，被拒绝
int maxArea_m1(vector<int>& height) {
    const auto n = height.size();
    if (n <= 1)
        return 0;

    int  max_area = 0;
    
    int  cur_width = n - 1;
    int  last_max_height = 0;

    //宽度从最大（n-1）逐渐变小，每层循环内，宽度不变，找最大高度
    while (cur_width > 0) {
        vector<int>::size_type start_pos = 0;
        decltype(start_pos) end_pos = n - cur_width;
        int max_height = 0;
        //保持当前宽度，找最大高度
        for (; start_pos < end_pos; ++start_pos) {
            const auto& cur_height = getMin(height[start_pos], height[start_pos + cur_width]);
            if (cur_height > max_height)
                max_height = cur_height;
        }

        //由于宽度是在逐渐减小的（while层），所以当前的最大高度必须比上次循环的最大高度更大才有必要计算面积
        if (last_max_height < max_height) {
            last_max_height = max_height;
            int cur_area = max_height * cur_width;
            if (cur_area > max_area)
                max_area = cur_area;
        }

        //下次，宽度变小
        --cur_width;
    }
    return max_area;
}

//第二个思路：任一个位置i的高度height[i]，如果它是矩形的高，意味着另一个高度必须大于等于它
//          现在我们在整个vector里面找另外一个高height[j],要求就是height[j] >= height[i]
//          显然这个j跟i间的距离越大越好，因为高度是height[i]不变了，面积就靠宽度来提升了。
//          所以选定一个i之后，就从离i最远的位置开始找满足条件的j，一旦找到就计算一下面积。然后不再找j，而是修改i开始下一次的循环
//
//这个思路也蛮容易理解的，但是代码写出来挺不好看，没有这段说明我自己都看不懂了。
//效率满足了题目的要求通过了。
//但是提交之后发现，跟主流解法的效率相比弱爆了。
int maxArea_m2(vector<int>& height) {
    auto n = height.size();
    if (n < 2)
        return 0;
    
    int max_area = 0;
    int max_height = 0;
    int max_width = 0;

    for (auto i = 0; i < n; ++i) {
        auto ii = i << 1;
        
        if (ii < (n - 1)) {
            bool found = false;
            for (auto j = n - 1; j > ii; --j) {
                if (height[j] >= height[i]) {
                    found = true;

                    if (max_height < height[i] || max_width < (j - i)) {
                        auto area = (j - i)*height[i];
                        if (area > max_area)
                            max_area = area;
                    }

                    break;
                }
            }

            if (!found) {
                for (auto j = i; j > 0; --j) {
                    if (height[i + j] >= height[i] || height[i - j] >= height[i]) {
                        //found = true;
                        if (max_height < height[i] || max_width < j) {
                            auto area = j*height[i];
                            if (area > max_area)
                                max_area = area;
                        }

                        break;
                    }
                }
            }
        }
        else {
            bool found = false;
            for (auto j = 0; j < ii - n + 1; ++j) {
                if (height[j] >= height[i]) {
                    found = true;
                    if (max_height < height[i] || max_width < (i - j)) {
                        auto area = height[i] * (i - j);
                        if (area > max_area)
                            max_area = area;
                    }
                    
                    break;
                }
            }

            if (!found) {
                for (auto j = n - i - 1; j > 0; --j) {
                    if (height[i + j] >= height[i] || height[i - j] >= height[i]) {
                        if (max_height < height[i] || max_width < j) {
                            auto area = height[i] * j;
                            if (area > max_area)
                                max_area = area;
                        }

                        break;
                    }
                }
            }
        }
    }
    return max_area;
}

//最后一个解法，也就是别人写出来的高效率实现
//           思路是，宽度先取最大值，两个高height[0]和 height[n-1]
//           较短的高向中间靠拢，不断计算面积
//           最终两个高相邻，然后结束。
//           宽在逐渐缩小，高在慢慢变大。
int maxArea_m3(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;

    int max_area = 0;
    int last_height = 0;
    while (l < r) {
        if (height[l] < height[r]) {
            if (last_height < height[l]) {
                auto area = height[l] * (r - l);
                if (area > max_area)
                    max_area = area;

                last_height = height[l];
            }

            ++l;
        }
        else {
            if (last_height < height[r]) {
                auto area = height[r] * (r - l);
                if (area > max_area)
                    max_area = area;

                last_height = height[r];
            }

            --r;
        }
    }

    return max_area;
}

#endif /*_leetcode_algorithm_11_h_*/
