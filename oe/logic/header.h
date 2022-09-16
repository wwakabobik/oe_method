/*        File header.h
  classes TLab1, TLab2, TLab3, TLab4
  Classes for automation of checking student's homework
  in MIREA (http://www.mirea.ru), chair of TISSU,
  special for Zypkin V. N. from IP-4-03
  Vereshchagin I.G. 2005 (C) all rights reserved
  GPL license (http://www.fsf.org/licensing/licenses/gpl.html),
  OSI licence (http://www.opensource.org/)  */

#ifndef __HEADER_H
#define __HEADER_H 1

char tempname[] = "swap.tmp";

class TLab1 {
 // private block
 private:
  // variable number
  int number;
  // current block
  float I1;
  float I2;
  float I3;
  float I4;
  float I5;
  float I6;
  float I7; // reserved
  float I8; // reserved
  // number of coil
  int W1;
  int W2;
  int W3;
  int W4; // reserved
  int W5; // reserved
  int W6; // reserved
  int W7; // reserved
  int W8; // reserved
  // bool block, to modify a vector of current
  bool IV1;
  bool IV2;
  bool IV3;
  bool IV4;
  bool IV5;
  bool IV6;
  bool IV7; // reserved
  bool IV8; // reserved
  // other data
  long double nu;
  long double l;
  long double S;
  long double delta;
  // results
  long double Hs;
  long double Hd;
  long double Us;
  long double Ud;
  long double Bs;
  long double Bd;
  long double Fs;
  long double Fd;
  bool FVs;
  bool FVd;
  // public block
  public:
  TLab1();    // constructor;
  ~TLab1();   // destructor;
  // calculating of result
  void TLab1::CalcNum(int num0);
  // creation block
  bool TLab1::Change(int num0);
  long double TLab1::GetData(int stat);
  void TLab1::save(void);
  void TLab1::NewNum(int num0);
  void TLab1::NewCurrent(float I01, float I02, float I03, float I04, float I05, float I06, float I07, float I08);
  void TLab1::NewCoil(int W01, int W02, int W03, int W04, int W05, int W06, int W07, int W08);
  void TLab1::NewVector(bool IV01, bool IV02, bool IV03, bool IV04, bool IV05, bool IV06, bool IV07, bool IV08);
  void TLab1::NewOther(long double nu00, long double l0, long double S0, long double delta0);
  // destruction
  void TLab1::DelNum(int num0);
};

class TLab2 {
  // private block
  private:
  int number;
  long double w;
  long double s;
  long double T;
  long double F;
  long double Bm;
  long double B0;
  long double Em;
  long double Fm;
  bool EV;
  bool FV;
  // int t=0; time
  // public block
  public:
  TLab2();  // constructor
  ~TLab2(); // destructor
  // calculate
  bool TLab2::Change(int num0);
  long double TLab2::GetData(int num0);
  void TLab2::Lab2Calc();
  // creation
  void TLab2::save(void);
  void TLab2::NewLab2(long double num0, long double par1, long double par2, long double par3, long double par4, long double par5);
  // destruction
  void TLab2::DelLab2(int num0);
 };

class TLab3 {
  // private block
  private:
  // data block
  int number;
  long double R1;
  long double R2;
  long double R3;
  long double R4;
  long double R5;
  long double R6; // reserved
  long double E1;
  long double E2;
  long double E3; // reserved
  long double J;
  // result block
  long double I1;
  long double I2;
  long double I3;
  long double I4;
  long double I5;
  long double I6; // reserved
  long double fi1;
  long double fi2;
  // public block
  public:
  TLab3();
  ~TLab3();
  // creation block
  bool TLab3::Change(int num0);
  long double TLab3::GetData(int num0);
  void TLab3::save(void);
  void TLab3::NewLab3(int num0);
  void TLab3::NewResist(long double R01, long double R02, long double R03, long double R04, long double R05, long double R06);
  void TLab3::NewEDS(long double E01, long double E02, long double E03, long double J0);
  // delete block
  void TLab3::DelLab3(int num0);
  // calculate
  void TLab3::Lab3Calc(int num0);
};

class TLab4 {
  //private block
  private:
  // data
  int number;
  long double U;
  long double F;
  long double R;
  long double C;
  long double l;
  long double xc;
  long double xl;
  long double z;
  long double xab1;
  long double xab2;
  long double fi;
  long double ut;
  long double il;
  long double ul;
  long double uab;
  long double c;
  long double d;
  long double g;
  long double h;
  long double fiab;
  long double ic;
  long double ir;
  long double uc;
  long double ur;
  // result
  // public block
  public:
  TLab4();
  ~TLab4();
  // calculate
  bool TLab4::Change(int num0);
  void TLab4::Lab4Calc(int num0);
  // create
  long double TLab4::GetData(int num0);
  void TLab4::save(void);
  void TLab4::NewLab4(int num0, long double U0, long double F0, long double R0, long double C0, long double l0);
  void TLab4::NewData4(long double xl0, long double xc0, long double xab10, long double xab20, long double z0, long double fi0, long double ut0, long double il0, long double  ul0, long double  c0, long double  d0, long double  g0, long double  h0, long double  uab0, long double  fiab0, long double  ic0, long double  ir0);
  // delete
  void TLab4::DelLab4(int num0);
};

class TLab5 {
  //private block
  private:
  // data
  int number;
  long double I;
  long double w;
  long double delta;
  long double a;
  long double c;
  long double e;
  long double D;
  long double d;
  long double h;
  long double bk;
  long double hk;
  long double B;
  long double hc;
  long double hd;
  long double umc;
  long double umd;
  long double F;
  long double L;
  public:
  TLab5();
  ~TLab5();
  bool TLab5::Change(int num0);
  void TLab5::Lab5Calc(int num0);
  long double TLab5::GetData(int num0);
  void TLab5::save(void);
  void TLab5::NewLab5(int num0, long double I0, long double w0, long double delta0,   long double a0, long double c0, long double e0, long double D0, long double d0, long double h0);
  void TLab5::DelLab5(int num0);
  };


#endif // _HEADER.H
