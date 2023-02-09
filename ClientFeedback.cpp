#include "ClientFeedback.h"



ClientFeedback :: ClientFeedback()
{
}


int ClientFeedback :: getFirst()
{
  return response[0];
}

int ClientFeedback :: getLast()
{
  return response[1];
}



void ClientFeedback :: setFirst(LockBox box, LockBox guess)
{
  response[0] = box.correctLocation(guess);
}


void ClientFeedback :: setLast(LockBox box, LockBox guess)
{
  response[1] = box.incorrectLocation(guess);

}



bool operator== (const LockBox box, const LockBox guess)
{
  for (int i = 0; i < box.getCode().size(); i++)
  if ((box.getCode())[i] != (guess.getCode())[i]){
    return false;
  }
  
  return true;

}


ostream & operator << (ostream &out, ClientFeedback feedback)
{
    out << feedback.getFirst() << " " << feedback.getLast()<<endl;
    return out;
}