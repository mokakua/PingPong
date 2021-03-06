//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner), MAX_BALL_SPEED(25), MIN_BALL_SPEED(8),
        PADDLE_TO_BORDER_DISTANCE(80), MAX_SPEED_RATIO(2), PERK_DURATION(8),
        paddleLeftData(NULL), paddleRightData(NULL)
{
        leftPoints = 0;
        rightPoints = 0;
        ballSpeed = MIN_BALL_SPEED;
        ballHits = 0;
        cannonBallTime = 0;
        hitsToSpeedIncrease = 3;
        paddleLeftData = new PaddleData(paddleLeftShape, PADDLE_SPEED, KEY_LEFT_UP, KEY_LEFT_DOWN);
        paddleRightData = new PaddleData(paddleRightShape, PADDLE_SPEED, KEY_RIGHT_UP, KEY_RIGHT_DOWN);
        perkManager.showPerksDescription(perkShape1, perkShape2, perkShape3, perk1Description, perk2Description, perk3Description);
        gameArea->Width = 1400;
        gameArea->Height = 700;
        ShowMessage     ("Welcome! Let's try Ping Pong game!\nControl your paddle with:\nA and Z buttons for left player,\nUP and DOWN arrow buttons for right player\nCollect perks and win the game.\nGood luck!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        prepareIconsLayout();
        dalejButton->Enabled = false;
        dalejButton->Visible = false;
        koniecButton->Enabled = false;
        koniecButton->Visible = false;
        setStartBallSpeed();
}
//---------------------------------------------------------------------------
void TForm1::prepareIconsLayout(){

        paddleLeftShape->Height = PADDLE_LENGTH;
        paddleRightShape->Height = PADDLE_LENGTH;
        paddleLeftShape->Left = PADDLE_TO_BORDER_DISTANCE;
        paddleLeftShape->Top = gameArea->Height/2-paddleLeftShape->Height/2;
        paddleRightShape->Left = gameArea->Width-paddleRightShape->Width-PADDLE_TO_BORDER_DISTANCE;
        paddleRightShape->Top = gameArea->Height/2-paddleRightShape->Height/2;

        lPointsLabel->Left = PADDLE_TO_BORDER_DISTANCE + 100;
        lPointsLabel->Top = gameArea->Height/2 - lPointsLabel->Height/2;
        rPointsLabel->Left = gameArea->Width - PADDLE_TO_BORDER_DISTANCE - 100 - rPointsLabel->Width;
        rPointsLabel->Top = gameArea->Height/2 - rPointsLabel->Height/2;

        startButton->Top =  gameArea->Height/2 - startButton->Height/2 + 100;
        koniecButton->Top = gameArea->Height/2 - koniecButton->Height/2 + 100;
        dalejButton->Top =  gameArea->Height/2  - 100;

        startButton->Left =  gameArea->Width/2 - startButton->Width/2;
        koniecButton->Left = gameArea->Width/2 - koniecButton->Width/2;
        dalejButton->Left =  gameArea->Width/2 - dalejButton->Width/2;

        countdownLabel->Font->Size = gameArea->Height*0.7;
        countdownLabel->Left = gameArea->Width/2 - countdownLabel->Width/2;
        countdownLabel->Top =  gameArea->Height/2 - countdownLabel->Height/2;

        ball->Left = gameArea->Width/2 - ball->Width/2;
        ball->Top = gameArea->Height/2 - ball->Height/2;

        perkTimeLabel->Left = gameArea->Width/2 - perkTimeLabel->Width/2;
        perkTimeLabel->Top = gameArea->Height/2 - perkTimeLabel->Height/2;

        BSpeedLabel1->Left =  gameArea->Width/2 - 300;
        BSpeedLabel1->Top =  gameArea->Height - 50;
        BSpeedLabel->Left =  BSpeedLabel1->Left + 100;
        BSpeedLabel->Top =  gameArea->Height - 50;

        hitsLabel1->Left =  gameArea->Width/2 + 100;
        hitsLabel1->Top =  gameArea->Height - 50;
        hitsLabel->Left =  hitsLabel1->Left + 100;
        hitsLabel->Top =  gameArea->Height - 50;
}
//---------------------------------------------------------------------------
void TForm1::setStartBallSpeed(){

        randomize();
        //rand number < -MAX_SPEED_RATIO,MAX_SPEED_RATIO >
        float startSpeedRatio = (rand()%(MAX_SPEED_RATIO*20+1)-MAX_SPEED_RATIO*10)/10.0;
        xSpeed = rand()%2; //0 or 1 to randomize direction
        ballSpeed = MIN_BALL_SPEED;
        setBallSpeed(startSpeedRatio);
}
//---------------------------------------------------------------------------
void TForm1::setBallSpeed(float speedRatio){

        int xSpeedTemp = pow(pow(ballSpeed,2)/(pow(speedRatio,2)+1),0.5);
        if (xSpeed > 0){
                xSpeed = -xSpeedTemp;
        }else{
                xSpeed = xSpeedTemp;
        }
        ySpeed = speedRatio* abs(xSpeed);
}
//---------------------------------------------------------------------------
float TForm1::calcBallSpeedRatio(TShape* paddle){
        float speedRatio = 0;

        float paddleLengthRatio = (ball->Top+ball->Height/2.0 - paddle->Top)/paddle->Height;

        speedRatio = 2*MAX_SPEED_RATIO*paddleLengthRatio - MAX_SPEED_RATIO;

        return speedRatio;

}
//---------------------------------------------------------------------------
bool TForm1::doesBallHitPaddle(TShape* paddle){

        int ballY = ball->Top + ball->Height/2;

        if (ballY >= paddle->Top && ballY <= paddle->Top + paddle->Height){

                if (xSpeed < 0){
                        if (ball->Left <= paddle->Left+paddle->Width){
                                return true;
                        }
                }else {
                        if (ball->Left + ball->Width >= paddle->Left){
                                return true;
                        }
                }
        }
        return false;
}

//---------------------------------------------------------------------------
bool TForm1::doesBallHitWall(){
         if (ySpeed < 0 && ball->Top <= 5){
                return true;
        }else if (ySpeed > 0 && ball->Top + ball->Height >= gameArea->Height - 5){
                return true;
        }
        return false;
}

//---------------------------------------------------------------------------

bool TForm1::isFail(){

        if (ball->Left < PADDLE_TO_BORDER_DISTANCE - 25 ||
            ball->Left + ball->Width > gameArea->Width - (PADDLE_TO_BORDER_DISTANCE - 25)){
                return true;
            }
        return false;
}
//---------------------------------------------------------------------------
void TForm1::pauseGameAfterFail(){

        PlaySound(MAKEINTRESOURCE(IDR_WAVE1),GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
        timersOff();
        finishPerks();
        ball->Visible = false;
        setPoints();
        dalejButton->Enabled = true;
        dalejButton->Visible = true;
        koniecButton->Enabled = true;
        koniecButton->Visible = true;
}
//---------------------------------------------------------------------------
void TForm1::timersOff(){
        mainTimer->Enabled = false;
        paddleLeftUpTimer->Enabled = false;
        paddleLeftDownTimer->Enabled = false;
        paddleRightUpTimer->Enabled = false;
        paddleRightDownTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void TForm1::setPoints(){
        if(xSpeed > 0){
                leftPoints++;
        }else{
                rightPoints++;
        }
        lPointsLabel->Caption = leftPoints;
        rPointsLabel->Caption = rightPoints;
}
//---------------------------------------------------------------------------
void TForm1::startTheRound(){
        countdownLabel->Visible = true;
        ballHits = 0;
        ballSpeed = MIN_BALL_SPEED;
        hitsLabel->Caption = ballHits;
        BSpeedLabel->Caption = ballSpeed;
        for(int countdown = 3; countdown >0; countdown--){
                countdownLabel->Caption = countdown;
                Application->ProcessMessages();
                Sleep(700);
        }
        ball->Visible = true;
        mainTimer->Enabled = true;
        countdownLabel->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::mainTimerTimer(TObject *Sender)
{
        ball->Left += xSpeed;
        ball->Top += ySpeed;

        if(perkShape->Visible){
                perkShape->Top += perkManager.getPerkSpeed();
        }

        if(!perkManager.isPerkOn() && !perkTimer->Enabled){
                perkManager.setPerkTime(0);
                perkTimer->Enabled = true;
        }else if (perkManager.isPerkOn() && !perkTimer->Enabled){
                perkHitAction();
        }
        perkManager.changePerkDirectionIfHitWall(perkShape,gameArea);

        if (doesBallHitWall()){
                ySpeed *= -1;
        }

        if (isFail()){
                pauseGameAfterFail();

        }else{
                paddleHitAction();
        }

}
//---------------------------------------------------------------------------
void TForm1::perkHitAction(){
        if (perkManager.doesBallHitPerkShape(perkShape, ball)){
        perkManager.setWhoHitPerk(xSpeed);
        perkShape->Visible = false;
        perkManager.setPerkTime(0);
        perkTimer->Enabled = true;
        PlaySound(MAKEINTRESOURCE(IDR_WAVE3),GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
        perkTimeLabel->Visible = true;
        perkTimeLabel->Caption = PERK_DURATION;
        switch (perkManager.getPickedPerkNumber()){
                case 0:{
                        perkManager.perk1DrunkMode(paddleLeftData, paddleRightData);
                }break;
                case 1:{
                }break;
                case 2:{
                        perkManager.perk3Elongation(paddleLeftData, paddleRightData);
                }break;
                }
        }
}
//---------------------------------------------------------------------------
void TForm1::paddleHitAction(){
        if(xSpeed >0 && doesBallHitPaddle(paddleRightShape)){
                ballHits++;
                PlaySound(MAKEINTRESOURCE(IDR_WAVE2),GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
                if(ballHits%hitsToSpeedIncrease==0 && ballHits>0 && ballSpeed<MAX_BALL_SPEED){
                        ballSpeed++;
                }
                if (perkManager.getPickedPerkNumber()==1 && perkManager.getWhoHitPerk() == 'r'){
                        perk2CannonBall();
                }else{
                        setBallSpeed(calcBallSpeedRatio(paddleRightShape));
                }


        }else if (xSpeed <0 && doesBallHitPaddle(paddleLeftShape)){
                ballHits++;
                PlaySound(MAKEINTRESOURCE(IDR_WAVE2),GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
                if(ballHits%hitsToSpeedIncrease==0 && ballHits>0 && ballSpeed<MAX_BALL_SPEED){
                        ballSpeed++;
                }
                if (perkManager.getPickedPerkNumber()==1 && perkManager.getWhoHitPerk() == 'l'){
                        perk2CannonBall();
                }else{
                        setBallSpeed(calcBallSpeedRatio(paddleLeftShape));
                }
        }

        hitsLabel->Caption = ballHits;
        BSpeedLabel->Caption = ballSpeed;
}
//---------------------------------------------------------------------------
void TForm1::finishPerks(){
        perkManager.finishPerks(paddleLeftData, paddleRightData);
        perkTimer->Enabled = false;
        perkTimeLabel->Visible = false;
        perkShape->Visible = false;

        cannonTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void TForm1::perk2CannonBall(){
        cannonBallTime = 3;
        cannonTimer->Enabled = true;
        perkTimer->Enabled = false;
        perkManager.turnCannonBallOn();
        mainTimer->Enabled = false;
        perkTimeLabel->Caption = cannonBallTime;
        ySpeed = 0;
        if (perkManager.getWhoHitPerk() == 'l'){
                paddleLeftData->setPaddleSpeed(PADDLE_SPEED*1.5);
                ball->Top = paddleLeftShape->Top+paddleLeftShape->Height/2 - ball->Height/2;
                ball->Left = paddleLeftShape->Left + paddleLeftShape->Width;
                xSpeed = 50;
        }else{
                paddleRightData->setPaddleSpeed(PADDLE_SPEED*1.5);
                ball->Top = paddleRightShape->Top+paddleRightShape->Height/2 - ball->Height/2;
                ball->Left = paddleRightShape->Left - ball->Width;
                xSpeed = -50;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::perkTimerTimer(TObject *Sender)
{
        //perkTime++;
        perkManager.setPerkTime(perkManager.getPerkTime()+1);
        perkTimeLabel->Caption =  PERK_DURATION-perkManager.getPerkTime()/*perkTime*/;

        if (!perkManager.isPerkOn()){
                if(/*perkTime*/perkManager.getPerkTime() >= 2){
                        perkManager.turnPerkOn(perkShape, gameArea, perkTimeLabel);
                        perkTimer->Enabled = false;
                }
        }

        if (perkManager.getWhoHitPerk() != NULL && /*perkTime*/perkManager.getPerkTime() >= PERK_DURATION){
                finishPerks();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cannonTimerTimer(TObject *Sender)
{
        cannonBallTime--;
        perkTimeLabel->Caption = cannonBallTime;
        if(cannonBallTime <= 0){
                finishPerks();
                mainTimer->Enabled = true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        delete paddleLeftData;
        delete paddleRightData;
        Application->Terminate();
}
//---------------------------------------------------------------------------
//keys
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleRightUpTimerTimer(TObject *Sender)
{
        if (paddleRightShape->Top >= 5){
                paddleRightShape->Top -= paddleRightData->getPaddleSpeed();
                if (perkManager.getIsCannonBallOn() && perkManager.getWhoHitPerk() == 'r'){
                        ball->Top -= paddleRightData->getPaddleSpeed();
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleRightDownTimerTimer(TObject *Sender)
{
        if (paddleRightShape->Top + paddleRightShape->Height <= gameArea->Height - 5){
                paddleRightShape->Top += paddleRightData->getPaddleSpeed();
                if (perkManager.getIsCannonBallOn() && perkManager.getWhoHitPerk() == 'r'){
                        ball->Top += paddleRightData->getPaddleSpeed();
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleLeftUpTimerTimer(TObject *Sender)
{
        if (paddleLeftShape->Top >= 5){
                paddleLeftShape->Top -= paddleLeftData->getPaddleSpeed();
                if (perkManager.getIsCannonBallOn() && perkManager.getWhoHitPerk() == 'l'){
                        ball->Top -= paddleLeftData->getPaddleSpeed();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddleLeftDownTimerTimer(TObject *Sender)
{
        if (paddleLeftShape->Top + paddleLeftShape->Height <= gameArea->Height - 5){
                paddleLeftShape->Top += paddleLeftData->getPaddleSpeed();
                if (perkManager.getIsCannonBallOn() && perkManager.getWhoHitPerk() == 'l'){
                        ball->Top += paddleLeftData->getPaddleSpeed();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == paddleRightData->getKeyUp()){
                paddleRightUpTimer->Enabled = true;

        }
        if (Key == paddleRightData->getKeyDown()){
                paddleRightDownTimer->Enabled = true;
        }
        if (Key == paddleLeftData->getKeyUp()){
                paddleLeftUpTimer->Enabled = true;
        }
        if (Key == paddleLeftData->getKeyDown()){
                paddleLeftDownTimer->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == paddleRightData->getKeyUp()){
                paddleRightUpTimer->Enabled = false;
        }
        if (Key == paddleRightData->getKeyDown()){
                paddleRightDownTimer->Enabled = false;
        }
        if (Key == paddleLeftData->getKeyUp()){
                paddleLeftUpTimer->Enabled = false;
        }
        if (Key == paddleLeftData->getKeyDown()){
                paddleLeftDownTimer->Enabled = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::startButtonClick(TObject *Sender)
{
        startButton->Enabled = false;
        startButton->Visible = false;
        perkManager.hidePerksDescription(perkShape1, perkShape2, perkShape3, perk1Description, perk2Description, perk3Description);
        FormCreate(Application);
        setStartBallSpeed();
        startTheRound();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::dalejButtonClick(TObject *Sender)
{
        FormCreate(Application);
        setStartBallSpeed();
        startTheRound();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::koniecButtonClick(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------

