//---------------------------------------------------------------------------

#ifndef lab4H
#define lab4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ArrowCha.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TRab4 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TArrowSeries *Series1;
        TArrowSeries *Series2;
        TImage *zep_toka;
        TArrowSeries *Series3;
        TArrowSeries *Series4;
        TArrowSeries *Series5;
        TArrowSeries *Series6;
        TLabel *Label3;
        TLabel *Label8;
        TLabel *Label10;
        TLabel *Label12;
        TLabel *Label14;
        TLabel *Label16;
        TLabel *Label18;
        TLabel *Label20;
        TLabel *Label49;
        TCSpinEdit *numZ;
        TEdit *UZ;
        TEdit *FZ;
        TEdit *RZ;
        TEdit *CZ;
        TEdit *LZ;
        TEdit *XCZ;
        TEdit *XLZ;
        TEdit *ZZ;
        TLabel *Label21;
        TLabel *etet;
        TEdit *XABZREZ;
        TEdit *XABIMFZ;
        TLabel *Label28;
        TLabel *Label29;
        TEdit *IlZ;
        TLabel *Label26;
        TLabel *Label27;
        TEdit *UlZ;
        TLabel *Label31;
        TEdit *c0Z;
        TLabel *Label30;
        TEdit *d0Z;
        TLabel *Label32;
        TEdit *g0Z;
        TLabel *Label33;
        TEdit *h0Z;
        TLabel *Label7;
        TLabel *Label9;
        TLabel *Label11;
        TLabel *Label13;
        TEdit *IcZ;
        TLabel *Label15;
        TLabel *Label17;
        TEdit *IrZ;
        TLabel *Label23;
        TLabel *Label25;
        TEdit *FIZ;
        TLabel *Label1;
        TEdit *FIabZ;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label34;
        TLabel *Label35;
        TEdit *UabZ;
        TPanel *result;
        TPanel *save;
        TLabel *Label19;
        TLabel *Label22;
        TEdit *UCZ;
        TLabel *Label24;
        TLabel *Label36;
        TEdit *URZ;
        void __fastcall numZChange(TObject *Sender);
        void __fastcall resultMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall saveMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TRab4(TComponent* Owner);
        };
//---------------------------------------------------------------------------
extern PACKAGE TRab4 *Rab4;
//---------------------------------------------------------------------------
#endif
