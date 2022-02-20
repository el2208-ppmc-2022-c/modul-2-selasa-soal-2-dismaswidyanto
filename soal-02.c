/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : -
*Hari dan Tanggal : Selasa, 22 Januari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_ROW 200
#define STRING_SIZE 200

int N; //variabel untuk menyimpan banyak row

/*function declaration*/
void readFile(char *filename, char array[MAX_ROW][STRING_SIZE]); 
void printSubstring(char array[STRING_SIZE],int awal, int akhir);
int cekState(char c);

int main() {
    //inisialisasi variabel
    char filename[20];
    scanf("%s",filename);
    char array[MAX_ROW][STRING_SIZE]; 
    char printed_string[STRING_SIZE];

    int prev_state, curr_state;
    int count,max_count;
    int awal,akhir;
    int length;

    readFile(filename, array);
    for(int i=0;i<N;i++) {
        awal=0;
        akhir=0;
        max_count=-1;
        count=1;
        prev_state=-1;
        length=strlen(array[i]);
        for(int j=0;j<length;j++) {
            curr_state = cekState(array[i][j]);
            if(curr_state==prev_state) {
                count++;
            }
            else{
                if(count>max_count) {
                    max_count=count;
                    akhir=j-1;
                    awal=j-count;
					
                }
                count=1;
            }
            prev_state=curr_state;
        }
        //setelah keluar dari loop, cek lagi
        if(count>max_count) {
            max_count=count;
            akhir=length-1;
            awal=akhir-count+1;
        }
        printSubstring(array[i],awal,akhir);
    }
}

void readFile(char *filename, char array[MAX_ROW][STRING_SIZE]) {

    FILE *fp = fopen(filename, "r");
    char* token;

    //kasus file kosong
    if (fp ==NULL) {
        printf("Error : file tidak ada\n");
        return;    
    }

    char line[20]; // Variabel penyimpan baris dari file sementara  
    char* value; // Token penyimpan string sementara untuk parsing

    //baca banyak testcase
    fgets(line,STRING_SIZE,fp);
    value = strtok(line,",");
    N=atoi(value);

    //baca matriks
    for(int i=0;i<N;i++) {
        fgets(line,STRING_SIZE,fp);
        token=strtok(line,"\n");
        strcpy(array[i],token);
    }
}

int cekState(char c) {
    if(c<=122 && c>=97 ) {return 1;}
    else if(c<=90 && c>=65 ) {return 2;}
    else if(c<=57 && c>=48 ) {return 3;}
	else {return 0;}
}

void printSubstring(char array[STRING_SIZE],int awal,int akhir) {
    for(int j=awal;j<=akhir;j++) {
        printf("%c",array[j]);
    }
    printf("\n");
    return;
}
