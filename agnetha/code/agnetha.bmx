Import pub.win32 

Global ezLib=LoadLibraryA("bin\agnetha")
Global ezRegisterGraphics(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterGraphics")
Global ezRegisterCls(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterCls")

Global ezRegisterFlip(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterFlip")
Global ezRegisterKeyHit(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterKeyHit")
Global ezRegisterKeyDown(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterKeyDown")

Global ezRegisterMouseX(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterMouseX")
Global ezRegisterMouseY(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterMouseY")

Global ezRegisterDrawLine(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterDrawLine")
Global ezRegisterDrawRect(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterDrawRect")
Global ezRegisterDrawText(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterDrawText")

Global ezRegisterLoadImage(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterLoadImage")
Global ezRegisterDrawImage(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterDrawImage")
Global ezRegisterImageWidth(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterImageWidth")
Global ezRegisterImageHeight(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterImageHeight")

Global ezRegisterSetScale(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetScale")
Global ezRegisterSetMaskColor(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetMaskColor")
Global ezRegisterSetAlpha(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetAlpha")
Global ezRegisterSetBlend(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetBlend")
Global ezRegisterSetRotation(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetRotation")
Global ezRegisterSetOrigin(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetOrigin")
Global ezRegisterSetHandle(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetHandle")
Global ezRegisterSetImageHandle(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetImageHandle")

Global ezRegisterSetColor(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetColor")
Global ezRegisterSetClsColor(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterSetClsColor")

' Joystick
Global ezRegisterJoyCount(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterJoyCount")
Global ezRegisterJoyX(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterJoyX")
Global ezRegisterJoyY(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterJoyY")
Global ezRegisterJoyDown(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterJoyDown")
Global ezRegisterJoyHit(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterJoyHit")

' File Streams
Global ezRegisterWriteStream(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterWriteStream")
Global ezRegisterReadStream(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterReadStream")
Global ezRegisterCloseStream(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterCloseStream")
Global ezRegisterWriteInt(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterWriteInt")
Global ezRegisterReadInt(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterReadInt")
Global ezRegisterWriteString(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterWriteString")
Global ezRegisterReadString(fp:Byte Ptr)=getprocaddress(ezLib,"ezRegisterReadString")


Global ezRunApp()=getprocaddress(ezLib,"ezRunApp")

ezRegisterGraphics(ezGraphics)
ezRegisterCls(Cls)
ezRegisterFlip(Flip)
ezRegisterKeyHit(KeyHit)
ezRegisterKeyDown(KeyDown)

'Mouse
ezRegisterMouseX(MouseX)
ezRegisterMouseY(MouseY)

'Draw
ezRegisterDrawLine(DrawLine)
ezRegisterDrawRect(DrawRect)
ezRegisterDrawText(ezDrawText)

ezRegisterLoadImage(ezLoadImage)
ezRegisterDrawImage(ezDrawImage)
ezRegisterImageWidth(ezImageWidth)
ezRegisterImageHeight(ezImageHeight)

ezRegisterSetScale(SetScale)
ezRegisterSetMaskColor(SetMaskColor)
ezRegisterSetAlpha(SetAlpha)
ezRegisterSetBlend(SetBlend)
ezRegisterSetRotation(SetRotation)
ezRegisterSetOrigin(SetOrigin)
ezRegisterSetHandle(SetHandle)
ezRegisterSetImageHandle(ezSetImageHandle)

ezRegisterSetColor(SetColor)
ezRegisterSetClsColor(SetClsColor)

'Joystick
ezRegisterJoyCount(JoyCount)
ezRegisterJoyX(JoyX)
ezRegisterJoyY(JoyY)
ezRegisterJoyDown(JoyDown)
ezRegisterJoyHit(JoyHit)

'File Stream
ezRegisterWriteStream(ezWriteStream)
ezRegisterReadStream(ezReadStream)
ezRegisterCloseStream(ezCloseStream)
ezRegisterWriteInt(ezWriteInt)
ezRegisterReadInt(ezReadInt)
ezRegisterWriteString(ezWriteString)
ezRegisterReadString(ezReadString)


Function ezGraphics( a:Int, b:Int )
	Graphics a, b
End Function

Function ezDrawText(a:Byte Ptr, b:Float, c:Float)
	DrawText String.FromCString(a), b, c
End Function

Function ezLoadImage:Int(a:Byte Ptr)
	Local ret:Int = LoadImage(String.FromCString(a))
	Return ret 
End Function

Function ezDrawImage(a:Int, b:Float, c:Float)
	DrawImage (a,b,c)
End Function

Function ezSetImageHandle(a:Int, b:Float, c:Float)
	SetImageHandle (a,b,c)
End Function

Function ezImageWidth:Int(a:Int)
	Return ImageWidth(a)
End Function

Function ezImageHeight:Int(a:Int)
	Return ImageHeight(a)
End Function

Function ezWriteStream:Int(a:Byte Ptr)
	Local ret:Int = WriteStream(String.FromCString(a))
	Return ret 
End Function

Function ezReadStream:Int(a:Byte Ptr)
	Local ret:Int = ReadStream(String.FromCString(a))
	Return ret 
End Function

Function ezCloseStream(a:Int)
	CloseStream(a)
End Function

Function ezWriteInt(a:Int, b:Int)
	WriteInt(a, b)
End Function

Function ezReadInt:Int(a:Int)
	Return ReadInt(a)
End Function

Function ezWriteString(a:Int, b:Byte Ptr)
	WriteString(a, String.FromCString(b))
End Function

Function ezReadString:Byte Ptr(a:Int, b:Int)
	Local str:Byte Ptr
	Local flappa:String = ReadString(a,b)
	str = flappa.ToCString();
	Return str
End Function

'Graphics 640, 480
ezRunApp

' Run the game/app
'While Not KeyHit(27) 
   'Cls
   'Font_Head1 = LoadImageFont("Graphics\CENTURY.TTF", 42)', BOLDFONT + SMOOTHFONT )
   'SetImageFont( Font_Head1 )
   'DrawText("gaa", 50,50)

    
   'Flip
'Wend
End
