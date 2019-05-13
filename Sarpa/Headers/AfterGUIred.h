#ifndef AFTERGUIRED_H_INCLUDED
#define AFTERGUIRED_H_INCLUDED

void newwindowred()
{
    num1=4;
    num2=4;

    RenderWindow window (VideoMode(w+20,h+20),"Sarpa!!");

    Texture t1,t2,t3,trlt,trrt,trup,trdn,tglt,tgrt,tgup,tgdn;
    t1.loadFromFile("Images/Snake/red/red.png");
    t2.loadFromFile("Images/Snake/green/green.png");
    t3.loadFromFile("Images/Prey/mouse.png");
    trlt.loadFromFile("Images/Snake/red/redlt.png");
    trrt.loadFromFile("Images/Snake/red/redrt.png");
    trup.loadFromFile("Images/Snake/red/redup.png");
    trdn.loadFromFile("Images/Snake/red/reddn.png");
    tglt.loadFromFile("Images/Snake/green/greenlt.png");
    tgrt.loadFromFile("Images/Snake/green/greenrt.png");
    tgup.loadFromFile("Images/Snake/green/greenup.png");
    tgdn.loadFromFile("Images/Snake/green/greendn.png");

    Sprite player1(t1), player2(t2), musa(t3);
    Sprite redlt(trlt),redrt(trrt),redup(trup),reddn(trdn);
    Sprite greenlt(tglt),greenrt(tgrt),greenup(tgup),greendn(tgdn);


    Texture back2;
        back2.loadFromFile("Images/Backgrounds/x2.jpg");
    Sprite b2(back2);

    Texture bugsrone,bugsrtwo,bugsrthree,bugsrfour;
        bugsrone.loadFromFile("Images/prey/bugr1.png");
        bugsrtwo.loadFromFile("Images/prey/bugr2.png");
        bugsrthree.loadFromFile("Images/prey/bugr3.png");
        bugsrfour.loadFromFile("Images/prey/bugr4.png");
    Sprite bugir1(bugsrone),bugir2(bugsrtwo),bugir3(bugsrthree),bugir4(bugsrfour);


    Clock clock;
    float timer = 0;
    float delay = 0.1 ;

    //Clock clock2;
    //float timer2 = 0;

    mouse.x = 10 ;
    mouse.y = 10 ;

    bugr2.x= 50;
    bugr2.y= rand()%M;

    bugr4.x= rand()%N;
    bugr4.y= 0;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time ;
        /*float time2 = clock2.getElapsedTime().asSeconds();
        clock2.restart();
        timer2 += time2 ;
        */

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }
        //Setting Keyboard Movement
        if(Keyboard::isKeyPressed(Keyboard::Left))   { if(dir1 != 2) dir1 = 1 ; }
        if(Keyboard::isKeyPressed(Keyboard::Right))  { if(dir1 != 1) dir1 = 2 ; }
        if(Keyboard::isKeyPressed(Keyboard::Up))     { if(dir1 != 0) dir1 = 3 ; }
        if(Keyboard::isKeyPressed(Keyboard::Down))   { if(dir1 != 3) dir1 = 0 ; }
        if(Keyboard::isKeyPressed(Keyboard::A))     { if(dir2 != 2) dir2 = 1 ; }
        if(Keyboard::isKeyPressed(Keyboard::D))     { if(dir2 != 1) dir2 = 2 ; }
        if(Keyboard::isKeyPressed(Keyboard::W))     { if(dir2 != 0) dir2 = 3 ; }
        if(Keyboard::isKeyPressed(Keyboard::S))     { if(dir2 != 3) dir2 = 0 ; }
        //Setting Timer
        /*if(timer2>40){
            timer2=0;
        }
        */

        if (timer>delay ){
            timer = 0;
            delay = delay*0.9999;
            Move();
            Preys();
        //Setting Collision
        if ( num1 != 4 ){
            p = snakecollision() ;
            r = preycollisionred() ;

        }
        if ( num2 != 4 ){
            p = snakecollision() ;
            r = preycollisionred() ;
        }
    window.clear();

                b2.setPosition(10,10);
                window.draw(b2);

    //Setting sprites for snakes' cubes
   for ( int i=0 ; i<num1 ; i++){
          if(i==0){
            if(dir1==1)
                {
                    redlt.setPosition(snake1[i].x*size , snake1[i].y*size);
                    window.draw(redlt);
                }
            else if(dir1==2)
                {
                    redrt.setPosition(snake1[i].x*size , snake1[i].y*size);
                    window.draw(redrt);
                }
            else if(dir1==3)
                {
                    redup.setPosition(snake1[i].x*size , snake1[i].y*size);
                    window.draw(redup);
                }
            else
                {
                    reddn.setPosition(snake1[i].x*size , snake1[i].y*size);
                    window.draw(reddn);
                }
        }
       else{
                player1.setPosition(snake1[i].x*size , snake1[i].y*size);
                window.draw(player1);
        }
            }

        for ( int i=0 ; i<num2 ; i++){
          if(i==0){
            if(dir2==1)
                {
                    greenlt.setPosition(snake2[i].x*size , snake2[i].y*size);
                    window.draw(greenlt);
                }
            else if(dir2==2)
                {
                    greenrt.setPosition(snake2[i].x*size , snake2[i].y*size);
                    window.draw(greenrt);
                }
            else if(dir2==3)
                {
                    greenup.setPosition(snake2[i].x*size , snake2[i].y*size);
                    window.draw(greenup);
                }
            else
                {
                    greendn.setPosition(snake2[i].x*size , snake2[i].y*size);
                    window.draw(greendn);
                }
        }
       else{
                player2.setPosition(snake2[i].x*size , snake2[i].y*size);
                window.draw(player2);
        }
            }


    //Food for snakes
    musa.setPosition( mouse.x*size , mouse.y*size );
    window.draw(musa);

    bugir2.setPosition( bugr2.x*size , bugr2.y*size );
    window.draw(bugir2);

    bugir4.setPosition( bugr4.x*size , bugr4.y*size );
    window.draw(bugir4);


    if ( p == 1 || r ==1 ){
        cout<<"Red Rattle Wins."<<endl ;
        countr++;
        window.close() ;
    }
    if ( p == 2 || r ==2){
        cout<<"Green Mamba Wins."<<endl ;
        countg++;
        window.close() ;
    }
    window.display();
    }
  }
}

#endif // AFTERGUIRED_H_INCLUDED
