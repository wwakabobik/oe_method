//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include "lab4.h";
#include "header.h";

#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("lab1.cpp", Rab1);
USEFORM("lab4.cpp", Rab4);
USEFORM("lab3.cpp", Rab3);
USEFORM("main.cpp", Form1);
USEFORM("lab2.cpp", Rab2);
USEFORM("author.cpp", authors);
USEFORM("lab5.cpp", Rab5);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "TDSV ОЭ Контрольные Работы - МИРЭА";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TRab1), &Rab1);
                 Application->CreateForm(__classid(TRab4), &Rab4);
                 Application->CreateForm(__classid(TRab3), &Rab3);
                 Application->CreateForm(__classid(TRab2), &Rab2);
                 Application->CreateForm(__classid(Tauthors), &authors);
                 Application->CreateForm(__classid(TRab5), &Rab5);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
