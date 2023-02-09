//
// Created by Jonah Levis on 2/5/23.
//

#ifndef EECE2560LOCKBOX_LOCKBOX_H
#define EECE2560LOCKBOX_LOCKBOX_H
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
class LockBox 
{
    private:
        vector<int> code;
        int n;
        int m;
        
    public:
        /**
         * @brief Construct a new Lock Box object
         * 
         * @param p size of the guess
         * @param q range of values for the guess
         */
        LockBox(int p = 5, int q = 10);

        /**
         * @brief Returns the amount of correct digits in the correct spots
         * 
         * @param guess A lockbox containing a guess code
         * @return int The number of correct digits in the correct spot
         */
        int correctLocation(LockBox guess);

        /**
         * @brief Returns the amount of correct digits in the wrong spot
         * 
         * @param guess A lockbox containing the guess code
         * @return int the number of correct digits in the wrong spot
         */
        int incorrectLocation(LockBox guess);

        /**
         * @brief Get the Code member variable
         * 
         * @return vector<int> the code
         */
        vector<int> getCode() const;

        /**
         * @brief Set the Code member variable
         * 
         * @param newcode The code you want to add to the lockbox
         */
        void setCode(vector<int> newcode);
        
        /**
         * @brief Get the Digits member variable
         * 
         * @return int length of the code
         */
        int getDigits();

        /**
         * @brief Get the Range member variable
         * 
         * @return int range of values
         */
        int getRange();

};

#include "LockBox.cpp"
#endif //EECE2560LOCKBOX_LOCKBOX_H
