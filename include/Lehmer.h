/*
    File: Lehmer.h
    Description: The header file for the Lehmer random number algorithim. 
    This generates random numbers for the game to use. (Originally used by javidx9 in this video: https://www.youtube.com/watch?v=ZZY9YE7rZJw)
    Date: Monday, March 16th 2020 12:21 PM
*/

#ifndef LEHMER_INCLUDED
#define LEHMER_INCLUDED

#include "data.h"

extern uint32_t nLehmer; /* This is what the seed will be (the starting number of the algorithim, which gets set to the system time) */
uint32_t  Lehmer32();

#endif /* LEHMER_INCLUDED */