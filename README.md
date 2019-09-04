# Langston's Ant
This Langton's Ant simulation allows the player to choose the specifications of the board and ant. 

If the ant lands on a white (#) square, it will turn 90° right, flip the color of the square to black (blank), and move forward one unit. It the ant lands on a black square, it will turn 90° left, flip the color of the square to white, and move forward one unit.

To learn more about the Langston's Ant simulation, visit the [wikipedia page](https://en.wikipedia.org/wiki/Langton%27s_ant).

## Usage
The main menu allows the player to choose to play the game or quit.

![photo1](/screenshots/photo1.GIF)

If the player decides to play, they may select the number of rows and columns for the board, the start row, column, and direction for the ant, and the total number of steps.

![photo2](/screenshots/photo2.GIF)

Once the parameters are chosen, the player hits "Enter" to make the ant move until the steps are exhausted. The row, column, orientation, and remaining steps are tracked during each iteration.

![photo3](/screenshots/photo3.GIF)

When the simulation is complete, the player is returned to the main menu.

## Deployment
To deploy and play, please use the makefile.

## Built With
* C++

## Contributing
This project is closed to contributions at this time.

## Authors
Jennifer K. Ludwig

