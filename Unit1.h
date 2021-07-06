//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "PerkManager.h"
#include "PaddleData.h"
#include <math.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *mainTimer;
        TShape *gameArea;
        TShape *ball;
        TShape *paddleLeftShape;
        TShape *paddleRightShape;
        TTimer *paddleLeftUpTimer;
        TTimer *paddleLeftDownTimer;
        TTimer *paddleRightUpTimer;
        TTimer *paddleRightDownTimer;
        TLabel *lPointsLabel;
        TLabel *rPointsLabel;
        TButton *startButton;
        TButton *dalejButton;
        TButton *koniecButton;
        TLabel *countdownLabel;
        TLabel *Label4;
        TLabel *hitsLabel;
        TShape *perkShape;
        TShape *Shape1;
        TLabel *Label5;
        TLabel *BSpeedLabel;
        TTimer *perkTimer;
        TLabel *perkTimeLabel;
        TTimer *cannonTimer;
        void __fastcall mainTimerTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall paddleRightUpTimerTimer(TObject *Sender);
        void __fastcall paddleRightDownTimerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall paddleLeftUpTimerTimer(TObject *Sender);
        void __fastcall paddleLeftDownTimerTimer(TObject *Sender);
        void __fastcall startButtonClick(TObject *Sender);
        void __fastcall dalejButtonClick(TObject *Sender);
        void __fastcall koniecButtonClick(TObject *Sender);
        void __fastcall perkTimerTimer(TObject *Sender);
        void __fastcall cannonTimerTimer(TObject *Sender);
private:	// User declarations

        const int MIN_BALL_SPEED;
        const int MAX_BALL_SPEED;
        const int PADDLE_LENGTH;
        int ballSpeed;
        const int PADDLE_SPEED;
        int leftPaddleSpeed;
        int rightPaddleSpeed;
        int leftPoints, rightPoints;
        int ballHits;
        const int PADDLE_TO_BORDER_DISTANCE;
        float speedRatio; //ySpeed/xSpeed
        const int MAX_SPEED_RATIO;
        float xSpeed;
        float ySpeed;
        int perkTime;
        int cannonBallTime;
        const int PERK_DURATION;
        int keyRightUp;
        int keyRightDown;
        int keyLeftUp;
        int keyLeftDown;
        bool isCannonBallOn;
        int hitsToSpeedIncrease;
        PerkManager perkManager;
        PaddleData *paddleLeftData;
        PaddleData *paddleRightData;

        void swap (int& a, int& b);
        void setBallSpeed(float speedRatio);
        float calcBallSpeedRatio(TShape* paddle);
        bool doesBallHitPaddle(TShape* paddle);
        bool doesBallHitWall();
        bool doesBallHitPerkShape();
        bool isFail();
        void pauseGameAfterFail();
        void timersOff();
        void setPoints();
        void setStartBallSpeed();
        void prepareIconsLayout();
        void startTheRound();
        void perkTurnOn();
        void perk1DrunkMode();
        void perk2CannonBall();
        void perk3Elongation();
        void finishPerks();
        void perkHitAction();
        void paddleHitAction();

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
