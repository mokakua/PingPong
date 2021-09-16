#include "PaddleData.h"

PaddleData::PaddleData(TShape *paddleShape, int paddleSpeed, int keyUp, int keyDown):
paddleShape(paddleShape), paddleSpeed(paddleSpeed), keyUp(keyUp), keyDown(keyDown)
{}
//---------------------------------------------------------------------------
TShape* PaddleData::getPaddleShape(){
return this->paddleShape;
}
//---------------------------------------------------------------------------
int PaddleData::getPaddleSpeed(){
return this->paddleSpeed;
}
//---------------------------------------------------------------------------
int PaddleData::getKeyUp(){
return this->keyUp;
}
//---------------------------------------------------------------------------
int PaddleData::getKeyDown(){
return this->keyDown;
}
//---------------------------------------------------------------------------
void PaddleData::setPaddleSpeed(int paddleSpeed){
this->paddleSpeed = paddleSpeed;
}
//---------------------------------------------------------------------------
void PaddleData::setKeyUp(int keyUp){
this->keyUp = keyUp;
}
//---------------------------------------------------------------------------
void PaddleData::setKeyDown(int keyDown){
this->keyDown = keyDown;
}
//---------------------------------------------------------------------------
void PaddleData::swapKeys(){
        int tempValue = keyUp;
        keyUp = keyDown;
        keyDown = tempValue;
}
//---------------------------------------------------------------------------
