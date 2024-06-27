#include "pch.h"
#include "LogServer.hpp"

int main()
{
	LogServerInstance = new LogServer;
	LogServerInstance->Run();

	delete LogServerInstance;
}