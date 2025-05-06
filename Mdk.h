/**
 * @file Mdk.h
 * @author Ky4meru (@ky4meru)
 * @brief Malware Development Kit as a C header only.
 * @version 0.1
 * @date 2025-05-01
 * @copyright Copyright (c) 2025
 */

#ifndef _MDK_H_
#define _MDK_H_

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <Windows.h>

/**
 * @brief Represents a handle to the current process.
 */
#define MDK_CURRENT_PROCESS ( ( HANDLE ) ( LONG_PTR ) -1 )

/**
 * @brief Represents a handle to the current thread.
 */
#define MDK_CURRENT_THREAD ( ( HANDLE ) ( LONG_PTR ) -2 )

/**
 * @brief Casts a value to a VOID pointer.
 */
#define MDK_C_PTR( x ) ( ( LPVOID ) ( x ) )

/**
 * @brief Casts a value to an unsigned 64 bits value.
 */
#define MDK_U_PTR( x ) ( ( UINT_PTR ) ( x ) ) 

/**
 * @brief Gets a callable native syscall pointer.
 * 
 * As shown below, the returned function pointer is directly callable thanks to a generic cast.
 * However, this generic cast forces to explicitly cast the value returned by the syscall (if any).
 * 
 * @code{.cpp}
 * NTSTATUS status = (NTSTATUS)MDK_NTSYSCALL(NtDelayExecution)(FALSE, &delay);
 * @endcode
 * 
 * For C programming compability, the syscall can not be cast to a fully variadic function, at least one argument must be provided.
 * Therefore, in case the syscall do not take any argument, simply provide a dummy NULL value as parameter.
 * 
 * @code{.cpp}
 * ULONG number = (ULONG)MDK_NTSYSCALL(NtGetCurrentProcessorNumber)(NULL);
 * @endcode
 * 
 * @param s The name of the native syscall to get.
 * @return Native syscall pointer that can be called.
 */
#define MDK_NTSYSCALL( s ) ( ( LPVOID ( * ) ( LPVOID, ... ) ) MdkGetProcAddressByHash( MdkGetModuleHandleByHash( MDK_HASH_Ntdll ), MDK_HASH_##s ) )

/**
 * @brief The key used to encrypt string hashes.
 */
#define MDK_KEY 0x12345678

/**
 * @brief The hash corresponding to Advapi32.dll.
 */
#define MDK_HASH_Advapi32 0x768f6751

/**
 * @brief The hash corresponding to Kernel32.dll.
 */
#define MDK_HASH_Kernel32 0x7fefc32d

/**
 * @brief The hash corresponding to Kernelbase.dll.
 */
#define MDK_HASH_Kernelbase 0x11dfe5f3

/**
 * @brief The hash corresponding to Ntdll.dll.
 */
#define MDK_HASH_Ntdll 0xceee695

/**
 * @brief The hash corresponding to Wininet.dll.
 */
#define MDK_HASH_Wininet 0x4eef9d55

/**
 * @brief The hash corresponding to the NtCreateProcess syscall.
 */
#define MDK_HASH_NtCreateProcess 0xe277ce22

/**
 * @brief The hash corresponding to the NtCreateProcessEx syscall.
 */
#define MDK_HASH_NtCreateProcessEx 0x1dbf766f

/**
 * @brief The hash corresponding to the NtCreateUserProcess syscall.
 */
#define MDK_HASH_NtCreateUserProcess 0x46fa0901

/**
 * @brief The hash corresponding to the NtSetInformationProcess syscall.
 */
#define MDK_HASH_NtSetInformationProcess 0x64db8020

/**
 * @brief The hash corresponding to the NtQueryInformationProcess syscall.
 */
#define MDK_HASH_NtQueryInformationProcess 0x9ee80bba

/**
 * @brief The hash corresponding to the NtQueryObject syscall.
 */
#define MDK_HASH_NtQueryObject 0xda699fcc

/**
 * @brief The hash corresponding to the NtQuerySystemInformation syscall.
 */
#define MDK_HASH_NtQuerySystemInformation 0x69f66f50

/**
 * @brief The hash corresponding to the NtQuerySystemInformationEx syscall.
 */
#define MDK_HASH_NtQuerySystemInformationEx 0x67017a1d

/**
 * @brief The hash corresponding to the NtSetSystemInformation syscall.
 */
#define MDK_HASH_NtSetSystemInformation 0x8069a086

/**
 * @brief The hash corresponding to the NtSetInformationThread syscall.
 */
#define MDK_HASH_NtSetInformationThread 0x1e085589

/**
 * @brief The hash corresponding to the NtQueryInformationThread syscall.
 */
#define MDK_HASH_NtQueryInformationThread 0xe7941063

/**
 * @brief The hash corresponding to the NtUnmapViewOfSection syscall.
 */
#define MDK_HASH_NtUnmapViewOfSection 0x789044b5

/**
 * @brief The hash corresponding to the NtUnmapViewOfSectionEx syscall.
 */
#define MDK_HASH_NtUnmapViewOfSectionEx 0xb1c05532

/**
 * @brief The hash corresponding to the NtExtendSection syscall.
 */
#define MDK_HASH_NtExtendSection 0xa7da717c

/**
 * @brief The hash corresponding to the NtSuspendThread syscall.
 */
#define MDK_HASH_NtSuspendThread 0xf609c599

/**
 * @brief The hash corresponding to the NtResumeThread syscall.
 */
#define MDK_HASH_NtResumeThread 0x487f95a8

/**
 * @brief The hash corresponding to the NtSuspendProcess syscall.
 */
#define MDK_HASH_NtSuspendProcess 0x5d173230

/**
 * @brief The hash corresponding to the NtResumeProcess syscall.
 */
#define MDK_HASH_NtResumeProcess 0x94c3c46f

/**
 * @brief The hash corresponding to the NtGetCurrentProcessorNumber syscall.
 */
#define MDK_HASH_NtGetCurrentProcessorNumber 0x66b620eb

/**
 * @brief The hash corresponding to the NtSignalAndWaitForSingleObject syscall.
 */
#define MDK_HASH_NtSignalAndWaitForSingleObject 0x6aac6c95

/**
 * @brief The hash corresponding to the NtWaitForSingleObject syscall.
 */
#define MDK_HASH_NtWaitForSingleObject 0xfa985a44

/**
 * @brief The hash corresponding to the NtWaitForMultipleObjects syscall.
 */
#define MDK_HASH_NtWaitForMultipleObjects 0x9cea80a1

/**
 * @brief The hash corresponding to the NtWaitForMultipleObjects32 syscall.
 */
#define MDK_HASH_NtWaitForMultipleObjects32 0xd3dba1a6

/**
 * @brief The hash corresponding to the NtSetSecurityObject syscall.
 */
#define MDK_HASH_NtSetSecurityObject 0xf870b77a

/**
 * @brief The hash corresponding to the NtQuerySecurityObject syscall.
 */
#define MDK_HASH_NtQuerySecurityObject 0x9ee61514

/**
 * @brief The hash corresponding to the NtQueueApcThread syscall.
 */
#define MDK_HASH_NtQueueApcThread 0x185232c0

/**
 * @brief The hash corresponding to the NtQueueApcThreadEx syscall.
 */
#define MDK_HASH_NtQueueApcThreadEx 0x2fa62d8d

/**
 * @brief The hash corresponding to the NtProtectVirtualMemory syscall.
 */
#define MDK_HASH_NtProtectVirtualMemory 0x42dd7ef0

/**
 * @brief The hash corresponding to the NtFlushBuffersFile syscall.
 */
#define MDK_HASH_NtFlushBuffersFile 0xd5511b6e

/**
 * @brief The hash corresponding to the NtFlushInstructionCache syscall.
 */
#define MDK_HASH_NtFlushInstructionCache 0x705dee07

/**
 * @brief The hash corresponding to the NtFlushWriteBuffer syscall.
 */
#define MDK_HASH_NtFlushWriteBuffer 0xddf55ed6

/**
 * @brief The hash corresponding to the NtFsControlFile syscall.
 */
#define MDK_HASH_NtFsControlFile 0xfeeb8079

/**
 * @brief The hash corresponding to the NtLockFile syscall.
 */
#define MDK_HASH_NtLockFile 0x2209c768

/**
 * @brief The hash corresponding to the NtUnlockFile syscall.
 */
#define MDK_HASH_NtUnlockFile 0x7317e36b

/**
 * @brief The hash corresponding to the NtFlushVirtualMemory syscall.
 */
#define MDK_HASH_NtFlushVirtualMemory 0x314e2171

/**
 * @brief The hash corresponding to the NtQueryVirtualMemory syscall.
 */
#define MDK_HASH_NtQueryVirtualMemory 0x2f4be25

/**
 * @brief The hash corresponding to the NtLockVirtualMemory syscall.
 */
#define MDK_HASH_NtLockVirtualMemory 0x834548c8

/**
 * @brief The hash corresponding to the NtUnlockVirtualMemory syscall.
 */
#define MDK_HASH_NtUnlockVirtualMemory 0xbfab206b

/**
 * @brief The hash corresponding to the NtSystemDebugControl syscall.
 */
#define MDK_HASH_NtSystemDebugControl 0x877f2a6c

/**
 * @brief The hash corresponding to the NtShutdownSystem syscall.
 */
#define MDK_HASH_NtShutdownSystem 0x33289b30

/**
 * @brief The hash corresponding to the NtDisplayString syscall.
 */
#define MDK_HASH_NtDisplayString 0x6369ae2c

/**
 * @brief The hash corresponding to the NtDrawText syscall.
 */
#define MDK_HASH_NtDrawText 0xa3604482

/**
 * @brief The hash corresponding to the NtYieldExecution syscall.
 */
#define MDK_HASH_NtYieldExecution 0xcd43d2a

/**
 * @brief The hash corresponding to the NtClose syscall.
 */
#define MDK_HASH_NtClose 0x52e2b0e5

/**
 * @brief The hash corresponding to the NtQueryAttributesFile syscall.
 */
#define MDK_HASH_NtQueryAttributesFile 0xa85d615c

/**
 * @brief The hash corresponding to the NtQueryFullAttributesFile syscall.
 */
#define MDK_HASH_NtQueryFullAttributesFile 0x88ca976f

/**
 * @brief The hash corresponding to the NtQueryInformationByName syscall.
 */
#define MDK_HASH_NtQueryInformationByName 0xdee09c27

/**
 * @brief The hash corresponding to the NtQueryInformationFile syscall.
 */
#define MDK_HASH_NtQueryInformationFile 0xd06ae85b

/**
 * @brief The hash corresponding to the NtSetInformationFile syscall.
 */
#define MDK_HASH_NtSetInformationFile 0xdc115801

/**
 * @brief The hash corresponding to the NtSetQuotaInformationFile syscall.
 */
#define MDK_HASH_NtSetQuotaInformationFile 0xa8ade33b

/**
 * @brief The hash corresponding to the NtSetVolumeInformationFile syscall.
 */
#define MDK_HASH_NtSetVolumeInformationFile 0x27531649

/**
 * @brief The hash corresponding to the NtCreateFile syscall.
 */
#define MDK_HASH_NtCreateFile 0x742269c3

/**
 * @brief The hash corresponding to the NtCreateNamedPipeFile syscall.
 */
#define MDK_HASH_NtCreateNamedPipeFile 0xf945056

/**
 * @brief The hash corresponding to the NtCreateMailslotFile syscall.
 */
#define MDK_HASH_NtCreateMailslotFile 0x41e20118

/**
 * @brief The hash corresponding to the NtCancelIoFile syscall.
 */
#define MDK_HASH_NtCancelIoFile 0xd30e4d5d

/**
 * @brief The hash corresponding to the NtCancelIoFileEx syscall.
 */
#define MDK_HASH_NtCancelIoFileEx 0xea19d7da

/**
 * @brief The hash corresponding to the NtCancelSynchronousIoFile syscall.
 */
#define MDK_HASH_NtCancelSynchronousIoFile 0x8d59b3e8

/**
 * @brief The hash corresponding to the NtCreateSymbolicLinkObject syscall.
 */
#define MDK_HASH_NtCreateSymbolicLinkObject 0xe999f2da

/**
 * @brief The hash corresponding to the NtOpenSymbolicLinkObject syscall.
 */
#define MDK_HASH_NtOpenSymbolicLinkObject 0x3041c6d8

/**
 * @brief The hash corresponding to the NtQuerySymbolicLinkObject syscall.
 */
#define MDK_HASH_NtQuerySymbolicLinkObject 0xb59c52fc

/**
 * @brief The hash corresponding to the NtGetContextThread syscall.
 */
#define MDK_HASH_NtGetContextThread 0x7f16aefc

/**
 * @brief The hash corresponding to the NtSetContextThread syscall.
 */
#define MDK_HASH_NtSetContextThread 0xed94e968

/**
 * @brief The hash corresponding to the NtOpenProcess syscall.
 */
#define MDK_HASH_NtOpenProcess 0x59b6a160

/**
 * @brief The hash corresponding to the NtTerminateProcess syscall.
 */
#define MDK_HASH_NtTerminateProcess 0x5ced8b37

/**
 * @brief The hash corresponding to the NtGetNextProcess syscall.
 */
#define MDK_HASH_NtGetNextProcess 0x1b5795dd

/**
 * @brief The hash corresponding to the NtGetNextThread syscall.
 */
#define MDK_HASH_NtGetNextThread 0xb624ade6

/**
 * @brief The hash corresponding to the NtCreateDebugObject syscall.
 */
#define MDK_HASH_NtCreateDebugObject 0xf99bdd21

/**
 * @brief The hash corresponding to the NtDebugActiveProcess syscall.
 */
#define MDK_HASH_NtDebugActiveProcess 0x107488d1

/**
 * @brief The hash corresponding to the NtContinue syscall.
 */
#define MDK_HASH_NtContinue 0xee0e3a54

/**
 * @brief The hash corresponding to the NtRaiseException syscall.
 */
#define MDK_HASH_NtRaiseException 0xced6b2f2

/**
 * @brief The hash corresponding to the NtCreateThread syscall.
 */
#define MDK_HASH_NtCreateThread 0x770adbcb

/**
 * @brief The hash corresponding to the NtCreateThreadEx syscall.
 */
#define MDK_HASH_NtCreateThreadEx 0xbd2c99c8

/**
 * @brief The hash corresponding to the NtCreateJobObject syscall.
 */
#define MDK_HASH_NtCreateJobObject 0xd0dc0e15

/**
 * @brief The hash corresponding to the NtOpenJobObject syscall.
 */
#define MDK_HASH_NtOpenJobObject 0xf94e08d3

/**
 * @brief The hash corresponding to the NtAssignProcessToJobObject syscall.
 */
#define MDK_HASH_NtAssignProcessToJobObject 0xd57eb8

/**
 * @brief The hash corresponding to the NtTerminateJobObject syscall.
 */
#define MDK_HASH_NtTerminateJobObject 0x3217f8da

/**
 * @brief The hash corresponding to the NtIsProcessInJob syscall.
 */
#define MDK_HASH_NtIsProcessInJob 0xc1c6274c

/**
 * @brief The hash corresponding to the NtQueryInformationJobObject syscall.
 */
#define MDK_HASH_NtQueryInformationJobObject 0xfafc41ad

/**
 * @brief The hash corresponding to the NtSetInformationJobObject syscall.
 */
#define MDK_HASH_NtSetInformationJobObject 0xb7a85b93

/**
 * @brief The hash corresponding to the NtCreateJobSet syscall.
 */
#define MDK_HASH_NtCreateJobSet 0x5c554f7a

/**
 * @brief The hash corresponding to the NtAllocateReserveObject syscall.
 */
#define MDK_HASH_NtAllocateReserveObject 0x3eb05787

/**
 * @brief The hash corresponding to the NtRegisterThreadTerminatePort syscall.
 */
#define MDK_HASH_NtRegisterThreadTerminatePort 0x45bb498a

/**
 * @brief The hash corresponding to the NtRaiseHardError syscall.
 */
#define MDK_HASH_NtRaiseHardError 0x6dce287c

/**
 * @brief The hash corresponding to the NtAllocateVirtualMemory syscall.
 */
#define MDK_HASH_NtAllocateVirtualMemory 0xe5b7ee94

/**
 * @brief The hash corresponding to the NtFreeVirtualMemory syscall.
 */
#define MDK_HASH_NtFreeVirtualMemory 0x3a369071

/**
 * @brief The hash corresponding to the NtReadVirtualMemory syscall.
 */
#define MDK_HASH_NtReadVirtualMemory 0xb11cd77b

/**
 * @brief The hash corresponding to the NtWriteVirtualMemory syscall.
 */
#define MDK_HASH_NtWriteVirtualMemory 0xd12357ea

/**
 * @brief The hash corresponding to the NtAllocateUserPhysicalPages syscall.
 */
#define MDK_HASH_NtAllocateUserPhysicalPages 0x266f5160

/**
 * @brief The hash corresponding to the NtMapUserPhysicalPages syscall.
 */
#define MDK_HASH_NtMapUserPhysicalPages 0xc2b75b69

/**
 * @brief The hash corresponding to the NtMapUserPhysicalPagesScatter syscall.
 */
#define MDK_HASH_NtMapUserPhysicalPagesScatter 0x4fb0cdbf

/**
 * @brief The hash corresponding to the NtFreeUserPhysicalPages syscall.
 */
#define MDK_HASH_NtFreeUserPhysicalPages 0x6b910ccd

/**
 * @brief The hash corresponding to the NtQuerySection syscall.
 */
#define MDK_HASH_NtQuerySection 0x1cbd420a

/**
 * @brief The hash corresponding to the NtAreMappedFilesTheSame syscall.
 */
#define MDK_HASH_NtAreMappedFilesTheSame 0xd94eb708

/**
 * @brief The hash corresponding to the NtCreateSection syscall.
 */
#define MDK_HASH_NtCreateSection 0xaa3b2d28

/**
 * @brief The hash corresponding to the NtCreateSectionEx syscall.
 */
#define MDK_HASH_NtCreateSectionEx 0xebefcef5

/**
 * @brief The hash corresponding to the NtOpenSection syscall.
 */
#define MDK_HASH_NtOpenSection 0x17a8c76

/**
 * @brief The hash corresponding to the NtMapViewOfSection syscall.
 */
#define MDK_HASH_NtMapViewOfSection 0xc450cdb2

/**
 * @brief The hash corresponding to the NtMapViewOfSectionEx syscall.
 */
#define MDK_HASH_NtMapViewOfSectionEx 0x13cee9ff

/**
 * @brief The hash corresponding to the NtOpenSession syscall.
 */
#define MDK_HASH_NtOpenSession 0x65b83c5

/**
 * @brief The hash corresponding to the NtNotifyChangeDirectoryFile syscall.
 */
#define MDK_HASH_NtNotifyChangeDirectoryFile 0x66c6e223

/**
 * @brief The hash corresponding to the NtNotifyChangeDirectoryFileEx syscall.
 */
#define MDK_HASH_NtNotifyChangeDirectoryFileEx 0x6e451620

/**
 * @brief The hash corresponding to the NtOpenFile syscall.
 */
#define MDK_HASH_NtOpenFile 0x54e9b141

/**
 * @brief The hash corresponding to the NtQueryDirectoryFile syscall.
 */
#define MDK_HASH_NtQueryDirectoryFile 0x99a1470a

/**
 * @brief The hash corresponding to the NtQueryDirectoryFileEx syscall.
 */
#define MDK_HASH_NtQueryDirectoryFileEx 0xd72b6957

/**
 * @brief The hash corresponding to the NtQueryEaFile syscall.
 */
#define MDK_HASH_NtQueryEaFile 0xa2c1adfb

/**
 * @brief The hash corresponding to the NtSetEaFile syscall.
 */
#define MDK_HASH_NtSetEaFile 0x29333561

/**
 * @brief The hash corresponding to the NtLoadDriver syscall.
 */
#define MDK_HASH_NtLoadDriver 0x2cb5afcb

/**
 * @brief The hash corresponding to the NtUnloadDriver syscall.
 */
#define MDK_HASH_NtUnloadDriver 0x53b57c0e

/**
 * @brief The hash corresponding to the NtReadFile syscall.
 */
#define MDK_HASH_NtReadFile 0xa0ed647b

/**
 * @brief The hash corresponding to the NtReadFileScatter syscall.
 */
#define MDK_HASH_NtReadFileScatter 0x9712a01

/**
 * @brief The hash corresponding to the NtWriteFileGather syscall.
 */
#define MDK_HASH_NtWriteFileGather 0x20afb595

/**
 * @brief The hash corresponding to the NtDeleteFile syscall.
 */
#define MDK_HASH_NtDeleteFile 0x3bb08e82

/**
 * @brief The hash corresponding to the NtWriteFile syscall.
 */
#define MDK_HASH_NtWriteFile 0xf2e24bca

/**
 * @brief The hash corresponding to the NtDeviceIoControlFile syscall.
 */
#define MDK_HASH_NtDeviceIoControlFile 0x17e12ba8

/**
 * @brief The hash corresponding to the NtSetInformationObject syscall.
 */
#define MDK_HASH_NtSetInformationObject 0x12151568

/**
 * @brief The hash corresponding to the NtDuplicateObject syscall.
 */
#define MDK_HASH_NtDuplicateObject 0x56758e21

/**
 * @brief The hash corresponding to the NtMakePermanentObject syscall.
 */
#define MDK_HASH_NtMakePermanentObject 0xb2a949fe

/**
 * @brief The hash corresponding to the NtMakeTemporaryObject syscall.
 */
#define MDK_HASH_NtMakeTemporaryObject 0xfcdafa07

/**
 * @brief The hash corresponding to the NtCreateDirectoryObject syscall.
 */
#define MDK_HASH_NtCreateDirectoryObject 0x50201b5f

/**
 * @brief The hash corresponding to the NtOpenDirectoryObject syscall.
 */
#define MDK_HASH_NtOpenDirectoryObject 0x8019df9d

/**
 * @brief The hash corresponding to the NtQueryDirectoryObject syscall.
 */
#define MDK_HASH_NtQueryDirectoryObject 0xcba9be31

/**
 * @brief The hash corresponding to the NtCreatePrivateNamespace syscall.
 */
#define MDK_HASH_NtCreatePrivateNamespace 0xfdc5bcbb

/**
 * @brief The hash corresponding to the NtOpenPrivateNamespace syscall.
 */
#define MDK_HASH_NtOpenPrivateNamespace 0x5106e939

/**
 * @brief The hash corresponding to the NtDeletePrivateNamespace syscall.
 */
#define MDK_HASH_NtDeletePrivateNamespace 0x8f450cfa

/**
 * @brief The hash corresponding to the NtOpenThread syscall.
 */
#define MDK_HASH_NtOpenThread 0x84ba5ac9

/**
 * @brief The hash corresponding to the NtTerminateThread syscall.
 */
#define MDK_HASH_NtTerminateThread 0xdec1de70

/**
 * @brief The hash corresponding to the NtQuerySystemTime syscall.
 */
#define MDK_HASH_NtQuerySystemTime 0x5fb4a6a9

/**
 * @brief The hash corresponding to the NtSetSystemTime syscall.
 */
#define MDK_HASH_NtSetSystemTime 0xd8bc651f

/**
 * @brief The hash corresponding to the NtQueryTimerResolution syscall.
 */
#define MDK_HASH_NtQueryTimerResolution 0xb3a454ca

/**
 * @brief The hash corresponding to the NtSetTimerResolution syscall.
 */
#define MDK_HASH_NtSetTimerResolution 0xbf620570

/**
 * @brief The hash corresponding to the NtQueryPerformanceCounter syscall.
 */
#define MDK_HASH_NtQueryPerformanceCounter 0x4e0c5d97

/**
 * @brief The hash corresponding to the NtAllocateLocallyUniqueId syscall.
 */
#define MDK_HASH_NtAllocateLocallyUniqueId 0x7aed5d8

/**
 * @brief The hash corresponding to the NtSetUuidSeed syscall.
 */
#define MDK_HASH_NtSetUuidSeed 0xfa8b2fd3

/**
 * @brief The hash corresponding to the NtAllocateUuids syscall.
 */
#define MDK_HASH_NtAllocateUuids 0xa09b9eae

/**
 * @brief The hash corresponding to the NtCreateEvent syscall.
 */
#define MDK_HASH_NtCreateEvent 0x3ae77545

/**
 * @brief The hash corresponding to the NtOpenEvent syscall.
 */
#define MDK_HASH_NtOpenEvent 0x30bbec03

/**
 * @brief The hash corresponding to the NtSetEvent syscall.
 */
#define MDK_HASH_NtSetEvent 0xd9b38ecd

/**
 * @brief The hash corresponding to the NtResetEvent syscall.
 */
#define MDK_HASH_NtResetEvent 0xc5da0634

/**
 * @brief The hash corresponding to the NtClearEvent syscall.
 */
#define MDK_HASH_NtClearEvent 0xb4bdaba8

/**
 * @brief The hash corresponding to the NtQueryQuotaInformationFile syscall.
 */
#define MDK_HASH_NtQueryQuotaInformationFile 0xeff1e955

/**
 * @brief The hash corresponding to the NtQueryVolumeInformationFile syscall.
 */
#define MDK_HASH_NtQueryVolumeInformationFile 0xcc20d123

/**
 * @brief The hash corresponding to the NtCreateKey syscall.
 */
#define MDK_HASH_NtCreateKey 0x75c56bfc

/**
 * @brief The hash corresponding to the NtCreateKeyTransacted syscall.
 */
#define MDK_HASH_NtCreateKeyTransacted 0x6ce6b215

/**
 * @brief The hash corresponding to the NtOpenKey syscall.
 */
#define MDK_HASH_NtOpenKey 0x64b6bb3a

/**
 * @brief The hash corresponding to the NtOpenKeyTransacted syscall.
 */
#define MDK_HASH_NtOpenKeyTransacted 0x36d8fd3

/**
 * @brief The hash corresponding to the NtOpenKeyEx syscall.
 */
#define MDK_HASH_NtOpenKeyEx 0x30c71887

/**
 * @brief The hash corresponding to the NtOpenKeyTransactedEx syscall.
 */
#define MDK_HASH_NtOpenKeyTransactedEx 0xdd02afd0

/**
 * @brief The hash corresponding to the NtDeleteKey syscall.
 */
#define MDK_HASH_NtDeleteKey 0x13767c9b

/**
 * @brief The hash corresponding to the NtRenameKey syscall.
 */
#define MDK_HASH_NtRenameKey 0xe205d210

/**
 * @brief The hash corresponding to the NtDeleteValueKey syscall.
 */
#define MDK_HASH_NtDeleteValueKey 0xed4482f8

/**
 * @brief The hash corresponding to the NtQueryKey syscall.
 */
#define MDK_HASH_NtQueryKey 0xb2a3c3de

/**
 * @brief The hash corresponding to the NtSetInformationKey syscall.
 */
#define MDK_HASH_NtSetInformationKey 0x83d67afa

/**
 * @brief The hash corresponding to the NtQueryValueKey syscall.
 */
#define MDK_HASH_NtQueryValueKey 0x97a2275b

/**
 * @brief The hash corresponding to the NtSetValueKey syscall.
 */
#define MDK_HASH_NtSetValueKey 0xcb944041

/**
 * @brief The hash corresponding to the NtQueryMultipleValueKey syscall.
 */
#define MDK_HASH_NtQueryMultipleValueKey 0x8f2c2877

/**
 * @brief The hash corresponding to the NtEnumerateKey syscall.
 */
#define MDK_HASH_NtEnumerateKey 0x5fbedf0e

/**
 * @brief The hash corresponding to the NtEnumerateValueKey syscall.
 */
#define MDK_HASH_NtEnumerateValueKey 0xc6be108b

/**
 * @brief The hash corresponding to the NtFlushKey syscall.
 */
#define MDK_HASH_NtFlushKey 0xf866cb2a

/**
 * @brief The hash corresponding to the NtCompactKeys syscall.
 */
#define MDK_HASH_NtCompactKeys 0xcc0b5032

/**
 * @brief The hash corresponding to the NtCompressKey syscall.
 */
#define MDK_HASH_NtCompressKey 0xed4d97a4

/**
 * @brief The hash corresponding to the NtLoadKey syscall.
 */
#define MDK_HASH_NtLoadKey 0x9ec566e8

/**
 * @brief The hash corresponding to the NtLoadKey2 syscall.
 */
#define MDK_HASH_NtLoadKey2 0x392314ba

/**
 * @brief The hash corresponding to the NtLoadKeyEx syscall.
 */
#define MDK_HASH_NtLoadKeyEx 0x9fcbcbb5

/**
 * @brief The hash corresponding to the NtReplaceKey syscall.
 */
#define MDK_HASH_NtReplaceKey 0x13b55d94

/**
 * @brief The hash corresponding to the NtSaveKey syscall.
 */
#define MDK_HASH_NtSaveKey 0x9aa97987

/**
 * @brief The hash corresponding to the NtSaveKeyEx syscall.
 */
#define MDK_HASH_NtSaveKeyEx 0x369d6284

/**
 * @brief The hash corresponding to the NtSaveMergedKeys syscall.
 */
#define MDK_HASH_NtSaveMergedKeys 0x1751a5e

/**
 * @brief The hash corresponding to the NtRestoreKey syscall.
 */
#define MDK_HASH_NtRestoreKey 0x5de44e8c

/**
 * @brief The hash corresponding to the NtUnloadKey syscall.
 */
#define MDK_HASH_NtUnloadKey 0x33e5364b

/**
 * @brief The hash corresponding to the NtUnloadKey2 syscall.
 */
#define MDK_HASH_NtUnloadKey2 0x49c930bd

/**
 * @brief The hash corresponding to the NtUnloadKeyEx syscall.
 */
#define MDK_HASH_NtUnloadKeyEx 0xc99e1448

/**
 * @brief The hash corresponding to the NtNotifyChangeKey syscall.
 */
#define MDK_HASH_NtNotifyChangeKey 0x46cf8737

/**
 * @brief The hash corresponding to the NtNotifyChangeMultipleKeys syscall.
 */
#define MDK_HASH_NtNotifyChangeMultipleKeys 0xcc577d16

/**
 * @brief The hash corresponding to the NtQueryOpenSubKeys syscall.
 */
#define MDK_HASH_NtQueryOpenSubKeys 0x30b39eed

/**
 * @brief The hash corresponding to the NtQueryOpenSubKeysEx syscall.
 */
#define MDK_HASH_NtQueryOpenSubKeysEx 0xf1a81d6a

/**
 * @brief The hash corresponding to the NtInitializeRegistry syscall.
 */
#define MDK_HASH_NtInitializeRegistry 0x5a747ca

/**
 * @brief The hash corresponding to the NtLockRegistryKey syscall.
 */
#define MDK_HASH_NtLockRegistryKey 0x431258aa

/**
 * @brief The hash corresponding to the NtLockProductActivationKeys syscall.
 */
#define MDK_HASH_NtLockProductActivationKeys 0xdd1cffe7

/**
 * @brief The hash corresponding to the NtFreezeRegistry syscall.
 */
#define MDK_HASH_NtFreezeRegistry 0xa7f77679

/**
 * @brief The hash corresponding to the NtThawRegistry syscall.
 */
#define MDK_HASH_NtThawRegistry 0x79b81d4c

/**
 * @brief The hash corresponding to the NtDelayExecution syscall.
 */
#define MDK_HASH_NtDelayExecution 0xe79d60d2

/**
 * @brief The hash corresponding to the NtCallbackReturn syscall.
 */
#define MDK_HASH_NtCallbackReturn 0x856283cc

/**
 * @brief The hash corresponding to the NtFlushProcessWriteBuffers syscall.
 */
#define MDK_HASH_NtFlushProcessWriteBuffers 0xea726cb8

/**
 * @brief The hash corresponding to the NtQueryDebugFilterState syscall.
 */
#define MDK_HASH_NtQueryDebugFilterState 0xfc9d91d3

/**
 * @brief The hash corresponding to the NtSetDebugFilterState syscall.
 */
#define MDK_HASH_NtSetDebugFilterState 0x610e74b9

/**
 * @brief The hash corresponding to the NtRemoveProcessDebug syscall.
 */
#define MDK_HASH_NtRemoveProcessDebug 0x2f41d3c3

/**
 * @brief The hash corresponding to the NtWaitForDebugEvent syscall.
 */
#define MDK_HASH_NtWaitForDebugEvent 0x4b0fcf94

/**
 * @brief The hash corresponding to the NtDebugContinue syscall.
 */
#define MDK_HASH_NtDebugContinue 0x7909e98b

/**
 * @brief The hash corresponding to the NtSetInformationDebugObject syscall.
 */
#define MDK_HASH_NtSetInformationDebugObject 0x5812ce2f

/**
 * @brief The hash corresponding to the NtOpenProcessToken syscall.
 */
#define MDK_HASH_NtOpenProcessToken 0x27399ce1

/**
 * @brief The hash corresponding to the NtOpenProcessTokenEx syscall.
 */
#define MDK_HASH_NtOpenProcessTokenEx 0xbd9e886e

/**
 * @brief The hash corresponding to the NtOpenThreadToken syscall.
 */
#define MDK_HASH_NtOpenThreadToken 0x920711aa

/**
 * @brief The hash corresponding to the NtOpenThreadTokenEx syscall.
 */
#define MDK_HASH_NtOpenThreadTokenEx 0x4810dbf7

/**
 * @brief The hash corresponding to the NtCreateToken syscall.
 */
#define MDK_HASH_NtCreateToken 0x3bea8204

/**
 * @brief The hash corresponding to the NtDuplicateToken syscall.
 */
#define MDK_HASH_NtDuplicateToken 0x9c225d5b

/**
 * @brief The hash corresponding to the NtQueryInformationToken syscall.
 */
#define MDK_HASH_NtQueryInformationToken 0x1d03499c

/**
 * @brief The hash corresponding to the NtAdjustPrivilegesToken syscall.
 */
#define MDK_HASH_NtAdjustPrivilegesToken 0x3f882515

/**
 * @brief The hash corresponding to the NtAdjustGroupsToken syscall.
 */
#define MDK_HASH_NtAdjustGroupsToken 0xfb8f0d6b

/**
 * @brief The hash corresponding to the NtFilterToken syscall.
 */
#define MDK_HASH_NtFilterToken 0xfbbd68d6

/**
 * @brief The hash corresponding to the NtSetInformationToken syscall.
 */
#define MDK_HASH_NtSetInformationToken 0x81f32c82

/**
 * @brief The hash corresponding to the NtCompareTokens syscall.
 */
#define MDK_HASH_NtCompareTokens 0xc6c3789a

/**
 * @brief The hash corresponding to the NtPrivilegeCheck syscall.
 */
#define MDK_HASH_NtPrivilegeCheck 0x375998b4

/**
 * @brief The hash corresponding to the NtImpersonateAnonymousToken syscall.
 */
#define MDK_HASH_NtImpersonateAnonymousToken 0xd34f1160

/**
 * @brief The hash corresponding to the NtQuerySecurityAttributesToken syscall.
 */
#define MDK_HASH_NtQuerySecurityAttributesToken 0xe781f7c5

/**
 * @brief The hash corresponding to the NtAccessCheck syscall.
 */
#define MDK_HASH_NtAccessCheck 0x6f3f93ef

/**
 * @brief The hash corresponding to the NtAccessCheckByType syscall.
 */
#define MDK_HASH_NtAccessCheckByType 0x6027b84c

/**
 * @brief The hash corresponding to the NtAccessCheckByTypeResultList syscall.
 */
#define MDK_HASH_NtAccessCheckByTypeResultList 0x2fdc3cf7

/**
 * @brief The hash corresponding to the NtCreateIoCompletion syscall.
 */
#define MDK_HASH_NtCreateIoCompletion 0xd09327d5

/**
 * @brief The hash corresponding to the NtOpenIoCompletion syscall.
 */
#define MDK_HASH_NtOpenIoCompletion 0xef51e153

/**
 * @brief The hash corresponding to the NtQueryIoCompletion syscall.
 */
#define MDK_HASH_NtQueryIoCompletion 0x536c4677

/**
 * @brief The hash corresponding to the NtSetIoCompletion syscall.
 */
#define MDK_HASH_NtSetIoCompletion 0xf0e065d

/**
 * @brief The hash corresponding to the NtSetIoCompletionEx syscall.
 */
#define MDK_HASH_NtSetIoCompletionEx 0x473aa0da

/**
 * @brief The hash corresponding to the NtRemoveIoCompletion syscall.
 */
#define MDK_HASH_NtRemoveIoCompletion 0x14c0cc1f

/**
 * @brief The hash corresponding to the NtRemoveIoCompletionEx syscall.
 */
#define MDK_HASH_NtRemoveIoCompletionEx 0x84b08f1c

/**
 * @brief The hash corresponding to the NtCreateWaitCompletionPacket syscall.
 */
#define MDK_HASH_NtCreateWaitCompletionPacket 0xf603e01a

/**
 * @brief The hash corresponding to the NtAssociateWaitCompletionPacket syscall.
 */
#define MDK_HASH_NtAssociateWaitCompletionPacket 0x3b520132

/**
 * @brief The hash corresponding to the NtCancelWaitCompletionPacket syscall.
 */
#define MDK_HASH_NtCancelWaitCompletionPacket 0xde494eac

/**
 * @brief The hash corresponding to the NtNotifyChangeSession syscall.
 */
#define MDK_HASH_NtNotifyChangeSession 0x9f91ae32

/**
 * @brief The hash corresponding to the NtCreateMutant syscall.
 */
#define MDK_HASH_NtCreateMutant 0x47e2ef2c

/**
 * @brief The hash corresponding to the NtOpenMutant syscall.
 */
#define MDK_HASH_NtOpenMutant 0x95126e2a

/**
 * @brief The hash corresponding to the NtReleaseMutant syscall.
 */
#define MDK_HASH_NtReleaseMutant 0xaea11999

/**
 * @brief The hash corresponding to the NtAlertThread syscall.
 */
#define MDK_HASH_NtAlertThread 0xcb5ebaef

/**
 * @brief The hash corresponding to the NtAlertResumeThread syscall.
 */
#define MDK_HASH_NtAlertResumeThread 0x49954850

/**
 * @brief The hash corresponding to the NtTestAlert syscall.
 */
#define MDK_HASH_NtTestAlert 0x97be64a7

/**
 * @brief The hash corresponding to the NtImpersonateThread syscall.
 */
#define MDK_HASH_NtImpersonateThread 0x213f3fe

/**
 * @brief The hash corresponding to the NtCreateSemaphore syscall.
 */
#define MDK_HASH_NtCreateSemaphore 0xddfe98a7

/**
 * @brief The hash corresponding to the NtOpenSemaphore syscall.
 */
#define MDK_HASH_NtOpenSemaphore 0xea688365

/**
 * @brief The hash corresponding to the NtReleaseSemaphore syscall.
 */
#define MDK_HASH_NtReleaseSemaphore 0xea62a034

/**
 * @brief The hash corresponding to the NtQuerySemaphore syscall.
 */
#define MDK_HASH_NtQuerySemaphore 0xb93b6ef9

/**
 * @brief The hash corresponding to the NtCreateTimer syscall.
 */
#define MDK_HASH_NtCreateTimer 0x3befc4c4

/**
 * @brief The hash corresponding to the NtOpenTimer syscall.
 */
#define MDK_HASH_NtOpenTimer 0x31ac7f82

/**
 * @brief The hash corresponding to the NtSetTimer syscall.
 */
#define MDK_HASH_NtSetTimer 0xdea41e4c

/**
 * @brief The hash corresponding to the NtSetTimerEx syscall.
 */
#define MDK_HASH_NtSetTimerEx 0x23f77809

/**
 * @brief The hash corresponding to the NtCancelTimer syscall.
 */
#define MDK_HASH_NtCancelTimer 0x71824916

/**
 * @brief The hash corresponding to the NtQueryTimer syscall.
 */
#define MDK_HASH_NtQueryTimer 0x374c2d26

/**
 * @brief The hash corresponding to the NtCreateKeyedEvent syscall.
 */
#define MDK_HASH_NtCreateKeyedEvent 0xc1aa2977

/**
 * @brief The hash corresponding to the NtOpenKeyedEvent syscall.
 */
#define MDK_HASH_NtOpenKeyedEvent 0x1c451b75

/**
 * @brief The hash corresponding to the NtReleaseKeyedEvent syscall.
 */
#define MDK_HASH_NtReleaseKeyedEvent 0x1f9bc264

/**
 * @brief The hash corresponding to the NtWaitForKeyedEvent syscall.
 */
#define MDK_HASH_NtWaitForKeyedEvent 0xcaf83a6f

/**
 * @brief The hash corresponding to the NtUmsThreadYield syscall.
 */
#define MDK_HASH_NtUmsThreadYield 0x95ec7573

/**
 * @brief The hash corresponding to the NtCreateTransactionManager syscall.
 */
#define MDK_HASH_NtCreateTransactionManager 0x4ec09684

/**
 * @brief The hash corresponding to the NtOpenTransactionManager syscall.
 */
#define MDK_HASH_NtOpenTransactionManager 0x9188fa82

/**
 * @brief The hash corresponding to the NtRenameTransactionManager syscall.
 */
#define MDK_HASH_NtRenameTransactionManager 0xd6d25518

/**
 * @brief The hash corresponding to the NtRollforwardTransactionManager syscall.
 */
#define MDK_HASH_NtRollforwardTransactionManager 0xe7bfa3ae

/**
 * @brief The hash corresponding to the NtRecoverTransactionManager syscall.
 */
#define MDK_HASH_NtRecoverTransactionManager 0xd4c4b66

/**
 * @brief The hash corresponding to the NtQueryInformationTransactionManager syscall.
 */
#define MDK_HASH_NtQueryInformationTransactionManager 0x672031c

/**
 * @brief The hash corresponding to the NtSetInformationTransactionManager syscall.
 */
#define MDK_HASH_NtSetInformationTransactionManager 0x7ce3d242

/**
 * @brief The hash corresponding to the NtEnumerateTransactionObject syscall.
 */
#define MDK_HASH_NtEnumerateTransactionObject 0xe25eb1d2

/**
 * @brief The hash corresponding to the NtCreateTransaction syscall.
 */
#define MDK_HASH_NtCreateTransaction 0x14d11479

/**
 * @brief The hash corresponding to the NtOpenTransaction syscall.
 */
#define MDK_HASH_NtOpenTransaction 0x8e2599c7

/**
 * @brief The hash corresponding to the NtQueryInformationTransaction syscall.
 */
#define MDK_HASH_NtQueryInformationTransaction 0x31862d11

/**
 * @brief The hash corresponding to the NtSetInformationTransaction syscall.
 */
#define MDK_HASH_NtSetInformationTransaction 0x77681887

/**
 * @brief The hash corresponding to the NtCommitTransaction syscall.
 */
#define MDK_HASH_NtCommitTransaction 0x2a85546e

/**
 * @brief The hash corresponding to the NtRollbackTransaction syscall.
 */
#define MDK_HASH_NtRollbackTransaction 0xc7a68a8f

/**
 * @brief The hash corresponding to the NtCreateEnlistment syscall.
 */
#define MDK_HASH_NtCreateEnlistment 0x3e6c4006

/**
 * @brief The hash corresponding to the NtOpenEnlistment syscall.
 */
#define MDK_HASH_NtOpenEnlistment 0x751eb204

/**
 * @brief The hash corresponding to the NtQueryInformationEnlistment syscall.
 */
#define MDK_HASH_NtQueryInformationEnlistment 0x1c1b949e

/**
 * @brief The hash corresponding to the NtSetInformationEnlistment syscall.
 */
#define MDK_HASH_NtSetInformationEnlistment 0x77b62dc4

/**
 * @brief The hash corresponding to the NtRecoverEnlistment syscall.
 */
#define MDK_HASH_NtRecoverEnlistment 0x86ae26d8

/**
 * @brief The hash corresponding to the NtPrePrepareEnlistment syscall.
 */
#define MDK_HASH_NtPrePrepareEnlistment 0x11d4de98

/**
 * @brief The hash corresponding to the NtPrepareEnlistment syscall.
 */
#define MDK_HASH_NtPrepareEnlistment 0xd1772641

/**
 * @brief The hash corresponding to the NtCommitEnlistment syscall.
 */
#define MDK_HASH_NtCommitEnlistment 0x98c5f18b

/**
 * @brief The hash corresponding to the NtRollbackEnlistment syscall.
 */
#define MDK_HASH_NtRollbackEnlistment 0x43977ccc

/**
 * @brief The hash corresponding to the NtPrePrepareComplete syscall.
 */
#define MDK_HASH_NtPrePrepareComplete 0x396d4eee

/**
 * @brief The hash corresponding to the NtPrepareComplete syscall.
 */
#define MDK_HASH_NtPrepareComplete 0xd7cc03d7

/**
 * @brief The hash corresponding to the NtCommitComplete syscall.
 */
#define MDK_HASH_NtCommitComplete 0x9d550091

/**
 * @brief The hash corresponding to the NtReadOnlyEnlistment syscall.
 */
#define MDK_HASH_NtReadOnlyEnlistment 0x1066b4d0

/**
 * @brief The hash corresponding to the NtRollbackComplete syscall.
 */
#define MDK_HASH_NtRollbackComplete 0x94956312

/**
 * @brief The hash corresponding to the NtSinglePhaseReject syscall.
 */
#define MDK_HASH_NtSinglePhaseReject 0xac00f7ef

/**
 * @brief The hash corresponding to the NtCreateResourceManager syscall.
 */
#define MDK_HASH_NtCreateResourceManager 0xb1bb92a6

/**
 * @brief The hash corresponding to the NtOpenResourceManager syscall.
 */
#define MDK_HASH_NtOpenResourceManager 0xe19d57e4

/**
 * @brief The hash corresponding to the NtRecoverResourceManager syscall.
 */
#define MDK_HASH_NtRecoverResourceManager 0xd69d9238

/**
 * @brief The hash corresponding to the NtGetNotificationResourceManager syscall.
 */
#define MDK_HASH_NtGetNotificationResourceManager 0x3986b709

/**
 * @brief The hash corresponding to the NtQueryInformationResourceManager syscall.
 */
#define MDK_HASH_NtQueryInformationResourceManager 0x7f9f243e

/**
 * @brief The hash corresponding to the NtSetInformationResourceManager syscall.
 */
#define MDK_HASH_NtSetInformationResourceManager 0x429576a4

/**
 * @brief The hash corresponding to the NtRegisterProtocolAddressInformation syscall.
 */
#define MDK_HASH_NtRegisterProtocolAddressInformation 0x1fe79b32

/**
 * @brief The hash corresponding to the NtPropagationComplete syscall.
 */
#define MDK_HASH_NtPropagationComplete 0xf4def9dc

/**
 * @brief The hash corresponding to the NtPropagationFailed syscall.
 */
#define MDK_HASH_NtPropagationFailed 0x265b348

/**
 * @brief The hash corresponding to the NtFreezeTransactions syscall.
 */
#define MDK_HASH_NtFreezeTransactions 0x8c5aafd9

/**
 * @brief The hash corresponding to the NtThawTransactions syscall.
 */
#define MDK_HASH_NtThawTransactions 0xc44d02c

/**
 * @brief The hash corresponding to the NtCreateWorkerFactory syscall.
 */
#define MDK_HASH_NtCreateWorkerFactory 0x997957b5

/**
 * @brief The hash corresponding to the NtQueryInformationWorkerFactory syscall.
 */
#define MDK_HASH_NtQueryInformationWorkerFactory 0x27a634d

/**
 * @brief The hash corresponding to the NtSetInformationWorkerFactory syscall.
 */
#define MDK_HASH_NtSetInformationWorkerFactory 0x718f1033

/**
 * @brief The hash corresponding to the NtShutdownWorkerFactory syscall.
 */
#define MDK_HASH_NtShutdownWorkerFactory 0x7623f1cd

/**
 * @brief The hash corresponding to the NtReleaseWorkerFactoryWorker syscall.
 */
#define MDK_HASH_NtReleaseWorkerFactoryWorker 0xa2374f6c

/**
 * @brief The hash corresponding to the NtWorkerFactoryWorkerReady syscall.
 */
#define MDK_HASH_NtWorkerFactoryWorkerReady 0xf751ca10

/**
 * @brief The hash corresponding to the NtWaitForWorkViaWorkerFactory syscall.
 */
#define MDK_HASH_NtWaitForWorkViaWorkerFactory 0xe8913ba0

/**
 * @brief The hash corresponding to the ZwWaitForWorkViaWorkerFactory syscall.
 */
#define MDK_HASH_ZwWaitForWorkViaWorkerFactory 0x99fc207f

/**
 * @brief The hash corresponding to the NtQuerySystemEnvironmentValue syscall.
 */
#define MDK_HASH_NtQuerySystemEnvironmentValue 0x575769ac

/**
 * @brief The hash corresponding to the NtSetSystemEnvironmentValue syscall.
 */
#define MDK_HASH_NtSetSystemEnvironmentValue 0x95394512

/**
 * @brief The hash corresponding to the NtQuerySystemEnvironmentValueEx syscall.
 */
#define MDK_HASH_NtQuerySystemEnvironmentValueEx 0x3906d869

/**
 * @brief The hash corresponding to the NtSetSystemEnvironmentValueEx syscall.
 */
#define MDK_HASH_NtSetSystemEnvironmentValueEx 0x6cabc95f

/**
 * @brief The hash corresponding to the NtEnumerateSystemEnvironmentValuesEx syscall.
 */
#define MDK_HASH_NtEnumerateSystemEnvironmentValuesEx 0xf30cef0c

/**
 * @brief The hash corresponding to the NtAddBootEntry syscall.
 */
#define MDK_HASH_NtAddBootEntry 0x9ec8910e

/**
 * @brief The hash corresponding to the NtDeleteBootEntry syscall.
 */
#define MDK_HASH_NtDeleteBootEntry 0xb633f0b8

/**
 * @brief The hash corresponding to the NtModifyBootEntry syscall.
 */
#define MDK_HASH_NtModifyBootEntry 0x12970f2d

/**
 * @brief The hash corresponding to the NtEnumerateBootEntries syscall.
 */
#define MDK_HASH_NtEnumerateBootEntries 0x7ff30b03

/**
 * @brief The hash corresponding to the NtQueryBootEntryOrder syscall.
 */
#define MDK_HASH_NtQueryBootEntryOrder 0x9e948c87

/**
 * @brief The hash corresponding to the NtSetBootEntryOrder syscall.
 */
#define MDK_HASH_NtSetBootEntryOrder 0xf8272eed

/**
 * @brief The hash corresponding to the NtQueryBootOptions syscall.
 */
#define MDK_HASH_NtQueryBootOptions 0x22d523c5

/**
 * @brief The hash corresponding to the NtSetBootOptions syscall.
 */
#define MDK_HASH_NtSetBootOptions 0x5ce55d6b

/**
 * @brief The hash corresponding to the NtTranslateFilePath syscall.
 */
#define MDK_HASH_NtTranslateFilePath 0xffd2513a

/**
 * @brief The hash corresponding to the NtAddDriverEntry syscall.
 */
#define MDK_HASH_NtAddDriverEntry 0xee35c3d6

/**
 * @brief The hash corresponding to the NtDeleteDriverEntry syscall.
 */
#define MDK_HASH_NtDeleteDriverEntry 0x13753900

/**
 * @brief The hash corresponding to the NtModifyDriverEntry syscall.
 */
#define MDK_HASH_NtModifyDriverEntry 0xe1a04d35

/**
 * @brief The hash corresponding to the NtEnumerateDriverEntries syscall.
 */
#define MDK_HASH_NtEnumerateDriverEntries 0x2e58b28b

/**
 * @brief The hash corresponding to the NtQueryDriverEntryOrder syscall.
 */
#define MDK_HASH_NtQueryDriverEntryOrder 0xc55f4d0f

/**
 * @brief The hash corresponding to the NtSetDriverEntryOrder syscall.
 */
#define MDK_HASH_NtSetDriverEntryOrder 0x49cf20f5

/**
 * @brief The hash corresponding to the NtSerializeBoot syscall.
 */
#define MDK_HASH_NtSerializeBoot 0x5bab53b

/**
 * @brief The hash corresponding to the NtEnableLastKnownGood syscall.
 */
#define MDK_HASH_NtEnableLastKnownGood 0x7367f600

/**
 * @brief The hash corresponding to the NtDisableLastKnownGood syscall.
 */
#define MDK_HASH_NtDisableLastKnownGood 0xdd2e88bd

/**
 * @brief The hash corresponding to the DbgPrint syscall.
 */
#define MDK_HASH_DbgPrint 0xd313f207

/**
 * @brief The hash corresponding to the DbgPrintEx syscall.
 */
#define MDK_HASH_DbgPrintEx 0xbb969f04

/**
 * @brief The hash corresponding to the DbgBreakPoint syscall.
 */
#define MDK_HASH_DbgBreakPoint 0x74669639

/**
 * @brief The hash corresponding to the DbgUiConnectToDbg syscall.
 */
#define MDK_HASH_DbgUiConnectToDbg 0x91f1cab2

/**
 * @brief The hash corresponding to the DbgUiGetThreadDebugObject syscall.
 */
#define MDK_HASH_DbgUiGetThreadDebugObject 0x14501e

/**
 * @brief The hash corresponding to the DbgUiSetThreadDebugObject syscall.
 */
#define MDK_HASH_DbgUiSetThreadDebugObject 0xb1c2648a

/**
 * @brief The hash corresponding to the DbgUiWaitStateChange syscall.
 */
#define MDK_HASH_DbgUiWaitStateChange 0x1155db74

/**
 * @brief The hash corresponding to the DbgUiContinue syscall.
 */
#define MDK_HASH_DbgUiContinue 0xed1f8b4d

/**
 * @brief The hash corresponding to the DbgUiStopDebugging syscall.
 */
#define MDK_HASH_DbgUiStopDebugging 0x62e5c21a

/**
 * @brief The hash corresponding to the DbgUiDebugActiveProcess syscall.
 */
#define MDK_HASH_DbgUiDebugActiveProcess 0xd081b88a

/**
 * @brief The hash corresponding to the DbgUiRemoteBreakin syscall.
 */
#define MDK_HASH_DbgUiRemoteBreakin 0x67386f20

/**
 * @brief The hash corresponding to the DbgUiIssueRemoteBreakin syscall.
 */
#define MDK_HASH_DbgUiIssueRemoteBreakin 0xd690fcf9

/**
 * @brief The hash corresponding to the DbgUiConvertStateChangeStructure syscall.
 */
#define MDK_HASH_DbgUiConvertStateChangeStructure 0xcc01f031

/**
 * @brief The hash corresponding to the LdrLoadDll syscall.
 */
#define MDK_HASH_LdrLoadDll 0x8c713c3b

/**
 * @brief The hash corresponding to the LdrGetDllHandle syscall.
 */
#define MDK_HASH_LdrGetDllHandle 0xa25c0e37

/**
 * @brief The hash corresponding to the LdrGetDllHandleEx syscall.
 */
#define MDK_HASH_LdrGetDllHandleEx 0x79ebe734

/**
 * @brief The hash corresponding to the LdrGetDllHandleByMapping syscall.
 */
#define MDK_HASH_LdrGetDllHandleByMapping 0x640af26e

/**
 * @brief The hash corresponding to the LdrGetDllHandleByName syscall.
 */
#define MDK_HASH_LdrGetDllHandleByName 0xd6d9ac53

/**
 * @brief The hash corresponding to the LdrGetProcedureAddress syscall.
 */
#define MDK_HASH_LdrGetProcedureAddress 0xeed33dce

/**
 * @brief The hash corresponding to the LdrGetProcedureAddressEx syscall.
 */
#define MDK_HASH_LdrGetProcedureAddressEx 0xc6456c0b

/**
 * @brief The hash corresponding to the LdrLockLoaderLock syscall.
 */
#define MDK_HASH_LdrLockLoaderLock 0xdff96ae8

/**
 * @brief The hash corresponding to the LdrUnlockLoaderLock syscall.
 */
#define MDK_HASH_LdrUnlockLoaderLock 0xee5468ab

/**
 * @brief The hash corresponding to the LdrProcessRelocationBlock syscall.
 */
#define MDK_HASH_LdrProcessRelocationBlock 0xa5d9d139

/**
 * @brief The hash corresponding to the LdrUnloadDll syscall.
 */
#define MDK_HASH_LdrUnloadDll 0xcba1979e

/**
 * @brief The hash corresponding to the LdrDisableThreadCalloutsForDll syscall.
 */
#define MDK_HASH_LdrDisableThreadCalloutsForDll 0xd915f9a5

/**
 * @brief The hash corresponding to the LdrOpenImageFileOptionsKey syscall.
 */
#define MDK_HASH_LdrOpenImageFileOptionsKey 0xceeb4689

/**
 * @brief The hash corresponding to the LdrQueryImageFileKeyOption syscall.
 */
#define MDK_HASH_LdrQueryImageFileKeyOption 0x904bce5a

/**
 * @brief The hash corresponding to the LdrVerifyImageMatchesChecksum syscall.
 */
#define MDK_HASH_LdrVerifyImageMatchesChecksum 0x86a5906f

/**
 * @brief The hash corresponding to the LdrVerifyImageMatchesChecksumEx syscall.
 */
#define MDK_HASH_LdrVerifyImageMatchesChecksumEx 0x122fe76c

/**
 * @brief The hash corresponding to the LdrAccessResource syscall.
 */
#define MDK_HASH_LdrAccessResource 0x67424e59

/**
 * @brief The hash corresponding to the RtlAssert syscall.
 */
#define MDK_HASH_RtlAssert 0x2dbcc0d1

/**
 * @brief The hash corresponding to the RtlRaiseStatus syscall.
 */
#define MDK_HASH_RtlRaiseStatus 0xa2f44ed7

/**
 * @brief The hash corresponding to the RtlRaiseException syscall.
 */
#define MDK_HASH_RtlRaiseException 0xdd14c8c2

/**
 * @brief The hash corresponding to the RtlConnectToSm syscall.
 */
#define MDK_HASH_RtlConnectToSm 0x8ef6179c

/**
 * @brief The hash corresponding to the RtlSendMsgToSm syscall.
 */
#define MDK_HASH_RtlSendMsgToSm 0x9fe9d13

/**
 * @brief The hash corresponding to the RtlRegisterThreadWithCsrss syscall.
 */
#define MDK_HASH_RtlRegisterThreadWithCsrss 0xbefbc626

/**
 * @brief The hash corresponding to the RtlEnterCriticalSection syscall.
 */
#define MDK_HASH_RtlEnterCriticalSection 0x4bba8d8d

/**
 * @brief The hash corresponding to the RtlLeaveCriticalSection syscall.
 */
#define MDK_HASH_RtlLeaveCriticalSection 0x3f2043fc

/**
 * @brief The hash corresponding to the RtlIsCriticalSectionLocked syscall.
 */
#define MDK_HASH_RtlIsCriticalSectionLocked 0x5ff5f39d

/**
 * @brief The hash corresponding to the RtlIsCriticalSectionLockedByThread syscall.
 */
#define MDK_HASH_RtlIsCriticalSectionLockedByThread 0x4e224c20

/**
 * @brief The hash corresponding to the RtlGetCriticalSectionRecursionCount syscall.
 */
#define MDK_HASH_RtlGetCriticalSectionRecursionCount 0x68920142

/**
 * @brief The hash corresponding to the RtlTryEnterCriticalSection syscall.
 */
#define MDK_HASH_RtlTryEnterCriticalSection 0x2d9c702c

/**
 * @brief The hash corresponding to the RtlInitializeCriticalSection syscall.
 */
#define MDK_HASH_RtlInitializeCriticalSection 0x88388971

/**
 * @brief The hash corresponding to the RtlEnableEarlyCriticalSectionEventCreation syscall.
 */
#define MDK_HASH_RtlEnableEarlyCriticalSectionEventCreation 0xe9769b2a

/**
 * @brief The hash corresponding to the RtlInitializeCriticalSectionAndSpinCount syscall.
 */
#define MDK_HASH_RtlInitializeCriticalSectionAndSpinCount 0x1b916867

/**
 * @brief The hash corresponding to the RtlSetCriticalSectionSpinCount syscall.
 */
#define MDK_HASH_RtlSetCriticalSectionSpinCount 0x32022ede

/**
 * @brief The hash corresponding to the RtlDeleteCriticalSection syscall.
 */
#define MDK_HASH_RtlDeleteCriticalSection 0xf6352032

/**
 * @brief The hash corresponding to the RtlQueryPerformanceFrequency syscall.
 */
#define MDK_HASH_RtlQueryPerformanceFrequency 0x879e19a9

/**
 * @brief The hash corresponding to the RtlQueryPerformanceCounter syscall.
 */
#define MDK_HASH_RtlQueryPerformanceCounter 0x80b66a67

/**
 * @brief The hash corresponding to the RtlGetCompressionWorkSpaceSize syscall.
 */
#define MDK_HASH_RtlGetCompressionWorkSpaceSize 0x2fdf038b

/**
 * @brief The hash corresponding to the RtlCompressBuffer syscall.
 */
#define MDK_HASH_RtlCompressBuffer 0x534a36c5

/**
 * @brief The hash corresponding to the RtlDecompressBuffer syscall.
 */
#define MDK_HASH_RtlDecompressBuffer 0x59f713e

/**
 * @brief The hash corresponding to the RtlDecompressBufferEx syscall.
 */
#define MDK_HASH_RtlDecompressBufferEx 0xbd264c7b

/**
 * @brief The hash corresponding to the RtlDecompressBufferEx2 syscall.
 */
#define MDK_HASH_RtlDecompressBufferEx2 0x83610ced

/**
 * @brief The hash corresponding to the RtlDecompressFragment syscall.
 */
#define MDK_HASH_RtlDecompressFragment 0x7fa367f8

/**
 * @brief The hash corresponding to the RtlDecompressFragmentEx syscall.
 */
#define MDK_HASH_RtlDecompressFragmentEx 0x221dccc5

/**
 * @brief The hash corresponding to the RtlDescribeChunk syscall.
 */
#define MDK_HASH_RtlDescribeChunk 0x82cf5b89

/**
 * @brief The hash corresponding to the RtlReserveChunk syscall.
 */
#define MDK_HASH_RtlReserveChunk 0x790c1754

/**
 * @brief The hash corresponding to the RtlDecompressChunks syscall.
 */
#define MDK_HASH_RtlDecompressChunks 0xb293ba0

/**
 * @brief The hash corresponding to the RtlCompressChunks syscall.
 */
#define MDK_HASH_RtlCompressChunks 0x50c4f137

/**
 * @brief The hash corresponding to the RtlCreateHeap syscall.
 */
#define MDK_HASH_RtlCreateHeap 0xf39b3e31

/**
 * @brief The hash corresponding to the RtlDestroyHeap syscall.
 */
#define MDK_HASH_RtlDestroyHeap 0xdc8162e7

/**
 * @brief The hash corresponding to the RtlAllocateHeap syscall.
 */
#define MDK_HASH_RtlAllocateHeap 0x29dd1a22

/**
 * @brief The hash corresponding to the RtlFreeHeap syscall.
 */
#define MDK_HASH_RtlFreeHeap 0x619db2af

/**
 * @brief The hash corresponding to the RtlWalkHeap syscall.
 */
#define MDK_HASH_RtlWalkHeap 0xa1ff81c

/**
 * @brief The hash corresponding to the RtlQueryHeapInformation syscall.
 */
#define MDK_HASH_RtlQueryHeapInformation 0x9711c289

/**
 * @brief The hash corresponding to the RtlSetHeapInformation syscall.
 */
#define MDK_HASH_RtlSetHeapInformation 0x45facf3f

/**
 * @brief The hash corresponding to the RtlSizeHeap syscall.
 */
#define MDK_HASH_RtlSizeHeap 0xfd05b0c8

/**
 * @brief The hash corresponding to the RtlZeroHeap syscall.
 */
#define MDK_HASH_RtlZeroHeap 0xd1523ad

/**
 * @brief The hash corresponding to the RtlProtectHeap syscall.
 */
#define MDK_HASH_RtlProtectHeap 0x7ea3800e

/**
 * @brief The hash corresponding to the RtlLockHeap syscall.
 */
#define MDK_HASH_RtlLockHeap 0x3c3be6

/**
 * @brief The hash corresponding to the RtlUnlockHeap syscall.
 */
#define MDK_HASH_RtlUnlockHeap 0xce888bd9

/**
 * @brief The hash corresponding to the RtlReAllocateHeap syscall.
 */
#define MDK_HASH_RtlReAllocateHeap 0xbd405509

/**
 * @brief The hash corresponding to the RtlGetUserInfoHeap syscall.
 */
#define MDK_HASH_RtlGetUserInfoHeap 0xfdb3578

/**
 * @brief The hash corresponding to the RtlSetUserValueHeap syscall.
 */
#define MDK_HASH_RtlSetUserValueHeap 0x26cf1405

/**
 * @brief The hash corresponding to the RtlSetUserFlagsHeap syscall.
 */
#define MDK_HASH_RtlSetUserFlagsHeap 0xb7a88c75

/**
 * @brief The hash corresponding to the RtlCreateTagHeap syscall.
 */
#define MDK_HASH_RtlCreateTagHeap 0x117a521d

/**
 * @brief The hash corresponding to the RtlQueryTagHeap syscall.
 */
#define MDK_HASH_RtlQueryTagHeap 0x6ad81ff

/**
 * @brief The hash corresponding to the RtlCompactHeap syscall.
 */
#define MDK_HASH_RtlCompactHeap 0xdeed9044

/**
 * @brief The hash corresponding to the RtlValidateHeap syscall.
 */
#define MDK_HASH_RtlValidateHeap 0xa40f0c27

/**
 * @brief The hash corresponding to the RtlValidateProcessHeaps syscall.
 */
#define MDK_HASH_RtlValidateProcessHeaps 0xd25be209

/**
 * @brief The hash corresponding to the RtlGetProcessHeaps syscall.
 */
#define MDK_HASH_RtlGetProcessHeaps 0xf4ab25bf

/**
 * @brief The hash corresponding to the RtlEnumProcessHeaps syscall.
 */
#define MDK_HASH_RtlEnumProcessHeaps 0x42f21664

/**
 * @brief The hash corresponding to the RtlTimeToTimeFields syscall.
 */
#define MDK_HASH_RtlTimeToTimeFields 0x814dc397

/**
 * @brief The hash corresponding to the RtlUniform syscall.
 */
#define MDK_HASH_RtlUniform 0x35fdbc2f

/**
 * @brief The hash corresponding to the RtlRandom syscall.
 */
#define MDK_HASH_RtlRandom 0x77d39bc0

/**
 * @brief The hash corresponding to the RtlRandomEx syscall.
 */
#define MDK_HASH_RtlRandomEx 0x6d26728d

/**
 * @brief The hash corresponding to the RtlFindMessage syscall.
 */
#define MDK_HASH_RtlFindMessage 0x545ba925

/**
 * @brief The hash corresponding to the RtlFormatMessage syscall.
 */
#define MDK_HASH_RtlFormatMessage 0x64f4619d

/**
 * @brief The hash corresponding to the RtlNtStatusToDosError syscall.
 */
#define MDK_HASH_RtlNtStatusToDosError 0x2be39ee8

/**
 * @brief The hash corresponding to the RtlNtStatusToDosErrorNoTeb syscall.
 */
#define MDK_HASH_RtlNtStatusToDosErrorNoTeb 0xc7bf8c30

/**
 * @brief The hash corresponding to the RtlGetLastNtStatus syscall.
 */
#define MDK_HASH_RtlGetLastNtStatus 0xa20def49

/**
 * @brief The hash corresponding to the RtlGetLastWin32Error syscall.
 */
#define MDK_HASH_RtlGetLastWin32Error 0x8cdcd10

/**
 * @brief The hash corresponding to the RtlSetLastWin32ErrorAndNtStatusFromNtStatus syscall.
 */
#define MDK_HASH_RtlSetLastWin32ErrorAndNtStatusFromNtStatus 0x416c2b1f

/**
 * @brief The hash corresponding to the RtlSetLastWin32Error syscall.
 */
#define MDK_HASH_RtlSetLastWin32Error 0xef04650c

/**
 * @brief The hash corresponding to the RtlRestoreLastWin32Error syscall.
 */
#define MDK_HASH_RtlRestoreLastWin32Error 0xc27b1214

/**
 * @brief The hash corresponding to the RtlGetThreadErrorMode syscall.
 */
#define MDK_HASH_RtlGetThreadErrorMode 0xa7b90de6

/**
 * @brief The hash corresponding to the RtlSetThreadErrorMode syscall.
 */
#define MDK_HASH_RtlSetThreadErrorMode 0xcca2a352

/**
 * @brief The hash corresponding to the RtlCreateUnicodeString syscall.
 */
#define MDK_HASH_RtlCreateUnicodeString 0x88624531

/**
 * @brief The hash corresponding to the RtlUpcaseUnicodeString syscall.
 */
#define MDK_HASH_RtlUpcaseUnicodeString 0x76bd9bae

/**
 * @brief The hash corresponding to the RtlInitUnicodeString syscall.
 */
#define MDK_HASH_RtlInitUnicodeString 0xfd66e3f1

/**
 * @brief The hash corresponding to the RtlInitUnicodeStringEx syscall.
 */
#define MDK_HASH_RtlInitUnicodeStringEx 0x1ce2137e

/**
 * @brief The hash corresponding to the RtlInitAnsiString syscall.
 */
#define MDK_HASH_RtlInitAnsiString 0xb2fc1515

/**
 * @brief The hash corresponding to the RtlCopyUnicodeString syscall.
 */
#define MDK_HASH_RtlCopyUnicodeString 0x3b95f9a8

/**
 * @brief The hash corresponding to the RtlAppendUnicodeToString syscall.
 */
#define MDK_HASH_RtlAppendUnicodeToString 0x829304a8

/**
 * @brief The hash corresponding to the RtlAnsiStringToUnicodeString syscall.
 */
#define MDK_HASH_RtlAnsiStringToUnicodeString 0x7e543ac2

/**
 * @brief The hash corresponding to the RtlUnicodeStringToAnsiString syscall.
 */
#define MDK_HASH_RtlUnicodeStringToAnsiString 0xcf035ea2

/**
 * @brief The hash corresponding to the RtlUpperChar syscall.
 */
#define MDK_HASH_RtlUpperChar 0x21165fb9

/**
 * @brief The hash corresponding to the RtlPrefixString syscall.
 */
#define MDK_HASH_RtlPrefixString 0x6a400de4

/**
 * @brief The hash corresponding to the RtlAppendStringToString syscall.
 */
#define MDK_HASH_RtlAppendStringToString 0xacbb2d78

/**
 * @brief The hash corresponding to the RtlUpperString syscall.
 */
#define MDK_HASH_RtlUpperString 0xb83432e2

/**
 * @brief The hash corresponding to the RtlFreeAnsiString syscall.
 */
#define MDK_HASH_RtlFreeAnsiString 0x8a73fe43

/**
 * @brief The hash corresponding to the RtlFreeUnicodeString syscall.
 */
#define MDK_HASH_RtlFreeUnicodeString 0x738cd9ef

/**
 * @brief The hash corresponding to the RtlUnicodeStringToInteger syscall.
 */
#define MDK_HASH_RtlUnicodeStringToInteger 0x8a3457fe

/**
 * @brief The hash corresponding to the RtlDefaultNpAcl syscall.
 */
#define MDK_HASH_RtlDefaultNpAcl 0x8c01cbb2

/**
 * @brief The hash corresponding to the RtlCreateRegistryKey syscall.
 */
#define MDK_HASH_RtlCreateRegistryKey 0x8fe9ad35

/**
 * @brief The hash corresponding to the RtlQueryRegistryValues syscall.
 */
#define MDK_HASH_RtlQueryRegistryValues 0x5037edae

/**
 * @brief The hash corresponding to the RtlWriteRegistryValue syscall.
 */
#define MDK_HASH_RtlWriteRegistryValue 0x450aa620

/**
 * @brief The hash corresponding to the RtlCreateEnvironment syscall.
 */
#define MDK_HASH_RtlCreateEnvironment 0x64eb3f18

/**
 * @brief The hash corresponding to the RtlCreateEnvironmentEx syscall.
 */
#define MDK_HASH_RtlCreateEnvironmentEx 0xbe6b1ce5

/**
 * @brief The hash corresponding to the RtlDestroyEnvironment syscall.
 */
#define MDK_HASH_RtlDestroyEnvironment 0xd2316e8e

/**
 * @brief The hash corresponding to the RtlSetCurrentEnvironment syscall.
 */
#define MDK_HASH_RtlSetCurrentEnvironment 0x55796ba3

/**
 * @brief The hash corresponding to the RtlSetEnvironmentVar syscall.
 */
#define MDK_HASH_RtlSetEnvironmentVar 0xf1023819

/**
 * @brief The hash corresponding to the RtlSetEnvironmentVariable syscall.
 */
#define MDK_HASH_RtlSetEnvironmentVariable 0xc1c90146

/**
 * @brief The hash corresponding to the RtlQueryEnvironmentVariable syscall.
 */
#define MDK_HASH_RtlQueryEnvironmentVariable 0x946a4190

/**
 * @brief The hash corresponding to the RtlExpandEnvironmentStrings syscall.
 */
#define MDK_HASH_RtlExpandEnvironmentStrings 0x5289efce

/**
 * @brief The hash corresponding to the RtlSetEnvironmentStrings syscall.
 */
#define MDK_HASH_RtlSetEnvironmentStrings 0xb31137fa

/**
 * @brief The hash corresponding to the RtlGetCurrentTransaction syscall.
 */
#define MDK_HASH_RtlGetCurrentTransaction 0x87d972d8

/**
 * @brief The hash corresponding to the RtlSetCurrentTransaction syscall.
 */
#define MDK_HASH_RtlSetCurrentTransaction 0x70bcb4d4

/**
 * @brief The hash corresponding to the RtlCreateProcessParameters syscall.
 */
#define MDK_HASH_RtlCreateProcessParameters 0x5e826b66

/**
 * @brief The hash corresponding to the RtlCreateProcessParametersEx syscall.
 */
#define MDK_HASH_RtlCreateProcessParametersEx 0x410e53a3

/**
 * @brief The hash corresponding to the RtlDestroyProcessParameters syscall.
 */
#define MDK_HASH_RtlDestroyProcessParameters 0x9d6eb34c

/**
 * @brief The hash corresponding to the RtlNormalizeProcessParams syscall.
 */
#define MDK_HASH_RtlNormalizeProcessParams 0x1c896b13

/**
 * @brief The hash corresponding to the RtlDeNormalizeProcessParams syscall.
 */
#define MDK_HASH_RtlDeNormalizeProcessParams 0xf4dc2a8c

/**
 * @brief The hash corresponding to the RtlCreateUserProcess syscall.
 */
#define MDK_HASH_RtlCreateUserProcess 0xf2307dd1

/**
 * @brief The hash corresponding to the RtlCreateUserThread syscall.
 */
#define MDK_HASH_RtlCreateUserThread 0x7eb6255a

/**
 * @brief The hash corresponding to the RtlExitUserThread syscall.
 */
#define MDK_HASH_RtlExitUserThread 0x3d59e390

/**
 * @brief The hash corresponding to the RtlImageNtHeader syscall.
 */
#define MDK_HASH_RtlImageNtHeader 0x6af1bc5d

/**
 * @brief The hash corresponding to the RtlImageNtHeaderEx syscall.
 */
#define MDK_HASH_RtlImageNtHeaderEx 0xd3dd46da

/**
 * @brief The hash corresponding to the RtlImageDirectoryEntryToData syscall.
 */
#define MDK_HASH_RtlImageDirectoryEntryToData 0x9445b46

/**
 * @brief The hash corresponding to the RtlPcToFileHeader syscall.
 */
#define MDK_HASH_RtlPcToFileHeader 0x4d5d7d2e

/**
 * @brief The hash corresponding to the RtlAddressInSectionTable syscall.
 */
#define MDK_HASH_RtlAddressInSectionTable 0xffb6a969

/**
 * @brief The hash corresponding to the RtlImageRvaToSection syscall.
 */
#define MDK_HASH_RtlImageRvaToSection 0xc10746c3

/**
 * @brief The hash corresponding to the RtlImageRvaToVa syscall.
 */
#define MDK_HASH_RtlImageRvaToVa 0x6027ddc5

/**
 * @brief The hash corresponding to the RtlQueryProcessHeapInformation syscall.
 */
#define MDK_HASH_RtlQueryProcessHeapInformation 0x11b6be68

/**
 * @brief The hash corresponding to the RtlCreateQueryDebugBuffer syscall.
 */
#define MDK_HASH_RtlCreateQueryDebugBuffer 0x55f788fa

/**
 * @brief The hash corresponding to the RtlQueryProcessDebugInformation syscall.
 */
#define MDK_HASH_RtlQueryProcessDebugInformation 0xff1aeaa1

/**
 * @brief The hash corresponding to the RtlRestoreContext syscall.
 */
#define MDK_HASH_RtlRestoreContext 0xeb74698

/**
 * @brief The hash corresponding to the RtlAdjustPrivilege syscall.
 */
#define MDK_HASH_RtlAdjustPrivilege 0x29731a51

/**
 * @brief The hash corresponding to the RtlAcquirePrivilege syscall.
 */
#define MDK_HASH_RtlAcquirePrivilege 0xb8a95d0

/**
 * @brief The hash corresponding to the RtlReleasePrivilege syscall.
 */
#define MDK_HASH_RtlReleasePrivilege 0x1d516367

/**
 * @brief The hash corresponding to the RtlReleaseRelativeName syscall.
 */
#define MDK_HASH_RtlReleaseRelativeName 0xbdc55ecd

/**
 * @brief The hash corresponding to the RtlNtPathNameToDosPathName syscall.
 */
#define MDK_HASH_RtlNtPathNameToDosPathName 0xd1c60fc6

/**
 * @brief The hash corresponding to the RtlInitializeSRWLock syscall.
 */
#define MDK_HASH_RtlInitializeSRWLock 0x91cbab36

/**
 * @brief The hash corresponding to the RtlAcquireSRWLockExclusive syscall.
 */
#define MDK_HASH_RtlAcquireSRWLockExclusive 0x69630686

/**
 * @brief The hash corresponding to the RtlAcquireSRWLockShared syscall.
 */
#define MDK_HASH_RtlAcquireSRWLockShared 0x16ead2c5

/**
 * @brief The hash corresponding to the RtlReleaseSRWLockExclusive syscall.
 */
#define MDK_HASH_RtlReleaseSRWLockExclusive 0xa9fac0ed

/**
 * @brief The hash corresponding to the RtlReleaseSRWLockShared syscall.
 */
#define MDK_HASH_RtlReleaseSRWLockShared 0x708a8fcc

/**
 * @brief The hash corresponding to the RtlTryAcquireSRWLockExclusive syscall.
 */
#define MDK_HASH_RtlTryAcquireSRWLockExclusive 0x6dac2485

/**
 * @brief The hash corresponding to the RtlTryAcquireSRWLockShared syscall.
 */
#define MDK_HASH_RtlTryAcquireSRWLockShared 0xf8c39964

/**
 * @brief The hash corresponding to the RtlAcquireReleaseSRWLockExclusive syscall.
 */
#define MDK_HASH_RtlAcquireReleaseSRWLockExclusive 0x244d4a87

/**
 * @brief The hash corresponding to the RtlWalkFrameChain syscall.
 */
#define MDK_HASH_RtlWalkFrameChain 0x6a892ec

/**
 * @brief The hash corresponding to the PfxFindPrefix syscall.
 */
#define MDK_HASH_PfxFindPrefix 0xe4baf7ba

/**
 * @brief The hash corresponding to the PfxInitialize syscall.
 */
#define MDK_HASH_PfxInitialize 0x7bc7001d

/**
 * @brief The hash corresponding to the PfxInsertPrefix syscall.
 */
#define MDK_HASH_PfxInsertPrefix 0xa24c14e

/**
 * @brief The hash corresponding to the PfxRemovePrefix syscall.
 */
#define MDK_HASH_PfxRemovePrefix 0xd16311b7

/**
 * @brief The hash corresponding to the RtlAbsoluteToSelfRelativeSD syscall.
 */
#define MDK_HASH_RtlAbsoluteToSelfRelativeSD 0xbe7b040e

/**
 * @brief The hash corresponding to the RtlAddAccessAllowedAce syscall.
 */
#define MDK_HASH_RtlAddAccessAllowedAce 0x9f7e5abb

/**
 * @brief The hash corresponding to the RtlAddAccessAllowedAceEx syscall.
 */
#define MDK_HASH_RtlAddAccessAllowedAceEx 0x1a3404b8

/**
 * @brief The hash corresponding to the RtlAddAce syscall.
 */
#define MDK_HASH_RtlAddAce 0x2c448c11

/**
 * @brief The hash corresponding to the RtlAddAtomToAtomTable syscall.
 */
#define MDK_HASH_RtlAddAtomToAtomTable 0x284ff655

/**
 * @brief The hash corresponding to the RtlAppendUnicodeStringToString syscall.
 */
#define MDK_HASH_RtlAppendUnicodeStringToString 0x187a7ebf

/**
 * @brief The hash corresponding to the RtlAreAllAccessesGranted syscall.
 */
#define MDK_HASH_RtlAreAllAccessesGranted 0x57e0688f

/**
 * @brief The hash corresponding to the RtlAreAnyAccessesGranted syscall.
 */
#define MDK_HASH_RtlAreAnyAccessesGranted 0x180eb91e

/**
 * @brief The hash corresponding to the RtlAreBitsClear syscall.
 */
#define MDK_HASH_RtlAreBitsClear 0x81147810

/**
 * @brief The hash corresponding to the RtlAreBitsSet syscall.
 */
#define MDK_HASH_RtlAreBitsSet 0x1c3521d5

/**
 * @brief The hash corresponding to the RtlCaptureContext syscall.
 */
#define MDK_HASH_RtlCaptureContext 0xf99c8f68

/**
 * @brief The hash corresponding to the RtlCaptureStackBackTrace syscall.
 */
#define MDK_HASH_RtlCaptureStackBackTrace 0x32f88f99

/**
 * @brief The hash corresponding to the RtlClearAllBits syscall.
 */
#define MDK_HASH_RtlClearAllBits 0xfa51dc71

/**
 * @brief The hash corresponding to the RtlClearBits syscall.
 */
#define MDK_HASH_RtlClearBits 0xeb70a9c8

/**
 * @brief The hash corresponding to the RtlCreateSystemVolumeInformationFolder syscall.
 */
#define MDK_HASH_RtlCreateSystemVolumeInformationFolder 0x6b8e4b2

/**
 * @brief The hash corresponding to the RtlCompareAltitudes syscall.
 */
#define MDK_HASH_RtlCompareAltitudes 0xbe5b4dd5

/**
 * @brief The hash corresponding to the RtlCompareUnicodeString syscall.
 */
#define MDK_HASH_RtlCompareUnicodeString 0x6bd8b604

/**
 * @brief The hash corresponding to the RtlComputeCrc32 syscall.
 */
#define MDK_HASH_RtlComputeCrc32 0xc4b0d469

/**
 * @brief The hash corresponding to the RtlConvertSidToUnicodeString syscall.
 */
#define MDK_HASH_RtlConvertSidToUnicodeString 0x33ef2621

/**
 * @brief The hash corresponding to the RtlCopyLuid syscall.
 */
#define MDK_HASH_RtlCopyLuid 0xf13e99f8

/**
 * @brief The hash corresponding to the RtlAllocateAndInitializeSid syscall.
 */
#define MDK_HASH_RtlAllocateAndInitializeSid 0x60063059

/**
 * @brief The hash corresponding to the RtlAllocateAndInitializeSidEx syscall.
 */
#define MDK_HASH_RtlAllocateAndInitializeSidEx 0xda502de6

/**
 * @brief The hash corresponding to the RtlCopySid syscall.
 */
#define MDK_HASH_RtlCopySid 0xd33ba58a

/**
 * @brief The hash corresponding to the RtlCreateServiceSid syscall.
 */
#define MDK_HASH_RtlCreateServiceSid 0xce19104

/**
 * @brief The hash corresponding to the RtlFreeSid syscall.
 */
#define MDK_HASH_RtlFreeSid 0xbc184881

/**
 * @brief The hash corresponding to the RtlCreateAcl syscall.
 */
#define MDK_HASH_RtlCreateAcl 0x90c1f8a3

/**
 * @brief The hash corresponding to the RtlCreateAtomTable syscall.
 */
#define MDK_HASH_RtlCreateAtomTable 0x75265cfc

/**
 * @brief The hash corresponding to the RtlDelete syscall.
 */
#define MDK_HASH_RtlDelete 0x57b2b572

/**
 * @brief The hash corresponding to the RtlDeleteAce syscall.
 */
#define MDK_HASH_RtlDeleteAce 0xe72ca4b

/**
 * @brief The hash corresponding to the RtlDeleteAtomFromAtomTable syscall.
 */
#define MDK_HASH_RtlDeleteAtomFromAtomTable 0x96695ff0

/**
 * @brief The hash corresponding to the RtlDeleteNoSplay syscall.
 */
#define MDK_HASH_RtlDeleteNoSplay 0xcd98aa08

/**
 * @brief The hash corresponding to the RtlDowncaseUnicodeString syscall.
 */
#define MDK_HASH_RtlDowncaseUnicodeString 0x80713c71

/**
 * @brief The hash corresponding to the RtlDuplicateUnicodeString syscall.
 */
#define MDK_HASH_RtlDuplicateUnicodeString 0x61500488

/**
 * @brief The hash corresponding to the RtlEmptyAtomTable syscall.
 */
#define MDK_HASH_RtlEmptyAtomTable 0xcfe6ca47

/**
 * @brief The hash corresponding to the RtlEqualSid syscall.
 */
#define MDK_HASH_RtlEqualSid 0x4d4e3f37

/**
 * @brief The hash corresponding to the RtlEqualString syscall.
 */
#define MDK_HASH_RtlEqualString 0xdfd40de

/**
 * @brief The hash corresponding to the RtlEqualUnicodeString syscall.
 */
#define MDK_HASH_RtlEqualUnicodeString 0x34246b15

/**
 * @brief The hash corresponding to the RtlFindClearBits syscall.
 */
#define MDK_HASH_RtlFindClearBits 0x3ed6d5c9

/**
 * @brief The hash corresponding to the RtlFindClearBitsAndSet syscall.
 */
#define MDK_HASH_RtlFindClearBitsAndSet 0xa3f216c8

/**
 * @brief The hash corresponding to the RtlFindClearRuns syscall.
 */
#define MDK_HASH_RtlFindClearRuns 0x3edf2a7f

/**
 * @brief The hash corresponding to the RtlFindLastBackwardRunClear syscall.
 */
#define MDK_HASH_RtlFindLastBackwardRunClear 0x295dc03f

/**
 * @brief The hash corresponding to the RtlFindLeastSignificantBit syscall.
 */
#define MDK_HASH_RtlFindLeastSignificantBit 0x49def287

/**
 * @brief The hash corresponding to the RtlFindLongestRunClear syscall.
 */
#define MDK_HASH_RtlFindLongestRunClear 0x6259c408

/**
 * @brief The hash corresponding to the RtlFindMostSignificantBit syscall.
 */
#define MDK_HASH_RtlFindMostSignificantBit 0x9779e9b1

/**
 * @brief The hash corresponding to the RtlFindNextForwardRunClear syscall.
 */
#define MDK_HASH_RtlFindNextForwardRunClear 0x5719ccd0

/**
 * @brief The hash corresponding to the RtlFindSetBits syscall.
 */
#define MDK_HASH_RtlFindSetBits 0x66203ce

/**
 * @brief The hash corresponding to the RtlFindSetBitsAndClear syscall.
 */
#define MDK_HASH_RtlFindSetBitsAndClear 0x52fb1d48

/**
 * @brief The hash corresponding to the RtlGetCallersAddress syscall.
 */
#define MDK_HASH_RtlGetCallersAddress 0x429b7ebb

/**
 * @brief The hash corresponding to the RtlGetDaclSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlGetDaclSecurityDescriptor 0x1d6a149a

/**
 * @brief The hash corresponding to the RtlGetGroupSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlGetGroupSecurityDescriptor 0xbefc7a83

/**
 * @brief The hash corresponding to the RtlGetOwnerSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlGetOwnerSecurityDescriptor 0x6833d261

/**
 * @brief The hash corresponding to the RtlGetSaclSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlGetSaclSecurityDescriptor 0xd542f429

/**
 * @brief The hash corresponding to the RtlGetSetBootStatusData syscall.
 */
#define MDK_HASH_RtlGetSetBootStatusData 0xe39f0ed

/**
 * @brief The hash corresponding to the RtlCreateBootStatusDataFile syscall.
 */
#define MDK_HASH_RtlCreateBootStatusDataFile 0x2c852ba5

/**
 * @brief The hash corresponding to the RtlGetVersion syscall.
 */
#define MDK_HASH_RtlGetVersion 0x1fea0aa5

/**
 * @brief The hash corresponding to the RtlGUIDFromString syscall.
 */
#define MDK_HASH_RtlGUIDFromString 0x7b29a1b3

/**
 * @brief The hash corresponding to the RtlHashUnicodeString syscall.
 */
#define MDK_HASH_RtlHashUnicodeString 0x45b92b61

/**
 * @brief The hash corresponding to the RtlInitializeSid syscall.
 */
#define MDK_HASH_RtlInitializeSid 0x65f7adb1

/**
 * @brief The hash corresponding to the RtlLengthRequiredSid syscall.
 */
#define MDK_HASH_RtlLengthRequiredSid 0x67093422

/**
 * @brief The hash corresponding to the RtlLengthSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlLengthSecurityDescriptor 0xf3a82c28

/**
 * @brief The hash corresponding to the RtlLengthSid syscall.
 */
#define MDK_HASH_RtlLengthSid 0x4cfeb701

/**
 * @brief The hash corresponding to the RtlLockBootStatusData syscall.
 */
#define MDK_HASH_RtlLockBootStatusData 0x2f721aa

/**
 * @brief The hash corresponding to the RtlLookupAtomInAtomTable syscall.
 */
#define MDK_HASH_RtlLookupAtomInAtomTable 0x582c7a6a

/**
 * @brief The hash corresponding to the RtlMapSecurityErrorToNtStatus syscall.
 */
#define MDK_HASH_RtlMapSecurityErrorToNtStatus 0xb45f7538

/**
 * @brief The hash corresponding to the RtlMultiByteToUnicodeN syscall.
 */
#define MDK_HASH_RtlMultiByteToUnicodeN 0x707cdff6

/**
 * @brief The hash corresponding to the RtlMultiByteToUnicodeSize syscall.
 */
#define MDK_HASH_RtlMultiByteToUnicodeSize 0xfa8d9163

/**
 * @brief The hash corresponding to the RtlNumberOfClearBits syscall.
 */
#define MDK_HASH_RtlNumberOfClearBits 0x53ee7a56

/**
 * @brief The hash corresponding to the RtlNumberOfSetBits syscall.
 */
#define MDK_HASH_RtlNumberOfSetBits 0xd36bec8b

/**
 * @brief The hash corresponding to the RtlQueryAtomInAtomTable syscall.
 */
#define MDK_HASH_RtlQueryAtomInAtomTable 0xaeb2b136

/**
 * @brief The hash corresponding to the RtlRealPredecessor syscall.
 */
#define MDK_HASH_RtlRealPredecessor 0xf7f77ce2

/**
 * @brief The hash corresponding to the RtlRealSuccessor syscall.
 */
#define MDK_HASH_RtlRealSuccessor 0x6e20200d

/**
 * @brief The hash corresponding to the RtlRunDecodeUnicodeString syscall.
 */
#define MDK_HASH_RtlRunDecodeUnicodeString 0x45f3d0d6

/**
 * @brief The hash corresponding to the RtlRunEncodeUnicodeString syscall.
 */
#define MDK_HASH_RtlRunEncodeUnicodeString 0x755d7660

/**
 * @brief The hash corresponding to the RtlSelfRelativeToAbsoluteSD syscall.
 */
#define MDK_HASH_RtlSelfRelativeToAbsoluteSD 0xb3fb704e

/**
 * @brief The hash corresponding to the RtlSelfRelativeToAbsoluteSD2 syscall.
 */
#define MDK_HASH_RtlSelfRelativeToAbsoluteSD2 0xc987bb50

/**
 * @brief The hash corresponding to the RtlSetAllBits syscall.
 */
#define MDK_HASH_RtlSetAllBits 0xef803056

/**
 * @brief The hash corresponding to the RtlSetBits syscall.
 */
#define MDK_HASH_RtlSetBits 0x6baf938d

/**
 * @brief The hash corresponding to the RtlSetDaclSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlSetDaclSecurityDescriptor 0x32b67096

/**
 * @brief The hash corresponding to the RtlSetGroupSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlSetGroupSecurityDescriptor 0xf05cc4ff

/**
 * @brief The hash corresponding to the RtlSetOwnerSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlSetOwnerSecurityDescriptor 0xbd93bfdd

/**
 * @brief The hash corresponding to the RtlSetSaclSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlSetSaclSecurityDescriptor 0xcaaed025

/**
 * @brief The hash corresponding to the RtlSplay syscall.
 */
#define MDK_HASH_RtlSplay 0x300cc318

/**
 * @brief The hash corresponding to the RtlStringFromGUID syscall.
 */
#define MDK_HASH_RtlStringFromGUID 0x69e0e4f3

/**
 * @brief The hash corresponding to the RtlSubAuthorityCountSid syscall.
 */
#define MDK_HASH_RtlSubAuthorityCountSid 0x59179fab

/**
 * @brief The hash corresponding to the RtlSubAuthoritySid syscall.
 */
#define MDK_HASH_RtlSubAuthoritySid 0x82d976f2

/**
 * @brief The hash corresponding to the RtlSubtreePredecessor syscall.
 */
#define MDK_HASH_RtlSubtreePredecessor 0x82c16d28

/**
 * @brief The hash corresponding to the RtlSubtreeSuccessor syscall.
 */
#define MDK_HASH_RtlSubtreeSuccessor 0xd0cab7d3

/**
 * @brief The hash corresponding to the RtlTestBit syscall.
 */
#define MDK_HASH_RtlTestBit 0xd4b9ffae

/**
 * @brief The hash corresponding to the RtlUnlockBootStatusData syscall.
 */
#define MDK_HASH_RtlUnlockBootStatusData 0xf9ee51ed

/**
 * @brief The hash corresponding to the RtlCreateSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlCreateSecurityDescriptor 0xd700fcba

/**
 * @brief The hash corresponding to the RtlValidRelativeSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlValidRelativeSecurityDescriptor 0x40692882

/**
 * @brief The hash corresponding to the RtlValidSecurityDescriptor syscall.
 */
#define MDK_HASH_RtlValidSecurityDescriptor 0x31bb48e6

/**
 * @brief The hash corresponding to the RtlValidSid syscall.
 */
#define MDK_HASH_RtlValidSid 0x39f7e5ff

/**
 * @brief The hash corresponding to the RtlVerifyVersionInfo syscall.
 */
#define MDK_HASH_RtlVerifyVersionInfo 0xdb52e046

/**
 * @brief The hash corresponding to the VerSetConditionMask syscall.
 */
#define MDK_HASH_VerSetConditionMask 0x2d9b31a9

/**
 * @brief The hash corresponding to the TpAllocPool syscall.
 */
#define MDK_HASH_TpAllocPool 0x2df5e356

/**
 * @brief The hash corresponding to the TpDisablePoolCallbackChecks syscall.
 */
#define MDK_HASH_TpDisablePoolCallbackChecks 0xd045fb6d

/**
 * @brief The hash corresponding to the TpReleasePool syscall.
 */
#define MDK_HASH_TpReleasePool 0x35927e3c

/**
 * @brief The hash corresponding to the TpSetPoolMaxThreads syscall.
 */
#define MDK_HASH_TpSetPoolMaxThreads 0xd0c88218

/**
 * @brief The hash corresponding to the TpSetPoolMinThreads syscall.
 */
#define MDK_HASH_TpSetPoolMinThreads 0x3e7a5de6

/**
 * @brief The hash corresponding to the TpQueryPoolStackInformation syscall.
 */
#define MDK_HASH_TpQueryPoolStackInformation 0x17fd6d2d

/**
 * @brief The hash corresponding to the TpSetPoolStackInformation syscall.
 */
#define MDK_HASH_TpSetPoolStackInformation 0xc509de93

/**
 * @brief The hash corresponding to the TpAllocCleanupGroup syscall.
 */
#define MDK_HASH_TpAllocCleanupGroup 0x7df72e31

/**
 * @brief The hash corresponding to the TpReleaseCleanupGroup syscall.
 */
#define MDK_HASH_TpReleaseCleanupGroup 0xf728f727

/**
 * @brief The hash corresponding to the TpReleaseCleanupGroupMembers syscall.
 */
#define MDK_HASH_TpReleaseCleanupGroupMembers 0x7c8e2c52

/**
 * @brief The hash corresponding to the TpCallbackSetEventOnCompletion syscall.
 */
#define MDK_HASH_TpCallbackSetEventOnCompletion 0xe334c283

/**
 * @brief The hash corresponding to the TpCallbackReleaseSemaphoreOnCompletion syscall.
 */
#define MDK_HASH_TpCallbackReleaseSemaphoreOnCompletion 0x19065a6a

/**
 * @brief The hash corresponding to the TpCallbackReleaseMutexOnCompletion syscall.
 */
#define MDK_HASH_TpCallbackReleaseMutexOnCompletion 0xcb94b139

/**
 * @brief The hash corresponding to the TpCallbackLeaveCriticalSectionOnCompletion syscall.
 */
#define MDK_HASH_TpCallbackLeaveCriticalSectionOnCompletion 0xbab64ee2

/**
 * @brief The hash corresponding to the TpCallbackUnloadDllOnCompletion syscall.
 */
#define MDK_HASH_TpCallbackUnloadDllOnCompletion 0x9a450094

/**
 * @brief The hash corresponding to the TpCallbackMayRunLong syscall.
 */
#define MDK_HASH_TpCallbackMayRunLong 0x586630fa

/**
 * @brief The hash corresponding to the TpDisassociateCallback syscall.
 */
#define MDK_HASH_TpDisassociateCallback 0xef5b10aa

/**
 * @brief The hash corresponding to the TpSimpleTryPost syscall.
 */
#define MDK_HASH_TpSimpleTryPost 0x1ea33c00

/**
 * @brief The hash corresponding to the TpAllocWork syscall.
 */
#define MDK_HASH_TpAllocWork 0x2df1da4f

/**
 * @brief The hash corresponding to the TpReleaseWork syscall.
 */
#define MDK_HASH_TpReleaseWork 0x359da935

/**
 * @brief The hash corresponding to the TpPostWork syscall.
 */
#define MDK_HASH_TpPostWork 0x5fa50cca

/**
 * @brief The hash corresponding to the TpWaitForWork syscall.
 */
#define MDK_HASH_TpWaitForWork 0xb71b6170

/**
 * @brief The hash corresponding to the TpAllocTimer syscall.
 */
#define MDK_HASH_TpAllocTimer 0x2a093fed

/**
 * @brief The hash corresponding to the TpReleaseTimer syscall.
 */
#define MDK_HASH_TpReleaseTimer 0xe846913

/**
 * @brief The hash corresponding to the TpSetTimer syscall.
 */
#define MDK_HASH_TpSetTimer 0xe9bc8e

/**
 * @brief The hash corresponding to the TpSetTimerEx syscall.
 */
#define MDK_HASH_TpSetTimerEx 0x5030dfcb

/**
 * @brief The hash corresponding to the TpIsTimerSet syscall.
 */
#define MDK_HASH_TpIsTimerSet 0x204725aa

/**
 * @brief The hash corresponding to the TpWaitForTimer syscall.
 */
#define MDK_HASH_TpWaitForTimer 0x58e838fe

/**
 * @brief The hash corresponding to the TpAllocWait syscall.
 */
#define MDK_HASH_TpAllocWait 0x2df119f1

/**
 * @brief The hash corresponding to the TpReleaseWait syscall.
 */
#define MDK_HASH_TpReleaseWait 0x359d94e7

/**
 * @brief The hash corresponding to the TpSetWait syscall.
 */
#define MDK_HASH_TpSetWait 0x898efeb2

/**
 * @brief The hash corresponding to the TpSetWaitEx syscall.
 */
#define MDK_HASH_TpSetWaitEx 0x673c5aff

/**
 * @brief The hash corresponding to the TpAllocIoCompletion syscall.
 */
#define MDK_HASH_TpAllocIoCompletion 0x179dac1e

/**
 * @brief The hash corresponding to the TpWaitForIoCompletion syscall.
 */
#define MDK_HASH_TpWaitForIoCompletion 0x9281b04f

/**
 * @brief The hash corresponding to the TpAllocAlpcCompletion syscall.
 */
#define MDK_HASH_TpAllocAlpcCompletion 0x517b456

/**
 * @brief The hash corresponding to the TpAllocAlpcCompletionEx syscall.
 */
#define MDK_HASH_TpAllocAlpcCompletionEx 0x7d917893

/**
 * @brief The hash corresponding to the TpReleaseAlpcCompletion syscall.
 */
#define MDK_HASH_TpReleaseAlpcCompletion 0x555ffebc

/**
 * @brief The hash corresponding to the TpWaitForAlpcCompletion syscall.
 */
#define MDK_HASH_TpWaitForAlpcCompletion 0x96ee5047

/**
 * @brief The hash corresponding to the TpAlpcRegisterCompletionList syscall.
 */
#define MDK_HASH_TpAlpcRegisterCompletionList 0x44b1295c

/**
 * @brief The hash corresponding to the TpAlpcUnregisterCompletionList syscall.
 */
#define MDK_HASH_TpAlpcUnregisterCompletionList 0xbf1d129f

/**
 * @brief The ANSI_STRING structure defines a counted string used for ANSI strings.
 */
typedef struct _MDK_STRING
{
    USHORT Length;
    USHORT MaximumLength;
    PCHAR Buffer;
} MDK_STRING, *MDK_PSTRING;

/**
 * @brief The UNICODE_STRING structure is used to define Unicode strings.
 */
typedef struct _MDK_UNICODE_STRING
{
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
} MDK_UNICODE_STRING, *MDK_PUNICODE_STRING;

/**
 * @brief The LDR_DATA_TABLE_ENTRY structure represents a module loaded for the process.
 */
typedef struct _MDK_LDR_DATA_TABLE_ENTRY
{
    LIST_ENTRY InLoadOrderLinks;
    LIST_ENTRY InMemoryOrderLinks;
    LIST_ENTRY InInitializationOrderLinks;
    PVOID DllBase;
    PVOID EntryPoint;
    ULONG SizeOfImage;
    MDK_UNICODE_STRING FullDllName;
    MDK_UNICODE_STRING BaseDllName;
    ULONG Flags;
    USHORT LoadCount;
    USHORT TlsIndex;
    union
    {
        LIST_ENTRY HashLinks;
        struct
        {
            PVOID SectionPointer;
            ULONG CheckSum;
        };
    };
    union
    {
        ULONG TimeDateStamp;
        PVOID LoadedImports;
    };
    PVOID EntryPointActivationContext;
    PVOID PatchInformation;
    LIST_ENTRY ForwarderLinks;
    LIST_ENTRY ServiceTagLinks;
    LIST_ENTRY StaticLinks;
    PVOID ContextInformation;
    ULONG_PTR OriginalBase;
    LARGE_INTEGER LoadTime;
} MDK_LDR_DATA_TABLE_ENTRY, *MDK_PLDR_DATA_TABLE_ENTRY;

/**
 * @brief The PEB_LDR_DATA structure contains information about the loaded modules for the process.
 */
typedef struct _MDK_PEB_LDR_DATA
{
    ULONG Length;
    BOOLEAN Initialized;
    HANDLE SsHandle;
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    PVOID EntryInProgress;
    BOOLEAN ShutdownInProgress;
    HANDLE ShutdownThreadId;
} MDK_PEB_LDR_DATA, *MDK_PPEB_LDR_DATA;

/**
 * @brief The CURDIR structure contains information about the current directory of the running process.
 */
typedef struct _MDK_CURDIR
{
    MDK_UNICODE_STRING DosPath;
    HANDLE Handle;
} MDK_CURDIR, * MDK_PCURDIR;

/**
 * @brief The RTL_DRIVE_LETTER_CURDIR structure keeps a current directory for each drive (letter).
 */
typedef struct _MDK_RTL_DRIVE_LETTER_CURDIR
{
    USHORT Flags;
    USHORT Length;
    ULONG TimeStamp;
    MDK_STRING DosPath;
} MDK_RTL_DRIVE_LETTER_CURDIR, * MDK_PRTL_DRIVE_LETTER_CURDIR;

/**
 * @brief The RTL_USER_PROCESS_PARAMETERS contains process parameter information.
 */
typedef struct _RTL_USER_PROCESS_PARAMETERS
{
    ULONG MaximumLength;
    ULONG Length;
    ULONG Flags;
    ULONG DebugFlags;
    HANDLE ConsoleHandle;
    ULONG ConsoleFlags;
    HANDLE StandardInput;
    HANDLE StandardOutput;
    HANDLE StandardError;
    MDK_CURDIR CurrentDirectory;
    MDK_UNICODE_STRING DllPath;
    MDK_UNICODE_STRING ImagePathName;
    MDK_UNICODE_STRING CommandLine;
    PVOID Environment;
    ULONG StartingX;
    ULONG StartingY;
    ULONG CountX;
    ULONG CountY;
    ULONG CountCharsX;
    ULONG CountCharsY;
    ULONG FillAttribute;
    ULONG WindowFlags;
    ULONG ShowWindowFlags;
    MDK_UNICODE_STRING WindowTitle;
    MDK_UNICODE_STRING DesktopInfo;
    MDK_UNICODE_STRING ShellInfo;
    MDK_UNICODE_STRING RuntimeData;
    MDK_RTL_DRIVE_LETTER_CURDIR CurrentDirectories[32];
    ULONG EnvironmentSize;
    ULONG EnvironmentVersion;
} MDK_RTL_USER_PROCESS_PARAMETERS, *MDK_PRTL_USER_PROCESS_PARAMETERS;

/**
 * @brief The Process Environment Block (PEB) structure contains process information.
 */
typedef struct _MDK_PEB
{
    BOOLEAN InheritedAddressSpace;
    BOOLEAN ReadImageFileExecOptions;
    BOOLEAN BeingDebugged;
    union
    {
        BOOLEAN BitField;
        struct
        {
            BOOLEAN ImageUsesLargePages : 1;
            BOOLEAN IsProtectedProcess : 1;
            BOOLEAN IsLegacyProcess : 1;
            BOOLEAN IsImageDynamicallyRelocated : 1;
            BOOLEAN SkipPatchingUser32Forwarders : 1;
            BOOLEAN SpareBits : 3;
        };
    };
    HANDLE Mutant;
    PVOID ImageBaseAddress;
    MDK_PPEB_LDR_DATA Ldr;
    MDK_PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
    PVOID SubSystemData;
    PVOID ProcessHeap;
    PRTL_CRITICAL_SECTION FastPebLock;
    PVOID AtlThunkSListPtr;
    PVOID IFEOKey;
    union
    {
        ULONG CrossProcessFlags;
        struct
        {
            ULONG ProcessInJob : 1;
            ULONG ProcessInitializing : 1;
            ULONG ProcessUsingVEH : 1;
            ULONG ProcessUsingVCH : 1;
            ULONG ProcessUsingFTH : 1;
            ULONG ReservedBits0 : 27;
        };
        ULONG EnvironmentUpdateCount;
    };
    union
    {
        PVOID KernelCallbackTable;
        PVOID UserSharedInfoPtr;
    };
    ULONG SystemReserved[1];
    ULONG AtlThunkSListPtr32;
    PVOID ApiSetMap;
    ULONG TlsExpansionCounter;
    PVOID TlsBitmap;
    ULONG TlsBitmapBits[2];
    PVOID ReadOnlySharedMemoryBase;
    PVOID HotpatchInformation;
    PVOID ReadOnlyStaticServerData;
    PVOID AnsiCodePageData;
    PVOID OemCodePageData;
    PVOID UnicodeCaseTableData;
    ULONG NumberOfProcessors;
    ULONG NtGlobalFlag;
    LARGE_INTEGER CriticalSectionTimeout;
    SIZE_T HeapSegmentReserve;
    SIZE_T HeapSegmentCommit;
    SIZE_T HeapDeCommitTotalFreeThreshold;
    SIZE_T HeapDeCommitFreeBlockThreshold;
    ULONG NumberOfHeaps;
    ULONG MaximumNumberOfHeaps;
    PVOID ProcessHeaps;
    PVOID GdiSharedHandleTable;
    PVOID ProcessStarterHelper;
    ULONG GdiDCAttributeList;
    PRTL_CRITICAL_SECTION LoaderLock;
    ULONG OSMajorVersion;
    ULONG OSMinorVersion;
    USHORT OSBuildNumber;
    USHORT OSCSDVersion;
    ULONG OSPlatformId;
    ULONG ImageSubsystem;
    ULONG ImageSubsystemMajorVersion;
    ULONG ImageSubsystemMinorVersion;
    ULONG_PTR ImageProcessAffinityMask;
    ULONG GdiHandleBuffer[60];
    PVOID PostProcessInitRoutine;
    PVOID TlsExpansionBitmap;
    ULONG TlsExpansionBitmapBits[32];
    ULONG SessionId;
    ULARGE_INTEGER AppCompatFlags;
    ULARGE_INTEGER AppCompatFlagsUser;
    PVOID pShimData;
    PVOID AppCompatInfo;
    MDK_UNICODE_STRING CSDVersion;
    PVOID ActivationContextData;
    PVOID ProcessAssemblyStorageMap;
    PVOID SystemDefaultActivationContextData;
    PVOID SystemAssemblyStorageMap;
    SIZE_T MinimumStackCommit;
    PVOID FlsCallback;
    LIST_ENTRY FlsListHead;
    PVOID FlsBitmap;
    ULONG FlsBitmapBits[FLS_MAXIMUM_AVAILABLE / (sizeof(ULONG) * 8)];
    ULONG FlsHighIndex;
    PVOID WerRegistrationData;
    PVOID WerShipAssertPtr;
    PVOID pContextData;
    PVOID pImageHeaderHash;
    union
    {
        ULONG TracingFlags;
        struct
        {
            ULONG HeapTracingEnabled : 1;
            ULONG CritSecTracingEnabled : 1;
            ULONG SpareTracingBits : 30;
        };
    };
} MDK_PEB, *MDK_PPEB;

/**
 * @brief The Thread Environment Block (TEB) structure describes the state of a thread.
 */
typedef struct _MDK_TEB
{
    PVOID Reserved1[12];
    MDK_PPEB ProcessEnvironmentBlock;
    PVOID Reserved2[399];
    BYTE Reserved3[1952];
    PVOID TlsSlots[64];
    BYTE Reserved4[8];
    PVOID Reserved5[26];
    PVOID ReservedForOle;
    PVOID Reserved6[4];
    PVOID TlsExpansionSlots;
} MDK_TEB, *MDK_PTEB;

/**
 * @brief 
 * 
 * @param lhs 
 * @param rhs 
 * @param count 
 * @return INT 
 */
INT MdkCompareMemory(_In_ LPCVOID lhs, _In_ LPCVOID rhs, _In_ SIZE_T count)
{
    LPCBYTE p1 = (LPCBYTE)lhs;
    LPCBYTE p2 = (LPCBYTE)rhs;

    for (SIZE_T i = 0; i < count; ++i)
    {
        if (p1[i] < p2[i])
        {
            return -1;
        }
        else if (p1[i] > p2[i])
        {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief 
 * 
 * @param dest 
 * @param src 
 * @param count 
 * @return VOID 
 */
VOID MdkCopyMemory(_In_ LPVOID dest, _In_ LPCVOID src, _In_ SIZE_T count)
{
    PBYTE bsrc = (PBYTE)src;
    PBYTE bdest = (PBYTE)dest;

    for (SIZE_T i = 0; i < count; ++i)
    {
        bdest[i] = bsrc[i];
    }
}

/**
 * @brief Gets a pointer to the Process Environment Block (PEB) of the current process. 
 * 
 * @return Pointer to the Process Environment Block (PPEB) of the current process.
 */
MDK_PPEB MdkCurrentPeb(VOID)
{
#ifdef _M_X64
    return (MDK_PPEB)__readgsqword(0x60);
#else
    return (MDK_PPEB)__readfsdword(0x30);
#endif
}

/**
 * @brief Gets a pointer to the Thread Environment Block (TEB) of the current thread. 
 * 
 * @return Pointer to the Thread Environment Block (PTEB) of the current thread.
 */
MDK_PTEB MdkCurrentTeb(VOID)
{
#ifdef _M_X64
    return (MDK_PTEB)__readgsqword(0x30);
#else
    return (MDK_PTEB)__readfsdword(0x18);
#endif
}

/**
 * @brief 
 * 
 * @param dest 
 * @param value 
 * @param count 
 * @return LPVOID 
 */
LPVOID MdkSetMemory(_In_ LPVOID dest, _In_ INT value, _In_ SIZE_T count)
{
    PINT idest = (PINT)dest;

    for (SIZE_T i = 0; i < count; ++i)
    {
        idest[i] = value;
    }

    return dest;
}

/**
 * @brief 
 * 
 * @param dest 
 * @param count 
 * @return LPVOID 
 */
LPVOID MdkZeroMemory(_In_ LPVOID dest, _In_ SIZE_T count)
{
    return MdkSetMemory(dest, 0, count);
}

/**
 * @brief 
 * 
 * @param str 
 * @return SIZE_T 
 */
SIZE_T MdkStringLengthA(_In_ LPCSTR str)
{
    SIZE_T size = 0;

    if (str != NULL)
    {
        while (*str++)
        {
            size += 1;
        }
    }

    return size;
}

/**
 * @brief 
 * 
 * @param str 
 * @return SIZE_T 
 */
SIZE_T MdkStringLengthW(_In_ LPCWSTR str)
{
    SIZE_T size = 0;

    if (str != NULL)
    {
        while (*str++)
        {
            size += 1;
        }
    }

    return size;
}

/**
 * @brief 
 * 
 * @param lhs 
 * @param rhs 
 * @return INT 
 */
INT MdkCompareStringA(_In_ LPCSTR lhs, _In_ LPCSTR rhs)
{
    while (*lhs && (*lhs == *rhs))
    {
        lhs++;
        rhs++;
    }

    return *(CONST PUCHAR)lhs - *(CONST PUCHAR)rhs;
}

/**
 * @brief Performs an ordinal comparison of lhs and rhs and returns a value that indicates their relationship.
 * 
 * @param lhs First null-terminated string to compare.
 * @param rhs Second null-terminated string to compare.
 * @return The function returns 0 if lhs is identical to rhs, a value < 0 if lhs is less than rhs and a value > 0 if lhs is greater than rhs. 
 */
INT MdkCompareStringW(_In_ LPCWSTR lhs, _In_ LPCWSTR rhs)
{
    while (*lhs && (*lhs == *rhs))
    {
        lhs++;
        rhs++;
    }

    return *(CONST PWCHAR)lhs - *(CONST PWCHAR)rhs;
}


/**
 * @brief 
 * 
 * @param str 
 * @param len 
 * @return DWORD 
 */
DWORD MdkHashString(_In_ LPVOID str, _In_opt_ SIZE_T len)
{
    UCHAR cur = 0;
    DWORD hash = 5381;
    PUCHAR ptr = (PUCHAR)str;

    while (TRUE)
    {
        cur = *ptr;

        if (!len)
        {
            if (!*ptr)
            {
                break;
            }
        }
        else
        {
            if ((DWORD)(ptr - (PUCHAR)str) >= len)
            {
                break;
            };

            if (!*ptr)
            {
                ++ptr;
                continue;
            }
        }

        if (cur >= 'a')
        {
            cur -= 0x20;
        }

        hash = ((hash << 5) + hash) + cur;
        ++ptr;
    }

    return hash;
}

/**
 * @brief 
 * 
 * @param module 
 * @param gadget 
 * @param count 
 * @return LPVOID 
 */
LPVOID MdkFindGadgetA(_In_ LPBYTE module, _In_ LPCSTR gadget, _In_ SIZE_T count)
{
    for (SIZE_T i = 0; i < count; ++i)
    {
        if (MdkCompareStringA((LPCSTR)(module + i), gadget) == 0)
        {
            return MDK_C_PTR(module + i);
        }
    };

    return NULL;
}

/**
 * @brief Get the Module Handle By Hash object
 * 
 * @param hash 
 * @return LPVOID 
 */
LPVOID MdkGetModuleHandleByHash(_In_ DWORD hash)
{
    MDK_PPEB peb = MdkCurrentPeb();
    PLIST_ENTRY	hdr = &peb->Ldr->InLoadOrderModuleList;
    PLIST_ENTRY ent = hdr->Flink;
    MDK_PLDR_DATA_TABLE_ENTRY ldr = NULL;

    for (; hdr != ent; ent = ent->Flink)
    {
        ldr = (MDK_PLDR_DATA_TABLE_ENTRY)ent;

        if (MdkHashString(ldr->BaseDllName.Buffer, ldr->BaseDllName.Length) == (hash ^ MDK_KEY))
        {
            return ldr->DllBase;
        }
    }
    
    return NULL;
}

/**
 * @brief 
 * 
 * @param module 
 * @param hash 
 * @return LPVOID 
 */
LPVOID MdkGetProcAddressByHash(_In_ LPVOID module, _In_ DWORD hash)
{
    PUINT16	aoo = NULL;
    PUINT32	aof = NULL;
    PUINT32	aon = NULL;
    PIMAGE_DOS_HEADER hdr = (PIMAGE_DOS_HEADER)module;
    PIMAGE_NT_HEADERS nth = (PIMAGE_NT_HEADERS)(MDK_U_PTR(hdr) + hdr->e_lfanew);
    PIMAGE_DATA_DIRECTORY dir = &nth->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
    PIMAGE_EXPORT_DIRECTORY	exp = NULL;

    if (dir->VirtualAddress)
    {
        exp = (PIMAGE_EXPORT_DIRECTORY)(MDK_U_PTR(hdr) + dir->VirtualAddress);
        aon = (PUINT32)(MDK_U_PTR(hdr) + exp->AddressOfNames);
        aof = (PUINT32)(MDK_U_PTR(hdr) + exp->AddressOfFunctions);
        aoo = (PUINT16)(MDK_U_PTR(hdr) + exp->AddressOfNameOrdinals);

        for (DWORD i = 0; i < exp->NumberOfNames; ++i)
        {
            if (MdkHashString(MDK_C_PTR(MDK_U_PTR(hdr) + aon[i]), 0) == (hash ^ MDK_KEY))
            {
                return MDK_C_PTR(MDK_U_PTR(hdr) + aof[aoo[i]]);
            }
        }
    }
    
    return NULL;
}

LPVOID MdkGetSyscallInstruction(LPVOID addr)
{
    for (DWORD i = 0; i < 500; ++i)
    {
        if (((PBYTE)addr + i)[0] == 0x0F && ((PBYTE)addr + i)[1] == 0x05)
        {
            return (PVOID)((PBYTE)addr + i);
        }
    }

    return NULL;
}

#ifdef __cplusplus
}
#endif

#endif // _MDK_H_