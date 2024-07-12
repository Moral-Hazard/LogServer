#pragma once
#include "Subsystem/GameInstance.hpp"

MAKE_LOG_CATEGORY(LogServer);
struct LogServer final : public GameInstance
{
	LogServer();
	~LogServer();

	void Run() override;
};

static LogServer* LogServerInstance;