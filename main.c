#include "header.h"
#include "Fauza.h"
#include "Nisrina.h"
#include "Agam.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	address front, P;
	Link root;
	char role;
	infotype KodeChar;
	
	
	infotype KodeBinary;
	KodeBinary = (infotype)malloc(30*sizeof(char));
	
	KodeChar = Nil;
	 
	//market
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
	selamatDatang();
	system("cls");
//	loading("\tTUNGGU SEBENTAR...");
	do
	{
		system("cls");
		system("color 0F");
		tampilanFile("TAMPILAN.txt");
		sound("Suara/SiapakahAndaFix.wav");
		selection(&role);
		if(role == '1')
		{
			CekHarga ();
		}
		else if(role == '2')
		{
			adminFitur(&root);
		}
		else
		{
			printf("role yang and pilih tidak tersedia\n");
			printf("pilih role yang sudah tersedia [klik enter]");
			getche();
		}
	}while(role !='1' && role !='2');
	
	system("color 0F");
	tampilanFile("TAMPILAN(6).txt");
	sound("Suara/TerimakasihFix.wav");
	
	return 0;
}
