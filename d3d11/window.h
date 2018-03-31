#pragma once
#include<Windows.h>
#include"res.h"


class window
{
public:
	bool init(HINSTANCE hInstance, int nCmdShow);
	HWND GetWindow();
	window();
	virtual ~window();
protected:

private:
	HWND hWnd;

};


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);