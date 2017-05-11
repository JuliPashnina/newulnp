//---------------------------------------------------------------------------

#ifndef databaseH
#define databaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Oracle.hpp"
#include "OracleData.hpp"
#include <Db.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TDBase : public TDataModule
{
__published:	// IDE-managed Components
        TOracleLogon *OLelena;
        TOracleSession *OSelena;
        TOracleDataSet *ODSnaspunkt;
        TOracleQuery *OQgetulid;
        TOracleDataSet *ODSulitsa;
        TOracleQuery *OQnewnpid;
        TOracleQuery *OQokato;
        TOracleQuery *OQcomplex;
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDBase(TComponent* Owner);
    int __fastcall search(TStrings * list,AnsiString pattern);
    void __fastcall digitKey(char &Key,char moreKey);
};
//---------------------------------------------------------------------------
extern PACKAGE TDBase *DBase;
//---------------------------------------------------------------------------
#endif
