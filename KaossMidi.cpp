/* 
*	Author: Oscar Dragén
*/

#include "KaossMidi.h"
#include "KaossMisc.h"
#include <stdio.h>

KaossMIDI::KaossMIDI() : isInit(false) {
}

KaossMIDI::~KaossMIDI() {
	delete mPad;
	delete mGate;
	delete mLoops;
	delete mVolume;
	delete mProgram;
}

bool KaossMIDI::initialize(int device) {
	// SETUP STREAM
	isInit = false;
	int dev = device;
	PmError retval = Pm_OpenOutput(&messageStream, dev, NULL, 512L, NULL, NULL, 0l );

	if(retval != pmNoError) {
		// Error
		printf("Error in output: %s\n", Pm_GetErrorText(retval));
		Pm_Close(messageStream);
		return false;
	}

	Pm_SetChannelMask(messageStream, Pm_Channel(1));
	isInit = true;

	mPad = new KaossPad();
	mGate = new KaossGate();
	mLoops = new KaossLoops();
	mVolume = new KaossVolume();
	mProgram = new KaossProgram();

	mPad->initialize(messageStream);
	mGate->initialize(messageStream);
	mLoops->initialize(messageStream);
	mVolume->initialize(messageStream);
	mProgram->initialize(messageStream);

	return true;
}

void KaossMIDI::cleanup() {
	Pm_Close(messageStream);
}
