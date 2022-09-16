#ifndef __LAB3Z_CPP
#define __LAB3Z_CPP 1

#include "header.h"
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>
#include <fstream.h>

char filename[] = "3.dat";

TLab3::TLab3()
{
number = 0;
R1=0; R2=0; R3=0; R4=0; R5=0; R6=0;
E1=0; E2=0; E3=0; J=0;
I1=0; I2=0; I3=0; I4=0; I5=0; I6=0; fi1=0; fi2=0;
}

TLab3::~TLab3()
{
  number = 0;
  R1=0; R2=0; R3=0; R4=0; R5=0; R6=0;
  E1=0; E2=0; E3=0; J=0;
  I1=0; I2=0; I3=0; I4=0; I5=0; I6=0; fi1=0; fi2=0;
}

bool TLab3::Change(int num0)
{
  ifstream r;
  r.open(filename);
  r >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
  while (!r.eof())
  {
    if (number==num0)
    { r.close(); return true;}
  r >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
  }
  r.close();
  return false;
}

long double TLab3::GetData(int stat)
{
  switch(stat)
  {
    case 1:    return I1;
    case 2:    return I2;
    case 3:    return I3;
    case 4:    return I4;
    case 5:    return I5;
    case 6:    return I6;
    case 7:    return R1;
    case 8:    return R2;
    case 9:    return R3;
    case 10:   return R4;
    case 11:   return R5;
    case 12:   return R6;
    case 13:   return J;
    case 14:   return fi1;
    case 15:   return fi2;
    case 16:   return E1;
    case 17:   return E2;
    case 18:   return E3;
    default:   return 0;
    }
}


void TLab3::save(void)
{
int err=0;
int num0=number;
ofstream w,w2;
ifstream r,r2;
w2.open(tempname);
w2 << number << " " << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << " " << E1 << " " << E2 << " " << E3 << " " << J << " " << I1 << " " << I2 << " " << I3 << " " << I4 << " " << I5 << " " << I6 << " " << fi1 << " " << fi2;
w2.close();
r.open(filename);
r >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
while (!r.eof())
{
if (number==num0)
{ cout << "\n\n\007Number already exist, please delete it before you can add"; err++; break;}
r >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
}
r.close();
if (err==0)
{
r2.open(tempname);
r2 >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
r2.close();
w.open(filename,ios::app);
w << number << " " << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << " " << E1 << " " << E2 << " " << E3 << " " << J << " " << I1 << " " << I2 << " " << I3 << " " << I4 << " " << I5 << " " << I6 << " " << fi1 << " " << fi2 << endl;
w.close();
}
w2.open(tempname,ios::trunc);
w2.close();
}

void TLab3::NewLab3(int num0)
{
  number=num0;
}
void TLab3::NewResist(long double R01, long double R02, long double R03, long double R04, long double R05, long double R06)
{
  R1=R01;   R2=R02;   R3=R03;   R4=R04;   R5=R05;   R6=R06;
}

void TLab3::NewEDS(long double E01, long double E02, long double E03, long double J0)
{
  E1=E01; E2=E02; J=J0;
}

void TLab3::DelLab3(int num0)
{
  ifstream r, r2;
  ofstream w, w2;
  r.open(filename);
  w.open(tempname);
  r >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
  while (!r.eof())
  {
  if (number!=num0)
  w << number << " " << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << " " << E1 << " " << E2 << " " << E3 << " " << J << " " << I1 << " " << I2 << " " << I3 << " " << I4 << " " << I5 << " " << I6 << " " << fi1 << " " << fi2 << endl;
  r >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
  }
  w.close();
  r.close();
  w.open(filename,ios::trunc);
  w.close();
  w2.open(filename);
  r2.open(tempname);
  r2 >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
  while (!r2.eof())
  {
  w2 << number << " " << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << " " << E1 << " " << E2 << " " << E3 << " " << J << " " << I1 << " " << I2 << " " << I3 << " " << I4 << " " << I5 << " " << I6 << " " << fi1 << " " << fi2 << endl;
  r2 >> number >> R1 >> R2 >> R3 >> R4 >> R5 >> R6 >> E1 >> E2 >> E3 >> J >> I1 >> I2 >> I3 >> I4 >> I5 >> I6 >> fi1 >> fi2;
  }
  w2.close();
  r2.close();
  w2.open(tempname,ios::trunc);
  w2.close();
}

void TLab3::Lab3Calc(int num0)
{
  number = num0;
  if (number > 0 && number < 6)
  {
    I1=((R3*E1*R2+E1*R4*R2+R4*R3*E1+E1*R5*R2+R5*R3*E1+R4*R3*E2+R5*R3*E2-R3*R2*R5*J)/(R2*R3*R1+R4*R2*R1+R4*R3*R2+R4*R3*R1+R5*R2*R1+R5*R3*R2+R5*R3*R1));
    I2=((E2*R3*R1+R4*E2*R1+R4*R3*E1+R4*R3*E2+R5*E2*R1+R5*R3*E1+R5*R3*E2+R5*J*R3*R1)/(R2*R3*R1+R4*R2*R1+R4*R3*R2+R4*R3*R1+R5*R2*R1+R5*R3*R2+R5*R3*R1));
    I3=((E1*R4*R2+E1*R5*R2-R4*E2*R1-R5*E2*R1+R2*R1*R5*J)/(R2*R3*R1+R4*R2*R1+R4*R3*R2+R4*R3*R1+R5*R2*R1+R5*R3*R2+R5*R3*R1));
    I4=((R3*E1*R2-E2*R3*R1-R2*R1*R5*J-R3*R2*R5*J-R5*J*R3*R1)/(R2*R3*R1+R4*R2*R1+R4*R3*R2+R4*R3*R1+R5*R2*R1+R5*R3*R2+R5*R3*R1));
    I5=((R3*E1*R2-E2*R3*R1+J*R2*R3*R1+J*R4*R2*R1+J*R4*R3*R2+J*R4*R3*R1)/(R2*R3*R1+R4*R2*R1+R4*R3*R2+R4*R3*R1+R5*R2*R1+R5*R3*R2+R5*R3*R1));
    fi1=E1-I1*R1;
    fi2=I5*R5;
  }
  if (number > 9 && number < 16)
  {
    I1=((-R5*J*R4*R2+E3*R4*R2-R3*R2*R5*J+R4*R5*E1+E1*R4*R2+R5*R3*E1+R3*E1*R2+R4*R3*E1)/(R4*R5*R2+R4*R5*R1+R4*R2*R1+R5*R3*R2+R5*R3*R1+R2*R3*R1+R4*R3*R2+R4*R3*R1));
    I2=((-R4*R5*E1-R4*R5*J*R1+R4*E3*R1-R5*R3*E1-R5*J*R3*R1-R4*R3*E1)/(R4*R5*R2+R4*R5*R1+R4*R2*R1+R5*R3*R2+R5*R3*R1+R2*R3*R1+R4*R3*R2+R4*R3*R1));
    I3=((E1*R4*R2+E3*R5*R2+E3*R1*R5+E3*R1*R2+E3*R4*R2+R4*E3*R1-R5*J*R4*R2-R4*R5*J*R1)/(R4*R5*R2+R4*R5*R1+R4*R2*R1+R5*R3*R2+R5*R3*R1+R2*R3*R1+R4*R3*R2+R4*R3*R1));
    I4=((R3*R2*R5*J-R3*E1*R2+E3*R5*R2+E3*R1*R5+E3*R1*R2+R5*J*R3*R1)/(R4*R5*R2+R4*R5*R1+R4*R2*R1+R5*R3*R2+R5*R3*R1+R2*R3*R1+R4*R3*R2+R4*R3*R1));
    I5=((E3*R4*R2+E1*R4*R2+R3*E1*R2+R4*E3*R1+J*R4*R2*R1+J*R2*R3*R1+J*R4*R3*R2+J*R4*R3*R1)/(R4*R5*R2+R4*R5*R1+R4*R2*R1+R5*R3*R2+R5*R3*R1+R2*R3*R1+R4*R3*R2+R4*R3*R1));
    fi1=-I2*R2;
    fi2=I5*R5;
  }
  if (number > 15 && number < 21)
  {
    I1=((R3*E1+R4*R3*E1+E1*R4+J*R4*R3*R2+R3*J*R2+E2*R4*R2+E1*R2+R4*R5*R2+E1*R4*R2)/(R4*R3*R1+R1*R3+R1*R4+R4*R2*R1+R1*R2+R4*R3*R2+R3*R2+R4*R2));
    I2=((R3*E1-R4*R5*R1-R4*R1*E2+R4*R3*E1+E1*R4-J*R4*R3*R1-R1*R3*J)/(R4*R3*R1+R1*R3+R1*R4+R4*R2*R1+R1*R2+R4*R3*R2+R3*R2+R4*R2));
    I3=((-J*R4*R2-J*R1*R2-J*R1*R4+E2*R4*R2+E1*R2+R4*R5*R2+R4*R5*R1+R4*R1*E2+E1*R4*R2-J*R4*R2*R1)/(R4*R3*R1+R1*R3+R1*R4+R4*R2*R1+R1*R2+R4*R3*R2+R3*R2+R4*R2));
    I4=((-R1*R3*J+R1*R3*R5+R1*R3*E2+R1*R5*R2+R1*E2*R2-R3*J*R2+R3*J*R2+R3*R5*R2+R3*E2*R2-E1*R2)/(R4*R3*R1+R1*R3+R1*R4+R4*R2*R1+R1*R2+R4*R3*R2+R3*R2+R4*R2));
    I5=((R1*R2*E2+R1*R3*R5+R3+E3+R2+R3*R5*R2+R1*E2*R2+R1*R5*R2+E2*R4*R2+R4*R5*R2+R4*R5*R1+R4*R1*E2+E1*R4*R2+J*R4*R3*R2+J*R4*R3*R1)/(R4*R3*R1+R1*R3+R1*R4+R4*R2*R1+R1*R2+R4*R3*R2+R3*R2+R4*R2));
    fi1=I2*R2;
    fi2=-R4*I4;
  }
  if (number > 20 && number < 26)
  {
    I1=((R4*R3*E1+R5*R3*E1+R5*E1*R4-R2*R5*E2+E1*R5*R2)/(R5*R2*R1+R5*R3*R1+R5*R3*R2+R4*R2*R1+R4*R3*R1+R4*R3*R2+R5*R1*R4+R5*R2*R4));
    I2=((-R4*R3*E1-R4*E1*R1-R5*R3*E1-R5*E1*R4-R5*J*R1*R4-R5*E2*R1)/(R5*R2*R1+R5*R3*R1+R5*R3*R2+R4*R2*R1+R4*R3*R1+R4*R3*R2+R5*R1*R4+R5*R2*R4));
    I3=((R4*E1*R1+R5*J*R1*R4+R5*E2*R1+R2*R5*J*R4+R2*R5*E2-E1*R5*R2)/(R5*R2*R1+R5*R3*R1+R5*R3*R2+R4*R2*R1+R4*R3*R1+R4*R3*R2+R5*R1*R4+R5*R2*R4));
    I4=((-R5*E2*R1-R2*R5*E2+E1*R5*R2+E1*R1*R2+E1*R1*R3-R3*R2*E2-R2*R1*E1+R2*R3*E1-R3*R1*E2+J*R5*R3*R1+J*R5*R3*R2)/(R5*R2*R1+R5*R3*R1+R5*R3*R2+R4*R2*R1+R4*R3*R1+R4*R3*R2+R5*R1*R4+R5*R2*R4));
    I5=((-E1*R1*R2-E1*R1*R3-R4*E1*R1+R3*R2*E2+R3*R2*J*R4+R2*R1*E2-R2*R3*E1+R2*R1*J*R4+R3*R1*J*R4+R3*R1*E2)/(R5*R2*R1+R5*R3*R1+R5*R3*R2+R4*R2*R1+R4*R3*R1+R4*R3*R2+R5*R1*R4+R5*R2*R4));
    fi1=-I2*R2;
    fi2=I5*R5;
  }
}

#endif
