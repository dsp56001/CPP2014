#include "pch.h"
#include "TextRenderer.h"

#include "Common/DirectXHelper.h"

using namespace CPPHelloDirectX;


TextRenderer::TextRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
m_text(L""),
m_deviceResources(deviceResources)
{
	ZeroMemory(&m_textMetrics, sizeof(DWRITE_TEXT_METRICS));

	// Create device independent resources
	DX::ThrowIfFailed(
		m_deviceResources->GetDWriteFactory()->CreateTextFormat(
		L"Segoe UI",
		nullptr,
		DWRITE_FONT_WEIGHT_LIGHT,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		32.0f,
		L"en-US",
		&m_textFormat
		)
		);

	DX::ThrowIfFailed(
		m_textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR)
		);

	DX::ThrowIfFailed(
		m_deviceResources->GetD2DFactory()->CreateDrawingStateBlock(&m_stateBlock)
		);

	CreateDeviceDependentResources();

	//set default text
	m_text = L"Hello DirectX!!!";
	m_locX = 100.0f; 
	m_locY = 100.0f;

}


TextRenderer::~TextRenderer()
{
}


// Updates the text to be displayed.
void TextRenderer::Update(DX::StepTimer const& timer)
{
	
	m_screenTranslation = D2D1::Matrix3x2F::Translation(
		m_locX,
		m_locX
		);
	
	DX::ThrowIfFailed(
		m_deviceResources->GetDWriteFactory()->CreateTextLayout(
		m_text.c_str(),
		(uint32) m_text.length(),
		m_textFormat.Get(),
		240.0f, // Max width of the input text.
		50.0f, // Max height of the input text.
		&m_textLayout
		)
		);

	DX::ThrowIfFailed(
		m_textLayout->GetMetrics(&m_textMetrics)
		);
}

// Renders a frame to the screen.
void TextRenderer::Render()
{
	ID2D1DeviceContext* context = m_deviceResources->GetD2DDeviceContext();

	context->SaveDrawingState(m_stateBlock.Get());
	context->BeginDraw();


	context->SetTransform(m_screenTranslation * m_deviceResources->GetOrientationTransform2D());

	DX::ThrowIfFailed(
		m_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING)
		);

	context->DrawTextLayout(
		D2D1::Point2F(0.f, 0.f),
		m_textLayout.Get(),
		m_whiteBrush.Get()
		);

	// Ignore D2DERR_RECREATE_TARGET here. This error indicates that the device
	// is lost. It will be handled during the next call to Present.
	HRESULT hr = context->EndDraw();
	if (hr != D2DERR_RECREATE_TARGET)
	{
		DX::ThrowIfFailed(hr);
	}

	context->RestoreDrawingState(m_stateBlock.Get());
}

void TextRenderer::CreateDeviceDependentResources()
{
	DX::ThrowIfFailed(
		m_deviceResources->GetD2DDeviceContext()->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_whiteBrush)
		);
}
void TextRenderer::ReleaseDeviceDependentResources()
{
	m_whiteBrush.Reset();
}
