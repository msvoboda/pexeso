//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//----------Struktura pozice karet----------
typedef struct position {
	int x;
    int y;
} POSITION;
//-------------Promene----------------------
POSITION position[64];
Graphics::TBitmap *BitRub;
Graphics::TBitmap *Karta[32]; //32 bitmap
#define SIRKA 70
#define DELKA 50
//-------------Promne----------
int karty[64]; // pro losovani
int index[32];// pro losovani
int score[2] = {0, 0};
int otocena, otoc1, otoc2;
int hrac = 0;    // ma hodnoty 0 a 1
//------------------------------------------
//-----------------Fce Rub------------------
void Rub(void) {
    int poc;
    static BOOL status = FALSE;

	// inic rub
    if (status == FALSE) {
		  BitRub->LoadFromFile("rub1.bmp");
      status = TRUE;
    }

	for (poc = 0;poc < 64; poc++) {
    	Form1->Image1->Canvas->Draw(position[poc].x, position[poc].y, BitRub);
    }

    //delete BitRub;
}
//-------Fce. losovani karet
int losovani(void) {
    int losovane;

	losovane = random(32);
    if (index[losovane] < 2)
    	index[losovane]++;
    else
    	losovane = losovani();

    return(losovane);
}

void Losovani(void) {
	int poc;
    randomize();

	// nulovani
    for (poc = 0; poc < 64; poc++)
    	karty[poc] = 0;

    // vynulovat index[] / jinak sek
    for (int cis = 0; cis < 32; cis++)
    	index[cis] = 0;

    for (poc = 0; poc < 64; poc++) {
    	karty[poc] = losovani();
    	//printf("\t%d", karty[poc]);
    }
}


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
FILE *fr, *fp;   // ukazatel na stream
int pocit, x, y;
char soubor[55] = {NULL}; // string pro nazev souboru
char *p_znak;


BitRub = new Graphics::TBitmap();
//inicializace
randomize(); // zapnuti generatoru cisel
//Image1->Canvas->Brush->Color = clBlack;

fr = fopen("position.txt", "r");
if (fr == NULL) {
	Application->MessageBox("Nepodaøilo se otevøít soubor!", "Chyba!", 0);
    Application->Terminate();
}

for (pocit = 0; pocit < 64; pocit++) {
	  fscanf(fr, "*%d&%d ", &x, &y);
    position[pocit].x = x;
    position[pocit].y = y;
}
fclose(fr);
// nacist karty   *********
fp = fopen("karty3.txt", "r");
if (fp == NULL) {
    Application->MessageBox("Nepodaøilo se otevøít soubor!", "Chyba!", 0);
    Application->Terminate();
}
for (pocit = 0; pocit < 32; pocit++) {
   fgets(soubor, 24, fp);
   p_znak = strrchr(soubor, '\n');
   *p_znak = 0x00;
   Karta[pocit] = new Graphics::TBitmap();
   //Form1->Label1->Caption = (AnsiString) soubor;
   Karta[pocit]->LoadFromFile((AnsiString) soubor);
   //if (pocit == 15) break;
}
fclose(fp);

Rub(); //vykresli rub karet
Losovani(); // nalosuje karty
Form1->Canvas->Pen->Color = clBlue;
Form1->Canvas->FrameRect(Form1->Canvas->ClipRect);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Konec(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Hra(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
	int pozice, poc = 0;
	static int tah = 1;
	static int ukazatel;
  static int karta1, karta2;
	BOOL zasah = FALSE;

 //MediaPlayer1->Play();
// jestli pracuje timer tak vyskok
if (Timer1->Enabled == TRUE)
	return;
// zjisti, ktera karta byla oznacena
for (poc = 0; poc < 64; poc++) {
	if (X > position[poc].x && Y > position[poc].y && X < (position[poc].x+SIRKA) && Y < (position[poc].y+DELKA)) {
    	ukazatel = poc;
        //Label1->Caption = "vole";
        zasah = TRUE;
        break;
	}
}
// vykresleni urcene karty hracem
	if (zasah == TRUE) {
        pozice = karty[poc];
        if (pozice == 314) {
            Label5->Caption = "314";
        	return;
        }
    	Image1->Canvas->Draw(position[poc].x, position[poc].y, Karta[pozice]);
	}
    else
    	return; // pokud se trefis vedle - pryc
 // moznost chyb neprehledne necitelny vyznam ukazatel, pozice
	if (tah == 1) {
		Label5->Caption = "První";
        otocena = poc;
        tah = 2;
        karta1 = pozice;
        return;
    }
    if (tah == 2) {
        Label5->Caption = "druhá";
        if (otocena == poc) {
        	Label5->Caption = "Stejná";
            return;
        }
        karta2 = pozice;
    }
    if (karta1 == karta2) {
    	  Label5->Caption = "Zásah";
        karty[poc] = 314; // karta, kt je otocena uz nejde otocit kod 314
        karty[otocena] = 314; // -----""-----------
        score[hrac]++; // hrac si pripise bod
        // cis hodnotu na retezec
        Label3->Caption = score[0];
        Label4->Caption = score[1];
        // smazat objekty
        tah = 1;
        // test na vytezstvi
        poc=0;  // nutno vynulovat
        for (int vitez = 0; vitez < 64; vitez++) {
        	if (karty[vitez] == 314)
            	poc++;
        }
        if (poc == 64)  {
            Label5->Caption = "Vitez";

        }

        return;
    }
    else {
		Label5->Caption = "Vedle";
        // casova smycka
        otoc1 = poc;
        otoc2 = otocena;
        //Image1->Canvas->Draw(position[otocena].x, position[otocena].y, BitRub);
        Timer1->Enabled = TRUE;
        //Image1->Canvas->Draw(position[otocena].x, position[otocena].y, BitRub);

    }
    tah=1;
    if (hrac == 0)
    	hrac = 1;
    else
    	hrac = 0;
    // !!! otocit karty zpet
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Rub();
Losovani();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cas(TObject *Sender)
{
	  Image1->Canvas->Draw(position[otoc1].x, position[otoc1].y, BitRub);
    Image1->Canvas->Draw(position[otoc2].x, position[otoc2].y, BitRub);
    Timer1->Enabled = FALSE;
    if (hrac == 0)
        Label6->Caption = "Táhne: "+Label1->Caption;
    else
    	Label6->Caption = "Táhne: "+Label2->Caption;

    if (hrac == 1) {
      int karta1;
      while (karty[(karta1 = random(63))] == 314 || karta1 == otoc1 || karta1 == otoc2)
        ; // volim 1 kartu
      int karta2;
      while ((karta2 = random(63)) == karta1 || karty[karta2] == 314 || karta2 == otoc1 || karta2 == otoc2)
        ; // hledam kartu

    	Image1->Canvas->Draw(position[karta1].x, position[karta1].y, Karta[karty[karta1]]);
      //Sleep(3000);
      Image1->Canvas->Draw(position[karta2].x, position[karta2].y, Karta[karty[karta2]]);
      if (karty[karta1] == karty[karta2]) {
        karty[karta1] = 314;
        karty[karta2] = 314;
        score[hrac]++; // hrac si pripise bod
        // cis hodnotu na retezec
        Label3->Caption = score[0];
        Label4->Caption = score[1];
      }
      else {
        otoc1 = karta1;
        otoc2 = karta2;
      }
      hrac = 0;
      Timer1->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete BitRub;
for (int i = 0; i < 32; i++)
  delete Karta[i]; //32 bitmap
}
//---------------------------------------------------------------------------

