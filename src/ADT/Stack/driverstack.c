#include "stack.h"
#include <stdio.h>
// compile: gcc driverstack.c stack.c player.c listlinier.c skill.c -o driverstack
int main(){
    Stack S;
    int n;
    
    CreateEmptyStack(&S);
    printf("Masukkan n: ");
    scanf("%d", &n);
    for (int i = 0; i<n; ++i){
        Player x;
        printf("Masukkan elemen: ");
        scanf("%d", &x);
        Push(&S, x);
    }
    printf("Elemen puncak: %d\n", Top(S));
    if(!IsEmptyStack(S)){
        Pop(&S, &InfoTop(S));
    }
    printf("Elemen puncak setelah Pop: %d\n", Top(S));
    if(!IsEmptyStack(S)){
        printf("Stack tidak kosong\n");
    }
    else{
        printf("Stack kosong\n");
    }
    if(!IsFullStack(S)){
        printf("Stack tidak penuh\n");
    }
    else{
        printf("Stack penuh\n");
    }
}