//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Pixelsuft;
        TTimer *Starter;
        TTimer *PixelsuftMove;
        TLabel *SnakeName;
        TLabel *StartButton;
        TTimer *StartColor;
        TTimer *Randomizer;
        TImage *Canvas;
        TTimer *Respawn;
        TTimer *RandX;
        TTimer *RandY;
        TTimer *Move;
        TTimer *Mover;
        TLabel *Score;
        void __fastcall StarterTimer(TObject *Sender);
        void __fastcall PixelsuftMoveTimer(TObject *Sender);
        void __fastcall StartColorTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall RandomizerTimer(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall RespawnTimer(TObject *Sender);
        void __fastcall RandXTimer(TObject *Sender);
        void __fastcall RandYTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall MoveTimer(TObject *Sender);
        void __fastcall MoverTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
