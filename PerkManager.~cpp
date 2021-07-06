#include "PerkManager.h"

PerkManager::PerkManager(){

perkOn = false;
pickedPerk = 0;
perkSpeed = 2;
whoHitPerk = NULL;
Perk perk("Drunk Mode", "Chenges opponent's paddle speed and steering", clRed, 10);
perks.push_back(perk);
Perk perk1("Cannon Ball", "Catches the ball and shoot with incredible speed", clBlue, 0);
perks.push_back(perk1);
Perk perk2("Elongation", "Elongates player's paddle length", clYellow, 15);
perks.push_back(perk2);
}

void PerkManager::pickRandomPerk(){
        randomize();
        int perkSize = perks.size();
        pickedPerk = rand()%perkSize;

}

void PerkManager::showPerkIcon(TShape* perkShape, TShape* gameArea){
        perkShape->Brush->Color = perks[pickedPerk].getColor();
        perkShape->Left = gameArea->Width/2 - perkShape->Width/2;
        perkShape->Top = rand()%(gameArea->Height - perkShape->Height-10)+10;
        perkShape->Visible = true;
}

bool PerkManager::isPerkOn(){
        return perkOn;
}

int PerkManager::getPickedPerkNumber(){
        return pickedPerk;
}

void PerkManager::perkHitAction(TShape* perkShape, TLabel* perkTimeLabel){
        perkTimeLabel->Font->Color = perks[pickedPerk].getColor();
        perkOn = true;
}

int PerkManager::getPerkSpeed(){
        return perkSpeed;
}

void PerkManager::changePerkDirectionIfHitWall(TShape* perkShape, TShape* gameArea){
        if (doesPerkHitWall(perkShape, gameArea)){
                perkSpeed *= -1;
        }
}

bool PerkManager::doesPerkHitWall(TShape* perkShape, TShape* gameArea){
         if (perkSpeed <0 && perkShape->Top <= 5){
                return true;
        }else if (perkSpeed > 0 && perkShape->Top + perkShape->Height >= gameArea->Height - 5){
                return true;
        }
        return false;
}

bool PerkManager::doesBallHitPerkShape(TShape* perkShape, TShape* ball){
        int ballR = ball->Width/2;
        int perkR = perkShape->Width/2;
        int ballX = ball->Left+ballR/2;
        int ballY = ball->Top+ballR/2;
        int perkX = perkShape->Left+perkR/2;
        int perkY = perkShape->Top+perkR/2;
        int centersDistance = pow(pow(ballX-perkX,2)+pow(ballY-perkY,2),0.5);
        if(centersDistance <= ballR + perkR){
                return true;
        }
        return false;
}

void PerkManager::setWhoHitPerk(int xSpeed){
        if (xSpeed > 0){
                whoHitPerk = 'l';
        } else {
                whoHitPerk = 'r';
        }
}

char PerkManager::getWhoHitPerk(){
        return whoHitPerk;
}

void PerkManager::finishPerks(){
        //pickedPerk = 0;
}
