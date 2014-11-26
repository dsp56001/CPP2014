//--------------------------------------------------------------------------------------
// File: DirectXTK3DSceneRenderer.h
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

#pragma once

#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"

#include "Audio.h"
#include "CommonStates.h"
#include "Effects.h"
#include "GeometricPrimitive.h"
#include "Model.h"
#include "PrimitiveBatch.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "VertexTypes.h"
#include "GamePad.h"
#include "SimpleMath.h"

namespace SimpleSample
{
    // This class renders a scene using DirectXTK
	class DirectXTK3DSpriteRenderer
	{
	public:
		DirectXTK3DSpriteRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		void CreateDeviceDependentResources();
		void CreateWindowSizeDependentResources();
		void ReleaseDeviceDependentResources();
		void Update(DX::StepTimer const& timer);
		void Render();

       

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

        //void XM_CALLCONV DrawGrid(DirectX::FXMVECTOR xAxis, DirectX::FXMVECTOR yAxis, DirectX::FXMVECTOR origin, size_t xdivs, size_t ydivs, DirectX::GXMVECTOR color);

        std::unique_ptr<DirectX::CommonStates>                                  m_states;
        std::unique_ptr<DirectX::BasicEffect>                                   m_batchEffect;
        std::unique_ptr<DirectX::IEffectFactory>                                m_fxFactory;
        //std::unique_ptr<DirectX::GeometricPrimitive>                            m_shape;
        //std::unique_ptr<DirectX::Model>                                         m_model;
        std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>  m_batch;
        std::unique_ptr<DirectX::SpriteBatch>                                   m_sprites;
        //std::unique_ptr<DirectX::SpriteFont>                                    m_font;

        //Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>                        m_texture1;
        Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>                        m_texture2;
        Microsoft::WRL::ComPtr<ID3D11InputLayout>                               m_batchInputLayout;

		// Variables used with the rendering loop.
        //uint32_t                                                                m_audioEvent;
        //float                                                                   m_audioTimerAcc;

        bool                                                                    m_retryDefault;

        DirectX::XMFLOAT4X4 m_world;
        DirectX::XMFLOAT4X4 m_view;
        DirectX::XMFLOAT4X4 m_projection;

		DirectX::XMFLOAT2 m_Loc;
		DirectX::XMFLOAT2 m_Dir;
		DirectX::SimpleMath::Vector2 m_Dir2;
		float			  m_speed;
		float			  m_angle;
		
	};
}

