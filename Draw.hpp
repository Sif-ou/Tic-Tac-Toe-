#include "game.hpp"
#define H  500 
#define D 50
#define CN 9

char Num [] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' ,'7' , '8' , '9' } ;

SDL_Rect Orect , Xrect ;


char intTochar ( int n ) 
{
  char s = 'N' ;

      for ( int i = 0 ; i <= CN ; i++ )
        if ( i == n )
         s = Num[i] ;

  return s ;
}


void Draw_Number ( SDL_Renderer * r , SDL_Texture * b , int k  , int n )
{
   SDL_Rect Nrect ;
   Nrect.w = 40 ;
   Nrect.h = 45 ;

char s  ;
int i = 0  , t ;
    if ( k <= 9 )
     {
      s = intTochar ( k ) ;
      i = 0 ; 
     }
    else if ( k <= 99 )
     {
       t = k/10 ;
       s = intTochar (t) ;
       i = 1 ;
     }     

 for ( int j = 0 ; j <= i ; j++ )
 {
     switch ( s )
      {
      case '0' :
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/0_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/0_r.png") ;
        }    
        break;
       
       case '1' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/1_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/1_r.png") ;
        }  
        break;

       case '2' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/2_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/2_r.png") ;
        }  
        break;
       case '3' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/3_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/3_r.png") ;
        }  
        break;
       case '4' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/4_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/4_r.png") ;
        }  
        break;
       case '5' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/5_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/5_r.png") ;
        }  
        break;
       case '6' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/6_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/6_r.png") ;
        }  
        break;
       case '7' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/7_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/7_r.png") ;
        }  
        break;
       case '8' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/8_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/8_r.png") ;
        }  
        break;
       case '9' : 
       if ( n == 1 )
        {
           Nrect.x = 780 + j * 40 ; 
           Nrect.y = H+100 ;
          b = IMG_LoadTexture ( r , "assets/9_b.png") ;
        }
       else 
        {
           Nrect.x = 170 + j * 40 ; 
           Nrect.y = H+100 ;
           b = IMG_LoadTexture ( r , "assets/9_r.png") ;
        }  
        break;

      }
     
      if ( i > 0 )
       {
          SDL_RenderCopy ( r , b , NULL , &Nrect ) ;
          s = intTochar ( k - t * 10 ) ;
       }
      else
       SDL_RenderCopy ( r , b , NULL , &Nrect ) ;  
 }
    
}




void Draw_Score ( SDL_Renderer * r , SDL_Texture * b  ) 
{
     Xrect.x = 100 ;
     Xrect.y = H ;
     Xrect.w = 100 ;
     Xrect.h = D ;

     Orect.x = 700;
     Orect.y = H ;
     Orect.h = D ;
     Orect.w = 100 ;
     
    
     DrawO ( r , Orect.x , Orect.y ) ;
     DrawX ( r , Xrect.x , Xrect.y ) ;

     Xrect.y += 100 ;
     Xrect.x -= D ;
     b = IMG_LoadTexture ( r , "assets/Xs.png") ;
     SDL_RenderCopy ( r , b , NULL , &Xrect ) ;

     Orect.y +=100 ; 
     Orect.x -= D-10 ;
     b = IMG_LoadTexture ( r , "assets/Os.png") ;
     SDL_RenderCopy ( r , b , NULL , &Orect ) ;

}





