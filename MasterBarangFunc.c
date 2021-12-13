#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void masterbarang(struct daftarbarang arrbarang[],int bnykdata){
	system("cls");
	cetakinterface();
    FILE *fp;
    struct daftarbarang client = { 0, "", 0,0,0,0,0};

    if ( ( fp = fopen( "database.dat", "rb+" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    }
     printf( "%-6s|%-16s|%-16s|%-10s\n", "Id", "Nama Barang","Harga ","Stok" );
    int penanda=0;
      while ( !feof( fp ) ) { 
         fread( &client, sizeof( struct daftarbarang ), 1, fp );
        if(client.id==penanda)continue;
        penanda=client.id;
         if ( client.id != 0 ) {
            printf( "%-6d|%-16s|%-16llu|%-10d\n", client.id, client.nama,client.harga,client.stok );
         }
      }
    fclose( fp );
	cetakgaris();
    if ( ( fp = fopen( "database.dat", "rb+" ) ) == NULL ) {
        printf( "File could not be opened.\n" );
    }
    while ( 1 ) { 
        char command[7];
        printf("What do you want? (delete/insert/edit/stok/exit): ");
        scanf("%s",command);
        if(strcmp(command,"exit")==0){
            break;
        }
        else if(strcmp(command,"stok")==0){
        	printf( "Enter ID Barang\n? " );
            scanf( "%d", &client.id );
         	printf("Enter Banyak barang, harga total\n?");
            int hargatem;
            unsigned long long stoktem; 
            scanf("%d %lld",&stoktem,&hargatem);
            int i;
			for(i=1;i<bnykdata;i++){ 
			if(client.id==arrbarang[i].id){
				client.modal=arrbarang[i].modal+hargatem;
            	client.stok=arrbarang[i].stok+stoktem;   
            	strcpy(client.nama,arrbarang[i].nama);
            	client.harga=arrbarang[i].harga;
            	client.total=arrbarang[i].total;
            	break;
			}    
        }
        	fseek( fp, ( client.id - 1 ) * sizeof( struct daftarbarang ), SEEK_SET ); 
            fwrite( &client, sizeof( struct daftarbarang ), 1, fp );
		}
        else if(strcmp(command,"insert")==0){
            printf( "Enter ID Barang\n? " );
            scanf( "%d", &client.id );
            printf( "Enter Nama Barang, Harga\n? " );
            scanf( "%s %llu", client.nama, &client.harga );
            client.modal=0;
            client.total=0;
            client.stok=0;

            fseek( fp, ( client.id - 1 ) * sizeof( struct daftarbarang ), SEEK_SET );         
            
            fwrite( &client, sizeof( struct daftarbarang ), 1, fp );
            }
        else if(strcmp(command,"delete")==0){
            printf("Enter ID, to delete\n?");
            scanf("%d",&client.id);
            fseek( fp, ( client.id - 1 ) * sizeof( struct daftarbarang ), SEEK_SET );         
            client.id=0;
            client.harga=0;
            client.modal=0;
            client.total=0;
            client.stok=0;
            strcpy(client.nama,"");
            fwrite( &client, sizeof( struct daftarbarang ), 1, fp );
        }
        else if(strcmp(command,"edit")==0){
            printf("Enter ID, to edit\n?");
            scanf("%d",&client.id);
            int i;
            for(i=1;i<bnykdata;i++){ 
			if(client.id==arrbarang[i].id){
				client.modal=arrbarang[i].modal;
            	client.stok=arrbarang[i].stok; 
            	strcpy(client.nama,arrbarang[i].nama);
            	client.harga=arrbarang[i].harga;
            	client.total=arrbarang[i].total;
            	break;
			}    
        }
            printf("What do you want to edit? (nama/harga) : ");
            char choose[7];
            scanf("%s",choose);
            if(strcmp(choose,"nama")==0){
                printf( "Enter Nama Barang baru\n? " );
                scanf( "%s", client.nama );
            }
            else{
                printf( "Enter Harga Barang baru\n? " );
                scanf( "%llu", &client.harga );
            }        
        	fseek( fp, ( client.id - 1 ) * sizeof( struct daftarbarang ), SEEK_SET ); 
            
            fwrite( &client, sizeof( struct daftarbarang ), 1, fp );
        }
        else{
            printf("There No Such Command\n");
        }
    }
    fclose(fp);
}
