/*-------------------------------------------------------------------
 *                                              
 *                               -- GLIP --                     
 *                        
 *         --  OpenGL & GLUT based library for Image Processing  --
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
#include <string.h>
#include <math.h>
#include <GL/glut.h>
/* #include "glip.h" */
#include "glipImageSt.h"
#include "glipImages.h"
#include "glipDefaults.h"

int _IMAGE_PANEL=0;
int swin;
glipImageSt *timg[GLIP_MAX_NO_IMAGES];  
glipImageSt *img;

/* subimages */
glipImageSt *tsimg[GLIP_MAX_NO_IMAGES][GLIP_MAX_NO_SUBIMAGES];
int subImgPos[GLIP_MAX_NO_IMAGES][GLIP_MAX_NO_SUBIMAGES][2];
float subImgZoom[GLIP_MAX_NO_IMAGES][GLIP_MAX_NO_SUBIMAGES][2];

int *glines[GLIP_MAX_NO_IMAGES][GLIP_MAX_NO_DATA];

int imagePanel[GLIP_MAX_NO_IMAGES];
glipDataSt *dataStrs[GLIP_MAX_NO_IMAGES][GLIP_MAX_NO_DATA];

double zoomX[GLIP_MAX_NO_IMAGES];
double zoomY[GLIP_MAX_NO_IMAGES];

char imgPnlText[GLIP_MAX_NO_IMAGES][GLIP_MAX_PANEL_TEXT];
float _GLIP_PANEL_COLOR[]={0.5,0.5,0.5,1.0};

/* different groups of data (with same characteristics) to draw
   for each image */

int NoDataStrs[GLIP_MAX_NO_IMAGES]; 




/*------------------------------------------------------------------
 *                            Initialization
 *------------------------------------------------------------------*/


/*-------------------------------------------------------------------
 *  function:  glipInit -> Initialization for displaying images
 *
 *  param   :  int *argcp 
 *             char ** argv
 *             int option  -> no used
 *
 *  return  :  void
 *
 *------------------------------------------------------------------*/


int glipInit(int *argcp, char ** argv,int option)
{
  glutInit(argcp,argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);

  glDrawBuffer(GL_BACK);

/*   glEnable(GL_DEPTH_TEST); */
  glDepthFunc(GL_ALWAYS);
/*   if (glIsEnabled(GL_VERTEX_ARRAY)==GL_FALSE) { */
/*     printf("not array enabled\n"); */
/*     glEnableClientState(GL_VERTEX_ARRAY); */
/*   } */
  if (option==GLIP_IMAGE_PANEL)
    _IMAGE_PANEL=1; 

  return 0;
}

/*-------------------------------------------------------------------
 *  function:  glipInitDisplayMode -> Initialization for displaying 
 *                                    images
 *
 *  param   :  unsigned int -> mode
 *
 *  return  :  void
 *
 *------------------------------------------------------------------*/
void glipInitDisplayMode(unsigned int mode)
{
  glutInitDisplayMode(mode);
}




/*-------------------------------------------------------------------
 *  function:  _glipWriteInPanel -> Internal function to print 
 *                   information on image
 *
 *  param   :  char *text
 *
 *  return  :  int -> Number of writed characters.
 *
 *------------------------------------------------------------------*/

int _glipWriteInPanel(char *text)
{
  int No,tsize,i=0,chr;

  glClearColor(_GLIP_PANEL_COLOR[0],_GLIP_PANEL_COLOR[1],
	       _GLIP_PANEL_COLOR[2],_GLIP_PANEL_COLOR[3]);  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  tsize=strlen(text);

  for(i=0;i<tsize;i++){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13,(int)text[i]);
  }

  return tsize;
}

/*-------------------------------------------------------------------
 *  function:  _glipRenderPanel -> Internal function to print 
 *                   information in image
 *
 *  param   :  void 
 *
 *  return  :  void
 *
 *------------------------------------------------------------------*/

void _glipRenderPanel(void)
{
  int No;
/*   float rasterP[4]; */

  glClearColor(0.5, 0.5, 0.5, 1.0);  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  No=glutGet(GLUT_WINDOW_PARENT);

  glRasterPos2f(-1,-0.5); // to change
/*   glGetFloatv(GL_CURRENT_RASTER_POSITION,rasterP); */

  _glipWriteInPanel(imgPnlText[No]);
  //  sprintf(imgPnlText[No],"hola");
  glFlush();
  glutSwapBuffers();
}


/*-------------------------------------------------------------------
 *  function:   glip
 *
 *  param   :  
 *
 *  return  : 
 *
 *------------------------------------------------------------------*/
int glipGetImageCoord(int win,int u,int v,int *x,int *y)
{
  //  int win;
  int iW=0,iH=0;
  float zX,zY;
  int winWidth,winHeight;

  int rastPos[4];

  glutSetWindow(win);
  winWidth=glutGet(GLUT_WINDOW_WIDTH);
  winHeight=glutGet(GLUT_WINDOW_HEIGHT);

  glGetIntegerv(GL_CURRENT_RASTER_POSITION,rastPos);

  img=timg[win];
  zX=zoomX[win];
  zY=zoomY[win];

  *x=(u-rastPos[0])/zX;
  //  if (img->signY>0) {
  *y=(winHeight-v-rastPos[1])/zY;
    //    printf("y-> %d %d %d %d %d\n",*y,rastPos[1],winHeight,v,img->signY);
 /*  }  */
/*   else { */
/*     *y=(v-rastPos[1])/zY; */
/*     printf("y-> %d %d %d %d\n",*y,rastPos[1],v,img->signY); */
/*   } */
  return 1;
}
/*-------------------------------------------------------------------
 *  function:   glipSnapShot
 *
 *  param   :  int win    -> Image window
 *             int format -> Snapshot image format
 *             int type   -> Snapshot image type
 *
 *  return  :  glipImageSt -> SnapshotImage or NULL 
 *
 *------------------------------------------------------------------*/
glipImageSt * glipSnapShot(int win,int format,int type)
{
  int w,h;
  glipImageSt *snap;

  if(win>0) glutSetWindow(win);
  else if(win==0) win=glutGetWindow();
  else return 0;

  w=glutGet(GLUT_WINDOW_WIDTH);
  h=glutGet(GLUT_WINDOW_HEIGHT);

  snap=glipCreateImage(w,h,1,format,type);
  glReadPixels(0,0,w,h,format,type,snap->data);

  return snap;
}


/*-------------------------------------------------------------------
 *  function:  _glipDrawDataStrs -> Internal function
 *
 *  param   :  int win
 *
 *  return  :  int -> depth 
 *
 *------------------------------------------------------------------*/

void _glipDrawDataStrs(int No)
{
  int i,j;
  glipDataSt *sptr;
 
  for(i=0;i<NoDataStrs[No];i++){
    sptr=dataStrs[No][i];

    if (glIsEnabled(GL_VERTEX_ARRAY)==GL_FALSE)
      glEnableClientState(GL_VERTEX_ARRAY);

    if (sptr) {
      glPointSize(sptr->size);
      glLineWidth(sptr->size);
      glColor4fv(sptr->color);

      if ((sptr->mode>0) && (sptr->stipple>0)) {
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(sptr->stipple,sptr->pattern);
      } else  glDisable(GL_LINE_STIPPLE);

      glVertexPointer(2,sptr->type,0,sptr->pts);
      glDrawArrays(sptr->mode,0,sptr->NoPts);
    }
  }
}

/*-------------------------------------------------------------------
 *  function:  _glipOnSize ->
 *
 *  param   :  int width, 
 *             int height
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

void _glipOnSize(int width, int height)
{ 
  int win;
  int newW,newH;
  int iW=0,iH=0;
  float zX,zY;

  win=glutGetWindow();
  img=timg[win];
  zX=zoomX[win];
  zY=zoomY[win];

  if (width>img->width){
    iW=-(width/zX-img->width)/2;
    newW=width/zX+iW;
  } else {
    if (zX<0) {
      iW=fabs(width/zX);
      newW=0;
    } else  
    newW=width/zX;
  }

  if (height>img->height){
    iH=-(height/zY-img->height)/2;
    newH=height/zY+iH;
  } else {
    if (zY<0) {
      iH=fabs(height/zY);
      newH=0;
      //      newH=img->height-height;
    } else 
    newH=height/zY;
  }

  glLoadIdentity();
  glViewport(0, 0,width,height);
  gluOrtho2D(iW, newW, iH, newH);
 
}

/*-------------------------------------------------------------------
 *  function:  glipIntRenderImg ->
 *
 *  param   :  
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

void _glipRenderImage(void)
{
  int No,subImg=0;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  No=glutGetWindow();
  glPushMatrix();
  img=timg[No];
  //  glRasterPos2i(-(img->signX),-(img->signY));
  glRasterPos2i(0,0);
  glPixelZoom(zoomX[No],zoomY[No]);
  /* if (img->byteAlign>0) */ 
  glPixelStorei(GL_UNPACK_ALIGNMENT,img->byteAlign);
  glDrawPixels(img->width,img->height,img->format,img->type,img->data);
  
  while (subImg<GLIP_MAX_NO_SUBIMAGES) {
    if (tsimg[No][subImg]!=NULL) {
      img=tsimg[No][subImg];
      glRasterPos2i(subImgPos[No][subImg][0],subImgPos[No][subImg][1]);
      glPixelZoom(fabs(zoomX[No])*subImgZoom[No][subImg][0],
		  fabs(zoomY[No])*subImgZoom[No][subImg][1]);
      glPixelStorei(GL_UNPACK_ALIGNMENT,img->byteAlign);
      glDrawPixels(img->width,img->height,img->format,img->type,img->data);
      glRasterPos2i(0,0);
    } 
    subImg++;
  }
  
  if (NoDataStrs[No]>0) {
    _glipDrawDataStrs(No);
  }

  glPopMatrix();

  glFinish();
  glutSwapBuffers();
}
/*-------------------------------------------------------------------
 *  function:  glipCreatePanel
 *
 *  param   :  
 *
 *  return  : 
 *
 *------------------------------------------------------------------*/

void glipCreatePanel(int win,int yPos)
{
 
  int cdepth,swin;
  int winWidth,winHeight;
  int y; //temp
  winWidth=glutGet(GLUT_WINDOW_WIDTH);
  winHeight=glutGet(GLUT_WINDOW_HEIGHT);
  //  y=img->height-y;

  if ((!_IMAGE_PANEL) && (y*zoomY[win]>GLIP_PANEL_SIZE)) yPos=winHeight-GLIP_PANEL_SIZE;
  else yPos=0;

  swin=glutCreateSubWindow(win,0,yPos,winWidth,GLIP_PANEL_SIZE);
  glutDisplayFunc(_glipRenderPanel);

}

/*-------------------------------------------------------------------
 *  function:  glipDisplayColorVal(int x,int y)
 *
 *  param   :  
 *
 *  return  : 
 *
 *------------------------------------------------------------------*/

void glipDisplayColorVal(int x,int y)
{
  int i,j,win,swin;
  int r,g,b,a;
  int yPos,h=GLIP_PANEL_SIZE;
  int cdepth;
  int winWidth,winHeight;

  win=glutGetWindow();
  img=timg[win];
  cdepth=glipGetDepth(img->format);
  winWidth=glutGet(GLUT_WINDOW_WIDTH);
  winHeight=glutGet(GLUT_WINDOW_HEIGHT);

  i=(img->width*y+x)*cdepth;  
  if ((_IMAGE_PANEL>0) || (y*zoomY[win]>GLIP_PANEL_SIZE)) 
    yPos=winHeight-GLIP_PANEL_SIZE;
  else yPos=0;

  swin=glutCreateSubWindow(win,0,yPos,winWidth,h);
  //  printf("%d %d \n",win,swin);

  glutDisplayFunc(_glipRenderPanel);

  imagePanel[win]=swin;

  sprintf(imgPnlText[win],"Pxl (%d,%d)",x,y);

  if ((x>=0) && (y>=0) && (x<img->width) && (y<img->height)) {
    switch(img->type) {
    case GLIP_BYTE: 
      for (j=0;j<cdepth;j++) 
 	sprintf(imgPnlText[win],"%s %4d",imgPnlText[win],*((char*)img->data+i+j));
      break;
    case GLIP_UNSIGNED_BYTE: 
      for (j=0;j<cdepth;j++) 
 	sprintf(imgPnlText[win],"%s %4d",imgPnlText[win],*((unsigned char*)img->data+i+j));
      break;
    case GLIP_SHORT: 
      for (j=0;j<cdepth;j++) 
	sprintf(imgPnlText[win],"%s %4d",imgPnlText[win],*((short*)img->data+i+j));
      break;
  case GLIP_UNSIGNED_SHORT: 
      for (j=0;j<cdepth;j++) 
	sprintf(imgPnlText[win],"%s %4d",imgPnlText[win],*((unsigned short*)img->data+i+j));
      break;
    case GLIP_INT: 
      for (j=0;j<cdepth;j++) 
	sprintf(imgPnlText[win],"%s %4d",imgPnlText[win],*((int*)img->data+i+j));
      break;
    case GLIP_UNSIGNED_INT: 
      for (j=0;j<cdepth;j++) 
	sprintf(imgPnlText[win],"%s %4d",imgPnlText[win],*((unsigned int*)img->data+i+j));
      break;
    case GLIP_FLOAT: 
      for (j=0;j<cdepth;j++)
	sprintf(imgPnlText[win],"%s %4f",imgPnlText[win],*((float*)img->data+i+j));
      break;
    default:
      break;
    } 
  } else  sprintf(imgPnlText[win],"Out of image!");  

  //glutTimerFunc(2000,(void *)glutHideWindow,imagePanel[win]);
  glutTimerFunc(2000,(void *)glutDestroyWindow,imagePanel[win]);
  // printf("%d \n",imagePanel[win]);

}

/*-------------------------------------------------------------------
 *  function:  _glipDefaultMouse
 *
 *  param   :  (int button, int state ,int x,int y)
 *
 *  return  : 
 *
 *------------------------------------------------------------------*/

void _glipDefaultMouse(int button, int state ,int u,int v)
{
  int ny;
  int x,y,win;
  
  if ((button==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN)){
    win=glutGetWindow();
    glipGetImageCoord(win,u,v,&x,&y);
    glipDisplayColorVal(x,y);
  }
}
/*-------------------------------------------------------------------
 *  function:  _glipReshapeWindow -> 
 *
 *  param   :  
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/
void _glipReshapeWindow (int x, int y)
{
  int winSizeX,winSizeY;  

  if (x<GLIP_MIN_WINDOW_X_SIZE) winSizeX=GLIP_MIN_WINDOW_X_SIZE;
  else  winSizeX=x;
  if (y<GLIP_MIN_WINDOW_Y_SIZE) winSizeY=GLIP_MIN_WINDOW_Y_SIZE;
  else  winSizeY=y;

  if (_IMAGE_PANEL) {
    if (abs(winSizeY-y)<GLIP_PANEL_SIZE) winSizeY+=GLIP_PANEL_SIZE;
   /*  glutReshapeWindow(image->width,image->height+GLIP_PANEL_SIZE); */
/*     gluOrtho2D(0, image->width, 0, image->height+GLIP_PANEL_SIZE); */
    //    glipCreatePanel(0,0);
  /*   printf("test\n"); */
  }  else {
    
  }
  //  glutSetWindow(winNo);
  // printf("1X=%d,Y=%d\n",x,y);
  glutReshapeWindow(winSizeX,winSizeY);
  //printf("2X=%d,Y=%d\n",winSizeX,winSizeY);
  
  _glipOnSize(winSizeX,winSizeY);

}

/*-------------------------------------------------------------------
 *  function:  _glipSizeMenu
 *
 *  param   :  int sel -> 
 *
 *  return  : void
 *
 *------------------------------------------------------------------*/

void _glipSizeMenu(int sel)
{
  int win,zX,zY;

  win=glutGetWindow();
  img=timg[win];

  switch (sel) {
  case 1:
    zoomX[win]/=2.0;
    zoomY[win]/=2.0;
    break;
  case 2:
    zoomX[win]=timg[win]->signX;
    zoomY[win]=timg[win]->signY;
    break;
  case 3:
    zoomX[win]*=2.0;
    zoomY[win]*=2.0;
   break;
  default:
    break;
  }
  zX=(img->width*fabs(zoomX[win]));
  zY=(img->height*fabs(zoomY[win]));
  _glipReshapeWindow (zX,zY);
 
}

/*-------------------------------------------------------------------
 *  function:  glipKillImageWin -> Kill the DisplayImage window n
 *
 *  param   :  int winNo -> Window number
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

int glipKillImageWin(int No)
{
  int win;
  win=glutGetWindow();
  if(win==No) {
    glutSetWindow(No);
    glutHideWindow();
  }
  glutTimerFunc(1000,(void *)glutDestroyWindow,No);
  return win;
}



/*-------------------------------------------------------------------
 *  function:  _glipDefaultMenu
 *
 *  param   :  int sel ->  
 *
 *  return  : 
 *
 *------------------------------------------------------------------*/

void _glipDefaultMenu(int sel)
{
  int win;
  win=glutGetWindow();
  switch (sel) {
  case 9:
    glutHideWindow();
    break;
  case 10:
    glipKillImageWin(win);
    break;
  default:
    break;
  }
}

/*-------------------------------------------------------------------
 *  function:  glipDisplayImage -> 
 *
 *  param   :  
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

int glipDisplayImage(glipImageSt *image,const char *name,int winNo)
{
  int nWinNo,nSizeMenu;

  if (image->data==NULL) {
    printf("glipDisplayImage ERROR > NULL image in winNo %d - \"%s\"\n",winNo,name);
    return 0;      
  }

  /* if (winNo>0){ */
  nWinNo=glutCreateWindow(name);

  timg[nWinNo]=image;
  zoomX[nWinNo]=image->signX;
  zoomY[nWinNo]=image->signY;
  NoDataStrs[nWinNo]=0;

  //  _glipReshapeWindow (image->width,image->height);
  //  printf("Display X=%d,Y=%d\n",image->width,image->height);
  nSizeMenu=glutCreateMenu(_glipSizeMenu);
  glutAddMenuEntry("half size",1);
  glutAddMenuEntry("100%",2);
  glutAddMenuEntry("double size",3);

  glutCreateMenu(_glipDefaultMenu);
  glutAddSubMenu("Size",nSizeMenu);
  glutAddMenuEntry("Hide window",9);
  glutAddMenuEntry("Kill window",10);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutReshapeFunc(_glipReshapeWindow);
  glutMouseFunc(_glipDefaultMouse);
  glutDisplayFunc(_glipRenderImage);

  return nWinNo;
}

/*-------------------------------------------------------------------
 *  function:  glipRedisplayImage -> 
 *
 *  param   :  int winNo
 *
 *  return  :  int 
 *
 *------------------------------------------------------------------*/

int glipRedisplayImage(int winNo)
{
  glutSetWindow(winNo);
  if (glutGetWindow()!=winNo) 
    return 0;
  else 
    glutPostRedisplay();
  return winNo;
}

/*-------------------------------------------------------------------
 *  function:  glipDrawInImage -> 
 *
 *  param   :  
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

int glipDrawInImage(int win,glipDataSt *data)
{
  int j;
 
  if (data==NULL) {
    printf("drawLinesInImage>ERROR \n>> No a valid lines Structure \n");
    return 0;
  }
/*   if (glIsEnabled(GL_VERTEX_ARRAY)==GL_FALSE) { */
/*     printf("not array enabled\n"); */
/*     glEnableClientState(GL_VERTEX_ARRAY); */
/*   } */

  if (NoDataStrs[win]<GLIP_MAX_NO_DATA){
    NoDataStrs[win]++;
    dataStrs[win][NoDataStrs[win]-1]=data;
    //    printf("draw In Image %d %d\n",win,NoDataStrs[win]);
  } else {
    printf("drawLinesInImage>ERROR \n>>Max. number of group of lines passed\n");
    return 0;
  }

  return NoDataStrs[win];
}

/*-------------------------------------------------------------------
 *  function:  glipDeleteLinesSt -> 
 *
 *  param   :  int win
 *             glipDataSt *lines
 *
 *  return  :  
 *
 *------------------------------------------------------------------*/

int glipDeleteData(int win,glipDataSt *data)
{
  int i,NoLs=-1;
  int Ntot;
  
  Ntot=NoDataStrs[win];
  if (Ntot <= 0) {
    return 0;
  }

  for (i=0;i<Ntot;i++) {
    if (dataStrs[win][i]==data) {
      NoLs=i;
      break;
    }
  }
  
  if (NoLs<0) return 0;
  Ntot--;

  for (i=NoLs;i<Ntot;i++) 
    dataStrs[win][i]=dataStrs[win][i+1];
  
  NoDataStrs[win]=Ntot;
  glipRedisplayImage(win);
  return Ntot;
}

/*-------------------------------------------------------------------
 *  function:  glipDrawSubimage -> 
 *
 *  param   :  int win
 *             int x
 *             int y
 *             float zoomX
 *             float zoomY
 *             glipImageSt *image
 *
 *  return  :  int -> No of Subimage or -1 if ERROR  
 *
 *------------------------------------------------------------------*/

int glipDrawSubimage(int win,int x,int y,float zoomX,float zoomY,glipImageSt *image)
{
  int i=0;

  if ((image==NULL) || (image->data==NULL)){
    printf("GLIP DrawSubimage ERROR \n>> NULL image\n");
    return 0;
  }
  
  while (i<GLIP_MAX_NO_SUBIMAGES) { 
    if (tsimg[win][i]==NULL) {
      tsimg[win][i]=image;
      subImgPos[win][i][0]=x;
      subImgPos[win][i][1]=y;
      subImgZoom[win][i][0]=zoomX*image->signX;
      subImgZoom[win][i][1]=zoomY*image->signY;
      return i;
    } else 
      i++;
  }

  printf("GLIP DrawSubimage ERROR \n>> Max No. Subimage %d\n",i);
  return -1;
}

/*-------------------------------------------------------------------
 *  function:  glipMoveSubimage -> 
 *
 *  param   :  int win
 *             int NoSimg
 *             int x
 *             int y
 *             float zoomX
 *             float zoomY
 *
 *  return  :  int -> GLIP_OK or GLIP_ERROR
 *
 *------------------------------------------------------------------*/

int glipMoveSubimage(int win,int NoSimg,int x,int y,float zoomX,float zoomY)
{
  glipImageSt *image;
  if (tsimg[win][NoSimg]!=NULL) {
    image=tsimg[win][NoSimg];
    subImgPos[win][NoSimg][0]=x;
    subImgPos[win][NoSimg][1]=y;
    subImgZoom[win][NoSimg][0]=zoomX*image->signX;
    subImgZoom[win][NoSimg][1]=zoomY*image->signY;
    return GLIP_OK;
  } else 
    printf("GLIP MoveSubimage ERROR \n>> No such number  %d\n",NoSimg);

  return GLIP_ERROR;
}

/*-------------------------------------------------------------------
 *  function:  glipDeleteSubimage -> 
 *
 *  param   :  int win
 *             int NoSimg
 *
 *  return  :  int -> GLIP_OK or GLIP_ERROR
 *
 *------------------------------------------------------------------*/

int glipDeleteSubimage(int win,int NoSimg)
{

  if (tsimg[win][NoSimg]!=NULL) {
    tsimg[win][NoSimg]=NULL;
    subImgPos[win][NoSimg][0]=0;
    subImgPos[win][NoSimg][1]=0;
    subImgZoom[win][NoSimg][0]=0;
    subImgZoom[win][NoSimg][1]=0;
    return GLIP_OK;
  }

  printf("GLIP MoveSubimage ERROR \n>> No such number  %d\n",NoSimg);
  return GLIP_ERROR;
}

