/*
 * music.c: Handles the majority of the work required to play music.
 *
 *  Created on: Apr 20, 2019
 *      Author: ryanjl9
 */

#include <music.h>

struct note song[LENGTH];

/*
 * set_song: Used for loading and selecting songs into memory to be played
 *
 * @param num: which song to program in
 */

void set_song(int num){
	/*
	 * Tetris Theme A
	 */
	if(num == 1){
		SLENGTH = 57;

		QUARTER = 22;
		EIGTH 	= 11;
		HALF 	= 44;
		WHOLE 	= 88;
		DOTTED 	= 33;

		setNote(1, 76, QUARTER);
		setNote(2, 71, EIGTH);
		setNote(3, 72, EIGTH);
		setNote(4, 74, QUARTER);
		setNote(5, 72, EIGTH);
		setNote(6, 71, EIGTH);
		setNote(7, 69, QUARTER);
		setNote(8, 69, EIGTH);
		setNote(9, 72, EIGTH);
		setNote(10, 76, QUARTER);
		setNote(11, 74, EIGTH);
		setNote(12, 72, EIGTH);
		setNote(13, 71, QUARTER);
		setNote(14, 71, EIGTH);
		setNote(15, 72, EIGTH);
		setNote(16, 74, QUARTER);
		setNote(17, 76, QUARTER);
		setNote(18, 72, QUARTER);
		setNote(19, 69, QUARTER);
		setNote(20, 69, QUARTER);
		setNote(21, 0, QUARTER);
		setNote(22, 74, DOTTED);
		setNote(23, 77, EIGTH);
		setNote(24, 81, QUARTER);
		setNote(25, 79, EIGTH);
		setNote(26, 77, EIGTH);
		setNote(27, 76, DOTTED);
		setNote(28, 72, EIGTH);
		setNote(29, 76, QUARTER);
		setNote(30, 74, EIGTH);
		setNote(31, 72, EIGTH);
		setNote(32, 71, QUARTER);
		setNote(33, 71, EIGTH);
		setNote(34, 72, EIGTH);
		setNote(35, 74, QUARTER);
		setNote(36, 76, QUARTER);
		setNote(37, 72, QUARTER);
		setNote(38, 69, QUARTER);
		setNote(39, 69, QUARTER);
		setNote(40, 0, QUARTER);
		setNote(41, 64, HALF);
		setNote(42, 60, HALF);
		setNote(43, 62, HALF);
		setNote(44, 59, HALF);
		setNote(45, 60, HALF);
		setNote(46, 57, HALF);
		setNote(47, 56, HALF);
		setNote(48, 59, HALF);
		setNote(49, 64, HALF);
		setNote(50, 60, HALF);
		setNote(51, 62, HALF);
		setNote(52, 59, HALF);
		setNote(53, 60, QUARTER);
		setNote(54, 64, QUARTER);
		setNote(55, 69, QUARTER);
		setNote(56, 69, QUARTER);
		setNote(57, 68, WHOLE);
	}

	/*
	 *	Megalovania Part 1
	 */
	if(num == 2){
		SLENGTH 		= 44;

		QUARTER 		= 32;
		EIGTH 			= 16;
		SIXTEENTH 		= 8;
		THIRTYSECOND 	= 4;
		DOTTED_EIGTH 	= 24;

		setNote(1, 62, SIXTEENTH);
		setNote(2, 62, SIXTEENTH);
		setNote(3, 74, EIGTH);
		setNote(4, 69, DOTTED_EIGTH);
		setNote(5, 68, SIXTEENTH);
		setNote(6, 0, SIXTEENTH);
		setNote(7, 67, EIGTH);
		setNote(8, 65, EIGTH);
		setNote(9, 62, SIXTEENTH);
		setNote(10, 65, SIXTEENTH);
		setNote(11, 67, SIXTEENTH);
		setNote(12, 60, SIXTEENTH);
		setNote(13, 60, SIXTEENTH);
		setNote(14, 74, EIGTH);
		setNote(15, 69, DOTTED_EIGTH);
		setNote(16, 68, SIXTEENTH);
		setNote(17, 0, SIXTEENTH);
		setNote(18, 67, EIGTH);
		setNote(19, 65, EIGTH);
		setNote(20, 62, SIXTEENTH);
		setNote(21, 65, SIXTEENTH);
		setNote(22, 67, SIXTEENTH);
		setNote(23, 59, SIXTEENTH);
		setNote(24, 59, SIXTEENTH);
		setNote(25, 74, EIGTH);
		setNote(26, 69, DOTTED_EIGTH);
		setNote(27, 68, SIXTEENTH);
		setNote(28, 0, SIXTEENTH);
		setNote(29, 67, EIGTH);
		setNote(30, 65, EIGTH);
		setNote(31, 62, SIXTEENTH);
		setNote(32, 65, SIXTEENTH);
		setNote(33, 67, SIXTEENTH);
		setNote(34, 58, SIXTEENTH);
		setNote(35, 58, SIXTEENTH);
		setNote(36, 74, EIGTH);
		setNote(37, 69, DOTTED_EIGTH);
		setNote(38, 68, SIXTEENTH);
		setNote(39, 0, SIXTEENTH);
		setNote(40, 67, EIGTH);
		setNote(41, 65, EIGTH);
		setNote(42, 62, SIXTEENTH);
		setNote(43, 65, SIXTEENTH);
		setNote(44, 67, SIXTEENTH);
	}

	/*
	 *	Megalovania Part 2
	 */
	if(num == 3){
		SLENGTH 		= 44;

		QUARTER 		= 32;
		EIGTH 			= 16;
		SIXTEENTH 		= 8;
		THIRTYSECOND 	= 4;
		DOTTED_EIGTH 	= 24;

		setNote(1, 74, SIXTEENTH);
		setNote(2, 74, SIXTEENTH);
		setNote(3, 86, EIGTH);
		setNote(4, 81, DOTTED_EIGTH);
		setNote(5, 80, SIXTEENTH);
		setNote(6, 0, SIXTEENTH);
		setNote(7, 79, EIGTH);
		setNote(8, 77, EIGTH);
		setNote(9, 74, SIXTEENTH);
		setNote(10, 77, SIXTEENTH);
		setNote(11, 79, SIXTEENTH);
		setNote(12, 72, SIXTEENTH);
		setNote(13, 72, SIXTEENTH);
		setNote(14, 86, EIGTH);
		setNote(15, 81, DOTTED_EIGTH);
		setNote(16, 80, SIXTEENTH);
		setNote(17, 0, SIXTEENTH);
		setNote(18, 79, EIGTH);
		setNote(19, 77, EIGTH);
		setNote(20, 74, SIXTEENTH);
		setNote(21, 77, SIXTEENTH);
		setNote(22, 79, SIXTEENTH);
		setNote(23, 71, SIXTEENTH);
		setNote(24, 71, SIXTEENTH);
		setNote(25, 86, EIGTH);
		setNote(26, 81, DOTTED_EIGTH);
		setNote(27, 80, SIXTEENTH);
		setNote(28, 0, SIXTEENTH);
		setNote(29, 79, EIGTH);
		setNote(30, 77, EIGTH);
		setNote(31, 74, SIXTEENTH);
		setNote(32, 77, SIXTEENTH);
		setNote(33, 79, SIXTEENTH);
		setNote(34, 70, SIXTEENTH);
		setNote(35, 70, SIXTEENTH);
		setNote(36, 86, EIGTH);
		setNote(37, 81, DOTTED_EIGTH);
		setNote(38, 80, SIXTEENTH);
		setNote(39, 0, SIXTEENTH);
		setNote(40, 79, EIGTH);
		setNote(41, 77, EIGTH);
		setNote(42, 74, SIXTEENTH);
		setNote(43, 77, SIXTEENTH);
		setNote(44, 79, SIXTEENTH);
	}

	/*
	 *	Megalovania Part 3
	 */
	if(num == 4){
		SLENGTH 		= 59;

		QUARTER 		= 32;
		EIGTH 			= 16;
		SIXTEENTH 		= 8;
		THIRTYSECOND 	= 4;
		DOTTED_EIGTH 	= 24;
		QUARTER_TIESIX	= 40;

		setNote(1, 77, EIGTH);
		setNote(2, 77, SIXTEENTH);
		setNote(3, 77, SIXTEENTH);
		setNote(4, 0, SIXTEENTH);
		setNote(5, 77, EIGTH);
		setNote(6, 77, EIGTH);
		setNote(7, 74, EIGTH);
		setNote(8, 74, QUARTER_TIESIX);
		setNote(9, 77, EIGTH);
		setNote(10, 77, SIXTEENTH);
		setNote(11, 77, SIXTEENTH);
		setNote(12, 0, SIXTEENTH);
		setNote(13, 79, EIGTH);
		setNote(14, 80, EIGTH);
		setNote(15, 79, THIRTYSECOND);
		setNote(16, 80, THIRTYSECOND);
		setNote(17, 79, THIRTYSECOND);
		setNote(18, 77, SIXTEENTH);
		setNote(19, 74, SIXTEENTH);
		setNote(20, 77, SIXTEENTH);
		setNote(21, 79, SIXTEENTH);
		setNote(22, 0, EIGTH);
		setNote(23, 77, EIGTH);
		setNote(24, 77, SIXTEENTH);
		setNote(25, 77, SIXTEENTH);
		setNote(26, 0, SIXTEENTH);
		setNote(27, 79, EIGTH);
		setNote(28, 80, SIXTEENTH);
		setNote(29, 0, SIXTEENTH);
		setNote(30, 81, EIGTH);
		setNote(31, 84, EIGTH);
		setNote(32, 81, DOTTED_EIGTH);
		setNote(33, 86, EIGTH);
		setNote(34, 86, EIGTH);
		setNote(35, 86, SIXTEENTH);
		setNote(36, 81, SIXTEENTH);
		setNote(37, 86, SIXTEENTH);
		setNote(38, 84, EIGTH);
		setNote(39, 91, QUARTER);
		setNote(40, 81, EIGTH);
		setNote(41, 81, SIXTEENTH);
		setNote(42, 81, SIXTEENTH);
		setNote(43, 0, SIXTEENTH);
		setNote(44, 81, EIGTH);
		setNote(45, 81, EIGTH);
		setNote(46, 79, EIGTH);
		setNote(47, 79, QUARTER_TIESIX);
		setNote(48, 81, EIGTH);
		setNote(49, 81, SIXTEENTH);
		setNote(50, 81, SIXTEENTH);
		setNote(51, 0, SIXTEENTH);
		setNote(52, 81, EIGTH);
		setNote(53, 79, EIGTH);
		setNote(54, 0, SIXTEENTH);
		setNote(55, 81, EIGTH);
		setNote(56, 86, SIXTEENTH);
		setNote(57, 0, SIXTEENTH);
		setNote(58, 81, SIXTEENTH);
		setNote(59, 79, EIGTH);
	}

	/*
	 *	Megalovania Part 4
	 */
	if(num == 5){
		SLENGTH 		= 56;

		HALF			= 64;
		QUARTER 		= 32;
		EIGTH 			= 16;
		SIXTEENTH 		= 8;
		THIRTYSECOND 	= 4;
		DOTTED_EIGTH 	= 24;
		QUARTER_TIESIX	= 40;
		HALF_TIESIX		= 72;

		setNote(1, 83, SIXTEENTH);
		setNote(2, 79, SIXTEENTH);
		setNote(3, 74, SIXTEENTH);
		setNote(4, 76, SIXTEENTH);
		setNote(5, 77, SIXTEENTH);
		setNote(6, 74, SIXTEENTH);
		setNote(7, 71, SIXTEENTH);
		setNote(8, 74, SIXTEENTH);
		setNote(9, 0, SIXTEENTH);
		setNote(10, 74, SIXTEENTH);
		setNote(11, 71, SIXTEENTH);
		setNote(12, 74, SIXTEENTH);
		setNote(13, 71, SIXTEENTH);
		setNote(14, 67, SIXTEENTH);
		setNote(15, 71, SIXTEENTH);
		setNote(16, 67, SIXTEENTH);
		setNote(17, 70, EIGTH);
		setNote(18, 72, SIXTEENTH);
		setNote(19, 70, SIXTEENTH);
		setNote(20, 0, SIXTEENTH);
		setNote(21, 74, EIGTH);
		setNote(22, 76, HALF_TIESIX);
		setNote(23, 0, HALF);
		setNote(24, 77, SIXTEENTH);
		setNote(25, 74, SIXTEENTH);
		setNote(26, 77, SIXTEENTH);
		setNote(27, 79, SIXTEENTH);
		setNote(28, 80, SIXTEENTH);
		setNote(29, 79, SIXTEENTH);
		setNote(30, 77, SIXTEENTH);
		setNote(31, 74, SIXTEENTH);
		setNote(32, 80, THIRTYSECOND);
		setNote(33, 79, THIRTYSECOND);
		setNote(34, 77, THIRTYSECOND);
		setNote(35, 74, THIRTYSECOND);
		setNote(36, 77, EIGTH);
		setNote(37, 79, HALF_TIESIX);
		setNote(38, 80, EIGTH);
		setNote(39, 81, SIXTEENTH);
		setNote(40, 84, EIGTH);
		setNote(41, 81, SIXTEENTH);
		setNote(42, 80, SIXTEENTH);
		setNote(43, 79, SIXTEENTH);
		setNote(44, 77, SIXTEENTH);
		setNote(45, 74, SIXTEENTH);
		setNote(46, 76, SIXTEENTH);
		setNote(47, 77, EIGTH);
		setNote(48, 79, EIGTH);
		setNote(49, 81, EIGTH);
		setNote(50, 84, EIGTH);
		setNote(51, 85, EIGTH);
		setNote(52, 80, EIGTH);
		setNote(53, 80, SIXTEENTH);
		setNote(54, 79, SIXTEENTH);
		setNote(55, 77, SIXTEENTH);
		setNote(56, 79, HALF_TIESIX);
	}

	/*
	 *	Megalovania Part 5
	 */
	if(num == 6){
		SLENGTH 		= 21;

		HALF			= 64;
		QUARTER 		= 32;
		EIGTH 			= 16;
		SIXTEENTH 		= 8;
		THIRTYSECOND 	= 4;
		DOTTED_EIGTH 	= 24;
		QUARTER_TIESIX	= 40;
		HALF_TIESIX		= 72;

		setNote(1, 65, EIGTH);
		setNote(2, 67, EIGTH);
		setNote(3, 69, EIGTH);
		setNote(4, 77, EIGTH);
		setNote(5, 76, QUARTER);
		setNote(6, 74, QUARTER);
		setNote(7, 76, QUARTER);
		setNote(8, 77, QUARTER);
		setNote(9, 79, QUARTER);
		setNote(10, 76, QUARTER);
		setNote(11, 81, HALF);
		setNote(12, 81, SIXTEENTH);
		setNote(13, 80, SIXTEENTH);
		setNote(14, 79, SIXTEENTH);
		setNote(15, 78, SIXTEENTH);
		setNote(16, 77, SIXTEENTH);
		setNote(17, 76, SIXTEENTH);
		setNote(18, 75, SIXTEENTH);
		setNote(19, 74, SIXTEENTH);
		setNote(20, 73, HALF);
		setNote(21, 75, HALF);
	}

	/*
	 *	Legend of Zelda Part 1
	 */
	if(num == 7){
		SLENGTH 		= 36;

		HALF			= 60;
		QUARTER 		= 28;
		EIGTH 			= 14;
		SIXTEENTH 		= 7;
		TRIP_EIGTH		= 9;
		TRIP_QUART		= 18;
		DOTTED_QUART	= 42;
		DOTTED_HALF		= 90;

		setNote(1, 69, HALF);
		setNote(2, 0, TRIP_EIGTH);
		setNote(3, 0, TRIP_EIGTH);
		setNote(4, 69, TRIP_EIGTH);
		setNote(5, 69, TRIP_EIGTH);
		setNote(6, 69, TRIP_EIGTH);
		setNote(7, 69, TRIP_EIGTH);
		setNote(8, 69, TRIP_QUART);
		setNote(9, 67, TRIP_EIGTH);
		setNote(10, 69, QUARTER);
		setNote(11, 0, TRIP_EIGTH);
		setNote(12, 0, TRIP_EIGTH);
		setNote(13, 69, TRIP_EIGTH);
		setNote(14, 69, TRIP_EIGTH);
		setNote(15, 69, TRIP_EIGTH);
		setNote(16, 69, TRIP_EIGTH);
		setNote(17, 69, TRIP_QUART);
		setNote(18, 67, TRIP_EIGTH);
		setNote(19, 69, QUARTER);
		setNote(20, 0, TRIP_EIGTH);
		setNote(21, 0, TRIP_EIGTH);
		setNote(22, 69, TRIP_EIGTH);
		setNote(23, 69, TRIP_EIGTH);
		setNote(24, 69, TRIP_EIGTH);
		setNote(25, 69, TRIP_EIGTH);
		setNote(26, 69, EIGTH);
		setNote(27, 64, SIXTEENTH);
		setNote(28, 64, SIXTEENTH);
		setNote(29, 64, EIGTH);
		setNote(30, 64, SIXTEENTH);
		setNote(31, 64, SIXTEENTH);
		setNote(32, 64, EIGTH);
		setNote(33, 64, SIXTEENTH);
		setNote(34, 64, SIXTEENTH);
		setNote(35, 64, EIGTH);
		setNote(36, 64, EIGTH);
	}

	/*
	 *	Legend of Zelda Part 2
	 */
	if(num == 8){
		SLENGTH 		= 64;

		HALF			= 60;
		QUARTER 		= 28;
		EIGTH 			= 14;
		SIXTEENTH 		= 7;
		TRIP_EIGTH		= 9;
		TRIP_QUART		= 18;
		DOTTED_QUART	= 42;
		DOTTED_HALF		= 90;

		setNote(1, 69, QUARTER);
		setNote(2, 64, DOTTED_QUART);
		setNote(3, 69, EIGTH);
		setNote(4, 69, SIXTEENTH);
		setNote(5, 71, SIXTEENTH);
		setNote(6, 72, SIXTEENTH);
		setNote(7, 74, SIXTEENTH);
		setNote(8, 76, HALF);
		setNote(9, 0, EIGTH);
		setNote(10, 76, EIGTH);
		setNote(11, 76, TRIP_EIGTH);
		setNote(12, 77, TRIP_EIGTH);
		setNote(13, 79, TRIP_EIGTH);
		setNote(14, 81, HALF);
		setNote(15, 0, EIGTH);
		setNote(16, 81, EIGTH);
		setNote(17, 81, TRIP_EIGTH);
		setNote(18, 79, TRIP_EIGTH);
		setNote(19, 77, TRIP_EIGTH);
		setNote(20, 79, DOTTED_EIGTH);
		setNote(21, 77, SIXTEENTH);
		setNote(22, 76, HALF);
		setNote(23, 76, QUARTER);
		setNote(24, 74, EIGTH);
		setNote(25, 74, SIXTEENTH);
		setNote(26, 76, SIXTEENTH);
		setNote(27, 77, HALF);
		setNote(28, 76, EIGTH);
		setNote(29, 74, EIGTH);
		setNote(30, 72, EIGTH);
		setNote(31, 72, SIXTEENTH);
		setNote(32, 74, SIXTEENTH);
		setNote(33, 76, HALF);
		setNote(34, 74, EIGTH);
		setNote(35, 72, EIGTH);
		setNote(36, 71, EIGTH);
		setNote(37, 71, SIXTEENTH);
		setNote(38, 72, SIXTEENTH);
		setNote(39, 74, HALF);
		setNote(40, 77, QUARTER);
		setNote(41, 76, EIGTH);
		setNote(42, 64, SIXTEENTH);
		setNote(43, 64, SIXTEENTH);
		setNote(44, 64, EIGTH);
		setNote(45, 64, SIXTEENTH);
		setNote(46, 64, SIXTEENTH);
		setNote(47, 64, EIGTH);
		setNote(48, 64, SIXTEENTH);
		setNote(49, 64, SIXTEENTH);
		setNote(50, 64, EIGTH);
		setNote(51, 64, EIGTH);
		setNote(52, 69, QUARTER);
		setNote(53, 64, DOTTED_QUART);
		setNote(54, 69, EIGTH);
		setNote(55, 69, SIXTEENTH);
		setNote(56, 71, SIXTEENTH);
		setNote(57, 72, SIXTEENTH);
		setNote(58, 74, SIXTEENTH);
		setNote(59, 76, HALF);
		setNote(60, 0, EIGTH);
		setNote(61, 76, EIGTH);
		setNote(62, 76, TRIP_EIGTH);
		setNote(63, 77, TRIP_EIGTH);
		setNote(64, 79, TRIP_EIGTH);
	}

	/*
	 *	Legend of Zelda Part 3
	 */
	if(num == 9){
		SLENGTH 		= 38;

		HALF			= 60;
		QUARTER 		= 28;
		EIGTH 			= 14;
		SIXTEENTH 		= 7;
		TRIP_EIGTH		= 9;
		TRIP_QUART		= 18;
		DOTTED_QUART	= 42;
		DOTTED_HALF		= 90;

		setNote(1, 81, HALF);
		setNote(2, 0, EIGTH);
		setNote(3, 0, EIGTH);
		setNote(4, 84, QUARTER);
		setNote(5, 83, QUARTER);
		setNote(6, 79, HALF);
		setNote(7, 76, QUARTER);
		setNote(8, 77, DOTTED_HALF);
		setNote(9, 81, QUARTER);
		setNote(10, 79, QUARTER);
		setNote(11, 76, HALF);
		setNote(12, 76, QUARTER);
		setNote(13, 77, DOTTED_HALF);
		setNote(14, 81, QUARTER);
		setNote(15, 80, QUARTER);
		setNote(16, 76, HALF);
		setNote(17, 73, QUARTER);
		setNote(18, 74, DOTTED_HALF);
		setNote(19, 77, QUARTER);
		setNote(20, 76, QUARTER);
		setNote(21, 72, HALF);
		setNote(22, 69, QUARTER);
		setNote(23, 71, EIGTH);
		setNote(24, 71, SIXTEENTH);
		setNote(25, 72, SIXTEENTH);
		setNote(26, 74, HALF);
		setNote(27, 77, QUARTER);
		setNote(28, 76, EIGTH);
		setNote(29, 64, SIXTEENTH);
		setNote(30, 64, SIXTEENTH);
		setNote(31, 64, EIGTH);
		setNote(32, 64, SIXTEENTH);
		setNote(33, 64, SIXTEENTH);
		setNote(34, 64, EIGTH);
		setNote(35, 64, SIXTEENTH);
		setNote(36, 64, SIXTEENTH);
		setNote(37, 64, EIGTH);
		setNote(38, 64, EIGTH);
	}


	/*
	 *	Marble Machine Part 1
	 */
	if(num == 10){
		SLENGTH 		= 64;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 76, DOTTED_QUART);
		setNote(2, 71, HALF);
		setNote(3, 69, EIGTH);
		setNote(4, 67, EIGTH);
		setNote(5, 69, QUARTER);
		setNote(6, 71, QUARTER);
		setNote(7, 67, EIGTH);
		setNote(8, 69, EIGTH);
		setNote(9, 74, HALF);
		setNote(10, 71, HALF);
		setNote(11, 69, EIGTH);
		setNote(12, 67, EIGTH);
		setNote(13, 69, QUARTER);
		setNote(14, 66, QUARTER);
		setNote(15, 67, EIGTH);
		setNote(16, 69, EIGTH);
		setNote(17, 74, DOTTED_QUART);
		setNote(18, 0, EIGTH);
		setNote(19, 71, DOTTED_QUART);
		setNote(20, 0, EIGTH);
		setNote(21, 74, EIGTH);
		setNote(22, 72, EIGTH);
		setNote(23, 71, QUARTER);
		setNote(24, 69, QUARTER);
		setNote(25, 67, EIGTH);
		setNote(26, 69, EIGTH);
		setNote(27, 64, HALF);
		setNote(28, 71, DOTTED_QUART);
		setNote(29, 0, EIGTH);
		setNote(30, 74, EIGTH);
		setNote(31, 72, EIGTH);
		setNote(32, 71, QUARTER);
		setNote(33, 69, QUARTER);
		setNote(34, 67, EIGTH);
		setNote(35, 69, EIGTH);
		setNote(36, 76, DOTTED_QUART);
		setNote(37, 0, EIGTH);
		setNote(38, 71, HALF);
		setNote(39, 69, EIGTH);
		setNote(40, 67, EIGTH);
		setNote(41, 69, QUARTER);
		setNote(42, 71, QUARTER);
		setNote(43, 67, EIGTH);
		setNote(44, 69, EIGTH);
		setNote(45, 76, HALF);
		setNote(46, 71, HALF);
		setNote(47, 74, EIGTH);
		setNote(48, 72, EIGTH);
		setNote(49, 71, EIGTH);
		setNote(50, 0, EIGTH);
		setNote(51, 69, QUARTER);
		setNote(52, 67, EIGTH);
		setNote(53, 69, EIGTH);
		setNote(54, 74, DOTTED_QUART);
		setNote(55, 0, EIGTH);
		setNote(56, 71, DOTTED_QUART);
		setNote(57, 69, EIGTH);
		setNote(58, 76, DOTTED_QUART);
		setNote(59, 71, QUARTER);
		setNote(60, 69, QUARTER);
		setNote(61, 67, EIGTH);
		setNote(62, 66, EIGTH);
		setNote(63, 64, QUARTER);
		setNote(64, 59, EIGTH);
	}


	/*
	 *	Marble Machine Part 2
	 */
	if(num == 11){
		SLENGTH 		= 64;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 60, EIGTH);
		setNote(2, 66, EIGTH);
		setNote(3, 60, EIGTH);
		setNote(4, 64, EIGTH);
		setNote(5, 67, EIGTH);
		setNote(6, 62, EIGTH);
		setNote(7, 66, EIGTH);
		setNote(8, 69, EIGTH);
		setNote(9, 64, EIGTH);
		setNote(10, 71, EIGTH);
		setNote(11, 66, EIGTH);
		setNote(12, 67, EIGTH);
		setNote(13, 69, EIGTH);
		setNote(14, 76, HALF);
		setNote(15, 71, HALF);
		setNote(16, 69, EIGTH);
		setNote(17, 67, EIGTH);
		setNote(18, 69, QUARTER);
		setNote(19, 71, QUARTER);
		setNote(20, 67, EIGTH);
		setNote(21, 69, EIGTH);
		setNote(22, 74, HALF);
		setNote(23, 71, HALF);
		setNote(24, 69, EIGTH);
		setNote(25, 67, EIGTH);
		setNote(26, 69, QUARTER);
		setNote(27, 66, QUARTER);
		setNote(28, 67, EIGTH);
		setNote(29, 69, EIGTH);
		setNote(30, 74, DOTTED_QUART);
		setNote(31, 0, EIGTH);
		setNote(32, 71, DOTTED_QUART);
		setNote(33, 0, EIGTH);
		setNote(34, 74, EIGTH);
		setNote(35, 72, EIGTH);
		setNote(36, 71, QUARTER);
		setNote(37, 69, QUARTER);
		setNote(38, 67, EIGTH);
		setNote(39, 69, EIGTH);
		setNote(40, 64, HALF);
		setNote(41, 0, EIGTH);
		setNote(42, 71, DOTTED_QUART);
		setNote(43, 0, EIGTH);
		setNote(44, 74, EIGTH);
		setNote(45, 72, EIGTH);
		setNote(46, 71, QUARTER);
		setNote(47, 69, QUARTER);
		setNote(48, 67, EIGTH);
		setNote(49, 69, EIGTH);
		setNote(50, 76, DOTTED_QUART);
		setNote(51, 0, EIGTH);
		setNote(52, 71, HALF);
		setNote(53, 69, EIGTH);
		setNote(54, 67, EIGTH);
		setNote(55, 69, QUARTER);
		setNote(56, 71, QUARTER);
		setNote(57, 67, EIGTH);
		setNote(58, 69, EIGTH);
		setNote(59, 74, HALF);
		setNote(60, 71, HALF);
		setNote(61, 74, EIGTH);
		setNote(62, 72, EIGTH);
		setNote(63, 71, EIGTH);
		setNote(64, 0, EIGTH);
	}


	/*
	 *	Marble Machine Part 3
	 */
	if(num == 12){
		SLENGTH 		= 64;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 69, QUARTER);
		setNote(2, 67, EIGTH);
		setNote(3, 69, EIGTH);
		setNote(4, 74, DOTTED_QUART);
		setNote(5, 0, EIGTH);
		setNote(6, 71, DOTTED_QUART);
		setNote(7, 71, EIGTH);
		setNote(8, 76, QUARTER);
		setNote(9, 71, QUARTER);
		setNote(10, 69, QUARTER);
		setNote(11, 67, EIGTH);
		setNote(12, 66, EIGTH);
		setNote(13, 64, EIGTH);
		setNote(14, 64, QUARTER);
		setNote(15, 0, QUARTER);
		setNote(16, 0, HALF);
		setNote(17, 0, HALF);
		setNote(18, 0, QUARTER);
		setNote(19, 0, EIGTH);
		setNote(20, 76, EIGTH);

		setNote(21, 64, EIGTH);
		setNote(22, 71, EIGTH);
		setNote(23, 76, EIGTH);
		setNote(24, 64, EIGTH);

		setNote(25, 71, EIGTH);
		setNote(26, 76, EIGTH);
		setNote(27, 64, EIGTH);
		setNote(28, 71, EIGTH);

		setNote(29, 76, EIGTH);
		setNote(30, 64, EIGTH);
		setNote(31, 71, EIGTH);
		setNote(32, 76, EIGTH);

		setNote(33, 64, EIGTH);
		setNote(34, 71, EIGTH);
		setNote(35, 64, EIGTH);
		setNote(36, 74, EIGTH);

		setNote(37, 64, EIGTH);
		setNote(38, 67, EIGTH);
		setNote(39, 74, EIGTH);
		setNote(40, 62, EIGTH);

		setNote(41, 67, EIGTH);
		setNote(42, 74, EIGTH);
		setNote(43, 62, EIGTH);
		setNote(44, 67, EIGTH);

		setNote(45, 74, EIGTH);
		setNote(46, 62, EIGTH);
		setNote(47, 67, EIGTH);
		setNote(48, 74, EIGTH);

		setNote(49, 62, EIGTH);
		setNote(50, 71, EIGTH);
		setNote(51, 62, EIGTH);
		setNote(52, 74, EIGTH);

		setNote(53, 62, EIGTH);
		setNote(54, 66, EIGTH);
		setNote(55, 74, EIGTH);
		setNote(56, 62, EIGTH);

		setNote(57, 66, EIGTH);
		setNote(58, 74, EIGTH);
		setNote(59, 62, EIGTH);
		setNote(60, 66, EIGTH);

		setNote(61, 74, EIGTH);
		setNote(62, 62, EIGTH);
		setNote(63, 66, EIGTH);
		setNote(64, 74, EIGTH);
	}


	/*
	 *	Marble Machine Part 4
	 */
	if(num == 13){
		SLENGTH 		= 64;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 62, EIGTH);
		setNote(2, 71, EIGTH);
		setNote(3, 62, EIGTH);
		setNote(4, 67, EIGTH);

		setNote(5, 64, EIGTH);
		setNote(6, 66, EIGTH);
		setNote(7, 67, EIGTH);
		setNote(8, 64, EIGTH);

		setNote(9, 66, EIGTH);
		setNote(10, 67, EIGTH);
		setNote(11, 64, EIGTH);
		setNote(12, 69, EIGTH);

		setNote(13, 69, EIGTH);
		setNote(14, 62, EIGTH);
		setNote(15, 64, EIGTH);
		setNote(16, 66, EIGTH);

		setNote(17, 0, EIGTH);
		setNote(18, 67, EIGTH);
		setNote(19, 69, EIGTH);
		setNote(20, 76, EIGTH);

		setNote(21, 64, EIGTH);
		setNote(22, 71, EIGTH);
		setNote(23, 76, EIGTH);
		setNote(24, 64, EIGTH);

		setNote(25, 71, EIGTH);
		setNote(26, 76, EIGTH);
		setNote(27, 64, EIGTH);
		setNote(28, 71, EIGTH);

		setNote(29, 76, EIGTH);
		setNote(30, 64, EIGTH);
		setNote(31, 71, EIGTH);
		setNote(32, 76, EIGTH);

		setNote(33, 64, EIGTH);
		setNote(34, 76, EIGTH);
		setNote(35, 64, EIGTH);
		setNote(36, 74, EIGTH);

		setNote(37, 62, EIGTH);
		setNote(38, 67, EIGTH);
		setNote(39, 74, EIGTH);
		setNote(40, 62, EIGTH);

		setNote(41, 67, EIGTH);
		setNote(42, 74, EIGTH);
		setNote(43, 62, EIGTH);
		setNote(44, 67, EIGTH);

		setNote(45, 74, EIGTH);
		setNote(46, 62, EIGTH);
		setNote(47, 67, EIGTH);
		setNote(48, 74, EIGTH);

		setNote(49, 62, EIGTH);
		setNote(50, 71, EIGTH);
		setNote(51, 67, EIGTH);
		setNote(52, 78, EIGTH);

		setNote(53, 66, EIGTH);
		setNote(54, 71, EIGTH);
		setNote(55, 78, EIGTH);
		setNote(56, 66, EIGTH);

		setNote(57, 71, EIGTH);
		setNote(58, 78, EIGTH);
		setNote(59, 66, EIGTH);
		setNote(60, 71, EIGTH);

		setNote(61, 78, EIGTH);
		setNote(62, 66, EIGTH);
		setNote(63, 71, EIGTH);
		setNote(64, 78, EIGTH);
	}


	/*
	 *	Marble Machine Part 5
	 */
	if(num == 14){
		SLENGTH 		= 64;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 66, EIGTH);
		setNote(2, 78, EIGTH);
		setNote(3, 66, EIGTH);
		setNote(4, 76, EIGTH);

		setNote(5, 69, EIGTH);
		setNote(6, 72, EIGTH);
		setNote(7, 76, EIGTH);
		setNote(8, 69, EIGTH);

		setNote(9, 72, EIGTH);
		setNote(10, 76, EIGTH);
		setNote(11, 69, EIGTH);
		setNote(12, 78, EIGTH);

		setNote(13, 78, EIGTH);
		setNote(14, 71, EIGTH);
		setNote(15, 72, EIGTH);
		setNote(16, 79, EIGTH);

		setNote(17, 0, EIGTH);
		setNote(18, 74, EIGTH);
		setNote(19, 76, EIGTH);
		setNote(20, 83, EIGTH);

		setNote(21, 71, EIGTH);
		setNote(22, 76, EIGTH);
		setNote(23, 83, EIGTH);
		setNote(24, 71, EIGTH);

		setNote(25, 76, EIGTH);
		setNote(26, 83, EIGTH);
		setNote(27, 71, EIGTH);
		setNote(28, 76, EIGTH);

		setNote(29, 83, EIGTH);
		setNote(30, 71, EIGTH);
		setNote(31, 76, EIGTH);
		setNote(32, 83, EIGTH);

		setNote(33, 71, EIGTH);
		setNote(34, 83, EIGTH);
		setNote(35, 71, EIGTH);
		setNote(36, 78, EIGTH);

		setNote(37, 66, EIGTH);
		setNote(38, 71, EIGTH);
		setNote(39, 78, EIGTH);
		setNote(40, 66, EIGTH);

		setNote(41, 71, EIGTH);
		setNote(42, 78, EIGTH);
		setNote(43, 66, EIGTH);
		setNote(44, 71, EIGTH);

		setNote(45, 78, EIGTH);
		setNote(46, 66, EIGTH);
		setNote(47, 71, EIGTH);
		setNote(48, 78, EIGTH);

		setNote(49, 66, EIGTH);
		setNote(50, 78, EIGTH);
		setNote(51, 66, EIGTH);
		setNote(52, 79, EIGTH);

		setNote(53, 67, EIGTH);
		setNote(54, 71, EIGTH);
		setNote(55, 79, EIGTH);
		setNote(56, 67, EIGTH);

		setNote(57, 71, EIGTH);
		setNote(58, 79, EIGTH);
		setNote(59, 67, EIGTH);
		setNote(60, 71, EIGTH);

		setNote(61, 79, EIGTH);
		setNote(62, 67, EIGTH);
		setNote(63, 71, EIGTH);
		setNote(64, 79, EIGTH);
	}

	/*
	 *	Marble Machine Part 6
	 */
	if(num == 15){
		SLENGTH 		= 64;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 67, EIGTH);
		setNote(2, 79, EIGTH);
		setNote(3, 67, EIGTH);
		setNote(4, 74, EIGTH);

		setNote(5, 67, EIGTH);
		setNote(6, 71, EIGTH);
		setNote(7, 74, EIGTH);
		setNote(8, 67, EIGTH);

		setNote(9, 71, EIGTH);
		setNote(10, 74, EIGTH);
		setNote(11, 67, EIGTH);
		setNote(12, 71, EIGTH);

		setNote(13, 74, EIGTH);
		setNote(14, 67, EIGTH);
		setNote(15, 71, EIGTH);
		setNote(16, 74, EIGTH);

		setNote(17, 67, EIGTH);
		setNote(18, 71, EIGTH);
		setNote(19, 67, EIGTH);
		setNote(20, 76, EIGTH);

		setNote(21, 64, EIGTH);
		setNote(22, 71, EIGTH);
		setNote(23, 76, EIGTH);
		setNote(24, 64, EIGTH);

		setNote(25, 71, EIGTH);
		setNote(26, 76, EIGTH);
		setNote(27, 64, EIGTH);
		setNote(28, 71, EIGTH);

		setNote(29, 76, EIGTH);
		setNote(30, 64, EIGTH);
		setNote(31, 71, EIGTH);
		setNote(32, 76, EIGTH);

		setNote(33, 64, EIGTH);
		setNote(34, 76, EIGTH);
		setNote(35, 64, EIGTH);
		setNote(36, 78, EIGTH);

		setNote(37, 66, EIGTH);
		setNote(38, 71, EIGTH);
		setNote(39, 78, EIGTH);
		setNote(40, 66, EIGTH);

		setNote(41, 71, EIGTH);
		setNote(42, 78, EIGTH);
		setNote(43, 66, EIGTH);
		setNote(44, 71, EIGTH);

		setNote(45, 78, EIGTH);
		setNote(46, 66, EIGTH);
		setNote(47, 71, EIGTH);
		setNote(48, 78, EIGTH);

		setNote(49, 66, EIGTH);
		setNote(50, 78, EIGTH);
		setNote(51, 66, EIGTH);
		setNote(52, 78, EIGTH);

		setNote(53, 64, EIGTH);
		setNote(54, 71, EIGTH);
		setNote(55, 78, EIGTH);
		setNote(56, 66, EIGTH);

		setNote(57, 71, EIGTH);
		setNote(58, 78, EIGTH);
		setNote(59, 66, EIGTH);
		setNote(60, 71, EIGTH);

		setNote(61, 78, EIGTH);
		setNote(62, 66, EIGTH);
		setNote(63, 71, EIGTH);
		setNote(64, 78, EIGTH);
	}

	/*
	 *	Marble Machine Part 7
	 */
	if(num == 16){
		SLENGTH 		= 63;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 66, EIGTH);
		setNote(2, 78, EIGTH);
		setNote(3, 66, EIGTH);
		setNote(4, 76, QUARTER);

		setNote(5, 71, EIGTH);
		setNote(6, 72, EIGTH);
		setNote(7, 78, EIGTH);
		setNote(8, 72, EIGTH);
		setNote(9, 76, EIGTH);
		setNote(10, 79, EIGTH);
		setNote(11, 74, EIGTH);
		setNote(12, 78, EIGTH);
		setNote(13, 81, EIGTH);
		setNote(14, 76, EIGTH);
		setNote(15, 83, EIGTH);
		setNote(16, 78, EIGTH);
		setNote(17, 79, EIGTH);
		setNote(18, 81, EIGTH);
		setNote(19, 88, DOTTED_QUART);
		setNote(20, 76, EIGTH);
		setNote(21, 83, DOTTED_QUART);
		setNote(22, 76, EIGTH);
		setNote(23, 81, EIGTH);
		setNote(24, 79, EIGTH);
		setNote(25, 81, EIGTH);
		setNote(26, 76, EIGTH);
		setNote(27, 83, QUARTER);
		setNote(28, 79, EIGTH);
		setNote(29, 81, EIGTH);
		setNote(30, 86, DOTTED_QUART);
		setNote(31, 78, EIGTH);
		setNote(32, 83, DOTTED_QUART);
		setNote(33, 78, EIGTH);
		setNote(34, 81, EIGTH);
		setNote(35, 79, EIGTH);
		setNote(36, 81, EIGTH);
		setNote(37, 74, EIGTH);
		setNote(38, 78, QUARTER);
		setNote(39, 79, EIGTH);
		setNote(40, 81, EIGTH);
		setNote(41, 86, DOTTED_QUART);
		setNote(42, 76, EIGTH);
		setNote(43, 83, DOTTED_QUART);
		setNote(44, 76, EIGTH);
		setNote(45, 86, EIGTH);
		setNote(46, 84, EIGTH);
		setNote(47, 83, EIGTH);
		setNote(48, 76, EIGTH);
		setNote(49, 81, QUARTER);
		setNote(50, 79, EIGTH);
		setNote(51, 81, EIGTH);
		setNote(52, 76, DOTTED_QUART);
		setNote(53, 72, EIGTH);
		setNote(54, 73, DOTTED_QUART);
		setNote(55, 72, EIGTH);
		setNote(56, 86, EIGTH);
		setNote(57, 84, EIGTH);
		setNote(58, 83, EIGTH);
		setNote(59, 74, HALF);
		setNote(60, 81, QUARTER);
		setNote(61, 79, EIGTH);
		setNote(62, 81, EIGTH);
		setNote(63, 86, DOTTED_QUART);
	}


	/*
	 *	Marble Machine Part 8
	 */
	if(num == 17){
		SLENGTH 		= 54;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;
		TRIP_EIGTH		= 8;

		setNote(1, 76, EIGTH);
		setNote(2, 83, DOTTED_QUART);
		setNote(3, 76, EIGTH);
		setNote(4, 86, EIGTH);
		setNote(5, 84, EIGTH);
		setNote(6, 83, EIGTH);
		setNote(7, 76, EIGTH);
		setNote(8, 81, QUARTER);
		setNote(9, 79, EIGTH);
		setNote(10, 81, EIGTH);
		setNote(11, 76, DOTTED_QUART);
		setNote(12, 72, EIGTH);
		setNote(13, 83, DOTTED_QUART);
		setNote(14, 72, EIGTH);
		setNote(15, 86, EIGTH);
		setNote(16, 84, EIGTH);
		setNote(17, 83, EIGTH);
		setNote(18, 74, EIGTH);
		setNote(19, 81, QUARTER);
		setNote(20, 79, EIGTH);
		setNote(21, 81, EIGTH);
		setNote(22, 86, DOTTED_QUART);
		setNote(23, 76, EIGTH);
		setNote(24, 83, DOTTED_QUART);
		setNote(25, 76, EIGTH);
		setNote(26, 81, EIGTH);
		setNote(27, 79, EIGTH);
		setNote(28, 81, EIGTH);
		setNote(29, 76, EIGTH);
		setNote(30, 83, DOTTED_EIGTH);
		setNote(31, 79, EIGTH);
		setNote(32, 81, EIGTH);
		setNote(33, 86, DOTTED_EIGTH);
		setNote(34, 78, EIGTH);
		setNote(35, 83, DOTTED_EIGTH);
		setNote(36, 78, EIGTH);
		setNote(37, 86, EIGTH);
		setNote(38, 84, EIGTH);
		setNote(39, 83, EIGTH);
		setNote(40, 78, EIGTH);
		setNote(41, 81, QUARTER);
		setNote(42, 79, EIGTH);
		setNote(43, 81, EIGTH);
		setNote(44, 86, DOTTED_QUART);
		setNote(45, 79, EIGTH);
		setNote(46, 83, DOTTED_QUART);
		setNote(47, 81, EIGTH);
		setNote(48, 86, QUARTER);
		setNote(49, 83, EIGTH);
		setNote(50, 78, EIGTH);
		setNote(51, 81, QUARTER);
		setNote(52, 79, EIGTH);
		setNote(53, 78, EIGTH);
		setNote(54, 76, DOTTED_HALF);
	}

	/*
	 *	Office Theme Part 1
	 */
	if(num == 18){
		SLENGTH 		= 64;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;
		TRIP_EIGTH		= 8;

		setNote(1, 74, EIGTH);
		setNote(2, 67, EIGTH);
		setNote(3, 74, HALF);
		setNote(4, 74, EIGTH);

		setNote(5, 67, EIGTH);
		setNote(6, 74, EIGTH);
		setNote(7, 66, EIGTH);
		setNote(8, 74, HALF);
		setNote(9, 74, EIGTH);
		setNote(10, 66, EIGTH);
		setNote(11, 76, EIGTH);
		setNote(12, 76, EIGTH);
		setNote(13, 76, HALF);
		setNote(14, 76, EIGTH);
		setNote(15, 67, EIGTH);
		setNote(16, 76, QUARTER);
		setNote(17, 76, QUARTER);
		setNote(18, 76, EIGTH);
		setNote(19, 71, EIGTH);
		setNote(20, 69, EIGTH);
		setNote(21, 71, EIGTH);
		setNote(22, 71, EIGTH);
		setNote(23, 67, EIGTH);
		setNote(24, 71, HALF);
		setNote(25, 71, EIGTH);
		setNote(26, 67, EIGTH);
		setNote(27, 71, EIGTH);
		setNote(28, 66, EIGTH);
		setNote(29, 71, HALF);
		setNote(30, 71, EIGTH);
		setNote(31, 66, EIGTH);
		setNote(32, 71, EIGTH);
		setNote(33, 67, EIGTH);
		setNote(34, 71, HALF);
		setNote(35, 71, EIGTH);
		setNote(36, 67, EIGTH);
		setNote(37, 72, QUARTER);
		setNote(38, 72, QUARTER);
		setNote(39, 72, EIGTH);
		setNote(40, 71, EIGTH);
		setNote(41, 69, EIGTH);
		setNote(42, 71, EIGTH);
		setNote(43, 67, HALF);
		setNote(44, 79, HALF);
		setNote(45, 0, HALF);
		setNote(46, 78, EIGTH);
		setNote(47, 79, EIGTH);
		setNote(48, 78, EIGTH);
		setNote(49, 74, EIGTH);
		setNote(50, 76, HALF);
		setNote(51, 76, QUARTER);
		setNote(52, 76, QUARTER);
		setNote(53, 72, QUARTER);
		setNote(54, 72, QUARTER);
		setNote(55, 72, EIGTH);
		setNote(56, 71, EIGTH);
		setNote(57, 69, EIGTH);
		setNote(58, 71, EIGTH);
		setNote(59, 67, HALF);
		setNote(60, 79, HALF);
		setNote(61, 0, HALF);
		setNote(62, 78, EIGTH);
		setNote(66, 79, EIGTH);
		setNote(64, 81, EIGTH);
	}


	/*
	 *	Office Theme Part 2
	 */
	if(num == 19){
		SLENGTH 		= 41;

		HALF			= 48;
		QUARTER 		= 24;
		EIGTH 			= 12;
		SIXTEENTH 		= 6;
		DOTTED_QUART	= 36;
		DOTTED_EIGTH	= 18;
		DOTTED_HALF		= 72;

		setNote(1, 78, EIGTH);
		setNote(2, 76, HALF);
		setNote(3, 76, QUARTER);
		setNote(4, 76, QUARTER);
		setNote(5, 72, QUARTER);

		setNote(6, 72, QUARTER);
		setNote(7, 72, EIGTH);
		setNote(8, 71, EIGTH);
		setNote(9, 69, EIGTH);
		setNote(10, 71, EIGTH);
		setNote(11, 74, EIGTH);
		setNote(12, 67, EIGTH);
		setNote(13, 74, HALF);
		setNote(14, 74, EIGTH);
		setNote(15, 69, EIGTH);
		setNote(16, 74, EIGTH);
		setNote(17, 66, EIGTH);
		setNote(18, 74, HALF);
		setNote(19, 74, EIGTH);
		setNote(20, 66, EIGTH);
		setNote(21, 76, EIGTH);
		setNote(22, 67, EIGTH);
		setNote(23, 76, HALF);
		setNote(24, 76, EIGTH);
		setNote(25, 67, EIGTH);
		setNote(26, 76, QUARTER);
		setNote(27, 76, QUARTER);
		setNote(28, 76, EIGTH);
		setNote(29, 71, EIGTH);
		setNote(30, 69, EIGTH);
		setNote(31, 67, EIGTH);
		setNote(32, 67, TRIP_EIGTH);
		setNote(33, 62, TRIP_EIGTH);
		setNote(34, 67, TRIP_EIGTH);
		setNote(35, 71, TRIP_EIGTH);
		setNote(36, 67, TRIP_EIGTH);
		setNote(37, 71, TRIP_EIGTH);
		setNote(38, 74, TRIP_EIGTH);
		setNote(39, 71, TRIP_EIGTH);
		setNote(40, 74, TRIP_EIGTH);
		setNote(41, 79, QUARTER);
	}
}

/*
 * load_song: Used for loading the selected song into memory
 */
void load_song(){
	unsigned char notes[16];
	unsigned char dur[16];
	struct note* temp;

	int i, j;

	for(i = 0; i < 4; i++){
		memset(notes, 0, 16);
		memset(dur, 0, 16);

		temp = getSong(i);

		for(j = 0; j < getSize(i+1); j++){
			notes[j] = temp[j].note;
			dur[j] = temp[j].dur;
		}

		oi_loadSong(i, getSize(i+1), notes, dur);
	}
}

/*
 * music_init: Easy to call method for automating the music portion of our code
 *
 * @param numsong: Which song we want to load
 */
void music_init(int numsong){
	int i;

	for(i = 0; i < LENGTH; i++){
		song[i].note = 0;
		song[i].dur = 0;
	}

	set_song(numsong);
	load_song();
}

/*
 * getSize: Breaks a number into sections of 16
 *
 * @param num: Number to be checked against
 * @return length of the the array
 */
int getSize(int num){
	if(SLENGTH/16*num) return 16;
	else return(SLENGTH - 16*(num-1));
}

/*
 * getSong: Gets the index for the selected song
 *
 * @param num: Song index
 * @return The pointer for where the first note starts
 */
struct note* getSong(int num){
	return &(song[num*16]);
}

/*
 * setNote: sets the note length and frequency
 *
 * @param index: which note in the array to set
 * @param note: frequency of the note
 * @param dur: duration of the note
 */
void setNote(int index, int note, int dur){
	song[index-1].note = note;
	song[index-1].dur = dur;
}






















