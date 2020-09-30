#include <stdio.h>
#include <string.h>

typedef char string[256];

typedef struct{
string Tanggal;
string Bulan;
string Tahun;
}rilis;

typedef struct {
string jumlah;
string Nama;
rilis L;
char Kelas[8];
float harga;
}Game;

 

Game InputDataGame (Game M) {

printf(" INPUT DATA GAME \n");
printf("——————————–\n");
printf(" Nama : "); scanf("%[^\n]", &M.Nama);
printf(" Jumlah Kaset : "); scanf("%s", &M.jumlah);
printf(" Tanggal Rilis (Contoh: DD MM YYYY) \n");
printf(" : ");scanf("%s%s%s", &M.L.Tanggal, &M.L.Bulan, &M.L.Tahun);
printf(" Kelas :  (Berat, Sedang, Ringan) \n");
printf(" : "); scanf("%s", &M.Kelas);
printf(" Harga Game : "); scanf("%f", &M.harga);
printf("\n\n\n");

return M;
}

void TampilkanDataGame (Game M) {

 

printf(" DATA MAHASISWA \n");
printf("——————————–\n");
printf(" Nama : %s\n ", M.Nama);
printf(" Jumlah Kaset : %s\n ", M.jumlah);
printf(" Tgl Lahir : %s  %s  %s \n", M.L.Tanggal, M.L.Bulan, M.L.Tahun);
printf(" Kelas : %s\n ", M.Kelas);
printf(" Harga Game : %.3f\n ", M.harga);
printf("\n\n");
}

int main() {
Game M;

M=InputDataGame(M);
TampilkanDataGame(M);

return 0;
}
