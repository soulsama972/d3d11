#include "DrawObject.h"

ID3D11Device *dev;                     // the pointer to our Direct3D device interface
ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context


float DrawObject::calX(float x)
{
	x = ((x / SCREEN_WIDTH) * 2 - 1);
	return x;
}

float DrawObject::calY(float y)
{
	y = -((y / SCREEN_HEIGHT) * 2 - 1);
	return y;
}

void DrawObject::createVertexBuffer(UINT byteWidth, const LPVOID src, size_t size,D&d)
{
	ID3D11Buffer * buf;
	D3D11_BUFFER_DESC bd;

	D3D11_SUBRESOURCE_DATA data;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;                // write access access by CPU and GPU
	bd.ByteWidth = byteWidth;             // size is the VERTEX struct * 3
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER; // D3D11_BIND_INDEX_BUFFER      // use as a vertex buffer
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;    // allow CPU to write in buffer


	data.pSysMem = src;
	data.SysMemPitch = 0;
	data.SysMemSlicePitch = 0;

	 dev->CreateBuffer(&bd, &data, &buf);

	map(buf, byteWidth, src);

	d.bufferVs = buf;
}

void  DrawObject::createIndexBuffer(UINT byteWidth, const LPVOID src,D&d)
{
	ID3D11Buffer * buf;
	D3D11_BUFFER_DESC bd;
	HRESULT result =NULL;

	D3D11_SUBRESOURCE_DATA data;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;                // write access access by CPU and GPU
	bd.ByteWidth = byteWidth;             // size is the VERTEX struct * 3
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER; // D3D11_BIND_INDEX_BUFFER      // use as a vertex buffer
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;    // allow CPU to write in buffer


	data.pSysMem = src;
	data.SysMemPitch = 0;
	data.SysMemSlicePitch = 0;
	

	dev->CreateBuffer(&bd, &data, &buf);
	map(buf, byteWidth, src);
	d.bufferPs  = buf;

}



void DrawObject::map(ID3D11Buffer * buf, UINT byteWidth, const LPVOID src)
{
	D3D11_MAPPED_SUBRESOURCE ms2;
	devcon->Map(buf, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms2);    // map the buffer
	memcpy(ms2.pData, src, byteWidth);                 // copy the data
	devcon->Unmap(buf, NULL);  // unmap the buffer
}




