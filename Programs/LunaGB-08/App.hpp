#pragma once
#include <Luna/RHI/Device.hpp>
#include "Emulator.hpp"
#include <Luna/Runtime/UniquePtr.hpp>
#include "DebugWindow.hpp"
using namespace Luna;

struct App
{
    //! `true` if the application is exiting. For example, if the user presses the close
    //! button of the window.
    bool is_exiting;

    //! The RHI device used to render interfaces.
    Ref<RHI::IDevice> rhi_device;
    //! The graphics queue index.
    u32 rhi_queue_index;

    //! The application main window.
    Ref<Window::IWindow> window;
    //! The application main window swap chain.
    Ref<RHI::ISwapChain> swap_chain;
    //! The command buffer used to submit draw calls.
    Ref<RHI::ICommandBuffer> cmdbuf;

    //! The emulator instance.
    UniquePtr<Emulator> emulator;
    //! The ticks for last frame.
    u64 last_frame_ticks;

    //! The debug window context.
    DebugWindow debug_window;

    //! Render resources.
    Ref<RHI::ITexture> emulator_display_tex;
    Ref<RHI::IBuffer> emulator_display_ub;
    Ref<RHI::IBuffer> emulator_display_vb;
    Ref<RHI::IBuffer> emulator_display_ib;
    Ref<RHI::IDescriptorSetLayout> emulator_display_dlayout;
    Ref<RHI::IDescriptorSet> emulator_display_desc_set;
    Ref<RHI::IPipelineLayout> emulator_display_playout;
    Ref<RHI::IPipelineState> emulator_display_pso;

    RV init();
    RV init_render_resources();
    RV update();
    ~App();

    RV draw_emulator_screen(RHI::ITexture* back_buffer);
    void draw_gui();
    void draw_main_menu_bar();

    void open_cartridge();
    void close_cartridge();
};

extern App* g_app;