/*

a) This fucntion calculates a random number in the interval [low, high]. The assert statement is used to stop program execution in case 'high' is lower than 'low'

b) Since the function has default arguments, it can be called in 3 different ways: rollDie(), rollDie(num), rollDie(num1, num2)

c) No, it is not, because the function, having both parameters as default, already has that prototype 

*/

#include <cmath>
#include <assert.h>

int rollDie(int low = 1, int high= 6) {
    assert(high >= low);
    
    return(rand() % (high - low + 1)) + low;
}