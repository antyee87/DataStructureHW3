#include "HT.h"

void HT::insert(int id, int score)
{
    ht.try_emplace(id, StudentProfile(id)).first->second.add_score(score);
}

double HT::search_average(int id)
{
    auto it = ht.find(id);
    if (it == ht.end())
        return -1;
    return it->second.get_scores_average();
}
