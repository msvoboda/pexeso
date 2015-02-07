//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::hrac1(TObject *Sender)
{
Form1->Label1->Caption = Edit1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::hrac2(TObject *Sender)
{
Form1->Label2->Caption = Edit2->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Nastav(TObject *Sender)
{
//MediaPlayer2->Play();
BitRub->LoadFromFile("rub2.bmp");
Rub();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Nastav1(TObject *Sender)
{
//MediaPlayer2->Play();
BitRub->LoadFromFile("rub1.bmp");
Losovani();
Rub();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Nastav2(TObject *Sender)
{
//MediaPlayer2->Play();
BitRub->LoadFromFile("rub3.bmp");
Losovani();
Rub();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Nastav3(TObject *Sender)
{
//MediaPlayer2->Play();
BitRub->LoadFromFile("rub4.bmp");
Losovani();
Rub();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Hra(TObject *Sender)
{
FILE *fx;
char soubor[25] = {NULL}; // string pro nazev souboru
char *pp_znak;


//MediaPlayer2->Play();
// nacist karty   *********
fx = fopen("karty1.txt", "r");
if (fx == NULL) {
    Application->MessageBox("Nepodaøilo se otevøít soubor!", "Chyba!", 0);
    Application->Terminate();
}
for (int pocit = 0; pocit < 32; pocit++) {
   fgets(soubor, 24, fx);
   pp_znak = strrchr(soubor, '\n');
   *pp_znak = 0x00;
   //Karta[pocit] = new Graphics::TBitmap();
   //Form1->Label1->Caption = (AnsiString) soubor;
   Karta[pocit]->LoadFromFile((AnsiString) soubor);
   //if (pocit == 15) break;
}
fclose(fx);
Label5->Font->Color = clRed;
Label6->Font->Color = clYellow;
Label8->Font->Color = clYellow;

Losovani();
Rub();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Hra1(TObject *Sender)
{
FILE *fy;
char soubor[25] = {NULL}; // string pro nazev souboru
char *pq_znak;


//MediaPlayer2->Play();
// nacist karty   *********
fy = fopen("karty3.txt", "r");
if (fy == NULL) {
    Application->MessageBox("Nepodaøilo se otevøít soubor!", "Chyba!", 0);
    Application->Terminate();
}
for (int pocit = 0; pocit < 32; pocit++) {
   fgets(soubor, 24, fy);
   pq_znak = strrchr(soubor, '\n');
   *pq_znak = 0x00;
   //Karta[pocit] = new Graphics::TBitmap();
   //Form1->Label1->Caption = (AnsiString) soubor;
   Karta[pocit]->LoadFromFile((AnsiString) soubor);
   //if (pocit == 15) break;
}
fclose(fy);
// prebarvit labely - ukazatele na akt. hru
Label6->Font->Color = clRed;
Label5->Font->Color = clYellow;
Label8->Font->Color = clYellow;

Losovani();
Rub();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Nahled(TObject *Sender)
{
Form1->Timer1->Interval = SpinEdit1->Value*1000;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::hra3(TObject *Sender)
{
FILE *fy;
char soubor[25] = {NULL}; // string pro nazev souboru
char *pq_znak;


//MediaPlayer2->Play();
// nacist karty   *********
fy = fopen("karty2.txt", "r");
if (fy == NULL) {
    Application->MessageBox("Nepodaøilo se otevøít soubor!", "Chyba!", 0);
    Application->Terminate();
}
for (int pocit = 0; pocit < 32; pocit++) {
   fgets(soubor, 24, fy);
   pq_znak = strrchr(soubor, '\n');
   *pq_znak = 0x00;
   //Karta[pocit] = new Graphics::TBitmap();
   //Form1->Label1->Caption = (AnsiString) soubor;
   Karta[pocit]->LoadFromFile((AnsiString) soubor);
   //if (pocit == 15) break;
}
fclose(fy);
// prebarvit labely - ukazatele na akt. hru
Label8->Font->Color = clRed;
Label6->Font->Color = clYellow;
Label5->Font->Color = clYellow;

Losovani();
Rub();
}
//---------------------------------------------------------------------------
