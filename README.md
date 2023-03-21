# AERSP424Project
space for the AERSP 424 computer project source and header files, as well as other documentation

the project will contain one .cpp file: airraid.cpp
three header files: gamemanager.h, bomber.h, fighter.h
game board will display horizontally with aircraft moving from left to right 
game board will be 16 squares long, 7 squares wide, 1 square tall (no z dimension)
aircraft will spawn in entirely with the last square it occupies at the 0th row
board coordinates will be defined with a letter-number combination, with A0 being the corner

class definitions:

gameboard - needs container that holds grid values
gamemanager - determines if game has started or ended, updates board as turns progress, and determines gameflow
gamemanager - responsible for aircraft spawn, keeping score, and 
gamemanager is responsible for the moving parts. static pieces such as gameboard and the aircraft classes have their own files
 
there will be a randomizer attacking class which will define where the first aircraft spawns. 

gameboard will print a blank grid initially. the random start position will be defined. this information will pass from gameboard to attacker to gamemanager back to gameboard, and will output again.
 


 game board design as of 3/21/23
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
|| | | | | | | | | | | | | | | | || A                                    
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+| 
|| | | | | | | | | | | | | | | | || B                                  
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
|| | | | | | | | | | | | | | | | || C                                   
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+| 	
|| | | | | | | | | | | | | | | | || D   Defender                                
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
|| | | | | | | | | | | | | | | | || E                                   
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
| | | | | | | | | | | | | | | | || F          
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+| 
|| | | | | | | | | | | | | | | | || G
|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
  0 1 2 3 4 5 6 7 8 9 1 1 1 1 1 1 end
 	                    0 1 2 3 4 5




# FUTURE WORK
# 
