
#include "Simplex.h"


class SandboxApplication : public Simplex::Application {
    public:
    SandboxApplication() {

    }
    ~SandboxApplication() {

    }
};

Simplex::Application* Simplex::CreateApplication() {
    return new SandboxApplication();
}

