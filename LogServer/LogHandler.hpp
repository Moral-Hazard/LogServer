#pragma once
#include <Thread/JobSerializer.hpp>
#include <generated/logs/Protocol.gen.hpp>

class LogHandler : public JobSerializer
{
public:
	void HandleSystemLog(gen::logs::SystemLog log);
};

static std::shared_ptr<LogHandler> GLogHandler = std::make_shared<LogHandler>();


