#pragma once
#include "DrawObject.h"
#include"shader.h"
class Squre : public DrawObject
{
public:
	Squre(float x, float y, D3DXCOLOR Color, float size);
	void rotate(float d);
	Squre();
	~Squre();
	void draw() override;
	void move(float x, float y) override;
	void createSqure(float x, float y, D3DXCOLOR Color, float size);
private:
	struct squre {
		FLOAT x, y, w, h;
		D3DXCOLOR color;
	};
	struct Data {
		unsigned short size;
		unsigned short scale;
		float x;
		float y;
	}data;
	//fun
	void initVertex(float x, float y, D3DXCOLOR Color, float size);
	void setPos(float x, float y);
	void setIndex();

	//var
	unsigned int *SqureIndex;
	shader * sSqure;
	squre * sVertex;
	D d;
	bool init;


};

