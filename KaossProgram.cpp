
#include "KaossProgram.h"
#include "KaossMisc.h"


KaossProgram::KaossProgram() 
	: programBlock(1), activeProgram(0)
{}

KaossProgram::~KaossProgram() {
}

void KaossProgram::initialize(PortMidiStream *_messageStream) {
	messageStream = _messageStream;
}

void KaossProgram::setProgram(uint8_t program) {
	activeProgram = program;
	uploadState();
}

void KaossProgram::nextProgram() {
	activeProgram++;
	if(activeProgram > 126) {
		activeProgram = 0;
	}
	uploadState();
}

void KaossProgram::previousProgram() {
	if(activeProgram == 0) {
		activeProgram = 127;
	} else {
		activeProgram--;
	}
	uploadState();
}

void KaossProgram::uploadState() {
	int type = (int)(MidiConstants::ProgramChange);
	uint32_t msg = Pm_Message(type, activeProgram, programBlock);
	Pm_WriteShort(messageStream, 0, msg);
}
