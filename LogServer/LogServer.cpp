#include "pch.h"
#include "LogServer.hpp"
#include "Database/DBConnectionPool.hpp"
#include "Network/Server.hpp"
#include "Session/LogSession.hpp"

Engine* GEngine;

LogServer::LogServer()
{
	GEngine = new Engine;
}

LogServer::~LogServer()
{
	delete GEngine;
}

void LogServer::Run()
{
	GEngine->Initialize();

	GEngine->GetDBConnectionPool()->Connect(10, TEXT(
		"DRIVER={MySQL ODBC 8.3 Unicode Driver};"
		"SERVER=localhost;"
		"PORT=3306;"
		"DATABASE=LogDB;"
		"USER=LogAdmin;"
		"PASSWORD=rHrmeLql$12;"
		"OPTION=3;"
	));

	auto ep = Endpoint(IpAddress::Loopback, 1225);
	try {
		auto server = Server::Open<LogSession>();
		server->Run(ep);

		Console::Log(Category::LogServer, TEXT("Log Server is running on ") + ToUnicodeString(ep.toString()));

		GEngine->ExecuteThread(2, 2);
	}
	catch (std::exception& e) {
		Console::Error(Category::LogServer, ToUnicodeString(e.what()));
	}
}
