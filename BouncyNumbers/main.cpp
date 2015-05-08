//
//  main.cpp
//  BouncyNumbers
//
//  Created by Joel Atyas on 5/8/15.
//  Copyright (c) 2015 Joel Atyas. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool is99PercentBouncy(int numTotal, int numBouncy);

bool iSBouncy(int numCurrent);

int main(int argc, const char * argv[])
{
    int numCurrent = 0;
    int numBouncy = 0;
    
    do
    {
        numCurrent++;
        if (iSBouncy(numCurrent))
            numBouncy++;
    }
    while (!is99PercentBouncy(numCurrent, numBouncy));
    
    cout << "99 percent bouncy occurs at number " << numCurrent << std::endl;
    
    return 0;
}

bool is99PercentBouncy(int numTotal, int numBouncy)
{
    if (100*numBouncy == 99*numTotal)
        return true;
    else
        return false;
}

bool iSBouncy(int numCurrent)
{
    vector<int> digits;
    
    int numTmp = numCurrent;
    int numRem = 0;
    int numBase = 10;
    
    do
    {
        numRem = numTmp % numBase;
        
        digits.push_back(numRem);
        
        numTmp = numTmp/numBase;
    }
    while (numTmp > 0);
    
    bool down = false;
    bool up = false;
    
    for (int index = 1; index < digits.size(); index++)
    {
        if (digits[index - 1] < digits[index])
        {
            up = true;
        }
        else if (digits[index - 1] > digits[index])
        {
            down = true;
        }
        
        if (down && up)
            return true;
    }
    
    return down && up;
}