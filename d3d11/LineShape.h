#pragma once
#include"DrawObject.h"
#include"shader.h" 


class LineShape : public DrawObject
{
public:
	LineShape();
	LineShape(float x, float y, float x2, float y2, D3DXCOLOR color);
	void CreateLine(float x, float y, float x2, float y2, D3DXCOLOR color);
	void draw() override;
	void move(float x, float y) override;
	void move(float x, float y, float x2, float y2);
	~LineShape();
private:
	struct Data {
		float x;
		float y;
		float x2;
		float y2;
		D3DXCOLOR color;
	}data;
	struct Line {
		FLOAT x, y;
		D3DXCOLOR color;
	};
	void setLine(float x,float y,float x2,float y2,D3DXCOLOR color);
	void setIndex();
	void fillData(float x, float y, float x2, float y2, D3DXCOLOR color);
	shader * sLine;
	D d;
	Line *line;
	bool init;
	unsigned int *LineIndex;
};

