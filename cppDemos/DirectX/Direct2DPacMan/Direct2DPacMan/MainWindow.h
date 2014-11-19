#include "Scene.h"
#include "basewin.h"

class MainWindow : public BaseWindow<MainWindow>
{
	Scene   m_scene;

public:

	PCWSTR  ClassName() const { return L"PacMan Window Class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};