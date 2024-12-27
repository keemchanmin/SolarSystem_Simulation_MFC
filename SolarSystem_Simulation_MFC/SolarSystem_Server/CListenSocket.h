#pragma once
#include <afxsock.h>
#include"CServerSocket.h"
class CListenSocket :public CAsyncSocket
{
public:
	CListenSocket() {}
	virtual void OnAccept(int nErrorCode);
	void CloseClientSocket(CSocket* pChild);
};

