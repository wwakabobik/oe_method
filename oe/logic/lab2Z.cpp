#ifndef __LAB2Z_CPP
#define __LAB2Z_CPP 1

#include "header.h"
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>
#include <fstream.h>

char filename[] = "2.dat";

TLab2::TLab2()
{
number=0; w=0; s=0; T=0; F=0; Bm=0; B0=0; Em=0; Fm=0; EV=0; FV=0;
}


TLab2::~TLab2()
{
number=0; w=0; s=0; T=0; F=0; Bm=0; B0=0; Em=0; Fm=0; EV=0; FV=0;
}

long double TLab2::GetData(int stat)
{
  switch(stat)
  {
    case 1:    return w;
    case 2:    return s;
    case 3:    return T;
    case 4:    return F;
    case 5:    return B0;
    case 6:    return Bm;
    case 7:    return Em;
    case 8:    return Fm;
    case 9:    return EV;
    case 10:   return FV;
    default:   return 0;
    }
}


bool TLab2::Change(int num0)
{
  ifstream r;
  r.open(filename);
  r >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
  while (!r.eof())
  {
    if (number==num0)
    { r.close(); return true;}
  r >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
  }
  r.close();
  return false;
}

void TLab2::Lab2Calc()
{
if (number>0 && number<6)
{
F=1/(T*0.001);
Em=((-w*s*(-Bm-Bm))/((4*T-3*T)*0.001))*0.000001;
Fm=Bm*s*0.000001*powl(10,6);
EV=true;
FV=false;
}
if (number>5 && number<11)
{
F=1/(T*0.001);
Em=w*s*0.000001*((2*Fm*powl(10,-6))/(3*T*0.001));
Bm=(Fm*powl(10,-6))/(s*0.000001);
EV=true;
FV=false;
}
if (number>10 && number<16)
{
T=(1/F)*1000;
//w=2*3.14*F;
Em=(3*s*0.000001*w*3.14*F/2)*Fm*powl(10,-6);
Bm=(Fm*powl(10,-6))/(s*0.000001);
EV=true;
FV=false;
}
if (number>15 && number<21)
{
F=1/(T*0.001);
Fm=-(Em/(2*w*T*0.001));
Bm=(Fm)/(s*0.000001);
EV=false;
FV=true;
}
if (number>20 && number<26)
{
F=1/(T*0.001);
Fm=-Em/(w*T*0.001);
Bm=(Fm)/(s*0.000001);
EV=false;
FV=true;
}
}

void TLab2::save(void)
{
  int err=0;
  int num0=number;
  ifstream r,r2;
  ofstream w1,w2;
  w2.open(tempname);
  w2 << number << " " << w << " " << s << " " << T << " " << F << " " << Bm << " " << B0 << " " << Em << " " << Fm << " " << EV << " " << FV << endl;
  w2.close();
  r.open(filename);
  r >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
  while (!r.eof())
  {
  if (number==num0)
  { cout << "\n\n\007Number already exist, please delete it before you can add"; err++; break;}
  r >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
  }
  r.close();
  if (err==0)
  {
  r2.open(tempname);
  r2 >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
  r2.close();
  w1.open(filename,ios::app);
  w1 << number << " " << w << " " << s << " " << T << " " << F << " " << Bm << " " << B0 << " " << Em << " " << Fm << " " << EV << " " << FV << endl;
  w1.close();
  }
  w2.open(tempname,ios::trunc);
  w2.close();
}

void TLab2::NewLab2(long double num0, long double par1, long double par2, long double par3, long double par4, long double par5)
{
  number=num0;
  if (number > 0 && number < 6)
  { w = par1; s = par2; Bm = par3; T = par4;  }
  else if (number > 5 && number < 11)
  { w = par1; s = par2; Fm = par3; T = par4;  }
  else if (number > 10 && number < 16)
  { w = par1; s = par2; Fm = par3; F = par4;  }
  else if (number > 15 && number < 21)
  { w = par1; s = par2; Em = par3; T = par4;  }
  else if (number > 20 && number < 26)
  { w = par1; s = par2; Em = par3; T = par4; B0=par5;  }
}

void TLab2::DelLab2(int num0)
{
ifstream r, r2;
ofstream w1, w2;
r.open(filename);
w1.open(tempname);
r >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
while (!r.eof())
{
if (number!=num0)
w1 << number << " " << w << " " << s << " " << T << " " << F << " " << Bm << " " << B0 << " " << Em << " " << Fm << " " << EV << " " << FV << endl;
r >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
}
w1.close();
r.close();
w1.open(filename,ios::trunc);
w1.close();
w2.open(filename);
r2.open(tempname);
r2 >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;

while (!r2.eof())
{
w2 << number << " " << w << " " << s << " " << T << " " << F << " " << Bm << " " << B0 << " " << Em << " " << Fm << " " << EV << " " << FV << endl;
r2 >> number >> w >> s >> T >> F >> Bm >> B0 >> Em >> Fm >> EV >> FV;
}
w2.close();
r2.close();
w2.open(tempname,ios::trunc);
w2.close();
}

#endif
