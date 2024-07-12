#include "pch.h"
#include "LogServer.hpp"
#include "Network/Server.hpp"
#include "Session/LogSession.hpp"

Engine* GEngine;
Database* GDatabase;

LogServer::LogServer()
{
	GEngine = new Engine;
	GDatabase = new Database;
}

LogServer::~LogServer()
{
	delete GEngine;
	delete GDatabase;
}

void LogServer::Run()
{
	GEngine->Initialize();
	GDatabase->Initialize();

	GDatabase->SetDatabaseProfile(TEXT("LogAdmin"), TEXT("rHrmeLql$12"), TEXT("LogDB"));
	GDatabase->CreateConnection();

	auto ep = Endpoint(IpAddress::Loopback, 1225);
	try {
		auto server = Server::Open<LogSession>();
		server->Run(ep);

		Console::Log(Category::LogServer, TEXT("Log Server is running on ") + ToUnicodeString(ep.toString()));

		GEngine->Run(2);
	}
	catch (std::exception& e) {
		Console::Error(Category::LogServer, ToUnicodeString(e.what()));
	}
}
