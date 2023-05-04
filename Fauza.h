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

void FSearchBarang(infotype NmFile, infotype NmBarang, infotype *Harga, infotype *Stok);

void Replace(Link root, infotype namabrg, infotype hargabaru, infotype stokbaru);

void InsertLastBrg (address2 *head, address2 *tail, address2 Q);

void InsVLastBrg(address2 *front, address2 *rear, infotype X, infotype Y, infotype Z);

address2 CreateNodeBrg(infotype nmbrg, infotype harga, infotype stok);

address2 SearchNodeBrg (address2 front, infotype X);

void DelFirstBrg (address2 *front, infotype *nmbrg, infotype *harga, infotype *stok);

#endif
