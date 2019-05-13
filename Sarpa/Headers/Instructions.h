#ifndef INSTRUCTIONS_H_INCLUDED
#define INSTRUCTIONS_H_INCLUDED

void Instructions(){
    RenderWindow Ins (VideoMode(w+20,h+20),"Sarpa");

    Texture I;
    I.loadFromFile("Images/Pictures/Instructions.jpg");
    Sprite ITS(I);

    while(Ins.isOpen())
    {

        Event newevent;
        while (Ins.pollEvent(newevent))
        {
            if(newevent.type == Event::Closed)
                Ins.close();
        }
        ITS.setPosition(10,10);
            Ins.draw(ITS);

        Ins.display();
}
}

#endif // INSTRUCTIONS_H_INCLUDED
