
#include "header.h"

void Game_Over()
{
    cleardevice();
    setcolor(WHITE);
    outtextxy(170,220,"GAME OVER CUY!!");
}
void gambar_tembok()
{
    int i, j, x,y;
	boolean resmi=true;
    for(i=0;i<MAX; i++) ///pingir
    {
        for(j=0;j<MAX; j++) ///samping
        {
            if(all_stage[j][i].objekprint==1)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/batas.bmp",x,y,x+10,y+10);
            }

            if (all_stage[j][i].objekprint==3)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/tembok.bmp",x,y,x+10,y+10);
            }
             if (all_stage[j][i].objekprint==5)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/besi.bmp",x,y,x+10,y+10);
            }
            if (all_stage[j][i].objekprint==11 && resmi)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/garuda.bmp",x,y,x+40,y+40);
                resmi=false;
            }

        }
    }
}

void gambar_musuh()
{

    int i, j, x,y;

    for(i=0;i<MAX; i++)
    {
        for(j=0;j<MAX; j++)
        {
            if (all_stage[j][i].objekprint==20)
            {
                x=i*10;
                y=j*10;
                readimagefile("garuda.bmp",x,y,x+10,y+10);
            }
        }
    }
}
void HapusTank(TANK *tank)
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(tank->hapus.kordinat.x[0],tank->hapus.kordinat.y[0],tank->hapus.kordinat.x[1],tank->hapus.kordinat.y[1]);
}

void HapusPeluru(TANK tank)
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    pieslice(tank.gambar_peluru.x[0],tank.gambar_peluru.y[0],0,360,5);
}
void Vtank(TANK *s_tank)
{
    setfillstyle(SOLID_FILL,s_tank->warna[0]);
    bar(s_tank->banV.kordinat.x[0],s_tank->banV.kordinat.y[0],s_tank->banV.kordinat.x[1],s_tank->banV.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank->warna[1]);
    bar(s_tank->banV.kordinat.x[0],s_tank->banV.kordinat.y[0]-10,s_tank->banV.kordinat.x[1],s_tank->banV.kordinat.y[1]-10);
    setfillstyle(SOLID_FILL,s_tank->warna[0]);
    bar(s_tank->banV.kordinat.x[0],s_tank->banV.kordinat.y[0]-20,s_tank->banV.kordinat.x[1],s_tank->banV.kordinat.y[1]-20);
    setfillstyle(SOLID_FILL,s_tank->warna[1]);
    bar(s_tank->banV.kordinat.x[0],s_tank->banV.kordinat.y[0]-30,s_tank->banV.kordinat.x[1],s_tank->banV.kordinat.y[1]-30);

    setfillstyle(SOLID_FILL,0);
    bar (s_tank->kordinat_tank.x[0]+5,s_tank->kordinat_tank.y[0]-10,s_tank->kordinat_tank.x[1]-5,s_tank->kordinat_tank.y[1]+10);

    setfillstyle(1,6);
    bar(s_tank->kordinat_tank.x[0]+5,s_tank->kordinat_tank.y[0]-5,s_tank->kordinat_tank.x[1]-5,s_tank->kordinat_tank.y[1]);

    setfillstyle(1,15);
    pieslice(s_tank->Moncong.kordinat.x[0],s_tank->Moncong.kordinat.y[0]+5,0,360,8);

    if(s_tank->key==2)
    {
        setfillstyle(1,4);
        bar(s_tank->Moncong.kordinat.x[0]-5,s_tank->Moncong.kordinat.y[0]-15,s_tank->Moncong.kordinat.x[1]-15,s_tank->Moncong.kordinat.y[1]-5);
    }
    else if(s_tank->key==3)
    {
        setfillstyle(1,4);
        bar(s_tank->Moncong.kordinat.x[0]-5,s_tank->Moncong.kordinat.y[0]+5,s_tank->Moncong.kordinat.x[1]-15,s_tank->Moncong.kordinat.y[1]+15);
    }
}

void Htank(TANK *s_tank)
{
    setfillstyle(SOLID_FILL,s_tank->warna[0]);
    bar(s_tank->banH.kordinat.x[0],s_tank->banH.kordinat.y[0],s_tank->banH.kordinat.x[1],s_tank->banH.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank->warna[1]);
    bar(s_tank->banH.kordinat.x[0]+10,s_tank->banH.kordinat.y[0],s_tank->banH.kordinat.x[1]+10,s_tank->banH.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank->warna[0]);
    bar(s_tank->banH.kordinat.x[0]+20,s_tank->banH.kordinat.y[0],s_tank->banH.kordinat.x[1]+20,s_tank->banH.kordinat.y[1]);
    setfillstyle(SOLID_FILL,s_tank->warna[1]);
    bar(s_tank->banH.kordinat.x[0]+30,s_tank->banH.kordinat.y[0],s_tank->banH.kordinat.x[1]+30,s_tank->banH.kordinat.y[1]);

    setfillstyle(SOLID_FILL,0);
    bar (s_tank->kordinat_tank.x[0]-5,s_tank->kordinat_tank.y[0],s_tank->kordinat_tank.x[1]+5,s_tank->kordinat_tank.y[1]);

    setfillstyle(1,6);
    bar(s_tank->kordinat_tank.x[0],s_tank->kordinat_tank.y[0],s_tank->kordinat_tank.x[1],s_tank->kordinat_tank.y[1]);

    setfillstyle(1,15);
    pieslice(s_tank->Moncong.kordinat.x[0],s_tank->Moncong.kordinat.y[0]+5,0,360,8);

    if(s_tank->key==0)
    {
        setfillstyle(1,4);
        bar(s_tank->Moncong.kordinat.x[0],s_tank->Moncong.kordinat.y[0],s_tank->Moncong.kordinat.x[1],s_tank->Moncong.kordinat.y[1]);
    }
    else if(s_tank->key==1)
    {
        setfillstyle(1,4);
        bar(s_tank->Moncong.kordinat.x[0]-20,s_tank->Moncong.kordinat.y[0],s_tank->Moncong.kordinat.x[1]-20,s_tank->Moncong.kordinat.y[1]);
    }
}

void Set_player(TANK *tank)
{
    tank->banV.kordinat.x[0]=170;//0 Karena c mulai dari 0
    tank->banV.kordinat.x[1]=210;
    tank->banV.kordinat.y[0]=450;
    tank->banV.kordinat.y[1]=460;
    //POSISI awal ban untuk horizontal
    tank->banH.kordinat.x[0]=170;
    tank->banH.kordinat.x[1]=180;
    tank->banH.kordinat.y[0]=420;
    tank->banH.kordinat.y[1]=460;
    //POSISI awal moncong
    tank->Moncong.kordinat.x[0]=190;
    tank->Moncong.kordinat.x[1]=210;
    tank->Moncong.kordinat.y[0]=435;
    tank->Moncong.kordinat.y[1]=445;
    //Posisi awal Tank
    tank->kordinat_tank.x[0]=175;
    tank->kordinat_tank.x[1]=205;
    tank->kordinat_tank.y[0]=430;
    tank->kordinat_tank.y[1]=450;
    //Posisi Tank pada array
    tank->posisi.baris[0]=42, tank->posisi.kolom[0]=17;
    tank->posisi.baris[1]=43, tank->posisi.kolom[1]=18;
    tank->posisi.baris[2]=44, tank->posisi.kolom[2]=19;
    tank->posisi.baris[3]=45, tank->posisi.kolom[3]=20;
//    tank->posisi.baris[4]=43, tank->posisi.kolom[4]=21;
//    tank->posisi.baris[5]=46, tank->posisi.kolom[5]=19;
    ///Warna ban
    tank->warna[0] = 10, tank->warna[1]=2;
    ///Posisi tank kanan=0 kiri=1 atas=2 bawah=3
    tank->key=2;
    //
}

void Set_enemy_1(TANK *tank)
{
    tank->banV.kordinat.x[0]=450;//0 Karena c mulai dari 0
    tank->banV.kordinat.x[1]=490;
    tank->banV.kordinat.y[0]=40;
    tank->banV.kordinat.y[1]=50;
    //POSISI awal ban untuk horizontal
    tank->banH.kordinat.x[0]=450;
    tank->banH.kordinat.x[1]=460;
    tank->banH.kordinat.y[0]=10;
    tank->banH.kordinat.y[1]=50;
    //POSISI awal moncong
    tank->Moncong.kordinat.x[0]=470;
    tank->Moncong.kordinat.x[1]=490;
    tank->Moncong.kordinat.y[0]=25;
    tank->Moncong.kordinat.y[1]=35;
    //Posisi awal Tank
    tank->kordinat_tank.x[0]=455;
    tank->kordinat_tank.x[1]=485;
    tank->kordinat_tank.y[0]=20;
    tank->kordinat_tank.y[1]=40;
    //Posisi Tank pada array
    tank->posisi.baris[0]=1, tank->posisi.kolom[0]=45;
    tank->posisi.baris[1]=2, tank->posisi.kolom[1]=46;
    tank->posisi.baris[2]=3, tank->posisi.kolom[2]=47;
    tank->posisi.baris[3]=4, tank->posisi.kolom[3]=48;
//    tank->posisi.baris[4]=43, tank->posisi.kolom[4]=21;
//    tank->posisi.baris[5]=46, tank->posisi.kolom[5]=19;
    ///Warna ban
    tank->warna[0] = 4, tank->warna[1]=14;
    ///Posisi tank kanan=0 kiri=1 atas=2 bawah=3
    tank->key=1;
    //
}

void Set_enemy_2(TANK *tank)
{
    tank->banV.kordinat.x[0]=230;//0 Karena c mulai dari 0
    tank->banV.kordinat.x[1]=270;
    tank->banV.kordinat.y[0]=40;
    tank->banV.kordinat.y[1]=50;
    //POSISI awal ban untuk horizontal
    tank->banH.kordinat.x[0]=230;
    tank->banH.kordinat.x[1]=240;
    tank->banH.kordinat.y[0]=10;
    tank->banH.kordinat.y[1]=50;
    //POSISI awal moncong
    tank->Moncong.kordinat.x[0]=250;
    tank->Moncong.kordinat.x[1]=270;
    tank->Moncong.kordinat.y[0]=25;
    tank->Moncong.kordinat.y[1]=35;
    //Posisi awal Tank
    tank->kordinat_tank.x[0]=235;
    tank->kordinat_tank.x[1]=265;
    tank->kordinat_tank.y[0]=20;
    tank->kordinat_tank.y[1]=40;
    //Posisi Tank pada array
    tank->posisi.baris[0]=1, tank->posisi.kolom[0]=23;
    tank->posisi.baris[1]=2, tank->posisi.kolom[1]=24;
    tank->posisi.baris[2]=3, tank->posisi.kolom[2]=25;
    tank->posisi.baris[3]=4, tank->posisi.kolom[3]=26;
//    tank->posisi.baris[4]=43, tank->posisi.kolom[4]=21;
//    tank->posisi.baris[5]=46, tank->posisi.kolom[5]=19;
    ///Warna ban
    tank->warna[0] = 4, tank->warna[1]=14;
    ///Posisi tank kanan=0 kiri=1 atas=2 bawah=3
    tank->key=3;
    //
}

void Set_enemy_3(TANK *tank)
{
    tank->banV.kordinat.x[0]=10;//0 Karena c mulai dari 0
    tank->banV.kordinat.x[1]=50;
    tank->banV.kordinat.y[0]=40;
    tank->banV.kordinat.y[1]=50;
    //POSISI awal ban untuk horizontal
    tank->banH.kordinat.x[0]=10;
    tank->banH.kordinat.x[1]=20;
    tank->banH.kordinat.y[0]=10;
    tank->banH.kordinat.y[1]=50;
    //POSISI awal moncong
    tank->Moncong.kordinat.x[0]=30;
    tank->Moncong.kordinat.x[1]=50;
    tank->Moncong.kordinat.y[0]=25;
    tank->Moncong.kordinat.y[1]=35;
    //Posisi awal Tank
    tank->kordinat_tank.x[0]=15;
    tank->kordinat_tank.x[1]=45;
    tank->kordinat_tank.y[0]=20;
    tank->kordinat_tank.y[1]=40;
    //Posisi Tank pada array
    tank->posisi.baris[0]=1, tank->posisi.kolom[0]=1;
    tank->posisi.baris[1]=2, tank->posisi.kolom[1]=2;
    tank->posisi.baris[2]=3, tank->posisi.kolom[2]=3;
    tank->posisi.baris[3]=4, tank->posisi.kolom[3]=4;
//    tank->posisi.baris[4]=43, tank->posisi.kolom[4]=21;
//    tank->posisi.baris[5]=46, tank->posisi.kolom[5]=19;
    ///Warna ban
    tank->warna[0] = 4, tank->warna[1]=14;
    ///Posisi tank kanan=0 kiri=1 atas=2 bawah=3
    tank->key=3;
    //
}

void Rumput()
{
    int i=0,j=0;
    int tembok=0,tembok2=0;
    while(i<=MAX-1)
    {
    if(all_stage[j][i].objektimpa==4){
        setfillstyle(1,2);
        bar(0+tembok,0+tembok2,10+tembok,10+tembok2);}
        while(j<=MAX-1)
            {
            j++;
            tembok2 += 10;
            if(all_stage[j][i].objektimpa==4) ///RUMPUT
                {
                setfillstyle(1,2);
                bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
                }
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
    if(all_stage[j][i].objektimpa==2){
        setfillstyle(1,2);
        bar(0+tembok,0+tembok2,10+tembok,10+tembok2);}
        while(j<=MAX-1)
            {
            j++;
            tembok2 += 10;
            if(all_stage[j][i].objektimpa==2)//air
                {
                setfillstyle(1,9);
                bar(0+tembok,0+tembok2,10+tembok,10+tembok2);
                }
            }
    tembok += 10;
    i++;
    j=0;
    tembok2=0;
    }
}

void Gerak_kanan(TANK *tank, int speed)
{
    tank->key=0;
        if((p5(*tank)==0 || p5(*tank)==4) && (p6(*tank)==0 || p6(*tank)==4) && (p7(*tank)==0 || p7(*tank)==4) && (p8(*tank)==0 || p8(*tank)==4) && (ot5(*tank)==0 || ot5(*tank)==4) && (ot6(*tank)==0 || ot6(*tank)==4)&& (ot7(*tank)==0 || ot7(*tank)==4) && (ot8(*tank)==0 || ot8(*tank)==4))
        {
            /*Menyimpan kordinat untuk dihapus*/
            tank->hapus.kordinat.x[0]=tank->banH.kordinat.x[0];
            tank->hapus.kordinat.y[0]=tank->banH.kordinat.y[0];
            tank->hapus.kordinat.x[1]=tank->banH.kordinat.x[1];
            tank->hapus.kordinat.y[1]=tank->banH.kordinat.y[1];
            /*Menyimpan kordinat untuk dihapus*/
            /*Pengubahan Untuk Kordinat Perpindahan Tank*/
            tank->kordinat_tank.x[0] += speed;
            tank->kordinat_tank.x[1] += speed;
            tank->Moncong.kordinat.x[0] += speed;
            tank->Moncong.kordinat.x[1] += speed;
            /*Pengubahan Kordinat Perpindahan Badan Tank, Moncong Tank*/
            /*Pengubahan Kordinat Perpindahan Ban*/
            tank->banH.kordinat.x[0] += speed;
            tank->banH.kordinat.x[1] +=  speed;
            tank->banV.kordinat.x[0] += speed;
            tank->banV.kordinat.x[1] +=  speed;
            /*Pengubahan Kordinat Perpindahan Ban*/

            PindahObjek6(&(*tank));

            /*Pengubahan Kordinat Perpindahan Tank pada Array*/
            for(int i=0;i<=3;i++)
            {
                tank->posisi.kolom[i] +=1;
            }
            /*Pengubahan Kordinat Perpindahan Tank pada Array*/
            HapusTank(&(*tank));
        }
        /*BAN AGAR TERLIHAT GERAK*/
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;
        /*BAN AGAR TERLIHAT GERAK*/
        Htank(&(*tank));
}

void Gerak_kiri(TANK *tank, int speed)
{
/*Procedure untuk tank geser ke kiri*/
    tank->key=1;
        if((p13(*tank)==0 || p13(*tank)==4) && (p14(*tank)==0 || p14(*tank)==4) && (p15(*tank)==0 || p15(*tank)==4) && (p16(*tank)==0 || p16(*tank)==4)&& (ot13(*tank)==0 || ot13(*tank)==4) && (ot14(*tank)==0 || ot14(*tank)==4)&& (ot15(*tank)==0 || ot15(*tank)==4) && (ot16(*tank)==0 || ot16(*tank)==4))
        {
            /*Menyimpan kordinat untuk dihapus*/
            tank->hapus.kordinat.x[0]=tank->banH.kordinat.x[0]+30;
            tank->hapus.kordinat.y[0]=tank->banH.kordinat.y[0];
            tank->hapus.kordinat.x[1]=tank->banH.kordinat.x[1]+30;
            tank->hapus.kordinat.y[1]=tank->banH.kordinat.y[1];
            /*Menyimpan kordinat untuk dihapus*/
            tank->kordinat_tank.x[0] -= speed;
            tank->kordinat_tank.x[1] -= speed;
            tank->Moncong.kordinat.x[0] -= speed;
            tank->Moncong.kordinat.x[1] -= speed;

            tank->banH.kordinat.x[0] -= speed;
            tank->banH.kordinat.x[1] -=  speed;
            tank->banV.kordinat.x[0] -= speed;
            tank->banV.kordinat.x[1] -=  speed;

            PindahObjek6(&(*tank));

            for(int i=0;i<=3;i++)
            {
                tank->posisi.kolom[i] -=1;
            }
            HapusTank(&(*tank));
        }
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;
        Htank(&(*tank));
}

void Gerak_atas(TANK *tank, int speed)
{
    tank->key=2;
        if((p1(*tank)==0 || p1(*tank)==4) && (p2(*tank)==0 || p2(*tank)==4) && (p3(*tank)==0 || p3(*tank)==4) && (p4(*tank)==0 || p4(*tank)==4) && (ot1(*tank)==0 || ot1(*tank)==4) && (ot2(*tank)==0 || ot2(*tank)==4)&& (ot3(*tank)==0 || ot3(*tank)==4) && (ot4(*tank)==0 || ot4(*tank)==4))
        {
            /*Menyimpan kordinat untuk dihapus*/
            tank->hapus.kordinat.x[0]=tank->banV.kordinat.x[0];
            tank->hapus.kordinat.x[1]=tank->banV.kordinat.x[1];
            tank->hapus.kordinat.y[0]=tank->banV.kordinat.y[0];
            tank->hapus.kordinat.y[1]=tank->banV.kordinat.y[1];
            /*Menyimpan kordinat untuk dihapus*/
            tank->kordinat_tank.y[0] -= speed;
            tank->kordinat_tank.y[1] -= speed;
            tank->Moncong.kordinat.y[0] -= speed;
            tank->Moncong.kordinat.y[1] -= speed;

            tank->banH.kordinat.y[0] -= speed;
            tank->banH.kordinat.y[1] -=  speed;
            tank->banV.kordinat.y[0] -= speed;
            tank->banV.kordinat.y[1] -= speed;

            PindahObjek6(&(*tank));

            for(int i=0;i<=3;i++)
            {
                tank->posisi.baris[i] -=1;
            }
            HapusTank(&(*tank));
        }
        /*BAN AGAR TERLIHAT GERAK*/
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;
        Vtank(&(*tank));
        /*BAN AGAR TERLIHAT GERAK*/
}

void Gerak_bawah(TANK *tank, int speed)
{
    tank->key=3;
        if((p9(*tank)==0 || p9(*tank)==4) && (p10(*tank)==0 || p10(*tank)==4) && (p11(*tank)==0 || p11(*tank)==4) && (p12(*tank)==0 || p12(*tank)==4 )&& (ot9(*tank)==0 || ot9(*tank)==4) && (ot10(*tank)==0 || ot10(*tank)==4)&& (ot11(*tank)==0 || ot11(*tank)==4) && (ot12(*tank)==0 || ot12(*tank)==4))
        {
            /*Menyimpan kordinat untuk dihapus*/
            tank->hapus.kordinat.x[0]=tank->banV.kordinat.x[0];
            tank->hapus.kordinat.x[1]=tank->banV.kordinat.x[1];
            tank->hapus.kordinat.y[0]=tank->banV.kordinat.y[0]-30;
            tank->hapus.kordinat.y[1]=tank->banV.kordinat.y[1]-30;
            /*Menyimpan kordinat untuk dihapus*/
            tank->kordinat_tank.y[0] += speed;
            tank->kordinat_tank.y[1] += speed;
            tank->Moncong.kordinat.y[0] += speed;
            tank->Moncong.kordinat.y[1] += speed;

            tank->banH.kordinat.y[0] += speed;
            tank->banH.kordinat.y[1] +=  speed;
            tank->banV.kordinat.y[0] += speed;
            tank->banV.kordinat.y[1] +=  speed;

            PindahObjek6(&(*tank));

            for(int i=0;i<=3;i++)
            {
                tank->posisi.baris[i] +=1;
            }
            HapusTank(&(*tank));
        }
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;
        Vtank(&(*tank));
}

void Set_map(int t_stage[MAX][MAX])
{
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(t_stage[j][i]==0 || t_stage[j][i]==1 || t_stage[j][i]==3 || t_stage[j][i]==4 || t_stage[j][i]==5 || t_stage[j][i]==6 || t_stage[j][i]==7 || t_stage[j][i]==11)
            {
                all_stage[j][i].objekprint=t_stage[j][i];
                all_stage[j][i].objektimpa=0;
            }
            if(t_stage[j][i]==4 || t_stage[j][i]==2)
            {
                all_stage[j][i].objektimpa=t_stage[j][i];
                all_stage[j][i].objekprint=0;
            }
        }
    }
}

void PindahObjek6 (TANK *tank)
{
    int i,j;
    for(i=tank->posisi.baris[0];i<=tank->posisi.baris[3];i++)
    {
        for(j=tank->posisi.kolom[0];j<=tank->posisi.kolom[3];j++)
        {
            if(tank->key==0)
            {
                all_stage[i][j+1].objekprint=6;
                    if(j==tank->posisi.kolom[0])
                    {
                        all_stage[i][j].objekprint=0;
                    }
            }
            else if(tank->key==1)
            {
                all_stage[i][j-1].objekprint=6;
                    if(j==tank->posisi.kolom[3])
                    {
                        all_stage[i][j].objekprint=0;
                    }
            }
            else if(tank->key==2)
            {
                all_stage[i-1][j].objekprint=6;
                    if(i==tank->posisi.baris[3])
                    {
                        all_stage[i][j].objekprint=0;
                    }
            }
            else if(tank->key==3)
            {
                all_stage[i+1][j].objekprint=6;
                    if(i==tank->posisi.baris[0])
                    {
                        all_stage[i][j].objekprint=0;
                    }
            }
        }
    }
}

void tembak(TANK *tank)
{
        if(tank->key==0)
        {
            tank->kordinat_peluru.x[0]=tank->posisi.kolom[3]+1;
            tank->kordinat_peluru.y[0]=tank->posisi.baris[1];
            tank->kordinat_peluru.x[1]=tank->posisi.kolom[3]+1;
            tank->kordinat_peluru.y[1]=tank->posisi.baris[2];

            tank->gambar_peluru.x[0]=tank->Moncong.kordinat.x[0]+10;
            tank->gambar_peluru.y[0]=tank->Moncong.kordinat.y[0]+5;
        }
        if(tank->key==1)
        {
            tank->kordinat_peluru.x[0]=tank->posisi.kolom[0]-1;
            tank->kordinat_peluru.y[0]=tank->posisi.baris[1];
            tank->kordinat_peluru.x[1]=tank->posisi.kolom[0]-1;
            tank->kordinat_peluru.y[1]=tank->posisi.baris[2];

            tank->gambar_peluru.x[0]=tank->Moncong.kordinat.x[0]-10;
            tank->gambar_peluru.y[0]=tank->Moncong.kordinat.y[0]+5;
        }
        if(tank->key==2)/*ATAS*/
        {
            tank->kordinat_peluru.x[0]=tank->posisi.kolom[1];
            tank->kordinat_peluru.y[0]=tank->posisi.baris[0]-1;
            tank->kordinat_peluru.x[1]=tank->posisi.kolom[2];
            tank->kordinat_peluru.y[1]=tank->posisi.baris[0]-1;

            tank->gambar_peluru.x[0]=tank->Moncong.kordinat.x[0];
            tank->gambar_peluru.y[0]=tank->Moncong.kordinat.y[0]-5;
        }
        if(tank->key==3)
        {
            tank->kordinat_peluru.x[0]=tank->posisi.kolom[1];
            tank->kordinat_peluru.y[0]=tank->posisi.baris[3]+1;
            tank->kordinat_peluru.x[1]=tank->posisi.kolom[2];
            tank->kordinat_peluru.y[1]=tank->posisi.baris[3]+1;

            tank->gambar_peluru.x[0]=tank->Moncong.kordinat.x[0];
            tank->gambar_peluru.y[0]=tank->Moncong.kordinat.y[0]+15;
        }
        tank->jml_peluru=1;
        tank->ktemp=tank->key;
}

void Gerak_peluru(TANK *tank, boolean *garuda)
{
    /*Kanan*/
    if(tank->ktemp==0)
        {
            if((pp1(*tank)==0 || pp1(*tank)==2 || oot1(*tank)==4) && (pp2(*tank)==0 || pp2(*tank)==2 || oot2(*tank)==4))
            {
                Rumput();
                HapusPeluru(*tank);
                air();
                tank->gambar_peluru.x[0]+=10;
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(tank->gambar_peluru.x[0],tank->gambar_peluru.y[0],0,360,4);
            }
            else
            {
                HapusPeluru(*tank);
                tank->jml_peluru=0;
            }
            tank->kordinat_peluru.x[0] += 1;
            tank->kordinat_peluru.x[1] += 1;

            int x=1;
            if((all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==3) || ((all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==0 && all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objektimpa==0) && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==3) || (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==3 && (all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==0 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objektimpa==0))) //buat ngehancurin tembok
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]+9,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]+21,tank->gambar_peluru.y[0]+11);
            }
            if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objektimpa==4)
            { ///ATAS TEMBOK, BAWAH RUMPUT
                all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objektimpa=4;
                all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]+9,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]+21,tank->gambar_peluru.y[0]+1);
                printf("Masuk");
            }
            else if (all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==3 && all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objektimpa==4)
            { ///BAWAH TEMBOK, ATAS RUMPUT
                all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objektimpa=4;
                all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]+9,tank->gambar_peluru.y[0]-1,tank->gambar_peluru.x[0]+21,tank->gambar_peluru.y[0]+11);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objektimpa==2)
            {   ///BAWAH air, ATAS TEMBOK
                all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objektimpa=2;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]+9,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]+21,tank->gambar_peluru.y[0]+11);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objektimpa==2 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==3)
            {   ///BAWAH TEMBOK, ATAS air
                all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objektimpa=2;
                all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]+9,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]+21,tank->gambar_peluru.y[0]+11);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==5)
            {   ///BAWAH BESI, ATAS TEMBOK
                all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=5;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]+9,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]+21,tank->gambar_peluru.y[0]);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==5 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==3)
            {   ///BAWAH TEMBOK, ATAS BESI
                all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=5;
                all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]+9,tank->gambar_peluru.y[0]-1,tank->gambar_peluru.x[0]+21,tank->gambar_peluru.y[0]+11);
            }
            /*Atas Menghancurkan Benda*/
			/*
            if(all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==11 || all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==11)
            {
                tank->score += 50;
                setcolor(15);
                tank->life -= 1;                                 ///pengisian score
                sprintf(tank->scr,"%d",tank->score);
                if (tank->life < 1)
                {
                    tank->life = 0;

                }
                sprintf(tank->lfe,"%d",tank->life);

                Tmusuh += 1;
                if(Tmusuh > 4)
                {
                    setfillstyle(1,0);
                    bar(520,205,550,235);
                    bar(450,10,490,60);
                    msh=0;

                }
            }
            */

        }
        /*kiri*/
        if(tank->ktemp==1)
        {
            if((pp1(*tank)==0 || pp1(*tank)==2 || oot1(*tank)==4) && (pp2(*tank)==0 || pp2(*tank)==2 || oot2(*tank)==4))
            {
                HapusPeluru(*tank);
                Rumput();
                air();
                tank->gambar_peluru.x[0]-=10;
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(tank->gambar_peluru.x[0],tank->gambar_peluru.y[0],0,360,4);
            }
            else
            {
                HapusPeluru(*tank);
                tank->jml_peluru=0;
            }
            tank->kordinat_peluru.x[0] -= 1;
            tank->kordinat_peluru.x[1] -= 1;

            int x=1;
                if((all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==3) || ((all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==0 && all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objektimpa==0) && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==3) || (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==3 && (all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==0 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objektimpa==0))) //buat ngehancurin tembok
                {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint=0;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint=0;

                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+11);
                }
                if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objektimpa==4)
                { ///BAWAH RUMPUT, ATAS TEMBOK
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint=0;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objektimpa=4;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+1);
                }
                else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objektimpa==4 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==3)
                {   ///BAWAH TEMBOK, ATAS RUMPUT
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objektimpa=4;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint=0;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-1,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+11);
                }
                else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objektimpa==2)
                {   ///BAWAH air, ATAS TEMBOK
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=0;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objektimpa=2;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+1);
                }
                else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objektimpa==2 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==3)
                {   ///BAWAH TEMBOK, ATAS air
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objektimpa=2;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=0;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-1,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+11);
                }
                else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==5)
                {   ///BAWAH BESI, ATAS TEMBOK
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=0;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=5;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+1);
                }
                else if (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint==5 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint==3)
                {   ///BAWAH TEMBOK, ATAS BESI
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x].objekprint=5;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x].objekprint=0;
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-1,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+11);
                }
                else if((all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==11 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==11)|| (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==0 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==11) || (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==11 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==0))
                {
                    /*Kalau Garuda tertembak Langsung Game Over bukan nambah score yee*/
                	all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint=0;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint=0;
                    /*ini ganti sama animasi/gambar garuda ancur, Saudara PHUU (kordinat di bawah pake udah benar)*/
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-51,tank->gambar_peluru.y[0]-21,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+21);
                    /*ini ganti sama animasi/gambar garuda ancur, Saudara PHUU(kordinat di atas pake udah benar)*/
                    *garuda=false;
                    tank->score += 50;
                    tank->life -= 1;
                    Tmusuh += 1;                               ///pengisian score
                    sprintf(tank->scr,"%d",tank->score);          ////////////////////////////////////////lili////////////
                    if (tank->life < 1)
                    {
                        tank->life = 0;
                    }
                    sprintf(tank->lfe,"%d",tank->life);

                    if(Tmusuh > 4)
                    {
                        setfillstyle(1,0);
                        bar(520,205,550,235);
                        bar(450,10,490,60);
                        msh=0;
                    }
                }
        }
        /*Atas*/
        if(tank->ktemp==2)
        {
            if((pp1(*tank)==0 || pp1(*tank)==2 || oot1(*tank)==4) && (pp2(*tank)==0 || pp2(*tank)==2 || oot2(*tank)==4))
            {
                //circle(tank->gambar_peluru.x[0],tank->gambar_peluru.y[0]+5,4);
                HapusPeluru(*tank);
                Rumput();
                air();
                tank->gambar_peluru.y[0]-=10;
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(tank->gambar_peluru.x[0],tank->gambar_peluru.y[0],0,360,4);

            }
            else
            {
                HapusPeluru(*tank);
                tank->jml_peluru=0;
            }

                tank->kordinat_peluru.y[0] -= 1;
                tank->kordinat_peluru.y[1] -= 1;

            int x=1;
            if((all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint==3) || ((all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint==0 && all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objektimpa==0) && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint==3) || (all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint==3 && (all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint==0 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objektimpa==0)))
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]-21,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]-9);
            }
            if((all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==11 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==11)|| (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==0 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==11) || (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint==11 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint==0))
                {
                	all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]+x].objekprint=0;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]+x].objekprint=0;

                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-21,tank->gambar_peluru.y[0]-11,tank->gambar_peluru.x[0]-9,tank->gambar_peluru.y[0]+11);
                    tank->score += 50;
                    tank->life -= 1;
                    Tmusuh += 1;                               ///pengisian score
                    sprintf(tank->scr,"%d",tank->score);          ////////////////////////////////////////lili////////////
                    if (tank->life < 1)
                    {
                        tank->life = 0;
                    }
                    sprintf(tank->lfe,"%d",tank->life);

                    if(Tmusuh > 4)
                    {
                        setfillstyle(1,0);
                        bar(520,205,550,235);
                        bar(450,10,490,60);
                        msh=0;
                    }
                }

            if (all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objektimpa==4 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint==3)
            {   ///kiri RUMPUT, kanan TEMBOK
                all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objektimpa=4;
                all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-1,tank->gambar_peluru.y[0]-21,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]-9);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objektimpa==4)
            {   ///kanan RUMPUT, kiri TEMBOK
                all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objektimpa=4;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]-21,tank->gambar_peluru.x[0]+1,tank->gambar_peluru.y[0]-9);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint==5 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint==3)
            {   ///kiri besi, kanan TEMBOK
                all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint=5;
                all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objektimpa=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-1,tank->gambar_peluru.y[0]-21,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]-9);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint==5)
            {   ///kanan besi, kiri TEMBOK
                all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint=5;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]-21,tank->gambar_peluru.x[0]+1,tank->gambar_peluru.y[0]-9);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objektimpa==2 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint==3)
            {   ///kiri air, kanan TEMBOK
                all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objektimpa=2;
                all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-1,tank->gambar_peluru.y[0]-21,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]-9);
                air();
            }
            else if (all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objektimpa==2)
            {   ///kanan air, kiri TEMBOK
                all_stage[tank->kordinat_peluru.y[0]+x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]+x][tank->kordinat_peluru.x[1]].objektimpa=2;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]-15,tank->gambar_peluru.x[0]+1,tank->gambar_peluru.y[0]-9);
                air();
            }

                /*if((all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x]==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x]==3)|| (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x]==0 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x]==3) || (all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x]==3 && all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x]==0)) //buat ngehancurin tembok
                {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                    //temp_all_stage=all_stage[pely][pelx];
                    //temp_all_stage2=all_stage[pely2][pelx2];
                    all_stage[tank->kordinat_peluru.y[0]][tank->kordinat_peluru.x[0]-x]=0;
                    all_stage[tank->kordinat_peluru.y[1]][tank->kordinat_peluru.x[1]-x]=0;

                    sprintf(arr,"%d",tank->gambar_peluru.x[0]);
                    outtextxy(500,100,arr);
                    sprintf(arr,"%d",tank->gambar_peluru.y[0]);
                    outtextxy(500,120,arr);
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(tank->gambar_peluru.x[0]-20,tank->gambar_peluru.y[0]-5,tank->gambar_peluru.x[0]-10,tank->gambar_peluru.y[0]+15);
                }*/
            }
        /*Bawah*/
        if(tank->ktemp==3)
        {
            if((pp1(*tank)==0 || pp1(*tank)==2 || oot1(*tank)==4) && (pp2(*tank)==0 || pp2(*tank)==2 || oot2(*tank)==4))
            {
                HapusPeluru(*tank);
                Rumput();
                air();
                tank->gambar_peluru.y[0]+=10;
                setfillstyle(SOLID_FILL,RED);
                setcolor(RED);
                pieslice(tank->gambar_peluru.x[0],tank->gambar_peluru.y[0],0,360,4);
            }
            else
            {
                HapusPeluru(*tank);
                tank->jml_peluru=0;
            }

            tank->kordinat_peluru.y[0] += 1;
            tank->kordinat_peluru.y[1] += 1;

            int x=1;
            if((all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint==3) || ((all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint==0 && all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objektimpa==0) && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint==3) || (all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint==3 && (all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint==0 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objektimpa==0)))
            {   //Tembok & Tembok                                       Kosong & Tembok                                        Kosong & Tembok
                all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]+9,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]+21);
            }
            if (all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objektimpa==4 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint==3)
            {   ///kiri RUMPUT, kanan TEMBOK
                all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objektimpa=4;
                all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-1,tank->gambar_peluru.y[0]+9,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]+21);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objektimpa==4)
            {   ///kanan RUMPUT, kiri TEMBOK
                all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objektimpa=4;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]+9,tank->gambar_peluru.x[0]+1,tank->gambar_peluru.y[0]+21);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint==5 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint==3)
            {   ///kiri besi, kanan TEMBOK
                all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint=5;
                all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-1,tank->gambar_peluru.y[0]+9,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]+21);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint==5)
            {   ///kanan besi, kiri TEMBOK
                all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint=5;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]+9,tank->gambar_peluru.x[0]+1,tank->gambar_peluru.y[0]+21);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objektimpa==2 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint==3)
            {   ///kiri air, kanan TEMBOK
                all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objektimpa=2;
                all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objekprint=0;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-1,tank->gambar_peluru.y[0]+9,tank->gambar_peluru.x[0]+11,tank->gambar_peluru.y[0]+21);
            }
            else if (all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint==3 && all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objektimpa==2)
            {   ///Kiri TEMBOK, Kanan Air
                all_stage[tank->kordinat_peluru.y[0]-x][tank->kordinat_peluru.x[0]].objekprint=0;
                all_stage[tank->kordinat_peluru.y[1]-x][tank->kordinat_peluru.x[1]].objektimpa=2;
                setfillstyle(SOLID_FILL,BLACK);
                bar(tank->gambar_peluru.x[0]-11,tank->gambar_peluru.y[0]+9,tank->gambar_peluru.x[0]+1,tank->gambar_peluru.y[0]+21);
            }
        }
}
