#include "pch.h"
#include "LogServer.hpp"

Engine* GEngine;

LogServer::LogServer()
{
	GEngine = new Engine;
}

LogServer::~LogServer()
{
	delete GEngine;
}
