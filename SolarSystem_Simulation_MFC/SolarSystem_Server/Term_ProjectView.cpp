
// Term_ProjectView.cpp: CTermProjectView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Term_Project.h"
#endif

#include "Term_ProjectDoc.h"
#include "Term_ProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define PI 3.1415926535
// CTermProjectView

IMPLEMENT_DYNCREATE(CTermProjectView, CView)

BEGIN_MESSAGE_MAP(CTermProjectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CTermProjectView::OnShowPlanetDlg)
	ON_WM_TIMER()
	ON_COMMAND(ID_32772, &CTermProjectView::OnStartSimul)
	ON_COMMAND(ID_32773, &CTermProjectView::OnStopSimul)
	ON_COMMAND(ID_32799, &CTermProjectView::OnCreateMars)
	ON_COMMAND(ID_32801, &CTermProjectView::OnCreateJupiter)
	ON_COMMAND(ID_32803, &CTermProjectView::OnCreateSaturn)
	ON_COMMAND(ID_32805, &CTermProjectView::OnCreateUranus)
	ON_COMMAND(ID_32807, &CTermProjectView::OnCreateNeptun)
	ON_COMMAND(ID_32800, &CTermProjectView::OnDeleteMars)
	ON_COMMAND(ID_32802, &CTermProjectView::OnDeleteJupiter)
	ON_COMMAND(ID_32804, &CTermProjectView::OnDeleteSaturn)
	ON_COMMAND(ID_32806, &CTermProjectView::OnDeleteUranus)
	ON_COMMAND(ID_32808, &CTermProjectView::OnDeleteNeptun)
	ON_COMMAND(ID_32809, &CTermProjectView::OnCreateAllPlanet)
	
	ON_COMMAND(ID_32810, &CTermProjectView::OnCreateMoon)
	ON_COMMAND(ID_32794, &CTermProjectView::OnDeleteMercury)
	ON_COMMAND(ID_32796, &CTermProjectView::OnDeleteVenus)
	ON_COMMAND(ID_32798, &CTermProjectView::OnDeleteEarth)
	ON_COMMAND(ID_32793, &CTermProjectView::OnCreateMercury)
	ON_COMMAND(ID_32795, &CTermProjectView::OnCreateVenus)
	ON_COMMAND(ID_32797, &CTermProjectView::OnCreateEarth)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32811, &CTermProjectView::OnServerOpen)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32812, &CTermProjectView::OnFirstSimulStart)
END_MESSAGE_MAP()

// CTermProjectView 생성/소멸

CTermProjectView::CTermProjectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	planets[0] = new Planet{ "Mercury",5,5,0,1 };
	planets[1] = new Planet{ "Venus",5,5,0,1 };
	planets[2] = new Planet{ "Earth",5,5,0,1 };
	planets[3] = new Planet{ "Mars",5,5,0,1 };
	planets[4] = new Planet{ "Jupiter",5,5,0,1 };
	planets[5] = new Planet{ "Saturn",5,5,0,1 };
	planets[6] = new Planet{ "Uranus",5,5,0,1 };
	planets[7] = new Planet{ "Neptun",5,5,0,1 };
	planets[8] = new Satellite{"Moon",25,5,0,1 };
	list.insert(planets[0]);
	list.insert(planets[1]);
	list.insert(planets[2]);
	cnt = 0;
	stop_flag = 2;
	Open_flag = 0;
	TCP_flag = 2;
	stop_simul_flag = 2;
	m_pListenSocket = nullptr;
	check_flag = 0;
}

CTermProjectView::~CTermProjectView()
{
}

BOOL CTermProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTermProjectView 그리기

void CTermProjectView::OnDraw(CDC* pDC)
{
	CTermProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->SelectStockObject(BLACK_BRUSH);
	GetClientRect(&rect);
	pDC->Rectangle(0, 0, rect.Width(), rect.Height());

	load(pDC, nullptr, 0, 0);
	load(pDC, nullptr, 0, -1);

	CPen YellowPen(PS_SOLID, 1, RGB(255, 255, 0));
	CPen* pOldPen = pDC->SelectObject(&YellowPen);
	pDC->SelectStockObject(NULL_BRUSH);

	if (list.find("Mercury"))
	{
		CreatePlanet(planets[0], pDC, 0);
		load(pDC, planets[0], 49, 1);
	}

	if (list.find("Venus"))
	{
		CreatePlanet(planets[1], pDC, 1);
		load(pDC, planets[1], 45, 1);
	}

	if (list.find("Earth"))
	{
		CreatePlanet(planets[2], pDC, 2);
		load(pDC, planets[2], 43, 1);
	}

	if (list.find("Mars"))
	{
		CreatePlanet(planets[3], pDC, 3);
		load(pDC, planets[3], 49, 1);
	}

	if (list.find("Jupiter"))
	{
		CreatePlanet(planets[4], pDC, 4);
		load(pDC, planets[4], 30, 1);
	}

	if (list.find("Saturn"))
	{
		CreatePlanet(planets[5], pDC, 5);
		load(pDC, planets[5], 25, 1);
	}

	if (list.find("Uranus"))
	{
		CreatePlanet(planets[6], pDC, 6);
		load(pDC, planets[6], 37, 1);
	}
	if (list.find("Neptun"))
	{
		CreatePlanet(planets[7], pDC, 7);
		load(pDC, planets[7], 37, 1);
	}

	if (list.find("Moon"))
	{
		planets[8]->SetMoonFlag(1);
		planets[8]->position.x = (rect.Width() / 40) * cos(planets[8]->angle * (PI / 180))
			+ planets[2]->position.x + rect.Width() / 90;
		planets[8]->position.y = (rect.Width() / 40) * sin(planets[8]->angle * (PI / 180))
			+ planets[2]->position.y + rect.Width() / 110;

		load(pDC, planets[8], 80, 1);

		planets[8]->angle += planets[8]->speed + planets[2]->speed;

	}
	pDC->SelectObject(pOldPen);
	YellowPen.DeleteObject();
}


// CTermProjectView 인쇄

BOOL CTermProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTermProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTermProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTermProjectView 진단

#ifdef _DEBUG
void CTermProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CTermProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTermProjectDoc* CTermProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTermProjectDoc)));
	return (CTermProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CTermProjectView 메시지 처리기

PlanetControlDlg dlg;
void CTermProjectView::OnShowPlanetDlg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//PlanetControlDlg dlg;
	
	dlg.m_Mer_speed = planets[0]->speed;
	dlg.m_Mer_life = planets[0]->life;
	dlg.Mer_spin = planets[0]->spin;

	dlg.m_V_speed = planets[1]->speed;
	dlg.m_V_life= planets[1]->life;
	dlg.V_spin = planets[1]->spin;

	dlg.m_E_speed = planets[2]->speed;
	dlg.m_E_life = planets[2]->life;
	dlg.E_spin = planets[2]->spin;

	dlg.m_Mars_speed = planets[3]->speed;
	dlg.m_Mars_life = planets[3]->life;
	dlg.Mars_spin = planets[3]->spin;

	dlg.m_J_speed = planets[4]->speed;
	dlg.m_J_life = planets[4]->life;
	dlg.Ju_spin = planets[4]->spin;

	dlg.m_Sa_speed = planets[5]->speed;
	dlg.m_Sa_life = planets[5]->life;
	dlg.Sa_spin = planets[5]->spin;

	dlg.m_Ur_speed = planets[6]->speed;
	dlg.m_Ur_life = planets[6]->life;
	dlg.Ur_spin = planets[6]->spin;

	dlg.m_Ne_speed = planets[7]->speed;
	dlg.m_Ne_life = planets[7]->life;
	dlg.Ne_spin = planets[7]->spin;

	dlg.DoModal();
	planets[0]->speed = dlg.m_Mer_speed;
	planets[0]->life = dlg.m_Mer_life;
	planets[0]->spin = dlg.Mer_spin;

	planets[1]->speed = dlg.m_V_speed;
	planets[1]->life = dlg.m_V_life;
	planets[1]->spin = dlg.V_spin;

	planets[2]->speed = dlg.m_E_speed;
	planets[2]->life = dlg.m_E_life;
	planets[2]->spin = dlg.E_spin;

	planets[3]->speed = dlg.m_Mars_speed;
	planets[3]->life = dlg.m_Mars_life;
	planets[3]->spin = dlg.Mars_spin;

	planets[4]->speed = dlg.m_J_speed;
	planets[4]->life = dlg.m_J_life;
	planets[4]->spin = dlg.Ju_spin;

	planets[5]->speed = dlg.m_Sa_speed;
	planets[5]->life = dlg.m_Sa_life;
	planets[5]->spin = dlg.Sa_spin;

	planets[6]->speed = dlg.m_Ur_speed;
	planets[6]->life = dlg.m_Ur_life;
	planets[6]->spin = dlg.Ur_spin;

	planets[7]->speed = dlg.m_Ne_speed;
	planets[7]->life = dlg.m_Ne_life;
	planets[7]->spin = dlg.Ne_spin;
}


void CTermProjectView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CTermProjectView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	cnt++;
	if (cnt >= 200)
	{
		KillTimer(1);
		DisplayResult();
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}

void CTermProjectView::load(CDC* pDC, Planet* planet, int size, int flag)
{
	CDC MemDC;
	CBitmap bitmap;
	BITMAP bmpinfo, bmpinfo2, bmpinfo3;
	CBitmap* pOldBitmap;
	MemDC.CreateCompatibleDC(pDC);
	if (flag == 0 && planet == nullptr)
	{
		bitmap.LoadBitmap(IDB_UNIVERSE);
		bitmap.GetBitmap(&bmpinfo2);
		pOldBitmap = (CBitmap*)MemDC.SelectObject(&bitmap);
		pDC->Rectangle(0, 0, rect.Width(), rect.Height());
		pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &MemDC,
			0, 0, bmpinfo2.bmWidth, bmpinfo2.bmHeight, SRCCOPY);
		MemDC.SelectObject(pOldBitmap);
		bitmap.DeleteObject();
	}

	else if (flag == -1 && planet == nullptr)
	{
		bitmap.LoadBitmap(IDB_SUN);
		bitmap.GetBitmap(&bmpinfo3);
		pOldBitmap = (CBitmap*)MemDC.SelectObject(&bitmap);
		pDC->StretchBlt((rect.Width() / 2) - 90, (rect.Height() / 2) - 45
			, (rect.Width() / 17), (rect.Width() / 17)
			,&MemDC, 0, 0, bmpinfo3.bmWidth, bmpinfo3.bmHeight, SRCCOPY);
		MemDC.SelectObject(pOldBitmap);
		bitmap.DeleteObject();
	}

	else if (flag)
	{
		if (!strcmp(planet->Name, "Mercury"))
			bitmap.LoadBitmap(IDB_Mer);
		else if (!strcmp(planet->Name, "Venus"))
			bitmap.LoadBitmap(IDB_Venus);
		else if (!strcmp(planet->Name, "Earth"))
			bitmap.LoadBitmap(IDB_EEEE);
		else if (!strcmp(planet->Name, "Mars"))
			bitmap.LoadBitmap(IDB_BITMAP1);
		else if (!strcmp(planet->Name, "Jupiter"))
			bitmap.LoadBitmap(IDB_BITMAP2);
		else if (!strcmp(planet->Name, "Saturn"))
			bitmap.LoadBitmap(IDB_BITMAP6);
		else if (!strcmp(planet->Name, "Uranus"))
			bitmap.LoadBitmap(IDB_BITMAP4);
		else if (!strcmp(planet->Name, "Neptun"))
			bitmap.LoadBitmap(IDB_BITMAP5);
		else if (!strcmp(planet->Name, "Moon"))
			bitmap.LoadBitmap(IDB_BITMAP7);
		pOldBitmap = (CBitmap*)MemDC.SelectObject(&bitmap);
		bitmap.GetBitmap(&bmpinfo);

		pDC->StretchBlt(planet->position.x, planet->position.y, (rect.Width() / size), (rect.Width() / size),
			&MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		MemDC.SelectObject(pOldBitmap);
		bitmap.DeleteObject();
	}
}

void CTermProjectView::CreatePlanet(Planet* planet, CDC* pDC, int i)
{
	// TODO: 여기에 구현 코드 추가.

	CRect rect;
	GetClientRect(&rect);
	int compensation = (rect.Width() / 100);
	if (i == 4 || i == 5)
		compensation = (rect.Width() / 60);
	pDC->Ellipse(rect.Width() * (16 - 2 * i) / 40, rect.Height() * (16 - 2 * i) / 40,
		rect.Width() * (24 + 2 * i) / 40, rect.Height() * (24 + 2 * i) / 40);

	planet->position.x = rect.Width() * (4 + 2 * i) / 40 * cos(planet->angle * (PI / 180))
		+ rect.Width() * 20 / 40 - compensation;
	planet->position.y = rect.Height() * (4 + 2 * i) / 40 * sin(planet->angle * (PI / 180))
		+ rect.Height() * 20 / 40 - compensation;

	planet->angle += ((planet->speed) * (planet->spin));

	if (abs(planet->angle) > 360 * planet->count)
	{
		planet->life-- ;
		planet->count++;
	}

	if (planet->life <= 0)
	{
		BylifeDeletePlanet(planet);
		if (!(strcmp(planet->Name,"Earth"))) 
		{
			BylifeDeletePlanet(planets[8]);
			planets[8]->SetMoonFlag(0);
		}
	}
}


void CTermProjectView::OnStartSimul()
{
	if(stop_flag==0||Open_flag==1|| TCP_flag==1)
		SetTimer(1, 100, NULL);
}


void CTermProjectView::OnStopSimul()
{
	KillTimer(1);
	stop_flag = 0;
}

CString spin2string(Planet* planet)
{
	if (planet->spin == 1)
		return _T("CK");
	else if (planet->spin == -1)
		return _T("CCK");
}
int index = 0;
void CTermProjectView::DisplayResult()
{
	// TODO: 여기에 구현 코드 추가.

	CResultDlg dlg;
	PD_view.Mer_speed =	dlg.Mer_speed = planets[0]->speed;
	PD_view.V_speed =	dlg.V_speed = planets[1]->speed;
	PD_view.E_speed =	dlg.E_speed = planets[2]->speed;
	PD_view.Mars_speed=	dlg.Mars_speed= planets[3]->speed;
	PD_view.J_speed=	dlg.Ju_speed = planets[4]->speed;
	PD_view.Sa_speed=	dlg.Sa_speed = planets[5]->speed;
	PD_view.Ur_speed=	dlg.Ur_speed = planets[6]->speed;
	PD_view.Ne_speed=	dlg.Ne_speed = planets[7]->speed;

	PD_view.Mer_life=	dlg.Mer_life = planets[0]->life;
	PD_view.V_life=		dlg.V_life = planets[1]->life;
	PD_view.E_life=		dlg.E_life = planets[2]->life;
	PD_view.Mars_life=	dlg.Mars_life = planets[3]->life;
	PD_view.J_life=		dlg.Ju_life = planets[4]->life;
	PD_view.Sa_life=	dlg.Sa_life = planets[5]->life;
	PD_view.Ur_life=	dlg.Ur_life = planets[6]->life;
	PD_view.Ne_life=	dlg.Ne_life = planets[7]->life;

	dlg.Mer_spin =  spin2string(planets[0]);
	dlg.V_spin	=	spin2string(planets[1]);
	dlg.E_spin	=	spin2string(planets[2]);
	dlg.Mars_spin = spin2string(planets[3]);
	dlg.Ju_spin =	spin2string(planets[4]);         
	dlg.Sa_spin =	spin2string(planets[5]);
	dlg.Ur_spin =	spin2string(planets[6]);
	dlg.Ne_spin =	spin2string(planets[7]);

	PD_view.Mer_spin =	planets[0]->spin;
	PD_view.V_spin =	planets[1]->spin;
	PD_view.E_spin =	planets[2]->spin;
	PD_view.Mars_spin = planets[3]->spin;
	PD_view.J_spin =	planets[4]->spin;
	PD_view.Sa_spin =	planets[5]->spin;
	PD_view.Ur_spin =	planets[6]->spin;
	PD_view.Ne_spin =	planets[7]->spin;
	
	strcpy_s(PD_view.Moon_flag, planets[8]->GetMoonFlag());
	CString str(planets[8]->GetMoonFlag());

	for (int i = 0; i < 9; i++)
	{
		if ((list.find(planets[i]->Name)))
			ResultPlaent[index++] = list.find(planets[i]->Name);
	}

	if (list.getListNum() != 0)
	{
		resultText += "The planets in the orbit of the solar system are ";

		for (int i = 0; i < index; i++)
		{
			CString cstr(ResultPlaent[i]->Name);
			resultText += '<' + cstr + '>' + ',';
		}

		resultText.Delete(resultText.GetLength() - 1);
	}
	else if(list.getListNum() == 0)
		resultText += "There are no planets present in the solar system at the moment...";

	AfxMessageBox(resultText, MB_ICONINFORMATION);
	
	dlg.Moon_flag = str;

	if (check_flag==1)
		m_pServerSocket->Send(&PD_view, sizeof(PD_view));

	dlg.DoModal();

	list.removeAllplaent();
}


void CTermProjectView::OnCreateMars()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Mars")) 
		list.insert(planets[3]);
}


void CTermProjectView::OnCreateJupiter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Jupiter")) 
		list.insert(planets[4]);
}


void CTermProjectView::OnCreateSaturn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Saturn"))
		list.insert(planets[5]);
}


void CTermProjectView::OnCreateUranus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Uranus"))
		list.insert(planets[6]);
}


void CTermProjectView::OnCreateNeptun()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Neptun"))
		list.insert(planets[7]);
}


void CTermProjectView::OnDeleteMars()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if(list.find("Mars"))
		list.remove("Mars");
	planets[3]->Reset();
}


void CTermProjectView::OnDeleteJupiter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Jupiter"))
		list.remove("Jupiter");
	planets[4]->Reset();
}


void CTermProjectView::OnDeleteSaturn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Saturn"))
		list.remove("Saturn");
	planets[5]->Reset();
}


void CTermProjectView::OnDeleteUranus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Uranus"))
		list.remove("Uranus");
	planets[6]->Reset();
}

void CTermProjectView::OnDeleteNeptun()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Neptun"))
		list.remove("Neptun");
	planets[7]->Reset();
}


void CTermProjectView::OnCreateAllPlanet()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	for (int i = 0; i < 8; i++)
	{
		if(!(list.find(planets[i]->Name)))
				list.insert(planets[i]);
	}
}


void CTermProjectView::BylifeDeletePlanet(Planet* planet)
{
	// TODO: 여기에 구현 코드 추가.
	list.remove(planet->Name);
}


void CTermProjectView::OnCreateMoon()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Earth"))
		list.insert(planets[8]);
}


void CTermProjectView::OnDeleteMercury()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Mercury"))
		list.remove("Mercury");
	planets[0]->Reset();
}


void CTermProjectView::OnDeleteVenus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Venus"))
		list.remove("Venus");
	planets[1]->Reset();

}


void CTermProjectView::OnDeleteEarth()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (list.find("Earth"))
		list.remove("Earth");
	if (list.find("Moon"))
	{
		list.remove("Moon");
		planets[8]->SetMoonFlag(0);
	}
	planets[2]->Reset();

}


void CTermProjectView::OnCreateMercury()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Mercury"))
		list.insert(planets[0]);
}


void CTermProjectView::OnCreateVenus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Venus"))
		list.insert(planets[1]);
}


void CTermProjectView::OnCreateEarth()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!list.find("Earth"))
		list.insert(planets[2]);
}


void CTermProjectView::OnServerOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_pListenSocket = new CListenSocket;
	if (m_pListenSocket->Create(7000, SOCK_STREAM))
	{
		if (m_pListenSocket->Listen()) {
			AfxMessageBox(_T("Server OPEN"));	
			list.clear();

			for (int i = 0; i < 8; i++)
				planets[i]->Reset();

			list.insert(planets[0]);
			list.insert(planets[1]);
			list.insert(planets[2]);
			cnt = 0;
			KillTimer(1);
			Invalidate();
		}
		else 
			AfxMessageBox(_T("Failed to LISTEN."));
	}
	else
		AfxMessageBox(_T("Failed to create socket for listen."));
}


BOOL CTermProjectView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == 'X' 
		&& (GetKeyState(VK_CONTROL) & 0x8000))
	{
		KillTimer(1);
		DisplayResult();
		return TRUE;
	}

	return CView::PreTranslateMessage(pMsg);
}


void CTermProjectView::OnFirstSimulStart()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


	SetTimer(1, 100, NULL);
}
