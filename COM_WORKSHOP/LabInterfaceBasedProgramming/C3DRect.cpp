#include "stdafx.h"
#include "C3DRect.h"
#include <iostream>




C3DRect::C3DRect()
{
}


C3DRect::~C3DRect()
{
}

void C3DRect::Fill(FILLTYPE fType)
{
	char * FillString[] = { "HATCH", "SOLID", "POLKADOT" };
	std::cout << "Filling the 3d rect as " << FillString[fType] << std::endl;
}

void C3DRect::Draw()
{
	std::cout << "Drawing the rectangle" << std::endl;
}

void C3DRect::Inverse()
{
	std::cout << "Rectangle Is now Inverse" << std::endl;
}

void C3DRect::Stretch(int nFactor)
{
	std::cout << "Rectangle is now stretching by a factor of " <<nFactor << std::endl;
}

C3DRectEx::C3DRectEx()
{
}

C3DRectEx::~C3DRectEx()
{
}

void C3DRectEx::Draw()
{
	std::cout << "Drawing 3dRectEx" << std::endl;
}

void C3DRectEx::DrawToMemory()
{
	std::cout << "Drawing to memory" << std::endl;
}

void C3DRectEx::DrawToMetaFile()
{
	std::cout << "Drawing to metafile" << std::endl;
}

void C3DRectEx::DrawToPrinter()
{
	std::cout << "Drawing to Printer" << std::endl;
}
