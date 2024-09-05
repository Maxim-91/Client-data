//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "fstream.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
 int d=-1;
 typedef struct
 {
  AnsiString pol, im;
  int vo, r, ves, vo1,vo2, r1,r2, ves1,ves2;
 } Tstud;
 Tstud st[50];
 FILE *ff;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button1Click(TObject *Sender)
{
 d++;
 if (RadioButton1->Checked==true) st[d].pol="муржской";
 else st[d].pol="женський";
 st[d].im=Edit2->Text;
 st[d].vo=StrToInt(Edit3->Text);
 st[d].r=StrToInt(Edit4->Text);
 st[d].ves=StrToInt(Edit5->Text);
 st[d].vo1=StrToInt(Edit6->Text);
 st[d].vo2=StrToInt(Edit7->Text);
 st[d].r1=StrToInt(Edit8->Text);
 st[d].r2=StrToInt(Edit9->Text);
 st[d].ves1=StrToInt(Edit10->Text);
 st[d].ves2=StrToInt(Edit11->Text);

 Memo1->Lines->Add(st[d].pol+"  "+st[d].im+"  "+st[d].vo+"  "+st[d].r+"  "+st[d].ves+" [ "+st[d].vo1+"  "+st[d].vo2+" ][ "+st[d].r1+"  "+st[d].r2+" ][ "+st[d].ves1+"  "+st[d].ves2+" ]");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int i,j;

 for (i=0;i<d;i++)
 {
  if (st[i].pol=="0") goto n;

  for (j=0;j<d;j++)
  {
   if ((st[j].pol=="0")||j==i) goto m;
   else {if (((st[i].pol=="женський"&&st[j].pol=="муржской")||
             (st[j].pol=="женський"&&st[i].pol=="муржской"))&&
            st[j].vo>st[i].vo1&&st[j].vo<st[i].vo2&&
            st[j].r>st[i].r1&&st[j].r<st[i].r2&&
            st[j].ves>st[i].ves1&&st[j].ves<st[i].ves2&&
            st[i].vo>st[j].vo1&&st[i].vo<st[j].vo2&&
            st[i].r>st[j].r1&&st[i].r<st[j].r2&&
            st[i].ves>st[j].ves1&&st[i].ves<st[j].ves2)
   {
    Memo2->Lines->Add(st[i].pol+"  "+st[i].im+"  "+st[i].vo+"  "+st[i].r+"  "+st[i].ves);
    Memo2->Lines->Add(st[j].pol+"  "+st[j].im+"  "+st[j].vo+"  "+st[j].r+"  "+st[j].ves);
    Memo2->Lines->Add(" ");

    st[i].pol="0";
    st[j].pol="0";
    goto n;
   }}

   m:
  }
  n:
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int i;
 ofstream ff("Spusok_klientiv.text");
 for (i=0; i<=d;i++)
 {
  char* pol=st[i].pol.c_str();
  char* im=st[i].im.c_str();

  ff<<pol<<" "<<im<<" "<<st[i].vo<<" "<<st[i].r<<" "<<st[i].ves<<" "<<st[i].vo1<<" "<<st[i].vo2<<" "<<st[i].r1<<" "<<st[i].r2<<" "<<st[i].ves1<<" "<<st[i].ves2<<endl;
 }
 ff.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 int i;
 ifstream ff("Spusok_klientiv.text");
 for (i=0; i<=5;i++)
 {
  char pol;
  char im;

  ff>>pol>>im>>st[i].vo>>st[i].r>>st[i].ves>>st[i].vo1>>st[i].vo2>>st[i].r1>>st[i].r2>>st[i].ves1>>st[i].ves2;

  st[i].pol=pol;
  st[i].im=im;
  Memo1->Lines->Add(st[i].pol+" "+st[i].im);
 }
 ff.close();
}
//---------------------------------------------------------------------------

