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

struct elmGame;
typedef elmGame* adrGame;

struct elmGame {
    Game info;
    adrGame next;
};

struct ListGame {
    adrGame first;
};

void createListGame(ListGame &LG);
adrGame newGame(Game x);
void insertLastGame(ListGame &LG, adrGame G);
adrGame findGame(ListGame LG, string idGame);
void deleteGameOnly(ListGame &LG, string idGame);
void showAllGames(ListGame LG);

#endif
