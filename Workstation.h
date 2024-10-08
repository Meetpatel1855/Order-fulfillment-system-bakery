
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca
{
	extern std::deque<CustomerOrder> g_pending;

	extern std::deque<CustomerOrder> g_completed;

	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation = nullptr;
	public:
		Workstation(const std::string& src) : Station(src) {}; 

		void fill(std::ostream& os);

		bool attemptToMoveOrder();

		void setNextStation(Workstation* station); 

		Workstation* getNextStation() const; 

		void display(std::ostream& os) const; 
		Workstation& operator+=(CustomerOrder&& newOrder); 

		Workstation(const Workstation&) = delete; 
		Workstation(Workstation&&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator=(Workstation&&) = delete;
	};
}

#endif 