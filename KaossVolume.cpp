
#include "KaossVolume.h"

KaossVolume::KaossVolume() :
	volume(0), messageStream(NULL)
{}

KaossVolume::~KaossVolume() {
	messageStream = NULL;
}

void KaossVolume::initialize(const PortMidiStream *_messageStream) {
	messageStream = _messageStream;
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
