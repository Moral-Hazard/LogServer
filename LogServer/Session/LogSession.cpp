#include "pch.h"
#include "LogSession.hpp"
#include "generated/logs/ServerPacketHandler.gen.hpp"

void LogSession::OnConnected(net::Endpoint)
{

}

void LogSession::OnDisconnected(net::Endpoint)
{

}

void LogSession::OnReceive(std::span<char> buffer, int)
{
	gen::logs::PacketHandler::HandlePacket(this, buffer);
}

void LogSession::OnFail(Failure)
{

}