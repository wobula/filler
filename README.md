# filler - my first artificial intelligence
###### An epic, no holds barred battle between my first AI -- code named 'filler' -- and the 42 stock AIs.

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/0.png)

##### Game objectives and rules
 * If a player makes an invalid move, the game is over
 * The player with most board space at the end of the game is winner
 * Move syntax is 'x y' where x and why represent coordinates, followed by a newline
 * Players may use negative numbers for X,Y coordinate values
 * The asterisks of a piece must all be placed on the board or the move is invalid
 * The periods of a piece do not need to be on the board and can overlap any symbol
 * A move is valid if an asterisk overlays one (and only one) character piece already on the board
 * A move is invalid if a player piece overlays any of the opposing player's character

##### Instructions:
1.  "make"
2.  "./filler_vm -f maps/maps01 -p1 filler -p2 players/carli.filler"
3.  Observe. Repeat several times.
 * Try one of the other players/maps to see AI in different contexts

 My AI uses the 'X' character in the photos below:

 ## Input parsing:

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/1.png)
1.  Parse input for player, board, piece data.
2.  Validate all data
3.  Pass validated data to move-selector algorithm

## Algorithmic Strategy:

1.  Split the board in half
2.  Completely encircle the enemy
3.  Backfill leftover space

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/2.png)

1.  Split the board in half

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/3.png)

2.  Completely encircle the enemy

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/4.png)

3.  Backfill leftover space

4.  Offer humiliated/defeated AI spare change for bus fair back home to see crying mother

 * Win percentage is near 100% on the largest board size (greater than 75% on smallest map)
 * Checks positive and negative board X,Y values, depending on shape of piece