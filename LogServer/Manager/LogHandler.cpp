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
		if (success)
		{
			Console::Log(Category::LogServer, Info, std::format(TEXT("({}) {}."), log.serverName, log.message));
		}

		GEngine->GetDBConnectionPool()->Push(conn);
	}
}

void LogHandler::HandleSecurityLog(std::shared_ptr<class Session> session, gen::logs::SecurityLog log)
{
	auto conn = GEngine->GetDBConnectionPool()->Pop();
	if (conn)
	{
		int loginType = log.loginType;
		auto stmt = conn->CreateStatement<3, 0>(TEXT("CALL SP_SecuLog(?, ?, ?)"));
		stmt.SetParameter(0, loginType);
		stmt.SetParameter(1, log.uid.c_str());
		stmt.SetParameter(2, log.ipAddress.c_str());
		
		bool success = stmt.ExecuteQuery();
		if (success)
		{
			switch (log.loginType)
			{
			case gen::logs::ELoginType::LOGIN:
				Console::Log(Category::LogServer, Info, std::format(TEXT("'{}' has logined."), log.uid));
				break;
			case gen::logs::ELoginType::LOGOUT:
				Console::Log(Category::LogServer, Info, std::format(TEXT("'{}' has log out."), log.uid));
				break;
			case gen::logs::ELoginType::REGISTER:
				Console::Log(Category::LogServer, Info, std::format(TEXT("'{}' has registered."), log.uid));
				break;
			default:
				break;
			}
		}
		GEngine->GetDBConnectionPool()->Push(conn);
	}
}
