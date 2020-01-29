#pragma once
#include "MyShape.h"

class MyRectangle : public MyShape {
	DECLARE_SERIAL(MyRectangle) // Step 3 on msdn
	void drawShape(CPaintDC &dc);
};