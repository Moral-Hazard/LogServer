#include "pch.h"
#include "Network/Server.hpp"
#include "LogSession.hpp"
#include "LogServer.hpp"

using namespace std;

int main()
{
	auto ep = Endpoint(IpAddress::Loopback, 1225);
	try {
		auto server = Server::Open<LogSession>();

		Console::Log(LogLogServer, Log, TEXT("Log Server is running on ") + action::ToUnicodeString(ep.toString()));
		
		server->Run(ep);
		GEngine->ExecuteIocpLogic(thread::hardware_concurrency(), true);
	}
	catch (exception& e) {
		Console::Log(LogLogServer, Error, action::ToUnicodeString(e.what()));
	}
}