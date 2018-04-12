#ifndef __LINUX_LIKE_REGULAR_H__
#define __LINUX_LIKE_REGULAR_H__
#include <string>
#include <list>
using std::string;
using std::list;

struct Element{
    enum class ElementType {
        Unknown = -1,
        Any = 0,
        One = 1,
        Fixed = 2
    };

    ElementType type;
    string      expr;

    Element(ElementType t, const string& s) : type(t), expr(s) {}
};

size_t parseRegularExpr(const string& regular, list<Element>& elements) {

    size_t curMinPos = 0;
    size_t curElementBegin = 0;
    string curSegment;
    Element::ElementType curElementType = Element::ElementType::Unknown;
    for (size_t pos = 0; pos != regular.size(); ++pos) {
        if (regular[pos] == '*') {
            if (!curSegment.empty()) {
                if (curSegment == "*") {
                    continue;
                }
                else {
                    elements.push_back(Element(curElementType, curSegment));
                    curSegment = "*";
                    curElementType = Element::ElementType::Any;
                }
            }
            else {
                curSegment = "*";
                curElementType = Element::ElementType::Any;
            }
        }
        else if (regular[pos] == '.') {
            if (!curSegment.empty()) {
                elements.push_back(Element(curElementType, curSegment));
            }

            curSegment = ".";
            curElementType = Element::ElementType::One;
        }
        else {
            if (curElementType == Element::ElementType::One || curElementType == Element::ElementType::Any) {
                elements.push_back(Element(curElementType, curSegment));
                curSegment.clear();
            }
            curElementType = Element::ElementType::Fixed;
            curSegment.push_back(regular[pos]);
        }
    }

    elements.push_back(Element(curElementType, curSegment));
    return elements.size();
}
/*
param src is the flat string which need to be matched
param elements is the regular expr segments
param itr is an iterator on the elements, current position
param curRangeLeft is the begin position of src for matching
param strictly tell the position curRangeLeft is fixed or not
*/
bool match(const string& src, const list<Element>& elements, list<Element>::const_iterator itr, size_t curRangeLeft, bool strictly) {
    if (itr == elements.cend()) {
        if (curRangeLeft == src.size())
            return true;

        return !strictly;
    }

    switch (itr->type)
    {
    case Element::ElementType::Any:
        return match(src, elements, ++itr, curRangeLeft, false);
    case Element::ElementType::One:
        if (strictly) {
            return match(src, elements, ++itr, ++curRangeLeft, true);
        }
        else {
            auto nextItr = itr;
            ++nextItr;
            while (curRangeLeft != src.size()) {
                if (match(src, elements, nextItr, ++curRangeLeft, true))
                    return true;
            }
            return false;
        }
    case Element::ElementType::Fixed:
        if (strictly) {
            if (src.find(itr->expr, curRangeLeft) != curRangeLeft)
                return false;
            else {
                auto len = itr->expr.size();
                return match(src, elements, ++itr, curRangeLeft + len, true);
            }
        }
        else {
            auto pos = src.find(itr->expr, curRangeLeft);
            if (pos == string::npos)
                return false;
            else {
                auto len = itr->expr.size();
                auto nextItr = itr;
                ++nextItr;
                while (pos != string::npos) {
                    if (match(src, elements, nextItr, pos + len, true))
                        return true;

                    pos = src.find(itr->expr, pos + 1);
                }
                return false;
            }
        }
    default:
        return true;
        break;
    }
}

bool isMatch_Linux(string s, string p) {
    bool strictLength = (p.find('*') == string::npos);
    size_t minLength = 0;
    for (size_t i = 0; i != p.size(); ++i) {
        if (p[i] != '*')
            ++minLength;
    }

    if (s.size() < minLength || (strictLength && minLength != s.size()))
        return false;

    list<Element> elements;
    parseRegularExpr(p, elements);

    return match(s, elements, elements.cbegin(), 0, true);
}


#endif 