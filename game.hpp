#include "SDL.h"
#include <cmath>
#include "SDL_image.h"
#include <iostream>

#define HEIGHT 420+300
#define WIDTH 640+300
#define screen 0
#define c 2
#define PI 3.14
#define C1 65
#define C2 50

SDL_Color Red { 255 , 0 , 0 , 0} , Blue { 0 , 0 , 255 , 0 } , Green { 0 , 255 , 0 , 0 } , 
Black { 0 , 0 , 0 , 0 } , White { 255 , 255 , 255 , 255 } , Grey { 108 , 122 , 137 , 1 } ,
* C = nullptr ;



void ThickLine ( SDL_Renderer * r , float x1 , float y1 , float x2 , float y2 )
{
   for ( int i = 0 ; i <= 5 ; i++ )
     SDL_RenderDrawLineF ( r , x1+i , y1+i , x2+i , y2+i ) ;
}

void ThickPoint ( SDL_Renderer * r , float x , float y )
{
   for ( int i = 0 ; i <= 4 ; i++ )
    {
        SDL_RenderDrawPointF ( r , x , y+i ) ;
        SDL_RenderDrawPointF ( r , x , y-i ) ;
        SDL_RenderDrawPointF ( r , x+i , y ) ;
        SDL_RenderDrawPointF ( r , x-i , y ) ;
    }

    
}

void DrawO ( SDL_Renderer * r , int x , int y )
{
    C = &Blue ;
    int rad =50 ;
    double s = PI / 180 ;
    SDL_SetRenderDrawColor ( r , C->r , C->g , C->b , C->a ) ;   
       for ( int i = 0 ; i <= 360 ; i++ )
          ThickPoint ( r ,  x + (cos ( s * i ) * rad  ) , y+( sin(s*i) * rad ) ) ;
  
       // SDL_RenderDrawPoint ( r ,  point.x + (cos ( s * i ) * rad  ) , point.y+( sin(s*i) * rad ) );
}

void DrawX ( SDL_Renderer * r , int x , int y )
{
    C = &Red ;
    SDL_SetRenderDrawColor ( r , C->r , C->g , C->b , C->a ) ;   
     for ( int i = 0 ; i <= C2 ; i++ )
      {
        ThickPoint ( r , x+i , y+i ) ;
        ThickPoint ( r , x-i , y-i ) ;
        ThickPoint ( r , x+i , y-i ) ;
        ThickPoint ( r , x-i , y+i ) ;
      }
}


bool Array_Row ( int a [3][3] , int f , int n )
{
    int co = 0 ;
     for ( int i = 0 ; i <= 2 ; i++ )
      if ( a[i][f] == n )
       co++ ;
    
    if ( co == 3 )
     return true ;

 return false ;

}

bool Array_Column ( int a [3][3] , int f  , int n  )
{
    int co = 0 ;
     for ( int i = 0 ; i <= 2 ; i++ )
      if ( a[f][i] == n )
       co++ ;
    
    if ( co == 3 )
     return true ;

 return false ;
}

bool ArrayOther1 ( int a[3][3] , int n )
{
    int co = 0 ;
     for ( int i = 0 ; i <= 2 ; i++ )
      if ( a[i][i] == n )
       co++ ;
    if ( co == 3 )
     return true ;

    return false ;
}

bool ArrayOther2 ( int a[3][3] , int n )
{
    int co = 0 ;
     for ( int i = 0 ; i <= 2 ; i++ )
      if ( a[i][2-i] == n )
       co++ ;
    if ( co == 3 )
     return true ;

    return false ;
}


struct Tint 
{
   int x , y ;
};

Tint pos [9] = { {86 , 80} , {240 , 80 } , {400 , 80} , 
                  { 86 , 210} , {240 , 210} , {400 , 210} ,
                  { 86 , 340 } , {240 , 340} , {400 , 340} } ;

class GAME 
{
    private :
    SDL_Window * w  = nullptr ;
    SDL_Renderer * r = nullptr ;
    SDL_Texture * te = nullptr ;
    bool quit = false ;

    public : 
     SDL_Event e ;
     bool ot = true , xt = false ;
     int a [3][3] ,  t = 0 ;
     int os = 0 , xs = 0 ;
     
    bool Exit () { return quit ; } ;
    void Resete ( SDL_Color R ) ;
    void SetGame () ;
    void Init () ;
    void Present () ;
    void Clear () ;
    void Leave () ;
    void Event () ;
    void Platform( SDL_Color S ) ;
    void Draw ( int x , int y ) ;
    bool EmptyPos ( int x , int y ) ;
    bool Array ( int i , int j ) ;
    void fix_values ( int &x , int &y ) ;
    void HandleEvent () ;
    void SwapTurns () ;
    char TurnChar () ; 
    void WinCondition ( char s ) ;
    void FindWinner ( int n ) ;
    void ShowWinner ( int n , int j ) ;
    void ProveWinner ( int n , int j ) ; 
    void NumDraw ( int n , int x , int y ) ;
    SDL_Color TurnColor () ;
};