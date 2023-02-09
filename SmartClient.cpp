#include <cstddef>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stddef.h>
#include "SmartClient.h"


SmartClient :: SmartClient(int n, int m) : box(n , m) {
  
}


LockBox SmartClient :: getBox(){
  return box;
}


LockBox SmartClient :: clientGuess(){
  vector<int> v;
  int number;
  cout << "Enter a guess for the code, as one number with no whitespaces" << endl;
  cin >> number;
  
  for (int i = 5; i >= 0; i--) {
    v[i] = number % 10;
    number /= 10;
  }
  
   for(int i =0; i<v.size(); i++){
      cout <<v[i];
    }
    
  LockBox guessBox;
  guessBox.setCode(v);
  
  return guessBox;
}



vector<int> SmartClient:: printCode(){
  return box.getCode();
}



ClientFeedback SmartClient :: getFeedback(LockBox Guess){
  feedback.setFirst(box, Guess);
  feedback.setLast(box, Guess);
  
  
  return feedback;
}

//a function isOpened() that is passed a ClientFeedback object and returns true if the ClientFeedback indicates that the lock box has been opened (correct lock code has been entered/guessed). [n, 0]



bool SmartClient :: isOpened(ClientFeedback feedback){

  if (feedback.getFirst() != box.getDigits()){
   return false;
   }
   
  if (feedback.getLast() != 0){
   return false;
   }
   
   return true;
   
}


void SmartClient :: openLockBox(){
  LockBox guess;
  
  while (true){
      guess = clientGuess();
      cout << (getFeedback(guess));
      
      if(box == guess){
        break;
      }
  }
}



  
