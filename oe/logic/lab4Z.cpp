#ifndef __LAB4Z_CPP
#define __LAB4Z_CPP 1

#include "header.h"
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>
#include <fstream.h>

char filename[] = "4.dat";

TLab4::TLab4()
{
number=0; U=0; F=0; R=0; C=0; l=0;
xl=0; xc=0; xab1=0; xab2=0; z=0; fi=0; ut=0; il=0; ul=0; c=0; d=0; g=0; h=0; uab=0; fiab=0; ic=0; ir=0;
}

TLab4::~TLab4()
{
number=0; U=0; F=0; R=0; C=0; l=0;
xl=0; xc=0; xab1=0; xab2=0; z=0; fi=0; ut=0; il=0; ul=0; c=0; d=0; g=0; h=0; uab=0; fiab=0; ic=0; ir=0;
}

void TLab4::Lab4Calc(int num0)
{
  const long double pi=3.14;
if (number>0 && number<6)
{
xl=(2*pi*F*l)/1000;
xc=1/(2*pi*F*C/1000000);
xab1=(R*xc*xc)/(R*R+xc*xc);
xab2=(R*R*xc)/(R*R+xc*xc);
z=sqrt(xab1*xab1+((xl-xab2)*(xl-xab2)));
fi=atan((xl-xab2)/xab1);
ut=U;
il=ut/z;
ul=il*xl;
c=ul*cos((pi/2)-fi);
d=ul*sin((pi/2)-fi);
g=ut-c;
h=-d;
uab=sqrt(g*g+h*h);
fiab=atan(h/g);
ic=uab/xc;
ir=uab/R;
uc=0;
ur=0;
  }
// какая уверенность в том, что I=U/z???
// и что Uab=U?
if (number > 5 && number < 11)
{
long double xc0, xl0;
xl=(2*pi*F*l)/1000;
xc=1/(2*pi*F*C/1000000);
xab1=(xl*xl*R)/(R*R+xl*xl);
xab2=(R*R*xl)/(R*R+xl*xl)-xc;
z=sqrt(xab1*xab1+xab2*xab2);
fi=atan(xab2/xab1);
ut=U;
ic=ut/z; //??? это поебистика!!!
uc=ic*xc;
ul=-(U-uc); //llll
ur=ul;
ir=ur/R;
il=ul/xl;
uab=U-uc;
}
if (number > 10 && number < 16)
  {
xl=(2*pi*F*l)/1000;
xc=1/(2*pi*F*C/1000000);
xab1=(xl*xl*R)/(R*R+(xl-xc)*(xl-xc));
xab2=(xl*R*R-xl*xc*(xl-xc))/(R*R+(xl-xc)*(xl-xc));
ut=U;
z=sqrt(xab1*xab1+xab2*xab2);
fi=atan(xab2/xab1);
il=U/xl;
c=sqrt(R*R+xc*xc); //? мя плющит!!! ну не г?
fiab=atan(xc/R);
ir=U/c; // ВАС???
//ir=c;
ic=ir;
//ul=ic*xc;
ul=U;
uab=U; // ir*R
uc=ic*xc;
ur=ir*R;
  }
if (number > 15 && number < 21)
  {
xl=(2*pi*F*l)/1000;
xc=1/(2*pi*F*C/1000000);
xab1=(R*xc*xc)/(R*R+(xl-xc)*(xl-xc));
xab2=(xc*R+xc*xl*(xl-xc))/(R*R+(xl-xc)*(xl-xc));
xab2=-xab2;
z=sqrt(xab1*xab1+xab2*xab2);
fi=atan(xab2/xab1);
uab=U;
uc=U;
ic=uc/xc;
// il=ic-U/z;
il=ic-U/z;
ir=il;
ur=ir*R;
ul=il*xl;
  }
if (number > 20 && number < 26)
{
xl=(2*pi*F*l)/1000;
xc=1/(2*pi*F*C/1000000);
xab1=(R*(xl-xc)*(xl-xc))/((xl-xc)*(xl-xc));
xab2=(R*R*(xl-xc))/((xl-xc)*(xl-xc));
z=sqrt(xab1*xab1+xab2*xab2);
fi=atan(xab2/xab1);
ur=U;
ut=U;
ir=ur/R;
il=U/z-ir;
ic=il;
ul=il*xl;
uc=il*xc;
uab=ur;
}
}

void TLab4::save(void)
{
  int err=0;
  int num0=number;
  ofstream w,w2;
  ifstream r,r2;
  w2.open(tempname);
  w2 << number << " " << U << " " << F << " " << R << " " << C << " " << l << " " << xl << " " << xc << " " << xab1 << " " << xab2  << " " << z  << " " <<  fi << " " <<  ut << " " <<  il << " " <<  ul  << " " <<  c  << " " <<  d << " " <<  g  << " " <<  h << " " <<  uab << " " <<  fiab  << " " <<  ic << " " <<  ir  << " "<< uc << " " << ur;
  w2.close();
  r.open(filename);
  r >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
  while (!r.eof())
  {
  if (number==num0)
  { cout << "\n\n\007Number already exist, please delete it before you can add"; err++; break;}
  r >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
  }
  r.close();
  if (err==0)
  {
  r2.open(tempname);
  r2 >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
  r2.close();
  w.open(filename,ios::app);
  w << number << " " << U << " " << F << " " << R << " " << C << " " << l << " " << xl << " " << xc << " " << xab1 << " " << xab2  << " " << z  << " " <<  fi << " " <<  ut << " " <<  il << " " <<  ul  << " " <<  c  << " " <<  d << " " <<  g  << " " <<  h << " " <<  uab << " " <<  fiab  << " " <<  ic << " " <<  ir << " "<< uc << " " << ur << endl;
  w.close();
  }
  w2.open(tempname,ios::trunc);
  w2.close();
}

bool TLab4::Change(int num0)
{
  ifstream r;
  r.open(filename);
  r >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
  while (!r.eof())
  {
    if (number==num0)
    { r.close(); return true;}
  r >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
  }
  r.close();
  return false;
}

void TLab4::NewLab4(int num0, long double U0, long double F0, long double R0, long double C0, long double l0)
{
number=num0; U=U0; F=F0; R=R0; C=C0; l=l0;
}

void TLab4::NewData4(long double xl0, long double xc0, long double xab10, long double xab20, long double z0, long double fi0, long double ut0, long double il0, long double  ul0, long double  c0, long double  d0, long double  g0, long double  h0, long double  uab0, long double  fiab0, long double  ic0, long double  ir0)
{
xl=xl0; xc=xc0; xab1=xab10; xab2=xab20; z=z0; fi=fi0; ut=ut0; il=il0; ul=ul0; c=c0; d=d0; g=g0; h=h0; uab=uab0; fiab=fiab0; ic=ic0; ir=ir0;
}

long double TLab4::GetData(int stat)
{
  switch(stat)
  {
    case 1:    return U;
    case 2:    return F;
    case 3:    return R;
    case 4:    return C;
    case 5:    return l;
    case 6:    return xc;
    case 7:    return xl;
    case 8:    return xab1;
    case 9:    return xab2;
    case 10:   return z;
    case 11:   return fi;
    case 12:   return ut;
    case 13:   return il;
    case 14:   return ul;
    case 15:   return c;
    case 16:   return d;
    case 17:   return g;
    case 18:   return h;
    case 19:   return uab;
    case 20:   return fiab;
    case 21:   return ic;
    case 22:   return ir;
    case 23:   return uc;
    case 24:   return ur;
    default:   return 0;
    }
}

void TLab4::DelLab4(int num0)
{
ifstream r, r2;
ofstream w, w2;
r.open(filename);
w.open(tempname);
r >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
while (!r.eof())
{
if (number!=num0)
w << number << " " << U << " " << F << " " << R << " " << C << " " << l << " " << xl << " " << xc << " " << xab1 << " " << xab2  << " " << z  << " " <<  fi << " " <<  ut << " " <<  il << " " <<  ul  << " " <<  c  << " " <<  d << " " <<  g  << " " <<  h << " " <<  uab << " " <<  fiab  << " " <<  ic << " " <<  ir  << " " << uc << " " << ur << endl;
r >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
}
w.close();
r.close();
w.open(filename,ios::trunc);
w.close();
w2.open(filename);
r2.open(tempname);
r2 >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
while (!r2.eof())
{
w2 << number << " " << U << " " << F << " " << R << " " << C << " " << l << " " << xl << " " << xc << " " << xab1 << " " << xab2  << " " << z  << " " <<  fi << " " <<  ut << " " <<  il << " " <<  ul  << " " <<  c  << " " <<  d << " " <<  g  << " " <<  h << " " <<  uab << " " <<  fiab  << " " <<  ic << " " <<  ir  << " "<< uc << " " << ur << endl;
r2 >> number >> U >>  F >> R >>  C >> l >> xl >> xc >> xab1 >> xab2  >> z  >>  fi >>  ut >>  il >>  ul  >>  c  >>  d >>  g  >>  h >>  uab >>  fiab  >>  ic >>  ir >> uc >> ur;
}
w2.close();
r2.close();
w2.open(tempname,ios::trunc);
w2.close();

}

#endif
