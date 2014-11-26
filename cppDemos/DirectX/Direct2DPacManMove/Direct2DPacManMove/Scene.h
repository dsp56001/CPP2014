#include <windows.h>
#include <D2d1.h>


template <class T> void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}

class Scene
{
	ID2D1Factory                *m_pFactory;
	ID2D1HwndRenderTarget       *m_pRenderTarget;

	ID2D1RadialGradientBrush    *m_pFill;
	ID2D1SolidColorBrush        *m_pStroke;
	ID2D1GradientStopCollection *m_pGradientStops;

	ID2D1PathGeometry *m_pMouthGeometry;

	float                       m_fScaleX;
	float                       m_fScaleY;

	D2D1_ELLIPSE                m_ellipse;
	D2D_POINT_2F                m_Ticks[24];

	D2D_POINT_2F				m_PacLoc;
	float						m_PacRadius;

	HRESULT CreateGraphicsResources(HWND hwnd);
	HRESULT CreateDeviceDependentResources();
	void    DiscardDeviceDependentResources();
	
	void    RenderScene();

	HRESULT CreateRadialBrush();
	HRESULT CreateMouthGeometry();
	void    DrawClockHand(float fHandLength, float fAngle, float fStrokeWidth);
	

	template <class T>
	T PixelToDipX(T pixels) const
	{
		return static_cast<T>(pixels / m_fScaleX);
	}

	template <class T>
	T PixelToDipY(T pixels) const
	{
		return static_cast<T>(pixels / m_fScaleY);
	}

public:
	void	MovePac(float x, float y);
	void    CalculateLayout();
	Scene()
		: m_pFill(NULL),
		m_pStroke(NULL),
		m_pGradientStops(NULL),
		m_pFactory(NULL),
		m_pRenderTarget(NULL),
		m_fScaleX(1.0f),
		m_fScaleY(1.0f),
		m_PacRadius(100),
		m_PacLoc(D2D1::Point2F(100, 100))
	{
	}

	~Scene()
	{
		CleanUp();
	}

	HRESULT Initialize();
	void Render(HWND hwnd);
	HRESULT Resize(int x, int y);

	void CleanUp()
	{
		DiscardDeviceDependentResources();

		// Discard device-independent resources.
		SafeRelease(&m_pGradientStops);
		SafeRelease(&m_pFactory);
	}

	
};