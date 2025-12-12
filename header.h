#ifndef HEADER_H
#define HEADER_H

struct Motor {
    char merk[30];
    char tipe[30];
    int tahun;
    float harga_asli;   
    float diskon;        
    float harga_final;   
};


struct Harga {
    char tipe_motor[30];
    int harga;
    float diskon;
};


struct DataPembeli
{
    char nama[50];
    char alamat[100];   
    char noTelp[15];
    char email[50];
};

float harga_setelah_diskon(float harga, float diskon);




#endif
