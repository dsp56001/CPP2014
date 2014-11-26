//--------------------------------------------------------------------------------------
// File: DirectXTK3DSceneRenderer.cpp
//
// This is a simple Windows Store app for Windows 8.1 showing use of DirectXTK
//
// http://go.microsoft.com/fwlink/?LinkId=248929
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "DirectXTK3DSpriteRenderer.h"

#include "DDSTextureLoader.h"

#include "..\Common\DirectXHelper.h"	// For ThrowIfFailed and ReadDataAsync
#include <WICTextureLoader.h> //to load png
#include <math.h>

using namespace SimpleSample;

using namespace DirectX;
using namespace Windows::Foundation;

std::unique_ptr<GamePad> gamePad(new GamePad);

DirectXTK3DSpriteRenderer::DirectXTK3DSpriteRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
	m_deviceResources(deviceResources),
	m_Loc(100, 100),
	m_Dir(1, 0),
	m_speed(200),
	m_angle(0)
{
	CreateDeviceDependentResources();
    CreateWindowSizeDependentResources();
	
    
}

// Initializes view parameters when the window size changes.
void DirectXTK3DSpriteRenderer::CreateWindowSizeDependentResources()
{
    Size outputSize = m_deviceResources->GetOutputSize();
    float aspectRatio = outputSize.Width / outputSize.Height;
    float fovAngleY = 70.0f * XM_PI / 180.0f;

	// This is a simple example of change that can be made when the app is in
	// portrait or snapped view.
	if (aspectRatio < 1.0f)
	{
		fovAngleY *= 2.0f;
	}

	// Note that the OrientationTransform3D matrix is post-multiplied here
	// in order to correctly orient the scene to match the display orientation.
	// This post-multiplication step is required for any draw calls that are
	// made to the swap chain render target. For draw calls to other targets,
	// this transform should not be applied.

	// This sample makes use of a right-handed coordinate system using row-major matrices.
	/*XMMATRIX perspectiveMatrix = XMMatrixPerspectiveFovRH(
		fovAngleY,
		aspectRatio,
		0.01f,
		100.0f
		);

	XMFLOAT4X4 orientation = m_deviceResources->GetOrientationTransform3D();

	XMMATRIX orientationMatrix = XMLoadFloat4x4(&orientation);

    XMMATRIX projection = XMMatrixMultiply(perspectiveMatrix, orientationMatrix);

    m_batchEffect->SetProjection(projection);*/

    m_sprites->SetRotation( m_deviceResources->ComputeDisplayRotation() );

	/*XMStoreFloat4x4(
        &m_projection,
		projection
		);*/
}



void DirectXTK3DSpriteRenderer::Update(DX::StepTimer const& timer)
{
    /*XMVECTOR eye = XMVectorSet(0.0f, 0.7f, 1.5f, 0.0f);
    XMVECTOR at = XMVectorSet(0.0f, -0.1f, 0.0f, 0.0f);
    XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

    XMMATRIX view = XMMatrixLookAtRH(eye, at, up);
    XMMATRIX world = XMMatrixRotationY( float(timer.GetTotalSeconds() * XM_PIDIV4) );

    m_batchEffect->SetView(view);
    m_batchEffect->SetWorld(XMMatrixIdentity());

    XMStoreFloat4x4(&m_view, view);
    XMStoreFloat4x4(&m_world, world);*/
	 
	float deltaTime = timer.GetElapsedSeconds();

	//gamepad
	auto state = gamePad->GetState(0);

	if (state.IsConnected())
	{
		float posx = state.thumbSticks.leftX;
		float posy = state.thumbSticks.leftY;
		m_Dir.x = posx;
		m_Dir.y = posy *-1;
		
		m_angle = -(float) atan2(posy, posx);
	}


	m_Loc.x += m_Dir.x * (m_speed * deltaTime);
	m_Loc.y += m_Dir.y * (m_speed * deltaTime);

	//keep pacMan on screen 
	if (m_Loc.x > (m_deviceResources->GetOutputSize()).Width - 25) //HACK hard coded width of 1/2 width of 50
	{
		m_Loc.x = (m_deviceResources->GetOutputSize()).Width - 25;
	}
	if (m_Loc.x < 25)
	{
		m_Loc.x = 25;
	}
    
}




void DirectXTK3DSpriteRenderer::Render()
{
	//auto context = m_deviceResources->GetD3DDeviceContext();

	// Set render targets to the screen.
	//ID3D11RenderTargetView *const targets[1] = { m_deviceResources->GetBackBufferRenderTargetView() };
	//context->OMSetRenderTargets(1, targets, m_deviceResources->GetDepthStencilView());

    // Draw procedurally generated dynamic grid
    //const XMVECTORF32 xaxis = { 20.f, 0.f, 0.f };
    //const XMVECTORF32 yaxis = { 0.f, 0.f, 20.f };
    //DrawGrid(xaxis, yaxis, g_XMZero, 20, 20, Colors::Gray);

    // Draw sprite
    m_sprites->Begin();
	
	m_sprites->Draw(m_texture2.Get(), XMFLOAT2( m_Loc.x, m_Loc.y), nullptr, Colors::White, m_angle, XMFLOAT2(25,25));

    m_sprites->End();

}

void DirectXTK3DSpriteRenderer::CreateDeviceDependentResources()
{
    // Create DirectXTK objects
    auto device = m_deviceResources->GetD3DDevice();
    m_states.reset(new CommonStates(device));

    auto fx = new EffectFactory( device );
    fx->SetDirectory( L"Assets" );
    m_fxFactory.reset( fx );

    auto context = m_deviceResources->GetD3DDeviceContext();
    m_sprites.reset(new SpriteBatch(context));
    m_batch.reset(new PrimitiveBatch<VertexPositionColor>(context));

    m_batchEffect.reset(new BasicEffect(device));
    m_batchEffect->SetVertexColorEnabled(true);

    {
        void const* shaderByteCode;
        size_t byteCodeLength;

        m_batchEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);

        DX::ThrowIfFailed(
            device->CreateInputLayout(VertexPositionColor::InputElements,
            VertexPositionColor::InputElementCount,
            shaderByteCode, byteCodeLength,
            m_batchInputLayout.ReleaseAndGetAddressOf())
            );
    }

	//Update to load PNG



	DX::ThrowIfFailed(
		CreateWICTextureFromFile(device, L"assets\\pacmanSingle.png", nullptr, m_texture2.ReleaseAndGetAddressOf())
		);
}

void DirectXTK3DSpriteRenderer::ReleaseDeviceDependentResources()
{
    m_states.reset();
    m_fxFactory.reset();
    m_sprites.reset();
    m_batch.reset();
    m_batchEffect.reset();
    //m_font.reset();
    m_shape.reset();
    //m_model.reset();
    //m_texture1.Reset();
    m_texture2.Reset();
    m_batchInputLayout.Reset();
}