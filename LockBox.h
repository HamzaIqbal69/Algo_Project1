//
// Created by Jonah Levis on 2/5/23.
//

#ifndef EECE2560LOCKBOX_LOCKBOX_H
#define EECE2560LOCKBOX_LOCKBOX_H
#import <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
class LockBox {
private:
    vector<int> code;
    int n;
    int m;
    
public:
    LockBox(int p = 5, int q = 10);
    int correctLocation(LockBox guess);
    int incorrectLocation(LockBox guess);
    vector<int> getCode();
    void setCode(vector<int> newcode);
    
    int getDigits();
    int getRange();

};


#endif //EECE2560LOCKBOX_LOCKBOX_H
