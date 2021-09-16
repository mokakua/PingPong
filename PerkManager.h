#ifndef PerkManagerH
#define PerkManagerH

#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include "PaddleData.h"
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
int perkTime;
char whoHitPerk;
bool isCannonBallOn;


public:

PerkManager();

void pickRandomPerk();
void showPerkIcon(TShape* perkShape, TShape* gameArea);
bool isPerkOn();
void turnPerkOn(TShape* perkShape,TShape* gameArea, TLabel* perkTimeLabel);
int getPickedPerkNumber();
void perkHitAction(TShape* perkShape, TLabel* perkTimeLabel);
int getPerkSpeed();
void setPerkTime(int pTime);
int getPerkTime();
void changePerkDirectionIfHitWall(TShape* perkShape, TShape* gameArea);
bool doesPerkHitWall(TShape* perkShape, TShape* gameArea);
bool doesBallHitPerkShape(TShape* perkShape, TShape* ball);
void setWhoHitPerk(int xSpeed);
char getWhoHitPerk();
void finishPerks(PaddleData *paddleLeftData, PaddleData *paddleRightData);
bool getIsCannonBallOn();
void turnCannonBallOn();
void showPerksDescription(TShape* perkShape, TShape* perkShape1, TShape* perkShape2, TLabel* perkDescription, TLabel* perk1Description, TLabel* perk2Description);
void hidePerksDescription(TShape* perkShape, TShape* perkShape1, TShape* perkShape2, TLabel* perkDescription, TLabel* perk1Description, TLabel* perk2Description);
};
//---------------------------------------------------------------------------
#endif