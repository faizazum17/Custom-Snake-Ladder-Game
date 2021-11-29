#include <stdio.h>
#include <unistd.h>
#include "console.h"
#include "./ADT/Map/map.h"
#include "./ADT/Player/player.h"
#include "boolean.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/Command/command.h"

void StartGame(){
    Map map;
    Player P;
    boolean menang = false;
    ConfigureMap(&map);
    int jumlahorang;
    int giliran;
    printRD();
    printf("\n");
    printf("********* GAME START *********\n");
    printf("Konfigurasi jumlah player dulu!\n");
    printf ("Masukkan jumlah yang ingin bermain: ");
    scanf("%d", &jumlahorang);
    printf("\n");
    boolean valid = false;
    while (!valid){
        if (jumlahorang > 4 || jumlahorang <= 1){
            printf("Jumlah orang tidak valid. Hanya boleh terdapat 2 sampai 4 pemain.\n");
            printf("Masukkan kembali jumlah yang ingin bermain: ");
            scanf("%d", &jumlahorang);
        }else{
            valid = true;
        }
    }
    InputPlayer(&P, jumlahorang);
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("^^^^^^^^^^ SELAMAT BERMAIN ^^^^^^^^^^\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
    int n = 0;
    Stack histori;
    CreateEmptyStack(&histori);
    int nomorPemain;
    while (!menang){
        giliran = 1;
        while(giliran <= jumlahorang && (!menang)){
            if (giliran == 1){
                n++;
                Push(&histori, P);
                printf ("\n######################################\n");
                printf ("\n               RONDE-%d", n);
            }
            printf("\n========== POSISI SAAT INI ==========\n");
            for (nomorPemain = 1; nomorPemain <= jumlah(P); nomorPemain++){
                printf("%s  : ", (P).TabPlayer[nomorPemain].pName);
                for (int i=1; i <= Length(map); i++){
                    if (i != (P).TabPlayer[nomorPemain].position){
                        printf("%c", (map).Config.TI[i]);
                    }else{
                        printf("%c", '*');
                    }
                }
                printf("  %d\n", (P).TabPlayer[nomorPemain].position);
            }
            printf("====================================\n\n");
            printf("\n>>>>>>>>>>>> [Giliran  ");
            showName(&P, giliran);
            printf("] <<<<<<<<<<<<\n");
            showName(&P, giliran);
            printf (" mendapatkan skill ");
            getSkill(&((P).TabPlayer[giliran].skills));
            command(&map, &P, &giliran, &n, &histori);
            if ((P).TabPlayer[giliran].position == Length(map)){
                menang = true;
            }
            giliran++;
        }
        int nomorPem;
        for (nomorPem = 1; nomorPem <= jumlah(P); nomorPem++){
            (P).TabPlayer[nomorPem].isRolled = false;
            (P).TabPlayer[nomorPem].TabBuff[nomorPem].isSenterPembesar = false;
            (P).TabPlayer[nomorPem].TabBuff[nomorPem].isSenterPengecil = false;
            (P).TabPlayer[nomorPem].TabBuff[nomorPem].isCerminGanda = false;
            (P).TabPlayer[nomorPem].TabBuff[nomorPem].isImmuned = false;
        }
    }
    printf("\n**GAME TELAH SELESAI**\n");
    printf("Selamat kepada ");
    for(int p = 1; p <= jumlah(P); p++){
        if ((P).TabPlayer[p].position == Length(map)){
            showName(&P, p);
        }
    }
    printf(" telah memenangkan permainan kali ini.");
    printf("\n======== PERINGKAT ========\n");
    showPeringkat(P);
    printf("===========================\n");
}

void printLoading(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "Loading";

    for (int i= 0; i < 2; i++) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
    }
    printf("\n");
}

void printRD(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "Sedang membaca konfigurasi";

    for (int i= 0; i < 4; i++) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
    }
    printf("\n");
}



