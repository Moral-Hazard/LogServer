#include "pch.h"
#include "LogSession.hpp"
#include "LogHandler.hpp"
#include "generated/logs/ServerPacketHandler.gen.hpp"

void LogSession::OnConnected(net::Endpoint endpoint)
{
	GLogHandler->Launch([endpoint] { Console::Log(LogIO, Debug, action::ToUnicodeString(endpoint.toString())); });
}

void LogSession::OnDisconnected(net::Endpoint)
{

}

void LogSession::OnReceive(std::span<char> buffer, int)
{
	gen::logs::PacketHandler::handlePacket(shared_from_this(), buffer);
}

void LogSession::OnFail(Failure)
{

}