#include "PerkManager.h"
#include "Unit1.h"

PerkManager::PerkManager(){

        perkOn = false;
        pickedPerk = 0;
        perkSpeed = 2;
        perkTime = 0;
        whoHitPerk = NULL;
        Perk perk("Drunk Mode", "Changes opponent's paddle speed and steering", clRed, 10);
        perks.push_back(perk);
        Perk perk1("Cannon Ball", "Catches the ball and shoot with incredible speed", clBlue, 0);
        perks.push_back(perk1);
        Perk perk2("Elongation", "Elongates player's paddle length", clYellow, 15);
        perks.push_back(perk2);
}
//---------------------------------------------------------------------------
void PerkManager::pickRandomPerk(){
        randomize();
        int perkSize = perks.size();
        pickedPerk = rand()%perkSize;

}
//---------------------------------------------------------------------------
void PerkManager::showPerkIcon(TShape* perkShape, TShape* gameArea){
        perkShape->Brush->Color = perks[pickedPerk].getColor();
        perkShape->Left = gameArea->Width/2 - perkShape->Width/2;
        perkShape->Top = rand()%(gameArea->Height - perkShape->Height-10)+10;
        perkShape->Visible = true;
}
//---------------------------------------------------------------------------
bool PerkManager::isPerkOn(){
        return perkOn;
}
//---------------------------------------------------------------------------
void PerkManager::turnPerkOn(TShape* perkShape,TShape* gameArea, TLabel* perkTimeLabel){
        pickRandomPerk();
        showPerkIcon(perkShape, gameArea);
        perkHitAction(perkShape, perkTimeLabel);
}
//---------------------------------------------------------------------------
int PerkManager::getPickedPerkNumber(){
        return pickedPerk;
}
//---------------------------------------------------------------------------
void PerkManager::setPerkTime(int pTime){
        perkTime = pTime;
}
//---------------------------------------------------------------------------
int PerkManager::getPerkTime(){
        return perkTime;
}
//---------------------------------------------------------------------------
void PerkManager::perkHitAction(TShape* perkShape, TLabel* perkTimeLabel){
        perkTimeLabel->Font->Color = perks[pickedPerk].getColor();
        perkOn = true;
}
//---------------------------------------------------------------------------
int PerkManager::getPerkSpeed(){
        return perkSpeed;
}

void PerkManager::changePerkDirectionIfHitWall(TShape* perkShape, TShape* gameArea){
        if (doesPerkHitWall(perkShape, gameArea)){
                perkSpeed *= -1;
        }
}
//---------------------------------------------------------------------------
bool PerkManager::doesPerkHitWall(TShape* perkShape, TShape* gameArea){
         if (perkSpeed <0 && perkShape->Top <= 5){
                return true;
        }else if (perkSpeed > 0 && perkShape->Top + perkShape->Height >= gameArea->Height - 5){
                return true;
        }
        return false;
}
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
void PerkManager::setWhoHitPerk(int xSpeed){
        if (xSpeed > 0){
                whoHitPerk = 'l';
        } else {
                whoHitPerk = 'r';
        }
}
//---------------------------------------------------------------------------
char PerkManager::getWhoHitPerk(){
        return whoHitPerk;
}
//---------------------------------------------------------------------------
void PerkManager::perk1DrunkMode(PaddleData *paddleLeftData, PaddleData *paddleRightData){
        int drunkMultiplier = 3;
        if(getWhoHitPerk() == 'l'){
                paddleRightData->swapKeys();
                paddleRightData->setPaddleSpeed(drunkMultiplier * paddleRightData->getPaddleSpeed());
        }else{
                paddleLeftData->swapKeys();
                paddleLeftData->setPaddleSpeed(paddleLeftData->getPaddleSpeed()*drunkMultiplier);
        }
}
//---------------------------------------------------------------------------
void PerkManager::perk3Elongation(PaddleData *paddleLeftData, PaddleData *paddleRightData){
        if(getWhoHitPerk() == 'r'){
                (paddleRightData->getPaddleShape())->Height *=2;
        }else if(getWhoHitPerk() == 'l'){
                (paddleLeftData->getPaddleShape())->Height *=2;
        }
}
//---------------------------------------------------------------------------
void PerkManager::finishPerks(PaddleData *paddleLeftData, PaddleData *paddleRightData){
        pickedPerk = 0;
        perkOn = false;
        whoHitPerk = NULL;
        perkTime = 0;

        //drunkMode
        paddleRightData->setKeyUp(TForm1::KEY_RIGHT_UP);
        paddleRightData->setKeyDown(TForm1::KEY_RIGHT_DOWN);
        paddleLeftData->setKeyUp(TForm1::KEY_LEFT_UP);
        paddleLeftData->setKeyDown(TForm1::KEY_LEFT_DOWN);
        paddleRightData->setPaddleSpeed(TForm1::PADDLE_SPEED);
        paddleLeftData->setPaddleSpeed(TForm1::PADDLE_SPEED);

        //elongation
        (paddleLeftData->getPaddleShape())->Height = TForm1::PADDLE_LENGTH;
        (paddleRightData->getPaddleShape())->Height = TForm1::PADDLE_LENGTH;

        //cannonBall
        isCannonBallOn = false;
        //TForm1::cannonTimer->Enabled = false;
        //cannonTimer->Enabled = false;
        //paddleRightData->setPaddleSpeed(TForm1::PADDLE_SPEED);
        //paddleLeftData->setPaddleSpeed(TForm1::PADDLE_SPEED);

}
//---------------------------------------------------------------------------

bool PerkManager::getIsCannonBallOn(){
        return isCannonBallOn;
}
//---------------------------------------------------------------------------
void PerkManager::turnCannonBallOn(){
        isCannonBallOn = true;
}
//---------------------------------------------------------------------------
void PerkManager::showPerksDescription(TShape* perkShape, TShape* perkShape1, TShape* perkShape2, TLabel* perkDescription, TLabel* perk1Description, TLabel* perk2Description){
        perkShape->Visible = true;
        perkShape1->Visible = true;
        perkShape2->Visible = true;
        perkDescription->Visible = true;
        perk1Description->Visible = true;
        perk2Description->Visible = true;

        perkShape->Left =  300;
        perkShape->Top =  100;
        perkShape1->Left =  perkShape->Left;
        perkShape1->Top =  perkShape->Top + 100;
        perkShape2->Left =  perkShape1->Left;
        perkShape2->Top =  perkShape1->Top + 100;

        perkDescription->Left =  perkShape->Left + 100;
        perkDescription->Top =  perkShape->Top + 20;
        perk1Description->Left =  perkShape1->Left + 100;
        perk1Description->Top =  perkShape1->Top + 20;
        perk2Description->Left =  perkShape2->Left + 100;
        perk2Description->Top =  perkShape2->Top + 20;

        perkDescription->Visible = true;
        perk1Description->Visible = true;
        perk2Description->Visible = true;

        perkShape->Brush->Color = perks[0].getColor();
        perkShape1->Brush->Color = perks[1].getColor();
        perkShape2->Brush->Color = perks[2].getColor();
        perkDescription->Caption = perks[0].getDescription();
        perk1Description->Caption = perks[1].getDescription();
        perk2Description->Caption = perks[2].getDescription();
}
//---------------------------------------------------------------------------
void PerkManager::hidePerksDescription(TShape* perkShape, TShape* perkShape1, TShape* perkShape2, TLabel* perkDescription, TLabel* perk1Description, TLabel* perk2Description){
        perkShape->Visible = false;
        perkShape1->Visible = false;
        perkShape2->Visible = false;
        perkDescription->Visible = false;
        perk1Description->Visible = false;
        perk2Description->Visible = false;
}
//---------------------------------------------------------------------------
