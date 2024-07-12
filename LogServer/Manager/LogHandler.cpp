#include "pch.h"
#include "LogHandler.hpp"
#include "Network/Server.hpp"

void LogHandler::HandleSystemLog(class Session* session, std::shared_ptr<gen::logs::SystemLog> log)
{
	auto pstmt = GDatabase->CallProcedure("SP_SystemLog",
		static_cast<uint16>(log->severity),
		ToAnsiString(log->serverName),
		ToAnsiString(log->message)
	);
	pstmt->AsyncUpdate([&](int result) {
		if (result)
			Console::Log(Category::LogServer, std::format(TEXT("({}) {}."), log->serverName, log->message));
	});
}

void LogHandler::HandleSecurityLog(class Session* session, std::shared_ptr<gen::logs::SecurityLog> log)
{
	auto pstmt = GDatabase->CallProcedure("SP_SecuLog",
								static_cast<uint16>(log->loginType),
								ToAnsiString(log->uid),
								ToAnsiString(log->ipAddress)
							);
	pstmt->AsyncUpdate([&](int ret) {
		switch (log->loginType)
		{
		case gen::logs::ELoginType::LOGIN:
			Console::Log(Category::LogServer, std::format(TEXT("'{}' has logined."), log->uid));
			break;
		case gen::logs::ELoginType::LOGOUT:
			Console::Log(Category::LogServer, std::format(TEXT("'{}' has log out."), log->uid));
			break;
		case gen::logs::ELoginType::REGISTER:
			Console::Log(Category::LogServer, std::format(TEXT("'{}' has registered."), log->uid));
			break;
		default:
			break;
		}
	});
}
