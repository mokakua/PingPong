#include "PerkManager.h"

PerkManager::PerkManager(){

Perk perk("Drunk Mode", "Chenges opponent's paddle speed and steering", clRed, 10);
perks.push_back(perk);
Perk perk1("Cannon Ball", "Catches the ball and shoot with incredible speed", clBlue, 0);
perks.push_back(perk1);
Perk perk2("Elongation", "Elongates player's paddle length", clYellow, 15);
perks.push_back(perk2);
}

int PerkManager::pickRandomPerk(){

}

void PerkManager::showPerkIcon(TShape perk){

}

bool PerkManager::isPerkOn(){

}

int PerkManager::getPickedPerkNumber(){

}

void PerkManager::perkHitAction(TShape perk, TLabel timerLabel){

}
