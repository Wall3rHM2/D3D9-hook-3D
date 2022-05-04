#pragma once
#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")


D3DRENDERSTATETYPE renderTypes[104] = { D3DRS_ZENABLE,//these two arrays are used to get all the renderstatetype values of the device
  D3DRS_FILLMODE, 
  D3DRS_SHADEMODE,
  D3DRS_ZWRITEENABLE,
  D3DRS_ALPHATESTENABLE,
  D3DRS_LASTPIXEL,
  D3DRS_SRCBLEND,
  D3DRS_DESTBLEND,
  D3DRS_CULLMODE,
  D3DRS_ZFUNC,
  D3DRS_ALPHAREF,
  D3DRS_ALPHAFUNC,
  D3DRS_DITHERENABLE,
  D3DRS_ALPHABLENDENABLE,
  D3DRS_FOGENABLE,
  D3DRS_SPECULARENABLE,
  D3DRS_FOGCOLOR,
  D3DRS_FOGTABLEMODE,
  D3DRS_FOGSTART,
  D3DRS_FOGEND,
  D3DRS_FOGDENSITY,
  D3DRS_RANGEFOGENABLE,
  D3DRS_STENCILENABLE,
  D3DRS_STENCILFAIL,
  D3DRS_STENCILZFAIL,
  D3DRS_STENCILPASS,
  D3DRS_STENCILFUNC,
  D3DRS_STENCILREF,
  D3DRS_STENCILMASK,
  D3DRS_STENCILWRITEMASK,
  D3DRS_TEXTUREFACTOR,
  D3DRS_WRAP0,
  D3DRS_WRAP1,
  D3DRS_WRAP2,
  D3DRS_WRAP3,
  D3DRS_WRAP4,
  D3DRS_WRAP5,
  D3DRS_WRAP6,
  D3DRS_WRAP7,
  D3DRS_CLIPPING,
  D3DRS_LIGHTING,
  D3DRS_AMBIENT,
  D3DRS_FOGVERTEXMODE,
  D3DRS_COLORVERTEX,
  D3DRS_LOCALVIEWER,
  D3DRS_NORMALIZENORMALS,
  D3DRS_DIFFUSEMATERIALSOURCE,
  D3DRS_SPECULARMATERIALSOURCE,
  D3DRS_AMBIENTMATERIALSOURCE,
  D3DRS_EMISSIVEMATERIALSOURCE,
  D3DRS_VERTEXBLEND,
  D3DRS_CLIPPLANEENABLE,
  D3DRS_POINTSIZE,
  D3DRS_POINTSIZE_MIN,
  D3DRS_POINTSPRITEENABLE,
  D3DRS_POINTSCALEENABLE,
  D3DRS_POINTSCALE_A,
  D3DRS_POINTSCALE_B,
  D3DRS_POINTSCALE_C,
  D3DRS_MULTISAMPLEANTIALIAS,
  D3DRS_MULTISAMPLEMASK,
  D3DRS_PATCHEDGESTYLE,
  D3DRS_DEBUGMONITORTOKEN,
  D3DRS_POINTSIZE_MAX,
  D3DRS_INDEXEDVERTEXBLENDENABLE,
  D3DRS_COLORWRITEENABLE,
  D3DRS_TWEENFACTOR,
  D3DRS_BLENDOP,
  D3DRS_POSITIONDEGREE,
  D3DRS_NORMALDEGREE,
  D3DRS_SCISSORTESTENABLE,
  D3DRS_SLOPESCALEDEPTHBIAS,
  D3DRS_ANTIALIASEDLINEENABLE,
  D3DRS_MINTESSELLATIONLEVEL,
  D3DRS_MAXTESSELLATIONLEVEL,
  D3DRS_ADAPTIVETESS_X,
  D3DRS_ADAPTIVETESS_Y,
  D3DRS_ADAPTIVETESS_Z,
  D3DRS_ADAPTIVETESS_W,
  D3DRS_ENABLEADAPTIVETESSELLATION,
  D3DRS_TWOSIDEDSTENCILMODE,
  D3DRS_CCW_STENCILFAIL,
  D3DRS_CCW_STENCILZFAIL,
  D3DRS_CCW_STENCILPASS,
  D3DRS_CCW_STENCILFUNC,
  D3DRS_COLORWRITEENABLE1,
  D3DRS_COLORWRITEENABLE2,
  D3DRS_COLORWRITEENABLE3,
  D3DRS_BLENDFACTOR,
  D3DRS_SRGBWRITEENABLE,
  D3DRS_DEPTHBIAS,
  D3DRS_WRAP8,
  D3DRS_WRAP9,
  D3DRS_WRAP10,
  D3DRS_WRAP11,
  D3DRS_WRAP12,
  D3DRS_WRAP13,
  D3DRS_WRAP14,
  D3DRS_WRAP15,
  D3DRS_SEPARATEALPHABLENDENABLE,
  D3DRS_SRCBLENDALPHA,
  D3DRS_DESTBLENDALPHA,
  D3DRS_BLENDOPALPHA,
  D3DRS_FORCE_DWORD
};

const char* renderTypesST[104] = { "D3DRS_ZENABLE",
  "D3DRS_FILLMODE",
  "D3DRS_SHADEMODE",
  "D3DRS_ZWRITEENABLE",
  "D3DRS_ALPHATESTENABLE",
  "D3DRS_LASTPIXEL",
  "D3DRS_SRCBLEND",
  "D3DRS_DESTBLEND",
  "D3DRS_CULLMODE",
  "D3DRS_ZFUNC",
  "D3DRS_ALPHAREF",
  "D3DRS_ALPHAFUNC",
  "D3DRS_DITHERENABLE",
  "D3DRS_ALPHABLENDENABLE",
  "D3DRS_FOGENABLE",
  "D3DRS_SPECULARENABLE",
  "D3DRS_FOGCOLOR",
  "D3DRS_FOGTABLEMODE",
  "D3DRS_FOGSTART",
  "D3DRS_FOGEND",
  "D3DRS_FOGDENSITY",
  "D3DRS_RANGEFOGENABLE",
  "D3DRS_STENCILENABLE",
  "D3DRS_STENCILFAIL",
  "D3DRS_STENCILZFAIL",
  "D3DRS_STENCILPASS",
  "D3DRS_STENCILFUNC",
  "D3DRS_STENCILREF",
  "D3DRS_STENCILMASK",
  "D3DRS_STENCILWRITEMASK",
  "D3DRS_TEXTUREFACTOR",
  "D3DRS_WRAP0",
  "D3DRS_WRAP1",
  "D3DRS_WRAP2",
  "D3DRS_WRAP3",
  "D3DRS_WRAP4",
  "D3DRS_WRAP5",
  "D3DRS_WRAP6",
  "D3DRS_WRAP7",
  "D3DRS_CLIPPING",
  "D3DRS_LIGHTING",
  "D3DRS_AMBIENT",
  "D3DRS_FOGVERTEXMODE",
  "D3DRS_COLORVERTEX",
  "D3DRS_LOCALVIEWER",
  "D3DRS_NORMALIZENORMALS",
  "D3DRS_DIFFUSEMATERIALSOURCE",
  "D3DRS_SPECULARMATERIALSOURCE",
  "D3DRS_AMBIENTMATERIALSOURCE",
  "D3DRS_EMISSIVEMATERIALSOURCE",
  "D3DRS_VERTEXBLEND",
  "D3DRS_CLIPPLANEENABLE",
  "D3DRS_POINTSIZE",
  "D3DRS_POINTSIZE_MIN",
  "D3DRS_POINTSPRITEENABLE",
  "D3DRS_POINTSCALEENABLE",
  "D3DRS_POINTSCALE_A",
  "D3DRS_POINTSCALE_B",
  "D3DRS_POINTSCALE_C",
  "D3DRS_MULTISAMPLEANTIALIAS",
  "D3DRS_MULTISAMPLEMASK",
  "D3DRS_PATCHEDGESTYLE",
  "D3DRS_DEBUGMONITORTOKEN",
  "D3DRS_POINTSIZE_MAX",
  "D3DRS_INDEXEDVERTEXBLENDENABLE",
  "D3DRS_COLORWRITEENABLE",
  "D3DRS_TWEENFACTOR",
  "D3DRS_BLENDOP",
  "D3DRS_POSITIONDEGREE",
  "D3DRS_NORMALDEGREE",
  "D3DRS_SCISSORTESTENABLE",
  "D3DRS_SLOPESCALEDEPTHBIAS",
  "D3DRS_ANTIALIASEDLINEENABLE",
  "D3DRS_MINTESSELLATIONLEVEL",
  "D3DRS_MAXTESSELLATIONLEVEL",
  "D3DRS_ADAPTIVETESS_X",
  "D3DRS_ADAPTIVETESS_Y",
  "D3DRS_ADAPTIVETESS_Z",
  "D3DRS_ADAPTIVETESS_W",
  "D3DRS_ENABLEADAPTIVETESSELLATION",
  "D3DRS_TWOSIDEDSTENCILMODE",
  "D3DRS_CCW_STENCILFAIL",
  "D3DRS_CCW_STENCILZFAIL",
  "D3DRS_CCW_STENCILPASS",
  "D3DRS_CCW_STENCILFUNC",
  "D3DRS_COLORWRITEENABLE1",
  "D3DRS_COLORWRITEENABLE2",
  "D3DRS_COLORWRITEENABLE3",
  "D3DRS_BLENDFACTOR",
  "D3DRS_SRGBWRITEENABLE",
  "D3DRS_DEPTHBIAS",
  "D3DRS_WRAP8",
  "D3DRS_WRAP9",
  "D3DRS_WRAP10",
  "D3DRS_WRAP11",
  "D3DRS_WRAP12",
  "D3DRS_WRAP13",
  "D3DRS_WRAP14",
  "D3DRS_WRAP15",
  "D3DRS_SEPARATEALPHABLENDENABLE",
  "D3DRS_SRCBLENDALPHA",
  "D3DRS_DESTBLENDALPHA",
  "D3DRS_BLENDOPALPHA",
  "D3DRS_FORCE_DWORD"
};