#include <graphics.h>
#include <stdio.h>
#include <iostream>     ///final
#include <windows.h>
#include <mmsystem.h>
#include "Fakhri_header.c"



void Play_Game()
{
    cleardevice();
    TANK player_1,musuh_1,musuh_2,musuh_3;// Membuat data komposit untuk data player 1
	int tambah=1;
    int speed=10;// digunkan Perpindahan tank per 10 pixel

    //POSISI awal ban untuk vertikal

    Set_map(stage);
    Set_player(&player_1);
    Set_enemy_1(&musuh_1);

    int page=0;
    char arr[10];

    //gambar_musuh();//ARENA (print menu di sebelah)
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
        settextstyle(1,0,2);
        setfillstyle(1,7);
        bar(520,205,550,235);
        gambar_musuh();
        gambar_tembok();
        Rumput();
        air();
    //    settextstyle(1,0,2);
    //    bar(530,205,550,235);



    while(1){

        settextstyle(1,0,2);
        outtextxy(557,215,player_1.lfe);
        setcolor(4);
        outtextxy(515,55,player_1.scr);
        outtextxy(557,215,player_1.lfe);

        HapusTank(&player_1);
        HapusTank(&musuh_1);
        if(player_1.key==0 || player_1.key==1 )
        {
            Htank(player_1);
        }
        else if (player_1.key==2 || player_1.key==3)
        {
            Vtank(player_1);
        }
        if(musuh_1.key==0 || musuh_1.key==1 )
        {
            Htank(musuh_1);
        }
        else if (musuh_1.key==2 || musuh_1.key==3)
        {
            Vtank(musuh_1);
        }

    if(GetAsyncKeyState(VK_RIGHT))
    {
        Pindah_kanan(&player_1,speed);
    }
    else if(GetAsyncKeyState(VK_LEFT))
    {
        Pindah_kiri(&player_1,speed);
    }
    else if(GetAsyncKeyState(VK_UP))
    {
        Pindah_atas(&player_1,speed);
    }
    else if(GetAsyncKeyState(VK_DOWN))
    {
        Pindah_bawah(&player_1,speed);
    }
    if(GetAsyncKeyState(115))
    {
        Pindah_bawah(&player_1,speed);
    }

    if(GetAsyncKeyState(VK_SPACE) && player_1.jml_peluru==0)
    {
        /*ini untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/
        if(player_1.key==0)
        {
            player_1.kordinat_peluru.x[0]=player_1.posisi.kolom[3];
            player_1.kordinat_peluru.y[0]=player_1.posisi.baris[1];
            player_1.kordinat_peluru.x[1]=player_1.posisi.kolom[3];
            player_1.kordinat_peluru.y[1]=player_1.posisi.baris[2];
        }
        if(player_1.key==1)
        {
            player_1.kordinat_peluru.x[0]=player_1.posisi.kolom[0];
            player_1.kordinat_peluru.y[0]=player_1.posisi.baris[1];
            player_1.kordinat_peluru.x[1]=player_1.posisi.kolom[0];
            player_1.kordinat_peluru.y[1]=player_1.posisi.baris[2];
        }
        if(player_1.key==2)
        {
            player_1.kordinat_peluru.x[0]=player_1.posisi.kolom[1];
            player_1.kordinat_peluru.y[0]=player_1.posisi.baris[0];
            player_1.kordinat_peluru.x[1]=player_1.posisi.kolom[2];
            player_1.kordinat_peluru.y[1]=player_1.posisi.baris[0];
        }
        if(player_1.key==3)
        {
            player_1.kordinat_peluru.x[0]=player_1.posisi.kolom[1];
            player_1.kordinat_peluru.y[0]=player_1.posisi.baris[3];
            player_1.kordinat_peluru.x[1]=player_1.posisi.kolom[2];
            player_1.kordinat_peluru.y[1]=player_1.posisi.baris[3];
        }

		player_1.gambar_peluru.x[0]=player_1.Moncong.kordinat.x[0];
        player_1.gambar_peluru.y[0]=player_1.Moncong.kordinat.y[0];
        player_1.jml_peluru=1;
        player_1.ktemp=player_1.key;
    }

/*dibawah untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/
    if(player_1.jml_peluru==1)
    {
        if(player_1.ktemp==0)
        {
            if((pp1==0 || pp1==2 || pp1==4) && (pp2==0 || pp2==2 || pp2==4))
            {
                HapusPeluru(player_1);
                player_1.gambar_peluru.x[0]+=100;
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,0,360,4);

            }
            else
            {
                HapusPeluru(player_1);
                player_1.jml_peluru=0;
            }

            player_1.kordinat_peluru.x[0] += 1;
            player_1.kordinat_peluru.x[1] += 1;


            int x=1;

            if((stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3) || (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==0 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3) || (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==0)) //buat ngehancurin tembok
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                ///ini buat tembok jadi semua tembok gbisa di tembak
                //setfillstyle(SOLID_FILL,BLACK);
                //bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]-6,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+16);
            }

            if (stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==4 && stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3)
            {   ///BAWAH RUMPUT, ATAS TEMBOK
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=4;
                //setfillstyle(SOLID_FILL,BLACK);
                //bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]-6,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+6);
            }
            else if (stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3 && stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==4)
            { ///BAWAH TEMBOK, ATAS RUMPUT
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=4;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                //setfillstyle(SOLID_FILL,BLACK);
                //bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+6,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+16);
            }
            else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==2)
            {   ///  BAWAH AIR, ATAS TEMBOK
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=2;
                //setfillstyle(SOLID_FILL,BLACK);
                //bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]-6,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+6);
            }
            else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==2 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)
            {   ///BAWAH TEMBOK, ATAS AIR
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=2;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                //setfillstyle(SOLID_FILL,BLACK);
                //bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+6,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+16);
            }
           else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==5)
            {   ///BAWAH BESI, ATAS TEMBOK
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=5;
                //setfillstyle(SOLID_FILL,BLACK);
                //bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]-6,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+6);
            }
            else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==5 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)
            {   ///BAWAH TEMBOK, ATAS BESI
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=5;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                //setfillstyle(SOLID_FILL,BLACK);
                //bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+6,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+16);
            }
            /*Atas Menghancurkan Benda*/

            if(stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==6 || stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==6)
            {
                player_1.score += 50;
                setcolor(15);
                player_1.life -= 1;                                 ///pengisian score
                sprintf(player_1.scr,"%d",player_1.score);
                if (player_1.life < 1)
                {
                    player_1.life = 0;

                }
                sprintf(player_1.lfe,"%d",player_1.life);

                Tmusuh += 1;
                if(Tmusuh > 4)
                {
                    setfillstyle(1,0);
                    bar(520,205,550,235);
                    bar(450,10,490,60);
                    msh=0;

                }
            }
        }
        if(player_1.ktemp==1)///KIRI
        {
            if((pp1==0 || pp1==2 || pp1==4) && (pp2==0 || pp2==2 || pp2==4))
            {
                HapusPeluru(player_1);
                player_1.gambar_peluru.x[0]-=10;
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,0,360,4);
            }
            else
            {
                HapusPeluru(player_1);
                player_1.jml_peluru=0;
            }
            player_1.kordinat_peluru.x[0] -= 1;
            player_1.kordinat_peluru.x[1] -= 1;

            int x=1;
                if((stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==3)|| (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==0 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==3) || (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==0)) //buat ngehancurin tembok
                {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                    //temp_stage=stage[pely][pelx];
                    //temp_stage2=stage[pely2][pelx2];
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]=0;

                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-21,player_1.gambar_peluru.y[0]-4,player_1.gambar_peluru.x[0]-9,player_1.gambar_peluru.y[0]+16);
                }
                if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==4)
                { ///BAWAH RUMPUT, ATAS TEMBOK
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]=4;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-21,player_1.gambar_peluru.y[0]-4,player_1.gambar_peluru.x[0]-9,player_1.gambar_peluru.y[0]+6);
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==4 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==3)
                {   ///BAWAH TEMBOK, ATAS RUMPUT
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]=4;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]=0;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-21,player_1.gambar_peluru.y[0]+4,player_1.gambar_peluru.x[0]-9,player_1.gambar_peluru.y[0]+16);
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==2)
                {   ///  BAWAH AIR, ATAS TEMBOK
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=2;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-21,player_1.gambar_peluru.y[0]-4,player_1.gambar_peluru.x[0]-9,player_1.gambar_peluru.y[0]+6);
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==2 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)
                {   ///BAWAH TEMBOK, ATAS AIR
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=2;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-21,player_1.gambar_peluru.y[0]+4,player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+16);
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==5)
                {   ///BAWAH BESI, ATAS TEMBOK
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=5;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-21,player_1.gambar_peluru.y[0]-4,player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+6);
                }
                else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==5 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)
                {   ///BAWAH TEMBOK, ATAS BESI
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=5;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-21,player_1.gambar_peluru.y[0]+4,player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+16);
                }
                if((stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==6 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==6)|| (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==0 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==6) || (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]+x]==6 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]+x]==0))
                {
                    player_1.score += 50;
                    player_1.life -= 1;
                    Tmusuh += 1;                               ///pengisian score
                    sprintf(player_1.scr,"%d",player_1.score);          ////////////////////////////////////////lili////////////
                    if (player_1.life < 1)
                    {
                        player_1.life = 0;
                    }
                    sprintf(player_1.lfe,"%d",player_1.life);

                    if(Tmusuh > 4)
                    {
                        setfillstyle(1,0);
                        bar(520,205,550,235);
                        bar(450,10,490,60);
                        msh=0;
                    }
                }
        }
        if(player_1.ktemp==2)
        {
            if((pp1==0 || pp1==2 || pp1==4) && (pp2==0 || pp2==2 || pp2==4))
            {
                //circle(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,4);

                HapusPeluru(player_1);
                player_1.gambar_peluru.y[0]-=10;
                air();
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,0,360,4);

            }
            else
            {
                HapusPeluru(player_1);
                player_1.jml_peluru=0;
            }

                player_1.kordinat_peluru.y[0] -= 1;
                player_1.kordinat_peluru.y[1] -= 1;

            int x=1;
            if((stage[player_1.kordinat_peluru.y[0]+x][player_1.kordinat_peluru.x[0]]==3 && stage[player_1.kordinat_peluru.y[1]+x][player_1.kordinat_peluru.x[1]]==3) || (stage[player_1.kordinat_peluru.y[0]+x][player_1.kordinat_peluru.x[0]]==0 && stage[player_1.kordinat_peluru.y[1]+x][player_1.kordinat_peluru.x[1]]==3) || (stage[player_1.kordinat_peluru.y[0]+x][player_1.kordinat_peluru.x[0]]==3 && stage[player_1.kordinat_peluru.y[1]+x][player_1.kordinat_peluru.x[1]]==0))
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                //temp_stage=stage[pely][pelx];
                //temp_stage2=stage[pely2][pelx2];
                stage[player_1.kordinat_peluru.y[0]+x][player_1.kordinat_peluru.x[0]]=0;
                stage[player_1.kordinat_peluru.y[1]+x][player_1.kordinat_peluru.x[1]]=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(player_1.gambar_peluru.x[0]-10,player_1.gambar_peluru.y[0]-15,player_1.gambar_peluru.x[0]+11,player_1.gambar_peluru.y[0]-4);
            }

/*            if (stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==4 && stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3)
            {   ///BAWAH RUMPUT, ATAS TEMBOK
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=4;
                setfillstyle(SOLID_FILL,BLACK);
                bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]-4,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+6);
            }
            else if (stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3 && stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==4)
            { ///BAWAH TEMBOK, ATAS RUMPUT
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=4;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+4,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+16);
            }
            else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==2)
            {   ///  BAWAH AIR, ATAS TEMBOK
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=2;
                setfillstyle(SOLID_FILL,BLACK);
                bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]-4,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+6);
            }
            else if (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==2 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)
            {   ///BAWAH TEMBOK, ATAS AIR
                stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=2;
                stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(player_1.gambar_peluru.x[0]+9,player_1.gambar_peluru.y[0]+4,player_1.gambar_peluru.x[0]+21,player_1.gambar_peluru.y[0]+16);
            }
                if((stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)|| (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==0 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3) || (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==0)) //buat ngehancurin tembok
                {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                    //temp_stage=stage[pely][pelx];
                    //temp_stage2=stage[pely2][pelx2];
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;

                    sprintf(arr,"%d",player_1.gambar_peluru.x[0]);
                    outtextxy(500,100,arr);
                    sprintf(arr,"%d",player_1.gambar_peluru.y[0]);
                    outtextxy(500,120,arr);
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-20,player_1.gambar_peluru.y[0]-5,player_1.gambar_peluru.x[0]-10,player_1.gambar_peluru.y[0]+15);
                }*/
            }
        if(player_1.ktemp==3)
        {
            int y0=3, y1=1;
            if((pp1==0 || pp1==2 || pp1==4) && (pp2==0 || pp2==2 || pp2==4))
            {
                //circle(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,4);

                HapusPeluru(player_1);
                air();
                player_1.gambar_peluru.y[0]+=10;
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(player_1.gambar_peluru.x[0],player_1.gambar_peluru.y[0]+5,0,360,4);



            }
            else
            {
                HapusPeluru(player_1);
                player_1.jml_peluru=0;
            }

            player_1.kordinat_peluru.y[0] += 1;
            player_1.kordinat_peluru.y[1] += 1;

            /*
            x=3;
            if((stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3)|| (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==0 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==3) || (stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]==3 && stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]==0)) //buat ngehancurin tembok
                {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                    //temp_stage=stage[pely][pelx];
                    //temp_stage2=stage[pely2][pelx2];
                    stage[player_1.kordinat_peluru.y[0]][player_1.kordinat_peluru.x[0]-x]=0;
                    stage[player_1.kordinat_peluru.y[1]][player_1.kordinat_peluru.x[1]-x]=0;

                    sprintf(arr,"%d",player_1.gambar_peluru.x[0]);
                    outtextxy(500,100,arr);
                    sprintf(arr,"%d",player_1.gambar_peluru.y[0]);
                    outtextxy(500,120,arr);
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(player_1.gambar_peluru.x[0]-20,player_1.gambar_peluru.y[0]-5,player_1.gambar_peluru.x[0]-10,player_1.gambar_peluru.y[0]+15);
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
                */
        }
    }
/*diatas untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/
//Harus di LUAR
    Rumput();
    delay(20);
    }
}

int main()
{   PlaySound("song/themesong.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);

    POINT cpos;

    initwindow(640,480,"Battle Tank v2.0");

    readimagefile("pic/mainmenu.bmp",0,0,640,480);

 //       setcolor(BLUE);

 //       settextstyle(1, HORIZ_DIR, 5);
 //       outtextxy(125, 100, "Battle Tanks");



    while(1)
    {
//    setcolor(WHITE);
//    settextstyle(1, HORIZ_DIR, 3);
//    outtextxy(200, 170, "Play Game");
//    outtextxy(200, 230, "Exit Game");
        GetCursorPos(&cpos);

        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if((cpos.x>=10 && cpos.y>=320) && (cpos.x<=230 && cpos.y<=420))
            {
                setfillstyle(1,0);
                bar(0,0,640,480);
                readimagefile("pic/About Us.bmp", 100,0,480,480);
                setcolor(WHITE);
                settextstyle(1, HORIZ_DIR, 5);
                outtextxy(0,0,"x");
            }

            if((cpos.x>=0 && cpos.y>=0) && (cpos.x<=100 && cpos.y<=100))
            {
                closegraph();
                main();
            }

            if((cpos.x>=240 && cpos.y>=320) && (cpos.x<=420 && cpos.y<=420))
            {
                setcolor(RED);
                outtextxy(200, 170, "Play Game");
                Play_Game();
            }

            if((cpos.x>=430 && cpos.y>=320) && (cpos.x<=630 && cpos.y<=420))
            {
                setcolor(RED);
                outtextxy(200, 230, "Exit Game");

                closegraph();
            }
        }
        delay(0);
    }
    getch();
    closegraph();
}
