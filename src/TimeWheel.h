#pragma once
#include <string>

enum Granularity : uint64_t
{
	MS		= 1,
	Second	= 1000,
	Minute	= 60 * Second,
};

struct tw_links;
class TimeWheelMgr;
class TimeWheel {
	std::string		name;
	uint16_t		wheel_size;		// ʱ�����ж��ٸ�
	uint16_t		spoke_index = 0;	// ��ǰִ�е�����	
	Granularity		granularity;	// ���ȣ���λ����, һ��tick�ĺ�����
	TimeWheelMgr&	mgr;
	uint16_t		index;	// ��TimeWheelMgr�е�����
	friend class TimeWheelMgr;	

	tw_links* spokes;
	void tick();
	/// @param ticks �Ž��ӳٶ��ٸ��ӵ�����
	void AddTimer(Timer& timer, uint64_t ticks);
public:
	TimeWheel(TimeWheelMgr& _mgr, uint16_t _index, std::string _name, uint16_t _wheel_size, Granularity _granularity);
};
