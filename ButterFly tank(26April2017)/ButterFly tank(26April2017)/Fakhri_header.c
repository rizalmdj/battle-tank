
#include "header.h"

void gambar_tembok()
{
    int i, j, x,y;

    for(i=0;i<MAX; i++)
    {
        for(j=0;j<MAX; j++)
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
             if (all_stage[j][i].objekprint==9)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/air.bmp",x,y,x+10,y+10);
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
            if (stage [j][i]==6)
            {
                x=i*10;
                y=j*10;
                readimagefile("pic/null.bmp",x,y,x+10,y+10);
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
    pieslice(tank.gambar_peluru.x[0],tank.gambar_peluru.y[0]+5,0,360,5);
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
    bar(s_tank.kordinat_tank.x[0]+5,s_tank.kordinat_tank.y[0]-5,s_tank.kordinat_tank.x[1]-5,s_tank.kordinat_tank.y[1]);

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
    if(all_stage[j][i].objekprint==2){
        setfillstyle(1,2);
        bar(0+tembok,0+tembok2,10+tembok,10+tembok2);}
        while(j<=MAX-1)
            {
            j++;
            tembok2 += 10;
            if(all_stage[j][i].objekprint==2)//air
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

void Pindah_kanan(TANK *tank, int speed)
{
    tank->key=0;
        if((p5(*tank)==0 || p5(*tank)==4 || p5(*tank)==6) && (p6(*tank)==0 || p6(*tank)==4 || p6(*tank)==6) && (p7(*tank)==0 || p7(*tank)==4 || p7(*tank)==6) && (p8(*tank)==0 || p8(*tank)==4 || p8(*tank)==6))
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
            /*Pengubahan Kordinat Perpindahan Tank pada Array*/
            for(int i=0;i<=3;i++)
            {
                tank->posisi.kolom[i] +=1;
            }
            /*Pengubahan Kordinat Perpindahan Tank pada Array*/
            //HapusTank(&(*tank));
        }
        /*BAN AGAR TERLIHAT GERAK*/
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;
        /*BAN AGAR TERLIHAT GERAK*/
        //Htank(tank_value);
}

void Pindah_kiri(TANK *tank, int speed)
{
/*Procedure untuk tank geser ke kiri*/
    tank->key=1;
        if((p13(*tank)==0 || p13(*tank)==4 || p13(*tank)==6) && (p14(*tank)==0 || p14(*tank)==4 || p14(*tank)==6) && (p15(*tank)==0 || p15(*tank)==4 || p15(*tank)==6) && (p16(*tank)==0 || p16(*tank)==4 || p16(*tank)==6))
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


            for(int i=0;i<=3;i++)
            {
                tank->posisi.kolom[i] -=1;
            }

        }
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;

}

void Pindah_atas(TANK *tank, int speed)
{
    tank->key=2;
        if((p1(*tank)==0 || p1(*tank)==4 || p1(*tank)==6) && (p2(*tank)==0 || p2(*tank)==4 || p2(*tank)==6) && (p3(*tank)==0 || p3(*tank)==4 || p3(*tank)==6) && (p4(*tank)==0 || p4(*tank)==4 || p4(*tank)==6))
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

            for(int i=0;i<=3;i++)
            {
                tank->posisi.baris[i] -=1;
            }
        }
        /*BAN AGAR TERLIHAT GERAK*/
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;
        /*BAN AGAR TERLIHAT GERAK*/
}

void Pindah_bawah(TANK *tank, int speed)
{
    tank->key=3;
        if((p9(*tank)==0 || p9(*tank)==4 || p9(*tank)==6) && (p10(*tank)==0 || p10(*tank)==4 || p10(*tank)==6) && (p11(*tank)==0 || p11(*tank)==4 || p11(*tank)==6) && (p12(*tank)==0 || p12(*tank)==4 || p12(*tank)==6))
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

        for(int i=0;i<=3;i++)
            {
                tank->posisi.baris[i] +=1;
            }
        }
        int temp = tank->warna[1];
        tank->warna[1] = tank->warna[0];
        tank->warna[0] = temp;
}

void Set_map(int t_stage[MAX][MAX])
{
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(t_stage[j][i]==0 || t_stage[j][i]==1 || t_stage[j][i]==3 || t_stage[j][i]==4 || t_stage[j][i]==5 || t_stage[j][i]==6 || t_stage[j][i]==7)
            {
                all_stage[j][i].objekprint=t_stage[j][i];
            }
            if(t_stage[j][i]==4)
            {
                all_stage[j][i].objektimpa=t_stage[j][i];
            }
        }
    }
}
