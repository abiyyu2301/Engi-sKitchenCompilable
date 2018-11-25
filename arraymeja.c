#include <stdio.h>
#include "arraymeja.h"
#define Inf 9999999
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeMeja (TabMeja * T){
    int i;
    /* I.S. T sembarang */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    Elmtisi(*T,0)=2;
    Elmtisi(*T,1)=4;
    Elmtisi(*T,2)=2;
    Elmtisi(*T,3)=4;
    Elmtisi(*T,4)=2;
    Elmtisi(*T,5)=4;
    Elmtisi(*T,6)=2;
    Elmtisi(*T,7)=2;
    Elmtisi(*T,8)=4;
    Elmtisi(*T,9)=4;
    Elmtkesabaran(*T,0)=Inf;
    Elmtkesabaran(*T,1)=Inf;
    Elmtkesabaran(*T,2)=Inf;
    Elmtkesabaran(*T,3)=Inf;
    Elmtkesabaran(*T,4)=Inf;
    Elmtkesabaran(*T,5)=Inf;
    Elmtkesabaran(*T,6)=Inf;
    Elmtkesabaran(*T,7)=Inf;
    Elmtkesabaran(*T,8)=Inf;
    Elmtkesabaran(*T,9)=Inf;
    Elmtx(*T,0)=6;
    Elmty(*T,0)=3;
    Elmtx(*T,1)=2;
    Elmty(*T,1)=2;
    Elmtx(*T,2)=7;
    Elmty(*T,2)=2;
    Elmtx(*T,3)=2;
    Elmty(*T,3)=7;
    Elmtx(*T,4)=7;
    Elmty(*T,4)=7;
    Elmtx(*T,5)=2;
    Elmty(*T,5)=5;
    Elmtx(*T,6)=3;
    Elmty(*T,6)=1;
    Elmtx(*T,7)=7;
    Elmty(*T,7)=6;
    Elmtx(*T,8)=2;
    Elmty(*T,8)=2;
    Elmtx(*T,9)=3;
    Elmty(*T,9)=6;
    Elmtroom(*T,0)=3;
    Elmtroom(*T,1)=1;
    Elmtroom(*T,2)=1;
    Elmtroom(*T,3)=1;
    Elmtroom(*T,4)=1;
    Elmtroom(*T,5)=2;
    Elmtroom(*T,6)=2;
    Elmtroom(*T,7)=2;
    Elmtroom(*T,8)=3;
    Elmtroom(*T,9)=3;
    for(i=0;i<=9;i++){
        Elmtterisi(*T,i)=false;
    }
    Neff(*T)=10;
}/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtTabMeja (TabMeja T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}
void kosongmeja(TabMeja *T,MATRIKS *M,int x){
    // mengosongkan meja x
    if (Elmtisi(*T,x)==4){
        Elmt(*M,Elmtx(*T,x),Elmty(*T,x)-1)='X';
        Elmt(*M,Elmtx(*T,x),Elmty(*T,x)+1)='X';
    }
    Elmt(*M,Elmtx(*T,x)-1,Elmty(*T,x))='X';
    Elmt(*M,Elmtx(*T,x)+1,Elmty(*T,x))='X';
    Elmtkesabaran(*T,x)=Inf;
    Elmtterisi(*T,x)=false;
}
void isimeja(TabMeja *T,MATRIKS *M,int x,int y,int sabar)
// mengisi meja ke x sebanyak y orang dengan kesabaran sabar
{
    if (y==4){
        Elmt(*M,Elmtx(*T,x),Elmty(*T,x)-1)='W';
        Elmt(*M,Elmtx(*T,x),Elmty(*T,x)+1)='W';
    }
    Elmt(*M,Elmtx(*T,x)-1,Elmty(*T,x))='W';
    Elmt(*M,Elmtx(*T,x)+1,Elmty(*T,x))='W';
    Elmtkesabaran(*T,x)=sabar;
    Elmtterisi(*T,x)=true;
}
