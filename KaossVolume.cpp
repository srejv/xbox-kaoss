
#include "KaossVolume.h"
#include "KaossMisc.h"


KaossVolume::KaossVolume() :
	volume(0)
{}

KaossVolume::~KaossVolume() {
}

void KaossVolume::initialize(PortMidiStream *_messageStream) {
	messageStream = _messageStream;
}

void KaossVolume::setVolume(uint8_t _volume) {
	volume = _volume;
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::PadVolume, volume);
}

void KaossVolume::addToVolume(uint8_t deltaVolume) {
	volume += deltaVolume;
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::PadVolume, volume);
	Pm_WriteShort(messageStream, 0, msg);
}
