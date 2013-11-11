

joystick: joystick.cpp 
	g++ joystick.cpp -o joystick -lsfml-graphics -lsfml-window -lsfml-system

kaossloops.o: KaossLoops.cpp
	g++ -c KaossLoops.cpp -lportmidi

kaosspad.o: KaossPad.cpp
	g++ -c KaossPad.cpp -lportmidi
	