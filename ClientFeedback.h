#ifndef CLIENTFEEDBACK_H
#define CLIENTFEEDBACK_H

#include <cstddef>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stddef.h>
#include "LockBox.h"
using namespace std;


class ClientFeedback 
{
    
    //The first response value is the number of digits that are the right digit in the right location. The second response value is the number of digits that are the right digit in the wrong location.
    
    //vector<int> response(2);
  private:

    int response[2];
    

  public:
    
    /**
     * @brief Construct a new Client Feedback object
     * 
     */
    ClientFeedback();
    
    /**
     * @brief Get the first element of the response
     * 
     * @return int 
     */
    int getFirst();
    
    /**
     * @brief Get the second element of the response
     * 
     * @return int 
     */
    int getLast();
    
    /**
     * @brief Set the First object by figuring out the number of correct element 
     *        in the correct spot
     * 
     * @param box box we are trying to crack
     * @param guess  box with guess code
     */
    void setFirst(LockBox box, LockBox guess);
    
    /**
     * @brief Set the Second object by figuring out the number of correct elements
     *        in the incorrect spot
     * 
     * @param box box we are trying to crack
     * @param guess box with guess code
     */
    void setLast(LockBox box, LockBox guess);
    
    /**
     * @brief Checks to see if the codes are equal
     * 
     * @param box 
     * @param guess 
     * @return true 
     * @return false 
     */
    friend bool operator== (const LockBox box, const LockBox guess);

    /**
     * @brief Prints out the feedback
     * 
     * @param out 
     * @param feedback 
     * @return * ostream& 
     */
    friend ostream & operator << (ostream &out, ClientFeedback feedback);

};
#include "ClientFeedback.cpp"

#endif