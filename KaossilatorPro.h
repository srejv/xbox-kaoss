/*
* Author: Oscar Dragén
* Date: 2013-11-11
*/

#ifndef __KAOSSILATOR_PRO__
#define __KAOSSILATOR_PRO__

#include <portmidi.h>

class KaossilatorHandle
{
	KaossilatorPro();
	~KaossilatorPro();

	bool initialize(int _device);
	bool isInitialized() { return isInitialized; }

	void cleanup();

	void sendMessage(uint32_t message);
private:
	int device;
	PortMidiStream *messageStream;
	bool isInitialized;
};

KaossilatorPro::KaossilatorPro() :
	device(0), mstream(NULL), isInitialized(false)
	{}

KaossilatorPro::~KaossilatorPro() {
}

bool KaossilatorPro::initialize(int _device) {
	isInitialized = false;
	device = _device;
	PmError retval = Pm_OpenOutput(&messageStream, &device, NULL, 512L, NULL, NULL, 0l );

	if(retval != pmNoError) {
		// Error
		printf("Error in output: %s\n", Pm_GetErrorText(retval));
		Pm_Close(messageStream);
		return false;
	}

	Pm_SetChannelMask(mstream[OUTPUT], Pm_Channel(1));
	isInitialized = true;

	
	return true;
}

void KaossilatorPro::cleanup() {
	Pm_Close(messageStream);
}

void KaossilatorHandle::sendMessage(uint32_t message) {
	Pm_WriteShort(messageStream, 0, message);
}

#endif

	pad.initialize(messageStream);
	loop.initialize(messageStream);
	volume.initialize(messageStream);
	program.initialize(messageStream);
	gate.initialize(messageStream);

	KaossPad pad;
	KaossLoops loop;
	KaossVolume volume;
	KaossProgram program;
	KaossGate gate;