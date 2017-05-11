//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("newulnp.res");
USEFORM("main.cpp", Fnewulnp);
USEFORM("database.cpp", DBase); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TDBase), &DBase);
                 Application->CreateForm(__classid(TFnewulnp), &Fnewulnp);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
