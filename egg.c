// KIT107 Assignment 2
/*
 * Implementation for Egg
 * Author Julian Dermoudy
 * Version 22/3/2021
 *
 * THIS FILE IS COMPLETE
 */

#include <stdio.h>
#include <stdlib.h>
#include "egg.h"

struct egg_int
{
	double volume;
	int weight;
	chocolate choc;
	wrapping wrap;
	filling fill;
};

/*
* 'Constructor' for egg
*/
void init_egg(egg *e, double v, int w, chocolate c, wrapping r, filling f)
{
	*e = (egg)malloc(sizeof(struct egg_int));
	(*e)->volume = v;
	(*e)->weight = w;
	(*e)->choc = c;
	(*e)->wrap = r;
	(*e)->fill = f;
}

/*
* Getter for volume
* Return volume field
*/
double get_volume(egg e)
{
	return (e->volume);
}

/*
* Getter for weight
* Return weight field
*/
int get_weight(egg e)
{
	return (e->weight);
}

/*
* Getter for choc
* Return choc field
*/
chocolate get_choc(egg e)
{
	return (e->choc);
}

/*
* Getter for wrap
* Return wrap field
*/
wrapping get_wrap(egg e)
{
	return (e->wrap);
}

/*
* Getter for fill
* Return fill field
*/
filling get_fill(egg e)
{
	return (e->fill);
}

/*
* Setter for volume
* Param v value to be placed into the egg's volume field
*/
void set_volume(egg e, double v)
{
	e->volume = v;
}

/*
* Setter for weight
* Param w value to be placed into the egg's weight field
*/
void set_weight(egg e, int w)
{
	e->weight = w;
}

/*
* Setter for choc
* Param c value to be placed into the egg's choc field
*/
void set_choc(egg e, chocolate c)
{
	e->choc = c;
}

/*
* Setter for wrap
* Param r value to be placed into the egg's wrap field
*/
void set_wrap(egg e, wrapping r)
{
	e->wrap = r;
}

/*
* Setter for fill
* Param f value to be placed into the egg's fill field
*/
void set_fill(egg e, filling f)
{
	e->fill = f;
}

/*
* Display function
* Param e egg to be displayed
* Return e formatted as a string
*/
char *to_string(egg e)
{
	const char *fillings[] = {"solid", "filled", "empty"};
	const char *wrappings[] = {"stripy", "spotty", "plain"};
	const char *chocolates[] = {"dark", "milk", "white"};

	char *r = (char *)malloc(100 * sizeof(char));

	sprintf(r, "a %dg %s %s chocolate egg of volume %5.3lfcm3 with a %s wrapping", e->weight, fillings[e->fill], chocolates[e->choc], e->volume, wrappings[e->wrap]);
	return r;
}
