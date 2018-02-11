#define PICTOR_FASTMODE
#include <avr/io.h>

#include "pictor.h"
#include "/OryxB.h"
#include "Mash.h"
#include "sprite_ghost.h"
#include "sprite_check.h"
#include "plug.h"
//Linking
#include "Layout.h"

/*
In this example a selection of draw functions are demonstrated and the on board LED is lit for the duration of the initial screen drawing process
*/


//this text is stored entirely in program memory, useful for long strings that won't change
//it is also useful if the same string is used many times in the code, to declare the string once at the beginning rather than every time it is used
//this means that it is only in the code once, rather than once for every time it is used

void DrawLayout() {
	DDRB |= _BV(PB7);
	pictorInit(0);
	PORTB |= _BV(PB7);
	pictorSetRotation(1);
	pictorDrawAll(BLACK);
	//	Welcome
	//Draw value boxes
	pictorDrawBox((point){2, 10}, (point){77, 20}, CYAN);
	pictorDrawBox((point){3, 11}, (point){76, 19}, BLACK);
	//
	pictorDrawLine((point){79, 0}, (point){79, 240}, RED);
	pictorDrawLine((point){239, 0}, (point){239, 240}, RED);
//draw static texts
	pictorDrawS("W", (point){74,16}, MAGENTA, BLACK, OryxB,1);
	pictorDrawS("SMART METER- TEAM B", (point){80,0}, MAGENTA, BLACK, Mash,1);
	//	Draw chars
	uint8_t I, J, K, L;
	/*
	pictorDrawS("  FLUX  ", (point){0, 8}, BLACK, ORANGE, Mash,1);
	pictorDrawBox( (point){0, 24}, (point){127, 151}, DARK WHITE);
	for (I = 0; I < 8; I++) {
		for (J = 0; J < 16; J++) {
			pictorDrawC( I * 16 + J, (point){I * 8, 24 + J * 8}, ORANGE, BLACK, Mash,1);
		}
	}
	pictorDrawS("  FLUX ", (point){64, 8}, BLACK, PALE BLUE, OryxB,1);
	for (I = 0; I < 8; I++) {
		for (J = 0; J < 16; J++) {
			pictorDrawC( I * 16 + J, (point){64 + I * 8, 24 + J * 8}, PALE BLUE, BLACK, OryxB,1);
		}
	}*/
	//	Draw sprites
	pictorDrawSpriteType(&plug, (point){0, 0}, 1, 1);


	//draw scaled text
	pictorDrawS("SMART METER- TEAM B", (point){80,0}, MAGENTA, BLACK, Mash,1);
	//	Complete
	//pictorDrawSP(text1, ORIGIN, GREEN, BLACK, Mash,1);
	pictorDrawS("Last Modified:", (point){0, 231}, MAGENTA, BLACK, Mash,1);
	pictorDrawS(__TIMESTAMP__, (point){120, 231}, MAGENTA, BLACK, Mash,1);
	PORTB &= ~_BV(PB7);
	int16_t M=0;

	while(1)
	{
		pictorDrawD(M, (point){128,178}, CYAN, BLACK, Mash, 2, 4);
		M++;
		/*if (M < 998)
		{
			M=0;
		}*/
	}
}
