#pragma once
#include <afxsock.h>

class CClienwtSocket : public CSocket
{



public:
    virtual void OnClose(int nErrorCode);
    virtual void OnReceive(int nErrorCode);
};

