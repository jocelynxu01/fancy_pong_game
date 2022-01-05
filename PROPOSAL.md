# Final project proposal

For my final project, I want to build a simple 2D pong game.

Since I am not a gamer, there are only a few “games” I have played before. The Pong game is one of the games I know and downloaded on my phone. The pong game has pretty easy rules and it can be coded and presented through Cinder comparatively easily from my perspective. Throughout this semester, we have built a competition game (minopoly) and cinder-based project (ideal-gas simulation). Based on the knowledge I have about C++ and familiarity with Cinder, building a visualized pong game is kinda doable in my opinion (Hopefully).

From the website we know that “*We expect this project to take you about 3 weeks of development time in total, with each week requiring about as much work as one of our assignments*”, I have a rough plan for each week:

* Week 1: basic pong game. one robot and one player
    * Ball: position, velocity, radius, color
    * Logic: if the ball did not touch any board, it would just “fly out of the screen” and disappear, a new ball would be created.
    * Ball velocity: it changes after hitting the board (the width of the board is fixed, similar logic as hitting the wall)
    * Ball position = position + updated velocity (initial position would be randomized from the center - randomized y -value)
    * Player: length, width, starting position(left top corner), end position(right bottom corner)
    * Left one: the board will move up and down at a constant speed
    * Right one: the player can control the position with the up and down arrow key (keyDown)
* Week 2: 2 players mode, ball acceleration, and test cases
    * Player2: keyUp and keyDown
    * Player2: w and s
    * make sure velocity changes as the key is pressed even if it happens at the same time
    * the velocity of the ball would increase as time goes on
    * Freeze the page when somebody gets 10 points (ending page for now)
* Week 3: player can choose how many balls to start with.

If I were able to finish the entire final project earlier, I will probably make a starting page and a fancy ending page, I believe they would just require extra work building on the cinder algorithm, and hopefully they can be done within a short amount of time.

