#pragma once

#include "MyShape.h"

class MyEllipse : public MyShape {
	DECLARE_SERIAL(MyEllipse) // Step 3 on msdn
	void drawShape(CPaintDC &dc);
};