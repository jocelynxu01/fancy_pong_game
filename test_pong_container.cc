#include <catch2/catch.hpp>

#include <pong_container.h>

using pong::PongContainer;
using pong::PongBall;

TEST_CASE("Testing valid gaming system") {
    SECTION("Ball would bounce off after touching the edges") {
        PongContainer container = PongContainer(vec2(450, 0), vec2(450, 600),
                                                vec2(0, 0),vec2(900, 600), true);
        float original_velocity = container.GetBall().GetVelocity().x;
        for (size_t times = 0; times < 141; times++) {
            container.AdvanceOneFrame();

        }
        REQUIRE(original_velocity == 3);
        REQUIRE(container.GetBall().GetVelocity().x == Approx(-3.3f));
    }

    SECTION("Ball has acceleration") {
        PongContainer container = PongContainer(vec2(450, 0), vec2(450, 600),
                                                vec2(0, 0),vec2(900, 600), true);
        float original_velocity = container.GetBall().GetVelocity().x;
        for (size_t times = 0; times < 141; times++) {
            container.AdvanceOneFrame();

        }
        REQUIRE(original_velocity + container.GetBall().GetVelocity().x == Approx(-0.3f));
    }

    SECTION("Update Score") {
        PongContainer container = PongContainer(vec2(450, 0), vec2(450, 600),
                                                vec2(0, 0),vec2(900, 600), true);
        for (size_t times = 0; times < 402; times++) {
            container.AdvanceOneFrame();

        }
        REQUIRE(container.GetPlayer().GetScore() == 1);
    }
}

