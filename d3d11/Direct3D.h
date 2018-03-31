#pragma once
#include"res.h"
#include"DrawObject.h"


class Direct3D 
{
public:
	bool init(HINSTANCE hInstance, int nCmdShow);
	void InitD3D();
	virtual void RenderFrame(void);
	void draw(DrawObject& obj);
	void move(DrawObject& obj,float x,float y);
	virtual void update(void);

	~Direct3D();
	Direct3D();
protected:
	IDXGISwapChain * swapchain;             // the pointer to the swap chain interface
	ID3D11RenderTargetView *backbuffer;    // the pointer to our back buffer
private:
	HWND hWnd;
};





LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);