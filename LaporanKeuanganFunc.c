#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void laporankeuangan(){
	system("cls");
	cetakinterface();
	unsigned long long modal=0;
	unsigned long long pendapatan=0;
	long long int laba;
	FILE *fp;
    struct daftarbarang client = { 0, "", 0,0,0,0,0};

    if ( ( fp = fopen( "database.dat", "rb+" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    }
     printf( "%-6s|%-16s|%-16s|%-10s|%-16s|%-16s\n", "Id", "Nama Barang","Harga","Stok","Modal","Pendapatan" );
    int penanda=0;
      while ( !feof( fp ) ) { 
         fread( &client, sizeof( struct daftarbarang ), 1, fp );
        if(client.id==penanda)continue;
        penanda=client.id;
         if ( client.id != 0 ) {
         	modal+=client.modal;
         	pendapatan+=client.total;
            printf( "%-6d|%-16s|%-16llu|%-10d|%-16llu|%-16llu\n", client.id, client.nama,client.harga,client.stok,client.modal,client.total );
         }
      }
    fclose( fp );
    cetakgaris();
    printf("Modal /Pengeluaran \t: %llu\n",modal);
    printf("Pemasukan \t\t: %llu\n", pendapatan);
    laba=pendapatan-modal;
    printf("~ Keuangan ~\n");
    if(laba<0){
    	printf("Rugi \t\t\t: %lld\n",laba*-1);
	}
    else{
    	printf("Untung \t\t\t: %lld\n",laba);
	}
    getchar();
    printf("Press Enter to back");
    getchar();
}
