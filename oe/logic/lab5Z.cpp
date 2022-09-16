#ifndef __LAB5Z_CPP
#define __LAB5Z_CPP 1

#include "header.h"
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>
#include <fstream.h>

char filename[] = "5.dat";
//char tempname[] = "swap.tmp";

TLab5::TLab5()
{
number = 0;
I=0; w=0; delta=0; B=0; c=0; e=0; D=0; d=0; h=0; F=0;
}

TLab5::~TLab5()
{
number = 0;
I=0; w=0; delta=0; B=0; c=0; e=0; D=0; d=0; h=0; F=0;
}

bool TLab5::Change(int num0)
{
  ifstream r;
  r.open(filename);
  r >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
  while (!r.eof())
  {
    if (number==num0)
    { r.close(); return true;}
  r >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
  }
  r.close();
  return false;
}

long double TLab5::GetData(int stat)
{
  switch(stat)
  {
    case 1:    return I;
    case 2:    return w;
    case 3:    return delta;
    case 4:    return a;
    case 5:    return c;
    case 6:    return e;
    case 7:    return D;
    case 8:    return d;
    case 9:    return h;
    case 10:   return bk;
    case 11:   return hk;
    case 12:   return B;
    case 13:   return hc;
    case 14:   return hd;
    case 15:   return umc;
    case 16:   return umd;
    case 17:   return F;
    case 18:   return L;
    default:   return 0;
    }
}


void TLab5::save(void)
{
int err=0;
int num0=number;
ofstream w1,w2;
ifstream r,r2;
w2.open(tempname);
w2 << number << " " << I << " " << w << " " << delta << " " << a << " " << c << " " << e << " " << D << " " << d << " " << h <<" " << bk << " " << hk << " " << B << " " << hc << " " << hd << " " << umc << " " << umd << " " << F << " " << L << endl;
w2.close();
r.open(filename);
r >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
while (!r.eof())
{
if (number==num0)
{ cout << "\n\n\007Number already exist, please delete it before you can add"; err++; break;}
r >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
}
r.close();
if (err==0)
{
r2.open(tempname);
r2 >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
r2.close();
w1.open(filename,ios::app);
w1 << number << " " << I << " " << w << " " << delta << " " << a << " " << c << " " << e << " " << D << " " << d << " " << h <<" " << bk << " " << hk << " " << B << " " << hc << " " << hd << " " << umc << " " << umd << " " << F << " " << L << endl;
w1.close();
}
w2.open(tempname,ios::trunc);
w2.close();
}

void TLab5::NewLab5(int num0, long double I0, long double w0, long double delta0,   long double a0, long double c0, long double e0, long double D0, long double d0, long double h0)
{
  number=num0; I=I0; w=w0; delta=delta0; a=a0; c=c0; e=e0; D=D0; d=d0; h=h0;
}

void TLab5::DelLab5(int num0)
{
  ifstream r, r2;
  ofstream w1, w2;
  r.open(filename);
  w1.open(tempname);
  r >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
  while (!r.eof())
  {
  if (number!=num0)
  w1 << number << " " << I << " " << w << " " << delta << " " << a << " " << c << " " << e << " " << D << " " << d << " " << h <<" " << bk << " " << hk << " " << B << " " << hc << " " << hd << " " << umc << " " << umd << " " << F << " " << L << endl;
  r >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
  }
  w1.close();
  r.close();
  w1.open(filename,ios::trunc);
  w1.close();
  w2.open(filename);
  r2.open(tempname);
  r2 >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
  while (!r2.eof())
  {
  w2 << number << " " << I << " " << w << " " << delta << " " << a << " " << c << " " << e << " " << D << " " << d << " " << h <<" " << bk << " " << hk << " " << B << " " << hc << " " << hd << " " << umc << " " << umd << " " << F << " " << L << endl;
  r2 >> number >> I >> w >> delta >> a >> c >> e >> D >> d >> h >> bk >> hk >> B >> hc >> hd >> umc >> umd >> F >> L;
  }
  w2.close();
  r2.close();
  w2.open(tempname,ios::trunc);
  w2.close();
}

void TLab5::Lab5Calc(int num0)
{
  number = num0;
  if (number > 0 && number < 26)
  {
  long double mm=powl(10,-3);
  long double mju0=4*M_PI*powl(10,-7);
  long double l,d0,D0,del0,h0;
  d0=d;
  D0=D;
  del0=delta;
  h0=h;
  d*=mm;
  D*=mm;
  delta*=mm;
  h*=mm;
  l=(M_PI*(D*mm+d*mm))/2;
  hk=e/(a-c);
  bk=hk*mju0;
  B=((I*w*c+e*l)*mju0)/(delta*c+l*mju0);
  F=B*(D-d)*h*0.5;
  if (B>bk)
  hc=(B-e)/c;
  else
  hc=B/a;
  hd=B/mju0;
  umc=hc*l;
  umd=hd*delta;
  L=(w*F)/I;
  d=d0;
  D=D0;
  delta=del0;
  h=h0;
  F*=1000;
  L*=1000;
  hd/=1000;
  }
}

#endif
