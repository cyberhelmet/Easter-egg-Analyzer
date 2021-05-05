// KIT107 Assignment 2
/*
 * Specification for the Egg ADT
 * Author Julian Dermoudy
 * Version 22/3/2021
 *
 * THIS FILE IS COMPLETE
 */

#ifndef EGG_H
#define EGG_H

typedef enum
{
    DARK,
    MILK,
    WHITE
} chocolate;
typedef enum
{
    STRIPY,
    SPOTTY,
    PLAIN
} wrapping;
typedef enum
{
    SOLID,
    HOLLOW,
    FILLED
} filling;

struct egg_int;
typedef struct egg_int *egg;

void init_egg(egg *e, double v, int w, chocolate c, wrapping r, filling f);
double get_volume(egg e);
int get_weight(egg e);
chocolate get_choc(egg e);
wrapping get_wrap(egg e);
filling get_fill(egg e);
void set_volume(egg e, double v);
void set_weight(egg e, int w);
void set_choc(egg e, chocolate c);
void set_wrap(egg e, wrapping r);
void set_fill(egg e, filling f);
char *to_string(egg e);

#endif