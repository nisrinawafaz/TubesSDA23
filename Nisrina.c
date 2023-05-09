#include "header.h"
#include "Fauza.h"
#include "Nisrina.h"
#include "Agam.h"

//market modul
bool loginAdmin(infotype username, infotype password)
{
	infotype usernameAdm;
	usernameAdm = (infotype)malloc(10*sizeof(char));
	usernameAdm = "adminTubes";
	
	infotype passwordAdm;
	passwordAdm = (infotype)malloc(10*sizeof(char));
	passwordAdm = "tubesSDA23";
	
	
	if((strcmp(username, usernameAdm) == 0) && (strcmp(password, passwordAdm) == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void selamat_datang()
{
	puts	("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t     SELAMAT DATANG DI PENGGUNA APLIKASI MINI MARKET");
	puts	("\n\t\t\t\t\t\t\t\t\t\t\t     ^^BELANJA SENANG^^\n\n");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::::::::::::::::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       :::::::@@@@@@::::::::::@@@@@@:::::::");	
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::@@@@::::@@@@::::@@@@::::@@@@::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       :::@@@:::::::::@@::@@:::::::::@@@:::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::@@@::::::::::::@@::::::::::::@@@::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::@@@::::::::::::::::::::::@@@::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::@@@::::::::::::::::::@@@::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::@@@::::::::::::::@@@::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::@@@::::::::::@@@::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::@@@::::::@@@::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::::@@@::@@@::::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       :::::::::::::::::@@:::::::::::::::::");
	puts	("\t\t\t\t\t\t\t\t\t\t       ::::::::::::::::::::::::::::::::::::");
	getche();
}

void loading(char x[100])
{										// ====>  Fitur tampilan loading  <==== //
	int i;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t%s\n\n\t\t\t\t\t\t\t\t       ",x);
	for (i=0; i<=65;i++){
		printf("w",178);
		Sleep(18);
	}
	system("cls");
}


void selection(char *choice, infotype fChoice, infotype sChoice, infotype pertanyaan, infotype kesimpulan)
{
		system("cls");
		printf("%s \n", pertanyaan);
		printf("%s \n", fChoice);
		printf("%s \n", sChoice);
		printf("%s \n", kesimpulan);
		*choice = getche();
}

void inputLogin(infotype *username, infotype *password)
{
	system("cls");
	printf("\n masukkan Username : ");
	scanf("%s", *username);
	printf("\n masukkan password : ");
	scanf("%s", *password);
}

void adminFitur(Link *root)
{
	bool valid;
	char fitur;
	float potongan = 0.07;
	float ppn = 0.10;
	int minimal = 100000;
	float total ;
	float diskon;
	float pajak;
	float total_akhir;
	float uang_kembalian;
	float uang_bayar;
	uang_kembalian = 0;
	infotype username;
	username = (infotype)malloc(20*sizeof(char));
	
	infotype password;
	password = (infotype)malloc(20*sizeof(char));
	
		
	stroller front;
	front = Nil;
	
	stroller rear;
	rear = Nil;
	
	do
	{
		//inputLogin(&username, &password);
		valid = 1;//loginAdmin(username,password);
		if(valid)
		{
			printf("login berhasil");
			
			do
			{
				selection(&fitur, "Input Barang Baru", "Kasir", "Fitur admin : ", "saya akan menggunakan fitur : ");
				if(fitur == '1')
				{
					InputBarang(root);
				}
				else if(fitur == '2')
				{
					pemesanan(&front, &rear, *root);
					system("cls");
					PrintInfokeranjang (front);
					total = total_harga(front);
					diskon = hitung_diskon(total, potongan);
					pajak = hitung_ppn(total, ppn);
					total_akhir = hitung_hasil(total, potongan,  minimal,  pajak);
					output_bayar(total, minimal, pajak, potongan, total_akhir);	
					uang_kembalian = UangKembalian(total_akhir, &uang_bayar);
					tampilanKembalian(uang_kembalian);
					input_struk(front, total, minimal, pajak, potongan, total_akhir, uang_bayar, uang_kembalian);
				}
				else
				{
					printf("fitur yang anda pilih tidak tersedia\n");
					printf("pilih fitur yang sudah tersedia [klik enter]");
					getche();
				}
			}while(fitur !='1' && fitur !='2');
		}
		else
		{
			printf("login gagal");
			printf("masukkan username dan password yang valid [klik enter]");
			getche();
		}	
	}while(!valid);
	
}

void pemesanan(stroller *front, stroller *rear, Link root)
{
	char nStep;
	char pilih;
	bool search;
	infotype KodeCharKodeBarang;
	infotype KodeCharNama;
	infotype KodeCharHarga;
	infotype KodeCharStok;
	infotype KodeCharSize;
	float harga;
	int kuantitas;
	float total;
	int stok;
	infotype KodeBinaryKodeBarang;

	stroller alamatBarang;
	stroller deleteKeranjang;
	
		do
		{
			KodeCharKodeBarang = (infotype) malloc (30*sizeof(char));
			KodeBinaryKodeBarang = (infotype) malloc (30*sizeof(char));
			KodeCharNama = (infotype) malloc (30*sizeof(char));
			KodeCharSize= (infotype) malloc (30*sizeof(char));
			KodeCharHarga = (infotype) malloc (30*sizeof(char));
			KodeCharStok = (infotype) malloc (30*sizeof(char));
			
			do
			{
				KodeBinaryKodeBarang = InputCodeBinary("\n masukkan kode yang tertera pada barang : ");
				FSearchKodeChar("KodeBarang.txt", KodeBinaryKodeBarang, &KodeCharKodeBarang);
				if(KodeCharKodeBarang != Nil)
				{
					FSearchBarang2("NamaBarang.txt", KodeCharKodeBarang, &KodeCharNama, &KodeCharSize, &KodeCharHarga, &KodeCharStok);
					stok = atoi(KodeCharStok);
						if(stok != 0)
						{
							do
							{
								printf("\n masukkan kuantitas barang : ");
								scanf("%d", &kuantitas);
								if(kuantitas == 0 || kuantitas <0)
								{
									printf("\n kuantitas tidak valid, masukkan kuantitas mulai dari 1");
									printf("\n klik [enter]");
									getche();
								}	
								else if( kuantitas> stok)
								{
									printf("\n kuantitas tidak valid, stok hanya tersisa %d", stok);
									printf("\n klik [enter]");
									getche();
								}
							}while(kuantitas == 0 || kuantitas> stok || kuantitas <0);
							FSearchBarang2("NamaBarang.txt", KodeCharKodeBarang, &KodeCharNama, &KodeCharSize, &KodeCharHarga, &KodeCharStok);
							stok = atoi(KodeCharStok);
							stok = stok - kuantitas;
							sprintf(KodeCharStok, "%d", stok);
							harga  = atoi(KodeCharHarga);
							total = harga * kuantitas;
							alamatBarang = SearchKeranjang (*front, KodeCharNama);
							if(alamatBarang != Nil)
							{
								kuantitas = kuantitas + Kuantitas(alamatBarang);
								Kuantitas(alamatBarang) = kuantitas;
								Total(alamatBarang) = harga * kuantitas;
							}
							else
							{
								InsVLastKeranjang(&(*front), &(*rear), KodeCharKodeBarang, KodeCharNama,KodeCharSize, harga, kuantitas, total);
							}
							sprintf(KodeCharHarga, "%d", harga);
							sprintf(KodeCharStok, "%d", stok);
							Replace(KodeCharKodeBarang, KodeCharHarga, KodeCharStok);
							PrintInfokeranjang (*front);
							printf("ketikkan huruf 'H' untuk menghapus barang :  \n");
							nStep = getche();
							if(nStep == 'H' || nStep == 'h')
							{
								deleteKeranjang = SearchKeranjang (*front, KodeCharKodeBarang);
								do{
									printf("\n masukkan kuantitas barang : ");
									scanf("%d", &kuantitas);
								}while(kuantitas > Kuantitas(deleteKeranjang) || kuantitas <0);
								FSearchBarang2("NamaBarang.txt", KodeCharKodeBarang, &KodeCharNama, &KodeCharSize, &KodeCharHarga, &KodeCharStok);
								sprintf(KodeCharStok, "%d", stok);
								stok = atoi(KodeCharStok);
								stok = stok + kuantitas;
								Kuantitas(deleteKeranjang) = Kuantitas(deleteKeranjang) - kuantitas;
								sprintf(KodeCharStok, "%d", stok);
								printf("hai %s", KodeCharStok);
								Replace(KodeCharKodeBarang, KodeCharHarga, KodeCharStok);
								if(Kuantitas(deleteKeranjang) == 0)
								{
									DelKeranjang (front, KodeCharKodeBarang);
								}
								
							}
							printf("Ketikkan huruf 'T' untuk menambah barang : \n");
							nStep = getche();
							printf("hoii %c", nStep);
							if(nStep != 'T' || nStep != 't')
							{
								break;
							}
						}
						else
						{
							printf("\n Kode yang anda masukkan tidak valid karena stok habis : ");
							printf("\n masukkan kode barang yang valid [klik enter] : ");
							getche();
						}
				}else{
					printf("\n Kode yang anda masukkan tidak valid : ");
					printf("\n masukkan kode barang yang valid [klik enter] : ");
					getche();
				}
			}while(KodeCharKodeBarang == Nil || stok == 0);
		}while(nStep == 'T' || nStep == 't');
	
}

void input_struk(stroller data, float total, float minimal, float ppn, float diskon, float hasil, float uang_bayar,float uang_kembalian)
{
	stroller P;
	int i;
	i = 1;
	FILE *kj;
	
	kj=fopen("struk_belanja.txt", "a+");
	if (data != Nil)
	{
		header_struk();
		 P = data;
		 for (;;)
		 {
			if (P == Nil)
			{
				 printf("\n");
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 fprintf(kj, "  %d.\t   %s\t\t   %s\t\t      %g\t    %d\t     %g\t      \n", i, Barang(P), Size(P), Harga(P), Kuantitas(P), Total(P));
			fprintf(kj,"|-------------------------------------------------------------|\n");
				 P = Next(P);
				 i++;
			}
		 }
		fprintf(kj,"PPN 10 persen :                          Rp. %g\n", ppn);
		if(total >= minimal)
		{
			fprintf(kj,"|---------------Selamat anda mendapatkan diskon!--------------|\n");
			fprintf(kj,"  Jumlah pembelanjaan anda lebih dari %g\n",minimal);
			fprintf(kj,"  Jumlah pembayaran : Rp. %g ( Diskon sebesar Rp.%g) \n",hasil, diskon);
			fprintf(kj,"|-------------------------------------------------------------|\n");
			
		}
		else
		{
			fprintf(kj,"  Jumlah pembayaran :                       Rp. %g \n",hasil);
			fprintf(kj,"|-------------------------------------------------------------|\n");
		}
		fprintf(kj,"  Nominal Uang :                       Rp. %g \n",uang_bayar);
		fprintf(kj,"  Kembalian    :                       Rp. %g \n",uang_kembalian);
		footer_struk();
	}
	fclose(kj);
}

stroller AlokasiKeranjang(infotype kode, infotype barang,infotype size,  float harga, int kuantitas, float total)
{
	 /* Kamus Lokal */
	 stroller P;
	 
	 /* Algoritma */
	 P = (stroller) malloc (sizeof (keranjang));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
		Prev(P) = Nil;
		Kode(P) = kode;
		Barang(P) = barang;
		Size(P) = size;
		Harga(P) = harga;
		Kuantitas(P) = kuantitas;
		Total(P) = total;
		Next(P) = Nil;
	 }
	 return (P);
}

stroller SearchKeranjang (stroller front, infotype kode)
{
	 /* Kamus Lokal */
	 stroller P;
	 bool found =  false;
	 int match;
	 P = front;
	 	while ((P != Nil) && (!found))
		{
			match = strcmp(Kode(P), kode);
			 if (match == 0)
			 { 
			 found = true; 	
			 return P;
			 }
			else
			{	
			P = Next(P);
			}
		}
		return NULL;
	
}

void InsertLastKeranjang (stroller *front, stroller *rear, stroller P)
{
	
	if(*front == Nil)
	{
		*front= P;
		*rear = P;
	}
	else
	{
		Next(*rear) = P;
		Prev(P) = *rear;
		*rear = P;
	}
}

void InsVLastKeranjang(stroller *front, stroller *rear, infotype kode, infotype barang, infotype size, float harga, int kuantitas, float total)
{
	stroller P;
	P = AlokasiKeranjang(kode, barang,size, harga, kuantitas, total);
	if (P != Nil)
	{	
	InsertLastKeranjang (front,rear, P);
			}
			
}

void PrintInfokeranjang (stroller data)
{
	 /* Kamus Lokal */
	stroller P;
	int i;
	i = 1;
	
	 /* Algoritma */
	system("cls");
	puts	("\n\t\t\t\t\t\t\t\t\t|======================================================================|");
	puts	("\t\t\t\t\t\t\t\t\t|                            DELIVERY MARKET                             |");
	puts	("\t\t\t\t\t\t\t\t\t|                         Telepon : 087734469228                         |");
	puts	("\t\t\t\t\t\t\t\t\t|                      Jl. Gegerkalong Hilir, Ciwaruga                   |");
	puts	("\t\t\t\t\t\t\t\t\t|                              Bandung Barat                             |");
	puts	("\t\t\t\t\t\t\t\t\t|========================================================================|");
	puts	("\t\t\t\t\t\t\t\t\t| NO |      BARANG        |   SIZE   |   HARGA   | KUANTITAS |   TOTAL   |");
	puts	("\t\t\t\t\t\t\t\t\t|------------------------------------------------------------------------|");
	if (data == Nil)
	{
		 printf (" ");
	}
	else	/* List memiliki elemen */
	{
		 P = data;
		 for (;;)
		 {
			if (P == Nil)
			{
				 printf("\n");
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 printf (" \t\t\t\t\t\t\t\t\t  %d.\t   %s\t    %s\t     %g\t    %d\t     %g\t      \n ", i, Barang(P),Size(P), Harga(P), Kuantitas(P), Total(P));
				 puts	("\t\t\t\t\t\t\t\t\t|-------------------------------------------------------------|");	
				 P = Next(P);
				 i++;
			}
		 }
	}
}

void DelKeranjang (stroller *front, infotype kode)
{
	stroller P, Prec;
	bool found=false;
	int compare;
	
	
	Prec = Nil;
	P = *front;
	while ((P != Nil) && (!found))
	{
		compare = strcmp(Kode(P), kode);
		 if (compare == 0)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = Next(P);
		 }
	} /* P = Nil Atau Ketemu */

	if (found)
	{
		 if (Prec == Nil && Next(P) == Nil)		
		 {	*front = Nil;	}
		 else if (Prec == Nil)			
		 {	*front = Next(P);	}
		 else		
		 {	Next(Prec) = Next(P);	}
		 Next(P) = Nil;
		 DeAlokasi (P);
	}
}

void DeAlokasi (stroller P)
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

void header_struk()
{
	FILE *kj;
	kj=fopen("struk_belanja.txt", "w+");
    fprintf(kj,"|========================================================================|\n");
	fprintf(kj,"|                            DELIVERY MARKET                             |\n");
	fprintf(kj,"|                         Telepon : 087734469228                         |\n");
	fprintf(kj,"|                      Jl. Gegerkalong Hilir, Ciwaruga                   |\n");
	fprintf(kj,"|                              Bandung Barat                             |\n");
	fprintf(kj,"|========================================================================|\n");
	fprintf(kj,"| NO |      BARANG        |   SIZE   |   HARGA   | KUANTITAS |   TOTAL   |\n");
	fprintf(kj,"|------------------------------------------------------------------------|\n");
    fclose(kj);
}

void footer_struk()
{
	FILE *kj;
	kj=fopen("struk_belanja.txt", "a+");
	fprintf(kj,"|=============================================================|\n");
	fprintf(kj,"|             TERIMA KASIH, SUDAH BERBELANJA                  |\n");
	fprintf(kj,"|              SELAMAT BERBELANJA KEMBALI :)                  |\n");
	fprintf(kj,"|=============================================================|\n");
	fclose(kj);
}

float hitung_diskon(float total, float potongan)
{
	float hitung;
	hitung = total*potongan;
	
	return hitung;
}

float hitung_hasil(float total, float potongan, float minimal, float ppn)
{
	float totalAkhir;
	if(total>= minimal )
	{
		totalAkhir = (total - potongan)  + ppn;
	}
	else
	{
		totalAkhir = total  + ppn;
	}
	
	return totalAkhir;
}

void output_bayar(float total, float minimal, float ppn, float diskon, float hasil)
{
	printf	("\t\t\t\t\t\t\t\t\t   PPN 10 persen :                          Rp. %g\n", ppn);
	if(total >= minimal)
	{
		puts	("\t\t\t\t\t\t\t\t\t|---------------Selamat anda mendapatkan diskon!--------------|");
		printf	("\t\t\t\t\t\t\t\t\t  Jumlah pembelanjaan anda lebih dari %g\n",minimal);
		printf	("\t\t\t\t\t\t\t\t\t  Jumlah pembayaran : Rp. %g ( Diskon sebesar Rp.%g) \n",hasil, diskon);
		puts	("\t\t\t\t\t\t\t\t\t|-------------------------------------------------------------|");
		
	}
	else
	{
		printf	("\t\t\t\t\t\t\t\t\t  Jumlah pembayaran :                       Rp. %g \n",hasil);
		puts	("\t\t\t\t\t\t\t\t\t|-------------------------------------------------------------|");
	}
}

float total_harga(stroller front)
{
	stroller P;
	float total;
	
	total =0;
	if (front!= Nil)
	{
		 P = front;
		 for (;;)
		 {
			if (P == Nil)
			{
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 total = total + Total(P);
				 P = Next(P);
			}
		 }
	}
	
	return total;
}

float hitung_ppn(float total, float ppn)
{
	float hitung;
	
	hitung = total*ppn;
	
	return hitung;
}

//huffman tree modul
address AlokasiChar(char X)
{
	 
	 address P;
	 
	
	 P = (address) malloc (sizeof (Node));
	 if (P != Nil)	
	 {
		Prev(P) = Nil;
		Info(P) = X;
		Freq(P) = 1;
		Next(P) = Nil;
	 }
	 return (P);
}

address Search (address front, char X)
{
	 
	 address P;
	 bool found =  false;
	
	 P = front;
	 	while ((P != Nil) && (!found))
		{
			 if (Info(P) == X)
			 { 
			 found = true; 	
			 return P;
			 }
			else
			{	
			P = Next(P);
			}
		}
		return NULL;
	
}

void InsertLastChar (address *front, address *rear, address P)
{
	
	if(*front == Nil)
	{
		*front= P;
		*rear = P;
	}
	else
	{
		Next(*rear) = P;
		Prev(P) = *rear;
		*rear = P;
	}
}

void InsVLastChar(address *front, address *rear, char X)
{
	address P;
	P = AlokasiChar(X);
	if (P != Nil)
	{	
	InsertLastChar (front,rear, P);
			}
			
}


address createFrekuensi()
{
	FILE *in, *out;
    char ch;
    address front, rear;
    address tempAdd;
    address temp;
    
    front = NULL;
    rear = NULL;
 
    in = fopen("panjang.txt", "r");
    if (in == NULL)
    {
        printf("Cannot open source file.\n");
        exit(1);
    }
    
    
    out = fopen("output.txt", "w");
    if (out == NULL)
    {
        printf("Cannot open destination file.\n");
        exit(1);
    }
    
    do {
        ch = getc(in);
        tempAdd = Search (front, ch);
        if(tempAdd == NULL)
        {
        	
        	InsVLastChar(&front, &rear, ch);
		}
		else
		{
			Freq(tempAdd)++;
		}
    }
    while (!feof(in));
    
    PrintFrekuensi (front);
 
    fputs("karakter    frekuensi    ", out);
    
    temp = front;
    
    while(temp != NULL)
    {
    	fprintf(out, "\n%c\t\t\t\t%2d\t\t\t\t", Info(temp), Freq(temp));
		temp = Next(temp);
	}
    

    fclose(out);
    fclose(in);
    
    return front;
}

void sortingFreq(address *front)
{
	address Pcur;
	address temp, max;
	int tempFreq;
	char tempChar;
	
	Pcur = Nil;
	temp = Nil;
	max = Nil;
	
	if(*front!=NULL)
    {
        Pcur=*front;
        while(Next(Pcur)!=NULL)
        {
            temp=Pcur;
            max=Pcur;
            while(temp!=NULL)
            {
                if(Freq(temp) > Freq(max))
                {
                    max=temp;
                }
                temp = Next(temp);
            }
            if(Freq(Pcur) < Freq(max))
            {
            	tempChar = Info(Pcur);
                tempFreq= Freq(Pcur);
                Info(Pcur) = Info(max);
                Freq(Pcur) = Freq(max);
                Info(max)=tempChar;
                Freq(max)=tempFreq;
            }
            Pcur=Next(Pcur);
        }
    }
	
}

Link CreateHuffmanTree()
{
	Link root;
	root = Nil;
	
	address front;
	front = Nil;
	
	address1 leafref;
	leafref = Nil;
	
	front = createFrekuensi();
	sortingFreq(&front);
			
	leafref = CreateListOfLeaf(front);
			
	root = CreateTree (leafref);
	
	return root;
}

void  incodeBarang(infotype *kodebinary, infotype *barangbinary, infotype *sizebinary, infotype *hargabinary, infotype *stokbinary, infotype kode, infotype barang, infotype size, infotype harga, infotype stok, Link root)
{
	*kodebinary = Incode(root, kode);
	*barangbinary = Incode(root, barang);
	*sizebinary = Incode(root, size);
	*hargabinary = Incode(root, harga);
	*stokbinary = Incode(root, stok);
}

void PrintFrekuensi (address data)
{
	 /* Kamus Lokal */
	address P;
	
	 /* Algoritma */
	if (data == Nil)
	{
		 printf ("List Kosong .... \a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = data;
		 for (;;)
		 {
			if (P == Nil)
			{
				 printf("\n");
				 break;
			}
			else	/* Belum berada di akhir List */
			{
				 printf ("| %c : %d |\n", Info(P), Freq(P));
				 printf	("    |\n");
				 printf	("    |\n");
				 P = Next(P);
			}
		 }
	}
}

infotype InputCodeChar(infotype deskripsi)
{
	infotype KodeChar;
	
	KodeChar = (infotype)malloc(50*sizeof(char));
	
	printf("%s", deskripsi);
	scanf(" %[^\n]s", KodeChar);
	
	return KodeChar;
}


void SearchTree(Link temp, char x, Link *temp2)
{
	if(temp != Nil)
	{
		if(Info(temp) == x)
			{
				*temp2 = temp;
			}
		SearchTree(RightSon(temp), x, &(*temp2));
		SearchTree(LeftSon(temp), x, &(*temp2));
	}
	
}

infotype Incode(Link root, infotype KodeChar)
{
	char huruf;
	Link alamat, Pcur;
	infotype KodeBinary;
	
	
	infotype tempBinary;
	tempBinary = (infotype)malloc(30*sizeof(char));
	tempBinary[0] = '\0';
	
	infotype temp;
	temp = (infotype)malloc(2*sizeof(char));
	temp[0] = '\0';
	
	
	alamat = Nil;
	Pcur = Nil;
	
	int i,length,j;
	i=0;
	do{
		KodeBinary = (infotype)malloc(30*sizeof(char));
		KodeBinary[0] = '\0';
		huruf = KodeChar[i];
		SearchTree(root, huruf, &alamat);
		while(alamat != root)
		{
			if(alamat == LeftSon(Parent(alamat)))
			{
				strcat(KodeBinary,"0");
				alamat = Parent(alamat);
			}
			else if(alamat == RightSon(Parent(alamat)))
			{
				strcat(KodeBinary,"1");
				alamat = Parent(alamat);
			}
		}
		length = strlen(KodeBinary);
		for(j=length;j>=0;j--)
		{
			temp[0]= KodeBinary[j];
			temp[1]= '\0';
			strcat(tempBinary,temp);
		}
		i++;
		
	}while(huruf != '\0');
	
	return tempBinary;
}



void FSearchBarang2(infotype NmFile, infotype kode, infotype *NmBarang, infotype *size, infotype *Harga, infotype *Stok)
// search barang menggunakan kode yang sudah didapat
{
	FILE *in;
	infotype KodeBarang;
	
	in = fopen(NmFile,"r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(1){
			KodeBarang = (infotype) malloc (50*sizeof(char));
			
        	fscanf(in,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", KodeBarang,*NmBarang, *size, *Harga, *Stok);
			fflush(stdin);
			
        	if (strcmp(KodeBarang, kode) == 0){
				break;
			}
       }
       fclose(in);
    }
}

void FSearchKodeChar(infotype NmFile, infotype binary, infotype *kodeChar)
{
	FILE *in;
	int compare;
	infotype Kbinary,Kchar;
	Kbinary = (infotype) malloc (30*sizeof(char));
	Kchar = (infotype) malloc (30*sizeof(char));
	
	in = fopen(NmFile,"r");
    if(!in){  
       printf("\nFile tidak ditemukan");
    }else{
       while(!feof(in)){
        	fscanf(in,"%[^\t]\t%[^\n]\n", Kchar, Kbinary);
			fflush(stdin);
			compare = strcmp(Kbinary, binary);
        	if (compare == 0){
        		*kodeChar = Kchar;
        		break;
			}
			else
			{
				*kodeChar = Nil;
			}

       }
       fclose(in);
    }
}



