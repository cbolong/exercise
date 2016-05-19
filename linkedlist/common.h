#ifndef _COMMON_H_
#define _COMMON_H_

typedef enum
{
	PROTO_NONE = 0,
	PROTO_USA,
	PROTO_CHINA,
	PROTO_JAPAN,
}CarProto;

//typedef struct Node{...} NewNode
typedef struct _CarInfo
{
	char Brand[20];
	int Model;
	CarProto Contry;
	struct _CarInfo *next;
}CarInfo;

CarInfo *InsertCars(CarInfo *cars, CarInfo *p);
CarInfo *GetCarNode(void);
void PrintCars(CarInfo *cars);
void FreeCarsList(CarInfo *cars);
CarInfo *DeleteCars(CarInfo *cars, char *Brand, int Model);
#endif
