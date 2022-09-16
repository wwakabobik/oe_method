//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "logic/lab3Z.cpp"
#include "logic/syserr.cpp"
#include "lab3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TLab3 t3;
TRab3 *Rab3;
//---------------------------------------------------------------------------
__fastcall TRab3::TRab3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRab3::numZChange(TObject *Sender)
{
bool succes = false;
if (numZ->Value > 0 && numZ->Value < 6)
scheme->Picture->LoadFromFile("pic/lab3_1.jpg");
else if (numZ->Value > 5 && numZ->Value < 11)
scheme->Picture->LoadFromFile("pic/lab3_2.jpg");
else if (numZ->Value > 10 && numZ->Value < 16)
scheme->Picture->LoadFromFile("pic/lab3_3.jpg");
else if (numZ->Value > 15 && numZ->Value < 21)
scheme->Picture->LoadFromFile("pic/lab3_4.jpg");
else if (numZ->Value > 20 && numZ->Value < 26)
scheme->Picture->LoadFromFile("pic/lab3_5.jpg");
succes=t3.Change(numZ->Value);
if (succes)
{
IZ1->Text=FloatToStr(t3.GetData(1));
IZ2->Text=FloatToStr(t3.GetData(2));
IZ3->Text=FloatToStr(t3.GetData(3));
IZ4->Text=FloatToStr(t3.GetData(4));
IZ5->Text=FloatToStr(t3.GetData(5));
RZ1->Text=FloatToStr(t3.GetData(7));
RZ2->Text=FloatToStr(t3.GetData(8));
RZ3->Text=FloatToStr(t3.GetData(9));
RZ4->Text=FloatToStr(t3.GetData(10));
RZ5->Text=FloatToStr(t3.GetData(11));
JZ->Text=FloatToStr(t3.GetData(13));
fiZ1->Text=FloatToStr(t3.GetData(14));
fiZ2->Text=FloatToStr(t3.GetData(15));
EZ1->Text=FloatToStr(t3.GetData(16));
EZ2->Text=FloatToStr(t3.GetData(17));
EZ3->Text=FloatToStr(t3.GetData(18));
}
else
{
IZ1->Text=0;
IZ2->Text=0;
IZ3->Text=0;
IZ4->Text=0;
IZ5->Text=0;
RZ1->Text=0;
RZ2->Text=0;
RZ3->Text=0;
RZ4->Text=0;
RZ5->Text=0;
JZ->Text=0;
fiZ1->Text=0;
fiZ2->Text=0;
EZ1->Text=0;
EZ2->Text=0;
EZ3->Text=0;
}

}
//---------------------------------------------------------------------------

void __fastcall TRab3::resultMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// String error protection block
IZ1->Text=StrCheck(IZ1->Text);
IZ2->Text=StrCheck(IZ2->Text);
IZ3->Text=StrCheck(IZ3->Text);
IZ4->Text=StrCheck(IZ4->Text);
IZ5->Text=StrCheck(IZ5->Text);
RZ1->Text=StrCheck(RZ1->Text);
RZ2->Text=StrCheck(RZ2->Text);
RZ3->Text=StrCheck(RZ3->Text);
RZ4->Text=StrCheck(RZ4->Text);
RZ5->Text=StrCheck(RZ5->Text);
JZ->Text=StrCheck(JZ->Text);
fiZ1->Text=StrCheck(fiZ1->Text);
fiZ2->Text=StrCheck(fiZ2->Text);
EZ1->Text=StrCheck(EZ1->Text);
EZ2->Text=StrCheck(EZ2->Text);
EZ3->Text=StrCheck(EZ3->Text);
// input
t3.NewLab3(numZ->Value);
t3.NewResist(StrToFloat(RZ1->Text), StrToFloat(RZ2->Text), StrToFloat(RZ3->Text), StrToFloat(RZ4->Text), StrToFloat(RZ5->Text), 0);
t3.NewEDS(StrToFloat(EZ1->Text), StrToFloat(EZ2->Text), StrToFloat(EZ3->Text), StrToFloat(JZ->Text));
t3.Lab3Calc(numZ->Value);
// output
IZ1->Text=FloatToStr(t3.GetData(1));
IZ2->Text=FloatToStr(t3.GetData(2));
IZ3->Text=FloatToStr(t3.GetData(3));
IZ4->Text=FloatToStr(t3.GetData(4));
IZ5->Text=FloatToStr(t3.GetData(5));
RZ1->Text=FloatToStr(t3.GetData(7));
RZ2->Text=FloatToStr(t3.GetData(8));
RZ3->Text=FloatToStr(t3.GetData(9));
RZ4->Text=FloatToStr(t3.GetData(10));
RZ5->Text=FloatToStr(t3.GetData(11));
JZ->Text=FloatToStr(t3.GetData(13));
fiZ1->Text=FloatToStr(t3.GetData(14));
fiZ2->Text=FloatToStr(t3.GetData(15));
EZ1->Text=FloatToStr(t3.GetData(16));
EZ2->Text=FloatToStr(t3.GetData(17));
EZ3->Text=FloatToStr(t3.GetData(18));
}
//---------------------------------------------------------------------------

void __fastcall TRab3::saveMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
// String error protection block
IZ1->Text=StrCheck(IZ1->Text);
IZ2->Text=StrCheck(IZ2->Text);
IZ3->Text=StrCheck(IZ3->Text);
IZ4->Text=StrCheck(IZ4->Text);
IZ5->Text=StrCheck(IZ5->Text);
RZ1->Text=StrCheck(RZ1->Text);
RZ2->Text=StrCheck(RZ2->Text);
RZ3->Text=StrCheck(RZ3->Text);
RZ4->Text=StrCheck(RZ4->Text);
RZ5->Text=StrCheck(RZ5->Text);
JZ->Text=StrCheck(JZ->Text);
fiZ1->Text=StrCheck(fiZ1->Text);
fiZ2->Text=StrCheck(fiZ2->Text);
EZ1->Text=StrCheck(EZ1->Text);
EZ2->Text=StrCheck(EZ2->Text);
EZ3->Text=StrCheck(EZ3->Text);
t3.DelLab3(numZ->Value);
// input
t3.NewLab3(numZ->Value);
t3.NewResist(StrToFloat(RZ1->Text), StrToFloat(RZ2->Text), StrToFloat(RZ3->Text), StrToFloat(RZ4->Text), StrToFloat(RZ5->Text), 0);
t3.NewEDS(StrToFloat(EZ1->Text), StrToFloat(EZ2->Text), StrToFloat(EZ3->Text), StrToFloat(JZ->Text));
t3.Lab3Calc(numZ->Value);
// output
IZ1->Text=FloatToStr(t3.GetData(1));
IZ2->Text=FloatToStr(t3.GetData(2));
IZ3->Text=FloatToStr(t3.GetData(3));
IZ4->Text=FloatToStr(t3.GetData(4));
IZ5->Text=FloatToStr(t3.GetData(5));
RZ1->Text=FloatToStr(t3.GetData(7));
RZ2->Text=FloatToStr(t3.GetData(8));
RZ3->Text=FloatToStr(t3.GetData(9));
RZ4->Text=FloatToStr(t3.GetData(10));
RZ5->Text=FloatToStr(t3.GetData(11));
JZ->Text=FloatToStr(t3.GetData(13));
fiZ1->Text=FloatToStr(t3.GetData(14));
fiZ2->Text=FloatToStr(t3.GetData(15));
EZ1->Text=FloatToStr(t3.GetData(16));
EZ2->Text=FloatToStr(t3.GetData(17));
EZ3->Text=FloatToStr(t3.GetData(18));
t3.save();
}
//---------------------------------------------------------------------------

