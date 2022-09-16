//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "logic/header.h"
#include "logic/lab2Z.cpp"
#include "logic/syserr.cpp"
#include "lab2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TLab2 t2;
TRab2 *Rab2;
//---------------------------------------------------------------------------
__fastcall TRab2::TRab2(TComponent* Owner)
        : TForm(Owner)
{
image_m->Picture->LoadFromFile("pic/lab2_main.jpg");
}
//---------------------------------------------------------------------------
void __fastcall TRab2::numZChange(TObject *Sender)
{
Series1->Clear();
bool succes = false;
if (numZ->Value > 0 && numZ->Value < 6)
{
graph->Picture->LoadFromFile("pic/lab2_1.jpg");
}
else if (numZ->Value > 5 && numZ->Value < 11)
graph->Picture->LoadFromFile("pic/lab2_2.jpg");
else if (numZ->Value > 10 && numZ->Value < 16)
graph->Picture->LoadFromFile("pic/lab2_3.jpg");
else if (numZ->Value > 15 && numZ->Value < 21)
graph->Picture->LoadFromFile("pic/lab2_4.jpg");
else if (numZ->Value > 20 && numZ->Value < 26)
graph->Picture->LoadFromFile("pic/lab2_5.jpg");
succes=t2.Change(numZ->Value);
if (succes)
{
wZ->Text=FloatToStr(t2.GetData(1));
SZ->Text=FloatToStr(t2.GetData(2));
TZ->Text=FloatToStr(t2.GetData(3));
FZ->Text=FloatToStr(t2.GetData(4));
B0Z->Text=FloatToStr(t2.GetData(5));
BmZ->Text=FloatToStr(t2.GetData(6));
EmZ->Text=FloatToStr(t2.GetData(7));
FmZ->Text=FloatToStr(t2.GetData(8));
FVZ->Text=FloatToStr(t2.GetData(10));
if (t2.GetData(9)==false)
EVZ->Text="отрицат.";
else EVZ->Text="положит.";
if (t2.GetData(10)==false)
FVZ->Text="Против ЧС";
else FVZ->Text="По ЧС";
if (numZ->Value>0 && numZ->Value<6)
{
Series1->AddXY(0,0);
Series1->AddXY(1,0);
Series1->AddXY(1,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,0);
Series1->AddXY(3,0);
Series1->AddXY(3,StrToFloat(EmZ->Text));
Series1->AddXY(4,StrToFloat(EmZ->Text));
Series1->AddXY(4,0);
Series1->AddXY(5,0);
Series1->AddXY(5,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(6,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(6,0);
Series1->AddXY(7,0);
}
if (numZ->Value>5 && numZ->Value<11)
{
EmZ->Text=FloatToStr(t2.GetData(7)); //double, make it better? hm... it's pity...
Series1->AddXY(0,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(1,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(1,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(2,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(2,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(3,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(3,StrToFloat(EmZ->Text));
Series1->AddXY(4,StrToFloat(EmZ->Text));
Series1->AddXY(4,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(6,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(6,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(7,(-(StrToFloat(EmZ->Text)/3)));
}
if (numZ->Value>10 && numZ->Value<16)
{
for (int i=0; i<=100; i++)
{
Series1->AddXY(i,(StrToFloat(EmZ->Text)*(cos(i*0.02*3.14))));
}
}
if (numZ->Value>15 && numZ->Value<21)
{
for (int i=0; i<=150; i++)
{
Series1->AddXY(i,(StrToFloat(FmZ->Text)*(sin(i*0.02*3.14))));
}
}
if (numZ->Value>20 && numZ->Value<26)
{
Series1->AddXY(0,0);
Series1->AddXY(1,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(1,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(2,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(3,(-(StrToFloat(EmZ->Text)/2)));
Series1->AddXY(3,(-(StrToFloat(EmZ->Text)/2)));
Series1->AddXY(4,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(4,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(6,0);
Series1->AddXY(6,0);
Series1->AddXY(7,0);
}
}
else
{
wZ->Text=0;
SZ->Text=0;
TZ->Text=0;
FZ->Text=0;
B0Z->Text=0;
BmZ->Text=0;
EmZ->Text=0;
FmZ->Text=0;
FVZ->Text="       ?";
EVZ->Text="       ?";
}
}
//---------------------------------------------------------------------------



void __fastcall TRab2::FormClose(TObject *Sender, TCloseAction &Action)
{
//Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TRab2::resultMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Series1->Clear();
// input
if (numZ->Value > 0 && numZ->Value < 6)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(BmZ->Text), StrToFloat(TZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_1.jpg");
t2.Lab2Calc();
EmZ->Text=FloatToStr(t2.GetData(7)); //double, make it better? hm... it's pity...
Series1->AddXY(0,0);
Series1->AddXY(1,0);
Series1->AddXY(1,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,0);
Series1->AddXY(3,0);
Series1->AddXY(3,StrToFloat(EmZ->Text));
Series1->AddXY(4,StrToFloat(EmZ->Text));
Series1->AddXY(4,0);
Series1->AddXY(5,0);
Series1->AddXY(5,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(6,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(6,0);
Series1->AddXY(7,0);
}
else if (numZ->Value > 5 && numZ->Value < 11)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(FmZ->Text), StrToFloat(TZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_2.jpg");
t2.Lab2Calc();
EmZ->Text=FloatToStr(t2.GetData(7)); //double, make it better? hm... it's pity...
Series1->AddXY(0,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(1,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(1,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(2,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(2,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(3,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(3,StrToFloat(EmZ->Text));
Series1->AddXY(4,StrToFloat(EmZ->Text));
Series1->AddXY(4,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(6,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(6,(-(StrToFloat(EmZ->Text)/3)));
Series1->AddXY(7,(-(StrToFloat(EmZ->Text)/3)));
}
else if (numZ->Value > 10 && numZ->Value < 16)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(FmZ->Text), StrToFloat(FZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_3.jpg");
t2.Lab2Calc();
EmZ->Text=FloatToStr(t2.GetData(7)); //double, make it better? hm... it's pity...
for (int i=0; i<=100; i++)
{
//Em=//((3*StrToFloat(wZ->Text)*3.14*StrToFloat(FZ->Text))/2)*StrToFloat(FmZ->Text)*powl(10,-6)
Series1->AddXY(i,(StrToFloat(EmZ->Text)*(cos(i*0.02*3.14))));
}
}
else if (numZ->Value > 15 && numZ->Value < 21)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(EmZ->Text), StrToFloat(TZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_4.jpg");
t2.Lab2Calc();
for (int i=0; i<=150; i++)
{
Series1->AddXY(i,(StrToFloat(FmZ->Text)*(sin(i*0.02*3.14))));
}
}
else if (numZ->Value > 20 && numZ->Value < 26)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(EmZ->Text), StrToFloat(TZ->Text), StrToFloat(B0Z->Text));
graph->Picture->LoadFromFile("pic/lab2_5.jpg");
t2.Lab2Calc();
Series1->AddXY(0,0);
Series1->AddXY(1,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(1,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(2,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(3,(-(StrToFloat(EmZ->Text)/2)));
Series1->AddXY(3,(-(StrToFloat(EmZ->Text)/2)));
Series1->AddXY(4,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(4,(-(3*StrToFloat(EmZ->Text)/4)));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(5,(-(StrToFloat(EmZ->Text))));
Series1->AddXY(6,0);
Series1->AddXY(6,0);
Series1->AddXY(7,0);
}
// output
wZ->Text=FloatToStr(t2.GetData(1));
SZ->Text=FloatToStr(t2.GetData(2));
TZ->Text=FloatToStr(t2.GetData(3));
FZ->Text=FloatToStr(t2.GetData(4));
B0Z->Text=FloatToStr(t2.GetData(5));
BmZ->Text=FloatToStr(t2.GetData(6));
EmZ->Text=FloatToStr(t2.GetData(7)); //double, make it better?
FmZ->Text=FloatToStr(t2.GetData(8));
if (t2.GetData(9)==false)
EVZ->Text="отрицат.";
else EVZ->Text="положит.";
if (t2.GetData(10)==false)
FVZ->Text="Против ЧС";
else FVZ->Text="По ЧС";
}
//---------------------------------------------------------------------------

void __fastcall TRab2::saveMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
t2.DelLab2(numZ->Value);
// input
if (numZ->Value > 0 && numZ->Value < 6)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(BmZ->Text), StrToFloat(TZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_1.jpg");
t2.Lab2Calc();
EmZ->Text=FloatToStr(t2.GetData(7)); //double, make it better? hm... it's pity...
Series1->AddXY(0,0);
Series1->AddXY(1,0);
Series1->AddXY(1,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(2,0);
Series1->AddXY(3,0);
Series1->AddXY(3,StrToFloat(EmZ->Text));
Series1->AddXY(4,StrToFloat(EmZ->Text));
Series1->AddXY(4,0);
Series1->AddXY(5,0);
Series1->AddXY(5,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(6,(-(StrToFloat(EmZ->Text)/4)));
Series1->AddXY(6,0);
Series1->AddXY(7,0);
}
else if (numZ->Value > 5 && numZ->Value < 11)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(FmZ->Text), StrToFloat(TZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_2.jpg");
t2.Lab2Calc();
}
else if (numZ->Value > 10 && numZ->Value < 16)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(FmZ->Text), StrToFloat(FZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_3.jpg");
t2.Lab2Calc();
}
else if (numZ->Value > 15 && numZ->Value < 21)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(EmZ->Text), StrToFloat(TZ->Text), 0);
graph->Picture->LoadFromFile("pic/lab2_4.jpg");
t2.Lab2Calc();
}
else if (numZ->Value > 20 && numZ->Value < 26)
{
t2.NewLab2(numZ->Value, StrToFloat(wZ->Text), StrToFloat(SZ->Text), StrToFloat(EmZ->Text), StrToFloat(TZ->Text), StrToFloat(B0Z->Text));
graph->Picture->LoadFromFile("pic/lab2_5.jpg");
t2.Lab2Calc();
}
// output
wZ->Text=FloatToStr(t2.GetData(1));
SZ->Text=FloatToStr(t2.GetData(2));
TZ->Text=FloatToStr(t2.GetData(3));
FZ->Text=FloatToStr(t2.GetData(4));
B0Z->Text=FloatToStr(t2.GetData(5));
BmZ->Text=FloatToStr(t2.GetData(6));
EmZ->Text=FloatToStr(t2.GetData(7)); //double, make it better?
FmZ->Text=FloatToStr(t2.GetData(8));
FVZ->Text=FloatToStr(t2.GetData(10));
if (t2.GetData(9)==false)
EVZ->Text="отрицат.";
else EVZ->Text="положит.";
if (t2.GetData(10)==false)
FVZ->Text="Против ЧС";
else FVZ->Text="По ЧС";
t2.save();
}
//---------------------------------------------------------------------------

