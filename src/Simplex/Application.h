//
// Created by Jonas Seifried on 08.11.25.
//

#pragma once
#include "include/simplex/export.h"

namespace Simplex {
    class SIMPLEX_EXPORT Application {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined by Client
    Application* CreateApplication();
} // Simplex
