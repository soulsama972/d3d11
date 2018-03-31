#include"Direct3D.h"
#include"DrawObject.h"
#include"Squre.h"
#include"LineShape.h"




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	Direct3D d;
	if (d.init(hInstance,nCmdShow)) {
		Squre s(100, 399, D3DXCOLOR(0, 1, 1, 1), 200);
		LineShape l(300, 200, 800, 200, D3DXCOLOR(0, 1, 1, 1));

		LineShape t[6];
		t[0].CreateLine(0, 1, 1200, 1, D3DXCOLOR(1, 0, 0, 1));
		t[1].CreateLine(0, 2, 1200, 2, D3DXCOLOR(1, 0, 0, 1));
		t[2].CreateLine(0, 3, 1200, 3, D3DXCOLOR(1, 0, 0, 1));

		t[3].CreateLine(1, 0, 1, 800, D3DXCOLOR(1, 0, 0, 1));
		t[4].CreateLine(2, 0, 2, 800, D3DXCOLOR(1, 0, 0, 1));
		t[5].CreateLine(3, 0, 3, 800, D3DXCOLOR(1, 0, 0, 1));
		MSG msg;
		while (TRUE)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_QUIT)
					break;
			}
			static float x =90;
			d.update();
			d.draw(s);
			d.draw(l);
			for (int i = 0; i < 6; i++)
				d.draw(t[i]);

			d.RenderFrame();
		}
		return msg.wParam;
	}
	return false;
}


