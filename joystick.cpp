#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>

#include <portmidi.h>
#include <porttime.h>
#include "KaossMidi.h"


float stick1x = 0.0f;
float stick1y = 0.0f;

float stick2x = 0.0f;
float stick2y = 0.0f;
KaossMIDI midi;

void handleJoystickInput() {
    
    stick1x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    stick1y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    //printf("Pos: (%f, %f)\n", stick1x, stick1y);
    uint8_t x = abs(int(stick1x));
    uint8_t y = abs(int(stick1y));

    if (sf::Joystick::isButtonPressed(0, 1)) {
        printf("BUtton pressed\n");
        midi.pad()->setPosition(x,y);
        midi.pad()->touch(64);
    } else {
        midi.pad()->release();
    }
}


const float deadzone = 10.0f;

int main()
{
    Pm_Initialize();
    /*int cnt = Pm_CountDevices();
    if(!cnt) { 
        Pm_Terminate();
        printf("No Devices.\n");
        return -1;
    }

    printf("Choose Output: ")
    for(i=0;i < cnt; i++) {
        info = Pm_GetDeviceInfo(i);
        if(info->output)
            printf("%d: %s \n", i, info->name);
    }*/
    int device = 2;
    Pt_Start(1, NULL, NULL);
    bool isinit = midi.initialize(device);
    if(isinit) {
        printf("INITIALIZED KAOSS\n");
    }

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (sf::Joystick::isConnected(0))
        {
            
            handleJoystickInput();

        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    midi.cleanup();
    Pm_Terminate();

    return 0;
}