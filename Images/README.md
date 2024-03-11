# Images
The images in this project are plain text files, with their contents sized to fit one of the 3 viewports: Main, Log and User command.

In general, only the Main and User command viewports will be overwritten.

## Viewports
~~~
____________________________________________________________________________________
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                   MAIN VIEWPORT                         ||    LOGS VIEWPORT      |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|                                                         ||                       |
|_________________________________________________________||_______________________|
____________________________________________________________________________________
|                                                                                  |
|                                USER COMMANDS VIEWPORT                            |
|__________________________________________________________________________________|


~~~
### Main
The main viewport is a 60x21 block of text. It should be used to display the things that are happening in-game.

### User commands
The user commands viewport is a 85x4 block of text. It should be used to display the commands a user can take at any given moment.

### Log
The log viewport is a 26x21 block of text. It should be managed by the output system to display relevant logs.