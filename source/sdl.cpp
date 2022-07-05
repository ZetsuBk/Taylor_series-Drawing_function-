#include <stdio.h>
#include<cmath>
#include<SDL2/SDL.h>
#include<fstream>
#include<iostream>
#include<SDL2/SDL_image.h>

SDL_Window* gwindo=NULL;
SDL_Renderer* grender=NULL;
SDL_Texture* text = NULL;

int widht=720;
int height=720;
const int unit = 50;

int a = 0;
int ax= 0;
float point[100] , pointr[100] ,pointx[100];


void exit()
{
    SDL_DestroyWindow(gwindo);
    gwindo=NULL;
    SDL_DestroyRenderer(grender);
    grender=NULL;
    IMG_Quit();
    SDL_Quit();
}
int
SDL_RenderDrawCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

   // CHECK_RENDERER_MAGIC(renderer, -1);

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

int
SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

//    CHECK_RENDERER_MAGIC(renderer, -1);

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

class ma3lam {

public:
   ma3lam()
   {

    // init axes x position
    
   if (a >=0)
    {
     positionX= height/2 + ( ax ) * unit ; 
     std::cout<<positionY;
    }
    else if(a<0)
    {
     positionX=height/2 + ( ax ) * unit;
    }

    
    if (a >=0)
    {
     positionY= widht/2 - ( a ) * unit ; 
     std::cout<<positionY;
    }
    else if(a<0)
    {
     positionY= widht/2 - ( a ) * unit;
    }

    }
    
    void drawpoint_A()
{       
          
        // DRAW point SHape
       SDL_SetRenderDrawColor(grender,255,0,0,255);
       SDL_RenderFillCircle(grender, widht/2 , getpositionX()  ,3);
       SDL_RenderFillCircle(grender, positionY , positionX - ax * 50  ,3);

}
    
  
  
  
  
  
  
  
   void setpositionX(float x)
   {
       positionX = x ;
   }
   void setpositionY(float y)
   {
        positionY = y;
   }

   float getpositionX(){return positionX;}
   float getpositionY(){return positionY;}

   void draw()
   {       
            if(positionY >= widht/8 && positionY <= widht/8 * 7 ){
            // DRAW Y axes
            SDL_SetRenderDrawColor(grender,255,255,255,255);
            SDL_RenderDrawLine(grender,positionY+1,height/8,positionY+1,height/8*7 );
            SDL_RenderDrawLine(grender,positionY-1,height/8,positionY-1,height/8*7 );
            SDL_RenderDrawLine(grender,positionY,height/8,positionY,height/8*7 );
            }
             if(positionX >= height/8 && positionX <= height/8 * 7 ){
            // DRAW X axes
            SDL_SetRenderDrawColor(grender,255,255,255,255);
            SDL_RenderDrawLine(grender,widht/8,positionX,widht/8 *7,positionX );
            SDL_RenderDrawLine(grender,widht/8,positionX+1,widht/8 *7,positionX+1 );
            SDL_RenderDrawLine(grender,widht/8,positionX-1,widht/8 *7,positionX-1 );
             }
             
           
   }
     void Draw_Dala()
    {   SDL_SetRenderDrawColor(grender,0,255,0,255);
       
        for(int i= 0 ; i<99 ;i++)
        {    SDL_SetRenderDrawColor(grender,0,255,0,255);
            if(positionY + pointx[i] *50 <= widht * 7 && positionY + pointx[i] *50 >= widht - widht * 7  && positionX - point[i+1] * unit <= height * 4 && positionX - point[i] * unit >= height - height * 4  )
           { SDL_RenderDrawLine(grender,positionY + pointx[i]*unit +1  ,positionX - point[i] * unit +2 ,positionY + pointx[i+1] *unit + 1,positionX - point[i+1] * unit +2 );
            SDL_RenderDrawLine(grender,positionY + pointx[i]*unit +1 ,positionX - point[i] * unit -2,positionY + pointx[i+1] *unit +1 ,positionX - point[i+1] * unit -2 );
            SDL_RenderDrawLine(grender,positionY + pointx[i]*unit  ,positionX - point[i] * unit +1 ,positionY + pointx[i+1] *unit ,positionX - point[i+1] * unit +1 );
            SDL_RenderDrawLine(grender,positionY + pointx[i]*unit ,positionX - point[i] * unit -1,positionY + pointx[i+1] *unit,positionX - point[i+1] * unit -1 );
            SDL_RenderDrawLine(grender,positionY + pointx[i]*unit ,positionX - point[i] * unit,positionY + pointx[i+1] *unit,positionX - point[i+1] * unit );
            }
             SDL_SetRenderDrawColor(grender,255,0,0,255);
           if(positionY + pointx[i] *50 <= widht*7 && positionY + pointx[i] *50 >= widht - widht * 7 && positionX - pointr[i+1] * unit <= (height) *7 && positionX - pointr[i] * unit >= height - height * 8 )
            {
            SDL_RenderDrawLine(grender,positionY + pointx[i]*unit  ,positionX - pointr[i] * unit +1 ,positionY + pointx[i+1] *unit ,positionX - pointr[i+1] * unit +1 );
            SDL_RenderDrawLine(grender,positionY + pointx[i]*unit ,positionX - pointr[i] * unit -1,positionY + pointx[i+1] *unit,positionX - pointr[i+1] * unit -1 );
            SDL_RenderDrawLine(grender,positionY + pointx[i]*unit ,positionX - pointr[i] * unit,positionY + pointx[i+1] *unit,positionX - pointr[i+1] * unit );
            }
           
        }
    }

   private:
   float positionX , positionY;

};


void load()
{
  SDL_Surface* msurface=IMG_Load("1.png");
  text =SDL_CreateTextureFromSurface(grender,msurface);
            SDL_FreeSurface(msurface);
}








bool init()
{   
    bool suc= true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
         printf("could not init vedio %s\n",SDL_GetError());
         suc=false;
    }
    else
    {  // SDL_SetHint(SDL_HINT_RENDER_VSYNC,"1");
        gwindo=SDL_CreateWindow("FS DEVLIMIT",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,widht,height,SDL_WINDOW_SHOWN );
        if(gwindo==NULL)
        {
            printf("could not creat window %s\n",SDL_GetError());
                 suc=false;
        }
        else
        {
        grender=SDL_CreateRenderer(gwindo,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(grender==NULL)
        {
            printf("could not creat renderer %s\n",SDL_GetError());
            suc=false;
        }
        else
        {     if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
            {
               printf("could not init img %s\n",IMG_GetError());
            suc=false;
            } 
         }
        }
    }
    return suc;
}

int main(int argc, char *argv[])
{
  
   std::fstream file("a.txt",std::ios::in);
      if(file.is_open())
      {
        file>>a;
           
        
         
      file.close();
     
      }
      std::fstream filre("f a point.txt",std::ios::in);
      if(filre.is_open())
      {
        filre>>ax;
           std::cout<<ax<<std::endl;
        
         
      filre.close();
     
      }

      ///////////////////////////////////////////////////
    std::fstream fil("point fx .txt",std::ios::in);
      if(fil.is_open())
      {
        
        for(int i=0 ; i<100 ; i++){
            
            fil>>point[i];        
      }
     
        fil.close();
      }
      else
      {
           for(int i=0 ; i<100 ; i++){
            
           point[i] = 0;        
      }
      }
      std::fstream fl("point fx prime.txt",std::ios::in);
      if(fl.is_open())
      {
        
        for(int i=0 ; i<100 ; i++){
            
            fl>>pointr[i];        
      }
       
        fl.close();
      }
      else
      {
           for(int i=0 ; i<100 ; i++){
            
           pointr[i] = 0;        
      }
      
      
      }
      
       std::fstream filr("f x point.txt",std::ios::in);
      if(filr.is_open())
      {
        
        for(int i=0 ; i<100 ; i++){
            
            filr>>pointx[i];        
      }
     
        filr.close();
      }
      else
      {
           for(int i=0 ; i<100 ; i++){
            
           pointx[i] = 0;        
      }}
         
       ma3lam z;
  
  
  if(!init())
   {
       printf("could not init()\n");
   }
   else
   {
        bool quit =false;
         SDL_Event e;
         
             
load();
       while(!quit)
         {   while(SDL_PollEvent(&e)!=0)
             {
                  if(e.type==SDL_QUIT)
                  {
                      quit=true;

                  }
             }
             //////////////////////////////////////
           SDL_Rect rect = {0,0,720,720};
        

    ////////////////////////// ///////////////////////////////////////////////////////////////////////////////               
               SDL_SetRenderDrawColor(grender,49,52,56,255);
               SDL_RenderClear(grender);
            
               z.draw();
               z.drawpoint_A();
               z.Draw_Dala();
              SDL_RenderCopy(grender,text,NULL,&rect);
               SDL_RenderPresent(grender);
         
         }
   }
      exit();
    return 0;
}