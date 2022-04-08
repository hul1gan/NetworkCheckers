#pragma once

struct MyPair
{
    MyPair(int newIn, int checkIn) : newIndex(newIn), indexOfChecker(checkIn){}

    int newIndex;
    int indexOfChecker;
};
