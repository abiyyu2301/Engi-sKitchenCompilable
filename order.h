#ifndef order_h
#define order_h

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"
#include "matriks.h"
#include <math.h>
#include <time.h>
#include "stackt.h"

typedef int IdxType;
#define IdxUndef -999;
typedef struct {
    Kata food;
    int meja;
}OrdCust;

typedef struct {
    OrdCust TO[100]; /* memori tempat penyimpan elemen (container) */
    int Neff; /* >=0, banyaknya elemen efektif */
} TabOrd;

#define Neff(T)   (T).Neff
#define TO(T)     (T).TO
#define ElmtOrd(T,i) (T).TO[(i)]
#define Food(T,i) (T).TO[(i)].food
#define Meja(T,i) (T).TO[(i)].meja

IdxType SearchOrd (TabOrd T, Kata X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

void DelOrd(TabOrd *T, IdxType idx);
/*Delete Elmt(T, idx), dan menjaga array TabOrd tetap kontigu*/

void order(TabOrd *T, MATRIKS M, Kata * arr_makanan);
/*matriks itu buat
//Variables
//Stack ord adalah stack yang berisi orderan
//Matriks M adalah board ruangan
*/
 #endif /* order_h */
