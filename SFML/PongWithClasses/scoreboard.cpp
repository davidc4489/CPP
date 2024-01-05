#include "scoreboard.hpp"

Scoreboard::Scoreboard()
: scorePlayer1(0),
  scorePlayer2(0)
{};

void Scoreboard::increaseScorePlayer1(){
    scorePlayer1++;
}

void Scoreboard::increaseScorePlayer2(){
    scorePlayer2++;
}

void Scoreboard::resetScores(){
    scorePlayer1 = 0;
    scorePlayer2 = 0;
}

int Scoreboard::getScorePlayer1(){
    return scorePlayer1;
}

int Scoreboard::getScorePlayer2(){
    return scorePlayer2;
}

