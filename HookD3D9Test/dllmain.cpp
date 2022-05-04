#include <Windows.h>
#include "detours.h"
#include "debug.hpp"
#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")




const char* windowName = "Garry's Mod";
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)
LPDIRECT3DVERTEXBUFFER9 v_buffer{ nullptr };
LPDIRECT3DINDEXBUFFER9 i_buffer;
struct CUSTOMVERTEX { FLOAT X, Y, Z; D3DCOLOR COLOR; };


void initMyStuff(IDirect3DDevice9* pDevice)
{


	CUSTOMVERTEX vertices[] =
	{
		{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },
		{ 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },
		{ -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 0, 0), },
		{ -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 255), },
	};
	pDevice->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX),
		0,
		CUSTOMFVF,
		D3DPOOL_DEFAULT,
		&v_buffer,
		NULL);
	void* bData;

	v_buffer->Lock(NULL, NULL, &bData, NULL);
	memcpy(bData, vertices, sizeof(vertices));
	v_buffer->Unlock();
	short indices[] =
	{
		0, 1, 2,    // side 1
		2, 1, 3,
		4, 0, 6,    // side 2
		6, 0, 2,
		7, 5, 6,    // side 3
		6, 5, 4,
		3, 1, 7,    // side 4
		7, 1, 5,
		4, 5, 0,    // side 5
		0, 5, 1,
		3, 7, 2,    // side 6
		2, 7, 6,
	};

	// create an index buffer interface called i_buffer
	pDevice->CreateIndexBuffer(36 * sizeof(short),
		0,
		D3DFMT_INDEX16,
		D3DPOOL_DEFAULT,
		&i_buffer,
		NULL);

	// lock i_buffer and load the indices into it
	i_buffer->Lock(NULL, NULL, &bData, NULL);
	memcpy(bData, indices, sizeof(indices));
	i_buffer->Unlock();
}


typedef HRESULT(__stdcall* f_EndScene)(IDirect3DDevice9* pDevice);
f_EndScene oEndScene;

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

WNDPROC oWndProc;
HRESULT __stdcall Hooked_EndScene(IDirect3DDevice9* pDevice) // hooke endscene
{


	//pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	//pDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	static bool init = true;
	if (init)
	{
		init = false;
		initMyStuff(pDevice);
	}

	pDevice->SetTexture(0, NULL);
	pDevice->SetPixelShader(NULL);
	pDevice->SetVertexShader(NULL);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
	pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

	//things i am testing
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, 8);
	pDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, TRUE);
	static bool printedTypes = false; //used for debugging
	if (!printedTypes)
	{
		printedTypes = true;
		std::cout << "\n\nRenderState: \n";
		for (int i = 0; i < 104; i++) {
			DWORD pValue;
			pDevice->GetRenderState(renderTypes[i], &pValue);
			std::cout << renderTypesST[i] << "		" << pValue << "\n";
		}

	}
	pDevice->SetFVF(CUSTOMFVF);

	D3DXMATRIX matView;
	D3DXVECTOR3 vec1(0.0f, 0.0f, 15.0f);
	D3DXVECTOR3 vec2(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vec3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&matView,
		&vec1,   // camera position
		&vec2,    // eye position
		&vec3);    // up normal direction
	pDevice->SetTransform(D3DTS_VIEW, &matView);
	D3DXMATRIX matProjection;    // projection matrix
	D3DXMatrixPerspectiveFovLH(&matProjection,
		D3DXToRadian(45),    // FOV
		(FLOAT)1920 / (FLOAT)1080, // aspect ratio
		1.0f,
		100.0f);
	pDevice->SetTransform(D3DTS_PROJECTION, &matProjection);

	pDevice->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
	pDevice->SetIndices(i_buffer);

	D3DXMATRIX rotateY;
	static float index = 0.0f; index += 0.003f;
	D3DXMatrixRotationY(&rotateY, index);

	D3DXMATRIX matPos;
	D3DXMatrixTranslation(&matPos, 0.0f, 0.0f, -2.0f);

	D3DMATRIX result = (matPos * rotateY);
	pDevice->SetTransform(D3DTS_WORLD, &result);
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

	return oEndScene(pDevice); // original ensdcene for the game continue drawing
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


DWORD WINAPI MainThread(LPVOID param) // Our main thread
{
	HWND  window = FindWindowA(NULL, windowName);

	oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);

	IDirect3D9* pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (!pD3D)
		return false;

	D3DPRESENT_PARAMETERS d3dpp{ 0 };
	d3dpp.hDeviceWindow = window, d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD, d3dpp.Windowed = TRUE;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	IDirect3DDevice9* Device = nullptr;
	if (FAILED(pD3D->CreateDevice(0, D3DDEVTYPE_HAL, d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &Device)))
	{
		pD3D->Release();
		return false;
	}


	void** pVTable = *reinterpret_cast<void***>(Device);

	if (Device)
		Device->Release(), Device = nullptr;

	oEndScene = (f_EndScene)DetourFunction((PBYTE)pVTable[42], (PBYTE)Hooked_EndScene);

	return false;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
