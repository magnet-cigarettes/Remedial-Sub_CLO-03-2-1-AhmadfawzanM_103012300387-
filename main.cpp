#include <iostream>
#include "header.h"

using namespace std;

int main() {
    Stack S_Aksi, S_Redo;
    create_stack(S_Aksi);
    create_stack(S_Redo);

    cout << "--- Simulasi Game Pertarungan ---" << endl;

    
    cout << "Pemain melakukan: ATTACK, ATTACK, DEFENSE" << endl;
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "DEFENSE");

    cout << "Pemain menekan: UNDO" << endl;
    manageAction(S_Aksi, S_Redo, "UNDO"); 

    cout << "Pemain menekan: REDO" << endl;
    manageAction(S_Aksi, S_Redo, "REDO"); 

    cout << "Pemain melakukan: ATTACK" << endl;
    manageAction(S_Aksi, S_Redo, "ATTACK");

    cout << "\nMenghitung Total Damage..." << endl;
    int damage = totalDamage(S_Aksi); 

    cout << "Total Damage yang dihasilkan: " << damage << endl;
    cout << "Status Stack Aksi sekarang kosong: " << (is_Empty(S_Aksi) ? "Ya" : "Tidak") << endl;

    return 0;

}
