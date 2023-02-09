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


class ClientFeedback {
  
  //The first response value is the number of digits that are the right digit in the right location. The second response value is the number of digits that are the right digit in the wrong location.
  
  //vector<int> response(2);
  
  int response[2];
  


public:
  
  ClientFeedback();
  
  int getFirst();
  
   int getLast();
  
  void setFirst(LockBox box, LockBox guess);
  
  void setLast(LockBox box, LockBox guess);
  
  friend bool operator== (const LockBox box, const LockBox guess);
  
  LockBox getBox(LockBox guess);
  
  /*
  void operator<< (ClientFeedback feedback);
  */
  
  friend ostream & operator << (ostream &out, ClientFeedback feedback);




};
#include "ClientFeedback.cpp"

#endif