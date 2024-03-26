#include "pch.h"
#include "LogHandler.hpp"
#include "Database/DBConnectionPool.hpp"
#include "Database/Statement.hpp"

void LogHandler::HandleSystemLog(std::shared_ptr<class Session> session, gen::logs::SystemLog log)
{
	auto conn = GEngine->GetDBConnectionPool()->Pop();
	if (conn)
	{
		int severity = log.severity;
		auto stmt = conn->CreateStatement<3, 0>(TEXT("CALL SP_SystemLog(?, ?, ?)"));
		stmt.SetParameter(0, severity);
		stmt.SetParameter(1, log.serverName.c_str());
		stmt.SetParameter(2, log.message.c_str());

		bool success = stmt.ExecuteQuery();

		GEngine->GetDBConnectionPool()->Push(conn);
	}
}

void LogHandler::HandleSecurityLog(std::shared_ptr<class Session> session, gen::logs::SecurityLog log)
{
}
