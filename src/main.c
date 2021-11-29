#include <stdio.h>
#include <string.h>
#include "adt.h"
#include "banner.h"
#include "console.h"


int main(){
    PrintBanner();
    printf("\n\n========== MAIN MENU ===========\n");
    printf("1. New Game\n");
    printf("2. Exit\n");
    printf("Masukkan pilihan : ");
    int pilihan;
    scanf("%d", &pilihan);
    boolean valid = false;
    while (!valid){
        if (pilihan == 1){
            valid = true;
            StartGame();  
        }else if (pilihan == 2){
            valid = true;
            exit(0);
        }else{
            printf("Pilihan angka tidak valid\n");
            printf("Masukkan kembali angka 1 atau 2 sesuai pilihan dari main menu : ");
            scanf("%d", &pilihan);
        }
    }
}