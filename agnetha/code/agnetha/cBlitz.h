#ifndef CBLITZ_H
#define CBLITZ_H

typedef int EzStream; // Handle for file streams

#define SOLIDBLEND 1
#define MASKBLEND 2
#define ALPHABLEND 3
#define LIGHTBLEND 4
#define SHADEBLEND 5

int ezGraphics(int, int);
void ezCls();
void ezFlip();
int ezLoadImage(char*);
void ezDrawImage(int, float, float);
int ezKeyHit(int);
int ezKeyDown(int);
int ezMouseX();
int ezMouseY();
void ezDrawLine(float,float,float,float);
void ezDrawRect(float,float,float,float);
void ezDrawText(char*,float,float);
int ezImageWidth(int);
int ezImageHeight(int);

// Memory management
void ezRelease(int);
int ezGCMemAlloced();
int ezGCCollect();

void ezSetScale(float, float);
void ezSetMaskColor(int, int, int);
void ezSetAlpha(float);
void ezSetBlend(int);
void ezSetRotation(float);
void ezSetOrigin(float,float);
void ezSetHandle(float,float);
void ezSetImageHandle(int,float,float);
void ezSetColor(int, int, int);
void ezSetClsColor(int, int, int);

int ezJoyCount();
float ezJoyX(int);
float ezJoyY(int);
int ezJoyDown(int /*button*/, int /*port*/);
int ezJoyHit(int /*button*/, int /*port*/);

EzStream ezWriteStream(char*);
EzStream ezReadStream(char*);
void ezCloseStream(EzStream);
void ezWriteInt(EzStream, int);
int ezReadInt(EzStream);

void ezWriteString(EzStream, char*);
char* ezReadString(EzStream);

#endif //CBLITZ_H