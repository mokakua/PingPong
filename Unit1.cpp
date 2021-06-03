//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner), MAX_BALL_SPEED(25), MIN_BALL_SPEED(8), PADDLE_SPEED(8),
        PADDLE_TO_BORDER_DISTANCE(80), MAX_SPEED_RATIO(2)
{
        leftPaddleSpeed = PADDLE_SPEED;
        rightPaddleSpeed = PADDLE_SPEED;
        leftPoints = 0;
        rightPoints = 0;
        gameStarted = false;
        ballSpeed = MIN_BALL_SPEED;
        ballHits = 0;

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
        paddleLeft->Left = PADDLE_TO_BORDER_DISTANCE;
        paddleLeft->Top = gameArea->Height/2-paddleLeft->Height/2;
        paddleRight->Left = gameArea->Width-paddleRight->Width-PADDLE_TO_BORDER_DISTANCE;
        paddleRight->Top = gameArea->Height/2-paddleRight->Height/2;

        lPointsLabel->Left = PADDLE_TO_BORDER_DISTANCE + 100;
        lPointsLabel->Top = gameArea->Height/2 - lPointsLabel->Height/2;
        rPointsLabel->Left = gameArea->Width - PADDLE_TO_BORDER_DISTANCE - 100 - rPointsLabel->Width;
        rPointsLabel->Top = gameArea->Height/2 - rPointsLabel->Height/2;

        startButton->Top =  gameArea->Height/2 - startButton->Height/2;
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

        sRatio->Caption = speedRatio;
        xLabel->Caption = xSpeed;
        yLabel->Caption = ySpeed;
}
//---------------------------------------------------------------------------
float TForm1::calcBallSpeedRatio(TShape* paddle){
        float speedRatio = 0;

        float paddleLengthRatio = (ball->Top+ball->Height/2.0 - paddle->Top)/paddle->Height;

        speedRatio = 2*MAX_SPEED_RATIO*paddleLengthRatio - MAX_SPEED_RATIO;

        lLabel->Caption = paddleLengthRatio;

        return speedRatio;

}
//---------------------------------------------------------------------------
void TForm1::setStartBallSpeed(){

        randomize();
        float startSpeedRatio = (rand()%(MAX_SPEED_RATIO*20+1)-MAX_SPEED_RATIO*10)/10.0;
        xSpeed = rand()%2;
        ballSpeed = MIN_BALL_SPEED;
        setBallSpeed(startSpeedRatio);

}
//---------------------------------------------------------------------------
bool TForm1::doesHitPaddle(TShape* paddle){

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
bool TForm1::doesHitWall(){
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
        timersOff();
        ball->Visible = false;
        setPoints();
        gameStarted = false;
        dalejButton->Enabled = true;
        dalejButton->Visible = true;
        koniecButton->Enabled = true;
        koniecButton->Visible = true;

        /*
        if (Application->MessageBox("Czy chcesz kontynuowac?", "Nastepna runda?", MB_YESNO) == IDYES){
                FormCreate(Application);
        }else{
                Application->Terminate();
        }
        */
}
//---------------------------------------------------------------------------
void TForm1::timersOff(){
        ballTimer->Enabled = false;
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
void TForm1::startTheBall(){
        countdownLabel->Visible = true;
        for(int countdown = 3; countdown >0; countdown--){
                countdownLabel->Caption = countdown;
                Application->ProcessMessages();
                Sleep(700);
        }
        ball->Visible = true;
        ballTimer->Enabled = true;
        countdownLabel->Visible = false;

        ballHits = 0;
        ballSpeed = MIN_BALL_SPEED;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{
        ball->Left += xSpeed;
        ball->Top += ySpeed;

        if (doesHitWall()){
                ySpeed *= -1;
        }

        if (isFail()){
                pauseGameAfterFail();

        }else if(xSpeed >0 && doesHitPaddle(paddleRight)){
                ballHits++;
                if(ballHits%1==0 && ballHits>0 && ballSpeed<MAX_BALL_SPEED){
                        ballSpeed++;
                }
                setBallSpeed(calcBallSpeedRatio(paddleRight));


        }else if (xSpeed <0 && doesHitPaddle(paddleLeft)){
                ballHits++;
                if(ballHits%1==0 && ballHits>0 && ballSpeed<MAX_BALL_SPEED){
                        ballSpeed++;
                }
                setBallSpeed(calcBallSpeedRatio(paddleLeft));
        }

        hitsLabel->Caption = ballHits;
        BSpeedLabel->Caption = ballSpeed;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::paddleRightUpTimerTimer(TObject *Sender)
{
        if (paddleRight->Top >= 5){
                paddleRight->Top -= rightPaddleSpeed;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddleRightDownTimerTimer(TObject *Sender)
{
        if (paddleRight->Top + paddleRight->Height <= gameArea->Height - 5){
                paddleRight->Top += rightPaddleSpeed;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleLeftUpTimerTimer(TObject *Sender)
{
        if (paddleLeft->Top >= 5){
                paddleLeft->Top -= leftPaddleSpeed;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddleLeftDownTimerTimer(TObject *Sender)
{
        if (paddleLeft->Top + paddleLeft->Height <= gameArea->Height - 5){
                paddleLeft->Top += leftPaddleSpeed;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP){
                paddleRightUpTimer->Enabled = true;

        }
        if (Key == VK_DOWN){
                paddleRightDownTimer->Enabled = true;
        }
        if (Key == 0x41){
                paddleLeftUpTimer->Enabled = true;

        }
        if (Key == 0x5A){
                paddleLeftDownTimer->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP){
                paddleRightUpTimer->Enabled = false;
                xLabel->Caption = xSpeed;
        }
        if (Key == VK_DOWN){
                paddleRightDownTimer->Enabled = false;
        }
        if (Key == 0x41){
                paddleLeftUpTimer->Enabled = false;
                xLabel->Caption = xSpeed;
        }
        if (Key == 0x5A){
                paddleLeftDownTimer->Enabled = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::startButtonClick(TObject *Sender)
{
        startButton->Enabled = false;
        startButton->Visible = false;
        startTheBall();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::dalejButtonClick(TObject *Sender)
{
        FormCreate(Application);
        setStartBallSpeed();
        startTheBall();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::koniecButtonClick(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

