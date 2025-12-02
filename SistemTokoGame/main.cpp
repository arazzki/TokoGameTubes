#include <iostream>
using namespace std;

#include "GAME.h"
#include "USER.h"
#include "RELASI.h"

void pause() {
    cout << "\nTekan ENTER...";
    cin.get();
}

void menu() {
    cout << "\n=== MENU ===\n";
    cout << "1. Tambah Game\n";
    cout << "2. Tambah User\n";
    cout << "3. Purchase Game\n";
    cout << "4. Tampilkan Game\n";
    cout << "5. Tampilkan User\n";
    cout << "6. Tampilkan Purchase\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

int main() {
    ListGame LG;
    ListUser LU;
    ListRelasi LR;

    createListGame(LG);
    createListUser(LU);
    createListRelasi(LR);

    int pilih = -1;

    while (pilih != 0) {

        menu();
        cin >> pilih;

        if (pilih == 1) {
            Game g;
            cout << "ID Game: ";
            cin >> g.idGame;
            cout << "Title: ";
            cin >> g.title;
            cout << "Genre: ";
            cin >> g.genre;
            cout << "Harga: ";
            cin >> g.price;

            insertLastGame(LG, newGame(g));
            cout << "Game ditambahkan.\n";
            pause();
            cin.get();
        }

        else if (pilih == 2) {
            User u;
            cout << "ID User: ";
            cin >> u.idUser;
            cout << "Username: ";
            cin >> u.username;
            cout << "Email: ";
            cin >> u.email;
            cout << "Level: ";
            cin >> u.level;

            insertLastUser(LU, newUser(u));
            cout << "User ditambahkan.\n";
            pause();
            cin.get();
        }

        else if (pilih == 3) {
            string gid, uid;
            cout << "ID Game: ";
            cin >> gid;
            cout << "ID User: ";
            cin >> uid;

            adrGame G = findGame(LG, gid);
            adrUser U = findUser(LU, uid);

            if (G != NULL && U != NULL) {
                Purchase p;
                cout << "Tanggal (YYYYMMDD): ";
                cin >> p.date;
                cout << "Playtime: ";
                cin >> p.playtime;

                insertLastRelasi(LR, newRelasi(p, G, U));
                cout << "Purchase sukses.\n";
            } else {
                cout << "Game/User tidak ditemukan.\n";
            }

            pause();
            cin.get();
        }

        else if (pilih == 4) {
            showAllGames(LG);
            pause();
            cin.get();
        }

        else if (pilih == 5) {
            showAllUsers(LU);
            pause();
            cin.get();
        }

        else if (pilih == 6) {
            showRelations(LR);
            pause();
            cin.get();
        }
    }

    cout << "Selesai.\n";
    return 0;
}
