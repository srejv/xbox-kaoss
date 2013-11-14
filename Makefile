

joystick: joystick.cpp 
	g++ -o joystick joystick.cpp KaossMidi.cpp KaossPad.cpp KaossGate.cpp KaossLoops.cpp KaossVolume.cpp KaossProgram.cpp -lsfml-graphics -lsfml-window -lsfml-system -lportmidi -lporttime

KaossLoops.o: KaossLoops.cpp
	g++ -o KaossLoops.o -c KaossLoops.cpp -lportmidi

KaossPad.o: KaossPad.cpp
	g++ -o KaossPad.o -c KaossPad.cpp -lportmidi
	
KaossGate.o: KaossGate.cpp
	g++ -o KaossGate.o -c KaossGate.cpp -lportmidi

KaossProgram.o: KaossProgram.cpp
	g++ -o KaossProgram.o -c KaossProgram.cpp -lportmidi

KaossVolume.o: KaossVolume.cpp
	g++ -o KaossVolume.o -c KaossVolume.cpp -lportmidi

KaossMidi.o: KaossLoops.o KaossPad.o KaossGate.o KaossProgram.o KaossVolume.o
	g++ -o KaossMidi.o -c KaossMidi.cpp -lKaossLoops -lKaossPad -lKaossGate -lKaossProgram -lKaossVolume -lportmidi


	