//
// Created by Jonah Levis on 2/5/23.
//

#include "LockBox.h"
using namespace std;
LockBox::LockBox(int p, int q) {
    n = p;
    m = q;
    for (int i = 0; i < p; i ++) {
        code.push_back(rand()%q);
    }
}


vector<int> LockBox::getCode() const 
{
    return code;
}


void LockBox :: setCode(vector<int> newcode){
  code = newcode;
}


int LockBox :: getDigits(){
  return n;
}


int LockBox :: getRange(){
  return m;
}


int LockBox::correctLocation(LockBox guess) {
    vector<int> compare = guess.getCode();
    int c = 0;
    for (int i = 0; i < compare.size(); i++) {
        if (code.at(i) == compare.at(i)) {
            c++;
        }
    }
    return c;
}

/*
int LockBox::incorrectLocation(LockBox guess) {
    int num_correct = correctLocation(guess);
    vector<int> compare = guess.getCode();
    int c = 0;
    for (int i = 0; i < code.size(); i++) {
        for (int j = 0; j < compare.size(); j++) {
            if (i == j) {
                continue;
            }
            else if (code.at(i) == compare.at(j)) {
                c++;
                compare.at(j) = -1;
            }
        }
    }
    return c - num_correct;
}
*/

int LockBox::incorrectLocation(LockBox guess) {
    int correct = correctLocation(guess);
    vector<int> copy;
    for (int i = 0; i < code.size(); i ++) {
        copy.push_back(code.at(i));
    }
    vector<int> compare = guess.getCode();
    int c = 0;
    for (int i = 0; i < copy.size(); i++) {
        for (int j = 0; j < compare.size(); j++) {
            if (i == j) {
                continue;
            }
            else if (copy.at(i) == compare.at(j)) {
                c++;
                copy.at(i) = -1;
                compare.at(j) = -2;
                break;
            }
        }
    }
    return c-correct;
}
