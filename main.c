#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

struct daftarbarang arrbarang[];
void kasir();

int main(){
	while(1){
	system("cls");
	int bnykdata=copydatabarang(arrbarang);
	cetakinterface();
	printf("Pilih Menu :\n");
	printf("1. Kasir\n");
	printf("2. Riwayat Transaksi\n");
	printf("3. Master Barang\n");
	printf("4. Laporan Keuangan\n");
	printf("5. Keluar\n");
	int choose;
	printf("Pilih (1/2/3/4/5) : ");
	scanf("%d",&choose);
	if(choose==1){
		kasir(arrbarang,bnykdata);
	}
	else if(choose==2){
		riwayattransaksi(arrbarang,bnykdata);
	}
	else if(choose==3){
		masterbarang(arrbarang,bnykdata);
	}
	else if(choose==4){
		laporankeuangan();
	}
	else if(choose==5){
		exit(0);
	}
	else{
		printf("BRUH\n");
	}
	}
	
}

void kasir(){
	char jwb;
	do{
    system("cls");
    cetakinterface();
    int bnykdata=copydatabarang(arrbarang);
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
        if(arrbarang[index].jumlah>arrbarang[index].stok){
        	printf("Barang Tidak Mencukupi\n");
        	arrbarang[index].jumlah=0;
        	continue;
		}
        total=plus(total,arrbarang[index].harga,arrbarang[index].jumlah);
    }
    cetakgaris();
    printf("Total             : %llu\n",total);
    printf("Uang yang Dibayar : ");
    unsigned long long duit;
    scanf("%llu",&duit);
	long long int kembali;
    kembali=duit-total;
    printf("Kembalian         : %lld\n",kembali);
    getchar();
    cetakstruk(arrbarang,bnykdata,total,duit,kembali);
    laporan(arrbarang,bnykdata);
    plusriwayat(arrbarang,bnykdata);
    printf("Transaksi lain? (y/t) : ");
    scanf("%c",&jwb);
    getchar();
	}while(jwb=='y');
}
