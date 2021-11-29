//Impementasi dari listlinier.h

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmptyList(List L){
// Mengirim true jika list kosong
    return First(L) == Nil;
}

void CreateEmpty (List *L){
// I.S. sembarang
// F.S. Terbentuk list kosong 
    First(*L) = Nil;
}

address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address p;
    p = (address) malloc (sizeof(ElmtList));
    if (p != Nil){
        Info(p) = X;
        Next(p) = Nil;
    }
    return p;
}

void Dealokasi (address *P){
// I.S. P terdefinisi
// F.S. P dikembalikan ke sistem
// Melakukan dealokasi/pengembalian address P
    free(*P);
}

address Search (List L, infotype X){
// Melakukan pencarian terhadap X dalam sebuah list   
	address P;
	P = First(L);
	if (IsEmptyList(L)){
		return Nil;
	}
	else{
		while (P != Nil && Info(P) != X){
			P = Next(P);
		}
		return P;
	}
};

void InsVFirst (List *L, infotype X){
// I.S. L mungkin kosong 
// F.S. Melakukan alokasi sebuah elemen dan 
// menambahkan elemen pertama dengan nilai X jika alokasi berhasil 
    address newP = Alokasi(X);
    if (newP != Nil){
        Next(newP) = First(*L);
        First(*L) = newP;
    }
}

void InsVLast (List *L, infotype X){
// I.S. L mungkin kosong 
// F.S. Melakukan alokasi sebuah elemen dan 
// menambahkan elemen list di akhir: elemen terakhir yang baru 
// bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. 
    address newlast = Alokasi(X);
    if (newlast == Nil) return;

    if (IsEmptyList(*L)){
        InsVFirst(L, X);
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = newlast;
        Next(Next(now)) = Nil;
    }
}

void DelVFirst (List *L, infotype *X){
// I.S. List L tidak kosong
// F.S. Elemen pertama list dihapus: nilai info disimpan pada X
// dan alamat elemen pertama di-dealokasi
    address deletedP = First(*L);
    *X = Info(deletedP);
    First(*L) = Next(deletedP);

    Dealokasi(&deletedP);
}

void DelVLast (List *L, infotype *X){
// I.S. list tidak kosong
// F.S. Elemen terakhir list dihapus: nilai info disimpan pada X 
// dan alamat elemen terakhir di-dealokasi */    
    address now = First(*L);
    if(Next(now) != Nil){
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        *X = Info(Next(now));
        Dealokasi(&Next(now));
        Next(now) = Nil;
    }else{
        DelVFirst(L, X);
    }
}

void InsertFirst (List *L, address P){
// I.S. Sembarang, P sudah dialokasi  
// F.S. Menambahkan elemen ber-address P sebagai elemen pertama 
    address first = First(*L);
    if (P != Nil){
        Next(P) = first;
        First(*L) = P;
    }
}

void InsertLast (List *L, address P){
// I.S. Sembarang, P sudah dialokasi  
// F.S. P ditambahkan sebagai elemen terakhir yang baru
    if (P == Nil) return;

    if (IsEmptyList(*L)){
        First(*L) = P;
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(P) = Nil;
        Next(now) = P;
    }
}

void DelLast (List *L, address *P){
// I.S. List tidak kosong
// F.S. P adalah alamat elemen terakhir list sebelum penghapusan
// Elemen list berkurang satu (mungkin menjadi kosong) 
// Last element yg baru adalah suksesor elemen pertama yang lama
    address now = First(*L);
    if(Next(now) == Nil){
        DelFirst(L, P);
    }else{
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        DelAfter(L, P, now);
    }
}

void DeleteI(List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Elemen ke-X dari list dihapus dan didealokasi */
/* Jika tidak ada elemen list dengan list ke-X maka list tetap dan memberikan peringatan */
/* List mungkin menjadi kosong karena penghapusan */
{
    address p;
    address Prev = Nil;
    p = First(*L);
    if (X != 1)
    {
        int i = 1;
        while(i < X){
            Prev = p;
            p = Next(p);
            i++;
        }
        Next(Prev) = Next(p);
        Dealokasi(&p);
        
    }
    else if (X == 1)
    {
        DelFirst(L, &p);
    }
}

void DelFirst (List *L, address *P){
// I.S. List tidak kosong
// F.S. P adalah alamat elemen pertama list sebelum penghapusan
// Elemen list berkurang satu (mungkin menjadi kosong) 
// First element yg baru adalah suksesor elemen pertama yang lama
    address deletedP = First(*L);
    *P = deletedP;
    First(*L) = Next(deletedP);
}

void DelAfter (List *L, address *Pdel, address Prec){
// I.S. List tidak kosong. Prec adalah anggota list 
// F.S. Menghapus Next(Prec): 
//      Pdel adalah alamat elemen list yang dihapus  

    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L){
// I.S. List mungkin kosong
// F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] 
    printf("[");
    if (!IsEmptyList(L)){
        address now = First(L);
        while (now != Nil) {
            printf("%d", Info(now));
            now = Next(now);

            if (now != Nil)
                printf(",");
        }
    }
    printf("]");
}

int infoKe(List L, int X){
// Mengecek dan mengembalikan info dari suatu element dalam list
    address P = First(L);
    if (X == 1){
        if (Info(P) == 1){
            return 1;
        }
        else if (Info(P) == 2){
            return 2;
        }
        else if (Info(P) == 3){
            return 3;
        }
        else if (Info(P) == 4){
            return 4;
        }
        else if (Info(P) == 5){
            return 5;
        }
    }
    else
    {
        for (int i = 1; i < X; i++)
        {
            P = Next(P);
        }
        if (Info(P) == 1)
        {
            return 1;
        }
        else if (Info(P) == 2)
        {
            return 2;
        }
        else if (Info(P) == 3)
        {
            return 3;
        }
        else if (Info(P) == 4)
        {
            return 4;
        }
        else if (Info(P) == 5)
        {
            return 5;
        }
    }
}

int NbElmt (List L){
// Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong 
    int n = 0;
    if (!IsEmptyList(L)){
        address now = First(L);
        while (now != Nil){
            n++;
            now = Next(now);
        }
    }
    return n;
}

void InsertAfter (List *L, address P, address Prec){
// I.S. Prec pastilah elemen list dan bukan elemen terakhir, 
// P sudah dialokasi  
// F.S. Insert P sebagai elemen sesudah elemen beralamat Prec 
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void ShowSkill(List L, int X)
//Menampilkan Skill yang dimiliki oleh pemain
{
    address P = First(L);
    if (X == 1)
    {
        if (Info(P) == 1)
        {
            printf("Pintu Ga Ke Mana Mana\n");
        }
        else if (Info(P) == 2)
        {
            printf("Cermin Pengganda\n");
        }
        else if (Info(P) == 3)
        {
            printf("Senter Pembesar Hoki\n");
        }
        else if (Info(P) == 4)
        {
            printf("Senter Pengecil Hoki\n");
        }
        else if (Info(P) == 5)
        {
            printf("Mesin Penukar Posisi\n");
        }
        else
        {
            printf("Teknologi Gagal\n");
        }
    }
    else
    {
        for (int i = 1; i < X; i++)
        {
            P = Next(P);
        }
        if (Info(P) == 1)
        {
            printf("Pintu Ga Ke Mana Mana\n");
        }
        else if (Info(P) == 2)
        {
            printf("Cermin Pengganda\n");
        }
        else if (Info(P) == 3)
        {
            printf("Senter Pembesar Hoki\n");
        }
        else if (Info(P) == 4)
        {
            printf("Senter Pengecil Hoki\n");
        }
        else if (Info(P) == 5)
        {
            printf("Mesin Penukar Posisi\n");
        }
        else
        {
            printf("Teknologi Gagal\n");
        }
    }
};