//---------------------------------------------------------------------------

#ifndef lab1H
#define lab1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "CSPIN.h"
#include "PERFGRAP.h"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TRab1 : public TForm
{
__published:	// IDE-managed Components
        TImage *image_sh;
        TCSpinEdit *numZ;
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
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label49;
        TLabel *Label33;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label39;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *Label43;
        TLabel *Label45;
        TLabel *Label47;
        TLabel *Label34;
        TLabel *Label38;
        TLabel *Label40;
        TLabel *Label44;
        TLabel *Label46;
        TEdit *IZ1;
        TEdit *IZ2;
        TEdit *IZ3;
        TEdit *IZ4;
        TEdit *IZ5;
        TEdit *IZ6;
        TEdit *IW1;
        TEdit *IW2;
        TEdit *IW3;
        TEdit *nuZ;
        TEdit *lZ;
        TEdit *SZ;
        TEdit *dZ;
        TEdit *HcZ;
        TEdit *HdZ;
        TEdit *UcZ;
        TEdit *UdZ;
        TEdit *FZ;
        TEdit *BZ;
        TEdit *vector;
        TLabel *Label48;
        TPanel *result;
        TPanel *save;
        void __fastcall numZChange(TObject *Sender);
        void __fastcall Button1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall resultMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall saveMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TRab1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRab1 *Rab1;
//---------------------------------------------------------------------------
#endif
