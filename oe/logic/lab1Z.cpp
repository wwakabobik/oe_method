#ifndef __LAB1Z_CPP
#define __LAB1Z_CPP 1

#include "header.h"
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>
#include <fstream.h>

const long double nu0=4*3.14*0.0000001;

char filename[] = "1.dat";

TLab1::TLab1()
{
  number=0;
  I1=0;  I2=0;  I3=0;  I4=0;  I5=0;  I6=0;  I7=0;  I8=0;
  nu = 0; l=0; S=0; delta =0;
  W1=0;   W2=0;  W3=0;  W4=0;  W5=0;  W6=0;  W7=0;  W8=0;
  Hs = 0; Hd = 0; Us = 0; Ud = 0; Bs = 0;Bd = 0; Fs = 0; Fd = 0; FVs = 0; FVd = 0;
}


TLab1::~TLab1()
{
  number=0;
  I1=0;  I2=0;  I3=0;  I4=0;  I5=0;  I6=0;  I7=0;  I8=0;
  nu = 0; l=0; S=0; delta =0;
  W1=0;   W2=0;  W3=0;  W4=0;  W5=0;  W6=0;  W7=0;  W8=0;
  Hs = 0; Hd = 0; Us = 0; Ud = 0; Bs = 0;Bd = 0; Fs = 0; Fd = 0; FVs = 0; FVd = 0;
}

void TLab1::CalcNum(int num0)
{
  delta/=1000;
  S/=1000000;
  l/=1000;
  if (num0 > 0 && num0 < 26)
  {
    Hs=(I1*W1+I2*W2-I3*W3-I4+I5)/(l+nu*delta);
    Hd=nu*Hs;
    Us=Hs*l;
    Ud=Hd*delta;
    Bs=nu0*Hd;
    Bd=Bs;
    Fs=Bs*S;
    Fd=Fs;
    if (Fd<0)
    {
    FVs=false;
    FVd=false;
    }
    else
    {
    FVs=true;
    FVd=true;
    }
  }
  delta*=1000;
  S*=1000000;
  l*=1000;
}

bool TLab1::Change(int num0)
{
  ifstream r;
  r.open(filename);
  r >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
  while (!r.eof())
  {
    if (number==num0)
    { r.close(); return true;}
  r >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
  }
  r.close();
  return false;
}

long double TLab1::GetData(int stat)
{
  switch(stat)
  {
    case 1:    return I1;
    case 2:    return I2;
    case 3:    return I3;
    case 4:    return I4;
    case 5:    return I5;
    case 6:    return I6;
    case 7:    return I7;
    case 8:    return I8;
    case 9:    return W1;
    case 10:   return W2;
    case 11:   return W3;
    case 12:   return W4;
    case 13:   return W5;
    case 14:   return W6;
    case 15:   return W7;
    case 16:   return W8;
    case 17:   return nu;
    case 18:   return l;
    case 19:   return S;
    case 20:   return delta;
    case 21:   return Hs;
    case 22:   return Hd;
    case 23:   return Us;
    case 24:   return Ud;
    case 25:   return Bs;
    case 26:   return Fs;
    case 27:   return FVs;
    default:   return 0;
    }
}

void TLab1::save(void)
{
int err=0;
ifstream r,r2;
ofstream w,w2;
int num0=number;
w2.open(tempname);
w2 << number << " " << I1 << " "  <<  I2 << " " <<  I3 << " " <<  I4 << " " <<  I5 << " " <<  I6 << " " <<  I7 << " " <<  I8 << " " << nu << " " <<  l << " " <<  S << " " <<  delta << " " <<  W1 << " " <<  W2 << " " <<  W3 << " " <<  W4 << " " <<  W5 << " " <<  W6 << " " <<  W7 << " " <<  W8 << " " <<  Hs << " " <<  Hd << " " <<  Us << " " <<  Ud << " " <<  Bs << " " <<  Bd << " " <<  Fs << " " <<  Fd << " " <<  FVs << " " <<  FVd<< endl;
w2.close();
r.open(filename);
r >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
while (!r.eof())
{
  if (number==num0)
  { cout << "\n\n\007Number already exist, please delete it before you can add"; err++; break;}
r >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
}
r.close();
if (err==0)
{
r2.open(tempname);
r2 >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
r2.close();
w.open(filename,ios::app);
w << number << " " << I1 << " "  <<  I2 << " " <<  I3 << " " <<  I4 << " " <<  I5 << " " <<  I6 << " " <<  I7 << " " <<  I8 << " " << nu << " " <<  l << " " <<  S << " " <<  delta << " " <<  W1 << " " <<  W2 << " " <<  W3 << " " <<  W4 << " " <<  W5 << " " <<  W6 << " " <<  W7 << " " <<  W8 << " " <<  Hs << " " <<  Hd << " " <<  Us << " " <<  Ud << " " <<  Bs << " " <<  Bd << " " <<  Fs << " " <<  Fd << " " <<  FVs << " " <<  FVd << endl;
w.close();
}
w2.open(tempname,ios::trunc);
w2.close();
}

void TLab1::NewNum(int num0)
{
  number=num0;
}

void TLab1::NewCurrent(float I01, float I02, float I03, float I04, float I05, float I06, float I07, float I08)
{
  I1=I01; I2=I02; I3=I03; I4=I04; I5=I05; I6=I06; I7=I07; I8=I08;
}
void TLab1::NewCoil(int W01, int W02, int W03, int W04, int W05, int W06, int W07, int W08)
{
  W1=W01; W2=W02; W3=W03; W4=W04; W5=W05; W6=W06; W7=W07; W8=W08;
}
void TLab1::NewVector(bool IV01, bool IV02, bool IV03, bool IV04, bool IV05, bool IV06, bool IV07, bool IV08)
{
  IV1=IV01; IV2=IV02; IV3=IV03; IV4=IV04; IV5=IV05; IV6=IV06; IV7=IV07; IV8=IV08;
}
void TLab1::NewOther(long double nu00, long double l0, long double S0, long double delta0)
{
  nu=nu00; l=l0; S=S0; delta=delta0;
}

void TLab1::DelNum(int num0)
{
  ifstream r, r2;
  ofstream w, w2;
  r.open(filename);
  w.open(tempname);
  r >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
  while (!r.eof())
  {
  if (number!=num0)
  w << number << " " << I1 << " "  <<  I2 << " " <<  I3 << " " <<  I4 << " " <<  I5 << " " <<  I6 << " " <<  I7 << " " <<  I8 << " " << nu << " " <<  l << " " <<  S << " " <<  delta << " " <<  W1 << " " <<  W2 << " " <<  W3 << " " <<  W4 << " " <<  W5 << " " <<  W6 << " " <<  W7 << " " <<  W8 << " " <<  Hs << " " <<  Hd << " " <<  Us << " " <<  Ud << " " <<  Bs << " " <<  Bd << " " <<  Fs << " " <<  Fd << " " <<  FVs << " " <<  FVd<< endl;
  r >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
  }
  w.close();
  r.close();
  w.open(filename,ios::trunc);
  w.close();
  w2.open(filename);
  r2.open(tempname);
  r2 >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
  while (!r2.eof())
  {
  w2 << number << " " << I1 << " "  <<  I2 << " " <<  I3 << " " <<  I4 << " " <<  I5 << " " <<  I6 << " " <<  I7 << " " <<  I8 << " " << nu << " " <<  l << " " <<  S << " " <<  delta << " " <<  W1 << " " <<  W2 << " " <<  W3 << " " <<  W4 << " " <<  W5 << " " <<  W6 << " " <<  W7 << " " <<  W8 << " " <<  Hs << " " <<  Hd << " " <<  Us << " " <<  Ud << " " <<  Bs << " " <<  Bd << " " <<  Fs << " " <<  Fd << " " <<  FVs << " " <<  FVd << endl;
  r2 >> number >> I1 >>  I2 >> I3 >>  I4 >> I5 >> I6 >> I7 >> I8 >> nu  >>  l  >>  S >>  delta >>  W1 >>  W2  >>  W3  >>  W4 >>  W5  >>  W6 >>  W7 >>  W8  >>  Hs >>  Hd >>  Us >>  Ud >>  Bs >>  Bd  >>  Fs >>  Fd >>  FVs  >>  FVd;
  }
  w2.close();
  r2.close();
  w2.open(tempname,ios::trunc);
  w2.close();
}

#endif
