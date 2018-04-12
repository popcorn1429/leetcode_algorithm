#ifndef __LEETCODE_LIKE_REGULAR_H__
#define __LEETCODE_LIKE_REGULAR_H__
#include <list>
#include <string>
using std::string;
using std::list;

struct RegularSegment {
    char   seg;
    bool   tensile;

    RegularSegment(char c, bool stretching = false) : seg(c), tensile(stretching) {}
    void setTensile() { tensile = true; }
    void setFixed() { tensile = false; }
    bool isTensile() const { return tensile; }
    char expr() const { return seg; }
};

size_t parseRegular(const string& regular, list<RegularSegment>& segs) {
    char curSeg = '\0';
    for(char c : regular) {
        if (c == '*') {
            if (curSeg == '\0') {
                throw "invalid regular expression!";
            }
            segs.push_back(RegularSegment(curSeg, true));
            curSeg = '\0';
        }
        else {
            if (curSeg != '\0') {
                segs.push_back(RegularSegment(curSeg));
            }
            curSeg = c;
        }
    }

    if (curSeg != '\0') {
        segs.push_back(RegularSegment(curSeg));
    }

    return segs.size();
}

bool charMatch(const char cSrc, const char cRegular) {
    if (cRegular == '.')
        return cSrc != '\0';
    else
        return cSrc == cRegular;
}

bool match(const string& src, size_t curPos, const list<RegularSegment>& segs, list<RegularSegment>::const_iterator curItr) {
    if (curItr == segs.cend()) {
        if (curPos == src.size())
            return true;

        return false;
    }

    if (curPos == src.size()) {
        if (curItr->isTensile())
            return match(src, curPos, segs, ++curItr);
        else
            return false;
    }

    auto nextPos = curPos;
    auto nextItr = curItr;
    
    if (!curItr->isTensile()) {
        //��ǰ��������ƥ��
        if (charMatch(src.at(curPos), curItr->expr())) {
            ++nextItr;
            return match(src, ++curPos, segs, nextItr);
        }
        else {
            return false;
        }
    }
    else {
        //��ǰ�̬ƥ�䣨����������ƥ�䣬ƥ��ʱ��������ƥ�䣩
        ++nextItr;
        if (match(src, curPos, segs, nextItr)) //��ǰ�ƥ�䣬ֱ��ƥ����һ��
            return true;
        else {
            //��ǰ�����ƥ�䣨����һ���ַ�����Ȼ��ƥ��������
            while ((nextPos < src.size())
                && charMatch(src.at(nextPos), curItr->expr())) {
                bool ret = match(src, nextPos + 1, segs, nextItr);
                if (ret)
                    return true;
                else
                    ++nextPos;
            }
            return false;
        }
    }
}

bool isMatch(string s, string p) {
    try {
        list<RegularSegment> segs;
        size_t cnt = parseRegular(p, segs);
        if (cnt == 0) {
            return s.empty();
        }

        return match(s, 0, segs, segs.cbegin());
    }
    catch (const char* msg) {
        return false;
    }
}

bool isMatch(const char* src, const char* pos) {
    if (*pos == '\0')
        return *src == '\0';

    if (*src == '\0') {
        if (*(pos + 1) == '*')
            return isMatch(src, pos + 2);
        else
            return false;
    }
     

    if (*pos == '*')
        return false;
    if (*pos != '\0') {
        if (*(pos + 1) == '*') {
            if (isMatch(src, pos + 2))
                return true;
            else {
                while (*src == *pos || (*pos == '.' && *src != '\0')) {
                    bool ret = isMatch(++src, pos + 2);
                    if (ret)
                        return true;
                }
                return false;
            }
        }
        else {
            if (*src == *pos || (*pos == '.' && *src != '\0')) {
                return isMatch(++src, ++pos);
            }
            else
                return false;
        }
    }
}

#endif