#include "mylib.h"

int mylib_add(int a, int b){
    return a+b;
}

int mylib_substract(int a, int b){
    return a-b;
}

int mylib_multiply(int a, int b){
    return a*b;
}

int mylib_divide(int a, int b){
    return a/b;
}

int mylib_power(int a, int b){
	int result = 1;
	while(b--) result*=a;
    return result;
}
