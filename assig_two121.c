// KIT107 Assignment 2
/*
* Implementation for driver
*
* Author Julian Dermoudy and <<Abhishek Tamang>>
* Student ID <<551272>>
* This program reads the data from a text file and store them in appropriate collection and performs different types
* of operations on the data and illustrates using histograms.
* Version <<5/5/2021>>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "egg.h"
#include "node.h"

/*
* Symbols
*/
#define NUM_CHOCOLATIERS 7

/*
* Types
*/
//define collection: - model the collection of eggs for each of the seven chocolatiers
typedef node collection;
typedef struct
{
	char *name;
	collection eggs;
} chocolatier;

//define chocolatiers: - model the collection of chocolatiers
typedef chocolatier chocolatiers[NUM_CHOCOLATIERS];

/*
* Global Constants
*/
const char *MAKERS[] = {"Lindt", "Cadbury", "Pink Lady", "Darrell Lea", "Kinder", "Ferrero", "Mars"};
const int INVALID = -1;

/*
* Global Variables
*/
chocolatiers basket;
int notValid = 0; //no. of invalid eggs

// Functions

/** This function finds and returns index in MAKERs array of given maker name.
      * @param provided maker's name
      * @return int index
      * Precondition: string should be passed
      * Postcondition: checks the position in the MAKERs array and returns position 
      */
int get_chocolatier(char *maker)
{
	int counter = -1; //variable storing integers to be returned
	for (int i = 0; i < NUM_CHOCOLATIERS; i++)
	{
		if (strcmp(maker, MAKERS[i]) == 0)
		{
			return ++i;
		}
	}
	return counter;
}

/** This function adds a data of type egg to the passed collection of eggs
     *and arranges the eggs of the provided collection in increasing order as per their volume.
      * @param provided collection of eggs and data of type egg
      * @return void
      * Precondition: valid parameters should be passed
      * Postcondition: adds the egg data to the collection of eggs
      */
void add_existing(collection *l, egg e)
{
	node one, two, three; //declaring nodes
	init_node(&three, e); //initializing node three with data value of e of type egg
	two = *l;			  //storing given collection in node two
	one = NULL;
	bool check = true;			   //variable to store if result of compared volume is desired
	egg first, second;			   //declaring egg nodes
	second = (egg)get_data(three); //getting value for the data field of the node two
	while ((two != NULL) && (check))
	{
		first = (egg)get_data(two); //getting value for the data field of the node two

		if (get_volume(first) < get_volume(second)) //comparing egg's volume of the collection and arranging in ascending order
		{
			one = two;
			two = get_next(two);
		}
		else
		{
			check = false;
		}
	}
	//if collection is empty
	if (one == NULL)
	{
		*l = three;
		set_next(three, two);
	}
	else
	{
		set_next(one, three);
		if (two != NULL)
		{
			set_next(three, two);
		}
	}
}

/** This function checks if the provided maker is valid or not and if valid it adds provided egg of 
      * provided maker to the chocolatiers provided that there are eggs of that maker already 
      * @param provided maker's name and data of type egg
      * @return void
      * Precondition: valid parameters should be passed
      * Postcondition: performs adding of eggs to the maker's collection
      */
void add_egg(char *maker, egg an_egg)
{
	int validityChecker;							 //position on the chocolatiers array
	node link;										 //declaring node
	validityChecker = get_chocolatier(basket->name); //getting index from the MAKERS array

	/**
	 * @brief  checking if the provided maker lies in the MAKERS array 
	 * 
	 */
	if (validityChecker > 0 && validityChecker < 8)
	{
		if (basket[validityChecker].name != NULL)
		{
			add_existing(&(basket[validityChecker].eggs), an_egg);
		}
		else
		{
			init_node(&link, an_egg);
			basket[validityChecker].name = maker;
			basket[validityChecker].eggs = link;
		}
	}
	else
	{
		notValid++; //incrementing the number of invalid eggs
	}
}

/** This function reads in data from the eggs.txt, calling add_egg() for each of the egg obtained 
      * @param none
      * @return none
      * Precondition: valid text file containing egg data should be provided
      * Postcondition: reads the data and stores them in appropriate collections
      */
void read_in_data()
{
	const char *FILENAME = "eggs.txt";
	//const int LIMIT = 10; // for debugging

	char *maker;
	double volume;
	int weight;
	chocolate choc;
	wrapping wrap;
	filling fill;

	FILE *fp;

	egg an_egg;
	//int limit = 10; // for debugging
	//int count = 0;  // for debugging

	fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
		exit(1);
	}
	else
	{
		maker = (char *)malloc(30 * sizeof(char));
		while (fscanf(fp, "%[^,],%lf,%d,%d,%d,%d\n", maker, &volume, &weight, &choc, &wrap, &fill) != EOF)
		{
			//printf("count is %d\n",count++);
			init_egg(&an_egg, volume, weight, choc, wrap, fill);
			//if (count<=LIMIT) // for debugging
			//{
			//printf("%s: %s\n", maker, to_string(an_egg));
			add_egg(maker, an_egg);
			//count++;
			//}
			maker = (char *)malloc(30 * sizeof(char));
		}
	}
	fclose(fp);
}
/** This function calculates the count of the given 'value' eggs in given category, of given collection
      * @param collection of eggs, char value, int value
      * @return double
      * Precondition: valid parameters should be passed
      * Postcondition: takes user's choice of operation and performs it 
      */
double process_category(collection head, char cat, int val)
{
	double num = 0.0;	 //initial number
	double weight = 0.0; // intializing weight value
	double volume = 0.0; //initializing volume value
	node temp;			 //declaring node
	temp = head;		 //passing provided collection to temp
	while (temp != NULL)
	{

		switch (cat)
		{
		case 't':
			/**
		 	 * @brief calculating the total number of eggs in the collection
		  	* 
		  	*/
			while (temp != NULL)
			{
				num++;
				temp = get_next(temp);
			}
			break;
		case 'w':
			/**
		      	 * @brief  calculating the total weight of eggs in the collection
		    	 * 
		     */
			while (temp != NULL)
			{
				weight = weight + (double)get_weight(get_data(temp));
				temp = get_next(temp);
			}
			num = weight;
			break;
		case 'v':
			/**
		       	* @brief calculating the total volume of eggs in the collection
		    	* 
		     */
			while (temp != NULL)
			{
				volume = volume + get_volume(get_data(temp));
			}
			num = volume;
			break;
		case 'c':
			/**
				 *@brief calculate the number of eggs of that particular chocolate value (dark, milk, or white)
				 * 
		 	*/
			while (get_choc(get_data(temp)) == val)
			{
				num++;
			}

			break;
		case 'r':
			/**
				 *@brief calculating the number of eggs of that particular wrap value (stripy, spotty, or plain)
				 * 
		 	*/
			while (get_wrap(get_data(temp)) == val)
			{
				num++;
			}

			break;
		case 'f':
			/**
				 *@brief calculating the number of eggs of that particular fill value (solid, hollow, filled).
				 * 
		 	*/
			while (get_fill(get_data(temp)) == val)
			{
				num++;
			}

			break;
		default:
			break;
		}
	}
	return num;
}

/** This function creates and displays histogram for eggs of given 'value' in given category with provided description
      * @param char value, int value and string for description
      * @return void
      * Precondition: process_category() working properly
      * Postcondition: displays histograms as per provided parameters
      */
void show_graph(char cat, char *desc, int val)
{
	double processedValue; //variable for storing validity of makers
	char *alias;		   //variable to store chocolatiers name
	printf("\t\t\t\t Easter Eggs  --  %s", desc);
	for (int i = 0; i < NUM_CHOCOLATIERS; i++)
	{
		processedValue = process_category(basket[i].eggs, cat, val);
		printf("%s  |", basket[i].name);
		for (int j = 0; j < processedValue / 25.0; j++)
		{
			if (cat == 't')
			{
				printf("*");
			}
			alias = basket[i].name;
		}
	}
	printf("\n Invalid eggs : %d", notValid);
	printf("\n\nAnd the most common chocolatier for %s eggs is......%d!\n", desc, alias);
}

/** This function initialise chocolatiers, fill it from file and display all the graphs created
      * @param none
      * @return none
      * Precondition: read_in_data() and show_graph() should be working properly
      * Postcondition: performs calling of associated functions
      */
int main(int argc, char *argv[])
{
	//initialising basket variable
	for (int i = 0; i < NUM_CHOCOLATIERS; i++)
	{
		basket[i].name = NULL;
		basket[i].eggs = NULL;
	}
	read_in_data();
	show_graph('t', "total number", INVALID);
	show_graph('v', "summed volume", INVALID);
	show_graph('w', "summed weight", INVALID);
	show_graph('c', "dark chocolate", DARK);
	show_graph('c', "milk chocolate", MILK);
	show_graph('c', "white chocolate", WHITE);
	show_graph('r', "stripy wrap", STRIPY);
	show_graph('r', "plain wrap", PLAIN);
	show_graph('r', "spotty wrap", SPOTTY);
	show_graph('f', "solid", SOLID);
	show_graph('f', "filled", FILLED);
	show_graph('f', "hollow", HOLLOW);
}
