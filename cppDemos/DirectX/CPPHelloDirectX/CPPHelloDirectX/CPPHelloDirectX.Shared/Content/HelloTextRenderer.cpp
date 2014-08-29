#include "pch.h"
#include "HelloTextRenderer.h"

#include "Common/DirectXHelper.h"

using namespace CPPHelloDirectX;

// Initializes D2D resources used for text rendering.
HelloTextRenderer::HelloTextRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
TextRenderer(deviceResources)
{


}

// Updates the text to be displayed.
void HelloTextRenderer::Update(DX::StepTimer const& timer)
{

	TextRenderer::Update(timer);
	
}

// Renders a frame to the screen.
void HelloTextRenderer::Render()
{

	Windows::Foundation::Size logicalSize = m_deviceResources->GetLogicalSize();

	

	TextRenderer::Render();
}