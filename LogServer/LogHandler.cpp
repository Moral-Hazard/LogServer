#include "pch.h"
#include "LogHandler.hpp"

void LogHandler::HandleSystemLog(gen::logs::SystemLog log)
{
	Console::Log(LogLogServer, Debug, log.serverName);
}
