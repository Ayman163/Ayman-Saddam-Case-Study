#include "ScoreManager.h"

ScoreManager::ScoreManager()
    : score(0)
{
}

void ScoreManager::addPoints(int points)
{
    score += points;
}

void ScoreManager::addPoints(int points, int multiplier)
{
    score += points * multiplier;
}

int ScoreManager::getScore() const
{
    return score;
}

void ScoreManager::resetScore()
{
    score = 0;
}
