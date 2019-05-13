#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

struct Snake{
    int x;
    int y;
    }snake1[1000],snake2[1000];

struct Food{
    int x;
    int y;
    }mouse;

int snakecollision(){
      for( i=1 ; i<num1 ; ++i ){
        if ( (snake1[i].x == snake2[0].x  && snake1[i].y == snake2[0].y)){
          return 1;
        }
       }

       for( i=1 ; i<num2 ; ++i ){
         if ( (snake2[i].x == snake1[0].x  && snake2[i].y == snake1[0].y)){
           return 2;
         }
    }
}

#endif // SNAKE_H_INCLUDED
