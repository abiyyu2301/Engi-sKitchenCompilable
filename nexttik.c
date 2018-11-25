#include "nexttik.h"


//jadi nexttik nambah waktu sama ngurangi kesabaran sekaligus klo udah gak sabar hapus pelanggan sambil kredibilitas ngurang
//Queue masih biasa belum prio
void NextTik(JAM *J,int *day,TabMeja *Meja,Queue *antrean,int *kredibilitas,boolean *exit,player p,MATRIKS *room1,MATRIKS * room2,MATRIKS * room3)
{
    long tik;
    int i;
    boolean found=false;
    infoqueue sampah;
    *J=NextDetik(*J);
    if (Hour(*J)==0&&Minute(*J)==0&&Second(*J)==0){            //nambah hari jika sebelumnya 23.59.59
        *day=+1;
    }
    //amtrian, keesabaran
    //kurangin kesabaran sama kredibilitas
    for(i=0;i<=9;i++){
        if (Elmtterisi(*Meja,i)){
            Elmtkesabaran(*Meja,i)--;
            if (Elmtkesabaran(*Meja,i)==0){
                if (Elmtroom(*Meja,i)==1){
                    kosongmeja(Meja,room1,i);
                }else if (Elmtroom(*Meja,i)==2){
                    kosongmeja(Meja,room2,i);
                }else if (Elmtroom(*Meja,i)==3){
                    kosongmeja(Meja,room3,i);
                }
                *kredibilitas-=1;
            }
        }
    }
    for(i=Head(*antrean);i<=Tail(*antrean);i++){
        (*antrean).T[i].kesabaran-=1;
    }
    while (!QueueIsEmpty(*antrean)&&(!found)){
        if (InfoHead(*antrean).kesabaran==0){
            Del(antrean, &sampah);
            *kredibilitas-=1;
        }
        else{
            found=true;
        }
    }
    if (*kredibilitas==0){
        *exit=true;
    }
}
