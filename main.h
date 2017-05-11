//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFnewulnp : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel1;
        TBevel *Bevel2;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Enaspunkt;
        TCheckBox *ChBnewnp;
        TEdit *Eulitsa;
        TComboBox *CBsocrul;
        TBitBtn *BBadd;
        TBitBtn *BBexit;
        TComboBox *CBsocrnp;
        TBitBtn *BBfindnp;
        TComboBox *CBnaspunkt;
        TEdit *Epattern1;
        TEdit *Ennaspunkt;
        TEdit *Epost;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *Eindex;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TEdit *Eres;
        TEdit *Eter;
        TEdit *Eokato;
        TCheckBox *ChBupdnp;
        TEdit *Enewnazvnp;
        TComboBox *CBnewsocrnp;
        TEdit *Epattern;
        TComboBox *CBulitsa;
        TEdit *Enulitsaid;
        TLabel *Label11;
        TBitBtn *BBfindul;
        TRadioGroup *RGactionul;
        TRadioButton *RBnewul;
        TRadioButton *RBupdul;
        TBitBtn *BBdelch;
        TCheckBox *ChBulitsa;
        TLabel *Label2;
        TEdit *Epos;
        void __fastcall ChBnewnpClick(TObject *Sender);
        void __fastcall BBexitClick(TObject *Sender);
        void __fastcall Epattern1Change(TObject *Sender);
        void __fastcall EnnaspunktKeyPress(TObject *Sender, char &Key);
        void __fastcall BBfindnpClick(TObject *Sender);
        void __fastcall BBaddClick(TObject *Sender);
        void __fastcall ChBupdnpClick(TObject *Sender);
        void __fastcall BBdelchClick(TObject *Sender);
        void __fastcall RBnewulClick(TObject *Sender);
        void __fastcall RBupdulClick(TObject *Sender);
        void __fastcall EpatternChange(TObject *Sender);
        void __fastcall BBfindulClick(TObject *Sender);
        void __fastcall ChBulitsaClick(TObject *Sender);
        void __fastcall EnaspunktExit(TObject *Sender);
private:	// User declarations
 TStringList * SLnaspunkt;
 TStringList * SLulitsa;
 AnsiString npid;
 AnsiString lastul;
 int cntul;
 FILE * fileout;
 FILE * fileccb;
public:		// User declarations
        __fastcall TFnewulnp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFnewulnp *Fnewulnp;
//---------------------------------------------------------------------------
#endif
