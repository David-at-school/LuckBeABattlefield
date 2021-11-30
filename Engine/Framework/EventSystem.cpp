#include "EventSystem.h"

namespace luck
{
	void EventSystem::Startup()
	{

	}

	void EventSystem::Shutdown()
	{

	}

	void EventSystem::Update(float dt)
	{

	}

	void EventSystem::Subscribe(const std::string& name, function_t function, Object* receiver)
	{
		Observer observer;
		observer.function = function;
		observer.receiver = receiver;
		observers[name].push_back(observer);
	}

	void EventSystem::Unsubscribe(const std::string& name, Object* receiver)
	{
		auto& eventObservers = observers[name];
		for (auto iter = eventObservers.begin(); iter != eventObservers.end();)
		{
			if (iter->receiver == receiver)
			{
				iter = eventObservers.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	void EventSystem::Notify(const Event& e)
	{
		auto& eventObservers = observers[e.name];
		for (auto& observer : eventObservers)
		{
			if (e.receiver == nullptr || e.receiver == observer.receiver)
			{
				observer.function(e);
			}
		}
	}
}