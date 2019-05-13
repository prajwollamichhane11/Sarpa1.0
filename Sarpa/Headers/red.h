#ifndef RED_H_INCLUDED
#define RED_H_INCLUDED
void red(){

    RenderWindow red (VideoMode(w,h),"Sarpa");

    SoundBuffer re;
    re.loadFromFile("Audios/red.wav");
    Sound redy;
    redy.setBuffer(re);

    Texture background;
    background.loadFromFile("Images/Backgrounds/backgroundr.jpg");
    Sprite bg(background);

    Texture mainpic;
    mainpic.loadFromFile("Images/Pictures/redrattle.jpg");
    Sprite mp(mainpic);

    Clock clockred;
    float timerred=0;

    while(red.isOpen())
    {
        float timered = clockred.getElapsedTime().asSeconds();
        clockred.restart();
        timerred += timered ;

        Event newevent;
        while (red.pollEvent(newevent))
        {
            if(newevent.type == Event::Closed)
                red.close();
        }


        bg.setPosition(0,0);
            red.draw(bg);

        mp.setPosition(237,55);
            red.draw(mp);

        redy.play();

        red.display();

                    if(timerred>2){
            red.close();
            }
}
}

#endif // RED_H_INCLUDED
