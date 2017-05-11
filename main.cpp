//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include "main.h"
#include "database.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFnewulnp *Fnewulnp;
//---------------------------------------------------------------------------
__fastcall TFnewulnp::TFnewulnp(TComponent* Owner)
        : TForm(Owner)
{
  //имя скрипта: год/месяц/день/алиаc.sql - перезаписывается только если тот же день для одной и той же базы
  AnsiString fileName=Date().DateString().SubString(7,4)+Date().DateString().SubString(4,2)+Date().DateString().SubString(1,2)+DBase->OSelena->LogonDatabase+".sql";
  fileout=fopen(fileName.c_str(),"w");
  if (fileout==NULL)
  {
    ShowMessage("Невозможно создать файл.");
    Application->Terminate();
  }
  //имя скрипта CC&B: день/месяц/час/минуты/секунды/ccb.sql - чтобы не перезаписывался вообще
  fileName=Date().DateString().SubString(1,2)+Date().DateString().SubString(4,2)+Time().TimeString().SubString(1,2)+Time().TimeString().SubString(4,2)+Time().TimeString().SubString(7,2)+"ccb.sql";
  fileccb=fopen(fileName.c_str(),"w");
  if (fileccb==NULL)
  {
    ShowMessage("Невозможно создать файл для СС&B.");
    Application->Terminate();
  }
  DBase->ODSnaspunkt->Open();
  DBase->ODSulitsa->Open();

 // формируем список населённый пунктов
 SLulitsa=new TStringList();
 SLnaspunkt=new TStringList();
 TOracleDataSet * nasp=DBase->ODSnaspunkt;
 TField * id_n=nasp->FieldByName("NNASPUNKT");
 TField * name_n=nasp->FieldByName("CTEXT");
 nasp->First();
 while (!nasp->Eof)
 {
   SLnaspunkt->Add(id_n->AsString);
   CBnaspunkt->Items->Add(name_n->AsString);
   nasp->Next();
 }
 CBsocrnp->ItemIndex=0;
 CBsocrul->ItemIndex=0;
 cntul=0;

 TOracleDataSet * ul=DBase->ODSulitsa;
 ul->SQL->Strings[1]="--";
 ul->Refresh();
 SLulitsa->Clear();
 CBulitsa->Clear();
 TField * id=ul->FieldByName("NULITSAID");
 TField * name=ul->FieldByName("CTEXT");
 ul->First();
 while (!ul->Eof)
 {
    SLulitsa->Add(id->AsString);
    CBulitsa->Items->Add(name->AsString);
    ul->Next();
 }

}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::ChBnewnpClick(TObject *Sender)
{
   if (ChBnewnp->Checked)
   {
      Enaspunkt->Enabled=true;
      CBsocrnp->Enabled=true;
      Epost->Enabled=true;
      Eindex->Enabled=true;
      Eres->Enabled=true;
      Eter->Enabled=true;
      Eokato->Enabled=true;

      ChBupdnp->Checked=false;
      Enewnazvnp->Enabled=false;
      CBnewsocrnp->Enabled=false;
   }
   else
   {
      Enaspunkt->Enabled=false;
      CBsocrnp->Enabled=false;
      Epost->Enabled=false;
      Eindex->Enabled=false;
      Eres->Enabled=false;
      Eter->Enabled=false;
      Eokato->Enabled=false;
   }
        
}
//---------------------------------------------------------------------------
void __fastcall TFnewulnp::BBexitClick(TObject *Sender)
{
  fclose(fileout);
  fclose(fileccb);
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TFnewulnp::Epattern1Change(TObject *Sender)
{
  AnsiString pat;
  DBase->ODSnaspunkt->Locate("NAIM",Epattern1->Text,TLocateOptions()<< loPartialKey);
  if (DBase->ODSnaspunkt->FieldByName("NAIM")->AsString.AnsiPos(Epattern1->Text)!=0)
  {
    pat=DBase->ODSnaspunkt->FieldByName("SOCR")->AsString.Trim()+" "+Epattern1->Text;
  }
  CBnaspunkt->ItemIndex=DBase->search(CBnaspunkt->Items,pat);
       TOracleDataSet * ul=DBase->ODSulitsa;
       ul->SQL->Strings[1]="where nnaspunkt="+SLnaspunkt->Strings[CBnaspunkt->ItemIndex];
       ul->Refresh();
       SLulitsa->Clear();
       CBulitsa->Clear();
       TField * id=ul->FieldByName("NULITSAID");
       TField * name=ul->FieldByName("CTEXT");
       ul->First();
       while (!ul->Eof)
       {
          SLulitsa->Add(id->AsString);
          CBulitsa->Items->Add(name->AsString);
          ul->Next();
       }
       CBulitsa->ItemIndex= -1;
}
//---------------------------------------------------------------------------
void __fastcall TFnewulnp::EnnaspunktKeyPress(TObject *Sender, char &Key)
{
  DBase->digitKey(Key,0);

}
//---------------------------------------------------------------------------
void __fastcall TFnewulnp::BBfindnpClick(TObject *Sender)
{
    if (!Ennaspunkt->Text.IsEmpty())
    {
        AnsiString pat;
        DBase->ODSnaspunkt->Locate("NNASPUNKT",Ennaspunkt->Text.Trim(),TLocateOptions()<< loPartialKey);
        if (DBase->ODSnaspunkt->FieldByName("NNASPUNKT")->AsInteger==StrToInt(Ennaspunkt->Text))
        {
           pat=DBase->ODSnaspunkt->FieldByName("SOCR")->AsString.Trim()+" "+DBase->ODSnaspunkt->FieldByName("NAIM")->AsString;
        }
        CBnaspunkt->ItemIndex=DBase->search(CBnaspunkt->Items,pat);
        if (CBnaspunkt->ItemIndex>=0)
        {
          TOracleDataSet * ul=DBase->ODSulitsa;
          ul->SQL->Strings[1]="where nnaspunkt="+SLnaspunkt->Strings[CBnaspunkt->ItemIndex];
          ul->Refresh();
          SLulitsa->Clear();
          CBulitsa->Clear();
          TField * id=ul->FieldByName("NULITSAID");
          TField * name=ul->FieldByName("CTEXT");
          ul->First();
          while (!ul->Eof)
          {
             SLulitsa->Add(id->AsString);
             CBulitsa->Items->Add(name->AsString);
             ul->Next();
          }
          CBulitsa->ItemIndex= -1;
        }
    }
    else ShowMessage("Заполните поле Код!");

}
//---------------------------------------------------------------------------
void __fastcall TFnewulnp::BBaddClick(TObject *Sender)
{
  AnsiString line;
  bool isccb=false;
  if (MessageDlg("Составить скрипт для CC&B?", mtConfirmation,TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) isccb=true;

  if (ChBnewnp->Checked)
  {
    if (Enaspunkt->Text.Trim().IsEmpty())
    {
      ShowMessage("Нет названия нового населенного пункта.");
    }
    else if (Eres->Text.Trim().IsEmpty())
    {
      ShowMessage("Нет номера РЭС нового населенного пункта.");
    }
    else if (CBsocrnp->Text.Trim().IsEmpty())
    {
      ShowMessage("Нет сокращения нового населенного пункта.");
    }
    else if (Eindex->Text.Trim().IsEmpty())
    {
      ShowMessage("Нет индекса нового населенного пункта.");
    }
    else if (Epost->Text.Trim().IsEmpty())
    {
      ShowMessage("Нет почтового названия нового населенного пункта.");
    }
    else if (Eter->Text.Trim().IsEmpty())
    {
      ShowMessage("Нет кода территории нового населенного пункта.");
    }
    else if (Eokato->Text.Trim().IsEmpty())
    {
      ShowMessage("Нет кода ОКАТО нового населенного пункта.");
    }
    else
    {
     DBase->OQnewnpid->Execute();
     npid=DBase->OQnewnpid->FieldAsString(0);
     line="insert into naspunkt (NNASPUNKT,CTEXT,NRES,SOCR,CINDEX,CTEXTP,NTERR,OKATO) values ("+npid+",'"+Enaspunkt->Text.Trim()+"',"+Eres->Text.Trim()+",'"+CBsocrnp->Text.Trim()+"','"+Eindex->Text.Trim()+"','"+Epost->Text.Trim()+"',"+Eter->Text.Trim()+","+Eokato->Text.Trim()+");";
     fprintf(fileout,"%s\n",line.c_str());
     if (isccb)
     {
        line="insert into cm_naspunkt (CM_OKATO,STATE,CM_CTEXT,CM_SOCR,CM_NTERR) values ("+Eokato->Text.Trim()+",'74','"+Enaspunkt->Text.Trim()+"','"+CBsocrnp->Text.Trim()+"',"+Eter->Text.Trim()+");";
        fprintf(fileccb,"%s\n",line.c_str());
     }
     if (RBnewul->Checked)
     {
        AnsiString ctext=Eulitsa->Text;
        if (Eulitsa->Text.IsEmpty()) ctext=" ";
        //if (Eulitsa->Text.Trim().IsEmpty()) ShowMessage("Не указано название улицы!");
        //else
        if (CBsocrul->Text.Trim().IsEmpty()) ShowMessage("Не указано сокращение для улицы!");
        else if (lastul==ctext+CBsocrul->Text.Trim()) ShowMessage("Для данной улицы уже создан скрипт.");  //    Eulitsa->Text.Trim()
        else
        {
           cntul++;
           AnsiString ulid=IntToStr(cntul);
           while (ulid.Length()<6) ulid="0"+ulid;
           line="insert into ulitsa (nulitsaid,ctext,nnaspunkt,socr) values ("+npid+ulid+",'"+ctext+"',"+npid+",'"+CBsocrul->Text.Trim()+"');";// Eulitsa->Text.Trim()
           fprintf(fileout,"%s\n",line.c_str());
           if (isccb)
           {
              ulid=npid+ulid;
              while (ulid.Length()<12) ulid="0"+ulid;
              int cm_pos=0;
              if (!Epos->Text.Trim().IsEmpty()) cm_pos=StrToInt(Epos->Text.Trim());
              line="insert into cm_ulitsa (CM_OKATO,CM_NPOSELOK,CM_CTEXT,CM_SOCR,CM_NULITSAID) values ("+Eokato->Text.Trim()+","+IntToStr(cm_pos)+",'"+ctext+"','"+CBsocrul->Text.Trim()+"','"+ulid+"');"; //     Eulitsa->Text.Trim()
              fprintf(fileccb,"%s\n",line.c_str());
           }
           lastul=ctext+CBsocrul->Text.Trim();    //  Eulitsa->Text.Trim()
        }
     }
    }
  }
  else
  {
    if (ChBupdnp->Checked)
    {
         if (CBnaspunkt->ItemIndex>=0)
         {
           if (Enewnazvnp->Text.Trim().IsEmpty() && CBnewsocrnp->Text.Trim().IsEmpty())
           {
             ShowMessage("Не указано ни новое название, ни новое сокращение для населенного пункта!");
           }
           else if (CBnewsocrnp->Text.Trim().IsEmpty())
           {
             line="update naspunkt set ctext='"+Enewnazvnp->Text.Trim()+"' where nnaspunkt="+SLnaspunkt->Strings[CBnaspunkt->ItemIndex]+";";
             fprintf(fileout,"%s\n",line.c_str());
             if (isccb)
             {
                DBase->OQokato->SetVariable("npid",SLnaspunkt->Strings[CBnaspunkt->ItemIndex]);
                DBase->OQokato->Execute();
                line="update cm_naspunkt set CM_CTEXT='"+Enewnazvnp->Text.Trim()+"' where CM_OKATO="+DBase->OQokato->FieldAsString(0).Trim()+";";
                fprintf(fileccb,"%s\n",line.c_str());
             }
           }
           else
           {
             line="update naspunkt set ctext='"+Enewnazvnp->Text.Trim()+"',socr='"+CBnewsocrnp->Text.Trim()+"' where nnaspunkt="+SLnaspunkt->Strings[CBnaspunkt->ItemIndex]+";";
             fprintf(fileout,"%s\n",line.c_str());
             if (isccb)
             {
                DBase->OQokato->SetVariable("npid",SLnaspunkt->Strings[CBnaspunkt->ItemIndex]);
                DBase->OQokato->Execute();
                line="update cm_naspunkt set CM_CTEXT='"+Enewnazvnp->Text.Trim()+"',CM_SOCR='"+CBnewsocrnp->Text.Trim()+"' where CM_OKATO="+DBase->OQokato->FieldAsString(0).Trim()+";";
                fprintf(fileccb,"%s\n",line.c_str());
             }
           }
         }
         else ShowMessage("Не выбран населенный пункт для обновления!");
    }
    else
    {
       AnsiString ctext=Eulitsa->Text;
       if (Eulitsa->Text.IsEmpty()) ctext=" ";
       if (RBnewul->Checked)
       {
         //if (Eulitsa->Text.Trim().IsEmpty()) ShowMessage("Не указано название улицы!");
         //else
         if (CBsocrul->Text.Trim().IsEmpty()) ShowMessage("Не указано сокращение для улицы!");
         else
         {
           AnsiString ulid;
           if (npid!=SLnaspunkt->Strings[CBnaspunkt->ItemIndex])
           {
              npid=SLnaspunkt->Strings[CBnaspunkt->ItemIndex];
              DBase->OQcomplex->Execute();
              DBase->OQgetulid->SetVariable("npid",SLnaspunkt->Strings[CBnaspunkt->ItemIndex]);
              if (DBase->OQcomplex->FieldAsInteger(0)==2) DBase->OQgetulid->SQL->Strings[1]="or 1=1";
              DBase->OQgetulid->Execute();
              ulid=DBase->OQgetulid->FieldAsString(0);
              cntul=0;
           }
           else
           {
              cntul++;
              ulid=IntToStr(cntul);
              while (ulid.Length()<6) ulid="0"+ulid;
              ulid=npid+ulid;
           }
           /*if (ulid.Length()<12) ulid="0"+ulid;
           ulid=IntToStr(StrToInt(ulid.SubString(7,6))+1);
           while (ulid.Length()<6) ulid="0"+ulid;  */
           line="insert into ulitsa (nulitsaid,ctext,nnaspunkt,socr) values ("+ulid+",'"+ctext+"',"+SLnaspunkt->Strings[CBnaspunkt->ItemIndex]+",'"+CBsocrul->Text+"');";  //  Eulitsa->Text
           fprintf(fileout,"%s\n",line.c_str());
           while (ulid.Length()<12) ulid="0"+ulid;
           if (isccb)
           {
              DBase->OQokato->SetVariable("npid",SLnaspunkt->Strings[CBnaspunkt->ItemIndex]);
              DBase->OQokato->Execute();
              int cm_pos=0;
              if (!Epos->Text.Trim().IsEmpty()) cm_pos=StrToInt(Epos->Text.Trim());
              line="insert into cm_ulitsa (CM_OKATO,CM_NPOSELOK,CM_CTEXT,CM_SOCR,CM_NULITSAID) values ("+DBase->OQokato->FieldAsString(0).Trim()+","+IntToStr(cm_pos)+",'"+ctext+"','"+CBsocrul->Text.Trim()+"','"+ulid+"');";  // Eulitsa->Text
              fprintf(fileccb,"%s\n",line.c_str());
           }
           cntul=StrToInt(ulid.SubString(7,6));

         }
       }
       if (RBupdul->Checked)
       {
         if (CBulitsa->ItemIndex>=0)
         {
           if (CBsocrul->Text.Trim().IsEmpty())   // Eulitsa->Text.Trim().IsEmpty() &&
           {
             ShowMessage("Не указано сокращение для улицы!");          //    ни новое название, ни новое
           }
           else if (CBsocrul->Text.Trim().IsEmpty())
           {
             line="update ulitsa set ctext='"+ctext+"' where nulitsaid="+SLulitsa->Strings[CBulitsa->ItemIndex]+";";   //  Eulitsa->Text.Trim()
             fprintf(fileout,"%s\n",line.c_str());
             if (isccb)
             {
                AnsiString ulid=SLulitsa->Strings[CBulitsa->ItemIndex];
                while (ulid.Length()<12) ulid="0"+ulid;
                line="update cm_ulitsa set CM_CTEXT='"+ctext+"' where CM_NULITSAID='"+ulid+"';";  //   Eulitsa->Text.Trim()
                fprintf(fileccb,"%s\n",line.c_str());
             }
           }
           else
           {
             line="update ulitsa set ctext='"+ctext+"',socr='"+CBsocrul->Text.Trim()+"' where nulitsaid="+SLulitsa->Strings[CBulitsa->ItemIndex]+";";   // Eulitsa->Text.Trim()
             fprintf(fileout,"%s\n",line.c_str());
             if (isccb)
             {
                AnsiString ulid=SLulitsa->Strings[CBulitsa->ItemIndex];
                while (ulid.Length()<12) ulid="0"+ulid;
                line="update cm_ulitsa set CM_CTEXT='"+ctext+"',CM_SOCR='"+CBsocrul->Text.Trim()+"' where CM_NULITSAID='"+ulid+"';";   // Eulitsa->Text.Trim()
                fprintf(fileccb,"%s\n",line.c_str());
             }
           }
         }
         else ShowMessage("Не выбрана улица для обновления!");
       }
    }
  }
  Ennaspunkt->Text="";
  Enulitsaid->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFnewulnp::ChBupdnpClick(TObject *Sender)
{
   if (ChBupdnp->Checked)
   {
      Enewnazvnp->Enabled=true;
      CBnewsocrnp->Enabled=true;

      ChBnewnp->Checked=false;
      Enaspunkt->Enabled=false;
      CBsocrnp->Enabled=false;
      Epost->Enabled=false;
      Eindex->Enabled=false;
      Eres->Enabled=false;
      Eter->Enabled=false;
      Eokato->Enabled=false;
   }
   else
   {
      Enewnazvnp->Enabled=false;
      CBnewsocrnp->Enabled=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::BBdelchClick(TObject *Sender)
{
  RBupdul->Checked=false;
  RBnewul->Checked=false;
  Eulitsa->Enabled=false;
  CBsocrul->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::RBnewulClick(TObject *Sender)
{
  if (RBnewul->Checked)
  {
     Eulitsa->Enabled=true;
     CBsocrul->Enabled=true;
     CBsocrul->ItemIndex=0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::RBupdulClick(TObject *Sender)
{
  if (RBupdul->Checked)
  {
     Eulitsa->Enabled=true;
     CBsocrul->Enabled=true;
     CBsocrul->ItemIndex=-1;
  }

}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::EpatternChange(TObject *Sender)
{
  AnsiString pat;
  DBase->ODSulitsa->Locate("CTEXT",Epattern->Text,TLocateOptions()<< loPartialKey);
  if (DBase->ODSulitsa->FieldByName("CTEXT")->AsString.AnsiPos(Epattern->Text)!=0)
  {
    pat=DBase->ODSulitsa->FieldByName("SOCR")->AsString.Trim()+" "+Epattern->Text;
  }
  CBulitsa->ItemIndex=DBase->search(CBulitsa->Items,pat);

}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::BBfindulClick(TObject *Sender)
{
    if (!Enulitsaid->Text.Trim().IsEmpty())
    {
        DBase->ODSulitsa->Locate("NULITSAID",Enulitsaid->Text.Trim(),TLocateOptions()<< loPartialKey);
        if (DBase->ODSulitsa->FieldByName("NULITSAID")->AsString==Enulitsaid->Text.Trim())
        {
           TOracleDataSet * ul=DBase->ODSulitsa;
           ul->SQL->Strings[1]="where NULITSAID="+Enulitsaid->Text.Trim();
           ul->Refresh();
           SLulitsa->Clear();
           CBulitsa->Clear();
           TField * id=ul->FieldByName("NULITSAID");
           TField * name=ul->FieldByName("CTEXT");
           ul->First();
           while (!ul->Eof)
           {
             SLulitsa->Add(id->AsString);
             CBulitsa->Items->Add(name->AsString);
             ul->Next();
           }
        }
        CBulitsa->ItemIndex=0;

    }
    else ShowMessage("Заполните поле Код!");
        
}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::ChBulitsaClick(TObject *Sender)
{
  if (ChBulitsa->Checked)
  {
   if (CBnaspunkt->ItemIndex>=0)
   {
       Epattern->Enabled=true;
       Enulitsaid->Enabled=true;
       CBulitsa->Enabled=true;
       BBfindul->Enabled=true;
       BBdelch->Enabled=true;
       RBnewul->Enabled=true;
       RBupdul->Enabled=true;
   }
   else if (ChBnewnp->Checked && !Enaspunkt->Text.Trim().IsEmpty())
   {
       Epattern->Enabled=false;
       Enulitsaid->Enabled=false;
       CBulitsa->Enabled=false;
       BBfindul->Enabled=false;
       BBdelch->Enabled=false;
       RBnewul->Enabled=false;
       RBupdul->Enabled=false;

       RBnewul->Checked=true;
       Eulitsa->Enabled=true;
       CBsocrul->Enabled=true;
       CBsocrul->ItemIndex=0;
   }
   else
   {
       Epattern->Enabled=true;
       Enulitsaid->Enabled=true;
       CBulitsa->Enabled=true;
       BBfindul->Enabled=true;

       BBdelch->Enabled=false;
       RBnewul->Enabled=false;
       RBupdul->Enabled=false;

       RBupdul->Checked=true;
       Eulitsa->Enabled=true;
       CBsocrul->Enabled=true;
       CBsocrul->ItemIndex=-1;
   }
  }
}
//---------------------------------------------------------------------------

void __fastcall TFnewulnp::EnaspunktExit(TObject *Sender)
{
    if (!Enaspunkt->Text.Trim().IsEmpty()) Epost->Text=Enaspunkt->Text;
}
//---------------------------------------------------------------------------

