//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\MPlayer.hpp>
#include <vcl\Buttons.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TTimer *Timer1;
	TLabel *Label6;
	TLabel *Label7;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	void __fastcall Konec(TObject *Sender);
	
	
	
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Hra(TObject *Sender, TMouseButton Button, TShiftState Shift,
	int X, int Y);
	
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall cas(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	virtual __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
extern void Rub(void);
void Losovani(void); 
extern Graphics::TBitmap *BitRub;
extern Graphics::TBitmap *Karta[32]; //32 bitmap
//---------------------------------------------------------------------------
#endif
 