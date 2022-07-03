#ifndef _PCA9685_H_
#define _PCA9685_H_

class PCA9685 {
public:
	bool PCA9685Init();
	void ResetPca9685();
	void PCA9685SetPwmFreq(unsigned short freq);
	void PCA9685SetPwm(unsigned char channel, unsigned short on, unsigned short value);
	void PCA9685SetMotorPwm(int channel, int duty);
	void SetServoPulse(unsigned char channel, unsigned short pulse);
	bool WriteByte(int fd, unsigned char regAddr, unsigned char data);

	unsigned char ReadByte(int fd, unsigned char regAddr);
};


#endif
