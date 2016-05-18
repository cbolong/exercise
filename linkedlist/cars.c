#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

CarInfo *GetCarNode(void)
{
	CarInfo *p;
	
	p = malloc(sizeof(CarInfo));
	
	if(p == NULL)
	{
		return NULL;
	}
	else
	{
		p->next = NULL;
		return p;
	}
}

CarInfo *InsertCars(CarInfo *cars, CarInfo *p)
{
	CarInfo *Total, *Temp;
	
	//if the node list is empty
	if (cars == NULL)
	{
		cars = p;
		return cars;
	}
	
	//if the node list is not empty
	Total = cars;
	while (Total != NULL)
	{
		Temp = Total;
		Total = Total->next;
	}

	Temp->next = p;
	return cars;
}

CarInfo *DeleteCars(CarInfo *cars, char *Brand, int Model)
{
	CarInfo *Current = NULL, *Prev = NULL;
	
	Current = cars;

	while(Current!=NULL)
	{
		if(0 == strcmp(Current->Brand,Brand) && Current->Model == Model)
		{	// the node is at the first
			if(Current == cars)
			{
				cars=Current->next;
				free(Current);
				return cars;
			}
			else
			{	// the node is at the middle
				Prev->next=Current->next;
				free(Current);
				return cars;
			}
		}
		else
		{	// it didn't find specified node.
			Prev=Current;
			Current=Current->next;
		}
	}
	
	return cars;
}

void PrintCars(CarInfo *cars)
{
	CarInfo *Head;
	
	for(Head = cars; Head != NULL; Head = Head->next)
	{
		printf("===Brand:[%s] Model:[%d]\n",Head->Brand,Head->Model);
	}
}

void FreeCarsList(CarInfo *cars)
{
	CarInfo *Head,*Temp;
	
	Head = cars;
	while(Head != NULL)
	{
		Temp = Head->next;
		free(Head);
		Head = Temp;
	}
}