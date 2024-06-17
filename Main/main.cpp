#include "pch.h"
#include "Network/Server.hpp"
#include "Session/LogSession.hpp"
#include "LogServer.hpp"

using namespace std;

int main()
{
	auto ep = Endpoint(IpAddress::Loopback, 1225);
	try {
		auto server = Server::Open<LogSession>();	
		server->Run(ep);

		Console::Log(Category::LogServer, TEXT("Log Server is running on ") + ToUnicodeString(ep.toString()));

		GEngine->ExecuteThread(2, 2);

		getchar();
	}
	catch (exception& e) {
		Console::Error(Category::LogServer, ToUnicodeString(e.what()));
	}
}