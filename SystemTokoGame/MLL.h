#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;



struct Game {
    string idGame;
    string title;
    string genre;
    float price;
};

struct User {
    string idUser;
    string username;
    string email;
    int level;
};

struct Purchase {
    string date;
    int playtime;
};

struct elmGame;
struct elmUser;
struct elmRelasi;

typedef elmGame* adrGame;
typedef elmUser* adrUser;
typedef elmRelasi* adrRelasi;

struct elmGame {
    Game info;
    adrGame next;
};

struct elmUser {
    User info;
    adrUser next;
};

struct elmRelasi {
    Purchase info;
    adrGame game;
    adrUser user;
    adrRelasi next;
};

struct ListGame { adrGame first; };
struct ListUser { adrUser first; };
struct ListRelasi { adrRelasi first; };



void createListGame(ListGame &LG);
void createListUser(ListUser &LU);
void createListRelasi(ListRelasi &LR);

adrGame newGame(Game x);
adrUser newUser(User x);
adrRelasi newRelasi(Purchase x, adrGame G, adrUser U);

void insertLastGame(ListGame &LG, adrGame G);
void insertLastUser(ListUser &LU, adrUser U);
void insertLastRelasi(ListRelasi &LR, adrRelasi R);

adrGame findGame(ListGame LG, string idGame);
adrUser findUser(ListUser LU, string idUser);
adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U);

void deleteGame(ListGame &LG, ListRelasi &LR, string idGame);
void deleteUser(ListUser &LU, ListRelasi &LR, string idUser);
void deleteRelation(ListRelasi &LR, adrGame G, adrUser U);

void showAllGames(ListGame LG);
void showAllUsers(ListUser LU);
void showRelations(ListRelasi LR);
void showUsersOfGame(ListRelasi LR, adrGame G);
void showGamesOfUser(ListRelasi LR, adrUser U);

int countUsersOfGame(ListRelasi LR, adrGame G);
int countGamesOfUser(ListRelasi LR, adrUser U);
int countGameWithoutUser(ListGame LG, ListRelasi LR);
int countUserWithoutGame(ListUser LU, ListRelasi LR);

void editRelation(ListRelasi &LR, adrGame oldG, adrUser oldU, adrGame newG, adrUser newU);

#endif
