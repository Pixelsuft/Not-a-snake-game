//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
int musictype=1;
int RandomX=50;
int RandomY=50;
int RespX=0;
int RespY=0;
bool l=false;
bool r=false;
bool u=false;
bool d=false;
bool gamestarted=false;
int SnakeX=0;
int SnakeY=0;
int Scoree=0;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StarterTimer(TObject *Sender)
{
        Starter->Enabled=false;
        Pixelsuft->Left=0;
        Pixelsuft->Top=0;
        Pixelsuft->Visible=true;
        PixelsuftMove->Enabled=true;      
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PixelsuftMoveTimer(TObject *Sender)
{
        if(PixelsuftMove->Interval==3000)PixelsuftMove->Interval=1;
        if(Pixelsuft->Top<-599)
        {
                PixelsuftMove->Enabled=false;
                Pixelsuft->Visible=false;
                MainForm->BorderStyle=bsSizeable;
                SnakeName->Top=72;
                SnakeName->Left=256;
                SnakeName->Visible=true;  
                StartButton->Top=440;
                StartButton->Left=248;
                StartButton->Visible=true;
                StartColor->Enabled=true;
                if(FileExists("music.txt"))PlaySound("music\\HateBit - MenuTrack.wav",0,SND_ASYNC | SND_LOOP);
        }
        else
        {
                Pixelsuft->Top-=20;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StartColorTimer(TObject *Sender)
{
        if(StartButton->Color==clLime)
        {
                StartButton->Color=clBlack;
                StartButton->Font->Color=clLime;
        }
        else
        {
                StartButton->Color=clLime;
                StartButton->Font->Color=clBlack;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_SPACE && StartButton->Visible==true)
        {
                StartColor->Enabled=false;
                Pixelsuft->Visible=false;
                StartButton->Visible=false;
                SnakeName->Visible=false;
                Score->Visible=true;
                if(FileExists("music.txt")){
                //PlaySound(NULL,0,SND_ASYNC | SND_LOOP);
                /*Randomize();
                musictype = random(5)+1; */
                if(musictype==1)/*if(FileExists("music\\HateBit - Track1.wav"))*/PlaySound("music\\HateBit - Track1.wav",0, SND_ASYNC | SND_LOOP);
                else if(musictype==2)/*if(FileExists("music\\HateBit - Track2.wav"))*/PlaySound("music\\HateBit - Track2.wav",0, SND_ASYNC | SND_LOOP);
                else if(musictype==3)/*if(FileExists("music\\HateBit - Track3.wav"))*/PlaySound("music\\HateBit - Track3.wav",0, SND_ASYNC | SND_LOOP);
                else if(musictype==4)/*if(FileExists("music\\HateBit - Track4.wav"))*/PlaySound("music\\HateBit - Track4.wav",0, SND_ASYNC | SND_LOOP);
                else if(musictype==5)/*if(FileExists("music\\HateBit - Track5.wav"))*/PlaySound("music\\HateBit - Track5.wav",0, SND_ASYNC | SND_LOOP);
                else if(musictype==6)/*if(FileExists("music\\HateBit - Track6.wav"))*/PlaySound("music\\HateBit - Track6.wav",0, SND_ASYNC | SND_LOOP);
                Canvas->Visible=true;
                /*RandX->Enabled=false;
                RandY->Enabled=false;
                Canvas->Canvas->Pen->Color=clBlack;
                Canvas->Canvas->Brush->Color=clBlack;
                Canvas->Canvas->Ellipse(RespX,RespY,RespX+25,RespY+25);
                Canvas->Canvas->Brush->Color=clRed;
                RespX=RandomX;
                RespY=RandomY;
                Canvas->Canvas->Ellipse(RespX,RespY,RespX+25,RespY+25);
                */Canvas->Canvas->Brush->Color=clLime;
                Canvas->Canvas->Pen->Color=clBlue;
                RandY->Enabled=true;
                RandX->Enabled=true;
                int CentX=Canvas->Width/2;
                int CentY=Canvas->Height/2;
                CentX=CentX/25;
                CentY=CentY/25;
                CentX=CentX*25;
                CentY=CentY*25;
                SnakeX=CentX;
                SnakeY=CentY;
                Canvas->Canvas->Ellipse(CentX,CentY,CentX+25,CentY+25);
                Respawn->Enabled=true;
                Move->Enabled=true;
                Mover->Enabled=true;
                gamestarted=true;
        }  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RandomizerTimer(TObject *Sender)
{
        if(musictype==6)musictype=1;
        else musictype++;
        /*RandomX=RandomX/25;
        RandomY=RandomY/25;
        RandomX=RandomX*25;
        RandomY=RandomY*25;*/
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
        Canvas->Width=MainForm->ClientWidth;
        Canvas->Height=MainForm->ClientHeight;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RespawnTimer(TObject *Sender)
{
        Respawn->Enabled=false;
        RandX->Enabled=false;
        RandY->Enabled=false;
        Canvas->Canvas->Pen->Color=clBlack;
        Canvas->Canvas->Brush->Color=clBlack;
        Canvas->Canvas->Ellipse(RespX,RespY,RespX+25,RespY+25);
        Canvas->Canvas->Brush->Color=clRed;
        RespX=RandomX;
        RespY=RandomY;
        Canvas->Canvas->Ellipse(RespX,RespY,RespX+25,RespY+25);
        Canvas->Canvas->Brush->Color=clLime;
        Canvas->Canvas->Pen->Color=clBlue;
        RandY->Enabled=true;
        RandX->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RandXTimer(TObject *Sender)
{
        if(RandomX>Canvas->Width-50)RandomX=0;
        else RandomX=RandomX+25;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RandYTimer(TObject *Sender)
{
        if(RandomY>Canvas->Height-50)RandomY=0;
        else RandomY=RandomY+25;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_LEFT && l==false && r==false && gamestarted==true)
        {
                l=true;
                u=false;
                d=false;
        }
        else if(Key==VK_RIGHT && l==false && r==false && gamestarted==true)
        {
                r=true;
                u=false;
                d=false;
        }
        else if(Key==VK_UP && u==false && d==false && gamestarted==true)
        {
                u=true;
                l=false;
                r=false;
        }
        else if(Key==VK_DOWN && u==false && d==false && gamestarted==true)
        {
                d=true;
                l=false;
                r=false;
        }
        else if(Key==65 && l==false && r==false && gamestarted==true)
        {
                l=true;
                u=false;
                d=false;
        }
        else if(Key==68 && l==false && r==false && gamestarted==true)
        {
                r=true;
                u=false;
                d=false;
        }
        else if(Key==87 && u==false && d==false && gamestarted==true)
        {
                u=true;
                l=false;
                r=false;
        }
        else if(Key==83 && u==false && d==false && gamestarted==true)
        {
                d=true;
                l=false;
                r=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MoveTimer(TObject *Sender)
{
        if(SnakeX==RespX && SnakeY==RespY){
        RandX->Enabled=false;
        RandY->Enabled=false;
        Canvas->Canvas->Brush->Color=clRed;
        Canvas->Canvas->Pen->Color=clBlack;
        RespX=RandomX;
        RespY=RandomY;
        Canvas->Canvas->Ellipse(RespX,RespY,RespX+25,RespY+25);
        Canvas->Canvas->Brush->Color=clLime;
        Canvas->Canvas->Pen->Color=clBlue;   
        Scoree=Scoree+1;
        Score->Caption="Score: " + IntToStr(Scoree);
        if(Move->Interval>50)Move->Interval-=20;
        RandY->Enabled=true;
        RandX->Enabled=true;
        }
        else{
        Canvas->Canvas->Pen->Color=clBlack;
        Canvas->Canvas->Brush->Color=clBlack;
        Canvas->Canvas->Ellipse(SnakeX,SnakeY,SnakeX+25,SnakeY+25);
        if(l && SnakeX>0)SnakeX-=25;
        else if(r && SnakeX<Canvas->Width-25)SnakeX+=25;
        else if(u && SnakeY>0)SnakeY-=25;
        else if(d && SnakeY<Canvas->Height-25)SnakeY+=25;
        Canvas->Canvas->Brush->Color=clLime;
        Canvas->Canvas->Pen->Color=clBlue;
        Canvas->Canvas->Ellipse(SnakeX,SnakeY,SnakeX+25,SnakeY+25);
        //Mover->Enabled=true;
        }
        //Mover->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MoverTimer(TObject *Sender)
{
        Mover->Enabled=false;
        Canvas->Canvas->Pen->Color=clBlack;
        Canvas->Canvas->Brush->Color=clBlack;
        Canvas->Canvas->Ellipse(SnakeX,SnakeY,SnakeX+25,SnakeY+25);
        Canvas->Canvas->Brush->Color=clLime;
        Canvas->Canvas->Pen->Color=clBlue;
        Canvas->Canvas->Ellipse(SnakeX,SnakeY,SnakeX+25,SnakeY+25);
        RandX->Enabled=false;
        RandY->Enabled=false;
        /*Canvas->Canvas->Pen->Color=clBlack;
        Canvas->Canvas->Brush->Color=clBlack;
        Canvas->Canvas->Ellipse(RespX,RespY,RespX+25,RespY+25);
        if(SnakeX==RespX && SnakeY==RespY){
        Canvas->Canvas->Brush->Color=clRed;
        Canvas->Canvas->Pen->Color=clBlack;
        RespX=RandomX;
        RespY=RandomY;
        Canvas->Canvas->Ellipse(RespX,RespY,RespX+25,RespY+25);
        Canvas->Canvas->Brush->Color=clLime;
        Canvas->Canvas->Pen->Color=clBlue;
        RandY->Enabled=true;
        RandX->Enabled=true;
        }                 */
}
//---------------------------------------------------------------------------




