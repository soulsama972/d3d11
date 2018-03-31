#include "shader.h"

extern  ID3D11Device *dev;                     // the pointer to our Direct3D device interface
extern ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context

shader::shader()
{
	this->pLayout = 0;
	this->pPS = 0;
	this->pVS = 0;
	this->PS = 0;
	this->VS = 0;
}


shader::~shader()
{
	if(pLayout)
	pLayout->Release();
	if (pPS)
	pPS->Release();
	if (pVS)
	pVS->Release();
}
void shader::compileHlSl(const char * nameFunc)
{
	D3DX11CompileFromFile("VertexShader.hlsl", 0, 0, nameFunc, "vs_4_0", 0, 0, 0, &VS, 0, 0);
	D3DX11CompileFromFile("PixelShader.hlsl", 0, 0, nameFunc, "ps_4_0", 0, 0, 0, &PS, 0, 0);
	// encapsulate both shaders into shader objects
	dev->CreateVertexShader(VS->GetBufferPointer(), VS->GetBufferSize(), NULL, &pVS);
	dev->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), NULL, &pPS);
}

void shader::CreateSqureElement(const char * nameFunc)
{
	compileHlSl(nameFunc);

	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0,0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0,16, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	dev->CreateInputLayout(ied, 2, VS->GetBufferPointer(), VS->GetBufferSize(), &pLayout);
}

void shader::CreateLineElement(const char * nameFunc)
{
	compileHlSl(nameFunc);
	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0,8, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	dev->CreateInputLayout(ied, 2, VS->GetBufferPointer(), VS->GetBufferSize(), &pLayout);
}
