#include "pch.h"
#include "SampleFpsTextRenderer.h"

#include "Common/DirectXHelper.h"

using namespace CPPHelloDirectX;

// Initializes D2D resources used for text rendering.
SampleFpsTextRenderer::SampleFpsTextRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
TextRenderer(deviceResources)
{

	
}

// Updates the text to be displayed.
void SampleFpsTextRenderer::Update(DX::StepTimer const& timer)
{
	
	TextRenderer::Update(timer);
	// Update display text.
	uint32 fps = timer.GetFramesPerSecond();
	m_text = (fps > 0) ? std::to_wstring(fps) + L" FPS" : L" - FPS";
}

// Renders a frame to the screen.
void SampleFpsTextRenderer::Render()
{
	
	Windows::Foundation::Size logicalSize = m_deviceResources->GetLogicalSize();

	// Position on the bottom right corner
	m_screenTranslation = D2D1::Matrix3x2F::Translation(
		logicalSize.Width - m_textMetrics.layoutWidth,
		logicalSize.Height - m_textMetrics.height
		);
	
	TextRenderer::Render();
}
