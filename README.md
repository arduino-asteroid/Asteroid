# Asteroid

## Project

![alt text](documentation/asteroid_game.png "Game image")

Our project consist in a wifi controller for the famous game Asteroid !

The game is about surviving among asteroids destroying the most we can.

In this Game, the user's actions are :

* Go forward
* Rotate on the left
* Rotate on the right
* Fire some lasers

We thought that was all kind of actions we could match with an accelerometer.


That is why we decided to create our own controller !


## The controller

### Components

* Accelerometer : GY-521
* Wifi module : ESP8266 WeMos D1 mini
* Push button

### Role

The main role of our controller is to be able, with it's accelerometer, to detect the X ans Z angles in order to hanfdle going forward and rotating.

We also added a Push Button in order to handle the differents clicks in the Game and to fire lasers.

### Controller historic

At first, we had to weld the push button with wire

![alt text](documentation/push_button.jpg "Push button image")

Then we experimented the button by just linking it to the wemos.

![alt text](documentation/push_to_wemos.jpg "Push button on wemos")

After that, we decided to use a suction cup in order to be able to play with the accelerometer like if it was a joystick.

So we had to find a way to put the button on it.

![alt text](documentation/button_on_joystick.jpg "button on joystick")

Finally, We had to put the wemos in a certain position in order to be sure that the accelerometerr would send the right informations to the game.

So we had to think about a way to fix the wemos to the suction cup.

We went for a gobelet and.... TADA !

![alt text](documentation/gobelet.jpg "Gobelet image")

![alt text](documentation/goblet_fix_on_stick.jpg "Push button image")







