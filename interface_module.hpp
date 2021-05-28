#pragma once

class InterfaceModule
{
public:
	virtual void init(){
    	printf("\u001b[31mWrong\u001b[0m");}
	virtual void draw(){}
	virtual void quit(){}
};