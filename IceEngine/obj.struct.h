#ifndef OBJSTRUCT_H
#define OBJSTRUCT_H

typedef struct vertex{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}VERTEX3D;

typedef struct line3d{
	VERTEX3D v1;
	VERTEX3D v2;
}LINE3D;

typedef struct line{
	int i;
	int j;
}LINE;

typedef struct tri{
	int i;
	int j;
	int z;
}TRI;

#endif