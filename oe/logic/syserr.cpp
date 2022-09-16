#ifndef __SYSERR_CPP
#define __SYSERR_CPP 1

#include <vcl.h>
#include <StdCtrls.hpp>
#include <string.h>

inline AnsiString StrCheck(AnsiString t)
{
bool only_one = false;
int j=0,i=0;
j=t.Length();
for(i=1;i<j;i++)
{
if (t[i]=='.')
 {
 if (!only_one)
 { t[i]=','; only_one=true;}
 else
 { t="000,000"; ShowMessage("Вы ввели некорректную информацию,\nпопробуйте еще раз!\nИспользуйте цифры и знаки \",\" и \".\""); break; }
 }
else if (t[i]==',')
 {
 if  (only_one)
 { t="000,000"; ShowMessage("Вы ввели некорректную информацию,\nпопробуйте еще раз!\nИспользуйте цифры и знаки \",\" и \".\""); break; }
 else only_one=true;
 }
else if (t[i]!='0' && t[i]!='1' && t[i]!='2' && t[i]!='3' && t[i]!='4' && t[i]!='5' && t[i]!='6' && t[i]!='7' && t[i]!='8' && t[i]!='9' && t[i]!=',')
 if (i==1 && t[i]=='-')
 { t=t; }
 else
 { t="000,000"; ShowMessage("Вы ввели некорректную информацию,\nпопробуйте еще раз!\nИспользуйте цифры и знаки \",\" и \".\""); break; }
}
return t;
}

#endif
