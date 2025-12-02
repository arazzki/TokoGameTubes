#include "MLL.h"

/* =========================
   INITIALIZATION FUNCTIONS
   ========================= */

void createListGame(ListGame &LG) {
    LG.first = NULL;
}

void createListUser(ListUser &LU) {
    LU.first = NULL;
}

void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}

/* =========================
      ALLOCATION / NEW NODE
   ========================= */

adrGame newGame(Game x) {
    adrGame G = new elmGame;
    G->info = x;
    G->next = NULL;
    return G;
}

adrUser newUser(User x) {
    adrUser U = new elmUser;
    U->info = x;
    U->next = NULL;
    return U;
}

adrRelasi newRelasi(Purchase x, adrGame G, adrUser U) {
    adrRelasi R = new elmRelasi;
    R->info = x;
    R->game = G;
    R->user = U;
    R->next = NULL;
    return R;
}

/* =========================
          INSERT LAST
   ========================= */

void insertLastGame(ListGame &LG, adrGame G) {
    if (LG.first == NULL) {
        LG.first = G;
    } else {
        adrGame p = LG.first;
        while (p->next != NULL) p = p->next;
        p->next = G;
    }
}

void insertLastUser(ListUser &LU, adrUser U) {
    if (LU.first == NULL) {
        LU.first = U;
    } else {
        adrUser p = LU.first;
        while (p->next != NULL) p = p->next;
        p->next = U;
    }
}

void insertLastRelasi(ListRelasi &LR, adrRelasi R) {
    if (LR.first == NULL) {
        LR.first = R;
    } else {
        adrRelasi p = LR.first;
        while (p->next != NULL) p = p->next;
        p->next = R;
    }
}

/* =========================
          FIND FUNCTIONS
   ========================= */

adrGame findGame(ListGame LG, string idGame) {
    adrGame p = LG.first;
    while (p != NULL) {
        if (p->info.idGame == idGame) return p;
        p = p->next;
    }
    return NULL;
}

adrUser findUser(ListUser LU, string idUser) {
    adrUser p = LU.first;
    while (p != NULL) {
        if (p->info.idUser == idUser) return p;
        p = p->next;
    }
    return NULL;
}

adrRelasi findRelation(ListRelasi LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first;
    while (p != NULL) {
        if (p->game == G && p->user == U) return p;
        p = p->next;
    }
    return NULL;
}

/* =========================
          DELETE FUNCTIONS
   ========================= */

/* Delete a specific relation (by pointers to game & user) */
void deleteRelation(ListRelasi &LR, adrGame G, adrUser U) {
    adrRelasi p = LR.first;
    adrRelasi prev = NULL;

    while (p != NULL && !(p->game == G && p->user == U)) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        if (prev == NULL) LR.first = p->next;
        else prev->next = p->next;
        delete p;
    }
}

/* Delete game and all relations that reference it */
void deleteGame(ListGame &LG, ListRelasi &LR, string idGame) {
    adrGame p = LG.first;
    adrGame prev = NULL;

    while (p != NULL && p->info.idGame != idGame) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        // Remove relations referencing this game
        adrRelasi r = LR.first;
        adrRelasi rprev = NULL;
        while (r != NULL) {
            if (r->game == p) {
                adrRelasi todel = r;
                if (rprev == NULL) {
                    LR.first = r->next;
                    r = LR.first;
                } else {
                    rprev->next = r->next;
                    r = rprev->next;
                }
                delete todel;
            } else {
                rprev = r;
                r = r->next;
            }
        }

        // Remove game node from list
        if (prev == NULL) LG.first = p->next;
        else prev->next = p->next;
        delete p;
    }
}

/* Delete user and all relations that reference it */
void deleteUser(ListUser &LU, ListRelasi &LR, string idUser) {
    adrUser p = LU.first;
    adrUser prev = NULL;

    while (p != NULL && p->info.idUser != idUser) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        // Remove relations referencing this user
        adrRelasi r = LR.first;
        adrRelasi rprev = NULL;
        while (r != NULL) {
            if (r->user == p) {
                adrRelasi todel = r;
                if (rprev == NULL) {
                    LR.first = r->next;
                    r = LR.first;
                } else {
                    rprev->next = r->next;
                    r = rprev->next;
                }
                delete todel;
            } else {
                rprev = r;
                r = r->next;
            }
        }

        // Remove user node from list
        if (prev == NULL) LU.first = p->next;
        else prev->next = p->next;
        delete p;
    }
}

/* =========================
          SHOW FUNCTIONS
   ========================= */

void showAllGames(ListGame LG) {
    cout << "=== List of Games ===\n";
    adrGame p = LG.first;
    if (p == NULL) {
        cout << "(no games)\n";
        return;
    }
    while (p != NULL) {
        cout << p->info.idGame << " | " << p->info.title
             << " | " << p->info.genre << " | $" << p->info.price << "\n";
        p = p->next;
    }
}

void showAllUsers(ListUser LU) {
    cout << "=== List of Users ===\n";
    adrUser p = LU.first;
    if (p == NULL) {
        cout << "(no users)\n";
        return;
    }
    while (p != NULL) {
        cout << p->info.idUser << " | " << p->info.username
             << " | " << p->info.email << " | level " << p->info.level << "\n";
        p = p->next;
    }
}

void showRelations(ListRelasi LR) {
    cout << "=== List of Purchases (Relations) ===\n";
    adrRelasi p = LR.first;
    if (p == NULL) {
        cout << "(no purchases)\n";
        return;
    }
    while (p != NULL) {
        string gtitle = (p->game ? p->game->info.title : "(deleted game)");
        string uname = (p->user ? p->user->info.username : "(deleted user)");
        cout << "Game: " << gtitle << " <-> User: " << uname
             << " | Date: " << p->info.date << " | Playtime: " << p->info.playtime << " hrs\n";
        p = p->next;
    }
}

void showUsersOfGame(ListRelasi LR, adrGame G) {
    if (G == NULL) {
        cout << "Game is NULL\n";
        return;
    }
    cout << "Buyers of " << G->info.title << ":\n";
    adrRelasi p = LR.first;
    bool found = false;
    while (p != NULL) {
        if (p->game == G) {
            cout << "- " << p->user->info.username << " (Date: " << p->info.date << ", "
                 << p->info.playtime << " hrs)\n";
            found = true;
        }
        p = p->next;
    }
    if (!found) cout << "(no buyers)\n";
}

void showGamesOfUser(ListRelasi LR, adrUser U) {
    if (U == NULL) {
        cout << "User is NULL\n";
        return;
    }
    cout << "Games owned by " << U->info.username << ":\n";
    adrRelasi p = LR.first;
    bool found = false;
    while (p != NULL) {
        if (p->user == U) {
            cout << "- " << p->game->info.title << " (Date: " << p->info.date << ", "
                 << p->info.playtime << " hrs)\n";
            found = true;
        }
        p = p->next;
    }
    if (!found) cout << "(no games)\n";
}

/* =========================
         COUNT FUNCTIONS
   ========================= */

int countUsersOfGame(ListRelasi LR, adrGame G) {
    int c = 0;
    adrRelasi p = LR.first;
    while (p != NULL) {
        if (p->game == G) c++;
        p = p->next;
    }
    return c;
}

int countGamesOfUser(ListRelasi LR, adrUser U) {
    int c = 0;
    adrRelasi p = LR.first;
    while (p != NULL) {
        if (p->user == U) c++;
        p = p->next;
    }
    return c;
}

int countGameWithoutUser(ListGame LG, ListRelasi &LR) {
    int c = 0;
    adrGame g = LG.first;
    while (g != NULL) {
        if (countUsersOfGame(LR, g) == 0) c++;
        g = g->next;
    }
    return c;
}

int countUserWithoutGame(ListUser LU, ListRelasi &LR) {
    int c = 0;
    adrUser u = LU.first;
    while (u != NULL) {
        if (countGamesOfUser(LR, u) == 0) c++;
        u = u->next;
    }
    return c;
}

/* =========================
        EDIT RELATION
   ========================= */

void editRelation(ListRelasi &LR, adrGame oldG, adrUser oldU, adrGame newG, adrUser newU) {
    adrRelasi p = LR.first;
    while (p != NULL) {
        if (p->game == oldG && p->user == oldU) {
            p->game = newG;
            p->user = newU;
            return; // edit first matching relation
        }
        p = p->next;
    }
}
