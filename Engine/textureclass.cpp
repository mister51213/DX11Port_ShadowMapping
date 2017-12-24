////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "textureclass.h"
#include "DDSTextureLoader.h"

using namespace DirectX;

TextureClass::TextureClass()
{
	//m_texture = 0;
}


TextureClass::TextureClass(const TextureClass& other)
{
}


TextureClass::~TextureClass()
{
}


bool TextureClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* d3dContext, WCHAR* filename)
{
	HRESULT result;


	// Load the texture in.
	//result = D3DX11CreateShaderResourceViewFromFile(device, filename, NULL, NULL, &m_texture, NULL);
	
	result = CreateDDSTextureFromFile(device, d3dContext, filename, &m_texture, &m_textureView);
	if(FAILED(result))
	{
		return false;
	}

	return true;
}


void TextureClass::Shutdown()
{
	//// Release the texture resource.
	//if(m_texture)
	//{
	//	m_texture->Release();
	//	m_texture = 0;
	//}

	return;
}


ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return m_textureView.Get();
}