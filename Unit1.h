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
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *mainTimer;
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
        TLabel *hitsLabel1;
        TLabel *hitsLabel;
        TShape *perkShape;
        TLabel *BSpeedLabel1;
        TLabel *BSpeedLabel;
        TTimer *perkTimer;
        TLabel *perkTimeLabel;
        TTimer *cannonTimer;
        TShape *Shape1;
        TShape *gameArea;
        TShape *perkShape1;
        TLabel *perk1Description;
        TLabel *perk2Description;
        TShape *perkShape2;
        TShape *perkShape3;
        TLabel *perk3Description;
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
        void __fastcall perkTimerTimer(TObject *Sender);
        void __fastcall cannonTimerTimer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall koniecButtonClick(TObject *Sender);
private:	// User declarations

        const int MIN_BALL_SPEED;
        const int MAX_BALL_SPEED;
        int ballSpeed;
        //int leftPaddleSpeed;
        //int rightPaddleSpeed;
        int leftPoints, rightPoints;
        int ballHits;
        const int PADDLE_TO_BORDER_DISTANCE;
        float speedRatio; //ySpeed/xSpeed
        const int MAX_SPEED_RATIO;
        float xSpeed;
        float ySpeed;
        //int perkTime;
        int cannonBallTime;
        const int PERK_DURATION;
        //bool isCannonBallOn;
        int hitsToSpeedIncrease;
        PerkManager perkManager;
        PaddleData *paddleLeftData;
        PaddleData *paddleRightData;

        //void swap (int& a, int& b);
        void setBallSpeed(float speedRatio);
        float calcBallSpeedRatio(TShape* paddle);
        bool doesBallHitPaddle(TShape* paddle);
        bool doesBallHitWall();
        bool isFail();
        void pauseGameAfterFail();
        void timersOff();
        void setPoints();
        void setStartBallSpeed();
        void prepareIconsLayout();
        void startTheRound();
        //void perk1DrunkMode();
        void perk2CannonBall();
        //void perk3Elongation();
        void finishPerks();
        void perkHitAction();
        void paddleHitAction();
        void showPerksDescription();

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        static const int PADDLE_SPEED = 10;
        static const int PADDLE_LENGTH = 150;
        static const int KEY_RIGHT_UP = VK_UP;//keyRightUp;
        static const int KEY_RIGHT_DOWN = VK_DOWN;//keyRightDown;
        static const int KEY_LEFT_UP = 0x41;//keyLeftUp;
        static const int KEY_LEFT_DOWN = 0x5A;//keyLeftDown;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
