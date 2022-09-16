//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "logic/lab1Z.cpp"
#include "logic/syserr.cpp"
#include "lab1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "PERFGRAP"
#pragma resource "*.dfm"
TLab1 t1;
TRab1 *Rab1;
//---------------------------------------------------------------------------
__fastcall TRab1::TRab1(TComponent* Owner)
        : TForm(Owner)
{
image_sh->Picture->LoadFromFile("pic/lab1_main.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TRab1::numZChange(TObject *Sender)
{
bool succes = false;
succes=t1.Change(numZ->Value);
if (succes)
{
IZ1->Text=FloatToStr(t1.GetData(1));
IZ2->Text=FloatToStr(t1.GetData(2));
IZ3->Text=FloatToStr(t1.GetData(3));
IZ4->Text=FloatToStr(t1.GetData(4));
IZ5->Text=FloatToStr(t1.GetData(5));
IZ6->Text=FloatToStr(t1.GetData(6));
IW1->Text=FloatToStr(t1.GetData(9));
IW2->Text=FloatToStr(t1.GetData(10));
IW3->Text=FloatToStr(t1.GetData(11));
nuZ->Text=FloatToStr(t1.GetData(17));
lZ->Text=FloatToStr(t1.GetData(18));
SZ->Text=FloatToStr(t1.GetData(19));
dZ->Text=FloatToStr(t1.GetData(20));
HcZ->Text=FloatToStr(t1.GetData(21));
HdZ->Text=FloatToStr(t1.GetData(22));
UcZ->Text=FloatToStr(t1.GetData(23));
UdZ->Text=FloatToStr(t1.GetData(24));
BZ->Text=FloatToStr(t1.GetData(25));
FZ->Text=FloatToStr(t1.GetData(26));
if (t1.GetData(27)==false)
vector->Text="Против ЧС";
else vector->Text="По ЧС";
}
else
{
IZ1->Text=0;
IZ2->Text=0;
IZ3->Text=0;
IZ4->Text=0;
IZ5->Text=0;
IZ6->Text=0;
IW1->Text=0;
IW2->Text=0;
IW3->Text=0;
nuZ->Text=0;
lZ->Text=0;
SZ->Text=0;
dZ->Text=0;
HcZ->Text=0;
HdZ->Text=0;
UcZ->Text=0;
UdZ->Text=0;
BZ->Text=0;
FZ->Text=0;
vector->Text="неизвестно";
}
}
//---------------------------------------------------------------------------

void __fastcall TRab1::Button1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Close();
}
//---------------------------------------------------------------------------


void __fastcall TRab1::resultMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// String error protection block
IZ1->Text=StrCheck(IZ1->Text);
IZ2->Text=StrCheck(IZ2->Text);
IZ3->Text=StrCheck(IZ3->Text);
IZ4->Text=StrCheck(IZ4->Text);
IZ5->Text=StrCheck(IZ5->Text);
IZ6->Text=StrCheck(IZ6->Text);
IW1->Text=StrCheck(IW1->Text);
IW2->Text=StrCheck(IW2->Text);
IW3->Text=StrCheck(IW3->Text);
nuZ->Text=StrCheck(nuZ->Text);
lZ->Text=StrCheck(lZ->Text);
SZ->Text=StrCheck(SZ->Text);
dZ->Text=StrCheck(dZ->Text);
//input
t1.NewNum(numZ->Value);
t1.NewCurrent(StrToFloat(IZ1->Text), StrToFloat(IZ2->Text), StrToFloat(IZ3->Text), StrToFloat(IZ4->Text), StrToFloat(IZ5->Text), StrToFloat(IZ6->Text), 0, 0);
t1.NewCoil(StrToFloat(IW1->Text), StrToFloat(IW2->Text), StrToFloat(IW3->Text), 0, 0, 0, 0, 0);
t1.NewOther(StrToFloat(nuZ->Text), StrToFloat(lZ->Text), StrToFloat(SZ->Text), StrToFloat(dZ->Text));
t1.CalcNum(numZ->Value);
//output
IZ1->Text=FloatToStr(t1.GetData(1));
IZ2->Text=FloatToStr(t1.GetData(2));
IZ3->Text=FloatToStr(t1.GetData(3));
IZ4->Text=FloatToStr(t1.GetData(4));
IZ5->Text=FloatToStr(t1.GetData(5));
IZ6->Text=FloatToStr(t1.GetData(6));
IW1->Text=FloatToStr(t1.GetData(9));
IW2->Text=FloatToStr(t1.GetData(10));
IW3->Text=FloatToStr(t1.GetData(11));
nuZ->Text=FloatToStr(t1.GetData(17));
lZ->Text=FloatToStr(t1.GetData(18));
SZ->Text=FloatToStr(t1.GetData(19));
dZ->Text=FloatToStr(t1.GetData(20));
HcZ->Text=FloatToStr(t1.GetData(21));
HdZ->Text=FloatToStr(t1.GetData(22));
UcZ->Text=FloatToStr(t1.GetData(23));
UdZ->Text=FloatToStr(t1.GetData(24));
BZ->Text=FloatToStr(t1.GetData(25));
FZ->Text=FloatToStr(t1.GetData(26));
if (t1.GetData(27)==false)
vector->Text="Против ЧС";
else vector->Text="По ЧС";
}
//---------------------------------------------------------------------------

void __fastcall TRab1::saveMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
t1.DelNum(numZ->Value);
// String error protection block
IZ1->Text=StrCheck(IZ1->Text);
IZ2->Text=StrCheck(IZ2->Text);
IZ3->Text=StrCheck(IZ3->Text);
IZ4->Text=StrCheck(IZ4->Text);
IZ5->Text=StrCheck(IZ5->Text);
IZ6->Text=StrCheck(IZ6->Text);
IW1->Text=StrCheck(IW1->Text);
IW2->Text=StrCheck(IW2->Text);
IW3->Text=StrCheck(IW3->Text);
nuZ->Text=StrCheck(nuZ->Text);
lZ->Text=StrCheck(lZ->Text);
SZ->Text=StrCheck(SZ->Text);
dZ->Text=StrCheck(dZ->Text);
//input
t1.NewNum(numZ->Value);
t1.NewCurrent(StrToFloat(IZ1->Text), StrToFloat(IZ2->Text), StrToFloat(IZ3->Text), StrToFloat(IZ4->Text), StrToFloat(IZ5->Text), StrToFloat(IZ6->Text), 0, 0);
t1.NewCoil(StrToFloat(IW1->Text), StrToFloat(IW2->Text), StrToFloat(IW3->Text), 0, 0, 0, 0, 0);
t1.NewOther(StrToFloat(nuZ->Text), StrToFloat(lZ->Text), StrToFloat(SZ->Text), StrToFloat(dZ->Text));
t1.CalcNum(numZ->Value);
//output
IZ1->Text=FloatToStr(t1.GetData(1));
IZ2->Text=FloatToStr(t1.GetData(2));
IZ3->Text=FloatToStr(t1.GetData(3));
IZ4->Text=FloatToStr(t1.GetData(4));
IZ5->Text=FloatToStr(t1.GetData(5));
IZ6->Text=FloatToStr(t1.GetData(6));
IW1->Text=FloatToStr(t1.GetData(9));
IW2->Text=FloatToStr(t1.GetData(10));
IW3->Text=FloatToStr(t1.GetData(11));
nuZ->Text=FloatToStr(t1.GetData(17));
lZ->Text=FloatToStr(t1.GetData(18));
SZ->Text=FloatToStr(t1.GetData(19));
dZ->Text=FloatToStr(t1.GetData(20));
HcZ->Text=FloatToStr(t1.GetData(21));
HdZ->Text=FloatToStr(t1.GetData(22));
UcZ->Text=FloatToStr(t1.GetData(23));
UdZ->Text=FloatToStr(t1.GetData(24));
BZ->Text=FloatToStr(t1.GetData(25));
FZ->Text=FloatToStr(t1.GetData(26));
if (t1.GetData(27)==false)
vector->Text="Против ЧС";
else vector->Text="По ЧС";
t1.save();
}
//---------------------------------------------------------------------------

