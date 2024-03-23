#include "pch.h"
#include "Manager.hpp"

#include "LogHandler.hpp"

Manager::Manager()
{
	m_logHandler = std::make_shared<::LogHandler>();
}

Manager::~Manager()
{
	m_logHandler = nullptr;
}

Manager Manager::Get()
{
	static Manager instance;
	return instance;
}
