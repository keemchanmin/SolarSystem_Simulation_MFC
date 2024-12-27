
// Term_ProjectView.h: CTermProjectView 클래스의 인터페이스
//

#pragma once
#include "PlanetControlDlg.h"
#include "Planet.h"
#include "PlanetList.h"
#include "CResultDlg.h"
#include "Satellite.h"
#include "CListenSocket.h"
#include "CServerSocket.h"
class CTermProjectView : public CView
{
protected: // serialization에서만 만들어집니다.
	CTermProjectView() noexcept;
	DECLARE_DYNCREATE(CTermProjectView)

// 특성입니다.
public:
	CTermProjectDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTermProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	PlanetList list;
	Planet* planets[9];
	Planet* ResultPlaent[9];
	int cnt;
	int stop_flag;
	CString resultText;
	CRect rect;

	afx_msg void OnCreateMars();
	afx_msg void OnCreateJupiter();
	afx_msg void OnCreateSaturn();
	afx_msg void OnCreateUranus();
	afx_msg void OnCreateNeptun();
	afx_msg void OnDeleteMars();
	afx_msg void OnDeleteJupiter();
	afx_msg void OnDeleteSaturn();
	afx_msg void OnDeleteUranus();
	afx_msg void OnDeleteNeptun();
	afx_msg void OnCreateAllPlanet();
	afx_msg void OnCreateMoon();
	afx_msg void OnDeleteMercury();
	afx_msg void OnDeleteVenus();
	afx_msg void OnDeleteEarth();
	afx_msg void OnCreateMercury();
	afx_msg void OnCreateVenus();
	afx_msg void OnCreateEarth();
	afx_msg void OnServerOpen();
	afx_msg void OnShowPlanetDlg();
	virtual void OnInitialUpdate();
	afx_msg void OnStartSimul();
	afx_msg void OnStopSimul();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void CreatePlanet(Planet* planet, CDC* pDC, int i);
	void load(CDC* pDC, Planet* planet, int length, int flag);
	void BylifeDeletePlanet(Planet* planet);
	void DisplayResult();


	CListenSocket* m_pListenSocket;
	CServerSocket* m_pServerSocket;
	int TCP_flag;
	int Open_flag;
	int stop_simul_flag;
	int check_flag;
	 struct Planetstruct {
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

	 struct Planetstruct PD_view;
	 afx_msg void OnFirstSimulStart();
};

#ifndef _DEBUG  // Term_ProjectView.cpp의 디버그 버전
inline CTermProjectDoc* CTermProjectView::GetDocument() const
   { return reinterpret_cast<CTermProjectDoc*>(m_pDocument); }
#endif

