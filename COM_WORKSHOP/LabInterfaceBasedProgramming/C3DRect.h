#pragma once
#include"Interfaces.h"

class C3DRect : public IDraw, public IShapeEdit
{
public:
	C3DRect();
	virtual ~C3DRect();
	// IDraw
	virtual void Draw();
	//IShapeEdit
	virtual void Fill(FILLTYPE fType);
	virtual void Inverse();
	virtual void Stretch(int factor);

};


class C3DRectEx : public IDraw3 {
public:
	C3DRectEx();
	virtual ~C3DRectEx();
	//IDraw3
	virtual void Draw();
	virtual void DrawToMemory();
	virtual void DrawToMetaFile();
	virtual void DrawToPrinter();

};

