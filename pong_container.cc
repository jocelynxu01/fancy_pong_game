#include "cinder/Rand.h"
#include "../include/pong_container.h"
#include <string>

namespace pong {
    
using glm::vec2;
using std::string;

PongContainer::PongContainer(vec2 middle_line_top, vec2 middle_line_bottom, vec2 lower_bound, vec2 upper_bound) :
        middle_line_top_(middle_line_top), middle_line_bottom_(middle_line_bottom), lower_bound_(lower_bound), upper_bound_(upper_bound) {
    test_ = false;
    InitializeBall();
    InitializePlayers();
}

PongContainer::PongContainer(vec2 middle_line_top, vec2 middle_line_bottom, vec2 lower_bound, vec2 upper_bound, bool test):
        middle_line_top_(middle_line_top), middle_line_bottom_(middle_line_bottom), lower_bound_(lower_bound), upper_bound_(upper_bound), test_(test){
    InitializeBall();
    InitializePlayers();
}

void PongContainer::Display() const {
    if (starting_page_) {
        ci::gl::drawString(welcome_page_, vec2(60, 230), "white", ci::Font("Helvetica", 75));
        ci::gl::drawString(start_game_one_, vec2(200, 300), "white", ci::Font("Helvetica", 40));
        ci::gl::drawString(start_game_two_, vec2(190, 328), "white", ci::Font("Helvetica", 40));
    } else {
        if (!has_won_ && !has_lost_) {
            //middle line
            ci::gl::color(ci::Color("white"));
            ci::gl::drawLine(middle_line_top_, middle_line_bottom_);
            
            if (one_player_) {
                //robot paddle && score
                ci::gl::color(ci::Color(robot_.GetColor()));
                ci::gl::drawSolidRect(ci::Rectf(robot_.GetLeftCorner(), robot_.GetRightCorner()));
                ci::gl::drawString(std::to_string(robot_.GetScore()), vec2(360, 40), "white", ci::Font("Helvetica", 50));
            } else {
                //player two && score
                ci::gl::color(ci::Color(player_two_.GetColor()));
                ci::gl::drawSolidRect(ci::Rectf(player_two_.GetLeftCorner(), player_two_.GetRightCorner()));
                ci::gl::drawString(std::to_string(player_two_.GetScore()), vec2(360, 40), "white", ci::Font("Helvetica", 50));
            }
            
            //player paddle && score
            ci::gl::color(ci::Color(player_.GetColor()));
            ci::gl::drawSolidRect(ci::Rectf(player_.GetLeftCorner(), player_.GetRightCorner()));
            ci::gl::drawString(std::to_string(player_.GetScore()), vec2(510, 40), "white", ci::Font("Helvetica", 50));

            //ball
            ci::gl::color(ci::Color(ball_.GetColor()));
            ci::gl::drawSolidCircle(ball_.GetPosition(), ball_.GetRadius());
        } else if (has_won_) {
            ci::gl::drawString(winning_state_, vec2(30, 230), "white", ci::Font("Helvetica", 75));
            ci::gl::drawString(restart_game_, vec2(210, 300), "white", ci::Font("Helvetica", 40));
        } else if(has_lost_) {
            ci::gl::drawString(losing_state_, vec2(27, 230), "white", ci::Font("Helvetica", 65));
            ci::gl::drawString(restart_game_, vec2(210, 300), "white", ci::Font("Helvetica", 40));
        }
    }
}

void PongContainer::AdvanceOneFrame() {
    CheckWinningCondition();
    if (test_) {
        KeepBoardWithinContainer(robot_);
        robot_.UpdatePosition();
        CalculateBallVelocity();
        ball_.UpdatePosition();
        return;
    }
    if (! has_won_ && ! has_lost_ && !starting_page_) {
        //players
        if (one_player_) {
            KeepBoardWithinContainer(robot_);
            robot_.UpdatePosition();
            player_.UpdatePosition();
            player_.SetVelocity(vec2(0, 0));
        } else {
            player_two_.UpdatePosition();
            player_.UpdatePosition();
            player_.SetVelocity(vec2(0, 0));
            player_two_.SetVelocity(vec2(0, 0));
        }
        //ball
        CalculateBallVelocity();
        ball_.UpdatePosition();
    }
}

void PongContainer::ControlBoardToGoUpPlayerOne() {
    vec2 new_velocity = vec2(0, -10);
    if (player_.GetLeftCorner().y == lower_bound_.y) {
        new_velocity = vec2(0, 0);
    }
    player_.SetVelocity(new_velocity);
}

void PongContainer::ControlBoardToGoDownPlayerOne() {
    vec2 new_velocity =  vec2(0, 10);
    if (player_.GetRightCorner().y == upper_bound_.y) {
        new_velocity = vec2(0, 0);
    }
    player_.SetVelocity(new_velocity);
    
}

void PongContainer::ControlBoardToGoUpPlayerTwo() {
    vec2 new_velocity = vec2(0, -10);
    if (player_two_.GetLeftCorner().y == lower_bound_.y) {
        new_velocity = vec2(0, 0);
    }
    player_two_.SetVelocity(new_velocity);
}

void PongContainer::ControlBoardToGoDownPlayerTwo() {
    vec2 new_velocity =  vec2(0, 10);
    if (player_two_.GetRightCorner().y == upper_bound_.y) {
        new_velocity = vec2(0, 0);
    }
    player_two_.SetVelocity(new_velocity);

}

void PongContainer::RestartGame() {
    has_lost_ = false;
    has_won_ = false;
    InitializeBall();
    InitializePlayers();
}


void PongContainer::StartGameOnePlayer() {
    starting_page_ = false;
    one_player_ = true;
    robot_.SetScore(0);
    player_.SetScore(0);
    InitializeBall();
}

void PongContainer::StartGameTwoPlayers() {
    starting_page_ = false;
    one_player_ = false;
    player_two_.SetScore(0);
    player_.SetScore(0);
    InitializeBall();
}

PongBall PongContainer::GetBall() {
    return ball_;
}

PongPlayer PongContainer::GetPlayer() {
    return player_;
}

//private methods
void PongContainer::KeepBoardWithinContainer(PongPlayer& player) const {
    vec2 player_left_top_corner = player.GetLeftCorner();
    vec2 player_right_bottom_corner = player.GetRightCorner();
    if (player_left_top_corner.y == lower_bound_.y || player_right_bottom_corner.y == upper_bound_.y) {
        vec2 player_velocity = player.GetVelocity();
        player_velocity *= vec2(1,-1);
        player.SetVelocity(player_velocity);
    }
}

void PongContainer::InitializeBall() {
    if (test_) {
        ball_.SetPosition(vec2(450, 300));
        vec2 starting_velocity = vec2(3, 0);
        ball_.SetVelocity(starting_velocity);
    } else if (start_with_player_two_) {
        ball_.SetPosition(vec2(450, 300));
        vec2 starting_velocity = vec2(-3, cinder::randFloat(-2, 2));
        ball_.SetVelocity(starting_velocity);
    } else if (!start_with_player_two_){
        ball_.SetPosition(vec2(450, 300));
        vec2 starting_velocity = vec2(3, cinder::randFloat(-2, 2));
        ball_.SetVelocity(starting_velocity);
    }
}

void PongContainer::InitializePlayers() {
    if (test_ || one_player_) {
        robot_.SetScore(0);
        robot_.SetLeftCorner(kRobotStartingPointLeft);
        robot_.SetRightCorner(kRobotStartingPointRight); 
    } else {
        player_two_.SetScore(0);
        player_two_.SetLeftCorner(kRobotStartingPointLeft);
        player_two_.SetRightCorner(kRobotStartingPointRight);
    }
    player_.SetScore(0);
    player_.SetLeftCorner(kPlayerStartingPointLeft);
    player_.SetRightCorner(kPlayerStartingPointRight);
}

void PongContainer::CalculateBallVelocity() {
    vec2 ball_position = ball_.GetPosition();
    CalculateABallVelocityHittingToTheRight(ball_position);
    CalculateABallVelocityHittingToTheLeft(ball_position);
    CalculateABallVelocityHittingToTheTop(ball_position);
    CalculateABallVelocityHittingToTheBottom(ball_position);
}

void PongContainer::CheckWinningCondition() {
    if (player_.GetScore() == 10) {
        has_won_ = true;
    }
    if (robot_.GetScore() == 10 || player_two_.GetScore() ==10) {
        has_lost_ = true;
    }
}

void PongContainer::CalculateABallVelocityHittingToTheRight(vec2 ball_position) {
    if (ball_position.x + ball_.GetRadius() >= kPlayerStartingPointLeft.x) {
        if (ball_position.y >= player_.GetLeftCorner().y && ball_position.y <= player_.GetRightCorner().y) {
            vec2 ball_velocity = ball_.GetVelocity();
            ball_velocity *= vec2(-1,1);
            ball_velocity *= vec2(1.1, 1.1);
            ball_.SetVelocity(ball_velocity);
        } else if (ball_position.x + ball_.GetRadius() >= kPlayerStartingPointRight.x) {
            start_with_player_two_ = true;
            InitializeBall();
            if (one_player_) {
                robot_.UpdateScore();
            } else {
                player_two_.UpdateScore();
            }
        }
    }
}
    
void PongContainer::CalculateABallVelocityHittingToTheLeft(vec2 ball_position) {
    if (one_player_) {
        if (ball_position.x - ball_.GetRadius() <= kRobotStartingPointRight.x) {
            if (ball_position.y >= robot_.GetLeftCorner().y && ball_position.y <= robot_.GetRightCorner().y) {
                vec2 ball_velocity = ball_.GetVelocity();
                ball_velocity *= vec2(-1,1);
                ball_velocity *= vec2(1.1, 1.1);
                ball_.SetVelocity(ball_velocity);
            } else  if (ball_position.x - ball_.GetRadius() <= kRobotStartingPointLeft.x) {
                start_with_player_two_ = false;
                InitializeBall();
                player_.UpdateScore();
            }
        }
    } else {
        if (ball_position.x - ball_.GetRadius() <= kRobotStartingPointRight.x) {
            if (ball_position.y >= player_two_.GetLeftCorner().y && ball_position.y <= player_two_.GetRightCorner().y) {
                vec2 ball_velocity = ball_.GetVelocity();
                ball_velocity *= vec2(-1,1);
                ball_velocity *= vec2(1.1, 1.1);
                ball_.SetVelocity(ball_velocity);
            } else  if (ball_position.x - ball_.GetRadius() <= kRobotStartingPointLeft.x) {
                start_with_player_two_ = false;
                InitializeBall();
                player_.UpdateScore();
            }
        }
    }
}

void PongContainer::CalculateABallVelocityHittingToTheTop(vec2 ball_position) {
    if (ball_position.y - ball_.GetRadius() <= lower_bound_.y ) {
        vec2 ball_velocity = ball_.GetVelocity();
        ball_velocity *= vec2(1, -1);
        ball_velocity *= vec2(1.1, 1.1);
        ball_.SetVelocity(ball_velocity);
    }
}

void PongContainer::CalculateABallVelocityHittingToTheBottom(vec2 ball_position) {
    if (ball_position.y + ball_.GetRadius() >= upper_bound_.y ) {
        vec2 ball_velocity = ball_.GetVelocity();
        ball_velocity *= vec2(1, -1);
        ball_velocity *= vec2(1.1, 1.1);
        ball_.SetVelocity(ball_velocity);
    }
}

}
