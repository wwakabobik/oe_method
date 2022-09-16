//---------------------------------------------------------------------------

#include <vcl.h>
#include "ShellAPI.h"
//#include "mmsystem.h"
//#include "winuser.h"
#pragma hdrstop

#include "author.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tauthors *authors;
//---------------------------------------------------------------------------
__fastcall Tauthors::Tauthors(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tauthors::Panel1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall Tauthors::FormClose(TObject *Sender, TCloseAction &Action)
{
MediaPlayer1->Pause();
}
//---------------------------------------------------------------------------


void __fastcall Tauthors::FormShow(TObject *Sender)
{
MediaPlayer1->Play();        
}
//---------------------------------------------------------------------------

