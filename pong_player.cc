#include "../include/pong_player.h"

namespace pong {

    using glm::vec2;

    PongPlayer::PongPlayer(vec2 left_top_corner, vec2 right_bottom_corner, vec2 velocity, ci::Color color, int score)
            : left_top_corner_(left_top_corner), right_bottom_corner_(right_bottom_corner), velocity_(velocity), color_(color), score_(score){}

    int PongPlayer::GetScore() const {
        return score_;
    }

    vec2 PongPlayer::GetLeftCorner() const {
        return left_top_corner_;
    }

    vec2 PongPlayer::GetRightCorner() const {
        return right_bottom_corner_;
    }

    vec2 PongPlayer::GetVelocity() const {
        return velocity_;
    }

    ci::Color PongPlayer::GetColor() const {
        return color_;
    }

    void PongPlayer::SetScore(int score) {
        score_ = score;
    }

    void PongPlayer::SetLeftCorner(vec2 left_corner) {
        left_top_corner_ = left_corner;
    }

    void PongPlayer::SetRightCorner(vec2 right_corner) {
        right_bottom_corner_ = right_corner;
    }

    void PongPlayer::SetVelocity(vec2 velocity) {
        velocity_ = velocity;
    }

    void PongPlayer::UpdatePosition()  {
        left_top_corner_ += velocity_;
        right_bottom_corner_ += velocity_;
    }

    void PongPlayer::UpdateScore() {
        score_ = score_ + 1;
    }

}