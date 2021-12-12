#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct daftarbarang{
    int id;
    char nama[20];
    unsigned long long harga;
    unsigned long long modal;
    unsigned long long total;
    int jumlah;
    int stok;
};

struct riwayat{
	int id;
	char nama[20];
	int jumlah;
	char time[30];
	int tanggal;
	int bulan;
	int tahun;
};

void masterbarang(struct daftarbarang arrbarang[],int bnykdata);

void laporankeuangan();

void riwayattransaksi(struct daftarbarang arrbarang[],int bnykdata);

void cetakinterface();

void cetakgaris();

int plus(unsigned long long total,int harga,int banyak);

int copydatabarang(struct daftarbarang arrbarang[]);

int search(struct daftarbarang arrbarang[],int kode,int bnykbarang);

void tampillist(struct daftarbarang arrbarang[],int bnykdata);

void cetakstruk(struct daftarbarang arrbarang[],int bnykdata,unsigned long long total,unsigned long long duit,unsigned long long kembali);

void laporan(struct daftarbarang arrbarang[],int bnykdata);

