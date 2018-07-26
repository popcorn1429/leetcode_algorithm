/*
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*/
#ifndef _leetcode_algorithm_71_h_
#define _leetcode_algorithm_71_h_
#include "basic_headers.h"

class Solution {
public:
    string simplifyPath(string path) {
        //it's like a stack, so i code it as a stack (by vector)
        vector<string> folders;

        int len = path.size();
        const char* p = path.data();
        int cur = 0;
        int start = 0;
        int end = 0;
        while (cur < len) {
            getNextFolder(p, len, cur, start, end);
            //deal current folder p[start, end)
            updateFolders(folders, p, start, end);
            cur = end;
        }

        return generatePath(folders);
    }

    void getNextFolder(const char* p, int len, int cur, int& start, int& end) {
        //p[cur] == '/'
        while (cur < len && p[cur] == '/')
            ++cur;
        start = cur;

        while (cur < len && p[cur] != '/')
            ++cur;
        end = cur;
    }

    void updateFolders(vector<string>& folders, const char* p, int start, int end) {
        if (end - start <= 0)
            return;

        if (end - start == 1 && p[start] == '.')
            return; //. means current dir, nothing changed.

        if (end - start == 2 && p[start] == '.' && p[start + 1] == '.') {
            //.. means upper dir
            if (folders.size() > 0)
                folders.pop_back();

            return;
        }

        //common
        folders.push_back(string(p + start, end - start));
        return;
    }

    string generatePath(const vector<string>& folders) {
        if (folders.empty())
            return "/";

        string newPathName;
        for (const string& folder : folders) {
            newPathName += '/';
            newPathName.append(folder);
        }
        return newPathName;
    }
};

#endif /*_leetcode_algorithm_71_h_*/