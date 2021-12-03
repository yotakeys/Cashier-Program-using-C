#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "command.h"

void cetakinterface(){
    printf("=========================================================\n");
    printf("=                                                       =\n");
    printf("=                      TOKO BOS                         =\n");
    printf("=                                                       =\n");
    printf("=========================================================\n");
}

void cetakgaris(){
    printf("=========================================================\n");
}

int plus(unsigned long long total,int harga,int banyak){
    int pluplu;
    pluplu=total+(harga*banyak);
    return pluplu;
}

int copydatabarang(struct daftarbarang arrbarang[]){
    FILE *daftar;
    daftar = fopen("DaftarBarang.txt", "r");
    int bnykbarang=1;
    char sampah[20];
    fscanf(daftar," %[^\n]",sampah);
    while( ( fscanf(daftar,"%d",&arrbarang[bnykbarang].id) ) != EOF ){
        fscanf(daftar," %s",arrbarang[bnykbarang].nama);
        fscanf(daftar,"%llu",&arrbarang[bnykbarang].harga);
        bnykbarang++;
        arrbarang[bnykbarang].jumlah=0;
    }
    fclose(daftar);
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
    for(i=1;i<bnykdata;i++){
        printf("%-6d | %s\n",arrbarang[i].id,arrbarang[i].nama);
    }
}

void cetakstruk(struct daftarbarang arrbarang[],int bnykdata,unsigned long long total,unsigned long long duit,unsigned long long kembali){
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
    fclose(daftar);
}

void tambahriwayat(struct daftarbarang arrbarang[],int bnykdata,unsigned long long total,unsigned long long duit,unsigned long long kembali){
    FILE *daftar;
    daftar = fopen("RiwayatTransaksi.txt", "a");
    int i;
    for(i=1;i<bnykdata;i++){
        if(arrbarang[i].jumlah==0)continue;
        fprintf(daftar,"%-20s | %-10llu | %llu\n",arrbarang[i].nama,arrbarang[i].jumlah,arrbarang[i].harga*arrbarang[i].jumlah);
    }
    fprintf(daftar,"Total   : %llu\n",total);
    fprintf(daftar,"=========================================================\n");
    fclose(daftar);
}

