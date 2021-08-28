#include "ElapsedTime.h"

ElapsedTime::ElapsedTime()
	:frameTime(0.0)
	,sleepAdjust(0.0)
	,target(1.0/60.0)
	,t1(std::chrono::steady_clock::now())
	

{
	/*elapsedTime = 0;
	timeNow = std::chrono::steady_clock::now();
	timeLast = std::chrono::steady_clock::now();*/
	

}

void ElapsedTime::run()
{
	//timeNow = std::chrono::steady_clock::now();
	//elapsedTime = std::chrono::duration<float>(timeNow - timeLast).count();
	//timeLast = std::chrono::steady_clock::now();

	t2 = std::chrono::steady_clock::now();

	std::chrono::duration<double> timeUsed = t2 - t1;
	mTimeUsed = std::chrono::duration<float>(timeUsed).count();
	sleepTime = target - timeUsed + sleepAdjust;

	if (sleepTime > std::chrono::duration<double>(0))
	{
		std::this_thread::sleep_for(sleepTime);
	}

	t3 = std::chrono::steady_clock::now();
	frameTime = t3 - t1;
	mElapsedTime = std::chrono::duration<float>(frameTime).count();
	sleepAdjust = 0.9 * sleepAdjust + 0.1 * (target - frameTime);
	///////////////////
	t1 = std::chrono::steady_clock::now();

}

void ElapsedTime::end()
{

	t2 = std::chrono::steady_clock::now();

	std::chrono::duration<double> timeUsed = t2 - t1;
	mTimeUsed = std::chrono::duration<float>(timeUsed).count();
	sleepTime = target - timeUsed + sleepAdjust;

	if (sleepTime > std::chrono::duration<double>(0))
	{
		std::this_thread::sleep_for(sleepTime);
	}

	t3 = std::chrono::steady_clock::now();
	frameTime = t3 - t1;
	mElapsedTime = std::chrono::duration<float>(frameTime).count();
	sleepAdjust = 0.9 * sleepAdjust + 0.1 * (target - frameTime);

	//t1 = std::chrono::steady_clock::now();
}

const float ElapsedTime::getElapsedTime()
{
	return mElapsedTime;
}

const float ElapsedTime::getTimeUsed()
{
	return mTimeUsed;
}

void ElapsedTime::setElapsedTime(float time)
{
	//elapsedTime = time;
}
