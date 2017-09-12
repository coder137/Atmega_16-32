#ifndef _KEYPAD_H
#define _KEYPAD_H

/*
"""
NOTE: rows are horizontal, columns are vertical
"""
*/
/*
1. We make the columns input(HIGH) and rows output(LOW)
2. We read the columns value and store it in columns
3. We make the columns output(LOW) and rows input(HIGH)
4. We read the rows value and store it in rows
5. We define a ret variable and return (columns|rows)
*/
unsigned char keypadScan();

/*
1. We check if button is pressed
2. We get the keypad data, [dat = keypadScan()]
3. We check if the button is released
4. Then we return the data
*/
unsigned char getKeypadData();

/*
1. If any Keypad button is pressed return 1
2. If Keypad button is not pressed then return 0
*/
//DEPRECEATED
//unsigned char buttonState();

unsigned char buttonValue(unsigned char);

//1 if button is pressed
//0 if button is not pressed
unsigned char buttonState();

#endif