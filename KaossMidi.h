
#ifndef __KAOSS_MIDI__
#define __KAOSS_MIDI__

#include "KaossPad.h"
#include "KaossGate.h"
#include "KaossLoops.h"
#include "KaossProgram.h"
#include "KaossVolume.h"
#include <portmidi.h>

class KaossMIDI {
public:
	KaossMIDI();
	~KaossMIDI();

	bool initialize(int device);
	void cleanup();

	KaossPad * pad() { return mPad; }
	KaossGate * gate() { return mGate; }
	KaossLoops * loop() { return mLoops; }
	KaossVolume * volume() { return mVolume; }
	KaossProgram * program() { return mProgram; }

	bool isInitialized() { return isInit; }
private:
	KaossPad *mPad;
	KaossGate *mGate;
	KaossLoops *mLoops;
	KaossVolume *mVolume;
	KaossProgram *mProgram;

	bool isInit;
	PortMidiStream *messageStream;
};


#endif