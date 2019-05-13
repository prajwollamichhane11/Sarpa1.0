#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

void Move(){
    //This is for the movement of the snakes one step
    //For snake 1st
    for ( i=num1 ; i>0 ; i--){

        snake1[i].x = snake1[i-1].x ;
        snake1[i].y = snake1[i-1].y ;

        }
    //For snake 2nd
    for ( i=num2 ; i>0 ; i--){

        snake2[i].x = snake2[i-1].x ;
        snake2[i].y = snake2[i-1].y ;

        }
//Setting Direction For Keyboard
        if( dir1 == 0 ) snake1[0].y += 1;
        if( dir1 == 1 ) snake1[0].x -= 1 ;
        if( dir1 == 2 ) snake1[0].x += 1 ;
        if( dir1 == 3 ) snake1[0].y -= 1 ;

        if( dir2 == 0 ) snake2[0].y += 1 ;
        if( dir2 == 1 ) snake2[0].x -= 1 ;
        if( dir2 == 2 ) snake2[0].x += 1 ;
        if( dir2 == 3 ) snake2[0].y -= 1 ;

        //Food Eating
        //Food by snake 1st
        if(( snake1[0].x==mouse.x ) && ( snake1[0].y == mouse.y )){
            num1++;
            mouse.x = rand() % N ;
            mouse.y = rand() % M ;
        }
        //Food by snake 2nd
        if(( snake2[0].x==mouse.x ) && ( snake2[0].y == mouse.y )){
            num2++;
            mouse.x = rand() % N ;
            mouse.y = rand() % M ;
        }
//Restarting points for snakes
    if (snake1[0].x>N) snake1[0].x=0;
    if (snake1[0].x<0) snake1[0].x=N;
    if (snake1[0].y>M) snake1[0].y=0;
    if (snake1[0].y<0) snake1[0].y=M;

    if (snake2[0].x>N) snake2[0].x=0;
    if (snake2[0].x<0) snake2[0].x=N;
    if (snake2[0].y>M) snake2[0].y=0;
    if (snake2[0].y<0) snake2[0].y=M;


        for( i=1 ; i<num1 ; i++ ){
            if( snake1[0].x == snake1[i].x  &&  snake1[0].y == snake1[i].y )    num1 = i ;       //windwon.close()
        }

        for( i=1 ; i<num2 ; i++ ){
            if( snake2[0].x == snake2[i].x  &&  snake2[0].y == snake2[i].y )    num2 = i ;       //windwon.close()
        }

}
#endif // MOVEMENT_H_INCLUDED
