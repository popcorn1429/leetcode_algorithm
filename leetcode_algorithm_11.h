#ifndef _leetcode_algorithm_11_h_
#define _leetcode_algorithm_11_h_

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
inline const T& getMin(const T& l, const T& r) {
    return l < r ? l : r;
}

//�����˼·���������ģ�height[0]�� height[n-1]��ɵľ���
//         Ȼ���ȼ�һ������ height[0]��height[n-2]�ľ��Σ��� height[1]��height[n-1]�ľ���
//         Ȼ�����ټ�һ�������������ε����
//         �Դ����ơ�
//         ����Ҫ����ѭ����������ѭ�����width��������Ҫѭ��ÿһ��ͬ����ȵĸ�������[0]&[width],[1]&[width+1],...,[n-width-1]&[n-1]
//         
//���˼·��������⵫��Ч�ʲ��У�����Ȼ��ȷ���ǲ���ͨ��ִ��ʱ�����ƣ����ܾ�
int maxArea_m1(vector<int>& height) {
    const auto n = height.size();
    if (n <= 1)
        return 0;

    int  max_area = 0;
    
    int  cur_width = n - 1;
    int  last_max_height = 0;

    //��ȴ����n-1���𽥱�С��ÿ��ѭ���ڣ���Ȳ��䣬�����߶�
    while (cur_width > 0) {
        vector<int>::size_type start_pos = 0;
        decltype(start_pos) end_pos = n - cur_width;
        int max_height = 0;
        //���ֵ�ǰ��ȣ������߶�
        for (; start_pos < end_pos; ++start_pos) {
            const auto& cur_height = getMin(height[start_pos], height[start_pos + cur_width]);
            if (cur_height > max_height)
                max_height = cur_height;
        }

        //���ڿ�������𽥼�С�ģ�while�㣩�����Ե�ǰ�����߶ȱ�����ϴ�ѭ�������߶ȸ�����б�Ҫ�������
        if (last_max_height < max_height) {
            last_max_height = max_height;
            int cur_area = max_height * cur_width;
            if (cur_area > max_area)
                max_area = cur_area;
        }

        //�´Σ���ȱ�С
        --cur_width;
    }
    return max_area;
}

//�ڶ���˼·����һ��λ��i�ĸ߶�height[i]��������Ǿ��εĸߣ���ζ����һ���߶ȱ�����ڵ�����
//          ��������������vector����������һ����height[j],Ҫ�����height[j] >= height[i]
//          ��Ȼ���j��i��ľ���Խ��Խ�ã���Ϊ�߶���height[i]�����ˣ�����Ϳ�����������ˡ�
//          ����ѡ��һ��i֮�󣬾ʹ���i��Զ��λ�ÿ�ʼ������������j��һ���ҵ��ͼ���һ�������Ȼ������j�������޸�i��ʼ��һ�ε�ѭ��
//
//���˼·Ҳ���������ģ����Ǵ���д����ͦ���ÿ���û�����˵�����Լ����������ˡ�
//Ч����������Ŀ��Ҫ��ͨ���ˡ�
//�����ύ֮���֣��������ⷨ��Ч����������ˡ�
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

//���һ���ⷨ��Ҳ���Ǳ���д�����ĸ�Ч��ʵ��
//           ˼·�ǣ������ȡ���ֵ��������height[0]�� height[n-1]
//           �϶̵ĸ����м俿£�����ϼ������
//           �������������ڣ�Ȼ�������
//           ��������С�������������
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
