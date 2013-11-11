
#ifndef __KAOSS_PROGRAM__
#define __KAOSS_PROGRAM__

class KaossProgram {
public:
	KaossProgram(const PortMidiStream *_messageStream);
	~KaossProgram();

	void setProgram(uint8_t program);
	void nextProgram();
	void previousProgram();
private:
	void uploadState();
	uint8_t programBlock;
	uint8_t activeProgram;

	const PortMidiStream *messageStream;
};

KaossProgram::KaossProgram(const PortMidiStream *_messageStream) 
	: programBlock(0), activeProgram(0), messageStream(_messageStream)
{}

KaossProgram::~KaossProgram() {
	messageStream = NULL;
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

#endif