#include "pch.h"
#include "CServerSocket.h"

#include "MainFrm.h"
#include "Term_ProjectDoc.h"
#include "Term_ProjectView.h"

void CServerSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	// TODO: 여기에 구현 코드 추가.
	m_pListenSocket = pSocket;

}


void CServerSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CTermProjectView* view = (CTermProjectView*)pFrame->GetActiveView();

	Receive(&PD2, sizeof(PD2));
	
		view->planets[0]->speed = PD2.Mer_speed;
		if(view->planets[0]->life == PD2.Mer_life)
			view->planets[0]->life = PD2.Mer_life;
		view->planets[0]->spin = PD2.Mer_spin;

		view->planets[1]->speed = PD2.V_speed;
		if (view->planets[1]->life == PD2.V_life)
			view->planets[1]->life = PD2.V_life;
		view->planets[1]->spin = PD2.V_spin;

		view->planets[2]->speed = PD2.E_speed;
		if(view->planets[2]->life == PD2.E_life)
			view->planets[2]->life = PD2.E_life;
		view->planets[2]->spin = PD2.E_spin;

		view->planets[3]->speed = PD2.Mars_speed;
		if(view->planets[3]->life == PD2.Mars_life)
			view->planets[3]->life = PD2.Mars_life;
		view->planets[3]->spin = PD2.Mars_spin;

		view->planets[4]->speed = PD2.J_speed;
		if(view->planets[4]->life == PD2.J_life)
			view->planets[4]->life = PD2.J_life;
		view->planets[4]->spin = PD2.J_spin;

		view->planets[5]->speed = PD2.Sa_speed;
		if(view->planets[5]->life == PD2.Sa_life)
			view->planets[5]->life = PD2.Sa_life;
		view->planets[5]->spin = PD2.Sa_spin;

		view->planets[6]->speed = PD2.Ur_speed;
		if(view->planets[6]->life == PD2.Ur_life)
			view->planets[6]->life = PD2.Ur_life;
		view->planets[6]->spin = PD2.Ur_spin;

		view->planets[7]->speed = PD2.Ne_speed;
		if (view->planets[7]->life== PD2.Ne_life)
			view->planets[7]->life = PD2.Ne_life;
		view->planets[7]->spin = PD2.Ne_spin;

		view->TCP_flag = PD2.TCP_flag;
		view->stop_flag = PD2.stop_simul_flag;
		view->Open_flag = PD2.Open_flag;

		if (PD2.TCP_flag == 0)
		{
			//AfxMessageBox(_T("ss"));
			view->OnStopSimul();
		}
		else if (PD2.TCP_flag == 1)
		{
			//AfxMessageBox(_T("qq"));
			view->OnStartSimul();
		}

		if (PD2.stop_simul_flag==1)
		{
			view->KillTimer(1);
			view->DisplayResult();
		}
		 if (PD2.Open_flag == 1)
		{
			view->OnStartSimul();
		}

	
	CSocket::OnReceive(nErrorCode);
}


void CServerSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
	CSocket::OnClose(nErrorCode);
}
