#ifndef PONG_PONG_PARTICLE_H
#define PONG_PONG_PARTICLE_H
#include "cinder/gl/gl.h"

using glm::vec2;

namespace pong {

    class PongBall{

    public:
        /**
         * Set the position, velocity, radius, and color for the ball.
         * @param position the position of the ball
         * @param velocity the velocity of the ball
         * @param radius the radius of the ball
         * @param color the color of the ball
         */
        PongBall(vec2 position, vec2 velocity, float radius, ci::Color color);

        /**
         * @param position the position vector of the ball
         */
        void SetPosition(vec2 position);

        /**
       * @param velocity the velocity vector of the ball
       */
        void SetVelocity(vec2 velocity);

        /**
         *
         * @return the current position of the ball
         */
        vec2 GetPosition() const;

        /**
         *
         * @return the current velocity of the ball
         */
        vec2 GetVelocity() const;

        /**
         *
         * @return the radius of the ball
         */
        float GetRadius() const;

        /**
         * @return the color of the ball
         */
        ci::Color GetColor() const;

        /**
         * Update the position of the ball.
         */
        void UpdatePosition();

    private:
        vec2 position_;
        vec2 velocity_;
        float radius_;
        ci::Color color_;
    };
}

#endif //PONG_PONG_PARTICLE_H
