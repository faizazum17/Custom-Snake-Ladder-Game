#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../Player/player.h"
#include "../ListLinier/listlinier.h"
#include "../Skill/skill.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    (*S).TOP = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return S.TOP == NilStack;
}
boolean IsFullStack (Stack S)
{   
    return S.TOP == MaxEl;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Player p)
/* Menambahkan P sebagai elemen Stack S. */
{
	int i = 1;
	if (IsEmptyStack(*S)){
		Top(*S) = 1;
	}else{
		Top(*S)++;
	}
	(*S).player[Top(*S)] = p;
	for(i; i<= jumlah(p); i++){
		(*S).player[Top(*S)].TabPlayer[i].skills.First = Nil;
		skillSebelum((p).TabPlayer[i].skills, &(*S).player[Top(*S)].TabPlayer[i].skills);
	}
}
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. P menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Player* p)
/* Menghapus P dari Stack S. */
{
	*p = (*S).player[Top(*S)];
	Top(*S)--;
}
/* I.S. S  tidak mungkin kosong */
/* F.S. P adalah nilai elemen TOP yang lama, TOP berkurang 1 */
