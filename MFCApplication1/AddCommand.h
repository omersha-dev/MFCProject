#pragma once

#include "Command.h"
#include "MyShape.h"
#include <vector>

using namespace std;

class AddCommand : public Command {
public:
	AddCommand(vector<MyShape*> &shapes, MyShape *shape)
		: shapes(shapes), shape(shape) {}

	void perform() {
		shapes.push_back(shape);
		shape->setDelete(0);//**
	}

	void rollback() {
		vector<MyShape*>::iterator it;
		for (it = shapes.begin(); it != shapes.end(); ++it)
			if (*it == shape)
				break;
		if (it != shapes.end()) {
			(*it)->setDelete(1); //**
			shapes.erase(it);
		}

	}
	int getIsDelete() { return shape->getIsDelete(); } //**

private:
	vector<MyShape*> &shapes;
	MyShape *shape;
};