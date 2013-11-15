#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>

#include <portmidi.h>
#include <porttime.h>
#include "KaossMidi.h"
#include "xboxcontroldefs.h"

float stick1x = 0.0f;
float stick1y = 0.0f;

float stick2x = 0.0f;
float stick2y = 0.0f;

float stickModifier = 16.0f/25.0f;

KaossMIDI midi;

sf::Joystick::Axis toAxis(XboxController::Analog stick) {
    switch(stick) {
    case XboxController::LeftX:
        return sf::Joystick::X;
    case XboxController::LeftY:
        return sf::Joystick::Y;
    case XboxController::L2:
        return sf::Joystick::Z;
    case XboxController::R2:
        return sf::Joystick::R;
    case XboxController::RightX:
        return sf::Joystick::U;
    case XboxController::RightY:
        return sf::Joystick::V;
    case XboxController::DigitalX:
        return sf::Joystick::PovX;
    case XboxController::DigitalY:
        return sf::Joystick::PovY;
    }
}

void handleJoystickInput() {
    
    stick1x = sf::Joystick::getAxisPosition(0, toAxis(XboxController::LeftX));
    stick1y = sf::Joystick::getAxisPosition(0, toAxis(XboxController::LeftY));
    uint8_t px = int(64 + (stick1x*stickModifier));
    uint8_t py = int(64 - (stick1y*stickModifier));

    if (sf::Joystick::getAxisPosition(0, toAxis(XboxController::L2)) > 0) {
        printf("Button pressed\n");
        midi.pad()->setPosition(px, py);
        midi.pad()->touch(64);
    } 

    stick2x = sf::Joystick::getAxisPosition(0, toAxis(XboxController::RightX));
    stick2y = sf::Joystick::getAxisPosition(0, toAxis(XboxController::RightY));
    // Time
    uint8_t gtime = int(64 + (stick2x*stickModifier));
    // Speed
    uint8_t gspeed = int(64 - (stick2y*stickModifier));

    if (sf::Joystick::getAxisPosition(0, toAxis(XboxController::R2)) > 0) {
        printf("GateSTuff\n");
        midi.gate()->setTime(gtime);
        midi.gate()->setSpeed(gspeed);
        midi.gate()->activate();
    } 

    
}


const float deadzone = 10.0f;

int main()
{
    const PmDeviceInfo *info;
    Pm_Initialize();
    int cnt = Pm_CountDevices();
    if(!cnt) { 
        Pm_Terminate();
        printf("No Devices.\n");
        return -1;
    }

    printf("Output \n");
    for(int i = 0; i < cnt; i++) {
        info = Pm_GetDeviceInfo(i);
        if(info->output)
            printf("%d: %s \n", i, info->name);
    }

    int device = 0;
    printf("choose your device: ");
    scanf("%d", &device);
    
    Pt_Start(1, NULL, NULL);
    bool isinit = midi.initialize(device);
    if(isinit) {
        printf("INITIALIZED KAOSS\n");
    }

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setJoystickThreshold(1);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::JoystickMoved) {
                //printf("joystick: %d. AXIS: %d, val: %f\n", event.joystickMove.joystickId, event.joystickMove.axis, event.joystickMove.position);
            } 

            if (event.type == sf::Event::JoystickButtonPressed) {
                switch(event.joystickButton.button) {
                case XboxController::L1:
                    midi.pad()->release();
                    break;
                case XboxController::R1:
                    midi.gate()->deactivate();
                    break;
                case XboxController::A:
                    midi.loop()->toggle(MidiConstants::LoopA);
                    break;
                case XboxController::B:
                    midi.loop()->toggle(MidiConstants::LoopB);
                    break;
                case XboxController::X:
                    midi.loop()->toggle(MidiConstants::LoopC);
                    break;
                case XboxController::Y:
                    midi.loop()->toggle(MidiConstants::LoopD);
                    break;
                }
            }

            if(event.type == sf::Event::JoystickMoved) {
                if(sf::Joystick::getAxisPosition(0, toAxis(XboxController::DigitalX)) > 0) {
                    midi.program()->nextProgram();
                }

                if(sf::Joystick::getAxisPosition(0, toAxis(XboxController::DigitalX)) < 0) {
                    midi.program()->previousProgram();
                }

                if(sf::Joystick::getAxisPosition(0, toAxis(XboxController::DigitalY)) > 0) {
                    midi.volume()->addToVolume(5);
                }

                if(sf::Joystick::getAxisPosition(0, toAxis(XboxController::DigitalY)) < 0) {
                    midi.volume()->addToVolume(-5);
                }
            }
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