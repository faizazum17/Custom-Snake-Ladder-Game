#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    list L;
    //Membentuk list kosong
    CreateEmpty(&L);
    //
    int x = 1;
    InsVLast(&L, x);
    PrintInfo(&L);
    int x = 2
    InsVFirst(&L, x);
    PrintInfo(&L);
    int x = 3;
    InsVFirst(&L, x);
    PrintInfo(&L);
    DeleteI(&L, 2)
    PrintInfo(&L);

    if (NbElmt(*L) >= 2){
        printf("list penuh\n");
    }
}