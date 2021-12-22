#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void cetakinterface(){
    printf("===================================================================================\n");
    printf("=                                                                                 =\n");
    printf("=                                   TOKO BOS                                      =\n");
    printf("=                                                                                 =\n");
    printf("===================================================================================\n");
}

void cetakgaris(){
    printf("===================================================================================\n");
}

int plus(unsigned long long total,int harga,int banyak){
    int pluplu;
    pluplu=total+(harga*banyak);
    return pluplu;
}

int copydatabarang(struct daftarbarang arrbarang[]){
    int bnykbarang=1;
    FILE *fp;
    struct daftarbarang client = { 0, "", 0,0,0,0,0};

    if ( ( fp = fopen( "database.dat", "rb" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
        return 0;
    }
    int penanda=0;
      while ( !feof( fp ) ) { 
         fread( &client, sizeof( struct daftarbarang ), 1, fp );
        if(client.id==penanda)continue;
        penanda=client.id;
         if ( client.id != 0 ) {
            arrbarang[bnykbarang].id=client.id;
            strcpy(arrbarang[bnykbarang].nama,client.nama);
            arrbarang[bnykbarang].harga=client.harga;
            arrbarang[bnykbarang].stok=client.stok;
            arrbarang[bnykbarang].modal=client.modal;
            arrbarang[bnykbarang].total=client.total;
            bnykbarang++;
         }
      }
    fclose( fp );
    return bnykbarang;
}

int search(struct daftarbarang arrbarang[],int kode,int bnykbarang){
    int i;
    for(i=1;i<bnykbarang;i++){
        if(arrbarang[i].id==kode){
            return i;
        }
    }
    return 0;
}

void tampillist(struct daftarbarang arrbarang[],int bnykdata){
    int i;
    printf("%-6s|%-20s|%-10s|%-5s\n","ID","Nama Barang", "Harga", "Stok");
    for(i=1;i<bnykdata;i++){
        printf("%-6d|%-20s|%-10llu|%-5d\n",arrbarang[i].id,arrbarang[i].nama,arrbarang[i].harga,arrbarang[i].stok);
    }
}

void cetakstruk(struct daftarbarang arrbarang[],int bnykdata,unsigned long long total,unsigned long long duit,unsigned long long kembali){
    time_t t; 
    time(&t);
	FILE *daftar;
    daftar = fopen("StrukBelanja.txt", "w");
    int i;
    fprintf(daftar,"=========================================================\n");
    fprintf(daftar,"=                                                       =\n");
    fprintf(daftar,"=                      TOKO BOS                         =\n");
    fprintf(daftar,"=                                                       =\n");
    fprintf(daftar,"=========================================================\n");
    fprintf(daftar,"Nama - Jumlah - Harga\n");
    for(i=1;i<bnykdata;i++){
        if(arrbarang[i].jumlah==0)continue;
        fprintf(daftar,"%-20s | %-10llu | %llu\n",arrbarang[i].nama,arrbarang[i].jumlah,arrbarang[i].harga*arrbarang[i].jumlah);
    }
    fprintf(daftar,"=========================================================\n");
    fprintf(daftar,"Total   : %llu\n",total);
    fprintf(daftar,"Uang    : %llu\n",duit);
    fprintf(daftar,"Kembali : %llu\n",kembali);
    fprintf(daftar,"=========================================================\n");
    fprintf(daftar,"Terima Kasih , %s",ctime(&t));
    fclose(daftar);
}

void laporan(struct daftarbarang arrbarang[],int bnykdata){
	FILE *fp;
    struct daftarbarang client = { 0, "", 0,0,0,0,0};

    if ( ( fp = fopen( "database.dat", "rb+" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    }
    int i;
	for(i=1;i<bnykdata;i++){
	if(arrbarang[i].jumlah==0)continue;
	client.harga=arrbarang[i].harga;
    client.stok=arrbarang[i].stok-arrbarang[i].jumlah;
    client.total=arrbarang[i].total+(arrbarang[i].jumlah*arrbarang[i].harga);
    client.jumlah=0;
    client.id=arrbarang[i].id;
    strcpy(client.nama,arrbarang[i].nama);
    client.modal=arrbarang[i].modal;
    fseek( fp, ( client.id - 1 ) * sizeof( struct daftarbarang ), SEEK_SET );         
    fwrite( &client, sizeof( struct daftarbarang ), 1, fp );
    }
    fclose( fp );
}

void plusriwayat(struct daftarbarang arrbarang[],int bnykdata){
	time_t t; 
    time(&t);
    int day,month,year;
    struct tm *local = localtime(&t);
    day = local->tm_mday;  
    month = local->tm_mon + 1;     
    year = local->tm_year + 1900;
	FILE *fp;
    struct riwayat client;

    if ( ( fp = fopen( "RiwayatTransaksi.dat", "ab+" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    }
    int i;
	for(i=1;i<bnykdata;i++){
	if(arrbarang[i].jumlah==0)continue;
	client.id=arrbarang[i].id;
	strcpy(client.nama,arrbarang[i].nama);
	client.jumlah=arrbarang[i].jumlah;
	strcpy(client.time,ctime(&t));
	client.tanggal=day;
	client.bulan=month;
	client.tahun=year;
    fwrite(&client,sizeof(client),1,fp);
      }
    fclose( fp );
}


