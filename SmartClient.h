#ifndef SMARTCLIENT_H
#define SMARTCLIENT_H

#include <cstddef>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stddef.h>
#include <vector>

#include "ClientFeedback.h"
#include "LockBox.h"

using namespace std;
 
class SmartClient 
{
    
  private:

    ClientFeedback feedback;
    LockBox box;
    
  public:

    /**
     * @brief Construct a new Smart Client object
     * 
     * @param n size of box code
     * @param m range of box code
     */
    SmartClient(int n, int m);
    
    /**
     * @brief Get the Box object
     * 
     * @return LockBox the box object
     */
    LockBox getBox();

    /**
     * @brief Returns the code from the box
     * 
     * @return vector<int> 
     */
    vector<int> printCode();

    /**
     * @brief Gets the client's guess for the code
     * 
     * @return LockBox containing clients guess
     */
    LockBox clientGuess();
    
    /**
     * @brief Get the Feedback object based on the guess
     * 
     * @param Guess LockBox object containing client guess
     * @return ClientFeedback feedback object containing information about guess
     */
    ClientFeedback getFeedback(LockBox Guess);
    
    /**
     * @brief Checks to see if the guess is the same as the code based on the feedback
     * 
     * @param feedback 
     * @return true 
     * @return false 
     */
    bool isOpened(ClientFeedback feedback);

    /**
     * @brief Runs the rest of the functions in the class to get the user input and 
     *        allows 5 guesses until the program exits.
     * 
     */
    void openLockBox();
  
  
};
#include "SmartClient.cpp"

#endif