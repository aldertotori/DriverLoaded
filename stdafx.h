// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__36047960_C926_419B_83AD_E91A2965C5FA__INCLUDED_)
#define AFX_STDAFX_H__36047960_C926_419B_83AD_E91A2965C5FA__INCLUDED_

// Change these values to use different versions
#define WINVER		0x0400
//#define _WIN32_WINNT	0x0400
#define _WIN32_IE	0x0400
#define _RICHEDIT_VER	0x0100

#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>
#include <atlctrls.h>




//
// System Information Classes.
//
typedef enum _SYSTEM_INFORMATION_CLASS {
	SystemBasicInformation,
		SystemProcessorInformation,              // obsolete...delete
		SystemPerformanceInformation,
		SystemTimeOfDayInformation,
		SystemPathInformation,
		SystemProcessInformation,                //系统进程信息
		SystemCallCountInformation,
		SystemDeviceInformation,
		SystemProcessorPerformanceInformation,
		SystemFlagsInformation,
		SystemCallTimeInformation,
		SystemModuleInformation,     //系统模块
		SystemLocksInformation,
		SystemStackTraceInformation,
		SystemPagedPoolInformation,
		SystemNonPagedPoolInformation,
		SystemHandleInformation,
		SystemObjectInformation,
		SystemPageFileInformation,
		SystemVdmInstemulInformation,
		SystemVdmBopInformation,
		SystemFileCacheInformation,
		SystemPoolTagInformation,
		SystemInterruptInformation,
		SystemDpcBehaviorInformation,
		SystemFullMemoryInformation,
		SystemLoadGdiDriverInformation,
		SystemUnloadGdiDriverInformation,
		SystemTimeAdjustmentInformation,
		SystemSummaryMemoryInformation,
		SystemMirrorMemoryInformation,
		SystemPerformanceTraceInformation,
		SystemObsolete0,
		SystemExceptionInformation,
		SystemCrashDumpStateInformation,
		SystemKernelDebuggerInformation,
		SystemContextSwitchInformation,
		SystemRegistryQuotaInformation,
		SystemExtendServiceTableInformation,
		SystemPrioritySeperation,
		SystemVerifierAddDriverInformation,
		SystemVerifierRemoveDriverInformation,
		SystemProcessorIdleInformation,
		SystemLegacyDriverInformation,
		SystemCurrentTimeZoneInformation,
		SystemLookasideInformation,
		SystemTimeSlipNotification,
		SystemSessionCreate,
		SystemSessionDetach,
		SystemSessionInformation,
		SystemRangeStartInformation,
		SystemVerifierInformation,
		SystemVerifierThunkExtend,
		SystemSessionProcessInformation,
		SystemLoadGdiDriverInSystemSpace,
		SystemNumaProcessorMap,
		SystemPrefetcherInformation,
		SystemExtendedProcessInformation,
		SystemRecommendedSharedDataAlignment,
		SystemComPlusPackage,
		SystemNumaAvailableMemory,
		SystemProcessorPowerInformation,
		SystemEmulationBasicInformation,
		SystemEmulationProcessorInformation,
		SystemExtendedHandleInformation,
		SystemLostDelayedWriteInformation,
		SystemBigPoolInformation,
		SystemSessionPoolTagInformation,
		SystemSessionMappedViewInformation,
		SystemHotpatchInformation,
		SystemObjectSecurityMode,
		SystemWatchdogTimerHandler,
		SystemWatchdogTimerInformation,
		SystemLogicalProcessorInformation,
		SystemWow64SharedInformation,
		SystemRegisterFirmwareTableInformationHandler,
		SystemFirmwareTableInformation,
		SystemModuleInformationEx,
		SystemVerifierTriageInformation,
		SystemSuperfetchInformation,
		SystemMemoryListInformation,
		SystemFileCacheInformationEx,
		MaxSystemInfoClass   // MaxSystemInfoClass should always be the last enum
} SYSTEM_INFORMATION_CLASS;

INT WINAPI
NtQuerySystemInformation (
						  IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
						  OUT PVOID SystemInformation,
						  IN ULONG SystemInformationLength,
						  OUT PULONG ReturnLength OPTIONAL
    );

typedef INT (WINAPI *PFN_NtQuerySystemInformation)(
												   IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
												   OUT PVOID SystemInformation,
												   IN ULONG SystemInformationLength,
												   OUT PULONG ReturnLength OPTIONAL
												   );

// LIST_ENTRY PsLoadedModuleList;//驱动模块列表
// LIST_ENTRY MmLoadedUserImageList;//应用程序映像列表

#pragma pack(push,1)

typedef struct _RTL_PROCESS_MODULE_INFORMATION
{
	HANDLE Section; // Not filled in
	PVOID  MappedBase;
	PVOID  ImageBase;
	ULONG  ImageSize;
	ULONG  Flags;
	USHORT LoadOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	UCHAR  FullPathName[256];
} RTL_PROCESS_MODULE_INFORMATION, *PRTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES
{
	ULONG NumberOfModules;
	RTL_PROCESS_MODULE_INFORMATION Modules[1];
} RTL_PROCESS_MODULES,*PRTL_PROCESS_MODULES;

#pragma pack(pop)

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__36047960_C926_419B_83AD_E91A2965C5FA__INCLUDED_)
