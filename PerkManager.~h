#ifndef PerkManagerH
#define PerkManagerH

#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include "Perk.h"
#include "DrunkMode.h"
#include "CannonBall.h"
#include "Elongation.h"

#include <vector>
#include <math.h>

using namespace std;

//---------------------------------------------------------------------------
class PerkManager{

vector <Perk> perks;
bool perkOn;
int pickedPerk;
int perkSpeed;
char whoHitPerk;

public:

PerkManager();

void pickRandomPerk();
void showPerkIcon(TShape* perkShape, TShape* gameArea);
bool isPerkOn();
int getPickedPerkNumber();
void perkHitAction(TShape* perkShape, TLabel* perkTimeLabel);
int getPerkSpeed();
void changePerkDirectionIfHitWall(TShape* perkShape, TShape* gameArea);
bool doesPerkHitWall(TShape* perkShape, TShape* gameArea);
bool doesBallHitPerkShape(TShape* perkShape, TShape* ball);
void setWhoHitPerk(int xSpeed);
char getWhoHitPerk();
void finishPerks();

};
//---------------------------------------------------------------------------
#endif