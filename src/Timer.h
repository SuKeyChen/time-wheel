#pragma once

#include <cstdint>
#include <functional>

/// ˫����
struct tw_links
{
	tw_links* next;
	tw_links* prev;
};

class TimeWheelMgr;
class Timer {
	tw_links links{};	// ����ָ�������ǰ��
	friend class TimeWheel;
	friend class TimeWheelMgr;

	uint64_t delay;	///< ���ٺ���֮��ִ��
	uint64_t rotation_count = 0;
	using Callback = std::function<void()>;
	Callback callback;

	void prepare();
	bool running()const;
	void stop();

public:
	Timer(uint64_t _delay, Callback && _callback);
	~Timer();

	int16_t repeat = 1;	///< -1��ʾ���޴�
	uint64_t periodic_delay = 0;
};
