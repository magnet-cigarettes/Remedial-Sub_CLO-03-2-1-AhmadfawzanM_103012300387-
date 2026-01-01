#include <iostream>
#include <string>
#include "header.h"
using namespace std;


void create_stack(Stack &S) {
    S.top = -1; 
}

bool is_Empty(Stack S) {
    return S.top == -1; 
}

bool is_full(Stack S) {
    return S.top == N_STACK - 1; 
}

void push(Stack &S, infotypeStack x) {
    if (!is_full(S)) {
        S.top++;
        S.info[S.top] = x; 
    }
}

infotypeStack pop(Stack &S) {
   if (!is_Empty(S)) {
        infotypeStack x = S.info[S.top];
        S.top--; 
        return x;
    }
    return ""; 
}

void manageAction(Stack &S_Aksi, Stack &S_Redo, infotypeStack aksi) {
    if (aksi == "UNDO") {
        infotypeStack temp = pop(S_Aksi);
        if (temp != "") {
            push(S_Redo, temp); 
        }
    } else if (aksi == "REDO") {
        infotypeStack temp = pop(S_Redo); 
        if (temp != "") {
            push(S_Aksi, temp); 
        }
    } else {
        push(S_Aksi, aksi); 
        create_stack(S_Redo); 
    }
}

int totalDamage(Stack &S) {
    int total = 0;
    while (!is_Empty(S)) {
        infotypeStack aksi = pop(S); 
        if (aksi == "ATTACK") {
            total += 30; 
        } else if (aksi == "DEFENSE") {
            total += 5; 
        }
    }
    return total; 
}
