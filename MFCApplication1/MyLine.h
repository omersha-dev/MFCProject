#pragma once
#include "MyShape.h"

class MyLine : public MyShape {
	DECLARE_SERIAL(MyLine) // Step 3 on msdn
	void drawShape(CPaintDC &dc);
};