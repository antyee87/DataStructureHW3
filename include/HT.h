#pragma once
#include "HomeworkRequirement.h"
#include <unordered_map>

class HT : public HomeworkRequirement
{
public:
    HT() = default;
    void insert(int id, int score) override;
    double search_average(int id) override;

private:
    std::unordered_map<int, StudentProfile> ht;
};