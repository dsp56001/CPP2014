#include <windows.h>
#include <D2d1.h>
#include <assert.h>
#include "Scene.h"



HRESULT Scene::Initialize()
{
	return D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&m_pFactory);
}

void Scene::Render(HWND hwnd)
{
	HRESULT hr = CreateGraphicsResources(hwnd);
	if (FAILED(hr))
	{
		return;
	}

	assert(m_pRenderTarget != NULL);

	m_pRenderTarget->BeginDraw();

	RenderScene();

	hr = m_pRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		DiscardDeviceDependentResources();
	}
}

HRESULT Scene::Resize(int x, int y)
{
	HRESULT hr = S_OK;
	if (m_pRenderTarget)
	{
		hr = m_pRenderTarget->Resize(D2D1::SizeU(x, y));
		if (SUCCEEDED(hr))
		{
			CalculateLayout();
		}
	}
	return hr;
}


HRESULT Scene::CreateGraphicsResources(HWND hwnd)
{
	HRESULT hr = S_OK;
	if (m_pRenderTarget == NULL)
	{
		RECT rc;
		GetClientRect(hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		hr = m_pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hwnd, size),
			&m_pRenderTarget
			);

		if (SUCCEEDED(hr))
		{
			hr = CreateDeviceDependentResources();
		}
		if (SUCCEEDED(hr))
		{
			CalculateLayout();
		}
	}
	return hr;
}


HRESULT Scene::CreateDeviceDependentResources()
{
	return m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0), &m_pStroke);
}

HRESULT Scene::CreateMouthGeometry()
{
	HRESULT hr = S_OK;
	//mouth
	hr = m_pFactory->CreatePathGeometry(&m_pMouthGeometry);
	if (SUCCEEDED(hr))
	{
		ID2D1GeometrySink *pSink = NULL;
		hr = m_pMouthGeometry->Open(&pSink);
		if (SUCCEEDED(hr))
		{
			pSink->SetFillMode(D2D1_FILL_MODE_WINDING);

			pSink->BeginFigure(
				D2D1::Point2F(m_ellipse.point.x, m_ellipse.point.y),
				D2D1_FIGURE_BEGIN_FILLED
				);
			D2D1_POINT_2F points[3] = {
				D2D1::Point2F(m_ellipse.point.x + m_ellipse.radiusX, m_ellipse.point.y - 10),
				D2D1::Point2F(m_ellipse.point.x + m_ellipse.radiusX, m_ellipse.point.y + 10),
				//D2D1::Point2F(212, 160),
				//D2D1::Point2F(156, 255),
				//D2D1::Point2F(346, 255),
				D2D1::Point2F(m_ellipse.point.x, m_ellipse.point.y),
			};
			pSink->AddLines(points, ARRAYSIZE(points));
			pSink->EndFigure(D2D1_FIGURE_END_CLOSED);

		}
		hr = pSink->Close();

		SafeRelease(&pSink);
		return hr;
	}
}
HRESULT Scene::CreateRadialBrush()
{
	SafeRelease(&m_pGradientStops);
	SafeRelease(&m_pFill);

	// Define the gradient stops for the brush.
	D2D1_GRADIENT_STOP gradientStops[2];
	gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::LightYellow, 1);
	gradientStops[0].position = 0.0f;
	gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Yellow, 1);
	gradientStops[1].position = 1.0f;

	// Create the gradient stop collection.
	HRESULT hr = m_pRenderTarget->CreateGradientStopCollection(
		gradientStops,          // Array of gradient stops
		2,                      // Number of elements in the array.
		D2D1_GAMMA_2_2,
		D2D1_EXTEND_MODE_CLAMP,
		&m_pGradientStops
		);

	// Create the brush. The radial gradient is centered on the clock face.
	if (SUCCEEDED(hr))
	{
		hr = m_pRenderTarget->CreateRadialGradientBrush(
			D2D1::RadialGradientBrushProperties(
			m_ellipse.point,        // center of gradient
			D2D1::Point2F(0, 0),    // offset
			m_ellipse.radiusX,
			m_ellipse.radiusY),
			m_pGradientStops,           // Pointer to the gradient stops collection.
			&m_pFill);
	}
	return hr;
}



void Scene::DrawClockHand(float fHandLength, float fAngle, float fStrokeWidth)
{
	m_pRenderTarget->SetTransform(
		D2D1::Matrix3x2F::Rotation(fAngle, m_ellipse.point)
		);

	m_pStroke->SetColor(D2D1::ColorF(D2D1::ColorF::Black, 1.f));
	m_pRenderTarget->DrawGeometry(m_pMouthGeometry, m_pStroke, 1.f);
	m_pRenderTarget->FillGeometry(m_pMouthGeometry, m_pStroke);

	// endPoint defines one end of the hand.
	/* D2D_POINT_2F endPoint = D2D1::Point2F(
	m_ellipse.point.x,
	m_ellipse.point.y - (m_ellipse.radiusY * fHandLength)
	);*/

	// Draw a line from the center of the ellipse to endPoint.
	/*m_pRenderTarget->DrawLine(
	m_ellipse.point, endPoint, m_pStroke, fStrokeWidth);*/



	//m_pRenderTarget->


}

void Scene::RenderScene()
{
	m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::CornflowerBlue));

	m_pRenderTarget->FillEllipse(m_ellipse, m_pFill);
	//m_pRenderTarget->DrawEllipse(m_ellipse, m_pStroke);

	// Draw tick marks
	/*for (DWORD i = 0; i < 12; i++)
	{
	m_pRenderTarget->DrawLine(m_Ticks[i*2], m_Ticks[i*2+1], m_pStroke, 2.0f);
	}*/

	// Draw hands
	//SYSTEMTIME time;
	//GetLocalTime(&time);

	// 60 minutes = 30 degrees, 1 minute = 0.5 degree
	/*const float fHourAngle = (360.0f / 12) * (time.wHour) + (time.wMinute * 0.5f);
	const float fMinuteAngle =(360.0f / 60) * (time.wMinute);
	const float fSecondAngle =
	(360.0f / 60) * (time.wSecond) + (360.0f / 60000) * (time.wMilliseconds);


	DrawClockHand(0.85f, fMinuteAngle, 4);
	DrawClockHand(0.85f, fSecondAngle, 1);*/

	// Restore the identity transformation.
	DrawClockHand(0.6f, 0, 6);
	m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
}

void Scene::CalculateLayout()
{
	D2D1_SIZE_F fSize = m_pRenderTarget->GetSize();

	const float x = fSize.width / 2.0f;
	const float y = fSize.height / 2.0f;
	const float radius = min(x, y);

	m_ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);

	// Calculate tick marks.

	D2D_POINT_2F pt1 = D2D1::Point2F(
		m_ellipse.point.x,
		m_ellipse.point.y - (m_ellipse.radiusY * 0.9f)
		);

	D2D_POINT_2F pt2 = D2D1::Point2F(
		m_ellipse.point.x,
		m_ellipse.point.y - m_ellipse.radiusY
		);

	for (DWORD i = 0; i < 12; i++)
	{
		D2D1::Matrix3x2F mat = D2D1::Matrix3x2F::Rotation(
			(360.0f / 12) * i, m_ellipse.point);

		m_Ticks[i * 2] = mat.TransformPoint(pt1);
		m_Ticks[i * 2 + 1] = mat.TransformPoint(pt2);
	}

	// Create the radial brush. The radial brush is centered on
	// the pac man, so it must be recreated when the size changes.
	CreateRadialBrush();
	CreateMouthGeometry();
}


void Scene::DiscardDeviceDependentResources()
{
	SafeRelease(&m_pFill);
	SafeRelease(&m_pStroke);
	SafeRelease(&m_pRenderTarget);
}