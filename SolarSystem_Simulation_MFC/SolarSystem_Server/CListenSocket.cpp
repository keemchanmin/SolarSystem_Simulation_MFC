#include "pch.h"
#include "CListenSocket.h"
#include "CServerSocket.h"


#include "MainFrm.h"
#include "Term_ProjectDoc.h"
#include "Term_ProjectView.h"

void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
	// TODO: ���⿡ ���� �ڵ� �߰�.
	pChild->ShutDown();
	pChild->Close();
}
