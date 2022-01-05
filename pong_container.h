#ifndef PONG_PONG_CONTAINER_H
#define PONG_PONG_CONTAINER_H

#include "cinder/gl/gl.h"
#include "../include/pong_player.h"
#include "../include/pong_ball.h"
#include <vector>

using glm::vec2;

namespace pong {
    
class PongContainer {
    
public:
    /**
     * Normal constructor which contains information about the middle line and the edges of the container.
     * @param middle_line_top the vector of the top middle line
     * @param middle_line_bottom the vector of the bottom middle line
     * @param lower_bound the left corner of the container
     * @param upper_bound the right bottom corner of the container
     */
    PongContainer(vec2 middle_line_top, vec2 middle_line_bottom, vec2 lower_bound, vec2 upper_bound);

    /**
     * Testing constructor which contains information about the middle line and the edges of the container.
     * @param middle_line_top the vector of the top middle line
     * @param middle_line_bottom the vector of the bottom middle line
     * @param lower_bound the left corner of the container
     * @param upper_bound the right bottom corner of the container
     * @param test whether I am testing or not.
     */
    PongContainer(vec2 middle_line_top, vec2 middle_line_bottom, vec2 lower_bound, vec2 upper_bound, bool test);
    /**
   * Displays the container walls and the current positions of the particles.
   */
    void Display() const;

    /**
     * Updates the positions and velocities of all particles (based on the rules
     * described in the assignment documentation).
     */
    void AdvanceOneFrame();

    /**
     * Control the player to go up.
     */
    void ControlBoardToGoUpPlayerOne();
    
    /**
     * Control the player to go down.
     */
    void ControlBoardToGoDownPlayerOne();

    /**
 * Control the player to go up.
 */
    void ControlBoardToGoUpPlayerTwo();

    /**
     * Control the player to go down.
     */
    void ControlBoardToGoDownPlayerTwo();
    
    /**
     * Restart the game.
     */
    void RestartGame();
    
    /**
     * Set information for the one player mode.
     */
    void StartGameOnePlayer();

    /**
     * Set information for the two players mode.
     */
    void StartGameTwoPlayers();
    
    /**
     * 
     * @return ball information
     */
    PongBall GetBall();
    
    /**
     * 
     * @return player one information
     */
    PongPlayer GetPlayer();
    
private:
    vec2 middle_line_top_;
    vec2 middle_line_bottom_;
    vec2 lower_bound_;
    vec2 upper_bound_;
    vec2 kRobotStartingPointLeft = vec2(0, 260);
    vec2 kRobotStartingPointRight = vec2(20, 340);
    vec2 kRobotVelocity = vec2(0, 5);
    vec2 kPlayerStartingPointLeft = vec2(880, 260);
    vec2 kPlayerStartingPointRight = vec2(900, 340);
    PongPlayer robot_ = PongPlayer(kRobotStartingPointLeft, kRobotStartingPointRight, kRobotVelocity, "white", 0 );
    PongPlayer player_ = PongPlayer(kPlayerStartingPointLeft, kPlayerStartingPointRight, vec2(0, 0), "pink", 0);
    PongPlayer player_two_ = PongPlayer(kRobotStartingPointLeft, kRobotStartingPointRight, vec2(0, 0), "green", 0);
    PongBall ball_ = PongBall(vec2(0, 0), vec2(0, 0), 10, "yellow");
    bool has_won_ = false;
    bool has_lost_ = false;
    bool starting_page_ = true;
    bool one_player_ = true;
    bool start_with_player_two_ = false;
    bool test_ = false;
    std::string winning_state_ = "Congratulations!! You just won!!";
    std::string losing_state_ = "Oh No! Can't Believe that you just lost!!";
    std::string restart_game_ = "tap space to restart the game:)";
    std::string welcome_page_ = "Welcome to the pong world!!!";
    std::string start_game_one_ = "Press '1' to start the one player game:)";
    std::string start_game_two_ = "Press '2' to start the two players game:)";

    /**
     * Keep the board within the boundary.
     * @param player which player I am talking about
     */
    void KeepBoardWithinContainer(PongPlayer& player) const;
    
    /**
     * Initialize the velocity and position of the ball.
     */
    void InitializeBall();
    
    /**
     * Initialize velocity, position, and score of the players.
     */
    void InitializePlayers();
    
    /**
     * Calculate the change of velocity of the ball for certain conditions.
     */
    void CalculateBallVelocity();
    
    /**
     * Determine whether the player is winning or losing.
     */
    void CheckWinningCondition();
    
    /**
     * Calculate ball velocity when hitting to the right edge.
     * @param ball_position the current position of the ball
     */
    void CalculateABallVelocityHittingToTheRight(vec2 ball_position);

    /**
     * Calculate ball velocity when hitting to the left edge.
     * @param ball_position the current position of the ball
     */
    void CalculateABallVelocityHittingToTheLeft(vec2 ball_position);

    /**
     * Calculate ball velocity when hitting to the top edge.
     * @param ball_position the current position of the ball
     */
    void CalculateABallVelocityHittingToTheTop(vec2 ball_position);

    /**
     * Calculate ball velocity when hitting to the bottom edge.
     * @param ball_position the current position of the ball
     */
    void CalculateABallVelocityHittingToTheBottom(vec2 ball_position);
};    
}
#endif //PONG_PONG_CONTAINER_H
