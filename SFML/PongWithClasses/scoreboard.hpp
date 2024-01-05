#pragma once

class Scoreboard {
private:
    int scorePlayer1;
    int scorePlayer2;

public:
    Scoreboard();
    void increaseScorePlayer1();
    void increaseScorePlayer2();
    void resetScores();
    int getScorePlayer1();
    int getScorePlayer2();
};