#include "pch.h"
#include "CClienwtSocket.h"
#include "TermProject_TCP_ClientDlg.h"
#include "CResult.h"

void CClienwtSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ShutDown();
	Close();
	CSocket::OnClose(nErrorCode);
}


void CClienwtSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CResult dlg;

	CTermProjectTCPClientDlg* pMain = (CTermProjectTCPClientDlg*)AfxGetMainWnd();
	Receive(&pMain->PD, sizeof(pMain->PD));
	dlg.Mer_speed = pMain->PD.Mer_speed;
	dlg.Mer_life = pMain->PD.Mer_life;
	dlg.Mer_spin = pMain->spin2string(pMain->PD.Mer_spin);
	dlg.V_speed = pMain->PD.V_speed;
	dlg.V_life = pMain->PD.V_life;
	dlg.V_spin = pMain->spin2string(pMain->PD.V_spin);
	dlg.E_speed = pMain->PD.E_speed;
	dlg.E_life = pMain->PD.E_life;
	dlg.E_spin = pMain->spin2string(pMain->PD.E_spin);
	dlg.Mars_speed = pMain->PD.Mars_speed;
	dlg.Mars_life = pMain->PD.Mars_life;
	dlg.Mars_spin = pMain->spin2string(pMain->PD.Mars_spin);
	dlg.J_speed = pMain->PD.J_speed;
	dlg.J_life = pMain->PD.J_life;
	dlg.J_spin = pMain->spin2string(pMain->PD.J_spin);
	dlg.Sa_speed = pMain->PD.Sa_speed;
	dlg.Sa_life = pMain->PD.Sa_life;
	dlg.Sa_spin = pMain->spin2string(pMain->PD.Sa_spin);
	dlg.Ur_speed = pMain->PD.Ur_speed;
	dlg.Ur_life = pMain->PD.Ur_life;
	dlg.Ur_spin = pMain->spin2string(pMain->PD.Ur_spin);
	dlg.Ne_speed = pMain->PD.Ne_speed;
	dlg.Ne_life = pMain->PD.Ne_life;
	dlg.Ne_spin = pMain->spin2string(pMain->PD.Ne_spin);
	
	CString str(pMain->PD.Moon_flag);
	dlg.Moon_flag = str;

	dlg.DoModal();

	CSocket::OnReceive(nErrorCode);
}
