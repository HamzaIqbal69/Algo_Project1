#include <cstddef>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stddef.h>
#include "SmartClient.h"


SmartClient :: SmartClient(int n, int m) 
{
  box = LockBox(n, m);
}


LockBox SmartClient :: getBox(){
  return box;
}


LockBox SmartClient :: clientGuess()
{
  vector<int> guess_vect;
  LockBox guessBox = LockBox();
  for(int i = 0; i < box.getRange(); i++)
  {
    int input;
    cout << "Enter a digit of your code: ";
    cin >> input;
    guess_vect.push_back(input);
  }
  guessBox.setCode(guess_vect);
  return guessBox;
}



vector<int> SmartClient:: printCode()
{
  return box.getCode();
}



ClientFeedback SmartClient :: getFeedback(LockBox Guess)
{
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


void SmartClient :: openLockBox()
{
  LockBox guess;
  
  cout << "The code is: " << endl;
  
  for(int i = 0; i < box.getCode().size(); i++)
  {
    cout << box.getCode()[i] << ", ";
  }
  
  cout << endl;
  int count = 0;
  
  while (count <= 5)
  {
    cout << (5 - count) << " guesses left" << endl;
    guess = clientGuess();
    cout << "Guess is: ";
    for(int i = 0; i < guess.getCode().size(); i++)
    {
      cout << guess.getCode()[i] << ", ";
    }
    cout << endl;
    
    if(box == guess)
    {
      cout << "Success!";
      break;
    }
    cout << (getFeedback(guess));
    
    count++;
  }
}



  
