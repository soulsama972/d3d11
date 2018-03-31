#pragma once

#include"res.h"
#include"shader.h"


class DrawObject 
{
protected:

	struct D
	{
		ID3D11Buffer* bufferVs;
		ID3D11Buffer* bufferPs;
		D3D_PRIMITIVE_TOPOLOGY type;
		UINT byteWidth;
		UINT strideSize;
	};

public:
	virtual void draw()=0;
	virtual void move(float x,float y) = 0;
	// inrnatte to another object
protected:

	//void createShape(float x, float y, float w, float h, D3DXCOLOR color,D &d);
	void createVertexBuffer(UINT byteWidth, const LPVOID src, size_t size, D & d);
	void createIndexBuffer(UINT byteWidth, const LPVOID src, D &d);
	float calX(float x);
	float calY(float y);
private:
	void map(ID3D11Buffer * buf, UINT byteWidth, const LPVOID src);


};

