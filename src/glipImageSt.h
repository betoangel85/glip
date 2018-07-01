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
 *           2002-2010
 *
 * Copyright (c) Antonio Marin-Hernandez
 *
 * This program is freely distributable without licensing fees and is
 * provided without guarantee or warrantee expressed or implied. This
 * program is -not- in the public domain.
 *
 *------------------------------------------------------------------*/

#ifndef _GLIP_IMAGES_STRUCTURES_H
#define _GLIP_IMAGES_STRUCTURES_H

#ifdef __cplusplus
extern "C" {
#endif

/*OpenGL definition */
  /*temporal*/  
#define GLIP_COLOR_INDEX       6400
#define GLIP_STENCIL_INDEX     6401
#define GLIP_DEPTH_COMPONENT   6402
#define GLIP_RED               6403
#define GLIP_GREEN             6404
#define GLIP_BLUE              6405
#define GLIP_ALPHA             6406
#define GLIP_RGB               6407
#define GLIP_RGBA              6408
#define GLIP_LUMINANCE         6409
#define GLIP_LUMINANCE_ALPHA   6410
#define GLIP_BGR               32992
#define GLIP_BGRA              32993

#define GLIP_BYTE              5120
#define GLIP_UNSIGNED_BYTE     5121
#define GLIP_SHORT             5122
#define GLIP_UNSIGNED_SHORT    5123
#define GLIP_INT               5124
#define GLIP_UNSIGNED_INT      5125
#define	GLIP_FLOAT             5126
#define GLIP_DOUBLE            5127

#define GLIP_POINTS            0 
#define GLIP_LINES             1
#define GLIP_LINE_LOOP         2
#define GLIP_LINE_STRIP        3 
#define GLIP_TRIANGLES         4 
#define GLIP_TRIANGLE_STRIP    5
#define GLIP_TRIANGLE_FAN      6
#define GLIP_QUADS             7
#define GLIP_QUAD_STRIP        8
#define GLIP_POLYGON           9
   

  typedef struct glipImageSt {

    int width,height;           /* width and height of image */
    int size;                   /* size = width*height+(byteBound-1)*height */
    int depth;                  /* color depth */
    int NoClrsInPltt;           /* No. of colors in palette */
    int format;                 /* Colors format */
    int type;                   /* Image data type */
    int signX,signY;
    int byteAlign;
    unsigned char * palette;
    void           * data;     
    
  } glipImageSt;


  typedef struct glipDataSt {

    int NoPts;
    int size;
    float *color;   /* checar esto */
    int mode;
    int type;
    int dim;
    int stipple;
    unsigned short pattern;
    void   * pts;
    
  } glipDataSt;


#ifdef __cplusplus
}
#endif

#endif
