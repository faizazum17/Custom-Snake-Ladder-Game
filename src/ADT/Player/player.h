#ifndef __PLAYER_H__
#define __PLAYER_H__


#include <stdlib.h>
#include "../../boolean.h"
#include <stdio.h>
#include "../ListLinier/listlinier.h"
#include "../Skill/skill.h"

#define NilPlayer NULL

typedef struct{
    boolean isImmuned;
    boolean isSenterPembesar;
    boolean isSenterPengecil;
    boolean isCerminGanda;
} BuffPlayer;

typedef struct{
    char pName[15];
    int nomorPemain;
    int position;
    List skills;
    boolean isRolled;
    boolean isTeleported;
    BuffPlayer TabBuff[4+1];
} DataPlayer;

typedef struct{
    int banyakPlayer;
    DataPlayer TabPlayer[4+1];
} Player;

#define jumlah(Player) (Player).banyakPlayer

/******* KONSTRUKTOR ***********/

void CreatePlayerEmpty(Player *P);
/* I.S. sembarang             */
/* F.S. Terbentuk list Player kosong */

void InputPlayer(Player *P, int banyakPlayer);
/* I.S. Array Player kosong             */
/* F.S. Array Player diisi oleh nama-nama pemain */

void showName (Player *P, int nomorPemain);
/* I.S. Array Player tidak kosong             */
/* F.S. Mengembalikan nama pemain sesuai input nomornya pemain */

void useSkill(Player *P, int inputs, int nomorPemain);
// I.S Array pada player tidak kosong
// F.S Element array pada player akan terhapus sesuai dengan input yang dimasukkan oleh player
// Pemain akan memberi masukkan untuk mimilih penggunaan skill, skill yang telah digunakan akan menghasilkan 
// buff yang akan dimasukkan ke array buff lalu pada array akan dihapus element skill yang telah digunakan .

void skillSebelum(List aslinya, List *hasilcopy);
/* I.S. List Skill tidak kosong            */
/* F.S. Mengembalikan list skill sebelum undo*/

void showPeringkat(Player p);
/* I.S. Array Player tidak kosong             */
/* F.S. Mengembalikan urutan peringkat pemain */

#endif