#pragma once


// CResult 대화 상자

class CResult : public CDialog
{
	DECLARE_DYNAMIC(CResult)

public:
	CResult(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CResult();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int Mer_speed;
	int Mer_life;
	CString Mer_spin;
	int V_speed;
	int V_life;
	CString V_spin;
	int E_speed;
	int E_life;
	CString E_spin;
	int Mars_speed;
	int Mars_life;
	CString Mars_spin;
	int J_speed;
	int J_life;
	CString J_spin;
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
