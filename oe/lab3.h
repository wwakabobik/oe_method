//---------------------------------------------------------------------------

#ifndef lab3H
#define lab3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TRab3 : public TForm
{
__published:	// IDE-managed Components
        TImage *scheme;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label49;
        TCSpinEdit *numZ;
        TEdit *IZ1;
        TEdit *IZ2;
        TEdit *IZ3;
        TEdit *IZ4;
        TEdit *IZ5;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TEdit *RZ1;
        TEdit *RZ2;
        TEdit *RZ3;
        TEdit *RZ4;
        TEdit *RZ5;
        TLabel *label0001;
        TLabel *Label26;
        TEdit *EZ1;
        TLabel *Label27;
        TLabel *Label28;
        TEdit *EZ2;
        TLabel *Label29;
        TLabel *Label30;
        TEdit *EZ3;
        TLabel *Label31;
        TEdit *JZ;
        TLabel *Label33;
        TLabel *Label34;
        TEdit *fiZ1;
        TLabel *Label35;
        TLabel *Label36;
        TEdit *fiZ2;
        TPanel *result;
        TPanel *save;
        void __fastcall numZChange(TObject *Sender);
        void __fastcall resultMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall saveMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TRab3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRab3 *Rab3;
//---------------------------------------------------------------------------
#endif
