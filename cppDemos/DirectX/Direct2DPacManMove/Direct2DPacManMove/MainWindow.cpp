#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hwnd = m_hwnd;

	

	switch (uMsg)
	{
	case WM_CREATE:
		if (FAILED(m_scene.Initialize()))
		{
			return -1;
		}
		return 0;

	case WM_DESTROY:
		m_scene.CleanUp();
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	case WM_DISPLAYCHANGE:
	{
		PAINTSTRUCT ps;
		BeginPaint(m_hwnd, &ps);
		m_scene.Render(m_hwnd);
		EndPaint(m_hwnd, &ps);
	}
		return 0;

	case WM_KEYDOWN:
		OnKeyDown((UINT) wParam);
		return 0;

	case WM_SIZE:
	{
		int x = (int) (short) LOWORD(lParam);
		int y = (int) (short) HIWORD(lParam);
		m_scene.Resize(x, y);
		InvalidateRect(m_hwnd, NULL, FALSE);
	}
	return 0;

	case WM_ERASEBKGND:
		return 1;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

void MainWindow::OnKeyDown(UINT vkey)
{
	//TODO Fix Key Repeat Rates
	//http://katyscode.wordpress.com/2013/08/30/xinput-tutorial-part-2-mapping-gamepad-buttons-and-analog-movement-to-windows-keyboard-events/

	
	switch (vkey)
	{
	case 87: // w
		m_scene.MovePac(0, -2);
		m_scene.CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);
		break;
	case 83: // s
		m_scene.MovePac(0, 2);
		m_scene.CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);
		break;
	case 65: // a
		m_scene.MovePac(-2, 0);
		m_scene.CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);
		break;
	case 68: // d
		m_scene.MovePac(2, 0);
		m_scene.CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);
		break;
	case VK_DELETE:
		
		break;
	}
}