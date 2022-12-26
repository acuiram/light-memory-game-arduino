# light-memory-game-arduino

The game ‘Repeat the colors’ is a memory game. We have four colors (4 different colored LEDs) and four corresponding buttons, a start button and a button to set the difficulty of the game with a corresponding red LED  (that will stay turned on at the very beginning of the game to warn the player that he/she must choose the difficulty – a total of 10 levels ranging from one second between two consecutive LEDs that light up and 0.1 seconds which  corresponds to the hardest level). 

<br>After the desired difficulty was set, the start button will be pressed and the game will begin, the red LED will turn off, the current score will be displayed on the LCD, and updated after each round. The microcontroller will generate a sequence of random numbers whose length will increase after each correct round. The player will 
have to press the corresponding buttons (in order) with the way the LEDs lit up. After each correct round, all the LEDs will light up at once to let the player know that they pressed the buttons in the correct order, the score will  increase and be updated on the display and the game will continue. 

<br>When the player makes a mistake, the LEDs will light up from left to right, and blink, to warn the player  of their mistake, and the message ‘Game Over!’ will appear on the first line of the LCD, followed by ‘Score:  %player’s score’ on the second line. In this case, the game will reset and the red LED that warns the player to  choose the difficulty will light up again.

<br>**Notes:**
- If no button is pressed for five seconds, the microcontroller will execute the wrong sequence for the LEDs, and the game will be over. Also, if the player pressed start and no button is pressed at the beginning of the game, the same will happen, but the message ‘No input’ will be displayed on the second line of the LCD.
- If the player reaches the maxim length of one hundred, on the LCD the message ‘MAX LVL REACHED’ will be displayed and the game will reset as well.
- If the difficulty button is pressed one more time, when the difficulty is already set to ‘MAX’, it will return to the default value of one second, avoiding the speed between lights up to be zero and the game not to work.
- When a button is pressed, the corresponding LED will light up.
- Digital LOW will mean that a button was pressed

<br>**Electrical Diagram:**
<br>![image](https://user-images.githubusercontent.com/106117736/209582801-a5d61e91-e0d3-4b1a-8eee-2e6fa283d215.png)

<br>**Hardware Components:** 5 LEDs, 6 x press buttons, 6 x 1kohm resistors, 5 x 330ohm resistors, I2C LCD, Breadboard, Wires, Intel Galileo Gen. 2 Board

<br>**Layout:**
<br>![image](https://user-images.githubusercontent.com/106117736/209582864-c085e232-3f67-46bc-9c73-ac1831deff00.png)

