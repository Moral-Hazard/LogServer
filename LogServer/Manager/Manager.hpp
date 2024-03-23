#pragma once
class Manager
{
public:
	Manager();
	~Manager();
public:
	__forceinline static std::shared_ptr<class LogHandler> LogHandler() { return Get().m_logHandler; };
private:
	static Manager Get();
private:
	std::shared_ptr<class LogHandler> m_logHandler;
};