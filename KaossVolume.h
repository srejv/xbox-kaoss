
#ifndef __KAOSS_VOLUME__
#define __KAOSS_VOLUME__

#include <portmidi.h>

class KaossVolume {
public:
	KaossVolume(const PortMidiStream *messageStream);
	~KaossVolume();

	void setVolume(uint8_t _volume);
	void addToVolume(uint8_t deltaVolume);
private:
	static const uint8_t PadVolume = 94;

	uint8_t volume;
	const PortMidiStream *messageStream;
};

KaossVolume::KaossVolume(const PortMidiStream *_messageStream) :
	volume(0), messageStream(_messageStream)
{}

KaossVolume::~KaossVolume() {
	messageStream = NULL;
}

void KaossVolume::setVolume(uint8_t _volume) {
	volume = _volume;
	uint32_t msg = Pm_Message(ControlChange, KaossVolume::PadVolume, volume);
}

void KaossVolume::addToVolume(uint8_t deltaVolume) {
	volume += deltaVolume;
	uint32_t msg = Pm_Message(ControlChange, KaossVolume::PadVolume, volume);
	Pm_WriteShort(messageStream, 0, msg);
}


#endif