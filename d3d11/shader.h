#pragma once
#include "res.h"
class shader
{
public:
	shader();
	~shader();
	void compileHlSl(const char * nameFunc);
	void CreateSqureElement(const char * nameFunc);
	void CreateLineElement(const char * nameFunc);
public:

	ID3D10Blob * VS, *PS;					//TODO find good expmple
	ID3D11InputLayout * pLayout;            // the pointer to the input layout
	ID3D11VertexShader *pVS;               // the pointer to the vertex shader
	ID3D11PixelShader *pPS;                // the pointer to the pixel shader

};

