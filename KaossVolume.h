
#ifndef __KAOSS_VOLUME__
#define __KAOSS_VOLUME__

#include <portmidi.h>

class KaossVolume {
public:
	KaossVolume();
	~KaossVolume();

	void initialize(PortMidiStream *_messageStream);

	void setVolume(uint8_t _volume);
	void addToVolume(uint8_t deltaVolume);
private:
	uint8_t volume;
	PortMidiStream *messageStream;
};

#endif