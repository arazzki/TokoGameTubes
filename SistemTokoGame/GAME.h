#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
using namespace std;

struct Game {
    string idGame;
    string title;
    string genre;
    int price;
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
adrGame newGame(Game x);
void insertLastGame(ListGame &LG, adrGame G);
adrGame findGame(ListGame LG, string idGame);
void deleteGame(ListGame &LG, struct ListRelasi &LR, string idGame);
void showAllGames(ListGame LG);

#endif
