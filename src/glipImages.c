/*-------------------------------------------------------------------
 *                                                                   
 *                   --  glip Images  --
 *                                         
 * Auteur:   Antonio Marin-Hernandez                            
 *
 *           LAAS - CNRS 
 *           Robotics and Artificial Intelligence group
 *           Toulouse, France
 *           &
 *           University of Veracruz
 *           Faculty of Physics and Artificial Intelligence
 *           IA department
 *           Xalapa, Mexico
 *
 *           2002-2010
 *
 * Copyright (c) Antonio Marin-Hernandez
 *
 * This program is freely distributable without licensing fees and is
 * provided without guarantee or warrantee expressed or implied. This
 * program is -not- in the public domain.
 *
 *------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glipImageSt.h"
//#include "glipDefaults.h"

/*-------------------------------------------------------------------
 *  function:  glipGetDepth -> returns the depth in levels needed for a
 *                         given pixel format
 *
 *  param   :  format -> format of pixel data 
 *
 *  return  :  int -> depth 
 *
 *------------------------------------------------------------------*/

int glipGetDepth(int format)
{
  int mult;

  switch (format) {
  case GLIP_RGBA:
  case GLIP_BGRA:
    mult=4;
    break;
  case GLIP_RGB: 
  case GLIP_BGR:
    mult=3;
    break;
  case GLIP_LUMINANCE_ALPHA:
    mult=2;
    break;
  default:
    mult=1;
    break;
  } 
  return mult;
}

/*-------------------------------------------------------------------
 *  function:  glipGetTypeString -> 
 *
 *  param   :  format -> format of pixel data 
 *
 *  return  :  int -> depth 
 *
 *------------------------------------------------------------------*/

char * glipGetTypeString(int type)
{
  char *tString;

  switch (type) {
  case GLIP_BYTE:
    tString="char";
    break;
  case GLIP_UNSIGNED_BYTE:
    tString="unsigned char";
    break;
  case GLIP_SHORT: 
    tString="short";
    break;
  case GLIP_UNSIGNED_SHORT:
    tString="unsigned short";
    break;
  case GLIP_INT:
    tString="int";
    break;
  case GLIP_UNSIGNED_INT:
    tString="unsigned int";
    break;
  case GLIP_FLOAT:
    tString="float";
    break;
  } 
  return tString;
}


/*-------------------------------------------------------------------
 *  function:  glipGetBytes -> returns the Bytes needed for a given 
 *                         type of data
 *
 *  param   :  type -> type of data storage type
 *
 *  return  :  int -> bytes needed
 *
 *------------------------------------------------------------------*/

int glipGetBytes(int type)
{
  int bytes;

  switch (type) {
  case GLIP_BYTE:
  case GLIP_UNSIGNED_BYTE:
    bytes=1;
    break;
  case GLIP_SHORT: 
  case GLIP_UNSIGNED_SHORT:
    bytes=2;
    break;
  case GLIP_INT:
  case GLIP_UNSIGNED_INT:
    bytes=4;
    break;
  case GLIP_FLOAT:
    bytes=4;
    break;
  case GLIP_DOUBLE:
    bytes=8;
    break;
  default:
    bytes=0;
    break;
  } 
  return bytes;
}

/*-------------------------------------------------------------------
 *  function:  glipFreeImage -> free image memory
 *
 *  param   :  glipImageSt image -> glipImageSt to free
 *             char option -> 'a' all
 *                            'h' header
 *                            'd' data
 *
 *  return  :  GLIP_OK     
 *             GLIP_ERROR -> Null Image or bad option
 *
 *------------------------------------------------------------------*/

int glipFreeImage(glipImageSt *image, char option)
{

  if (image==NULL) return 1;//GLIP_ERROR;
  
  if ((option!='a') && (option!='d') && (option!='h')) {
    printf("glipFreeImage ERROR -> Not a valid option '%c' \n",option);
    return 1;//GLIP_ERROR;
  }
  
  if ((option=='a') || (option=='d')) {
    if (image->data!=NULL) free(image->data);
  }
  
  if ((option=='a') || (option=='h')) {
    free(image);
  }

  return 0;//GLIP_OK;
}

/*-------------------------------------------------------------------
 *  function:  glipClearImage -> put zeros in image data.
 *
 *  param   :  glipImageSt *img
 *
 *  return  :  int -> 0 or -1
 *
 *------------------------------------------------------------------*/

int glipClearImage(glipImageSt *img)
{
  int size;

  if ((img==NULL) || (img->data==NULL)) {
    printf("Clear image ERROR, Not a valid Image or data\n");
    return 0;
  }

  size=img->size*img->depth;

  switch (img->type) {
  case GLIP_BYTE: 
  case GLIP_UNSIGNED_BYTE: 
    size*=sizeof(char);
    break;
  case GLIP_SHORT:
  case GLIP_UNSIGNED_SHORT:
    size*=sizeof(short);
    break;
  case GLIP_INT:
  case GLIP_UNSIGNED_INT:
    size*=sizeof(int);
    break;
  case GLIP_FLOAT:
    size*=sizeof(float);
    break;
  default:
    printf("ERROR, image type not implemented \n");
    return (0);
  }

  memset(img->data,0,size);
  return size;
}

/*-------------------------------------------------------------------
 *  function:  createLinesHeader -> create a new Image (glipImageSt)
 *
 *  param   :  w -> width of image
 *             h -> height of image
 *             format -> pixel data format
 *             type -> type of data storage type
 *
 *  return  :  glipImageSt || NULL
 *
 *------------------------------------------------------------------*/

glipDataSt * glipCreateDataSt(int NoPts,int dim,int ptSize,void *color,int mode,int type,void *pts)
{
 glipDataSt * newLns;

  if ((type!=GLIP_SHORT) && 
      (type!=GLIP_INT) && 
      (type!=GLIP_FLOAT) && 
      (type!=GLIP_DOUBLE)){
    printf("CreateLineHeader ERROR-> Not a valid format type\n");
    return NULL;
  }

  if ((newLns = (glipDataSt *)malloc(sizeof(glipDataSt)))==NULL) {
    fprintf(stderr, "Out of memory!\n");
    return NULL;
  }

  newLns->NoPts=NoPts;
  newLns->size=ptSize;
  newLns->color=(float*)color;
  newLns->mode=mode;
  newLns->type=type;
  newLns->dim=dim;
  newLns->stipple=0;
  if (pts!=NULL) newLns->pts=(void*)pts;

  return newLns;
}

/*-------------------------------------------------------------------
 *  function: _glipChekImageParam 
 *
 *  param   :  
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

int _glipCheckImageParam(int w,int h,int b,int format,int type)
{
  int r=1;

  if ((w<=0) || (h<=0)){
    printf("Image Size Not Valid  w=%d h=%d\n",w,h);
    r-=1;
  }
  
  if ((format<GLIP_COLOR_INDEX) || (format>GLIP_BGRA) ||
      ((format>GLIP_LUMINANCE) && (format<GLIP_BGR)) ) {
    printf("Image Not a valid format\n");
    r-=2;
  }

  if ((type<GLIP_BYTE) || (type>GLIP_FLOAT)) {
    printf("Image Not a valid type\n");
    r-=4;
  }

  if (!((b==1) || (b==2) || (b==4) || (b==8))) {
    r=-8;
    printf("Image  Not a valid byte Aligment \n");
  }
  return r;
}


/*-------------------------------------------------------------------
 *  function:  _glipCreateImageMem
 *
 *  param   :  glipImageSt *img
 *
 *  return  :  1 , 0
 *
 *------------------------------------------------------------------*/

int _glipCreateImageMem(glipImageSt *img)
{
  int nbytes;

  if (img==NULL) return 1;

  nbytes=glipGetBytes(img->type);
  
  img->data=(void *)malloc(nbytes*img->size*img->depth);

  if (img->data==NULL){
    fprintf(stderr, "Out of memory!\n");
    return 0;
  }

}


/*-------------------------------------------------------------------
 *  function:  glipCreateImageHeader -> create a new Image (glipImageSt)
 *
 *  param   :  w -> width of image
 *             h -> height of image
 *             format -> pixel data format
 *             type -> type of data storage type
 *
 *  return  :  glipImageSt || NULL
 *
 *------------------------------------------------------------------*/
glipImageSt * glipCreateImageHeader(int w,int h,int b,int format,int type)
{
  int size,mult;
  glipImageSt *newImg;

  if ((w<=0) || (h<=0)){
    printf("size error w=%d h=%d\n",w,h);
    return NULL;
  }
  
  if ((format<GLIP_COLOR_INDEX) || (format>GLIP_BGRA) ||
      ((format>GLIP_LUMINANCE_ALPHA) && (format<GLIP_BGR)) ) {
    printf("CreateImageHeader ERROR-> Not a valid format\n");
    return NULL;
  }

  if ((type<GLIP_BYTE) || (type>GLIP_FLOAT)) {
    printf("CreateImageHeader ERROR-> Not a valid format\n");
    return NULL;
  }

  if ((newImg = (glipImageSt *)malloc(sizeof(glipImageSt)))==NULL) {
    fprintf(stderr, "createImageHeader -> Out of memory!\n");
    return NULL;
  }

  if ((b==1) || (b==2) || (b==4) || (b==8)) {
  
    mult=glipGetDepth(format);
    size=w*h+(((w*mult)%b)*h);  
    newImg->width=w;
    newImg->height=h;  
    newImg->size=size;
    newImg->depth=mult;
    newImg->format=format;
    newImg->type=type;
    newImg->byteAlign=b;
    newImg->signX=1;
    newImg->signY=1;
    newImg->data=NULL;

    return newImg;
  } else {
    printf("CreateImg ERROR-> Not a valid byte Aligment \n");
    return NULL;
  }
}


/*-------------------------------------------------------------------
 *  function:  createImg -> create a new Image (glipImageSt)
 *
 *  param   :  w -> width of image
 *             h -> height of image
 *             format -> pixel data format
 *             type -> type of data storage type
 *           //  bound -> Bound Byte //not used by the moment
 *
 *  return  :  glipImageSt || NULL
 *
 *------------------------------------------------------------------*/

glipImageSt * glipCreateImage(int w,int h,int b,int format,int type)
{
  int nbytes;
  int size,mult;
  glipImageSt *newImg;

  newImg = glipCreateImageHeader(w,h,b,format,type);
  if (newImg==NULL) return (NULL);

  if (_glipCreateImageMem(newImg)!=0) {
    if (newImg->data==NULL){
      fprintf(stderr, "Out of memory!\n");
      glipFreeImage(newImg,'a');
      return(NULL);
    }
  }

  return newImg;
}



/*-------------------------------------------------------------------
 *  function:  int glipAssignImageData
 *  param   :  
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

int glipAssignImageData(int type,void *ptr,glipImageSt *img)
{
  
  if ((img==NULL) || 
      (ptr==NULL)){
    printf("Not a valid image data pointer\n");
    return 1;
  }

  if (type!=img->type) {
    printf("Assig Image data pointer ERROR -> Not the same type\n");
    return 2;
  }

  img->data=(void*)ptr;

  return img->type;
}



/*-------------------------------------------------------------------
 *  function:  modifImage ->modifies an image
 *
 *  param   :  w -> width of image
 *             h -> height of image
 *             b -> Bound Byte 
 *             format -> pixel data format
 *             type -> type of data storage type
 *             data -> Pointer to image data or NULL to alloc space
 *
 *  return  :  int -> 1 , 0 
 *
 *------------------------------------------------------------------*/

int glipModifImage(int w,int h,int b,int format,int type,void * data,glipImageSt *img)
{
  int size,mult;

  if (_glipCheckImageParam(w,h,b,format,type)<=0) {
    return 0;
  }

  size=w*h+(((w*mult)%b)*h);  // size=w*h;
  mult=glipGetDepth(format);

  img->width=w;
  img->height=h;  
  img->size=size;
  img->depth=mult;
  img->format=format;
  img->type=type;
  img->byteAlign=b;
/*   img->signX=1; */
/*   img->signY=1; */
  if (data==NULL) {
    if (img->data!=NULL) free(img->data);
    _glipCreateImageMem(img);
  } else img->data=(void*) data;

  return 1;

}
