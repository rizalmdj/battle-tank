#include <graphics.h>
#include <stdio.h>
#include <iostream>     ///final
#include <windows.h>
#include <mmsystem.h>
#include "Fakhri_header.c" ////percobaan



void Play_Game()
{
    cleardevice();

    TANK player_1,musuh_1,musuh_2,musuh_3;// Membuat data komposit untuk data player 1
	int tambah=1;
    int speed=10;// digunkan Perpindahan tank per 10 pixel

    //POSISI awal ban untuk vertikal

    Set_map(stage1);
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
        gambar_tembok();
        Rumput();
        air();
    //    settextstyle(1,0,2);
    //    bar(530,205,550,235);

        if(player_1.key==0 || player_1.key==1 )
        {
            Htank(&player_1);
        }
        else if (player_1.key==2 || player_1.key==3)
        {
            Vtank(&player_1);
        }
        if(musuh_1.key==0 || musuh_1.key==1 )
        {
            Htank(&musuh_1);
        }
        else if (musuh_1.key==2 || musuh_1.key==3)
        {
            Vtank(&musuh_1);
        }

    while(1){
        settextstyle(1,0,2);
        outtextxy(557,215,player_1.lfe);
        setcolor(4);
        outtextxy(515,55,player_1.scr);
        outtextxy(557,215,player_1.lfe);

        HapusTank(&musuh_1);


    if(GetAsyncKeyState(VK_RIGHT))
    {
        Gerak_kanan(&player_1,speed);
    }
    else if(GetAsyncKeyState(VK_LEFT))
    {
        Gerak_kiri(&player_1,speed);
    }
    else if(GetAsyncKeyState(VK_UP))
    {
        Gerak_atas(&player_1,speed);
    }
    else if(GetAsyncKeyState(VK_DOWN))
    {
        Gerak_bawah(&player_1,speed);
    }

    if(musuh_1.posisi.baris[0]<player_1.posisi.baris[0])
    {
        Gerak_bawah(&musuh_1,speed);
        Rumput();
    }
    else if(musuh_1.posisi.baris[0]>player_1.posisi.baris[0])
    {
        Gerak_atas(&musuh_1,speed);
        Rumput();
    }
    else if(musuh_1.posisi.kolom[0]<player_1.posisi.kolom[0])
    {
        Gerak_kanan(&musuh_1,speed);
        Rumput();
    }
    else if(musuh_1.posisi.kolom[0]>player_1.posisi.kolom[0])
    {
        Gerak_kiri(&musuh_1,speed);
        Rumput();
    }

    if(GetAsyncKeyState(VK_SPACE) && player_1.jml_peluru==0)
    {
        tembak(&player_1);
    }

/*dibawah untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/
    if(player_1.jml_peluru==1)
    {
        Gerak_peluru(&player_1);
    }
/*diatas untuk nembak sambil bisa gerak (masih belum pas perhitungannya)*/
//Harus di LUAR
    delay(30);
    }
}

int main()
{   PlaySound("themesong.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);

    POINT cpos;

    initwindow(640,480,"Battle Tank v2.0");

    readimagefile("mainmenu.bmp",0,0,640,480);

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
            if((cpos.x>=10 && cpos.y>=370) && (cpos.x<=230 && cpos.y<=420))
            {
                setfillstyle(1,0);
                bar(0,0,640,480);
                readimagefile("About Us.bmp", 100,0,480,480);
                setcolor(WHITE);
                settextstyle(1, HORIZ_DIR, 5);
                outtextxy(0,0,"x");
            }

            if((cpos.x>=0 && cpos.y>=0) && (cpos.x<=100 && cpos.y<=100))
            {
                closegraph();
                main();
            }

            if((cpos.x>=240 && cpos.y>=370) && (cpos.x<=420 && cpos.y<=420))
            {
                setcolor(RED);
                outtextxy(200, 170, "Play Game");
                Play_Game();
            }

            if((cpos.x>=430 && cpos.y>=370) && (cpos.x<=630 && cpos.y<=420))
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
