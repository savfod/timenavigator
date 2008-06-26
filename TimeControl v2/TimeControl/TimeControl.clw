; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgCorrect
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TimeControl.h"
LastPage=0

ClassCount=10
Class1=CTimeControlApp
Class2=CTimeControlDoc
Class3=CTimeControlView
Class4=CMainFrame

ResourceCount=12
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TIMECONTROL_FORM
Resource4=IDD_ALL
Resource5=IDD_ABOUTBOX (English (U.S.))
Class5=CAboutDlg
Resource6=IDR_CONTEXTMENU
Class6=CDlgAdding
Resource7=IDD_ADDING
Class7=CDlgError
Resource8=IDD_SURE
Class8=CDlgSure
Resource9=IDD_CORRECT
Class9=CDlgCorrect
Resource10=IDD_TIMECONTROL_FORM (English (U.S.))
Resource11=IDD_ERROR
Class10=CDlgAllTasks
Resource12=IDR_MAINFRAME (English (U.S.))

[CLS:CTimeControlApp]
Type=0
HeaderFile=TimeControl.h
ImplementationFile=TimeControl.cpp
Filter=N

[CLS:CTimeControlDoc]
Type=0
HeaderFile=TimeControlDoc.h
ImplementationFile=TimeControlDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CTimeControlDoc

[CLS:CTimeControlView]
Type=0
HeaderFile=TimeControlView.h
ImplementationFile=TimeControlView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CTimeControlView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=TimeControl.cpp
ImplementationFile=TimeControl.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE

[DLG:IDD_TIMECONTROL_FORM]
Type=1
Class=CTimeControlView

[DLG:IDD_TIMECONTROL_FORM (English (U.S.))]
Type=1
Class=CTimeControlView
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631429

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_Stop_Time
Command6=ID_add_task
Command7=ID_Delete
Command8=ID_correct
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_Stop_Time
Command14=ID_add_task
Command15=ID_Delete
Command16=ID_correct
Command17=ID_ARCHIVE
Command18=ID_SHOW
Command19=ID_VIEW_TOOLBAR
Command20=ID_VIEW_STATUS_BAR
Command21=ID_ViewAllTime
Command22=ID_APP_ABOUT
CommandCount=22

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_add_task
Command2=ID_correct
Command3=ID_EDIT_COPY
Command4=ID_ARCHIVE
Command5=ID_FILE_NEW
Command6=ID_FILE_OPEN
Command7=ID_FILE_PRINT
Command8=ID_FILE_SAVE
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_UNDO
Command11=ID_Delete
Command12=ID_EDIT_CUT
Command13=ID_Stop_Time
Command14=ID_NEXT_PANE
Command15=ID_PREV_PANE
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_EDIT_CUT
Command19=ID_EDIT_UNDO
CommandCount=19

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADDING]
Type=1
Class=CDlgAdding
ControlCount=7
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TYPE,button,1342308361
Control7=IDC_RADIO2,button,1342177289

[CLS:CDlgAdding]
Type=0
HeaderFile=DlgAdding.h
ImplementationFile=DlgAdding.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgAdding
VirtualFilter=dWC

[DLG:IDD_ERROR]
Type=1
Class=CDlgError
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:CDlgError]
Type=0
HeaderFile=DlgError.h
ImplementationFile=DlgError.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_SURE]
Type=1
Class=CDlgSure
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CDlgSure]
Type=0
HeaderFile=DlgSure.h
ImplementationFile=DlgSure.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgSure

[DLG:IDD_CORRECT]
Type=1
Class=CDlgCorrect
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_TYPE,button,1342308361
Control6=IDC_RADIO2,button,1342177289
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PLUS,button,1342308361
Control9=IDC_RADIO4,button,1342177289
Control10=IDC_EDIT2,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT3,edit,1350631552
Control15=IDC_EDIT4,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_TODAY,button,1342242819

[CLS:CDlgCorrect]
Type=0
HeaderFile=DlgCorrect.h
ImplementationFile=DlgCorrect.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgCorrect
VirtualFilter=dWC

[MNU:IDR_CONTEXTMENU]
Type=1
Class=?
Command1=ID_Delete
Command2=ID_correct
Command3=ID_ARCHIVE
CommandCount=3

[CLS:CDlgAllTasks]
Type=0
HeaderFile=DlgAllTasks.h
ImplementationFile=DlgAllTasks.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_ALL]
Type=1
Class=CDlgAllTasks
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631429
Control4=IDC_STATIC,static,1342308352

