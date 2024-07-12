#pragma once
#include "Functor.hpp"
#include <generated/logs/Protocol.gen.hpp>

class LogHandler : public Runnable<LogHandler>
{
public:
	void HandleSystemLog(class Session* session, std::shared_ptr<gen::logs::SystemLog> packet);
	void HandleSecurityLog(class Session* session, std::shared_ptr<gen::logs::SecurityLog> log);
};

