#pragma once

#define TIME_WHELL_COUNT 1

// ��߾��� 1000 ����
#define TW_RESOLUTION 1000

class Timer;
class TimeWheel;
class TimeWheelMgr {
	friend class TimeWheel;
	TimeWheel* tws[TIME_WHELL_COUNT];
public:
	TimeWheelMgr();
	~TimeWheelMgr();

	/// ���ⲿ����߾���TW_RESOLUTION ����
	void tick();

	void AddTimer(Timer& timer);
	void KillTimer(Timer& timer);
	
};
