
#ifndef __KAOSS_PROGRAM__
#define __KAOSS_PROGRAM__

class KaossProgram {
public:
	KaossProgram();
	~KaossProgram();

	void initialize(const PortMidiStream *_messageStream);

	void setProgram(uint8_t program);
	void nextProgram();
	void previousProgram();
private:
	void uploadState();
	uint8_t programBlock;
	uint8_t activeProgram;

	const PortMidiStream *messageStream;
};

#endif
