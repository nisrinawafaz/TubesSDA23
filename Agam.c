#include "header.h"
#include "Nisrina.h"
#include "Fauza.h"
#include "Agam.h"

infotype InputCodeBinary(infotype deskripsi)
{
	infotype str;
	
	str = (infotype) malloc (10 * sizeof(char));
	
	printf("%s", deskripsi);
	scanf("%s", str);
	
	return str;
}

infotype Decode(Link root, infotype str){
	int i = 0;
	Link pCur;
	
	infotype kalimat;
	kalimat = (infotype) malloc (30 * sizeof(char));
	kalimat[0] ='\0';
	
	infotype temp;
	temp = (infotype) malloc (2 * sizeof(char));
	temp[0] ='\0';
	
	pCur = root;
	
	while(str[i] != '\0'){
		while(RightSon(pCur) != Nil && LeftSon(pCur) != Nil){
			if(str[i] == '1'){
				pCur = RightSon(pCur);
			}else if(str[i] == '0'){
				pCur = LeftSon(pCur);
			}
			i++;
		} 
		temp[0] = Info(pCur);
		temp[1] = '\0';
		strcat(kalimat,temp);
		pCur = root;	
	}

	return kalimat;
}

infotype sensitiveCase(infotype kata){
	int i;
	
	for (i = 0; kata[i]!='\0'; i++) {
		if(kata[i] >= 'a' && kata[i] <= 'z'){ //'a' itu 75, 'z' itu 122. Pake ascii
  			kata[i] = kata[i] - 32;
		} 
	}
	
	return kata;
}

void InputBarang(Link *root){
	FILE *pf;
	FILE *in;
	infotype kode, barang, size, harga, stok, kodebinary, barangbinary, sizebinary, hargabinary, stokbinary, penampung;
	char pilihan, pilihan1, lagi = 'y';
	int stokbarang, stokbarang1;
	int cek = 0;
	
	
	while (lagi == 'y' || lagi =='Y'){
		kode = (infotype) malloc (50*sizeof(char));
		barang = (infotype) malloc (50*sizeof(char));
		size = (infotype) malloc (50*sizeof(char));
		harga = (infotype) malloc (50*sizeof(char));
		stok = (infotype) malloc (50*sizeof(char));
		kodebinary = (infotype) malloc (50*sizeof(char));
		barangbinary = (infotype) malloc (50*sizeof(char));
		sizebinary = (infotype) malloc (50*sizeof(char));
		hargabinary = (infotype) malloc (50*sizeof(char));
		stokbinary = (infotype) malloc (50*sizeof(char));
	
		barang = InputCodeChar("\nMasukkan Nama Barang:");
		barang = sensitiveCase(barang);
		size = InputCodeChar("\nMasukkan Ukuran Barang:");
		size = sensitiveCase(size);
		if(SearchBarang("NamaBarang.txt", barang) && SearchSize("NamaBarang.txt", barang, size)){
			FSearchBarang("NamaBarang.txt", &kode, barang, size, &harga, &stok);
			
			printf("\nBerikut adalah Harga, Size, dan Stok Barang %s:\n", barang);
			printf("Size: %s, Harga: %s, Stok: %s\n", size, harga, stok);
			
			printf("Apakah anda ingin mengubah Harga? (Y/N)");
			fflush(stdin);
			scanf("%c", &pilihan);
			
			if(pilihan == 'Y' || pilihan == 'y'){
				harga = InputCodeChar("Masukkan Harga Barang Terbaru:");
				pf = fopen("panjang.txt","a");
				if (!pf){
					printf("\nFile tidak ditemukan");
				} else{
					fprintf(pf,"%s", harga);
					fclose(pf);
				}
			}
			
			printf("Apakah anda ingin menambah Stok? (Y/N)");
			fflush(stdin);
			scanf("%c", &pilihan1);
			
			if(pilihan1 == 'Y' || pilihan1 == 'y'){
				stokbarang = atoi(stok);
				stok = InputCodeChar("Masukkan Stok Barang yang ingin ditambahkan:");
				
				pf = fopen("panjang.txt","a");
				if (!pf){
					printf("\nFile tidak ditemukan");
				} else{
					fprintf(pf,"%s", stok);
					fclose(pf);
				}
				
				stokbarang1 = atoi(stok);
				sprintf(stok, "%d", (stokbarang+stokbarang1));
				
			}
			Replace(kode, harga, stok);
		} else{
			harga = InputCodeChar("Masukkan Harga Barang:");
			stok = InputCodeChar("Masukkan Jumlah Stok Barang:");
			
			kode = BuatKodeBarang (barang);
			
			pf = fopen("NamaBarang.txt","a");
			if (!pf){
				printf("\nFile tidak ditemukan");
			} else{
				fprintf(pf,"%s\t%s\t%s\t%s\t%s\n", kode, barang, size, harga, stok);
				fclose(pf);
			}
			
			pf = fopen("panjang.txt","a");
			if (!pf){
				printf("\nFile tidak ditemukan");
			} else{
				fprintf(pf,"%s%s%s%s%s", kode, barang, size, harga, stok);
				fclose(pf);
			}
			
			*root = CreateHuffmanTree();
			incodeBarang(&barangbinary, &sizebinary, &hargabinary, &stokbinary, barang, size, harga, stok, *root);
			
			kodebinary = Incode(*root, kode);
			InputFileKodeBarang (kode, kodebinary);
			
			printf ("\ncoba");
			getche();
			pf = fopen("BarangBinary.txt","a");
			if (!pf){
				printf("\nFile tidak ditemukan");
			} else{
				fprintf(pf,"%s\t%s\t%s\t%s\n", kodebinary, barangbinary, sizebinary, hargabinary, stokbinary);
				fclose(pf);
			}
		}
		printf ("\n\nApakah anda ingin menginputkan barang lagi? (y/t)");
		lagi = getche ();	
	}
}

double UangKembalian(double totalHarga){
	double UangKembali, JumlahUang;
	
	do{
		printf("\nMasukkan Jumlah Uang: ");
		scanf("%lf", &JumlahUang);
		
		if(totalHarga > JumlahUang){
			printf("\nMaaf Uang Anda kurang");
		}	
	}while(totalHarga > JumlahUang);

	UangKembali = JumlahUang - totalHarga;
	printf("%lf", UangKembali);
	printf("\nini yang g %g", UangKembali);
	
	return UangKembali;
}

void tampilanKembalian(double Uangkembalian){
	printf	("\t\t\t\t\t\t\t\t\t  Kembalian :                       Rp. %g \n",Uangkembalian);
	puts	("\n\t\t\t\t\t\t\t\t\t|=============================================================|");
	puts	("\t\t\t\t\t\t\t\t\t|             TERIMA KASIH, SUDAH BERBELANJA                  |");
	puts	("\t\t\t\t\t\t\t\t\t|              SELAMAT BERBELANJA KEMBALI :)                  |");
	puts	("\n\t\t\t\t\t\t\t\t\t|=============================================================|");
}

