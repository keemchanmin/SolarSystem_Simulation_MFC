#pragma once
#include <afxsock.h>
#include"CListenSocket.h"


class CServerSocket :public CSocket
{



public:
	CServerSocket() :m_pListenSocket(nullptr) { }
	CAsyncSocket* m_pListenSocket;
	void SetListenSocket(CAsyncSocket* pSocket);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);

	typedef struct Planet {
		int Mer_speed;
		int Mer_life;
		int Mer_spin;
		int V_speed;
		int V_life;
		int V_spin;
		int E_speed;
		int E_life;
		int E_spin;
		int Mars_speed;
		int Mars_life;
		int Mars_spin;
		int J_speed;
		int J_life;
		int J_spin;
		int Sa_speed;
		int Sa_life;
		int Sa_spin;
		int Ur_speed;
		int Ur_life;
		int Ur_spin;
		int Ne_speed;
		int Ne_life;
		int Ne_spin;
		int TCP_flag;
		char MoonFlag[30];
		int stop_simul_flag;
		int Open_flag;
	}planetdata;

	planetdata PD2;
};



