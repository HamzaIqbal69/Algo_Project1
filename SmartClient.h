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
 
class SmartClient {
  
    ClientFeedback feedback;

    LockBox box;
  
  
  
public:

  SmartClient(int n, int m);
  
  
  LockBox getBox();


  vector<int> printCode();

  //function that gets sectret code {.getCode()}!!!!!!!!

  LockBox clientGuess();
  
  ClientFeedback getFeedback(LockBox Guess);
  
  bool isOpened(ClientFeedback feedback);
  
  void openLockBox();
  
  
};
#include "SmartClient.cpp"

#endif