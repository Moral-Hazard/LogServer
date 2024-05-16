#pragma once

#include <Network/Session.hpp>

class LogSession : public Session
{
public:
    virtual void OnConnected(net::Endpoint);
    virtual void OnDisconnected(net::Endpoint);
    virtual void OnReceive(std::span<char>, int);
    virtual void OnFail(Failure);
    
    String serverName;
};

