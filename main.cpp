#include <cstddef>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <stddef.h>
#include "SmartClient.h"


using namespace std;


int main()
{


SmartClient client = SmartClient(5, 5);

client.openLockBox();



return 0;
}