#pragma once
#include <Thread/JobSerializer.hpp>
#include <generated/logs/Protocol.gen.hpp>

class LogHandler : public JobSerializer
{
public:
	void HandleSystemLog(std::shared_ptr<class Session> session, gen::logs::SystemLog log);
	void HandleSecurityLog(std::shared_ptr<class Session> session, gen::logs::SecurityLog log);
};

