///CEK ATAS
#define p1(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[0]].objekprint
#define p2(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[1]].objekprint
#define p3(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[2]].objekprint
#define p4(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[3]].objekprint
#define ot1(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[0]].objektimpa
#define ot2(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[1]].objektimpa
#define ot3(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[2]].objektimpa
#define ot4(P1) all_stage[(P1).posisi.baris[0]-1][(P1).posisi.kolom[3]].objektimpa
///CEK KANAN
#define p5(P1) all_stage[(P1).posisi.baris[0]][(P1).posisi.kolom[3]+1].objekprint
#define p6(P1) all_stage[(P1).posisi.baris[1]][(P1).posisi.kolom[3]+1].objekprint
#define p7(P1) all_stage[(P1).posisi.baris[2]][(P1).posisi.kolom[3]+1].objekprint
#define p8(P1) all_stage[(P1).posisi.baris[3]][(P1).posisi.kolom[3]+1].objekprint
#define ot5(P1) all_stage[(P1).posisi.baris[0]][(P1).posisi.kolom[3]+1].objektimpa
#define ot6(P1) all_stage[(P1).posisi.baris[1]][(P1).posisi.kolom[3]+1].objektimpa
#define ot7(P1) all_stage[(P1).posisi.baris[2]][(P1).posisi.kolom[3]+1].objektimpa
#define ot8(P1) all_stage[(P1).posisi.baris[3]][(P1).posisi.kolom[3]+1].objektimpa
///CEK BAWAH
#define p9(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[3]].objekprint
#define p10(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[2]].objekprint
#define p11(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[1]].objekprint
#define p12(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[0]].objekprint
#define ot9(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[3]].objektimpa
#define ot10(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[2]].objektimpa
#define ot11(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[1]].objektimpa
#define ot12(P1) all_stage[(P1).posisi.baris[3]+1][(P1).posisi.kolom[0]].objektimpa
///CEK KIRI
#define p13(P1) all_stage[(P1).posisi.baris[0]][(P1).posisi.kolom[0]-1].objekprint
#define p14(P1) all_stage[(P1).posisi.baris[1]][(P1).posisi.kolom[0]-1].objekprint
#define p15(P1) all_stage[(P1).posisi.baris[2]][(P1).posisi.kolom[0]-1].objekprint
#define p16(P1) all_stage[(P1).posisi.baris[3]][(P1).posisi.kolom[0]-1].objekprint
#define ot13(P1) all_stage[(P1).posisi.baris[0]][(P1).posisi.kolom[0]-1].objektimpa
#define ot14(P1) all_stage[(P1).posisi.baris[1]][(P1).posisi.kolom[0]-1].objektimpa
#define ot15(P1) all_stage[(P1).posisi.baris[2]][(P1).posisi.kolom[0]-1].objektimpa
#define ot16(P1) all_stage[(P1).posisi.baris[3]][(P1).posisi.kolom[0]-1].objektimpa

#define pp1(P1) all_stage[(P1).kordinat_peluru.y[0]][(P1).kordinat_peluru.x[0]].objekprint
#define pp2(P1) all_stage[(P1).kordinat_peluru.y[1]][(P1).kordinat_peluru.x[1]].objekprint

#define oot1(P1) all_stage[(P1).kordinat_peluru.y[0]][(P1).kordinat_peluru.x[0]].objektimpa
#define oot2(P1) all_stage[(P1).kordinat_peluru.y[1]][(P1).kordinat_peluru.x[1]].objektimpa

#define MAX 50


int Tmusuh=0;
int msh=6;


struct infoposisi
{
    int baris[4];
    int kolom[4];
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
    int ktemp;
    char scr[5]={'0'};
    int life = 4;
    char lfe[2] = {'4'};
    int warna[2];
    int score=0;
    int jml_peluru=0;
    infokordinat kordinat_peluru;
    infokordinat gambar_peluru;
};

struct PETA
{
    int objekprint;
    int objektimpa;
};

PETA all_stage[MAX][MAX];

int stage1[MAX][MAX] =       {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //0   50 (50x10=500)
                            {1,4,4,4,4,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,1}, //1
                            {1,4,4,4,4,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,1}, //2
                            {1,4,4,4,4,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,1}, //3
                            {1,4,4,4,4,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,1}, //4
                            {1,4,4,4,4,3,3,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,1}, //5
                            {1,4,4,4,4,3,3,0,0,0,0,5,5,5,5,4,4,4,4,4,4,4,4,0,0,0,0,3,3,3,3,4,4,4,4,4,4,4,4,4,3,3,3,3,0,0,0,0,0,1}, //6
                            {1,4,4,4,4,3,3,0,0,0,0,5,5,5,5,4,4,4,4,4,4,4,4,0,0,0,0,3,3,3,3,4,4,4,4,4,4,4,4,4,3,3,3,3,0,0,0,0,0,1}, //7
                            {1,4,4,4,4,3,3,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,3,3,3,3,0,0,0,0,0,1}, //8
                            {1,4,4,4,4,3,3,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,3,3,3,3,0,0,0,0,0,1}, //9
                            {1,4,4,4,4,3,3,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,1}, //10
                            {1,4,4,4,4,3,3,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,1}, //11
                            {1,4,4,4,4,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,1}, //12
                            {1,4,4,4,4,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,1}, //13
                            {1,4,4,4,4,4,4,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,1}, //14
                            {1,4,4,4,4,4,4,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //15
                            {1,4,4,4,4,4,4,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //16
                            {1,4,4,4,4,4,4,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //17
                            {1,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,4,4,4,4,4,4,4,4,5,5,5,5,3,3,3,3,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //18
                            {1,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,4,4,4,4,4,4,4,4,5,5,5,5,3,3,3,3,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //19
                            {1,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,4,4,4,4,4,4,4,4,5,5,5,5,3,3,3,3,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //20
                            {1,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,4,4,4,4,4,4,4,4,5,5,5,5,3,3,3,3,0,0,0,0,0,0,4,4,4,4,4,4,4,4,1}, //21
                            {1,0,0,0,0,0,0,0,0,0,0,5,5,5,5,4,4,4,4,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,2,2,2,2,1}, //22
                            {1,0,0,0,0,0,0,0,0,0,0,5,5,5,5,4,4,4,4,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,2,2,2,2,1}, //23
                            {1,0,0,0,0,0,0,0,0,0,0,5,5,5,5,4,4,4,4,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,2,2,2,2,1}, //24
                            {1,0,0,0,0,0,0,0,0,0,0,5,5,5,5,4,4,4,4,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,2,2,2,2,1}, //25
                            {1,2,2,2,2,3,3,4,4,4,4,5,5,5,5,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,1}, //26
                            {1,2,2,2,2,3,3,4,4,4,4,5,5,5,5,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,1}, //27
                            {1,2,2,2,2,3,3,4,4,4,4,5,5,5,5,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,1}, //28
                            {1,2,2,2,2,3,3,4,4,4,4,5,5,5,5,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,1}, //29
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,1}, //30
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,1}, //31
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,1}, //32
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,1}, //33
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,1}, //34
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,1}, //35
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,1}, //36
                            {1,2,2,2,2,3,3,0,0,0,0,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,1}, //37
                            {1,2,2,2,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //38
                            {1,2,2,2,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //39
                            {1,2,2,2,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //40
                            {1,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //41
                            {1,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,6,6,6,6,5,5,7,7,7,7,5,5,0,0,0,0,0,0,0,3,3,0,0,0,0,3,3,0,0,0,0,0,1}, //42
                            {1,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,6,6,6,6,5,5,7,7,7,7,5,5,0,0,0,0,0,0,0,3,3,0,0,0,0,3,3,0,0,0,0,0,1}, //43
                            {1,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,6,6,6,6,5,5,7,7,7,7,5,5,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,1}, //44
                            {1,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,6,6,6,6,5,5,7,7,7,7,5,5,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,1}, //45
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};//46

void gambar_musuh();
//Print Arena
void gambar_tembok();
//print gambar tembok
void air();
//Print Arena khusus Air
void Hapus();
//Untuk Menghapus Tank sebelumnya (blm dipergunakan)
void Vtank(TANK s_tank);
//Untuk Menampilkan Tank dengan posisi Vertikal pada Layar(BGI)
void Htank(TANK s_tank);
//Untuk Menampilkan Tank dengan posisi Horizontal pada Layar(BGI)
void Play_Game();
//Menu pada saat permainan Mulai
void Rumput();
//Print Hutan
void PindahObjek6 (TANK *tank);

void tembak (TANK *tank);

void Gerak_peluru (TANK *tank);
