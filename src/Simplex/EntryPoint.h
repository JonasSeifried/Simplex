//
// Created by Jonas Seifried on 08.11.25.
//

#pragma once

#if defined(SX_PLATFORM_WINDOWS) || defined(SX_PLATFORM_MACOS)

extern Simplex::Application* CreateApplication();

int main(int argc, char** argv) {
    Simplex::Log::Init();
    SX_CORE_WARN("Initialized Log!");
    SX_INFO("Hello");
    const auto app = Simplex::CreateApplication();
    app->Run();
    delete app;
}

#endif