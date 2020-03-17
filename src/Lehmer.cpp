/*
    File: Lehmer.cpp
    Description: The source file for the Lehmer random number algorithim. 
    This generates random numbers for the game to use. (Originally used by javidx9 in this video: https://www.youtube.com/watch?v=ZZY9YE7rZJw)
    Date: Monday, March 16th 2020 12:26 PM
*/

#include "../include/Lehmer.h"

/*  This is what the seed will be (the starting number of the algorithim, which gets set to the system time) */
uint32_t nLehmer = 0; 

/* 
    This is the algorithim for generating a random number 
    I understand that it looks complicated, I did not make it but all it really is, is a starting number
    shuffled up using special hex numbers then put through different operations to make the output number
    unpredictable, thus generating seemingly random numbers
*/
uint32_t Lehmer32() 
{
    nLehmer += 0xe120fc15;                 
    uint64_t tmp;
    tmp = (uint64_t)nLehmer * 0x4a39b70d;   
    uint32_t m1 = (tmp >> 32) ^ tmp;
    tmp = (uint64_t)m1 * 0x12fad5c9;         
    uint32_t m2 = (tmp >> 32) ^ tmp;
    return m2;
}
