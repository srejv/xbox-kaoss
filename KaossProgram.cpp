
#include "KaossProgram.h"

KaossProgram::KaossProgram() 
	: programBlock(0), activeProgram(0), messageStream(NULL)
{}

KaossProgram::~KaossProgram() {
	messageStream = NULL;
}

void KaossProgram::initialize(const PortMidiStream *_messageStream) {
	messageStream = _messageStream;
}

void KaossProgram::setProgram(uint8_t program) {
	activeProgram = program;
	uploadState();
}

void KaossProgram::nextProgram() {
	activeProgram++;
	uploadState();
}

void KaossProgram::previousProgram() {
	activeProgram--;
	uploadState();
}

void KaossProgram::uploadState() {
	uint32_t msg = Pm_Message(ProgramChange, activeProgram, programBlock);
	Pm_WriteShort(messageStream, 0, msg);
}
