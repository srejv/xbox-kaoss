
#ifndef __KAOSS_LOOPS__
#define __KAOSS_LOOPS__

#include "KaossMisc.h"

class KaossLoops
{
public:
	KaossLoops();
	~KaossLoops();

	void initialize(const PortMidiStream *_messageStream);

	void activate(uint8_t loop);
	void deactivate(uint8_t loop);
	void toggle(uint8_t loop);

	static const uint8_t LoopA = 36;
	static const uint8_t LoopB = 37;
	static const uint8_t LoopC = 38;
	static const uint8_t LoopD = 39;
private:
	bool isActive[4];
	PortMidiStream *messageStream;

	int loopToId(Loop loop);
	int loopToNote(Loop loop);
};

#endif