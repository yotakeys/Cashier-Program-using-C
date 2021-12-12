#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void riwayattransaksi(struct daftarbarang arrbarang[],int bnykdata){
	int tgl1=0,tgl2=32,bln1=0,bln2=13,thn1=1990,thn2=3000;
	while (1){
	system("cls");
	cetakinterface();
	int i;
    for(i=1;i<bnykdata;i++){
    	arrbarang[i].jumlah=0;
    }
	unsigned long long modal=0;
	unsigned long long pendapatan=0;
	long long int laba;
	FILE *fp;
    struct riwayat client = { 0, "", 0,"",0,0,0};

    if ( ( fp = fopen( "RiwayatTransaksi.dat", "rb" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    }
    printf( "%-6s|%-20s|%-10s|%-25s\n", "Id", "Nama Barang","Jumlah", "waktu");
    int penanda=0;
      while ( !feof( fp ) ) { 
         fread( &client, sizeof( struct riwayat ), 1, fp );
        if(client.id==penanda)continue;
        penanda=client.id;
         if ( client.id != 0 ) {
         	if(client.tanggal<=tgl2&&client.tanggal>=tgl1&&client.bulan<=bln2&&client.bulan>=bln1&&client.tahun<=thn2&&client.tahun>=thn1){
            int i;
            for(i=1;i<bnykdata;i++){
            	if(client.id==arrbarang[i].id){
            		arrbarang[i].jumlah+=client.jumlah;
            		break;
				}
			}
			printf( "%-6d|%-20s|%-10d|%-25s", client.id, client.nama,client.jumlah,client.time);
        }
         }
      }
      cetakgaris();
      printf("Accumulation : \n");
    for(i=1;i<bnykdata;i++){
    	if(arrbarang[i].jumlah!=0){
    		printf( "%-6d|%-20s|%-10d\n", arrbarang[i].id, arrbarang[i].nama,arrbarang[i].jumlah);
		}
    }
    fclose( fp );
    getchar();
    printf("Command (search/exit) : ");
    char command[7];
    scanf("%s",command);
    if(strcmp(command,"exit")==0){
    	break;
	}
	else if(strcmp(command,"search")==0){
		printf("Input awal (dd mm yyyy) : ");
		scanf("%d %d %d",&tgl1,&bln1,&thn1);
		printf("Input akhir (dd mm yyyy) : ");
		scanf("%d %d %d",&tgl2,&bln2,&thn2);
	}
	else{
		printf("Nai");
	}
	}
}
