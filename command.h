#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct daftarbarang{
    int id;
    char nama[20];
    unsigned long long harga;
    int jumlah;
};

void cetakinterface();

void cetakgaris();

int plus(unsigned long long total,int harga,int banyak);

int copydatabarang(struct daftarbarang arrbarang[]);

int search(struct daftarbarang arrbarang[],int kode,int bnykbarang);

void tampillist(struct daftarbarang arrbarang[],int bnykdata);

void cetakstruk(struct daftarbarang arrbarang[],int bnykdata,unsigned long long total,unsigned long long duit,unsigned long long kembali);

void tambahriwayat(struct daftarbarang arrbarang[],int bnykdata,unsigned long long total,unsigned long long duit,unsigned long long kembali);

