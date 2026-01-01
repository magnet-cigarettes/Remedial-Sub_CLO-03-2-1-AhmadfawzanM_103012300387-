#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

const int N_STACK = 2025; 
typedef string infotypeStack;

struct Stack {
    infotypeStack info[N_STACK]; 
    int top; 
};

void create_stack(Stack &S);
bool is_Empty(Stack S);
bool is_full(Stack S);
void push(Stack &S, infotypeStack x);
infotypeStack pop(Stack &S);
void manageAction(Stack &S_Aksi, Stack &S_Redo, infotypeStack aksi);
int totalDamage(Stack &S);

#endif // HEADER_H_INCLUDED
