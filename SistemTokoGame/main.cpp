#include <iostream>
#include <string>
using namespace std;

#include "Game.h"
#include "User.h"
#include "Relasi.h"

// --- input validators ---
int inputIntValidated() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka (int). Masukkan lagi: ";
    }
    cin.ignore(1000, '\n'); // clear rest of line
    return x;
}

float inputFloatValidated() {
    float x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka (float). Masukkan lagi: ";
    }
    cin.ignore(1000, '\n');
    return x;
}

// simple string input (no spaces) using cin >> (fits coursework)
void menu() {
    cout << "\n=== Steam Store MLL Type B (Menu) ===\n";
    cout << "1. Insert Game\n";
    cout << "2. Insert User\n";
    cout << "3. Insert Purchase (relation)\n";
    cout << "4. Show All Games\n";
    cout << "5. Show All Users\n";
    cout << "6. Show All Purchases\n";
    cout << "7. Show buyers of a game\n";
    cout << "8. Show games of a user\n";
    cout << "9. Delete Game (cascade)\n";
    cout << "10. Delete User (cascade)\n";
    cout << "11. Delete Purchase\n";
    cout << "12. Count functions\n";
    cout << "13. Edit Purchase (change relation)\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

void countMenu() {
    cout << "\n--- Count Menu ---\n";
    cout << "1. Count users of a game\n";
    cout << "2. Count games of a user\n";
    cout << "3. Count games without buyers\n";
    cout << "4. Count users without games\n";
    cout << "0. Back\n";
    cout << "Choose: ";
}

int main() {
    ListGame LG; ListUser LU; ListRelasi LR;
    createListGame(LG); createListUser(LU); createListRelasi(LR);

    while (true) {
        menu();
        int choice = inputIntValidated();

        if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }

        if (choice == 1) {
            Game g;
            cout << "ID Game (no spaces): "; cin >> g.idGame;
            cout << "Title (no spaces): "; cin >> g.title;
            cout << "Genre (no spaces): "; cin >> g.genre;
            cout << "Price (float): "; g.price = inputFloatValidated();
            insertLastGame(LG, newGame(g));
            cout << "Game added.\n";
        }

        else if (choice == 2) {
            User u;
            cout << "ID User: "; cin >> u.idUser;
            cout << "Username: "; cin >> u.username;
            cout << "Email: "; cin >> u.email;
            cout << "Level (int): "; u.level = inputIntValidated();
            insertLastUser(LU, newUser(u));
            cout << "User added.\n";
        }

        else if (choice == 3) {
            string gid, uid;
            cout << "Game ID: "; cin >> gid;
            cout << "User ID: "; cin >> uid;
            adrGame G = findGame(LG, gid);
            adrUser U = findUser(LU, uid);
            if (G == nullptr || U == nullptr) {
                cout << "Game or User not found.\n";
            } else {
                if (findRelation(LR, G, U) != nullptr) {
                    cout << "Purchase already exists.\n";
                } else {
                    Purchase p;
                    cout << "Date (YYYYMMDD): "; cin >> p.date;
                    cout << "Playtime (int hours): "; p.playtime = inputIntValidated();
                    insertLastRelasi(LR, newRelasi(p, G, U));
                    cout << "Purchase added.\n";
                }
            }
        }

        else if (choice == 4) {
            showAllGames(LG);
        }

        else if (choice == 5) {
            showAllUsers(LU);
        }

        else if (choice == 6) {
            showRelations(LR);
        }

        else if (choice == 7) {
            string gid; cout << "Game ID: "; cin >> gid;
            adrGame G = findGame(LG, gid);
            if (G == nullptr) cout << "Game not found.\n";
            else showUsersOfGame(LR, G);
        }

        else if (choice == 8) {
            string uid; cout << "User ID: "; cin >> uid;
            adrUser U = findUser(LU, uid);
            if (U == nullptr) cout << "User not found.\n";
            else showGamesOfUser(LR, U);
        }

        else if (choice == 9) {
            string gid; cout << "Game ID to delete: "; cin >> gid;
            deleteGame(LG, LR, gid);
            cout << "Delete (if existed) done.\n";
        }

        else if (choice == 10) {
            string uid; cout << "User ID to delete: "; cin >> uid;
            deleteUser(LU, LR, uid);
            cout << "Delete (if existed) done.\n";
        }

        else if (choice == 11) {
            string gid, uid;
            cout << "Game ID: "; cin >> gid;
            cout << "User ID: "; cin >> uid;
            adrGame G = findGame(LG, gid);
            adrUser U = findUser(LU, uid);
            if (G == nullptr || U == nullptr) cout << "Game or user not found.\n";
            else {
                deleteRelation(LR, G, U);
                cout << "Delete purchase (if existed) done.\n";
            }
        }

        else if (choice == 12) {
            while (true) {
                countMenu();
                int c = inputIntValidated();
                if (c == 0) break;
                if (c == 1) {
                    string gid; cout << "Game ID: "; cin >> gid;
                    adrGame G = findGame(LG, gid);
                    if (G == nullptr) cout << "Game not found.\n";
                    else cout << "Buyers: " << countUsersOfGame(LR, G) << "\n";
                } else if (c == 2) {
                    string uid; cout << "User ID: "; cin >> uid;
                    adrUser U = findUser(LU, uid);
                    if (U == nullptr) cout << "User not found.\n";
                    else cout << "Games owned: " << countGamesOfUser(LR, U) << "\n";
                } else if (c == 3) {
                    cout << "Games without buyers: " << countGameWithoutUser(LG, LR) << "\n";
                } else if (c == 4) {
                    cout << "Users without games: " << countUserWithoutGame(LU, LR) << "\n";
                } else {
                    cout << "Invalid choice.\n";
                }
            }
        }

        else if (choice == 13) {
            string og, ou, ng, nu;
            cout << "Old Game ID: "; cin >> og;
            cout << "Old User ID: "; cin >> ou;
            adrGame oldG = findGame(LG, og);
            adrUser oldU = findUser(LU, ou);
            if (oldG == nullptr || oldU == nullptr) { cout << "Old pair not found.\n"; continue; }
            cout << "New Game ID: "; cin >> ng;
            cout << "New User ID: "; cin >> nu;
            adrGame newG = findGame(LG, ng);
            adrUser newU = findUser(LU, nu);
            if (newG == nullptr || newU == nullptr) { cout << "New pair not found.\n"; continue; }
            editRelation(LR, oldG, oldU, newG, newU);
            cout << "First matching relation edited (if existed).\n";
        }

        else {
            cout << "Invalid option.\n";
        }

    } // end main loop

    return 0;
}
