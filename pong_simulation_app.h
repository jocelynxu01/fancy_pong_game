#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pong_container.h"

namespace pong {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
    class SimplePongApp : public ci::app::App {
    public:
        SimplePongApp();

        void draw() override;
        void update() override;
        void keyDown(ci::app::KeyEvent event) override;

        // provided that you can see the entire UI on your screen.
        const int kWindowLimitVertical = 600;
        const int kWindowLimitHorizontal = 900;

    private:
        PongContainer container_ =
                PongContainer(vec2(450, 0), vec2(450, 600), vec2(0, 0),
                              vec2(kWindowLimitHorizontal, kWindowLimitVertical));
    };
}  // namespace idealgas

