#include<graphics.h>
#include<stdio.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h> ///lama

struct infoposisi
{
    int baris[6];
    int kolom[6];
};
struct infokordinat
{
    int x[2]={0,0};
    int y[2]={0,0};
};

struct infoban
{
        infokordinat kordinat;
};
struct moncong
{
    infokordinat kordinat;
};
struct infohapus
{
    infokordinat kordinat;
};
struct TANK
{
    infoposisi posisi;
    infoban banV;
    infoban banH;
    moncong Moncong;
    infokordinat kordinat_tank;
    infohapus hapus;
    int key;    ///Identitas untuk arah kanan kiri atas bawah
    int score=0;
    char scr[5];
    int warna[2];
    int jml_peluru=0;
    infokordinat kordinat_peluru;
    infokordinat gambar_peluru;
};
void gambar_tembok();
void air();
void gambar_tembok();
//print arena via sprite
void arena();
//Print Arena
void air();
//Print Arena khusus Air
void Tembak(TANK, int);
//Menembak
void Hapus();
//Untuk Menghapus Tank sebelumnya (blm dipergunakan)
void Vtank(TANK s_tank);
//Untuk Menampilkan Tank dengan posisi Vertikal pada Layar(BGI)
void Htank(TANK s_tank);
//Untuk Menampilkan Tank dengan posisi Horizontal pada Layar(BGI)
void Play_Game();
//Menu pada saat permainan Mulai

#define MAX 50



int stage[MAX][MAX] =       {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //0   50 (50x10=500)
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //1
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //2
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //3
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //4
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //5
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //6
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //7
                            {1,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,1}, //8
                            {1,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,1}, //9
                            {1,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,1}, //10
                            {1,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,1}, //11
                            {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //12
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //13
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //14
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,1}, //15
                            {1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //16
                            {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //17
                            {1,4,4,4,4,4,4,4,4,0,0,0,0,0,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //18
                            {1,4,4,4,4,4,4,4,4,0,0,0,0,0,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //19
                            {1,4,4,4,4,4,4,4,4,0,0,0,0,0,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //20
                            {1,4,4,4,4,4,4,4,4,0,0,0,0,0,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //21
                            {1,3,3,3,3,3,3,3,3,0,0,0,0,0,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,0,0,0,0,0,0,2,2,2,2,2,2,2,2,1}, //22
                            {1,3,3,3,3,3,3,3,3,0,0,0,0,0,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,0,0,0,0,0,0,2,2,2,2,2,2,2,2,1}, //23
                            {1,0,0,0,0,0,0,0,3,3,3,3,3,3,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,2,2,2,2,2,2,2,0,0,0,0,0,0,0,1}, //24
                            {1,0,0,0,0,0,0,0,3,3,3,3,3,3,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,2,2,2,2,2,2,2,0,0,0,0,0,0,0,1}, //25
                            {1,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,1}, //26
                            {1,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,1}, //27
                            {1,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,3,3,0,0,0,0,0,0,0,0,3,3,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,1}, //28
                            {1,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,1,1,0,0,0,0,0,0,0,0,1,1,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,1}, //29
                            {1,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,1}, //30
                            {1,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,1}, //31
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //32
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //33
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //34
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //35
                            {1,0,0,0,0,0,0,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,0,0,0,0,0,1}, //36
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //37
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //38
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //39
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //40
                            {1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //41
                            {1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,1}, //42
                            {1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,1}, //43
                            {1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,1}, //44
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //45
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};//46

void gambar_tembok()
{

    int i, j, x,y;

    for(i=0;i<MAX; i++)
    {
        for(j=0;j<MAX; j++)
        {
            if(stage[j][i]==1)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/batas.bmp",x,y,x+10,y+10);
            }

            if (stage [j][i]==3)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/tembok.bmp",x,y,x+10,y+10);
            }
             if (stage [j][i]==5)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/besi.bmp",x,y,x+10,y+10);
            }
                if (stage [j][i]==9)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/null.bmp",x,y,x+10,y+10);
            }
        }
    }
}



void Tembak(TANK player_1,int page)
{       char arr[10];
        int pely=player_1.posisi.baris[3], pelx=player_1.posisi.kolom[3];
        int pely2=player_1.posisi.baris[4], pelx2=player_1.posisi.kolom[4];
        int kec;
        int tambah;

        if(player_1.key==0)
        {tambah=0;
            for(kec=0; (stage[pely][pelx-2]==0 || stage[pely][pelx-2]==2 || stage[pely][pelx-2]==4 || stage[pely][pelx-2]==6) && (stage[pely2][pelx2-2]==0 || stage[pely2][pelx2-2]==2 || stage[pely2][pelx2-2]==4 || stage[pely2][pelx2]==6) ;kec+=2)
            {
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();

                air();
                circle(player_1.Moncong.kordinat.x[0]+kec,player_1.Moncong.kordinat.y[0]+5,4);
                if(tambah==5)
                {
                    pelx+=1;
                    pelx2+=1;
                    tambah=0;
                }
                tambah+=1;
                sprintf(arr,"%d",pelx);
                outtextxy(500,250,arr);
                sprintf(arr,"%d",pelx2);
                outtextxy(500,260,arr);
                sprintf(arr,"%d",player_1.posisi.kolom[3]);
                outtextxy(500,270,arr);
                sprintf(arr,"%d",player_1.posisi.kolom[4]);
                outtextxy(500,280,arr);

                Htank(player_1);
                gambar_tembok();
                arena();
                gambar_tembok();
                page=1-page;
            }
            int temp_stage, temp_stage2;
            //if((stage[pely][pelx-2]==3 || stage[pely][pelx-2]==5 || stage[pely][pelx-2]==0) && (stage[pely2][pelx2-2]==3 || stage[pely2][pelx2-2]==5 || stage[pely2][pelx2-2]==0))

            /*Menghancurkan Benda*/
            if((stage[pely][pelx-2]==3 && stage[pely2][pelx2-2]==3)|| (stage[pely][pelx-2]==0 && stage[pely2][pelx2-2]==3) || (stage[pely][pelx-2]==3 && stage[pely2][pelx2-2]==0)) //buat ngehancurin tembok
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                //temp_stage=stage[pely][pelx];
                //temp_stage2=stage[pely2][pelx2];
                stage[pely][pelx-2]=0;
                stage[pely2][pelx2-2]=0;
            }
            if (stage[pely][pelx-2]==4 && stage[pely2][pelx2-2]==3)
            {
                stage[pely][pelx-2]=4;
                stage[pely2][pelx2-2]=0;
            }
            else if (stage[pely][pelx-2]==3 && stage[pely2][pelx2-2]==4)
            {
                stage[pely][pelx-2]=0;
                stage[pely2][pelx2-2]=4;
            }
            else if (stage[pely][pelx-2]==2 && stage[pely2][pelx2-2]==3)
            {
                stage[pely][pelx-2]=2;
                stage[pely2][pelx2-2]=0;
            }
            else if (stage[pely][pelx-2]==3 && stage[pely2][pelx2-2]==2)
            {
                stage[pely][pelx-2]=0;
                stage[pely2][pelx2-2]=2;
            }
            /*Atas Menghancurkan Benda*/
        }

        else if(player_1.key==1)
        {
            tambah=0;
            for(kec=0; (stage[pely][pelx-3]==0 || stage[pely][pelx-3]==2 || stage[pely][pelx-3]==4 ) && (stage[pely2][pelx2-3]==0 || stage[pely2][pelx2-3]==2 || stage[pely2][pelx2-3]==4);kec+=2)
            {
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();

                air();
                circle(player_1.Moncong.kordinat.x[0]-kec,player_1.Moncong.kordinat.y[0]+5,4);
                if(tambah==5)
                {
                    pelx-=1;
                    pelx2-=1;
                    tambah=0;
                }
                tambah+=1;

                Htank( player_1);
                gambar_tembok();
                arena();
                gambar_tembok();
                sprintf(arr,"%d",pelx);
                outtextxy(500,250,arr);
                sprintf(arr,"%d",pelx2);
                outtextxy(500,260,arr);
                page=1-page;
            }
            int temp_stage, temp_stage2;
            if((stage[pely][pelx-2]==6) && (stage[pely2][pelx2-2]==6)) //kondi dimana score valid
            {
                temp_stage=stage[pely][pelx-2];
                temp_stage2=stage[pely2][pelx2-2];
                stage[pely][pelx-2]=0;
                stage[pely2][pelx2-2]=0;
            }
            /*Menghancurkan Benda*/
            if((stage[pely][pelx-3]==3 && stage[pely2][pelx2-3]==3)|| (stage[pely][pelx-3]==0 && stage[pely2][pelx2-3]==3) || (stage[pely][pelx-3]==3 && stage[pely2][pelx2-3]==0)) //buat ngehancurin tembok
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                temp_stage=stage[pely][pelx-3];
                temp_stage2=stage[pely2][pelx2-3];
                stage[pely][pelx-3]=0;
                stage[pely2][pelx2-3]=0;
            }
            if (stage[pely][pelx-3]==4 && stage[pely2][pelx2-3]==3)
            {   //Rumput & Tembok
                stage[pely][pelx-3]=4;
                stage[pely2][pelx2-3]=0;
            }
            else if (stage[pely][pelx-3]==3 && stage[pely2][pelx2-3]==4)
            {   //Tembok & Rumput
                stage[pely][pelx-3]=0;
                stage[pely2][pelx2-3]=4;
            }
            else if (stage[pely][pelx-3]==2 && stage[pely2][pelx2-3]==3)
            {   //Air & Tembok
                stage[pely][pelx-3]=2;
                stage[pely2][pelx2-3]=0;
            }
            else if (stage[pely][pelx-3]==3 && stage[pely2][pelx2-3]==2)
            {   //Tembok &  Air
                stage[pely][pelx-3]=0;
                stage[pely2][pelx2-3]=2;
            }
        }

            else if(player_1.key==2)
        {
            pely=player_1.posisi.baris[3];
            pelx=player_1.posisi.kolom[3];
            pely2=player_1.posisi.baris[4]+1;
            pelx2=player_1.posisi.kolom[4];
            tambah=0;
            for(kec=0; (stage[pely-1][pelx-2]==0 || stage[pely-1][pelx-2]==2 || stage[pely-1][pelx-2]==4 ) && (stage[pely2-1][pelx2-2]==0 || stage[pely2-1][pelx2-2]==2 || stage[pely2-1][pelx2-2]==4);kec+=2)
            {

                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();

                air();

                circle(player_1.Moncong.kordinat.x[0],player_1.Moncong.kordinat.y[0]+5-kec,4);
                if(tambah==5)
                {
                    pely-=1;
                    pely2-=1;
                    tambah=0;
                }
                tambah+=1;

                sprintf(arr,"%d",player_1.posisi.baris[3]);
                outtextxy(500,200,arr);
                sprintf(arr,"%d",player_1.posisi.baris[4]);
                outtextxy(500,220,arr);

                sprintf(arr,"%d",pely);
                outtextxy(500,250,arr);
                sprintf(arr,"%d",pely2);
                outtextxy(500,270,arr);

                Vtank( player_1);
                gambar_tembok();
                arena();
                gambar_tembok();
                page=1-page;
            }
        }

        else if (player_1.key==3)
        {
            pely=player_1.posisi.baris[3]-2;
            pelx=player_1.posisi.kolom[3];
            pely2=player_1.posisi.baris[4]-1;
            pelx2=player_1.posisi.kolom[4];
            tambah=0;
            for(kec=0; (stage[pely+2][pelx-3]==0 || stage[pely+2][pelx-3]==2 || stage[pely+2][pelx-3]==4 ) && (stage[pely2+2][pelx2-3]==0 || stage[pely2+2][pelx2-3]==2 || stage[pely2+2][pelx2-3]==4);kec+=2)
            {

                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();

                air();
                circle(player_1.Moncong.kordinat.x[0],player_1.Moncong.kordinat.y[0]+5+kec,4);
                if(tambah==5)
                {
                    pely+=1;
                    pely2+=1;
                    tambah=0;
                }
                tambah+=1;

                sprintf(arr,"%d",pely);
                outtextxy(500,250,arr);
                sprintf(arr,"%d",pely2);
                outtextxy(500,270,arr);

                Vtank( player_1);
                gambar_tembok();
                arena();
                page=1-page;
            }
            if((stage[pely+2][pelx-3]==0 || stage[pely+2][pelx-3]==2 || stage[pely+2][pelx-3]==4 ) && (stage[pely2+2][pelx2-3]==0 || stage[pely2+2][pelx2-3]==2 || stage[pely2+2][pelx2-3]==4)) //buat ngehancurin tembok
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                //temp_stage=stage[pely+2][pelx-3];
                //temp_stage2=stage[pely2+2][pelx2-3];
                stage[pely+2][pelx-3]=0;
                stage[pely2+2][pelx2-3]=0;
            }
            if (stage[pely+2][pelx-3]==4 && stage[pely2+2][pelx2-3]==3)
            {   //Rumput & Tembok
                stage[pely+2][pelx-3]=4;
                stage[pely2+2][pelx2-3]=0;
            }
            else if (stage[pely+2][pelx-3]==3 && stage[pely2+2][pelx2-3]==4)
            {   //Tembok & Rumput
                stage[pely][pelx-3]=0;
                stage[pely2][pelx2-3]=4;
            }
            else if (stage[pely+2][pelx-3]==2 && stage[pely2+2][pelx2-3]==3)
            {   //Air & Tembok
                stage[pely][pelx-3]=2;
                stage[pely2][pelx2-3]=0;
            }
            else if (stage[pely+2][pelx-3]==3 && stage[pely2+2][pelx2-3]==2)
            {   //Tembok &  Air
                stage[pely][pelx-3]=0;
                stage[pely2][pelx2-3]=2;
            }
        }
}

void HapusTank(TANK all_tank)
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(all_tank.hapus.kordinat.x[0],all_tank.hapus.kordinat.y[0],all_tank.hapus.kordinat.x[1],all_tank.hapus.kordinat.y[1]);
}

void HapusPeluru(TANK all_tank)
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    pieslice(all_tank.gambar_peluru.x[0]-10,all_tank.gambar_peluru.y[0]+5,0,360,5);
}
void Vtank(TANK s_tank)
{
    setfillstyle(SOLID_FILL,s_tank.warna[0]);
    bar(s_tank.banV.kordinat.x[0],s_tank.banV.kordinat.y[0],s_tank.banV.kordinat.x[1],s_tank.banV.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank.warna[1]);
    bar(s_tank.banV.kordinat.x[0],s_tank.banV.kordinat.y[0]-10,s_tank.banV.kordinat.x[1],s_tank.banV.kordinat.y[1]-10);
    setfillstyle(SOLID_FILL,s_tank.warna[0]);
    bar(s_tank.banV.kordinat.x[0],s_tank.banV.kordinat.y[0]-20,s_tank.banV.kordinat.x[1],s_tank.banV.kordinat.y[1]-20);
    setfillstyle(SOLID_FILL,s_tank.warna[1]);
    bar(s_tank.banV.kordinat.x[0],s_tank.banV.kordinat.y[0]-30,s_tank.banV.kordinat.x[1],s_tank.banV.kordinat.y[1]-30);

    setfillstyle(SOLID_FILL,0);
    bar (s_tank.kordinat_tank.x[0]+5,s_tank.kordinat_tank.y[0]-10,s_tank.kordinat_tank.x[1]-5,s_tank.kordinat_tank.y[1]+10);

    setfillstyle(1,6);
    bar(s_tank.kordinat_tank.x[0]+5,s_tank.kordinat_tank.y[0]-5,s_tank.kordinat_tank.x[1]-5,s_tank.kordinat_tank.y[1]+5);

    setfillstyle(1,15);
    pieslice(s_tank.Moncong.kordinat.x[0],s_tank.Moncong.kordinat.y[0]+5,0,360,8);

    if(s_tank.key==2)
    {
        setfillstyle(1,4);
        bar(s_tank.Moncong.kordinat.x[0]-5,s_tank.Moncong.kordinat.y[0]-15,s_tank.Moncong.kordinat.x[1]-15,s_tank.Moncong.kordinat.y[1]-5);
    }
    else if(s_tank.key==3)
    {
        setfillstyle(1,4);
        bar(s_tank.Moncong.kordinat.x[0]-5,s_tank.Moncong.kordinat.y[0]+5,s_tank.Moncong.kordinat.x[1]-15,s_tank.Moncong.kordinat.y[1]+15);
    }
}

void Htank(TANK s_tank)
{
    setfillstyle(SOLID_FILL,s_tank.warna[0]);
    bar(s_tank.banH.kordinat.x[0],s_tank.banH.kordinat.y[0],s_tank.banH.kordinat.x[1],s_tank.banH.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank.warna[1]);
    bar(s_tank.banH.kordinat.x[0]+10,s_tank.banH.kordinat.y[0],s_tank.banH.kordinat.x[1]+10,s_tank.banH.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank.warna[0]);
    bar(s_tank.banH.kordinat.x[0]+20,s_tank.banH.kordinat.y[0],s_tank.banH.kordinat.x[1]+20,s_tank.banH.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank.warna[1]);
    bar(s_tank.banH.kordinat.x[0]+30,s_tank.banH.kordinat.y[0],s_tank.banH.kordinat.x[1]+30,s_tank.banH.kordinat.y[1]);

    setfillstyle(SOLID_FILL,0);
    bar (s_tank.kordinat_tank.x[0]-5,s_tank.kordinat_tank.y[0],s_tank.kordinat_tank.x[1]+5,s_tank.kordinat_tank.y[1]);

    setfillstyle(1,6);
    bar(s_tank.kordinat_tank.x[0],s_tank.kordinat_tank.y[0],s_tank.kordinat_tank.x[1],s_tank.kordinat_tank.y[1]);

    setfillstyle(1,15);
    pieslice(s_tank.Moncong.kordinat.x[0],s_tank.Moncong.kordinat.y[0]+5,0,360,8);

    if(s_tank.key==0)
    {
        setfillstyle(1,4);
        bar(s_tank.Moncong.kordinat.x[0],s_tank.Moncong.kordinat.y[0],s_tank.Moncong.kordinat.x[1],s_tank.Moncong.kordinat.y[1]);
    }
    else if(s_tank.key==1)
    {
        setfillstyle(1,4);
        bar(s_tank.Moncong.kordinat.x[0]-20,s_tank.Moncong.kordinat.y[0],s_tank.Moncong.kordinat.x[1]-20,s_tank.Moncong.kordinat.y[1]);
    }
}
void Play_Game()
{
    cleardevice();
	int tambah=1;
    int speed=10;// digunkan Perpindahan tank per 10 pixel
    TANK player_1;// Membuat data komposit untuk data player 1
    //POSISI awal ban untuk vertikal
    player_1.banV.kordinat.x[0]=170;//0 Karena c mulai dari 0
    player_1.banV.kordinat.x[1]=210;
    player_1.banV.kordinat.y[0]=450;
    player_1.banV.kordinat.y[1]=460;
    //POSISI awal ban untuk horizontal
    player_1.banH.kordinat.x[0]=170;
    player_1.banH.kordinat.x[1]=180;
    player_1.banH.kordinat.y[0]=420;
    player_1.banH.kordinat.y[1]=460;
    //POSISI awal moncong
    player_1.Moncong.kordinat.x[0]=190;
    player_1.Moncong.kordinat.x[1]=210;
    player_1.Moncong.kordinat.y[0]=435;
    player_1.Moncong.kordinat.y[1]=445;
    //Posisi awal Tank
    player_1.kordinat_tank.x[0]=175;
    player_1.kordinat_tank.x[1]=205;
    player_1.kordinat_tank.y[0]=430;
    player_1.kordinat_tank.y[1]=450;
    //Posisi Tank pada array
    player_1.posisi.baris[0]=42, player_1.posisi.kolom[0]=17;
    player_1.posisi.baris[1]=45, player_1.posisi.kolom[1]=20;
    player_1.posisi.baris[2]=42, player_1.posisi.kolom[2]=18;
    player_1.posisi.baris[3]=44, player_1.posisi.kolom[3]=21;
    player_1.posisi.baris[4]=43, player_1.posisi.kolom[4]=21;
    player_1.posisi.baris[5]=46, player_1.posisi.kolom[5]=19;
    //Warna ban
    player_1.warna[0] = 10, player_1.warna[1]=2;
    //Posisi tank kanan=0 kiri=1 atas=2 bawah=3
    player_1.key=2;
    //

    int page=0;
    char arr[10];

    air();//Print air                                  ////////////////////////////////////////////////////////////////////////////////////////////////////
    gambar_tembok();// gambar via sprite
    arena();//ARENA
    setfillstyle(1,6);
                bar(500,0,640,470);
                setfillstyle(1,5);
                bar(504,24,636,86);
                setfillstyle(1,0);
                bar(510,30,630,80);
                setfillstyle(1,5);
                bar(504,174,636,266);
                setfillstyle(1,0);
                bar(510,180,630,260);
                settextstyle(8,0,1);
                outtextxy(515,180,"TANK ENEMY");
                settextstyle(1,0,1);
                outtextxy(515,35,"SCORE");
                settextstyle(1,0,2);
                setcolor(15);
                outtextxy(515,55,player_1.scr);
                settextstyle(1,0,2);
                setfillstyle(1,7);
                bar(520,205,550,235);
                settextstyle(1,0,2);
                bar(530,205,550,235);


    while(1){

//        setactivepage(page);//Halaman Layar untuk operasi
//        setvisualpage(1-page);//Halaman Layar yang dimunculkan

        //cleardevice();//Menghapus semua yang ada di layar



        if(player_1.key==0 || player_1.key==1 ){
            Htank(player_1);}
        else if (player_1.key==2 || player_1.key==3){
            Vtank(player_1);
        }


//        if(player_1.hapus.kordinat.x[0]!=0)
//        {
//            Hapus(player_1);
//        }
//    Htank( banx, bany, banx2, bany2, warna1, warna2, tankx, tanky, tankx2, tanky2, moncongx, moncongy, moncongx2, moncongy2);
    if(GetAsyncKeyState(VK_RIGHT)){
            player_1.key=0;
        if((stage[player_1.posisi.baris[0]][player_1.posisi.kolom[0]+4]==0 || stage[player_1.posisi.baris[0]][player_1.posisi.kolom[0]+4]==4) && (stage[player_1.posisi.baris[1]][player_1.posisi.kolom[1]+1]==0 || stage[player_1.posisi.baris[1]][player_1.posisi.kolom[1]+1]==4) && (stage[player_1.posisi.baris[4]][player_1.posisi.kolom[4]]==0 || stage[player_1.posisi.baris[4]][player_1.posisi.kolom[4]]==4))
        {
            /*Menyimpan kordinat untuk dihapus*/
            player_1.hapus.kordinat.x[0]=player_1.banH.kordinat.x[0];
            player_1.hapus.kordinat.y[0]=player_1.banH.kordinat.y[0];
            player_1.hapus.kordinat.x[1]=player_1.banH.kordinat.x[1];
            player_1.hapus.kordinat.y[1]=player_1.banH.kordinat.y[1];
            /*Menyimpan kordinat untuk dihapus*/
            /*Pengubahan Untuk Kordinat Perpindahan Tank*/
            player_1.kordinat_tank.x[0] += speed;
            player_1.kordinat_tank.x[1] += speed;
            player_1.Moncong.kordinat.x[0] += speed;
            player_1.Moncong.kordinat.x[1] += speed;
            /*Pengubahan Kordinat Perpindahan Badan Tank, Moncong Tank*/
            /*Pengubahan Kordinat Perpindahan Ban*/
            player_1.banH.kordinat.x[0] += speed;
            player_1.banH.kordinat.x[1] +=  speed;
            player_1.banV.kordinat.x[0] += speed;
            player_1.banV.kordinat.x[1] +=  speed;
            /*Pengubahan Kordinat Perpindahan Ban*/
            /*Pengubahan Kordinat Perpindahan Tank pada Array*/
            for(int i=0;i<=5;i++)
            {
                player_1.posisi.kolom[i] +=1;
            }
            /*Pengubahan Kordinat Perpindahan Tank pada Array*/


            HapusTank(player_1); ///PENGHAPUSAN TANK

        }
            /*BAN AGAR TERLIHAT GERAK*/
            int temp = player_1.warna[1];
            player_1.warna[1] = player_1.warna[0];
            player_1.warna[0] = temp;
            /*BAN AGAR TERLIHAT GERAK*/
            Htank(player_1); ///PRINT TANK SETELAH PENGUBAHAN KORDINAT
    }
    else if(GetAsyncKeyState(VK_LEFT))
    {
        player_1.key=1;
        if((stage[player_1.posisi.baris[0]][player_1.posisi.kolom[0]-1]==0 || stage[player_1.posisi.baris[0]][player_1.posisi.kolom[0]-1]==4)&&(stage[player_1.posisi.baris[1]][player_1.posisi.kolom[1]-4]==0 ||stage[player_1.posisi.baris[1]][player_1.posisi.kolom[1]-4]==4)&&(stage[player_1.posisi.baris[4]][player_1.posisi.kolom[4]-5]==0 || stage[player_1.posisi.baris[4]][player_1.posisi.kolom[4]-5]==4))
        {
            /*Menyimpan kordinat untuk dihapus*/
            player_1.hapus.kordinat.x[0]=player_1.banH.kordinat.x[0]+30;
            player_1.hapus.kordinat.y[0]=player_1.banH.kordinat.y[0];
            player_1.hapus.kordinat.x[1]=player_1.banH.kordinat.x[1]+30;
            player_1.hapus.kordinat.y[1]=player_1.banH.kordinat.y[1];
            /*Menyimpan kordinat untuk dihapus*/

            player_1.kordinat_tank.x[0] -= speed;
            player_1.kordinat_tank.x[1] -= speed;
            player_1.Moncong.kordinat.x[0] -= speed;
            player_1.Moncong.kordinat.x[1] -= speed;

            player_1.banH.kordinat.x[0] -= speed;
            player_1.banH.kordinat.x[1] -=  speed;
            player_1.banV.kordinat.x[0] -= speed;
            player_1.banV.kordinat.x[1] -=  speed;


            for(int i=0;i<=5;i++)
            {
                player_1.posisi.kolom[i] -=1;
            }

            HapusTank(player_1);
        }

            Htank(player_1);
            int temp = player_1.warna[1];
            player_1.warna[1] = player_1.warna[0];
            player_1.warna[0] = temp;
    }
    else if(GetAsyncKeyState(VK_UP))
    {
        player_1.key=2;
        if((stage[player_1.posisi.baris[0]-1][player_1.posisi.kolom[0]]==0 || stage[player_1.posisi.baris[0]-1][player_1.posisi.kolom[0]]==4) && (stage[player_1.posisi.baris[1]-4][player_1.posisi.kolom[1]]==0 || stage[player_1.posisi.baris[1]-4][player_1.posisi.kolom[1]]==4) && (stage[player_1.posisi.baris[2]][player_1.posisi.kolom[2]]==0 || stage[player_1.posisi.baris[2]][player_1.posisi.kolom[2]]==4)&& (stage[player_1.posisi.baris[5]-5][player_1.posisi.kolom[5]]==0 || stage[player_1.posisi.baris[5]-5][player_1.posisi.kolom[5]]==4 ))
        {
            /*Menyimpan kordinat untuk dihapus*/
            player_1.hapus.kordinat.x[0]=player_1.banV.kordinat.x[0];
            player_1.hapus.kordinat.x[1]=player_1.banV.kordinat.x[1];
            player_1.hapus.kordinat.y[0]=player_1.banV.kordinat.y[0];
            player_1.hapus.kordinat.y[1]=player_1.banV.kordinat.y[1];
            /*Menyimpan kordinat untuk dihapus*/
            player_1.kordinat_tank.y[0] -= speed;
            player_1.kordinat_tank.y[1] -= speed;
            player_1.Moncong.kordinat.y[0] -= speed;
            player_1.Moncong.kordinat.y[1] -= speed;

            player_1.banH.kordinat.y[0] -= speed;
            player_1.banH.kordinat.y[1] -=  speed;
            player_1.banV.kordinat.y[0] -= speed;
            player_1.banV.kordinat.y[1] -= speed;

            for(int i=0;i<=5;i++)
            {
                player_1.posisi.baris[i] -=1;
            }

        }
        /*BAN AGAR TERLIHAT GERAK*/
        int temp = player_1.warna[1];
        player_1.warna[1] = player_1.warna[0];
        player_1.warna[0] = temp;
        /*BAN AGAR TERLIHAT GERAK*/
        HapusTank(player_1);
        Vtank(player_1); ///PRINT TANK SETELAH PENGUBAHAN KORDINAT
    }
    else if(GetAsyncKeyState(VK_DOWN))
    {
        player_1.key=3;
        if((stage[player_1.posisi.baris[0]+4][player_1.posisi.kolom[0]]==0 || stage[player_1.posisi.baris[0]+4][player_1.posisi.kolom[0]]==4) && (stage[player_1.posisi.baris[1]+1][player_1.posisi.kolom[1]]==0 || stage[player_1.posisi.baris[1]+1][player_1.posisi.kolom[1]]==4)&& (stage[player_1.posisi.baris[2]+4][player_1.posisi.kolom[2]]==0 || stage[player_1.posisi.baris[2]+4][player_1.posisi.kolom[2]]==4 ) && (stage[player_1.posisi.baris[5]][player_1.posisi.kolom[5]]==0 || stage[player_1.posisi.baris[5]][player_1.posisi.kolom[5]]==4 ))
        {
        /*Menyimpan kordinat untuk dihapus*/
        player_1.hapus.kordinat.x[0]=player_1.banV.kordinat.x[0];
        player_1.hapus.kordinat.x[1]=player_1.banV.kordinat.x[1];
        player_1.hapus.kordinat.y[0]=player_1.banV.kordinat.y[0]-30;
        player_1.hapus.kordinat.y[1]=player_1.banV.kordinat.y[1]-30;
        /*Menyimpan kordinat untuk dihapus*/

        player_1.kordinat_tank.y[0] += speed;
        player_1.kordinat_tank.y[1] += speed;
        player_1.Moncong.kordinat.y[0] += speed;
        player_1.Moncong.kordinat.y[1] += speed;

        player_1.banH.kordinat.y[0] += speed;
        player_1.banH.kordinat.y[1] +=  speed;
        player_1.banV.kordinat.y[0] += speed;
        player_1.banV.kordinat.y[1] +=  speed;

        for(int i=0;i<=5;i++)
            {
                player_1.posisi.baris[i] +=1;
            }
        }
        int temp = player_1.warna[1];
        player_1.warna[1] = player_1.warna[0];
        player_1.warna[0] = temp;
        HapusTank(player_1);
        Vtank(player_1);
    }
    if(GetAsyncKeyState(VK_SPACE) && player_1.jml_peluru==0)
    {
        /*ini untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/
        player_1.kordinat_peluru.y[0]=player_1.posisi.baris[3];
        player_1.kordinat_peluru.y[1]=player_1.posisi.baris[4];
        player_1.kordinat_peluru.x[0]=player_1.posisi.kolom[3];
        player_1.kordinat_peluru.x[1]=player_1.posisi.kolom[4];

		player_1.gambar_peluru.x[0]=player_1.Moncong.kordinat.x[0];
        player_1.gambar_peluru.y[0]=player_1.Moncong.kordinat.y[0];
        player_1.jml_peluru=1;

        /*ini untuk nembak tidak bisa gerak*/
        //Tembak(player_1,page);
    }

/*dibawah untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/
    if(player_1.jml_peluru==1)
    {
        int x=2;
            if((stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==0 || stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==2 || stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==4)&&(stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==0 || stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==2 || stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==4))
            {
                //circle(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,4);

                player_1.hapus.kordinat.x[0]=player_1.gambar_peluru.x[0]-14;
                player_1.hapus.kordinat.y[0]=player_1.gambar_peluru.y[0]+1;
                player_1.hapus.kordinat.x[1]=player_1.gambar_peluru.x[0]+8;
                player_1.hapus.kordinat.y[1]=player_1.gambar_peluru.y[0]+9;


                HapusPeluru(player_1);
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,0,360,4);
                player_1.gambar_peluru.x[0]+=10;
            }
            else
            {
                HapusPeluru(player_1);
                player_1.jml_peluru=0;
            }

            player_1.kordinat_peluru.x[0] += 1;
            player_1.kordinat_peluru.x[1] += 1;


            x=3;
            if((stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)|| (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==0 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3) || (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==0)) //buat ngehancurin tembok
                {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                    //temp_stage=stage[pely][pelx];
                    //temp_stage2=stage[pely2][pelx2];
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]-5,player_1.gambar_peluru.x[0]+10,player_1.gambar_peluru.y[0]+15);
                }
                if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==4 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)
                {
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=4;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==4)
                {
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-2]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-2]=4;
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==2 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)
                {
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=2;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==2)
                {
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=2;
                }
                /*Atas Menghancurkan Benda*/
    }
/*diatas untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/


//Harus di LUAR
    //page = 1 - page;//Halaman
    delay(50);
    }
}


void arena(){
    int i=0,j=0;
    int tembok=0,tembok2=0;
    while(i<=MAX-1)
    {
        while(j<=MAX-1)
            {
 //           if(stage[j][i]==1)//tembok
 //           {
 //               setfillstyle(1,4);
 //               bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
 //           }
 //           else if(stage[j][i]==3)//bata
 //           {
 //               setfillstyle(1,12);
//                bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
//            }
            if(stage[j][i]==4)//rumput
            {
                setfillstyle(1,2);
                bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
            }
//            else if(stage[j][i]==5)//besi
//            {
//                setfillstyle(1,7);
//                bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
//            }
            if(stage[j][i]==6)//rumput
            {
                setfillstyle(1,12);
                bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
            }
            j++;
            tembok2 += 10;
            }
    tembok += 10;
    i++;
    j=0;
    tembok2=0;
    }
}

void air()
{
    int i=0,j=0;
    int tembok=0,tembok2=0;
    while(i<=MAX-1)
    {
    if(stage[j][i]==2){
        setfillstyle(1,2);
        bar(0+tembok,0+tembok2,10+tembok,10+tembok2);}
        while(j<=MAX-1)
            {
            j++;
            tembok2 += 10;
            if(stage[j][i]==2)//air
                {
                setfillstyle(1,1);
                bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
                }
            }
    tembok += 10;
    i++;
    j=0;
    tembok2=0;
    }
}

int main()
{   PlaySound("themesong.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);

    POINT cpos;

    initwindow(640,480,"Battle Tank v2.0");

    for(int x=-300;x<121;x+=5)
    {
        setcolor(BLUE);

        settextstyle(1, HORIZ_DIR, 5);
        outtextxy(x, 100, "Battle Tanks");

        delay (1);
    }
    while(1)
    {
    setcolor(WHITE);
    settextstyle(1, HORIZ_DIR, 3);
    outtextxy(200, 170, "Play Game");
    outtextxy(200, 230, "Exit Game");
        GetCursorPos(&cpos);
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if((cpos.x>=200 && cpos.y>=200) && (cpos.x<=375 && cpos.y<=230))
            {
                setcolor(RED);
                outtextxy(200, 170, "Play Game");
                Play_Game();
            }

            if((cpos.x>=200 && cpos.y>=260) && (cpos.x<=375 && cpos.y<=290))
            {
                setcolor(RED);
                outtextxy(200, 230, "Exit Game");

                closegraph();
            }
        }
        delay(100);
    }
    getch();
    closegraph();
}
