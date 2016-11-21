/*
 * FILE:
 *   dx11_window.hpp
 *
 * PURPOSE:
 *   Implementation of Window for Direct3D 11
 *   
 * AUTHOR:
 *   Stephen Thompson <stephen@solarflare.org.uk>
 *
 * CREATED:
 *   19-Oct-2011
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

#ifndef COERCRI_DX11_WINDOW_HPP
#define COERCRI_DX11_WINDOW_HPP

#include "dx11_gfx_driver.hpp"
#include "../../gfx/window.hpp"

namespace Coercri {

    class DX11Window : public Window {
    public:
        // ctor not intended to be called directly by the user; use DX11GfxDriver::createWindow()
        DX11Window(int width, int height, bool resizable, bool fullscreen, const std::string &title, int icon_id,
                   DX11GfxDriver &driver);
        ~DX11Window();

        // Overridden from Coercri::Window
        virtual void getSize(int &w, int &h) const;
        virtual bool hasFocus() const;
        virtual void popToFront();
        virtual void showMousePointer(bool shown);
        virtual void captureMouse(bool captured);
        virtual void switchToWindowed(int w, int h);
        virtual void switchToFullScreen(int w, int h);
        virtual bool isFullScreen() const;
        virtual std::auto_ptr<GfxContext> createGfxContext();

        // Functions for accessing Direct3D objects
        IDXGISwapChain * getSwapChain() { return m_psSwapChain.get(); }
        ID3D11RenderTargetView * getRenderTargetView() { return m_psRenderTargetView.get(); }

    private:
        // prevent copying
        DX11Window(const DX11Window&);
        void operator=(const DX11Window&);

    private:
        void createRenderTargetView();
        static LRESULT CALLBACK windowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
        void handleWindowResize();
        
    private:
        DX11GfxDriver &gfx_driver;
        HWND hwnd;
        bool in_size_move;  // inhibit back buffer resizing while user is resizing window with the mouse.
        bool is_minimized;

        ComPtrWrapper<IDXGISwapChain> m_psSwapChain;
        ComPtrWrapper<ID3D11RenderTargetView> m_psRenderTargetView;
    };

}

#endif
