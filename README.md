# filler
###### my first artificial intelligence

An epic, no holds barred battle between my AI -- code named 'filler' -- and the 42 School stock AIs.

## Input parsing:
Instructions:
1.  "make"
2.  "./filler_vm -f maps/maps01 -p1 filler -p2 players/carli.filler"
3.  Observe. Repeat several times.
 * Try one of the other players/maps to see AI in different contexts

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/img1.png)

## Algorithmic Strategy:
1.  Split the board in half

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/img2.png)

2.  Completely encircle the enemy

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/img3.png)

3.  Backfill leftover space

![Input Content](https://raw.githubusercontent.com/wobula/filler/master/img4.png)

4.  Offer humiliated/defeated AI bus fair back home to see crying mother
 * Win percentage is near 100% on the largest board size (greater than 75% on smallest map)
 * Checks positive and negative board X,Y values, depending on shape of piece