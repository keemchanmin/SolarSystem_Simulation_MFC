
// TermProject_TCP_ClientDlg.h: 헤더 파일
//

#pragma once

#include"CClienwtSocket.h"
#include"CConnectDlg.h"
// CTermProjectTCPClientDlg 대화 상자
class CTermProjectTCPClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CTermProjectTCPClientDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CClienwtSocket m_Socket;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERMPROJECT_TCP_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
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
	 struct Planet {
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
		char Moon_flag[30];
		int stop_simul_flag;
		int Open_flag;
	};
	 struct Planet PD;

	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();

	
	CString spin2string(int spin);
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButtonEnd();
	afx_msg void OnBnClickedButtonFirstStartSimul();
};
