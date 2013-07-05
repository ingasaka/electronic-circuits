/*
 * main.h
 *
 * Created: 5. 5. 2013 20:04:09
 *  Author: asaka
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define  F_CPU 1000000L

#define H(a,b) a |=(1<<(b))
#define L(a,b) a &=~(1<<(b))
#define IS(a,b) bit_is_set(a,b)
#define BS(a,b) (a & (1<<(b)))



#endif /* MAIN_H_ */