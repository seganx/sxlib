#include <windows.h>
#include "Timer.h"

Timer::Timer(void): m_time(0), m_elpsTime(0), m_elpsTime_smoothed(0), m_speed(1), m_speedFactor(1), m_lastTime(1e30f) 
{ 
	update();
}

void Timer::update(void)
{
	double tickCount = get_curr_time() * 0.000001;
	double elpsTime = (tickCount - m_lastTime) * m_speed * m_speedFactor;
	m_lastTime = tickCount;
	if (elpsTime > 0)
	{
		m_time += elpsTime;
		m_elpsTime = elpsTime;
		m_elpsTime_smoothed += (elpsTime - m_elpsTime_smoothed) * 0.1f;		
	}
}

uint64 Timer::get_curr_time( void )
{
	return sx_time_counter();
}

uint64 sx_time_counter(void)
{
#if _WIN32 || _WIN64
	static LARGE_INTEGER ferquency;
	static LARGE_INTEGER counter;
	static BOOL useHighPerformance = QueryPerformanceFrequency(&ferquency);
	if (useHighPerformance && QueryPerformanceCounter(&counter))
		return (1000000 * counter.QuadPart) / ferquency.QuadPart;
	else
		return 0;
#endif
}

SEGAN_LIB_API uint sx_time_milliseconds(void)
{
	uint64 t = sx_time_counter() / 1000;
	return (uint)t;
}

SEGAN_LIB_API uint sx_time_seconds(void)
{
	return sx_time_milliseconds() / 1000;
}
