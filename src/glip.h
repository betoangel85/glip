/*-------------------------------------------------------------------
 *                                              
 *                               -- GLIP --                     
 *                        
 *         --  OpenGL & GLUT based library for Image Processing  --
 *
 *                            -- Version 0.71--
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

#ifndef __GLIPLIB_H
#define __GLIPLIB_H

#ifndef GL_BGR_EXT
#define GL_BGR_EXT GL_BGR
#endif

#define GLIP_VERSION 0.7 /*** Current version ***/

#ifdef __cplusplus
extern "C" {
#endif

#define GLIP_TRUE 1
#define GLIP_FALSE 0
#define GLIP_NEGATIVE     -1
#define GLIP_POSITIVE      1

#include <GL/glut.h>
#include <stdio.h>
#include "glipImageSt.h"

  /* GLIP COLORS */

  extern float glipColorWhite;
  extern float glipColorBlack;
  extern float glipColorRed;
  extern float glipColorBlue;
  extern float glipColorGreen;
  extern float glipColorCyan;
  extern float glipColorYellow;
  extern float glipColorMagenta;
  extern float glipColorOrange;
  extern float glipColorGray1;
  extern float glipColorGray2;
  extern float glipColorGray3;

#define GLIP_COLOR_WHITE     (&glipColorWhite)
#define GLIP_COLOR_BLACK     (&glipColorBlack)
#define GLIP_COLOR_RED       (&glipColorRed)
#define GLIP_COLOR_BLUE      (&glipColorBlue)
#define GLIP_COLOR_GREEN     (&glipColorGreen)
#define GLIP_COLOR_CYAN      (&glipColorCyan)
#define GLIP_COLOR_YELLOW    (&glipColorYellow)
#define GLIP_COLOR_MAGENTA   (&glipColorMagenta)
#define GLIP_COLOR_ORANGE    (&glipColorOrange)
#define GLIP_COLOR_GRAY1     (&glipColorGray1)
#define GLIP_COLOR_GRAY2     (&glipColorGray2)
#define GLIP_COLOR_GRAY3     (&glipColorGray3)




/*-------------------------------------------------------------------
 *                                              
 *                      -- GLIP Image handling--                     
 *
 *------------------------------------------------------------------*/ 
  extern glipImageSt * glipCreateImageHeader(int w,int h,int b,
					 int format,
					 int type);
  extern glipImageSt * glipCreateImage(int w,int h,int b,
				   int format,
				   int type);

  extern int glipFreeImage(glipImageSt *image, char option);

/*temp*/
  extern int glipAssignImageData(int type,void *ptr,
				 glipImageSt *img);

  extern int glipClearImage(glipImageSt *img);

  extern glipImageSt *glipSnapShot(int win,int format,
			       int type);

  extern int glipDrawSubimage(int win,int x,int y,
			      float zoomX,float zoomY,
			      glipImageSt *image);

  extern int glipMoveSubimage(int win,int NoSimg,int x,int y,
			      float zoomX,float zoomY);

  extern int glipDeleteSubimage(int win,int NoSimg);

/*-------------------------------------------------------------------
 *                                              
 *                      -- GLIP data handling--                     
 *
 *------------------------------------------------------------------*/ 
  extern int glipDrawInImage(int win,glipDataSt *data);
  extern int glipDeleteData(int win,glipDataSt *data);
  extern glipDataSt * glipCreateDataSt(int NoPts,int dim,int ptSize,
				     void *color,int mode,
				     int type,void *pts);

/*-------------------------------------------------------------------
 *                                              
 *                      -- GLIP windows handling--                     
 *
 *------------------------------------------------------------------*/ 


  extern int glipInit(int *argcp, char ** argv,int option);
  extern int glipDisplayImage(glipImageSt *image,const char *name,int winNo);
  extern int glipRedisplayImage(int winNo);
  extern int glipKillImageWin(int No);


  //  extern int glipGetPixelValue(int win,int x,int y,int *pxl_X,int *pxl_Y);
  extern int glipGetImageCoord(int win,int u,int v,int *x,int *y);


  extern int glipGetDepth(int format);
  extern int glipGetBytes(int type);
  

#ifdef __cplusplus
}
#endif

#endif // __GLIPLIB_H

