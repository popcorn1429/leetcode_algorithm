#pragma once
#include "basic_headers.h"

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importance = 0;

        Employee *self = getEmployee(employees, id);
        if (nullptr == self) return importance;
        
        importance += self->importance;

        for (int i = 0; i < self->subordinates.size(); ++i) {
            importance += getImportance(employees, self->subordinates[i]);
        }

        return importance;
    }

    Employee *getEmployee(vector<Employee *> &employees, int id) {
        for (int i = 0; i < employees.size(); ++i) {
            if (employees[i]->id == id) return employees[i];
        }
        return nullptr;
    }
};