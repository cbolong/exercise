#ifndef _COMMON_H_
#define _COMMON_H_

//typedef struct Node{...} NewNode
typedef struct _CarInfo
{
	char Brand[20];
	int Model;
	struct _CarInfo *next;
}CarInfo;

CarInfo *InsertCars(CarInfo *cars, CarInfo *p);
CarInfo *GetCarNode(void);
void PrintCars(CarInfo *cars);
void FreeCarsList(CarInfo *cars);
CarInfo *DeleteCars(CarInfo *cars, char *Brand, int Model);
#endif