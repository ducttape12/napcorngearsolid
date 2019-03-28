// Program:			Napcorn Gear Solid
// Program I.D.:	ngs.cpp
// Written by:		Keith Ott
//						Some humor by: Chris Connar
// Date due:		Friday, June 6, 2003

// Purpose:
// This program is a parody of the popular Komani game, Metal Gear Solid.  The
// user plays a Morris Chestnut, going through many rooms trying to find the
// Napcorn Horde.  Controls are as follows:

//          I = Up
// J = Left        L = Right
//         K = Down

// More information on the game is detailed in functions.

// This game made possible by Nap Co. and Napcorn Industries of America.
// http://napcorn.tripod.com



// Metal Gear Solid
// Copyright 1998 Konami of America, Inc.

// *****************************************************************************

// Complier directives
#include <iostream.h>			// Standard I/O
#include "apmatrix.h"			// For two-dimention arrays - used to hold the
										// mazes
#include <fstream.h>				// For file I/O
#include <conio.h>				// For gotoxy and getting keys
#include "apstring.h"			// For strings
#include <time.h>					// For delay

// -----------------------------------------------------------------------------

	// Program Function prototypes
	// ---------------------------
	// Displays the title
	// ACCEPTS: nothing
	// RETURNS: nothing
	void DisplayTitle(void);

	// Displays the Codec screen and flash (CALL) on the screen
	// ACCEPTS: nothing
	// RETURNS: nothing
	void DisplayCodec(void);

	// Starts a new game
	// ACCEPTS: nothing
	// RETURNS: nothing
	void NewGame(void);

	// Returns the value of the X and the Y from the set of levels
	// ACCEPTS: the level to get, the X of the level, the Y of the level
	// RETURNS: what is at that place of the level
	char LevelPart(int CurrentLevel, int X, int Y);

	// Displays the map and the HUD
	// ACCEPTS: the level and the current level
	// RETURNS: nothing
	void DisplayMap(apmatrix <char> Level, int CurrentLevel);

	// Delays for x number of seconds
	// ACCEPTS: the number of seconds
	// RETURNS: nothing
	void Delay(float Seconds);

	// Simulates text being typed to the screen
	// ACCEPTS: the text to be "typed"
	// RETURNS: nothing
	void TypeText(apstring String);

	// Clears off any text left from the codec, but leaves the graphic
	// ACCEPTS: nothing
	// RETURNS: nothing
	void TextClear(void);

	// Displays the instructions to the game
	// ACCEPTS: nothing
	// RETURNS: nothing
	void Instructions(void);

// *****************************************************************************

// Main program function
int main()
{
	// Declare variables
	// -----------------
	char MenuChoice;							// The user's choice on which menu option
													// to use

// -----------------------------------------------------------------------------

	// Entrance
	clrscr();

	gotoxy(19,12);
	cout << "Napcorn Industries of America Presents";

	Delay(5);

	clrscr();

	gotoxy(30,12);
	cout << "A Keith Ott Game";

	Delay(5);

// -----------------------------------------------------------------------------

	// End of loop 1 - loops until user wants to quit
	do
	{
		// Clear the screen
		clrscr();


		// Display the title
		DisplayTitle();


		// Display the main menu
		gotoxy(35,17);
		cout << "1. New Game\n";
		gotoxy(35,18);
		cout << "2. Instructions\n";
		gotoxy(35,19);
		cout << "3. Quit\n";

		// Position the cursor off the screen to eliminate flashing
      gotoxy(1,26);
		// Get user's selection
		MenuChoice = getche();


		// Evualate user's choice
		switch(MenuChoice)
		{
			// User wants to start a new game
			case '1':
				NewGame();

				break;

			// User wants to see the instructions
			case '2':
				Instructions();

				break;

			// User wants to quit
			case '3':
				clrscr();

				// Display in the center of the screen
				gotoxy(19,12);
				cout << "Thank you for playing Napcorn Gear Solid";
				gotoxy(26,13);
				cout << "http://napcorn.tripod.com/";

				// Quit the program
				return 0;

			// Error handling
			default:
				// Do not do anything
				;
		}

	// End of loop 1 - loops until user wants to quit
	} while(1);

}

// -----------------------------------------------------------------------------

// Displays the title
// ACCEPTS: nothing
// RETURNS: nothing
void DisplayTitle(void)
{
	// For looping
	int Loop;

	// Display the title
	cout << "         " << "  \\  |\n";
	cout << "         " << "   \\ |  _` | __ \\   __|  _ \\   __| __ \\\n";
	cout << "         " << " |\\  | (   | |  | (    (   | |    |   |      By\n";
	cout << "         " << "_| \\_|\\__,_| .__/ \\___|\\___/_|   _|  _|       Keith\n";
	cout << "         " << "            _|                                    Ott\n";
	cout << "         " << "                        ___|\n";
	cout << "         " << "                       |      _ \\  _` |  __|\n";
	cout << "         " << "                       |   |  __/ (   | |\n";
	cout << "         " << "                      \\____|\\___|\\__,_|_|\n";
	cout << "         " << "\n";
	cout << "         " << "    Starring                    ___|       |_)     |\n";
	cout << "         " << "     Morris Chestnut          \\___ \\   _ \\ | |  _` |\n";
	cout << "         " << "                                   | (   | | | (   |\n";
	cout << "         " << "                              _____/ \\___/_|_|\\__,_|\n";

	// Display the divider
	for(Loop = 1; Loop <= 79; Loop++)
	{
		cout << '_';
	}

	cout << "\n\n";

}

// -----------------------------------------------------------------------------

// Displays the Codec screen
// ACCEPTS: nothing
// RETURNS: nothing
void DisplayCodec(void)
{
	// For flashing Call on the screen - will flash 3 times
	int Loop;


	// Clear the screen
	clrscr();


	// "Call" Morris
	// -------------
	// Flash "Call" on the screen 3 times total
	for(Loop = 1; Loop <= 3; Loop++)
	{
		// Center it on screen
		gotoxy(35,10);
		cout << "+----+";
		gotoxy(35,11);
		cout << "|CALL|";
		gotoxy(35,12);
		cout << "+----+";
		gotoxy(32,13);
		cout << "PRESS SELECT";

		// Wait for a bit
		Delay(.3);

		// Clear the screen
		clrscr();

		// Wait for a bit
		Delay(.3);

		// Reflash it
		gotoxy(35,10);
		cout << "+----+";
		gotoxy(35,11);
		cout << "|CALL|";
		gotoxy(35,12);
		cout << "+----+";
		gotoxy(32,13);
		cout << "PRESS SELECT";

		// Wait for a bit
		Delay(.3);

		// Clear the screen
		clrscr();

		// Wait for a bit longer and then reflash it
		Delay(.7);
	}


	// Display the Codec screen
	// ------------------------
	// Done << "  " << "|--" so if Codec size changes, can be easily recentered
   // and can edit codec easier
	clrscr();
	cout << "\n";
	cout << "     " << "+------------+----------------+---+-----------------+------------+\n";
	cout << "     " << "|            |                |PTT|                 |            |\n";
	cout << "     " << "|    /////   |----------------+---+-----------------|    /--\\    |\n";
	cout << "     " << "|  ////////  |        +--------------------+        |   -\\-\\\\-\\  |\n";
	cout << "     " << "| ////////// |        |              ------|        | //::::\\\\\\\\ |\n";
	cout << "     " << "| ///      \\ |        |          ---/      |        | \\::::::XX| |\n";
	cout << "     " << "| |||  * * | |        |********-/          |        | |**-**/:|/ |\n";
	cout << "     " << "| ||    -| | | +----+ |******//            | +----+ | |:|-::::// |\n";
	cout << "     " << "| |\\       / | | <= | |****//     _   _  _ | | => | | \\:::::::/  |\n";
	cout << "     " << "|   \\  ¯¯ /  | +----+ |***//||_|_/ \\ (_)|_ | +----+ |  \\:¯¯::/   |\n";
	cout << "     " << "|   /\\\\-//\\  |        |***| |  | \\_/o(_) _)|        |  /\\---/\\   |\n";
	cout << "     " << "|  /;;;;;;;\\ |        +--------------------+        | /       \\\\ |\n";
	cout << "     " << "| /;;;/;;;;\\ |---------------+------+---------------| /     \\   \\|\n";
	cout << "     " << "|/;;;/;;;;;;\\|               |MEMORY|               |/       \\   |\n";
	cout << "     " << "+------------+---------------+------+---------------+------------+\n";

}


// -----------------------------------------------------------------------------

// Starts a new game
// ACCEPTS: nothing
// RETURNS: nothing
void NewGame(void)
{
	// Set up parts of the program here
	// --------------------------------


	// Declare Constants
	// -----------------


	// Declare File Streams
	// --------------------


	// Declare variables
	// -----------------
	// ==New Game==
	apstring Story;									// Used to hold the story
	// ==The Game==
	apmatrix <char> Level(20,10);					// The maze used
	int CurrentLevel;									// The current level the user is on
	int MorrisX;										// Player's X position
	int MorrisY;										// Player's Y position
	char UserInput;									// What the user has pressed

	// ==Loading Level==
	int Loop;
	int Loop2;


	// Write story
	// -----------
	// This will sort of "type out" the message by looping though this apstring
	// letter by letter, display each letter with a second delay loop
	Story = "Morris, do you read me?  It's the commander of the operation, Greg Campbell.\n\n";
	Story += "We've inserted you into Keith's Country because we believe that NAP-";
	Story += "HOUND has\n";
	Story += "been hording the world's Napcorn supply and will soon";
	Story += " infect the artificial\n";
	Story += "butter-flavoring with Napdie, only to";
	Story += " release it onto the world.  We need you\n";
	Story += "to go in and dispose of the Napcorn supply";
	Story += " before they add any poison to it!\n\nTo do this, you must traverse";
	Story += " numerous rooms until you reach the Napcorn Horde!";


	// Display the Story
	// -----------------
	clrscr();
	TypeText(Story);

	// Start loop - will loop though every level
	for(CurrentLevel = 1; CurrentLevel <= 10; CurrentLevel++)
	{
		// Depending on the currentl level, display the codec and display a
		// message
		// Level 1 - welcome message
		if(CurrentLevel == 1)
		{
			// Call codec
			DisplayCodec();

			// Display welcome message
			gotoxy(1,18);
			TypeText("This is Morris.");
			TextClear();

			gotoxy(1,18);
			TypeText("Colonel, can you hear me?");
			TextClear();

			gotoxy(1,18);
			TypeText("Loud and clear.");
			TextClear();

			gotoxy(1,18);
			TypeText("What's the situation, Morris?");
			TextClear();

			gotoxy(1,18);
			TypeText("Looks like the $ in every room is the only way through.");
			TextClear();

			gotoxy(1,18);
			TypeText("Just as I expected.");
			TextClear();

         gotoxy(1,18);
			TypeText("You'll have to get to that $ to move on.");
			TextClear();

         gotoxy(1,18);
			TypeText("But make sure you don't get lost in these maze like areas.");
			TextClear();

         gotoxy(1,18);
			TypeText("If I need you, I'll contact you by Codec.");
			TextClear();

         gotoxy(1,18);
			TypeText("I'm at frequency 140.85.");
			TextClear();

         gotoxy(1,18);
			TypeText("When we need to contact you, the Codec will flash.");
			TextClear();

			gotoxy(1,18);
			TypeText("The Codec's receiver directly stimulates the small bones of your ear.");
			TextClear();

         gotoxy(1,18);
			TypeText("No one but you will be able to hear it.");
			TextClear();

			gotoxy(1,18);
			TypeText("Got it.\nOkay. I'm ready to go.");
			TextClear();
		}
		// Level 5 - call from Morris' mom
		if(CurrentLevel == 5)
		{
			// Call codec
			DisplayCodec();

			// Display mom message
			gotoxy(1,18);
			TypeText("Hello Morris.");
			TextClear();

			gotoxy(1,18);
			TypeText("Meryl!");
			TextClear();

         gotoxy(1,18);
			TypeText("What?! I'm your mother! I just called to ask what you want on your Napcorn for\ndinner.");
			TextClear();

         gotoxy(1,18);
			TypeText("I'm in the middle of a mission, mother.");
			TextClear();

			gotoxy(1,18);
			TypeText("Don't give me no lip, child!");
			TextClear();

			gotoxy(1,18);
			TypeText("Okay. I'm sorry mother.");
			TextClear();

			gotoxy(1,18);
			TypeText("Yes, well, you'd better be. I'm going to go watch my stories now.");
			TextClear();

			gotoxy(1,18);
			TypeText("...");
			TextClear();
		}


		// Start Game
		// ----------
		// Get new level
		// Because this compiler sucks, it kept stopping after 100 warnings.  I
		// rewrote this code, trying to stop the warnings.  It didn't help.  I
		// then realized that I can change the warning problems, but I don't feel
		// like chaning the code back.  So it's stuck here.  Oh well - just run it
		// on a fast computer! :)

		// A call is made each for each entry
		// to the map and it is saved into this matrix here.
		for(Loop = 0; Loop < 10; Loop++)
		{
			for(Loop2 = 0; Loop2 < 20; Loop2++)
			{
				// Save the returned character into the level matrix
				Level[Loop2][Loop] = LevelPart(CurrentLevel, Loop2, Loop);
			}
		}

		// Reset player's position to the starting area
		MorrisX = 1;
		MorrisY = 0;
		// Display the map and the HUD
		DisplayMap(Level, CurrentLevel);

		// Loop 1 - loops until user reaches the end or presses ESC (27)
		do
		{
			// Display Morris' position
			gotoxy(MorrisX + 30, MorrisY + 8);
			cout << '!';

			// Move cursor to the bottom of the screen
			gotoxy(25,80);
			// Get user's input
			UserInput = getch();
			// Convert the user's input into capital letters
			UserInput = toupper(UserInput);


			// Erase Morris from map
			gotoxy(MorrisX + 30, MorrisY + 8);
			cout << ' ';

			// Analyize Input
			// --------------
			// User wanted to move up (I) and it isn't off the map
			if( (UserInput == 'I') && (MorrisY - 1 >= 0) )
			{
				// Make sure nothing is there
				if(Level[MorrisX][MorrisY - 1] != 'X')
				{
					// Move player up
					MorrisY--;
				}
			}

			// Left (J) - make sure isn't off map
			if( (UserInput == 'J') && (MorrisX - 1 >= 0) )
			{
				// Make sure nothing is there
				if(Level[MorrisX - 1][MorrisY] != 'X')
				{
					// Move player left
					MorrisX--;
				}
			}

			// Down (K) - make sure isn't off map
			if( (UserInput == 'K') && (MorrisY + 1 <= 10) )
			{
				// Make sure nothing is there
				if(Level[MorrisX][MorrisY + 1] != 'X')
				{
					// Move player down
					MorrisY++;
				}
			}

			// Right (L) - make sure isn't off map
			if( (UserInput == 'L') && (MorrisX + 1 <= 20) )
			{
				// Make sure nothing is there
				if(Level[MorrisX + 1][MorrisY] != 'X')
				{
					// Move player right
					MorrisX++;
				}
			}


		// End of loop 1 - loops until user reaches the end or presses ESC (27)
		} while((MorrisX != 19) && (MorrisY != 9) && (UserInput != 27));


		// If user wants to quit, break this loop
		if(UserInput == 27)
		{
			break;
		}
	}

	// If the user isn't canceling the game, show the ending screen
	if(UserInput != 27)
	{
		clrscr();

		// Call codec
		DisplayCodec();

		// Display ending message
		gotoxy(1,18);
		TypeText("Greg Campbell, I've made it.");
		TextClear();

		gotoxy(1,18);
		TypeText("There is Napcorn as far as the eye can see.");
		TextClear();

      gotoxy(1,18);
		TypeText("My god. Burn it Morris; burn it!");
		TextClear();

		gotoxy(1,18);
		TypeText("...");
		TextClear();

		gotoxy(1,18);
		TypeText("Burn it!");
		TextClear();

		gotoxy(1,18);
		TypeText("No. I did not become a very well known actor by just giving up. I'm going to\neat it.");
		TextClear();

      gotoxy(1,18);
		TypeText("No! Even though it hasn't been infected with Napdie yet, that much fiber will\nclean you out for good!");
		TextClear();

		gotoxy(1,18);
		TypeText("That's a chance I'm willing to take.");
		TextClear();

		gotoxy(1,18);
		TypeText("Morris, I must tell you something. You were cloned from Napcorn, as part of the\nNapcorn Soldier Project!");
		TextClear();

		gotoxy(1,18);
		TypeText("What?!");
		TextClear();

		gotoxy(1,18);
		TypeText("Okay, I made that up. But come on, all that Napcorn will give you diarrhea!");
		TextClear();

		gotoxy(1,18);
		TypeText("I'm sorry, but this is something that I must do...");
		TextClear();

		gotoxy(1,18);
		TypeText("... fine. Do what you need to do.");
		TextClear();

		clrscr();
		DisplayTitle();
		gotoxy(1,17);
		// Save the story into an apstring to be displayed
		Story = "Morris, all that Napcorn you found, it seems that you need something";
		Story += " to wash it\ndown with. And I have just the thing. But you must come";
		Story += " see me, your brother,\nMark Chestnut!... **DRAMATIC MUSIC CUE**";
		TypeText(Story);
	}

}

// -----------------------------------------------------------------------------

// Delays for x number of seconds
// ACCEPTS: the number of seconds
// RETURNS: nothing
void Delay(float Seconds)
{
	// Declare of clock type
	clock_t LastLoop;

	// This is how long the while loop will loop until it is done looping
	LastLoop = clock() + Seconds * CLK_TCK;

	// Loop x number of seconds
	while (clock() < LastLoop)
	;
}


// -----------------------------------------------------------------------------

// Simulates text being typed to the screen
// ACCEPTS: the text to be "typed"
// RETURNS: nothing
void TypeText(apstring String)
{
	// The current letter that is being displayed to the screen
	int CurrentLetter;
	// The letter the user pressed
	char Dummy;

	// Loop though each letter and display each one with a pause between each one
	for(CurrentLetter = 0; CurrentLetter < String.length(); CurrentLetter++)
	{
		// Write the letter to the screen
		cout << String[CurrentLetter];

		// Delay for a bit
		Delay(.05);
	}

	// Wait for user to press any key - centered on the bottom of the window
	gotoxy(25,25);
	cout << "Press any key to continue";

	// Position the cursor off the screen to eliminate flashing
	gotoxy(1,26);
	// Wait for user to press any key
	Dummy = getch();

}

// -----------------------------------------------------------------------------

// Returns the value of the X and the Y from the set of levels
// ACCEPTS: the level to get, the X of the level, the Y of the level
// RETURNS: what is at that place of the level
char LevelPart(int CurrentLevel, int X, int Y)
{
	// This function works by first saving all the levels into different 2D
	// arrays.  Then, the part of the level that is requested is returned

	// Levels
	// ------
	// Level 1
	char Level1[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X',' ',' ','X',' ',' ','X','X',' ','X',' ',' ',' ',' ',' ',' ',' ','X',
'X',' ',' ',' ','X',' ','X',' ',' ',' ',' ',' ',' ','X',' ',' ','X',' ',' ','X',
'X',' ','X',' ',' ',' ',' ',' ','X',' ','X',' ','X',' ','X',' ',' ','X',' ','X',
'X',' ','X',' ','X','X',' ','X',' ','X','X',' ',' ','X',' ','X','X',' ',' ','X',
'X',' ',' ',' ','X',' ','X',' ','X',' ',' ','X',' ',' ',' ',' ',' ','X',' ','X',
'X',' ','X','X',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ','X','X','X',
'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ','X',' ','X',' ',' ',' ','X',
'X',' ',' ','X',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ','X',' ',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 2
	char Level2[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ','X',
'X',' ','X','X','X','X',' ','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',
'X',' ',' ',' ','X',' ',' ','X',' ',' ','X','X',' ','X','X','X','X',' ',' ','X',
'X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ','X',
'X',' ',' ',' ','X',' ',' ','X','X','X',' ',' ','X',' ',' ',' ','X',' ',' ','X',
'X',' ','X','X','X',' ',' ','X',' ',' ','X','X','X','X','X',' ','X','X',' ','X',
'X',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X',
'X',' ',' ','X','X',' ',' ',' ',' ',' ','X','X',' ',' ',' ','X',' ',' ',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};


	// Level 3
	char Level3[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ','X','X',
'X','X','X',' ',' ',' ',' ',' ','X','X','X',' ','X',' ','X','X','X',' ',' ','X',
'X','X','X',' ','X','X','X','X','X','X','X',' ','X',' ','X','X','X','X',' ','X',
'X','X','X',' ','X','X',' ',' ',' ',' ','X',' ',' ',' ','X',' ','X','X',' ','X',
'X','X',' ',' ','X','X',' ','X',' ',' ','X',' ','X','X',' ',' ','X',' ',' ','X',
'X','X',' ','X','X','X',' ','X','X','X','X','X','X','X',' ',' ','X',' ','X','X',
'X','X',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ','X','X',
'X','X',' ','X','X','X','X','X','X',' ',' ',' ','X','X','X','X','X',' ',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 4
	char Level4[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X','X','X',' ',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ','X',
'X',' ',' ',' ','X',' ',' ',' ','X',' ',' ','X',' ','X','X',' ',' ',' ',' ','X',
'X',' ','X',' ',' ',' ','X','X','X',' ',' ',' ',' ','X',' ',' ','X','X','X','X',
'X',' ',' ','X','X','X',' ','X',' ',' ','X',' ',' ','X',' ',' ','X','X',' ','X',
'X',' ',' ','X',' ','X',' ','X',' ','X',' ',' ','X',' ',' ',' ',' ',' ',' ','X',
'X',' ',' ',' ',' ','X',' ',' ',' ',' ','X',' ',' ',' ','X','X',' ',' ','X','X',
'X',' ','X','X',' ','X',' ',' ','X',' ',' ','X',' ',' ',' ','X','X',' ',' ','X',
'X',' ',' ',' ',' ',' ',' ','X','X',' ','X',' ',' ',' ','X',' ','X','X',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 5
	char Level5[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ','X',
'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X','X','X','X',' ','X',
'X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ',' ',' ',' ','X',' ','X',
'X',' ','X',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ','X','X',' ','X',' ','X',
'X',' ','X',' ','X',' ','X','X','X','X','X','X','X','X','X','X','X','X',' ','X',
'X',' ','X',' ','X',' ','X',' ','X',' ',' ',' ','X',' ',' ','X',' ','X',' ','X',
'X',' ','X',' ','X',' ','X','X',' ',' ','X',' ','X',' ','X','X',' ','X',' ','X',
'X',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ','X',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 6
	char Level6[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',
'X',' ','X',' ',' ',' ','X','X',' ','X','X','X',' ',' ',' ','X','X','X',' ','X',
'X',' ','X',' ',' ','X',' ',' ',' ',' ',' ',' ','X',' ',' ','X','X','X',' ','X',
'X',' ','X',' ',' ','X',' ',' ',' ',' ',' ',' ','X',' ',' ','X','X','X',' ','X',
'X',' ','X',' ',' ','X',' ',' ',' ',' ',' ',' ','X',' ',' ','X','X','X',' ','X',
'X',' ','X',' ',' ','X',' ',' ','X','X',' ',' ','X',' ',' ',' ',' ',' ',' ','X',
'X',' ',' ','X','X',' ',' ',' ','X','X',' ',' ',' ','X','X','X',' ',' ',' ','X',
'X',' ',' ',' ',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ',' ','X',' ',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 7
	char Level7[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X','X','X',' ','X',' ',' ',' ',' ',' ','X','X','X','X','X','X','X','X',
'X',' ','X','X','X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ','X','X','X',
'X',' ','X','X','X',' ','X','X','X','X',' ',' ',' ','X','X','X',' ','X','X','X',
'X',' ',' ',' ',' ',' ','X','X','X','X',' ','X','X','X','X','X',' ',' ',' ','X',
'X','X','X',' ','X','X','X','X','X','X',' ','X','X','X','X','X','X','X',' ','X',
'X','X','X',' ','X','X','X','X','X','X',' ','X','X','X',' ',' ','X','X','X','X',
'X','X','X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 8
	char Level8[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X',
'X',' ',' ','X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X',
'X',' ',' ',' ',' ',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',
'X',' ','X',' ',' ','X','X',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X',
'X',' ',' ','X',' ',' ',' ',' ',' ','X',' ',' ','X','X',' ','X',' ',' ','X','X',
'X',' ',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',
'X',' ','X',' ',' ','X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X',
'X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 9
	char Level9[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ','X',
'X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ','X',
'X',' ','X','X',' ','X',' ',' ',' ','X','X',' ',' ',' ','X',' ',' ',' ','X','X',
'X',' ',' ',' ','X',' ','X',' ','X',' ',' ','X',' ',' ',' ','X','X',' ',' ','X',
'X',' ','X',' ',' ',' ','X',' ','X',' ',' ',' ','X','X','X',' ',' ','X','X','X',
'X',' ',' ',' ','X',' ',' ','X',' ',' ','X',' ','X',' ',' ',' ','X',' ',' ','X',
'X',' ','X','X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X','X',
'X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X',' ',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};

	// Level 10
	char Level10[10][20] = {
'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',
'X',' ','X',' ','X',' ','X',' ','X',' ',' ',' ',' ',' ','X',' ','X',' ','X','X',
'X',' ',' ',' ',' ','X',' ','X',' ',' ',' ','X',' ','X',' ',' ',' ','X',' ','X',
'X',' ','X',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ','X','X',
'X','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X',' ',' ',' ',' ',' ','X',
'X',' ','X',' ','X',' ',' ',' ','X',' ','X',' ','X',' ','X',' ','X',' ','X','X',
'X','X',' ','X',' ','X',' ','X',' ',' ',' ',' ',' ','X',' ','X',' ','X',' ','X',
'X',' ','X',' ','X',' ',' ',' ',' ',' ','X',' ','X',' ','X',' ',' ',' ',' ','X',
'X','X',' ','X',' ','X',' ','X',' ','X',' ',' ',' ',' ',' ',' ',' ','X',' ','X',
'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','$','X'};


	// Copying Variables
	// -----------------
	char Copy;

	switch(CurrentLevel)
	{
		// Level 1
		case 1:
			Copy = Level1[Y][X];

			break;

		// Level 2
		case 2:
			Copy = Level2[Y][X];

			break;

		// Level 3
		case 3:
			Copy = Level3[Y][X];

			break;

		// Level 4
		case 4:
			Copy = Level4[Y][X];

			break;

		// Level 5
		case 5:
			Copy = Level5[Y][X];

			break;

		// Level 6
		case 6:
			Copy = Level6[Y][X];

			break;

		// Level 7
		case 7:
			Copy = Level7[Y][X];

			break;

		// Level 8
		case 8:
			Copy = Level8[Y][X];

			break;

		// Level 9
		case 9:
			Copy = Level9[Y][X];

			break;

		// Level 10
		case 10:
			Copy = Level10[Y][X];

			break;

		// Error handling
		default:
			// If for some reason, the level number would be smaller than 1
			// or larger then 10, just close the program w/an error value
			exit(1);

		break;
	}


	// Return the part of the level
	return Copy;

}

// -----------------------------------------------------------------------------

// Displays the map and the HUD
// ACCEPTS: the level and the current level
// RETURNS: nothing
void DisplayMap(apmatrix <char> Level, int CurrentLevel)
{
	// For displaying the map
	int X;
	int Y;


	// Clear the screen
	clrscr();


	// Display the info on the top
	cout << "Life\n";
	cout << "======\n";

	gotoxy(10,1);
	cout << "Current Level\n";
	gotoxy(15,2);
	cout << CurrentLevel;


	// Display the map
	// ---------------
	// The y axis
	for(Y = 0; Y < 10; Y++)
	{
		// Center on the screen
		gotoxy(30,Y + 8);

		// The x axis
		for(X = 0; X < 20; X++)
		{
			cout << Level[X][Y];
		}
	}

// End of function
}

// -----------------------------------------------------------------------------

// Clears off any text left from the codec, but leaves the graphic
// ACCEPTS: nothing
// RETURNS: nothing
void TextClear(void)
{
	// For looping
	int Loop;
	int Loop2;


	// Loop though each line (18 - 25) and each character (1 - 79)
	for(Loop = 18; Loop <= 25; Loop++)
	{
		for(Loop2 = 1; Loop2 <= 79; Loop2++)
		{
			// Go to that area and erase any characters there
			gotoxy(Loop2, Loop);
			cout << ' ';
		}
	}

// End of function
}

// -----------------------------------------------------------------------------

// Displays the instructions to the game
// ACCEPTS: nothing
// RETURNS: nothing
void Instructions(void)
{
	// For holding user's key - does nothing with it
	char Dummy;

	// Clear the screen
	clrscr();

	// Display the instructions
	// ------------------------
	cout << "        N A P C O R N   G E A R   S O L I D   I N S T R U C T I O N S\n";
	cout << "        ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";

	cout << "What better way to enjoy Napcorn then to play a game? Well, we here at\n";
	cout << "Nap Co. realized this, and released a completely original game entitled\n";
	cout << "Napcorn Gear Solid.\n\n";

	cout << "After being inserted into a foreign land, you, as Morris Chestnut, must\n";
	cout << "find the Napcorn that the terrorists are about to poison.  Napcorn Gear\n";
	cout << "Solid will have you traveling through countless hours of game play, pushing\n";
	cout << "your gaming skills to the limit!\n\n";

	cout << "HOW TO PLAY:\n";
	cout << "Move Morris (!) though each room until he reaches the end ($).  Although\n";
	cout << "Morris does have sexy chocolate skin, he cannot go though walls (X), so you\n";
	cout << "must find him another way.  Use \'I\' to move Morris up, \'J\' to move\n";
	cout << "Morris left, \'K\' to move Morris down, and \'L\' to move him right.  Press\n";
	cout << "\'ESC\' to quit at any time.";


	gotoxy(25,25);
	cout << "Press any key to continue";

	// Position the cursor off the screen to eliminate flashing
	gotoxy(1,26);
   // Wait for user's input
	Dummy = getch();
}
