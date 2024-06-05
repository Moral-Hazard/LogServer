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
	uint16 id = *reinterpret_cast<uint16*>(buffer.data());
	gen::logs::PacketHandler::HandlePacket(shared_from_this(), id, buffer);
}

void LogSession::OnFail(Failure)
{

}