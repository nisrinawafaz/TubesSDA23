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

void InputBarang(Link root){
	FILE *pf;
	infotype barang, harga, stok, barangbinary, hargabinary, stokbinary, penampung;
	char pilihan, pilihan1, lagi = 'y';
	int stokbarang, stokbarang1;
	
	while (lagi == 'y' || lagi =='Y'){
		barang = (infotype) malloc (50*sizeof(char));
		harga = (infotype) malloc (50*sizeof(char));
		stok = (infotype) malloc (50*sizeof(char));
		barangbinary = (infotype) malloc (50*sizeof(char));
		hargabinary = (infotype) malloc (50*sizeof(char));
		stokbinary = (infotype) malloc (50*sizeof(char));
	
	
		if (pf == NULL){
			printf("File gagal dibuka.");
	    	exit(1);
		}
	
		barang = InputCodeChar("\nMasukkan Nama Barang:");
		sensitiveCase(barang);
		barangbinary = Incode(root, barang);
		if(SearchBarang("BarangBinary.txt", barangbinary)){
			FSearchBarang("BarangBinary.txt", barangbinary, &hargabinary, &stokbinary);
			barang = Decode(root, barangbinary);
			printf("\nBerikut adalah Harga dan Stok Barang %s:\n", barang);
			harga = Decode(root, hargabinary);
			stok = Decode(root, stokbinary);
			printf("Harga: %s, Stok: %s\n", harga, stok);
			printf("Apakah anda ingin mengubah Harga? (Y/N)");
			fflush(stdin);
			scanf("%c", &pilihan);
			if(pilihan == 'Y' || pilihan == 'y'){
				harga = InputCodeChar("Masukkan Harga Barang Terbaru:");
				hargabinary = Incode(root, harga);
			}
			printf("Apakah anda ingin menambah Stok? (Y/N)");
			fflush(stdin);
			scanf("%c", &pilihan1);
			if(pilihan1 == 'Y' || pilihan1 == 'y'){
				stokbarang = atoi(stok);
				stok = InputCodeChar("Masukkan Stok Barang yang ingin ditambahkan:");
				stokbarang1 = atoi(stok);
				sprintf(stok, "%d", (stokbarang+stokbarang1));
				stokbinary = Incode(root, stok);
			}
			if(pilihan == 'Y' || pilihan == 'y' || pilihan1 == 'Y' || pilihan1 == 'y'){
				Replace(root, barangbinary, hargabinary, stokbinary);
			}
			
		}else{
			harga = InputCodeChar("Masukkan Harga Barang:");
			hargabinary = Incode(root, harga);
			stok = InputCodeChar("Masukkan Jumlah Stok Barang:");
			stokbinary = Incode(root, stok);
			pf = fopen("NamaBarang.txt","a");
			fprintf(pf,"%s\t%s\t%s\n", barang, harga, stok);
			fclose(pf);
			pf = fopen("BarangBinary.txt","a");
			fprintf(pf,"%s\t%s\t%s\n", barangbinary, hargabinary, stokbinary);
			fclose(pf);
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




