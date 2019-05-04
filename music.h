/*
 * music.h: Header file for the music file
 *
 *  Created on: Apr 20, 2019
 *      Author: ryanjl9
 */

#ifndef MUSIC_H_
#define MUSIC_H_

/*
 * Tetris theme A
 * 175 bpm
 * 57 notes
 * 2.91 bps
 * Quarter Note = 22
 *
 * Megalovania
 * 120 bpm
 * 44 notes
 * 2 bps
 * Quarter Note = 32
 *
 * Legend of Zelda
 * 115 bpm
 * 136 notes
 * 2 bps
 * Quarter Note = 34
 *
 * Middle C = 60
 *
 * QUARTER NOTE = (1/(BEATS_PER_MINUTE/60))*64
 */

#include <open_interface.h>

#define LENGTH  65

/*
 * note: Struct for holding the values associated with a note
 */
struct note{
	char note;
	char dur;
};

void set_song(int num);
void load_song();
void music_init(int numsong);
int getSize(int num);
struct note* getSong(int num);
void setNote(int index, int note, int dur);
/*
 * SLENGTH: Length of the song
 */
int SLENGTH;

/*
 * Duration of notes. Made programming note in easier.
 */
int QUARTER;
int EIGTH;
int HALF;
int WHOLE;
int DOTTED;
int SIXTEENTH;
int DOTTED_EIGTH;
int THIRTYSECOND;
int QUARTER_TIESIX;
int HALF_TIESIX;
int TRIP_EIGTH;
int TRIP_QUART;
int DOTTED_QUART;
int DOTTED_HALF;
int DOTTED_EIGTH;

#endif /* MUSIC_H_ */











