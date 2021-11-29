#include "array.h"
#include <stdio.h>

int main(){
    int n;
    TabInt arr;
    printf("Masukkan ukuran array: ");
    scanf("%d", &n); //input ukuran

    MakeEmptyArray(&arr);
    SetNeff(&arr, n);

    for(int i = 0; i<n; i++){   
        int elmt;
        printf("Masukkan elemen: ");
        scanf("%d", &elmt);    //input element
        SetEl(&arr, i, elmt);
    }
    printf("Maksimum banyak elemen pada array: %d\n", MaxNbEl(arr));
    printf("Banyak elemen efektif: %d\n", NbElmtArray(arr));
    printf("Indeks elemen pertama: %d\n", GetFirstIdx(arr));
    printf("Indeks elemen terakhir: %d\n", GetLastIdx(arr));
    printf("Elemen indeks kesatu: %d\n", GetElmt(arr, 1));
    if(!IsEmpty(arr)){
        printf("Array tidak kosong\n");
    }
    else{
        printf("Array kosong\n");
    }
    if(!IsFull(arr)){
        printf("Array tidak penuh\n");
    }
    else{
        printf("Array penuh\n");
    }
    if(IsIdxValid(arr, 20)){
        printf("Indeks ke-20 merupakan index yang valid.\n");
    }
    else{
        printf("Index ke-20 bukan index yang valid.\n");
    }
    if(IsIdxEff(arr, 3)){
    printf("Index ke-3 merupakan index efektif.\n");
    }
    else{
        printf("Index ke-3 bukan index efektif.\n");
    }
}