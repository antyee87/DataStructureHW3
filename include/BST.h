#pragma once
#include "HomeworkRequirement.h"
#include <map>

class BST : public HomeworkRequirement {
public:
    BST() = default;
    void insert(int id, int score) override;
    double search_average(int id) override;
private:
    std::map<int, StudentProfile> bst;
};