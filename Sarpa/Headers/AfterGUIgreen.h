#ifndef AFTERGUIGREEN_H_INCLUDED
#define AFTERGUIGREEN_H_INCLUDED

void newwindowgreen()
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


    Texture back3;
        back3.loadFromFile("Images/Backgrounds/x3.jpg");
    Sprite b3(back3);

    Texture bugsgone,bugsgtwo,bugsgthree,bugsgfour;
        bugsgone.loadFromFile("Images/prey/bugg1.png");
        bugsgtwo.loadFromFile("Images/prey/bugg2.png");
        bugsgthree.loadFromFile("Images/prey/bugg3.png");
        bugsgfour.loadFromFile("Images/prey/bugg4.png");
    Sprite bugig1(bugsgone),bugig2(bugsgtwo),bugig3(bugsgthree),bugig4(bugsgfour);

    Clock clock;
    float timer = 0;
    float delay = 0.1 ;

    //Clock clock2;
    //float timer2 = 0;

    mouse.x = 10 ;
    mouse.y = 10 ;

    bugg1.x= rand()%N;
    bugg1.y= 40;

    bugg3.x= 0;
    bugg3.y= rand()%M;

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
            g = preycollisiongreen() ;
        }
        if ( num2 != 4 ){
            p = snakecollision() ;
            g = preycollisiongreen() ;
        }
    window.clear();

                b3.setPosition(10,10);
                window.draw(b3);

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

    bugig1.setPosition( bugg1.x*size , bugg1.y*size );
    window.draw(bugig1);

    bugig3.setPosition( bugg3.x*size , bugg3.y*size );
    window.draw(bugig3);

    if ( p == 1 || g==1){
        cout<<"Red Rattle Wins."<<endl ;
        countr++;
          window.close() ;
    }
    if ( p == 2 || g==2){
        cout<<"Green Mamba Wins."<<endl ;
        countg++;
        window.close() ;
    }
    window.display();
    }
  }
}


#endif // AFTERGUIGREEN_H_INCLUDED
