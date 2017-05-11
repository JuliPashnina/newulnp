//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "database.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Oracle"
#pragma link "OracleData"
#pragma resource "*.dfm"
TDBase *DBase;
//---------------------------------------------------------------------------
__fastcall TDBase::TDBase(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDBase::DataModuleCreate(TObject *Sender)
{
  OSelena->LogonUsername="serg";
  OSelena->LogonDatabase="";
  OLelena->Execute();
  if (!OSelena->Connected)  Application->Terminate();

}
//---------------------------------------------------------------------------
int __fastcall TDBase::search(TStrings * list,AnsiString pattern)
{
  int result=-1,len=pattern.Length();
  if (len>0)
  {
    int i,count=list->Count;
    for(i=0;i<=count;i++)
    {
      if ((list->Strings[i]).SubString(1,len)==pattern)
      {
        result=i; break;
      }
    }
  }
  return result;
}
//---------------------------------------------------
void __fastcall TDBase::digitKey(char &Key,char moreKey)
{
 if (!(Key=='0' ||  Key=='1' ||  Key=='2' || Key=='3' ||
       Key=='4' ||  Key=='5' ||  Key=='6' || Key=='7' ||
       Key=='8' ||  Key=='9' ||  Key==8   || Key==13  ||
       Key==moreKey)) Key=0;
}
//---------------------------------------------------------------------------
