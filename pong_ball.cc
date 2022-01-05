#include "../include/pong_ball.h"

namespace pong {

    using glm::vec2;

    PongBall::PongBall(glm::vec2 position, glm::vec2 velocity, float radius, ci::Color color)
            : position_(position), velocity_(velocity), radius_(radius), color_(color){}

    void PongBall::SetPosition(vec2 position) {
        position_ = position;
    }

    void PongBall::SetVelocity(vec2 velocity) {
        velocity_ = velocity;
    }

    vec2 PongBall::GetPosition() const {
        return position_;
    }

    vec2 PongBall::GetVelocity() const {
        return velocity_;
    }

    float PongBall::GetRadius() const {
        return radius_;
    }

    ci::Color PongBall::GetColor() const {
        return color_;
    }

    void PongBall::UpdatePosition()  {
        position_ += velocity_;
    }
}
