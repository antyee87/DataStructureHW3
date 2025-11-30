#include "BST.h"

void BST::insert(int id, int score)
{
    bst.try_emplace(id, StudentProfile(id)).first->second.add_score(score);
}

double BST::search_average(int id)
{
    auto it = bst.find(id);
    if (it == bst.end())
        return -1;
    return it->second.get_scores_average();
}
