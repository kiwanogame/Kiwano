// Copyright (c) 2016-2018 Kiwano - Nomango
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <kiwano/render/Renderer.h>
#include <kiwano/event/WindowEvent.h>

namespace kiwano
{

Renderer::Renderer()
    : vsync_(true)
    , auto_reset_resolution_(true)
    , clear_color_(Color::Black)
{
}

void Renderer::SetClearColor(const Color& color)
{
    clear_color_ = color;
}

void Renderer::SetVSyncEnabled(bool enabled)
{
    vsync_ = enabled;
}

void Renderer::ResetResolutionWhenWindowResized(bool enabled)
{
    auto_reset_resolution_ = enabled;
}

void Renderer::Destroy()
{
    FontCache::GetInstance().Clear();
}

void Renderer::HandleEvent(EventModuleContext& ctx)
{
    if (auto_reset_resolution_)
    {
        auto evt = ctx.evt->Cast<WindowResizedEvent>();
        if (evt)
        {
            auto size = evt->window->GetLogicalSize();
            Resize((uint32_t)size.x, (uint32_t)size.y);
        }
    }
}

}  // namespace kiwano
