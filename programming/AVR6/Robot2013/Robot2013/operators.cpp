/*
 * operators.cpp
 *
 * Created: 5. 5. 2013 21:26:45
 *  Author: asaka
 */ 
#include "operators.h"

void * operator new(size_t size)
{
	return malloc(size);
}