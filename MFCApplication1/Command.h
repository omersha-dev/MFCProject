#pragma once

class Command {
public:
	virtual void perform() = 0;
	virtual void rollback() = 0;
	virtual int  getIsDelete() = 0; //**
};