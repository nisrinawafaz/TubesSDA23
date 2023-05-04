#ifndef Agam_H
#define Agam_H

#include "Fauza.h"
#include <ctype.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



infotype InputCodeBinary(infotype deskripsi);
infotype Decode(Link root, infotype str);
void InputBarang(Link root);
infotype sensitiveCase(infotype kata);
double UangKembalian(double totalHarga);
void tampilanKembalian(double Uangkembalian);

#endif
