#ifndef AFTERGUI_H_INCLUDED
#define AFTERGUI_H_INCLUDED
void newwindow()
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

    Texture back1;
        back1.loadFromFile("Images/Backgrounds/x1.jpg");
    Sprite b1(back1);

    Texture bugsrone,bugsrtwo,bugsrthree,bugsrfour;
        bugsrone.loadFromFile("Images/prey/bugr1.png");
        bugsrtwo.loadFromFile("Images/prey/bugr2.png");
        bugsrthree.loadFromFile("Images/prey/bugr3.png");
        bugsrfour.loadFromFile("Images/prey/bugr4.png");
    Sprite bugir1(bugsrone),bugir2(bugsrtwo),bugir3(bugsrthree),bugir4(bugsrfour);

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

    bugr1.x= rand()%N;
    bugr1.y= 40;

    bugr3.x= 0;
    bugr3.y= rand()%M;

    bugg2.x= 50;
    bugg2.y= rand()%M;

    bugg4.x= rand()%N;
    bugg4.y= 0;

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
            q = preycollision() ;
        }
        if ( num2 != 4 ){
            p = snakecollision() ;
            q = preycollision() ;
        }
    window.clear();
                b1.setPosition(10,10);
                window.draw(b1);

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

    bugir1.setPosition( bugr1.x*size , bugr1.y*size );
    window.draw(bugir1);

    bugig2.setPosition( bugg2.x*size , bugg2.y*size );
    window.draw(bugig2);

    bugir3.setPosition( bugr3.x*size , bugr3.y*size );
    window.draw(bugir3);

    bugig4.setPosition( bugg4.x*size , bugg4.y*size );
    window.draw(bugig4);

    if ( p == 1 || q==1 ){
        cout<<"Red Rattle Wins."<<endl ;
        countr++;
        gameover=1;
        window.close() ;
    }
    if ( p == 2 || q==2 ){
        cout<<"Green Mamba Wins."<<endl ;
        gameover=1;
        countg++;
        window.close() ;
    }

    window.display();
    }
  }
}
#endif // AFTERGUI_H_INCLUDED
