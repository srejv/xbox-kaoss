

#ifndef _XBOX_CONTROLLER_
#define _XBOX_CONTROLLER_

class XboxController {
public:
	enum Analog {
		LeftX = 0,
		LeftY = 1,
		L2 = 2,
		R2 = 3,
		RightX = 4,
		RightY = 5,
		DigitalX = 6,
		DigitalY = 7
	};

	enum Buttons {
		A = 0,
		B = 1,
		X = 2,
		Y = 3,
		L1 = 4,
		R1 = 5,
		Start = 7,
		Back = 6,
		Home = 8,
		L3 = 9,
		R3 = 10,
	};
};

#endif 