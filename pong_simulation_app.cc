#include "pong_simulation_app.h"

namespace pong {

    SimplePongApp::SimplePongApp() {
        ci::app::setWindowSize(kWindowLimitHorizontal, kWindowLimitVertical);
    }
 
    void SimplePongApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        container_.Display();
    }

    void SimplePongApp::update() {
        container_.AdvanceOneFrame();
    }
    
    void SimplePongApp::keyDown(ci::app::KeyEvent event) {
        if( event.getCode() == ci::app::KeyEvent::KEY_UP ) {
            container_.ControlBoardToGoUpPlayerOne();
        } 
        if (event.getCode() == ci::app::KeyEvent::KEY_DOWN) {
            container_.ControlBoardToGoDownPlayerOne();
        } 
        if (event.getCode() == ci::app::KeyEvent::KEY_SPACE) {
            container_.RestartGame();
        } 
        if (event.getChar() == '1') {
            container_.StartGameOnePlayer();
        } 
        if (event.getChar() == '2') {
            container_.StartGameTwoPlayers();
        } 
        if (event.getChar() == 'w') {
            container_.ControlBoardToGoUpPlayerTwo();
        } 
        if (event.getChar() == 's') {
            container_.ControlBoardToGoDownPlayerTwo();
        }
        if (event.getChar() == 'e') {
            //easy mode - one ball
        }
        if (event.getChar() == 'h') {
            container_.ControlBoardToGoDownPlayerTwo();
            //hard mode - two balls
        }
    }

}  // namespace idealgas

