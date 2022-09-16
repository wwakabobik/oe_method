//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "lab4.h"
#include "logic/lab4Z.cpp"
#include "logic/syserr.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TRab4 *Rab4;
TLab4 t4;
//---------------------------------------------------------------------------
__fastcall TRab4::TRab4(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TRab4::numZChange(TObject *Sender)
{
if (numZ->Value > 0 && numZ->Value < 6)
{ zep_toka->Picture->LoadFromFile("pic/lab4_1.jpg"); }
else if (numZ->Value > 5 && numZ->Value < 11)
{ zep_toka->Picture->LoadFromFile("pic/lab4_2.jpg"); }
else if (numZ->Value > 10 && numZ->Value < 16)
{ zep_toka->Picture->LoadFromFile("pic/lab4_3.jpg"); }
else if (numZ->Value > 15 && numZ->Value < 21)
{ zep_toka->Picture->LoadFromFile("pic/lab4_4.jpg"); }
else if (numZ->Value > 20 && numZ->Value < 26)
{ zep_toka->Picture->LoadFromFile("pic/lab4_5.jpg"); }
t4.Change(numZ->Value);
// output
UZ->Text=FloatToStr(t4.GetData(1));
FZ->Text=FloatToStr(t4.GetData(2));
RZ->Text=FloatToStr(t4.GetData(3));
CZ->Text=FloatToStr(t4.GetData(4));
LZ->Text=FloatToStr(t4.GetData(5));
XCZ->Text=FloatToStr(t4.GetData(6));
XLZ->Text=FloatToStr(t4.GetData(7));
ZZ->Text=FloatToStr(t4.GetData(10));
XABZREZ->Text=FloatToStr(t4.GetData(8));
XABIMFZ->Text=FloatToStr(t4.GetData(9));
FIZ->Text=FloatToStr(t4.GetData(11));
//UTZ->Text=FloatToStr(t4.GetData(12));
IlZ->Text=FloatToStr(t4.GetData(13));
UlZ->Text=FloatToStr(t4.GetData(14));
UabZ->Text=FloatToStr(t4.GetData(19));
c0Z->Text=FloatToStr(t4.GetData(15));
d0Z->Text=FloatToStr(t4.GetData(16));
g0Z->Text=FloatToStr(t4.GetData(17));
h0Z->Text=FloatToStr(t4.GetData(18));
FIabZ->Text=FloatToStr(t4.GetData(20));
IcZ->Text=FloatToStr(t4.GetData(21));
IrZ->Text=FloatToStr(t4.GetData(22));
UCZ->Text=FloatToStr(t4.GetData(23));
URZ->Text=FloatToStr(t4.GetData(24));
// graphic block
long double cx0, cy0, cvx0, cvy0, cvx20, cvy20, tetta, gippo, buf, x2, y2, axis;
buf=0;
cx0=StrToFloat(IrZ->Text);
cy0=StrToFloat(IcZ->Text);
cvx0=(StrToFloat(UabZ->Text));//50;
cvy0=0;
cvx20=cx0;
cvy20=cy0;
//if (cvy0+cy0!=0)
tetta=cvx20/cvy20;
//else buf=1;
//if (cvx0+cx0==0)
//buf=2;
if (cvx20>0 && cvy20>0)
axis=1;
else if (cvx20<0 && cvy20>0)
axis=2;
else if (cvx20>0 && cvy20<0)
axis=3;
else if (cvx20<0 && cvy20<0)
axis=4;
gippo=(StrToFloat(UlZ->Text));//50;
x2=sqrt(abs(powl(gippo,2)/(1+sqrt(abs(tetta)))));
x2/=50;
y2=tetta*x2;
if (gippo<0) { x2*=-1; y2*=-1; }
Series1->Clear();
Series2->Clear();
Series3->Clear();
Series4->Clear();
Series5->Clear();
Series6->Clear();
Series1->AddArrow(0,0,cx0,0);
Series2->AddArrow(0,0,0,cy0);
Series3->AddArrow(0,0,cx0,cy0);
Series4->AddArrow(0,0,cvx0/50,cvy0);
if (!buf)
{
if (axis==1)
{
Series6->AddArrow(0,0,-x2,y2);
Series5->AddArrow(0,0,-x2+cvx0/50,y2);
}
else if (axis==2)
{
Series6->AddArrow(0,0,-x2,y2);
Series5->AddArrow(0,0,-x2+cvx0/50,y2);
}
else if (axis==3)
{
Series6->AddArrow(0,0,x2,-y2);
Series5->AddArrow(0,0,x2+cvx0/50,-y2);
}
else if (axis==4)
{
Series6->AddArrow(0,0,x2,-y2);
Series5->AddArrow(0,0,x2+cvx0/50,-y2);
}
}
else if (buf==1)
{
if (cx0+cvx0==0 && cy0+cvy0==0)
buf=1;
else if (cx0+cvx0<0)
Series6->AddArrow(0,0,0,-gippo/50);
else Series6->AddArrow(0,0,0,gippo/50);
}
else if (buf==2)
{
if (cvy0+cy0<0)
Series6->AddArrow(0,0,gippo/50,0);
else Series6->AddArrow(0,0,-gippo/50,0);
}
else
{
UZ->Text=0;
FZ->Text=0;
RZ->Text=0;
CZ->Text=0;
LZ->Text=0;
XCZ->Text=0;
XLZ->Text=0;
ZZ->Text=0;
XABZREZ->Text=0;
XABIMFZ->Text=0;
FIZ->Text=0;
//UTZ->Text=0;
IlZ->Text=0;
UlZ->Text=0;
UabZ->Text=0;
c0Z->Text=0;
d0Z->Text=0;
g0Z->Text=0;
h0Z->Text=0;
FIabZ->Text=0;
IcZ->Text=0;
IrZ->Text=0;
UCZ->Text=0;
URZ->Text=0;
}
}
//---------------------------------------------------------------------------






void __fastcall TRab4::resultMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// String error protection block
UZ->Text=StrCheck(UZ->Text);
FZ->Text=StrCheck(FZ->Text);
RZ->Text=StrCheck(RZ->Text);
CZ->Text=StrCheck(CZ->Text);
LZ->Text=StrCheck(LZ->Text);
// input
t4.NewLab4(numZ->Value, StrToFloat(UZ->Text), StrToFloat(FZ->Text), StrToFloat(RZ->Text), StrToFloat(CZ->Text), StrToFloat(LZ->Text));
t4.Lab4Calc(numZ->Value);
// output
UZ->Text=FloatToStr(t4.GetData(1));
FZ->Text=FloatToStr(t4.GetData(2));
RZ->Text=FloatToStr(t4.GetData(3));
CZ->Text=FloatToStr(t4.GetData(4));
LZ->Text=FloatToStr(t4.GetData(5));
XCZ->Text=FloatToStr(t4.GetData(6));
XLZ->Text=FloatToStr(t4.GetData(7));
ZZ->Text=FloatToStr(t4.GetData(10));
XABZREZ->Text=FloatToStr(t4.GetData(8));
XABIMFZ->Text=FloatToStr(t4.GetData(9));
FIZ->Text=FloatToStr(t4.GetData(11));
//UTZ->Text=FloatToStr(t4.GetData(12));
IlZ->Text=FloatToStr(t4.GetData(13));
UlZ->Text=FloatToStr(t4.GetData(14));
UabZ->Text=FloatToStr(t4.GetData(19));
c0Z->Text=FloatToStr(t4.GetData(15));
d0Z->Text=FloatToStr(t4.GetData(16));
g0Z->Text=FloatToStr(t4.GetData(17));
h0Z->Text=FloatToStr(t4.GetData(18));
FIabZ->Text=FloatToStr(t4.GetData(20));
IcZ->Text=FloatToStr(t4.GetData(21));
IrZ->Text=FloatToStr(t4.GetData(22));
UCZ->Text=FloatToStr(t4.GetData(23));
URZ->Text=FloatToStr(t4.GetData(24));
// graphic block
long double cx0, cy0, cvx0, cvy0, cvx20, cvy20, tetta, gippo, buf, x2, y2, axis;
buf=0;
cx0=StrToFloat(IrZ->Text);
cy0=StrToFloat(IcZ->Text);
cvx0=(StrToFloat(UabZ->Text));//50;
cvy0=0;
cvx20=cx0;
cvy20=cy0;
//if (cvy0+cy0!=0)
tetta=cvx20/cvy20;
//else buf=1;
//if (cvx0+cx0==0)
//buf=2;
if (cvx20>0 && cvy20>0)
axis=1;
else if (cvx20<0 && cvy20>0)
axis=2;
else if (cvx20>0 && cvy20<0)
axis=3;
else if (cvx20<0 && cvy20<0)
axis=4;
gippo=(StrToFloat(UlZ->Text));//50;
x2=sqrt(abs(powl(gippo,2)/(1+sqrt(abs(tetta)))));
x2/=50;
y2=tetta*x2;
if (gippo<0) { x2*=-1; y2*=-1; }
Series1->Clear();
Series2->Clear();
Series3->Clear();
Series4->Clear();
Series5->Clear();
Series6->Clear();
Series1->AddArrow(0,0,cx0,0);
Series2->AddArrow(0,0,0,cy0);
Series3->AddArrow(0,0,cx0,cy0);
Series4->AddArrow(0,0,cvx0/50,cvy0);
if (!buf)
{
if (axis==1)
{
Series6->AddArrow(0,0,-x2,y2);
Series5->AddArrow(0,0,-x2+cvx0/50,y2);
}
else if (axis==2)
{
Series6->AddArrow(0,0,-x2,y2);
Series5->AddArrow(0,0,-x2+cvx0/50,y2);
}
else if (axis==3)
{
Series6->AddArrow(0,0,x2,-y2);
Series5->AddArrow(0,0,x2+cvx0/50,-y2);
}
else if (axis==4)
{
Series6->AddArrow(0,0,x2,-y2);
Series5->AddArrow(0,0,x2+cvx0/50,-y2);
}
}
else if (buf==1)
{
if (cx0+cvx0==0 && cy0+cvy0==0)
buf=1;
else if (cx0+cvx0<0)
Series6->AddArrow(0,0,0,-gippo/50);
else Series6->AddArrow(0,0,0,gippo/50);
}
else if (buf==2)
{
if (cvy0+cy0<0)
Series6->AddArrow(0,0,gippo/50,0);
else Series6->AddArrow(0,0,-gippo/50,0);
}

}
//---------------------------------------------------------------------------

void __fastcall TRab4::saveMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
// String error protection block
UZ->Text=StrCheck(UZ->Text);
FZ->Text=StrCheck(FZ->Text);
RZ->Text=StrCheck(RZ->Text);
CZ->Text=StrCheck(CZ->Text);
LZ->Text=StrCheck(LZ->Text);
t4.DelLab4(numZ->Value);
// input
t4.NewLab4(numZ->Value, StrToFloat(UZ->Text), StrToFloat(FZ->Text), StrToFloat(RZ->Text), StrToFloat(CZ->Text), StrToFloat(LZ->Text));
t4.Lab4Calc(numZ->Value);
UZ->Text=FloatToStr(t4.GetData(1));
FZ->Text=FloatToStr(t4.GetData(2));
RZ->Text=FloatToStr(t4.GetData(3));
CZ->Text=FloatToStr(t4.GetData(4));
LZ->Text=FloatToStr(t4.GetData(5));
XCZ->Text=FloatToStr(t4.GetData(6));
XLZ->Text=FloatToStr(t4.GetData(7));
ZZ->Text=FloatToStr(t4.GetData(10));
XABZREZ->Text=FloatToStr(t4.GetData(8));
XABIMFZ->Text=FloatToStr(t4.GetData(9));
FIZ->Text=FloatToStr(t4.GetData(11));
//UTZ->Text=FloatToStr(t4.GetData(12));
IlZ->Text=FloatToStr(t4.GetData(13));
UlZ->Text=FloatToStr(t4.GetData(14));
UabZ->Text=FloatToStr(t4.GetData(19));
c0Z->Text=FloatToStr(t4.GetData(15));
d0Z->Text=FloatToStr(t4.GetData(16));
g0Z->Text=FloatToStr(t4.GetData(17));
h0Z->Text=FloatToStr(t4.GetData(18));
FIabZ->Text=FloatToStr(t4.GetData(20));
IcZ->Text=FloatToStr(t4.GetData(21));
IrZ->Text=FloatToStr(t4.GetData(22));
UCZ->Text=FloatToStr(t4.GetData(23));
URZ->Text=FloatToStr(t4.GetData(24));
// graphic block
long double cx0, cy0, cvx0, cvy0, cvx20, cvy20, tetta, gippo, buf, x2, y2, axis;
buf=0;
cx0=StrToFloat(IrZ->Text);
cy0=StrToFloat(IcZ->Text);
cvx0=(StrToFloat(UabZ->Text));//50;
cvy0=0;
cvx20=cx0;
cvy20=cy0;
//if (cvy0+cy0!=0)
tetta=cvx20/cvy20;
//else buf=1;
//if (cvx0+cx0==0)
//buf=2;
if (cvx20>0 && cvy20>0)
axis=1;
else if (cvx20<0 && cvy20>0)
axis=2;
else if (cvx20>0 && cvy20<0)
axis=3;
else if (cvx20<0 && cvy20<0)
axis=4;
gippo=(StrToFloat(UlZ->Text));//50;
x2=sqrt(abs(powl(gippo,2)/(1+sqrt(abs(tetta)))));
x2/=50;
y2=tetta*x2;
if (gippo<0) { x2*=-1; y2*=-1; }
Series1->Clear();
Series2->Clear();
Series3->Clear();
Series4->Clear();
Series5->Clear();
Series6->Clear();
Series1->AddArrow(0,0,cx0,0);
Series2->AddArrow(0,0,0,cy0);
Series3->AddArrow(0,0,cx0,cy0);
Series4->AddArrow(0,0,cvx0/50,cvy0);
if (!buf)
{
if (axis==1)
{
Series6->AddArrow(0,0,-x2,y2);
Series5->AddArrow(0,0,-x2+cvx0/50,y2);
}
else if (axis==2)
{
Series6->AddArrow(0,0,-x2,y2);
Series5->AddArrow(0,0,-x2+cvx0/50,y2);
}
else if (axis==3)
{
Series6->AddArrow(0,0,x2,-y2);
Series5->AddArrow(0,0,x2+cvx0/50,-y2);
}
else if (axis==4)
{
Series6->AddArrow(0,0,x2,-y2);
Series5->AddArrow(0,0,x2+cvx0/50,-y2);
}
}
else if (buf==1)
{
if (cx0+cvx0==0 && cy0+cvy0==0)
buf=1;
else if (cx0+cvx0<0)
Series6->AddArrow(0,0,0,-gippo/50);
else Series6->AddArrow(0,0,0,gippo/50);
}
else if (buf==2)
{
if (cvy0+cy0<0)
Series6->AddArrow(0,0,gippo/50,0);
else Series6->AddArrow(0,0,-gippo/50,0);
}
t4.save();
}
//---------------------------------------------------------------------------


