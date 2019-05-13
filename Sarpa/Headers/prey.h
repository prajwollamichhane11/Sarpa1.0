#ifndef PREY_H_INCLUDED
#define PREY_H_INCLUDED

struct bug{
    int x;
    int y;
}bugr1,bugr2,bugr3,bugr4,bugg1,bugg2,bugg3,bugg4;

void Preys(){
    bugr1.y-=1;
    bugr2.x-=1;
    bugr3.x+=1;
    bugr4.y+=1;

    bugg1.y-=1;
    bugg2.x-=1;
    bugg3.x+=1;
    bugg4.y+=1;

    if  (bugr1.y<0)
    {
            bugr1.x= rand()%N;
            bugr1.y= M;
    }
    if  (bugr2.x<0)
    {
            bugr2.x= N;
            bugr2.y= rand()%M;
    }
    if  (bugr3.x>N)
    {
            bugr3.x= 0;
            bugr3.y= rand()%M;

    }
    if  (bugr4.y>M)
    {
            bugr4.x= rand()%N;
            bugr4.y= 0;
    }

    if  (bugg1.y<0)
    {
            bugg1.x= rand()%N;
            bugg1.y= M;
    }
    if  (bugg2.x<0)
    {
            bugg2.x= N;
            bugg2.y= rand()%M;
    }
    if  (bugg3.x>N)
    {
            bugg3.x= 0;
            bugg3.y= rand()%M;

    }
    if  (bugg4.y>M)
    {
            bugg4.x= rand()%N;
            bugg4.y= 0;
    }
}
int preycollision(){
    for( i=1 ; i<num1 ; ++i ){
             if ((snake1[i].x == bugg2.x  && snake1[i].y == bugg2.y) ||
             (snake1[i].x == bugg4.x  && snake1[i].y == bugg4.y)){
          return 2;

    snake1[1].x=4;
    snake1[1].y=4;
    snake2[1].x=4;
    snake2[1].y=47;
        }
    }
    for( i=1 ; i<num2 ;++i){
            if ( (snake2[i].x == bugr1.x  && snake2[i].y == bugr1.y) ||
             (snake2[i].x == bugr3.x  && snake2[i].y == bugr3.y)){
           return 1;

    snake1[1].x=4;
    snake1[1].y=4;
    snake2[1].x=4;
    snake2[1].y=47;
         }
    }
}
int preycollisionred(){
    for( i=1 ; i<num2 ;++i){
            if ((snake2[i].x == bugr2.x  && snake2[i].y == bugr2.y) ||
                (snake2[i].x == bugr4.x  && snake2[i].y == bugr4.y)){
           return 1;
         }
    }
}
int preycollisiongreen(){
for( i=1 ; i<num1 ; ++i ){
             if ( (snake1[i].x == bugg1.x  && snake1[i].y == bugg1.y) ||
             (snake1[i].x == bugg3.x  && snake1[i].y == bugg3.y)){
          return 2;
        }
    }
    }
#endif // PREY_H_INCLUDED
