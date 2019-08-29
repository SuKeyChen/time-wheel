#include "Timer.h"
#include "TimeWheel.h"
#include "TimeWheelMgr.h"
#include <cassert>

TimeWheelMgr::TimeWheelMgr() {
	tws[0] = new TimeWheel(*this, 0, "second", 60, Granularity::Second);
}

TimeWheelMgr::~TimeWheelMgr() {
	for (TimeWheel* tw : tws) {
		delete tw;
	}
}

void TimeWheelMgr::tick() {
	
	TimeWheel* tw = tws[0];
	assert(tw);
	tw->tick();
}

// 1��=366��= 366*24*3600*1000 = 31,622,400,000����
void TimeWheelMgr::AddTimer(Timer& timer) {
	TimeWheel* tw = tws[0];
	assert(tw);

	KillTimer(timer);	// ���֮ǰ�����������棬Ҫ��֮ǰ����������

	uint64_t ticks = 1;	// �����ӳٶ��ٸ����ӣ�����һ�񣬲���һ��Ҳ��һ��
	for (size_t i = TIME_WHELL_COUNT - 1; i >= 0; --i)
	{
		tw = tws[i];
		if (!tw)continue;
		if (timer.delay < tw->granularity)
		{
			if (i)
			{
				continue;
			}
		}
		else {
			ticks = timer.delay / tw->granularity;
		}
		tw->AddTimer(timer, ticks);

		break;
	}
}

void TimeWheelMgr::KillTimer(Timer& timer) {
	timer.stop();
}
