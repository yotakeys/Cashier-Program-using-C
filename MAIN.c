#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "command.h"

struct daftarbarang arrbarang[];

int main(){
	char jwb;
	do{
    int bnykdata=copydatabarang(arrbarang);
    system("cls");
    cetakinterface();
    printf("LIST BARANG\n");
    tampillist(arrbarang,bnykdata);
    cetakgaris();
    unsigned long long total=0;
    while(1){
        int kode,banyak;
        printf("Masukkan kode barang   : ");
        scanf("%d",&kode);
        if(kode==0){
            break;
        }
        int index;
        index=search(arrbarang,kode,bnykdata);
        if(!index){
            printf("Kode barang tidak ditemukan\n");
            continue;
        }
        printf("Masukkan banyak barang : ");
        scanf("%d",&arrbarang[index].jumlah);
        total=plus(total,arrbarang[index].harga,arrbarang[index].jumlah);
    }
    cetakgaris();
    printf("Total             : %llu\n",total);
    printf("Uang yang Dibayar : ");
    unsigned long long duit;
    scanf("%d",&duit);
    unsigned long long kembali;
    kembali=duit-total;
    printf("Kembalian         : %llu\n",kembali);
    getchar();
    cetakstruk(arrbarang,bnykdata,total,duit,kembali);
    tambahriwayat(arrbarang,bnykdata,total,duit,kembali);
    printf("Transaksi lain? (y/t) : ");
    scanf("%c",&jwb);
    getchar();
	}while(jwb=='y');
}


