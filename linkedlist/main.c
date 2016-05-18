#include <stdio.h>
#include <string.h>
#include "common.h"

CarInfo *AddList(CarInfo *cars, char *Brand, int Model)
{
	CarInfo *p;
	
	p = GetCarNode();	
	strcpy(p->Brand,Brand);
	p->Model = Model;
	cars = InsertCars(cars, p);
		
	return cars;
}

int main()
{
	CarInfo *cars = NULL;
	
	cars = AddList(cars,"Benz",119);
	cars = AddList(cars,"Mini",112);
	cars = AddList(cars,"Toyota",221);
	cars = AddList(cars,"BMW",113);
	PrintCars(cars);
	printf("******\n");
	cars = DeleteCars(cars,"Benz",119);
	PrintCars(cars);
	//printf("******\n");
	//cars = DeleteCars(cars,"Toyota",221);
	//PrintCars(cars);
	
	FreeCarsList(cars);
	return 0;
}
