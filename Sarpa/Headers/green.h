#ifndef GREEN_H_INCLUDED
#define GREEN_H_INCLUDED

void green(){
    RenderWindow green (VideoMode(w,h),"Sarpa");

    SoundBuffer gr;
    gr.loadFromFile("Audios/green.wav");
    Sound greeny;
    greeny.setBuffer(gr);

    Texture background;
    background.loadFromFile("Images/Backgrounds/backgroundg.jpg");
    Sprite bg(background);

    Texture mainpic;
    mainpic.loadFromFile("Images/Pictures/greenmambaa.jpg");
    Sprite mp(mainpic);

    Clock clockgreen;
    float timergreen=0;

    while(green.isOpen())
    {
        float timegreen = clockgreen.getElapsedTime().asSeconds();
        clockgreen.restart();
        timergreen += timegreen ;

        Event newevent;
        while (green.pollEvent(newevent))
        {
            if(newevent.type == Event::Closed)
                green.close();
        }


        bg.setPosition(0,0);
            green.draw(bg);

        mp.setPosition(197,50);
            green.draw(mp);

        greeny.play();

        green.display();

                    if(timergreen>2){
            green.close();
            }
    }
}

#endif // GREEN_H_INCLUDED
