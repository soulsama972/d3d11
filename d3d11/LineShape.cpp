#include "LineShape.h"

extern  ID3D11Device *dev;                     // the pointer to our Direct3D device interface
extern ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context


LineShape::LineShape()
{
	this->init = false;
	this->sLine = new shader;
	this->line = new Line[2];
	this->LineIndex = new unsigned int[2];
	this->setIndex();
	this->sLine->CreateLineElement("Line");


	d.byteWidth = 2;
	d.strideSize = sizeof(Line);
	d.type = D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
}

LineShape::LineShape(float x, float y, float x2, float y2, D3DXCOLOR color)
{
	this->init = true;
	this->sLine = new shader;
	this->line = new Line[2];
	this->LineIndex = new unsigned int[2];
	this->setIndex();

	this->sLine->CreateLineElement("Line");
	this->setLine(x, y, x2, y2, color);
	this->fillData(x, y, x2, y2, color);
	createVertexBuffer(sizeof(Line)*2, line, 2, d);
	createIndexBuffer(sizeof(unsigned int)*2, LineIndex, d);


	this->d.byteWidth = 2;
	this->d.strideSize = sizeof(Line);
	this->d.type = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP;
}

void LineShape::CreateLine(float x, float y, float x2, float y2, D3DXCOLOR color)
{
	if (!this->init) {
		this->setLine(x, y, x2, y2, color);
		this->fillData(x, y, x2, y2, color);
		createVertexBuffer(sizeof(Line) * 2, line, 2, d);
		createIndexBuffer(sizeof(unsigned int) * 2, LineIndex, d);
		this->init = true;
	}
}

void LineShape::draw()
{
	UINT stride = this->d.strideSize;
	UINT offset = 0;
	devcon->IASetVertexBuffers(0, 1, &this->d.bufferVs, &stride, &offset);
	devcon->IASetIndexBuffer(d.bufferPs, DXGI_FORMAT_R32_UINT, 0);
	devcon->IASetPrimitiveTopology(this->d.type);//D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP
	devcon->VSSetShader(sLine->pVS, 0, 0);
	devcon->PSSetShader(sLine->pPS, 0, 0);
	devcon->IASetInputLayout(sLine->pLayout);
	devcon->DrawIndexed(this->d.byteWidth, 0, 0);
}

void LineShape::move(float x, float y)
{
	this->line[1].y = calY(y);
	this->line[1].x = calX(x);
	this->d.bufferVs->Release();
	createVertexBuffer(sizeof(Line) * 2, line, 2, d);
}

void LineShape::move(float x, float y, float x2, float y2)
{
	this->setLine(x, y, x2, y2, this->data.color);
	this->fillData(x, y, x2, y2, this->data.color);
	this->d.bufferVs->Release();
	createVertexBuffer(sizeof(Line) * 2, line, 2, d);
}


LineShape::~LineShape()
{
	delete this->LineIndex;
	delete this->sLine;
	delete this->line;
}

void LineShape::setLine(float x, float y, float x2, float y2, D3DXCOLOR color)
{
	this->line[0].x = calX(x);
	this->line[0].y = calY(y);
	this->line[0].color = color;
	this->line[1].x = calX(x2);
	this->line[1].y = calY(y2);
	this->line[1].color = color;
}


void LineShape::setIndex()
{
	this->LineIndex[0] = 0;
	this->LineIndex[1] = 1;
}

void LineShape::fillData(float x, float y, float x2, float y2, D3DXCOLOR color)
{
	this->data.x = x;
	this->data.x2 = x2;

	this->data.y = y;
	this->data.y2 = y2;

	this->data.color = color;

}
