#pragma once

MAKE_LOG_CATEGORY(LogServer);
struct LogServer final
{
	LogServer();
	~LogServer();
};

static LogServer LogServerInstance;