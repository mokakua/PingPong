//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *ballTimer;
        TShape *gameArea;
        TShape *ball;
        TShape *paddleLeft;
        TShape *paddleRight;
        TTimer *paddleLeftUpTimer;
        TTimer *paddleLeftDownTimer;
        TTimer *paddleRightUpTimer;
        TTimer *paddleRightDownTimer;
        TLabel *lPointsLabel;
        TLabel *rPointsLabel;
        TLabel *SpeedRatio;
        TLabel *lLabel;
        TLabel *Label3;
        TLabel *Label2;
        TLabel *Label1;
        TLabel *yLabel;
        TLabel *xLabel;
        TLabel *sRatio;
        TButton *startButton;
        TButton *dalejButton;
        TButton *koniecButton;
        TLabel *countdownLabel;
        TLabel *Label4;
        TLabel *hitsLabel;
        TShape *Shape2;
        void __fastcall ballTimerTimer(TObject *Sender);
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
private:	// User declarations

        const int MIN_BALL_SPEED;
        const int MAX_BALL_SPEED;
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
        bool gameStarted;

        void setBallSpeed(float speedRatio);
        float calcBallSpeedRatio(TShape* paddle);
        bool doesHitPaddle(TShape* paddle);
        bool doesHitWall();
        bool isFail();
        void pauseGameAfterFail();
        void timersOff();
        void setPoints();
        void setStartBallSpeed();
        void prepareIconsLayout();
        void startTheBall();

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
