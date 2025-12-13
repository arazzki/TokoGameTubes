#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Game {
    string idGame;
    string title;
    string genre;
    float price;
};

typedef struct elmGame *adrGame;

struct elmGame {
    Game info;
    adrGame next;
};

struct ListGame {
    adrGame first;
};

void createListGame(ListGame &LG);
adrGame newGame(const Game &x);
void insertLastGame(ListGame &LG, adrGame G);
adrGame findGame(ListGame LG, const string &idGame);
void deleteGame(ListGame &LG, struct ListRelasi &LR, const string &idGame); // forward to relasi
void deleteGameOnly(ListGame &LG, const string &idGame); // delete game node only (no cascade)
void showAllGames(ListGame LG);
int countGameNodes(ListGame LG);

#endif
