//---------------------------------------------------------------------------

#ifndef lab2H
#define lab2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class TRab2 : public TForm
{
__published:	// IDE-managed Components
        TImage *image_m;
        TLabel *Label49;
        TCSpinEdit *numZ;
        TLabel *Label13;
        TLabel *Label15;
        TLabel *Label17;
        TEdit *wZ;
        TEdit *SZ;
        TEdit *TZ;
        TEdit *FZ;
        TChart *Chart1;
        TLabel *Label1;
        TEdit *B0Z;
        TLabel *Label2;
        TLabel *Label14;
        TEdit *BmZ;
        TLabel *Label3;
        TLabel *m;
        TEdit *EmZ;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *FmZ;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *EVZ;
        TLabel *Label9;
        TLabel *Label10;
        TEdit *FVZ;
        TLabel *fmmz;
        TLabel *Label11;
        TImage *graph;
        TLineSeries *Series1;
        TPanel *result;
        TPanel *save;
        void __fastcall numZChange(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall resultMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall saveMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TRab2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRab2 *Rab2;
//---------------------------------------------------------------------------
#endif
