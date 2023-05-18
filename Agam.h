#ifndef Agam_H
#define Agam_H

#include "header.h"
#include <ctype.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


infotype InputCodeBinary(infotype deskripsi);
infotype Decode(Link root, infotype str);
void InputBarang(Link *root);
infotype sensitiveCase(infotype kata);
float UangKembalian(float totalHarga, float *JumlahUang);
void tampilanKembalian(float Uangkembalian);
void loadingBar(int waktu);
void tampilanFile(char* namaFile);
void selamatDatang();
void teksUserPelanggan();
void teksAdmin();
void sound(char* namaFile);
void CekCode(Link root);
int SearchKodeDecode(infotype binary);


#endif
