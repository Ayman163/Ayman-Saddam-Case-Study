#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

class ScoreManager
{
private:
    int score;

public:
    ScoreManager();

    void addPoints(int points);
    void addPoints(int points, int multiplier);

    int getScore() const;

    void resetScore();
};

#endif
