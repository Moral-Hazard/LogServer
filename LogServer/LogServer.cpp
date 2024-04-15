#include "pch.h"
#include "LogServer.hpp"
#include "Database/DBConnectionPool.hpp"

Engine* GEngine;

LogServer::LogServer()
{
	GEngine = new Engine;
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
}

LogServer::~LogServer()
{
	delete GEngine;
}
