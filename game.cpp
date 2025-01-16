#include "Draw.hpp"

int FPS = 60 ;
Uint32 elapsed = 0 ;
int frameTime = 0 ;



void GAME :: Init ()
{
    w = SDL_CreateWindow ( "Tic Tac Toe " , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WIDTH , HEIGHT , screen ) ;
     if ( !w )
      std:: cout << " Error couldnt create window -> " << SDL_GetError() << std:: endl ;
     else
     {
         r = SDL_CreateRenderer ( w , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;
          if ( !r )
           std:: cout << " Error couldnt render the game -> " << SDL_GetError() << std:: endl ;   
       Resete ( Black ) ;
    }
}
void GAME:: SetGame()
{
    for ( int i = 0 ; i <= c ; i++ )
      for ( int j = 0 ; j <= c ; j++ )
       a[i][j] = 0 ;  
}
void GAME:: Present ()
{
  SDL_RenderCopy ( r , te , NULL , NULL ) ;
  SDL_RenderPresent ( r ) ;
}
void GAME:: Clear ()
{
  SDL_RenderClear ( r ) ;
}
void GAME::Leave() 
{
    SDL_DestroyTexture ( te ) ;
    SDL_DestroyRenderer ( r ) ;
    SDL_DestroyWindow ( w ) ;
    SDL_Quit() ;
}
void GAME::Platform( SDL_Color S ) 
{   
    int x = 160 ,
    y= 20 , Y= 400 ;
    SDL_SetRenderDrawColor ( r , S.r , S.g , S.b, S.a ) ;

    for ( int i = 1 ; i <= 2 ; i++ )
     ThickLine ( r , x/12 , y*7*i , x*3 , y*7*i );

    for ( int i = 1 ; i <= 2 ; i++ )
      ThickLine ( r , x*i  , y, x*i , y*20 ) ; ;
}
bool GAME::Array( int i , int j )
{
   if ( a[i][j] == 0 )
    {
        if ( ot )
         a[i][j] = 1 ;
        else if ( xt )
         a[i][j] = 2 ;
        return true ;
    }
    else 
    return false ;
}
bool GAME::EmptyPos( int x , int y)
{

 if ( x < 160 && y< 400 )
    {
      int i = 0 ;
       if ( y < 140 )
          return Array( 0 , i ) ;
       
       else if ( y > 140 && y < 280 )
         return Array( 1 , i ) ;

       else if ( y > 280 && y < 400 )
        return Array( 2 , i ) ;
    }


else if ( ( x > 160 && x < 320 ) &&  y<= 400 )
    {
        int i = 1 ;
       if ( y< 140 )
        return Array( 0 , i ) ;

       else if ( y> 140 && y< 280 )
         return Array( 1 , i ) ;

       else if ( y> 280 && y< 400 )
         return Array( 2 , i ) ;
    }


 else if ( ( x > 320 && x < 480 ) && y< 400 )
    {
        int i = 2 ;
       if ( y< 140 )
        return Array( 0 , i ) ;

       else if ( y> 140 && y< 280 )
        return Array( 1 , i ) ;

       else if ( y> 280 && y< 400 )
        return Array( 2 , i ) ;
    }
 return false ;
 
}
void GAME::fix_values ( int & x , int & y)
{
   if ( y< 140 )
    y= 160/2 ;
   else if ( y> 140 && y< 280 )
    y= 420/2 ;
   else if ( y> 280 )
    y= 680/2 ;
   //
    if ( x < 160 )
     x = 173 /2 ;
    if ( x > 160 && x < 320 )
     x = 480 / 2 ;
    if ( x > 320 )
     x = 800 /2 ;
}

void GAME::Resete ( SDL_Color R )
{
   SDL_SetRenderDrawColor ( r , R.r , R.g , R.b , R.a ) ;
   Clear() ;
   Platform( TurnColor() ) ;
   Draw_Score ( r , te  ) ;
   Draw_Number ( r , te , os , 1 ) ;
   Draw_Number ( r , te , xs , 0 ) ;
   
      if ( xs == 0 && os == 0 )
       {
        ot = true ;
        xt = false ;
       }
      else if ( xs >= os )
       {
        xt = true ;
        ot = false ;
       }
       else
       {
         ot = true ;
         xt = false ;
       }

    SetGame() ;
} 

void GAME::SwapTurns () 
{
     if ( ot == true )
     {
      xt = true ; 
      ot = false ;
      Platform ( TurnColor () ) ;
     }
     else if ( xt == true )
     {
      xt = false ; 
      ot = true  ;
      Platform ( TurnColor () ) ;
     }
     else if ( xt == false && ot == false  )
     {
       SDL_Delay ( 200 ) ;
        if ( xs > os )
         xt = true ;
        else 
         ot = true ;
     }

}

void GAME::Event() 
{
     int x , y;
    while ( SDL_PollEvent (&e) )
    {
        switch ( e.type )
        { 
             case SDL_QUIT : 
               quit = true;
              break;

            case SDL_MOUSEBUTTONUP : 
               SDL_GetMouseState( &x , &y) ;
                if ( EmptyPos ( x , y) == true  )
                 {
                    std:: cout << " x = " << x << " / y : " << y << std:: endl ;
                    t++;
                    fix_values ( x , y) ;
                    Draw ( x , y) ;
                 }
             break;

            case SDL_KEYDOWN : 
              for ( int i = 0 ; i <= c ; i++ )
              {
               for ( int j = 0 ; j <= c ; j++ )
                {
                    std:: cout << a[j][i] << " " ;
                }
               std:: cout << std:: endl ;
              }
             break;
        }
    }

}

char GAME::TurnChar ()
{
   if ( ot == false )
    return 'o' ;
   else if ( xt == false )
    return 'x' ;

  return 'e' ;
}

void GAME::HandleEvent() 
{
  if ( t == 9 )
   {
    Resete ( Black ) ;
    SDL_Delay ( 200 ) ;
     SetGame() ;
     t = 0 ;
   }
   else
    WinCondition ( TurnChar() ) ;

}

void GAME::WinCondition ( char s ) 
{
  int n = 0 ;
     if ( s == 'o' )
      n = 1 ;
     else if ( s == 'x' ) 
      n = 2 ;
    
  FindWinner ( n ) ;

}

void GAME::FindWinner ( int n ) 
{
   bool g [8] = { Array_Column( a , 0 , n ) ,  Array_Column( a , 1 , n ) ,  Array_Column( a , 2 , n ) , 
                  Array_Row( a , 0 , n ) , Array_Row( a , 1 , n ) , Array_Row( a , 2 , n ) , 
                  ArrayOther1( a , n ) , ArrayOther2 ( a , n ) } ;
    int i = 0 ;
    while ( g[i] == false && i != 8 )
     i++;
    
    if ( g[i] == true )
      ShowWinner ( i , n ) ;
}


SDL_Color GAME::TurnColor ()
{
   if ( ot )
    return Blue ;
   else
    return Red ;
}

void GAME::ShowWinner ( int n , int j )
{
   switch ( n )
   {
     case 0 :
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os ++ ;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         } 
      break;

     case 1 :
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os++;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         } 
      break;

     case 2 : 
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os++;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         }
      break;
     case 3 :
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os++;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         } 
      break;
     case 4 :
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os++;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         } 
      break;
     case 5 :
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os++;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         } 
      break;
     case 6 :
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os++;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         } 
      break;
     case 7 :
        if ( j == 1 )
         {
           t = 9 ;
           xt = false ; ot = false ;
           os++;
         }
         else
         {
           t = 9 ;
           xt = false ; ot = false ;
           xs++;
         } 
      break;
   }
 
ProveWinner ( n , j) ;

}


void GAME:: ProveWinner ( int n , int j )
{

  SDL_Color F  ;
    if ( j == 1 )
     {
      F = Blue ;
      std:: cout << " O : " << os << std:: endl ;
     }
    else
     {
      F = Red ;
      std:: cout << " X : " << xs << std:: endl ;
     }


Resete ( Black ) ;
Platform ( F ) ;

    switch ( n )
    {
       case 0 : 
        for ( int i = 0 ; i <= 2 ; i++ )
            NumDraw ( j , pos[i].x , pos[i].y ) ;
        
        break;
       case 1 :
        for ( int i = 3 ; i <= 5 ; i++ )
          NumDraw ( j , pos[i].x , pos[i].y ) ;
        
        break;    
       case 2 : 
        for ( int i = 6 ; i <= 8 ; i++ )
           NumDraw ( j , pos[i].x , pos[i].y ) ;
        break;
       case 3 : 
        for ( int i = 0 ; i <= 6 ; i += 3 )
            NumDraw ( j , pos[i].x , pos[i].y ) ;
        break;
       case 4 : 
        for ( int i = 1 ; i <= 7 ; i += 3 )
            NumDraw ( j , pos[i].x , pos[i].y ) ;
        break;
       case 5 : 
        for ( int i = 2 ; i <= 8 ; i += 3 )
            NumDraw ( j , pos[i].x , pos[i].y ) ;
        break;
       case 6 : 
        for ( int i = 0 ; i <= 8 ; i += 4 )
            NumDraw ( j , pos[i].x , pos[i].y ) ;
        break;
       case 7 : 
        for ( int i = 2 ; i <= 6 ; i += 2 )
            NumDraw ( j , pos[i].x , pos[i].y ) ;
        break;
    }
  
  Present () ;
  SDL_Delay ( 250 );
}

void GAME::NumDraw ( int n , int x , int y )
{
  if ( n == 1 )
   DrawO ( r , x , y ) ;
  else if ( n == 2 )
   DrawX ( r , x , y ) ;
}

void GAME::Draw( int x , int y)
{
    if ( ot )
     {
      DrawO ( r , x , y) ;
      SwapTurns() ;
     }

    else if ( xt )
     {
       DrawX ( r , x , y) ;
       SwapTurns() ;
     }
}

void Start ()
{
    GAME * xO = new GAME ;
    xO->Init() ;
    while ( xO->Exit() == false )
    {
      elapsed = SDL_GetTicks() ;

        xO->Event() ;
        xO->WinCondition ( xO->TurnChar() )  ;
        xO->Present() ;
        xO->HandleEvent() ;
       frameTime = SDL_GetTicks() - elapsed ;
       if ( FPS > frameTime )
         SDL_Delay ( FPS - frameTime ) ;
         
    }
    xO->Clear() ;
    xO->Leave() ;

}