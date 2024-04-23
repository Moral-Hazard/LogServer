#pragma once
#include <Thread/JobSerializer.hpp>
#include <generated/logs/Protocol.gen.hpp>

class LogHandler : public JobSerializer
{
public:
	void HandleSystemLog(std::shared_ptr<class Session> session, std::shared_ptr<gen::logs::SystemLog> log);
	void HandleSecurityLog(std::shared_ptr<class Session> session, std::shared_ptr<gen::logs::SecurityLog> log);
};

