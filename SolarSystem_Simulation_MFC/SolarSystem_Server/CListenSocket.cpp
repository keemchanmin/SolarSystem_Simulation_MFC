#include "pch.h"
#include "CListenSocket.h"
#include "CServerSocket.h"


#include "MainFrm.h"
#include "Term_ProjectDoc.h"
#include "Term_ProjectView.h"

void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CServerSocket* pChild = new CServerSocket;
	BOOL check = Accept(*pChild);

	if (check == FALSE) {
		delete pChild;
		AfxMessageBox(_T("Connect Fail"));
		return;
	}
	else
	{
		AfxMessageBox(_T("Connect !!"));
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CTermProjectView* view = (CTermProjectView*)pFrame->GetActiveView();
		view->m_pServerSocket = pChild;
		view->check_flag = 1;
		pChild->SetListenSocket(this);
	}
	CAsyncSocket::OnAccept(nErrorCode);
}


void CListenSocket::CloseClientSocket(CSocket* pChild)
{
	// TODO: 여기에 구현 코드 추가.
	pChild->ShutDown();
	pChild->Close();
}
