#pragma once
#include <chrono>
#include <thread>

class ElapsedTime
{
public:
	ElapsedTime();
	void run();
	void end();

	const float getElapsedTime();
	const float getTimeUsed();
	void setElapsedTime(float time);
	 
private:

	 //std::chrono::steady_clock::time_point timeNow;
	// std::chrono::steady_clock::time_point timeLast;
	std::chrono::steady_clock::time_point t1;
	std::chrono::steady_clock::time_point t2;
	std::chrono::steady_clock::time_point t3;
	std::chrono::duration<double> target;
	std::chrono::duration<double> sleepTime;
	std::chrono::duration<double> frameTime;
	std::chrono::duration<double> sleepAdjust;
	 
	float mElapsedTime;
	float mTimeUsed;




};

