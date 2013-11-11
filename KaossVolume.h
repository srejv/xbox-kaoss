
#ifndef __KAOSS_VOLUME__
#define __KAOSS_VOLUME__

#include <portmidi.h>

class KaossVolume {
public:
	KaossVolume();
	~KaossVolume();

	void initialize(const PortMidiStream *_messageStream);

	void setVolume(uint8_t _volume);
	void addToVolume(uint8_t deltaVolume);
private:
	static const uint8_t PadVolume = 94;

	uint8_t volume;
	const PortMidiStream *messageStream;
};

#endif