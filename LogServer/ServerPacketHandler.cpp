#include "pch.h"
#include <generated/logs/ServerPacketHandler.gen.hpp>

#include "Manager/Manager.hpp"
#include "Manager/LogHandler.hpp"

using namespace gen;

bool logs::PacketHandler::SystemLogPacketHandler(Session* session, TSharedPtr<SystemLog> packet)
{
	Manager::LogHandler()->Run(&LogHandler::HandleSystemLog, session, packet);
	return false;
}

bool logs::PacketHandler::SecurityLogPacketHandler(Session* session, TSharedPtr<SecurityLog> packet)
{
	Manager::LogHandler()->Run(&LogHandler::HandleSecurityLog, session, packet);
	return false;
}
