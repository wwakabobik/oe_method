//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "author.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Rab1->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Rab3->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Rab4->ShowModal();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel5MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
authors->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel6MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Close();
exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Rab2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel7MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Rab5->ShowModal();
}
//---------------------------------------------------------------------------

