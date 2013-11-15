/* 
*	Author: Oscar Dragén
*/

#ifndef __KAOSS_MISC__
#define __KAOSS_MISC__

#include <portmidi.h>

class MidiConstants {
public:
	enum MessageType { 
		NoteOff = 0x80,
		NoteOn = 0x90,
		PolyphonicAftertouch = 0xA0,
		ControlChange = 0xB0,
		ProgramChange = 0xC0,
		ChannelAftertouch = 0xD0,
		PitchWheelControl = 0xE0,
		SystemExclusive = 0xF0,
		MidiTimeCodeQtrFrame = 0xF1,
		SongPositionPointer = 0xF2,
		SongSelect = 0xF3,
		TuneRequest = 0xF6,
		EndOfSysEx = 0xF7,
		TimingClock = 0xF8,
		Start = 0xFA,
		Continue = 0xFB,
		Stop = 0xFC,
		ActiveSensing = 0xFE,
		SystemReset = 0xFF
	};

	enum Channel {
		Channel1 = 0x00,
		Channel2 = 0x01,
		Channel3 = 0x02,
		Channel4 = 0x03,
		Channel5 = 0x04,
		Channel6 = 0x05,
		Channel7 = 0x06,
		Channel8 = 0x07,
		Channel9 = 0x08,
		Channel10 = 0x09,
		Channel11 = 0x0A,
		Channel12 = 0x0B,
		Channel13 = 0x0C,
		Channel14 = 0x0D,
		Channel15 = 0x0E,
		Channel16 = 0x0F
	};

	enum Loop {
		LoopA = 36,
		LoopB = 37,
		LoopC = 38,
		LoopD = 39
	};

	enum Kaoss {
		PadVolume = 94,
		GateTime = 93,
		GateSpeed = 91,
		GateArp = 90,
		PadX = 12,
		PadY = 13,
		PadTouch = 92
	};

	uint8_t MessageChannelByte(MidiConstants::MessageType message, MidiConstants::Channel channel) {
		return message | channel;
	}
};



#endif