#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../boolean.h"
#include "../ListLinier/listlinier.h"
#include "../Skill/skill.h"

void CreatePlayerEmpty(Player *P){
/* I.S. sembarang             */
/* F.S. Terbentuk list Player kosong */
    jumlah(*P) = 0;
}

void InputPlayer(Player *P, int banyakPlayer){
/* I.S. Array Player kosong             */
/* F.S. Array Player diisi oleh nama-nama pemain */
    int i = 1;
    int j;
    int salah;
    boolean valid;
    jumlah(*P) = banyakPlayer;
    printf("Menambah player!\n");
    for (i; i <= banyakPlayer; i++){
        valid = false;
        printf("Masukkan Nama Player-%d: ", i);
        scanf("%s", ((*P).TabPlayer[i].pName));
        while(!valid){
            salah = 0;
            for (j = 1; j <= banyakPlayer; j++) {
                if ((!strcmp((*P).TabPlayer[i].pName, (*P).TabPlayer[j].pName)) && (i != j)){
                    salah++;
                    printf("Nama %s sudah ada!\n", (*P).TabPlayer[i].pName);
                    printf("Ganti nama player-%d: ", i);
                    scanf("%s", ((*P).TabPlayer[i].pName));
                }
            }
            if (salah == 0){
                valid = true;
                printf("Player %s berhasil ditambahkan!\n\n", ((*P).TabPlayer[i].pName));
            }else{
                valid = false;
            }
        }
        (*P).TabPlayer[i].nomorPemain = i;
        (*P).TabPlayer[i].position = 1;
        (*P).TabPlayer[i].isRolled = false;
        (*P).TabPlayer[i].isTeleported = false;
        (*P).TabPlayer[i].TabBuff[i].isImmuned = false;
        (*P).TabPlayer[i].TabBuff[i].isSenterPembesar = false;
        (*P).TabPlayer[i].TabBuff[i].isSenterPengecil = false;
        (*P).TabPlayer[i].TabBuff[i].isCerminGanda = false;
        First((*P).TabPlayer[i].skills) = NilPlayer;
    }
}

void showName (Player *P, int nomorPemain){
/* I.S. Array Player tidak kosong             */
/* F.S. Mengembalikan nama pemain sesuai input nomornya pemain */
    printf("%s", (*P).TabPlayer[nomorPemain].pName);
}

void useSkill(Player *P, int inputs, int nomorPemain){
// I.S Array pada player tidak kosong
// F.S Element array pada player akan terhapus sesuai dengan input yang dimasukkan oleh player
// Pemain akan memberi masukkan untuk mimilih penggunaan skill, skill yang telah digunakan akan menghasilkan 
// buff yang akan dimasukkan ke array buff lalu pada array akan dihapus element skill yang telah digunakan .
    if (infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 1){
        if(!(*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isImmuned){
            printf("\n");
            showName(&(*P), nomorPemain);
            printf(" memakai skill ");
            ShowSkill(((*P).TabPlayer[nomorPemain].skills), inputs);
            ((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isImmuned) = true;
            DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
        }else{
            printf("Punten, gabisa make skill ini soalnya buff imunitas lagi aktif.");
        }
    }
    else if(infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 2){
        if(NbElmt((*P).TabPlayer[nomorPemain].skills) <= 9 && (!(*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isCerminGanda)){
            printf("\n");
            showName(&(*P), nomorPemain);
            printf(" memakai skill ");
            ShowSkill(((*P).TabPlayer[nomorPemain].skills), inputs);
            (*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isCerminGanda = true;
            DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
            cerminPengganda(&(*P).TabPlayer[nomorPemain].skills);
        }else{
            if (NbElmt((*P).TabPlayer[nomorPemain].skills) >= 10){
                printf("\nPunten skillmu penuh, jadi ga bisa make skill ini");
            }else if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isCerminGanda)){
                printf("\nBuff cermin pengganda sudah aktif.");
            }
        }
    }
    else if (infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 3){
        if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPembesar)){
            printf("\nPunten kamu udah make skill Senter Pembesar, jadi gak bisa make lagi");
        }else if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPengecil)){
            printf("\nPunten kamu udah make skill Senter Pengecil, jadi gak bisa make skill Senter Pembesar\n");
        }else{
            printf("\n");
            showName(&(*P), nomorPemain);
            printf(" memakai skill ");
            ShowSkill(((*P).TabPlayer[nomorPemain].skills), inputs);
            (*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPembesar = true;
            DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
        }
    }
    else if(infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 4){
        if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPengecil)){
            printf("\nPunten kamu udah make skill Senter Pengecil, jadi gak bisa make lagi\n");
        }else if(((*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPembesar)) {
            printf("\nPunten kamu udah make skill Senter Pembesar, jadi gak bisa make skill Senter Pengecil\n");
        }else{
            printf("\n");
            showName(&(*P), nomorPemain);
            printf(" memakai skill ");
            ShowSkill(((*P).TabPlayer[nomorPemain].skills), inputs);
            (*P).TabPlayer[nomorPemain].TabBuff[nomorPemain].isSenterPengecil = true;
            DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
        }
    }else if (infoKe((*P).TabPlayer[nomorPemain].skills, inputs) == 5){
        int i;
        for (i = 1; i<=jumlah(*P); i++){
            if (i != nomorPemain){
                printf("%d. ", i);
                showName(&(*P), i);
                printf("\n");
            }
        }
        printf("Pilih pemain untuk ditukar posisinya : ");
        int pilihan;
        scanf("%d", &pilihan);
        boolean valid = false;
        while (!valid){
            if (pilihan <= jumlah(*P) && pilihan >= 1 && pilihan != nomorPemain){
                valid = true;
            }else{
                printf("Pilihan angka tidak valid\n");
                printf("Masukkan kembali angka sesuai nomor pemain yang tertera : ");
                scanf("%d", &pilihan);
            }
        }
        int posisi;
        posisi = (*P).TabPlayer[nomorPemain].position;
        (*P).TabPlayer[nomorPemain].position = (*P).TabPlayer[pilihan].position;
        (*P).TabPlayer[pilihan].position = posisi;
        DeleteI(&((*P).TabPlayer[nomorPemain].skills), inputs);
        printf("\n");
        showName(&(*P), nomorPemain);
        printf(" bertukar posisi dengan ");
        showName(&(*P), pilihan);
        printf(". ");
        showName(&(*P), nomorPemain);
        printf(" sekarang berada di petak %d, dan ", (*P).TabPlayer[nomorPemain].position);
        showName(&(*P), pilihan);
        printf(" berada di petak %d.\n", (*P).TabPlayer[pilihan].position);
    }
}

void skillSebelum(List aslinya, List *hasilcopy){
/* I.S. List Skill tidak kosong            */
/* F.S. Mengembalikan list skill sebelum undo*/
    List asli = aslinya;
    while(First(asli) != Nil){
        address skill;
        skill = Alokasi(Info(First(asli)));
        InsertLast(hasilcopy, skill);
        First(asli) = Next(First(asli));
    }
}

void showPeringkat(Player p){
/* I.S. Array Player tidak kosong             */
/* F.S. Mengembalikan urutan peringkat pemain */
    int TabPosPlayer[jumlah(p)];
    int Tabnomor[jumlah(p)];
    int i, j, a, t1, t2;
    for (i = 1; i <= jumlah(p); i++)
    {
        TabPosPlayer[i] = (p).TabPlayer[i].position;
        Tabnomor[i] = i;
    }
    // Sorting posisi player dari terbesar ke terkecil
    for(a = 1; a <= jumlah(p); a++)
    {
        for (j = 1; j < jumlah(p); j++)
        {
            if (TabPosPlayer[j] <= TabPosPlayer[j + 1])
            {
                t1 = TabPosPlayer[j];
                t2 = Tabnomor[j];
                TabPosPlayer[j] = TabPosPlayer[j + 1];
                Tabnomor[j] = Tabnomor[j + 1];
                TabPosPlayer[j + 1] = t1;
                Tabnomor[j + 1] = t2;
            }
        }
    }
    for (i = 1; i <= jumlah(p); i++)
    {
        printf("%d. ", i);
        showName(&p, Tabnomor[i]);
        printf("\n");
    }
}

