#pragma once


// PlanetControlDlg 대화 상자

class PlanetControlDlg : public CDialog
{
	DECLARE_DYNAMIC(PlanetControlDlg)

public:
	PlanetControlDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~PlanetControlDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIMUL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_Mer_speed;
	int m_V_speed;
	int m_E_speed;
	int m_Mer_life;
	int m_V_life;
	int m_E_life;
	afx_msg void OnBnClickedButton2();
	int Mer_spin;
	int V_spin;
	int E_spin;
	int m_Mars_speed;
	int m_Mars_life;
	int Mars_spin;
	int m_J_speed;
	int m_J_life;
	int Ju_spin;
	int m_Sa_speed;
	int  m_Sa_life;
	int Sa_spin;
	int m_Ur_speed;
	int m_Ur_life;
	int Ur_spin;
	int m_Ne_speed;
	int m_Ne_life;
	int Ne_spin;
};
