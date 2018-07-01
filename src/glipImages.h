/*-------------------------------------------------------------------
 *                                                                   
 *                   --  GLIP Image Structure  --
 *                                         
 * Author:   Antonio Marin-Hernandez                            
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
 *           2002-2005
 *
 * Copyright (c) Antonio Marin-Hernandez
 *
 * This program is freely distributable without licensing fees and is
 * provided without guarantee or warrantee expressed or implied. This
 * program is -not- in the public domain.
 *
 *------------------------------------------------------------------*/

#if defined(_GLIP_IMAGE_FUNCTIONS_H)
#else
#define _GLIP_IMAGE_FUNCTIONS_H

#if !defined(GL_BGR_EXT)
#define GL_BGR_EXT GL_BGR
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "glipImageSt.h"

 
/*-------------------------------------------------------------------
 * 
 *------------------------------------------------------------------*/

  extern int glipGetDepth(int format);
  extern int glipGetBytes(int type);
  extern int glipClearImage(glipImageSt *img);

  extern glipImageSt * glipCreateImageHeader(int w,int h,int b,int format,
					 int type);
  extern glipImageSt * glipCreateImage(int w,int h,int b,int format,
				   int type);

  extern glipDataSt * glipCreateDataSt(int NoPts,int dim,int ptSize,
				     float *color,int mode,
				     int type,void *pts);

  extern int glipAssignImageData(int type,void *ptr,glipImageSt *img);






#ifdef __cplusplus
}
#endif


#endif
