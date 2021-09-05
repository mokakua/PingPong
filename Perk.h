#ifndef PerkH
#define PerkH

#include <Classes.hpp>
#include <Controls.hpp>

//---------------------------------------------------------------------------
class Perk{

AnsiString name;
AnsiString description;
TColor color;
int duration;

public:

Perk(AnsiString name, AnsiString description, TColor color, int duration);
AnsiString getName();
AnsiString getDescription();
TColor getColor();
int getDuration();

};
//---------------------------------------------------------------------------
#endif