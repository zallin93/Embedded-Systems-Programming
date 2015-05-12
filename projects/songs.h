/*
 * songs.h
 *
 *  Created on: Feb 12, 2015
 *      Author: ben
 */

#ifndef SONGS_H_
#define SONGS_H_

//The spacing of nerves on the basilar membrane (our hearing organ)
//detects logarithmic changes (not spaced absolutely, the ratio of
//frequency detected by one nerve group to the next is the same
//across the organ).
//Double a note's frequency to go up an octave,
//half it to go down an octave
//Since there are 12 half-steps per octave, multiple
//a note's frequency by about 1.06 to go up a note
//There are 7 full steps (A, B, C, D, E, F, G) but
//only 5 half steps (A#/Bb, C#/Db, D#/Eb, F#/Gb, G#/Ab).
//"Concert A" is A4, which is 440Hz in modern music
/*
const unsigned int a4 = 440;
const unsigned int b4 = 494;
const unsigned int c5 = 523;
const unsigned int d5 = 587;
const unsigned int e5 = 659;
const unsigned int f5 = 698;
const unsigned int g5 = 784;
*/
#define rest 3

#define c3 131
#define c3s 139
#define d3 147
#define d3s 156
#define e3 165
#define f3 175
#define f3s 185
#define g3 196
#define g3s 208

#define a3 220
#define a3s 233
#define b3 247
#define c4 262
#define c4s 277
#define d4 294
#define d4s 311
#define e4 330
#define f4 349
#define f4s 370
#define g4 392
#define g4s 415

#define a4 440
#define a4s 466
#define b4 494
#define c5 523
#define c5s 554
#define d5 587
#define d5s 622
#define e5 659
#define f5 698
#define f5s 740
#define g5 784
#define g5s 831
#define a5s 932
#define b5 988

const unsigned int a_major[] = {a4, b4, c5s, d5, e5, f5s, g5s};
const unsigned int twinkle_twinkle[] = {
		a4, a4, e5, e5, f5s, f5s, e5, d5, d5, c5s, c5s, b4, b4, a4,
		f5s, f5s, e5, e5, d5, d5, c5s, f5s, f5s, e5, e5, d5, d5, c5s,
		a4, a4, e5, e5, f5s, f5s, e5, d5, d5, c5s, c5s, b4, f5s, a4
};
const unsigned int twinkle_durations[] = {
		1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,
		1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,
		1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2
};
//Total number of notes in the song
//const unsigned int total_notes = 42;
//const unsigned int quarter_note = 4000;

const unsigned int tetris_theme[] = {
		rest, rest, rest, e4,
		e4, b4, c5, d5, c5, b4,
		a4, a4, c5, e5, d5, c5, 
		b4, b4, c5, d5, e5, 
		c5, a4, a4, rest,
		d5, f5, a5, g5, f5,
		e5, c5, e5, d5, c5, 
		b4, b4, c5, d5, e5,
		c5, a4, a4, rest,
		e4, c4, 
		d4, b3, 
		c4, a3,
		g3s, b3, 
		e4, c4, 
		d4, b3,
		c4, e4, a4, a4, 
		g4s
};

const unsigned int tetris_durations[] = {
		2, 2, 2, 2, 
		2, 1, 1, 2, 1, 1, 
		2, 1, 1, 2, 1, 1, 
		2, 1, 1, 2, 2, 
		2, 2, 2, 2, 
		3, 1, 2, 1, 1, 
		3, 1, 2, 1, 1, 
		2, 1, 1, 2, 2, 
		2, 2, 2, 2, 
		4, 4, 
		4, 4, 
		4, 4, 
		4, 4, 
		4, 4, 
		4, 4,
		2, 2, 2, 2, 
		8  
};
// one beat is an eighth note
// const unsigned int total_notes = sizeof(tetris_theme)/sizeof(unsigned int);
// we want 144 bpm. 15625 ticks / (144 * 2 / 60seconds_per_minute) = 15625/4.8= 3255.2
// const unsigned int quarter_note = 3255;


// 15625ticks_per_second/(150bpm*4quarter_per_beat/60seconds_per_minute)

const unsigned int irish_washerwoman[] = {
		b4, g4, g4, d4, g4, g4, b4, g4, b4, d5, c5, b4,
		c5, a4, a4, e4, a4, a4, c5, a4, c5, e5, d5, c5,
		b4, g4, g4, d4, g4, g4, b4, g4, b4, d5, c5, b4,
		c5, b4, c5, a4, d5, c5, b4, g4, g4, g4, //End of part 1
		b4, g4, g4, d4, g4, g4, b4, g4, b4, b4, a4, g4,
		a4, f4, f4, d4, f4, f4, a4, f4, a4, a4, g4, f4,
		e4, g4, g4, d4, g4, g4, c4, g4, g4, b3, g4, g4,
		c5, b4, c5, a4, d5, c5, b4, g4, g4, g4, //End of part 2
		b4, g4, g4, d4, rest, g4, b4, g4, b4, d5, c5, b4,
		c5, a4, a4, e4, rest, a4, c5, a4, c5, e5, d5, c5,
		b4, g4, g4, d4, g4, g4, b4, g4, b4, d5, c5, b4,
		c5, b4, c5, a4, d5, c5, b4, g4, g4, g4, //End of part 1
		b4, g4, g4, d4, g4, g4, b4, g4, b4, b4, a4, g4,
		a4, f4, f4, d4, f4, f4, a4, f4, a4, a4, g4, f4,
		e4, g4, g4, d4, g4, g4, c4, g4, g4, b3, g4, g4,
		c5, b4, c5, a4, d5, c5, b4, g4, g4, g4
};
const unsigned int washerwoman_durations[] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 3
};
//Total number of notes in the song
unsigned int total_notes = sizeof(irish_washerwoman) / sizeof(unsigned int);
//const unsigned int quarter_note = 1953;
const unsigned int note_duration = 1953;

//Will list the zelda theme in 8th notes, it is in 4/4 time
const unsigned int zelda_theme[] = {
		a4s, rest, a4s, a4s, a4s, a4s,
		a4s, g4s, a4s, rest, a4s, a4s, a4s, a4s,
		a4s, g4s, a4s, rest, a4s, a4s, a4s, a4s,
		a4s, g3s, g3s, g3s, g3s, g3s, g3s, g3s, g3s, g3s, g3s,
		a4s, f3, f3, a4s, a4s, c5, d5, d5s,
		f5, rest, f5, f5, f5s, g5s,
		a5s, rest, a5s, a5s, a5s, g5s, f5s
};
const unsigned int zelda_durations[] = {
		36, 16, 8, 8, 8, 8,
		7, 5, 12, 16, 8, 8, 8, 8,
		7, 5, 12, 16, 8, 8, 8, 8,
		8, 5, 5, 8, 5, 5, 8, 5, 5, 9, 9,
		18, 18, 10, 8, 8, 9, 8, 9,
		36, 16, 8, 8, 8, 8,
		36, 8, 8, 8, 8, 8, 8
};
//Total number of notes in the song
//unsigned int total_notes = sizeof(zelda_theme)/sizeof(unsigned int);
//Theme is 150 bpm, so 15625ticks_per_second/(150bpm*4quarter_per_beat/60seconds_per_minute)
//So each quarter note is 1562 in duration, but we need to divide the 4/4 space into
//72 parts to fit all of the different duration notes; 1562.5/72 ~= 22
//const unsigned int quarter_note = 44;

#endif /* SONGS_H_ */