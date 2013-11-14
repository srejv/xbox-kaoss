
#ifndef __KAOSS_LOOPS__
#define __KAOSS_LOOPS__

#include <portmidi.h>
#include "KaossMisc.h"

class KaossLoops
{
public:
	KaossLoops();
	~KaossLoops();

	void initialize(PortMidiStream *_messageStream);
	void cleanup();

	void activate(MidiConstants::Loop loop);
	void deactivate(MidiConstants::Loop loop);
	void toggle(MidiConstants::Loop loop);

private:
	bool isActive[4];
	PortMidiStream *messageStream;

	int loopToId(MidiConstants::Loop loop);
	int loopToNote(MidiConstants::Loop loop);
};

#endif