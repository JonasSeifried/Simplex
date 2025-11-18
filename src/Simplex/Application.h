//
// Created by Jonas Seifried on 08.11.25.
//

#pragma once

#include "Simplex/Core.h"
#include "Window.h"

namespace Simplex {
    class SIMPLEX_EXPORT Application {
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined by Client
    Application* CreateApplication();
} // Simplex
