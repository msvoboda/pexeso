//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\MPlayer.hpp>
//#include "c:\aplikace\cbuilder\examples\controls\spin\spin.h"
#include "CSPIN.h"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TLabel *Label3;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TLabel *Label4;
	TImage *Image5;
	TLabel *Label5;
	TLabel *Label6;
	TImage *Image6;
  TLabel *Label7;
	TImage *Image7;
	TLabel *Label8;
  TCSpinEdit *SpinEdit1;
	void __fastcall hrac1(TObject *Sender);
	void __fastcall hrac2(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Nastav(TObject *Sender);
	void __fastcall Nastav1(TObject *Sender);
	void __fastcall Nastav2(TObject *Sender);
	void __fastcall Nastav3(TObject *Sender);
	void __fastcall Hra(TObject *Sender);
	void __fastcall Hra1(TObject *Sender);
	void __fastcall Nahled(TObject *Sender);
	void __fastcall hra3(TObject *Sender);
	
private:	// User declarations
public:		// User declarations
	virtual __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
