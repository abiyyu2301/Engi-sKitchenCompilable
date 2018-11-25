/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
 memori tabel statik */

#ifndef ARRAYMEJA_H
#define ARRAYMEJA_H

#include "boolean.h"
#include "matriks.h"
/*  Kamus Umum */
#define IdxMax 10
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct{
    int isi;
    int x;
    int y;
    int room;
    int kesabaran;
    boolean terisi;
} ElMejaType;   /* type elemen tabel */
typedef struct {
    ElMejaType Meja[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
    int Neff; /* >=0, banyaknya elemen efektif */
} TabMeja;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 T.Neff  untuk mengetahui banyaknya elemen
 T.TI    untuk mengakses seluruh nilai elemen tabel
 T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 Tabel kosong: T.Neff = 0
 Definisi elemen pertama : T.TI[i] dengan i=1
 Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define Meja(T)     (T).Meja
#define ElmtMeja(T,i) (T).Meja[(i)]
#define Elmtisi(T,i) (T).Meja[(i)].isi
#define Elmtkesabaran(T,i) (T).Meja[(i)].kesabaran
#define Elmtx(T,i) (T).Meja[(i)].x
#define Elmty(T,i) (T).Meja[(i)].y
#define Elmtroom(T,i) (T).Meja[(i)].room
#define Elmtterisi(T,i) (T).Meja[(i)].terisi
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeMeja (TabMeja * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtTabMeja (TabMeja T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
/* *** Selektor INDEKS *** */
void kosongmeja(TabMeja *T,MATRIKS *M,int x);
// mengosongkan meja
void isimeja(TabMeja *T,MATRIKS *M,int x,int y,int sabar);
// mengisi meja ke x sebanyak y orang
#endif
