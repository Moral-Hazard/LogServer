#include "pch.h"
#include <generated/logs/ServerPacketHandler.gen.hpp>

#include "Manager/Manager.hpp"
#include "Manager/LogHandler.hpp"

using namespace gen;

bool logs::PacketHandler::SystemLogPacketHandler(TSharedPtr<Session> session, TSharedPtr<SystemLog> packet)
{
	Manager::LogHandler()->Launch(&LogHandler::HandleSystemLog, session, packet);
	return false;
}

bool logs::PacketHandler::SecurityLogPacketHandler(TSharedPtr<Session> session, TSharedPtr<SecurityLog> packet)
{
	Manager::LogHandler()->Launch(&LogHandler::HandleSecurityLog, session, packet);
	return false;
}
