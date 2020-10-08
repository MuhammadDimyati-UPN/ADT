#include <stdio.h>
#include <stdlib.h>

struct DATA {
 int number;
 struct DATA *next;
};

int  cari(struct DATA *pList, int num);
void simpan(struct DATA *pList, int num);
void tampil(struct DATA *pList);
void hapus(struct DATA *pList, int num);

int main(void) {
 int num = 0;
 int i = 1;
 int r = 0;
 struct DATA *pList;
   
 pList = (struct DATA *)malloc(sizeof(struct DATA));
 pList->number = 0;
 pList->next = NULL;
   
 while(i != 0) {
  printf("\n-- Manajamen data NIM Mahasiswa --\n");
  
  printf("1 > Simpan\n");
  printf("2 > Hapus\n");
  printf("3 > Cari\n");
  printf("4 > Tampil\n");
  printf("0 > Exit\n");
  printf("\nPilih menu ? ");
  scanf("%d", &i);

  switch(i) {
   case 0: 
   default:
    printf("Terima Kasih..\n");
    i = 0;
    break;
   case 1:
    printf("== Simpan == \n");
    printf("Masukan NIM : ");
    scanf("%d", &num);
    simpan(pList, num);
    break;
   case 2:
    printf("== Hapus ==\n");
    printf("NIM yang di hapus: ");
    scanf("%d", &num);
    hapus(pList, num);
    break;
     case 3:
    printf("== Cari ==\n");
    printf("Masukan NIM untuk di cari: ");
    scanf("%d", &num);
    if((r = cari(pList, num)) == -1)
     printf("NIM `%d' tidak ditemukan\n", num);
    else
     printf("NIM `%d' barapa di posisi `%d'\n", num, r);
    break;
   case 4:
    printf("== Display =='\n");
    tampil(pList);
    break;
   }
  } 

 free(pList);
 system("pause");
 return(0);
}

void tampil(struct DATA *pList) {
 while(pList->next != NULL) {
  printf("%d \n", pList->number);
  pList = pList->next;
 }

 printf("%d \n", pList->number);
}

void simpan(struct DATA *pList, int num) {
 while(pList->next != NULL)
  pList = pList->next;

 pList->next = (struct DATA *)malloc(sizeof(struct DATA));
 pList->next->number = num;
 pList->next->next = NULL;
}

void hapus(struct DATA *pList, int num) {
 struct DATA *temp;
 temp = (struct DATA *)malloc(sizeof(struct DATA));

 if(pList->number == num) {

  temp = pList->next;
  free(pList);
  pList = temp;
 } else {
  while(pList->next->number != num)
   pList = pList->next;

  temp = pList->next->next;
  free(pList->next);
  pList->next = temp;
 }   
}
int cari(struct DATA *pList, int num) {
 int r = -1;
 int i = 1;

 while(pList->next != NULL) {
  if(pList->next->number == num)
   return i;
  else
   i++;

  pList = pList->next;
 }

 return r;
}

