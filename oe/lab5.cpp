//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "logic/header.h"
#include "logic/lab5Z.cpp"
#include "logic/syserr.cpp"
#include "lab5.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TRab5 *Rab5;
TLab5 t5;
//---------------------------------------------------------------------------
__fastcall TRab5::TRab5(TComponent* Owner)
        : TForm(Owner)
{
big_pic->Picture->LoadFromFile("pic/lab5_1.jpg");
small_pic->Picture->LoadFromFile("pic/lab5_2.jpg"); 
}
//---------------------------------------------------------------------------
void __fastcall TRab5::rastch0MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
IZ->Text=StrCheck(IZ->Text);
wZ->Text=StrCheck(wZ->Text);
deltaZ->Text=StrCheck(deltaZ->Text);
cZ->Text=StrCheck(cZ->Text);
eZ->Text=StrCheck(eZ->Text);
DZ->Text=StrCheck(DZ->Text);
dZZ->Text=StrCheck(dZZ->Text);
hZ->Text=StrCheck(hZ->Text);
aZ->Text=StrCheck(aZ->Text);
// input
t5.NewLab5(numZ->Value, StrToFloat(IZ->Text), StrToFloat(wZ->Text), StrToFloat(deltaZ->Text), StrToFloat(aZ->Text), StrToFloat(cZ->Text), StrToFloat(eZ->Text), StrToFloat(DZ->Text), StrToFloat(dZZ->Text), StrToFloat(hZ->Text));
t5.Lab5Calc(numZ->Value);
// output
BkZ->Text=FloatToStr(t5.GetData(10));
HkZ->Text=FloatToStr(t5.GetData(11));
BZ->Text=FloatToStr(t5.GetData(12));
HcZ->Text=FloatToStr(t5.GetData(13));
HdZ->Text=FloatToStr(t5.GetData(14));
UmcZ->Text=FloatToStr(t5.GetData(15));
UmdZ->Text=FloatToStr(t5.GetData(16));
FZ->Text=FloatToStr(t5.GetData(17));
LZ->Text=FloatToStr(t5.GetData(18));
}
//---------------------------------------------------------------------------

void __fastcall TRab5::numZChange(TObject *Sender)
{
if(t5.Change(numZ->Value))
{
IZ->Text=FloatToStr(t5.GetData(1));
wZ->Text=FloatToStr(t5.GetData(2));
deltaZ->Text=FloatToStr(t5.GetData(3));
aZ->Text=FloatToStr(t5.GetData(4));
cZ->Text=FloatToStr(t5.GetData(5));
eZ->Text=FloatToStr(t5.GetData(6));
DZ->Text=FloatToStr(t5.GetData(7));
dZZ->Text=FloatToStr(t5.GetData(8));
hZ->Text=FloatToStr(t5.GetData(9));
BkZ->Text=FloatToStr(t5.GetData(10));
HkZ->Text=FloatToStr(t5.GetData(11));
BZ->Text=FloatToStr(t5.GetData(12));
HcZ->Text=FloatToStr(t5.GetData(13));
HdZ->Text=FloatToStr(t5.GetData(14));
UmcZ->Text=FloatToStr(t5.GetData(15));
UmdZ->Text=FloatToStr(t5.GetData(16));
FZ->Text=FloatToStr(t5.GetData(17));
LZ->Text=FloatToStr(t5.GetData(18));
}
else
{
IZ->Text=0;
wZ->Text=0;
deltaZ->Text=0;
cZ->Text=0;
eZ->Text=0;
aZ->Text=0;
DZ->Text=0;
dZZ->Text=0;
hZ->Text=0;
BkZ->Text=0;
HkZ->Text=0;
BZ->Text=0;
HcZ->Text=0;
HdZ->Text=0;
UmcZ->Text=0;
UmdZ->Text=0;
FZ->Text=0;
LZ->Text=0;
}
}
//---------------------------------------------------------------------------

void __fastcall TRab5::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
t5.DelLab5(numZ->Value);
t5.NewLab5(numZ->Value, StrToFloat(IZ->Text), StrToFloat(wZ->Text), StrToFloat(deltaZ->Text), StrToFloat(aZ->Text), StrToFloat(cZ->Text), StrToFloat(eZ->Text), StrToFloat(DZ->Text), StrToFloat(dZZ->Text), StrToFloat(hZ->Text));
t5.Lab5Calc(numZ->Value);
t5.save();
}
//---------------------------------------------------------------------------


