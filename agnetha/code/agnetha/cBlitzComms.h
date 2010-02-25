#include <string.h>

#define EZSHARE_API __declspec(dllexport)

// Run App
extern "C"{EZSHARE_API void _cdecl ezRunApp(void);}

// Register prototypes
extern "C"{EZSHARE_API void _cdecl ezRegisterGraphics(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterCls(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterFlip(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterKeyHit(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterKeyDown(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterMouseX(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterMouseY(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterDrawLine(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterDrawRect(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterDrawText(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterLoadImage(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterDrawImage(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterImageWidth(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterImageHeight(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetScale(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetMaskColor(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetAlpha(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetRotation(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetOrigin(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetHandle(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetImageHandle(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetColor(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterSetClsColor(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterJoyCount(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterJoyX(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterJoyY(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterJoyDown(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterJoyHit(int* func);}

extern "C"{EZSHARE_API void _cdecl ezRegisterWriteStream(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterReadStream(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterCloseStream(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterWriteInt(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterReadInt(int* func);}

extern "C"{EZSHARE_API void _cdecl ezRegisterWriteString(int* func);}
extern "C"{EZSHARE_API void _cdecl ezRegisterReadString(int* func);}

extern "C"{EZSHARE_API void _cdecl ezRegisterSetBlend(int* func);}
#define SOLIDBLEND 1
#define MASKBLEND 2
#define ALPHABLEND 3
#define LIGHTBLEND 4
#define SHADEBLEND 5

// Use these to directly call Blitz functions
// These are function pointer 'var'iables
int (*varGraphics)(int, int);
void (*varCls)();
void (*varFlip)();
int (*varKeyHit)(int);
int (*varKeyDown)(int);
int (*varMouseX)();
int (*varMouseY)();
void (*varDrawLine)(float, float, float, float);
void (*varDrawRect)(float, float, float, float);
void (*varDrawText)(char*, float, float);
int (*varLoadImage)(char*);
void (*varDrawImage)(int, float, float);
int (*varImageWidth)(int);
int (*varImageHeight)(int);
void (*varSetScale)(float, float);
void (*varSetMaskColor)(int, int, int);
void (*varSetAlpha)(float);
void (*varSetBlend)(int);
void (*varSetRotation)(float);
void (*varSetOrigin)(float,float);
void (*varSetHandle)(float,float);
void (*varSetImageHandle)(int,float,float);
void (*varSetColor)(int, int, int);
void (*varSetClsColor)(int, int, int);
int (*varJoyCount)();
float (*varJoyX)(int);
float (*varJoyY)(int);
int (*varJoyDown)(int, int);
int (*varJoyHit)(int, int);

int (*varWriteStream)(char*);
int (*varReadStream)(char*);
void (*varCloseStream)(int);
void (*varWriteInt)(int, int);
int (*varReadInt)(int);

void (*varWriteString)(int, char*);
char* (*varReadString)(int, int);

// For now use this wrapper so other classes can directly call Blitz functions
int ezGraphics(int a, int b){return varGraphics(a,b);}
void ezCls(){varCls();}
void ezFlip(){varFlip();}
int ezKeyHit(int a){return varKeyHit(a);}
int ezKeyDown(int a){return varKeyDown(a);}
int ezMouseX(){return varMouseX();}
int ezMouseY(){return varMouseY();}
void ezDrawLine(float a, float b, float c, float d){varDrawLine(a,b,c,d);}
void ezDrawRect(float a, float b, float c, float d){varDrawRect(a,b,c,d);}
void ezDrawText(char* a, float b, float c){varDrawText(a,b,c);}
int ezLoadImage(char* a){return varLoadImage(a);}
void ezDrawImage(int a, float b, float c){varDrawImage(a,b,c);}
int ezImageWidth(int a){return varImageWidth(a);}
int ezImageHeight(int a){return varImageHeight(a);}
void ezSetScale(float a, float b){varSetScale(a,b);}
void ezSetMaskColor(int a, int b, int c){varSetMaskColor(a,b,c);}
void ezSetAlpha(float a){varSetAlpha(a);}
void ezSetBlend(int a){varSetBlend(a);}
void ezSetRotation(float a){varSetRotation(a);}
void ezSetOrigin(float a, float b){varSetOrigin(a,b);}
void ezSetHandle(float a, float b){varSetHandle(a,b);}
void ezSetImageHandle(int a, float b, float c){varSetImageHandle(a,b,c);}
void ezSetColor(int a, int b, int c){varSetColor(a,b,c);}
void ezSetClsColor(int a, int b, int c){varSetClsColor(a,b,c);}
int ezJoyCount(){return varJoyCount();}
float ezJoyX(int a){return varJoyX(a);}
float ezJoyY(int a){return varJoyY(a);}
int ezJoyDown(int a, int b){return varJoyDown(a,b);}
int ezJoyHit(int a, int b){return varJoyHit(a,b);}

int ezWriteStream(char* a){return varWriteStream(a);}
int ezReadStream(char* a){return varReadStream(a);}
void ezCloseStream(int a){return varCloseStream(a);}
void ezWriteInt(int a, int b){varWriteInt(a,b);}
int ezReadInt(int a){return varReadInt(a);}

// For some reason blitz needs to know the length of the string before it reads it, so have to save the length first.
void ezWriteString(int stream, char* b)
{
   varWriteInt(stream, static_cast<int>(strlen(b)));
   varWriteString(stream,b);
}

char* ezReadString(int stream)
{
   return varReadString(stream, varReadInt(stream));
}



// Blitz uses these to register its functions
void ezRegisterGraphics(int* func){varGraphics = (int (*) (int, int)) func;}
void ezRegisterKeyHit(int* func){varKeyHit = (int (*) (int)) func;}
void ezRegisterKeyDown(int* func){varKeyDown = (int (*) (int)) func;}
void ezRegisterMouseX(int* func){varMouseX = (int (*) ()) func;}
void ezRegisterMouseY(int* func){varMouseY = (int (*) ()) func;}
void ezRegisterCls(int* func){varCls = (void (*) ()) func;}
void ezRegisterFlip(int* func){varFlip = (void (*) ()) func;}
void ezRegisterDrawLine(int* func){varDrawLine = (void (*) (float,float,float,float)) func;}
void ezRegisterDrawRect(int* func){varDrawRect = (void (*) (float,float,float,float)) func;}
void ezRegisterDrawText(int* func){varDrawText = (void (*) (char*,float,float)) func;}
void ezRegisterLoadImage(int* func){varLoadImage = (int (*) (char*)) func;}
void ezRegisterDrawImage(int* func){varDrawImage = (void (*) (int,float,float)) func;}
void ezRegisterImageWidth(int* func){varImageWidth = (int (*) (int)) func;}
void ezRegisterImageHeight(int* func){varImageHeight = (int (*) (int)) func;}
void ezRegisterSetScale(int* func){varSetScale = (void (*) (float,float)) func;}
void ezRegisterSetMaskColor(int* func){varSetMaskColor = (void (*) (int,int,int)) func;}
void ezRegisterSetAlpha(int* func){varSetAlpha = (void (*) (float)) func;}
void ezRegisterSetBlend(int* func){varSetBlend = (void (*) (int)) func;}
void ezRegisterSetRotation(int* func){varSetRotation = (void (*) (float)) func;}
void ezRegisterSetOrigin(int* func){varSetOrigin = (void (*) (float,float)) func;}
void ezRegisterSetHandle(int* func){varSetHandle = (void (*) (float,float)) func;}
void ezRegisterSetImageHandle(int* func){varSetImageHandle = (void (*) (int,float,float)) func;}
void ezRegisterSetColor(int* func){varSetColor = (void (*) (int,int,int)) func;}
void ezRegisterSetClsColor(int* func){varSetClsColor = (void (*) (int,int,int)) func;}
void ezRegisterJoyCount(int* func){varJoyCount = (int (*) ()) func;}
void ezRegisterJoyX(int* func){varJoyX = (float (*) (int)) func;}
void ezRegisterJoyY(int* func){varJoyY = (float (*) (int)) func;}
void ezRegisterJoyDown(int* func){varJoyDown = (int (*) (int,int)) func;}
void ezRegisterJoyHit(int* func){varJoyHit = (int (*) (int,int)) func;}

void ezRegisterWriteStream(int* func){varWriteStream = (int (*) (char*)) func;}
void ezRegisterReadStream(int* func){varReadStream = (int (*) (char*)) func;}
void ezRegisterCloseStream(int* func){varCloseStream = (void (*) (int)) func;}
void ezRegisterWriteInt(int* func){varWriteInt = (void (*) (int,int)) func;}
void ezRegisterReadInt(int* func){varReadInt = (int (*) (int)) func;}

void ezRegisterWriteString(int* func){varWriteString = (void (*) (int,char*)) func;}
void ezRegisterReadString(int* func){varReadString = (char* (*) (int,int)) func;}