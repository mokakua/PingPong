#include "Perk.h"

Perk::Perk(AnsiString name, AnsiString description, TColor color, int duration){
this->name = name;
this->description = description;
this->color = color;
this->duration = duration;
}

AnsiString Perk::getName(){
        return name;
}
AnsiString Perk::getDescription(){
        return description;
}
TColor Perk::getColor(){
        return color;
}
int Perk::getDuration(){
        return duration;
}
