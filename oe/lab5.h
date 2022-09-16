//---------------------------------------------------------------------------

#ifndef lab5H
#define lab5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TRab5 : public TForm
{
__published:	// IDE-managed Components
        TImage *big_pic;
        TImage *small_pic;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label9;
        TLabel *Label11;
        TLabel *Label13;
        TLabel *Label15;
        TLabel *Label49;
        TCSpinEdit *numZ;
        TEdit *IZ;
        TEdit *wZ;
        TEdit *deltaZ;
        TEdit *cZ;
        TEdit *eZ;
        TEdit *DZ;
        TEdit *dZZ;
        TLabel *Label2;
        TLabel *Label4;
        TEdit *hZ;
        TEdit *BkZ;
        TLabel *Label6;
        TEdit *aZ;
        TPanel *rastch0;
        TPanel *Panel1;
        TLabel *Label8;
        TLabel *Label10;
        TEdit *HkZ;
        TLabel *Label12;
        TLabel *Label14;
        TEdit *BZ;
        TLabel *Label17;
        TEdit *HcZ;
        TLabel *Label18;
        TLabel *Label19;
        TEdit *HdZ;
        TLabel *Label20;
        TLabel *Label16;
        TEdit *UmcZ;
        TLabel *Label21;
        TLabel *Label22;
        TEdit *UmdZ;
        TLabel *Label23;
        TLabel *Label24;
        TEdit *FZ;
        TLabel *Label26;
        TEdit *LZ;
        TLabel *Label28;
        void __fastcall rastch0MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall numZChange(TObject *Sender);
        void __fastcall Panel1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TRab5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRab5 *Rab5;
//---------------------------------------------------------------------------
#endif
