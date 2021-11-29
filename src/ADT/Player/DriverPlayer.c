#include "player.h"
#include <stdio.h>
/* Compile : gcc player.c driverplayer.c listlinier.c skill.c -o driverplayer*/

int main(){
    Player P;
    
    CreatePlayerEmpty(&P);
    printf("Memasukkan tiga nama pemain\n");
    InputPlayer(&P, 3);
    printf("Nama dari player kedua: ");
    showName(&P, 2);
    printf("\n");
    printf("\n");
    printf("Peringkat:\n");
    showPeringkat(P);
}