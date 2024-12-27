#pragma once


// CResultDlg 대화 상자

class CResultDlg : public CDialog
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Result};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int Mer_speed;
	int V_speed;
	int E_speed;
	int Mer_life;
	int V_life;
	int E_life;
	CString Mer_spin;
	CString V_spin;
	CString E_spin;
	int Mars_speed;
	int Mars_life;
	CString Mars_spin;
	int Ju_speed;
	int Ju_life;
	CString Ju_spin;
	int Sa_speed;
	int Sa_life;
	CString Sa_spin;
	int Ur_speed;
	int Ur_life;
	CString Ur_spin;
	int Ne_speed;
	int Ne_life;
	CString Ne_spin;
	CString Moon_flag;

	
	
};
