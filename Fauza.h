#ifndef Fauza_H
#define Fauza_H

#include "header.h"

Link CreateNodeTree(char huruf, int freq);

address1 CreateLeafRef(Link leaf);

void InsLastLeaf (address1* head, address1* tail, address1 Q);

void InsFirstLeaf (address1* head, address1 Q);

void InsBetweenLeaf (address1* Pcur, address1 Q);

Link Pop (address1* tail);

address1 CreateListOfLeaf (address head);

Link CreateTree (address1 front);

void CekHarga(Link root);

bool SearchBarang(infotype NmFile, infotype NmBarang);

bool SearchSize (infotype NmFile, infotype NmBarang, infotype Size);

void FSearchBarang(infotype NmFile, infotype *kode, infotype NmBarang, infotype size, infotype *Harga, infotype *Stok);

void FSearchKode(infotype NmFile, infotype *kode, infotype NmBarang);

void FSearchKodeBinary(infotype NmFile, infotype Kode, infotype *kodebinary);

void Replace(infotype namabrg, infotype hargabaru, infotype stokbaru);

void InsertLastBrg (address2 *head, address2 *tail, address2 Q);

void InsVLastBrg(address2 *front, address2 *rear,infotype U, infotype V, infotype X, infotype Y, infotype Z);

address2 CreateNodeBrg(infotype kode,infotype nmbrg, infotype size, infotype harga, infotype stok);

address2 SearchNodeBrg (address2 front, infotype X);

void DelFirstBrg (address2 *front, infotype *kode, infotype *nmbrg, infotype *size, infotype *harga, infotype *stok);

infotype BuatKodeBarang (infotype NamaBarang);

void InputFileKodeBarang (infotype KodeBarang, infotype BinaryKodeBarang);

#endif
