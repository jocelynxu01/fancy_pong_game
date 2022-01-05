#ifndef PONG_PONG_PLAYER_H
#define PONG_PONG_PLAYER_H
#include "cinder/gl/gl.h"

using glm::vec2;

namespace pong {

    class PongPlayer{

    public:
        /**
         * Set the position, velocity, score, and color for the player.
         * @param position the position of the player
         * @param velocity the velocity of the player
         * @param color the color of the player
         */
        PongPlayer(vec2 left_top_corner, vec2 right_bottom_corner, vec2 velocity, ci::Color color, int score);

        /**
         * 
         * @return the score of the player
         */
        int GetScore() const;

        /**
         *
         * @return the current left top corner vector
         */
        vec2 GetLeftCorner() const;
        
        /**
         * 
         * @return the current right bottom corner vector
         */
        vec2 GetRightCorner() const;
        
        /**
         *
         * @return the current velocity of the particle as a vector
         */
        vec2 GetVelocity() const;

        /**
         * @return the color of the particle
         */
        ci::Color GetColor() const;
        
        /**
         * 
         * @param score the score of the player
         */
        void SetScore(int score);

        /**
         * 
         * @param left_corner the position of the left top corner
         */
        void SetLeftCorner(vec2 left_corner);

        /**
         * 
         * @param right_corner the position of the right bottom corner
         */
        void SetRightCorner(vec2 right_corner);

        /**
       * @param velocity the velocity vector of the particle
       */
        void SetVelocity(vec2 velocity);
        
        /**
         * Update the score by 1.
         */
        void UpdateScore();

        /**
         * Update the position of the particle.
         */
        void UpdatePosition();

    private:
        vec2 left_top_corner_;
        vec2 right_bottom_corner_;
        vec2 velocity_;
        ci::Color color_;
        int score_;
    };
}
#endif //PONG_PONG_PLAYER_H
