/* 
*	Author: Oscar Dragén
*/

#include "KaossLoops.h"
#include "KaossMisc.h"

KaossLoops::KaossLoops() {
	isActive[0] = false;
	isActive[1] = false;
	isActive[2] = false;
	isActive[3] = false;
}

KaossLoops::~KaossLoops() {
}

void KaossLoops::initialize(PortMidiStream *_messageStream) {
	messageStream = _messageStream;
}

void KaossLoops::cleanup() {
}

void KaossLoops::activate(MidiConstants::Loop loop) {
	int id = loopToId(loop);
	if(!isActive[id]) {
		toggle(loop);
	}
}

void  KaossLoops::deactivate(MidiConstants::Loop loop) {
	int id = loopToId(loop);
	if(isActive[id]) {
		toggle(loop);
	}
}

void KaossLoops::toggle(MidiConstants::Loop loop) {
	uint32_t msg = Pm_Message(MidiConstants::NoteOn, loopToNote(loop), 127);
	Pm_WriteShort(messageStream, 0, msg);
	int id = loopToId(loop);
	isActive[id] = !isActive[id];
}

int KaossLoops::loopToId(MidiConstants::Loop loop) {
	return loop - MidiConstants::LoopA;
}
 
int KaossLoops::loopToNote(MidiConstants::Loop loop) {
	return loop;
}