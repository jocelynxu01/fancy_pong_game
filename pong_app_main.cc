#include "pong_simulation_app.h"

using pong::SimplePongApp;

void prepareSettings(SimplePongApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(SimplePongApp, ci::app::RendererGl, prepareSettings);
