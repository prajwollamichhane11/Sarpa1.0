#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <SFML/Audio.hpp>
using namespace std ;
using namespace sf ;
int N = 50 , M = 40 ;
int size = 16 ;
int w = size*N ;
int h = size*M ;
int i ;
int p,q,r,g ;
int dir1 , dir2 ;
int num1 = 4 ;
int num2 = 4 ;
int countr;
int countg;
int gameover;
#include "Headers/snakefood.h"
#include "Headers/movement.h"
#include "Headers/red.h"
#include "Headers/green.h"
#include "Headers/prey.h"
void clear()
{
    num1=4;
    num2=4;
    int j;
    for(j=0;j<4;j++)
    {
        snake1[j].x=0;
        snake1[j].y=0;
        snake2[j].x=0;
        snake2[j].y=0;
        p=0;
        q=0;
        g=0;
        r=0;
    }
}
#include "Headers/AfterGUI.h"
#include "Headers/AfterGUIred.h"
#include "Headers/AfterGUIgreen.h"
#include "Headers/Instructions.h"
int main(){
    RenderWindow GUI (VideoMode(w,h),"Sarpa");

    Music music;
    if (!music.openFromFile("Audios/snakeback.wav"))
        {
            cout << "Error...";
        }
    else{
            music.setLoop(true);
            music.setVolume(15);
            music.play();
        }

    Texture background;
    background.loadFromFile("Images/Backgrounds/background.jpg");
    Sprite bg(background);

    Texture newgame;
    newgame.loadFromFile("Images/Pictures/newgame.jpg");
    Sprite ng(newgame);

    Texture quit;
    quit.loadFromFile("Images/Pictures/qt.jpg");
    Sprite qt(quit);

    Texture mainpic;
    mainpic.loadFromFile("Images/Pictures/mainpic.jpg");
    Sprite mp(mainpic);

    Texture hp;
    hp.loadFromFile("Images/Pictures/Help.jpg");
    Sprite help(hp);

    while(GUI.isOpen())
    {

        Event newevent;
        while (GUI.pollEvent(newevent))
        {
            if(newevent.type == Event::Closed)
                GUI.close();
        }

        bg.setPosition(0,0);
            GUI.draw(bg);

        mp.setPosition(237,55);
            GUI.draw(mp);

        ng.setPosition(320,420);
            GUI.draw(ng);

        qt.setPosition(397,475);
            GUI.draw(qt);

        help.setPosition(344,475);
            GUI.draw(help);

        Vector2f(Mouse::getPosition(GUI));
        {
        if (ng.getGlobalBounds().contains(newevent.mouseButton.x, newevent.mouseButton.y) == true)
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                if(rand()%2 == 0)
                    {
                    newwindowred();
                    clear();
                    newwindowgreen();
                    clear();
                    newwindow();
                    clear();
                    }
                else
                    {
                    newwindowgreen();
                    clear();
                    newwindowred();
                    clear();
                    newwindow();
                    clear();
                    }

            }
        }
        if (qt.getGlobalBounds().contains(newevent.mouseButton.x, newevent.mouseButton.y) == true)
        {
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                GUI.close();
            }
        }

        if (help.getGlobalBounds().contains(newevent.mouseButton.x, newevent.mouseButton.y) == true)
        {
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                Instructions();
            }
        }

    if(countg>1 && gameover==1)
    {
        green();
        clear();
        gameover=0;
        countg=0;
        countr=0;
    }
    else if(countr>2 && gameover==1)
    {
        red();
        clear();
        gameover=0;
        countg=0;
        countr=0;
    }
    else
    {}

        GUI.display();
    }
  return 0;
}
