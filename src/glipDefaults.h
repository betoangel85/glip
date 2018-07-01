/*-------------------------------------------------------------------
 *                                                                   
 *                   --  GLIP Defaults Values --
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

#ifndef _GLIP_CONST_H
#define _GLIP_CONST_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__)
# define GLIP_MIN_WINDOW_X_SIZE  120
#else 
# define GLIP_MIN_WINDOW_X_SIZE  90
#endif


#define GLIP_MAX_NO_IMAGES       64
#define GLIP_MAX_NO_DATA         16
#define GLIP_MAX_NO_SUBIMAGES     8
#define GLIP_MAX_PANEL_TEXT      32

#define GLIP_MIN_WINDOW_Y_SIZE   40

#define GLIP_PANEL_SIZE          20
#define GLIP_IMAGE_PANEL          1

#define GLIP_POSITIVE             1
#define GLIP_NEGATIVE            -1

#define GLIP_OK                   1
#define GLIP_ERROR                0

/* static const float glipColorWhite[]={1.0,1.0,1.0,1.0}; */
/*   float glipColorBlack[]={0.0,0.0,0.0,1.0}; */
/*   float glipColorRed[]={1.0,0.0,0.0,1.0}; */
/*   float glipColorBlue[]={0.0,0.0,1.0,1.0}; */
/*   float glipColorGreen[]={0.0,1.0,0.0,1.0}; */
/*   float glipColorCyan[]={0.0,1.0,1.0,1.0}; */
/*   float glipColorYellow[]={1.0,1.0,0.0,1.0}; */
/*   float glipColorMagenta[]={1.0,0.0,1.0,1.0}; */
/*   float glipColorOrange[]={1.0,0.0,1.0,1.0}; */
/*   float glipColorGray1[]={0.7,0.7,0.7,1.0}; */
/*   float glipColorGray2[]={0.5,0.5,0.5,1.0}; */
/*   float glipColorGray3[]={0.3,0.3,0.3,1.0}; */
   

#ifdef __cplusplus
}
#endif

#endif  /*_GLIP_CONST_H*/

