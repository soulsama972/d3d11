#include "Squre.h"


extern  ID3D11Device *dev;                     // the pointer to our Direct3D device interface
extern ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context
#define  VERTEXINDEX 3
Squre::Squre(float x, float y, D3DXCOLOR Color, float size)
{
	this->init = true;
	this->sSqure = new shader;
	this->sVertex = new squre[4];
	this->setIndex();

	this->sSqure->CreateSqureElement("Squre");
	this->initVertex(x, y, Color, size);
	createVertexBuffer(sizeof(Squre)*4, this->sVertex, 4, d);
	createIndexBuffer(sizeof(unsigned int)*VERTEXINDEX, SqureIndex, d);

	this->d.byteWidth = 6;
	this->d.strideSize = sizeof(squre);
	this->d.type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

}

void Squre::rotate(float dd)
{
	this->sVertex[2].y += calY(dd);
	this->sVertex[3].y -= calY(dd);
	this->d.bufferVs->Release();
	createVertexBuffer(sizeof(Squre) * 4, this->sVertex, 4, d);
}

Squre::Squre()
{
	this->init = false;
	this->sSqure = new shader;
	this->sVertex = new squre[4];
	this->setIndex();

	this->sSqure->CreateSqureElement("Squre");
	this->d.byteWidth = 6;
	this->d.strideSize = sizeof(squre);
	this->d.type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}


Squre::~Squre()
{
	delete this->sVertex;
	delete this->sSqure;
	delete this->SqureIndex;
}


void Squre::draw()
{
	UINT stride = d.strideSize;
	UINT offset = 0;

	devcon->IASetVertexBuffers(0, 1, &d.bufferVs, &stride, &offset);
	devcon->IASetIndexBuffer(d.bufferPs, DXGI_FORMAT_R32_UINT, 0);
	devcon->IASetPrimitiveTopology(d.type);//D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP
	devcon->VSSetShader(sSqure->pVS, 0, 0);
	devcon->PSSetShader(sSqure->pPS, 0, 0);
	devcon->IASetInputLayout(sSqure->pLayout);
	devcon->DrawIndexed(d.byteWidth, 0, 0);
}

void Squre::move(float x, float y)
{
	this->setPos(x, y);
	this->d.bufferVs->Release();
	createVertexBuffer(sizeof(Squre) * 4, this->sVertex, 4, d);
}

void Squre::createSqure(float x, float y, D3DXCOLOR Color, float size)
{
	if (!this->init) {
		this->initVertex(x, y, Color, size);
		createVertexBuffer(sizeof(Squre) * 4, this->sVertex, 4, d);
		createIndexBuffer(sizeof(unsigned int) *VERTEXINDEX, SqureIndex, d);
	}
}

void Squre::initVertex(float x, float y, D3DXCOLOR Color, float size)
{
	for (int i = 0; i < 4; i++) {
		this->sVertex[i].color = Color;
		this->sVertex[i].w = 0.0f;
		this->sVertex[i].h = 1.0f;
	}
	this->data.size = size;
	this->setPos(x, y);

}

void Squre::setPos(float x, float y)
{
	this->sVertex[0].x = calX(x);
	this->sVertex[0].y = calY(y);

	this->sVertex[1].x = calX(x);
	this->sVertex[1].y = calY(y + data.size);

	this->sVertex[2].x = calX(x + data.size);
	this->sVertex[2].y = calY(y);

	this->sVertex[3].x = calX(x + data.size);
	this->sVertex[3].y = calY(y + data.size);

	this->data.x = x;
	this->data.y = y;

}

void Squre::setIndex()
{
	unsigned int Index[]{
		0,2,3,//0,2,3,
		3,1,0,
	};
	this->SqureIndex = new unsigned int[6];
	for (unsigned int i = 0; i < 6; i++)
		this->SqureIndex[i] = Index[i];

}

