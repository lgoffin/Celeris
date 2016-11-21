/*
 * FILE:
 *   dx11_graphic.cpp
 *
 * AUTHOR:
 *   Stephen Thompson <stephen@solarflare.org.uk>
 *
 * CREATED:
 *   21-Oct-2011
 *   
 * COPYRIGHT:
 *   Copyright (C) Stephen Thompson, 2008 - 2011.
 *
 *   This file is part of the "Coercri" software library. Usage of "Coercri"
 *   is permitted under the terms of the Boost Software License, Version 1.0, 
 *   the text of which is displayed below.
 *
 *   Boost Software License - Version 1.0 - August 17th, 2003
 *
 *   Permission is hereby granted, free of charge, to any person or organization
 *   obtaining a copy of the software and accompanying documentation covered by
 *   this license (the "Software") to use, reproduce, display, distribute,
 *   execute, and transmit the Software, and to prepare derivative works of the
 *   Software, and to permit third-parties to whom the Software is furnished to
 *   do so, all subject to the following:
 *
 *   The copyright notices in the Software and this entire statement, including
 *   the above license grant, this restriction and the following disclaimer,
 *   must be included in all copies of the Software, in whole or in part, and
 *   all derivative works of the Software, unless such copies or derivative
 *   works are solely in the form of machine-executable object code generated by
 *   a source language processor.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 *   SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 *   FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *   DEALINGS IN THE SOFTWARE.
 *
 */

#include "dx11_graphic.hpp"
#include "../core/dx_error.hpp"
#include "../../gfx/pixel_array.hpp"

namespace Coercri {

    DX11Graphic::DX11Graphic(ID3D11Device *device, boost::shared_ptr<const PixelArray> pixels, int hx_, int hy_)
        : hx(hx_), hy(hy_), parr(pixels)
    {
        // Create the texture
        D3D11_TEXTURE2D_DESC td;
        memset(&td, 0, sizeof(td));
        td.Width = pixels->getWidth();
        td.Height = pixels->getHeight();
        td.MipLevels = 1;
        td.ArraySize = 1;
        td.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        td.SampleDesc.Count = 1;
        td.SampleDesc.Quality = 0;
        td.Usage = D3D11_USAGE_IMMUTABLE;
        td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
        td.CPUAccessFlags = 0;
        td.MiscFlags = 0;

        D3D11_SUBRESOURCE_DATA sd;
        memset(&sd, 0, sizeof(sd));
        sd.pSysMem = &(*pixels)(0,0);
        sd.SysMemPitch = pixels->getWidth() * 4;

        ID3D11Texture2D *pTexture;
        HRESULT hr = device->CreateTexture2D(&td, &sd, &pTexture);
        if (FAILED(hr)) {
            throw DXError("createGraphic: Failed to create 2D texture", hr);
        }
        m_psTexture.reset(pTexture);

        // Create the shader resource view
        D3D11_SHADER_RESOURCE_VIEW_DESC srvd;
        memset(&srvd, 0, sizeof(srvd));
        srvd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        srvd.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
        srvd.Texture2D.MostDetailedMip = 0;
        srvd.Texture2D.MipLevels = 1;
        
        ID3D11ShaderResourceView *pSRV;
        hr = device->CreateShaderResourceView(pTexture, &srvd, &pSRV);
        if (FAILED(hr)) {
            throw DXError("createGraphic: Failed to create shader resource view", hr);
        }
        m_psShaderResourceView.reset(pSRV);
    }

    int DX11Graphic::getWidth() const
    {
        return parr->getWidth();
    }

    int DX11Graphic::getHeight() const
    {
        return parr->getHeight();
    }
}
