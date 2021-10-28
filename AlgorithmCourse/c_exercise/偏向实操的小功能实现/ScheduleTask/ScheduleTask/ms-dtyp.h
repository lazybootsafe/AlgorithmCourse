

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 21:14:07 2038
 */
/* Compiler settings for ms-dtyp.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __ms2Ddtyp_h__
#define __ms2Ddtyp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ms2Ddtyp_0000_0000 */
/* [local] */ 

typedef int BOOL;

typedef int *PBOOL;

typedef int *LPBOOL;

typedef unsigned char BYTE;

typedef unsigned char *PBYTE;

typedef unsigned char *LPBYTE;

typedef BYTE BOOLEAN;

typedef BYTE *PBOOLEAN;

typedef wchar_t WCHAR;

typedef wchar_t *PWCHAR;

typedef WCHAR *BSTR;

typedef double DOUBLE;

typedef unsigned long DWORD;

typedef unsigned long *PDWORD;

typedef unsigned long *LPDWORD;

typedef unsigned int DWORD32;

typedef unsigned __int64 DWORD64;

typedef unsigned __int64 ULONGLONG;

typedef ULONGLONG DWORDLONG;

typedef ULONGLONG *PDWORDLONG;

typedef unsigned long error_status_t;

typedef float FLOAT;

typedef unsigned char UCHAR;

typedef unsigned char *PUCHAR;

typedef short SHORT;

typedef void *HANDLE;

typedef DWORD HCALL;

typedef int INT;

typedef int *LPINT;

typedef signed char INT8;

typedef short INT16;

typedef int INT32;

typedef __int64 INT64;

typedef const wchar_t *LMCSTR;

typedef WCHAR *LMSTR;

typedef long LONG;

typedef long *PLONG;

typedef long *LPLONG;

typedef INT64 LONGLONG;

typedef LONG HRESULT;

typedef int LONG32;

typedef __int64 LONG64;

typedef const wchar_t *LPCWSTR;

typedef wchar_t *LPWSTR;

typedef wchar_t *PWSTR;

typedef DWORD NET_API_STATUS;

typedef long NTSTATUS;

typedef unsigned __int64 QWORD;

typedef void *RPC_BINDING_HANDLE;

typedef UCHAR *STRING;

typedef unsigned int UINT;

typedef unsigned char UINT8;

typedef unsigned short UINT16;

typedef unsigned int UINT32;

typedef unsigned __int64 UINT64;

typedef unsigned long ULONG;

typedef unsigned long *PULONG;

typedef /* [custom][public] */ __int3264 INT_PTR;

typedef /* [custom][public] */ unsigned __int3264 UINT_PTR;

typedef /* [custom][public] */ __int3264 LONG_PTR;

typedef /* [custom][public] */ unsigned __int3264 ULONG_PTR;

typedef ULONG_PTR DWORD_PTR;

typedef ULONG_PTR SIZE_T;

typedef unsigned int ULONG32;

typedef unsigned __int64 ULONG64;

typedef unsigned short USHORT;

//typedef void VOID;

typedef void *PVOID;

typedef void *LPVOID;

typedef unsigned short WORD;

typedef unsigned short *PWORD;

typedef unsigned short *LPWORD;

typedef DWORD LCID;

typedef struct _RPC_UNICODE_STRING
    {
    unsigned short Length;
    unsigned short MaximumLength;
    /* [length_is][size_is] */ WCHAR *Buffer;
    } 	RPC_UNICODE_STRING;

typedef struct _RPC_UNICODE_STRING *PRPC_UNICODE_STRING;

typedef struct _UINT128
    {
    UINT64 lower;
    UINT64 upper;
    } 	UINT128;

typedef struct _UINT128 *PUINT128;

typedef struct _RPC_SID_IDENTIFIER_AUTHORITY
    {
    BYTE Value[ 6 ];
    } 	RPC_SID_IDENTIFIER_AUTHORITY;

typedef DWORD ACCESS_MASK;

typedef ACCESS_MASK *PACCESS_MASK;

typedef DWORD SECURITY_INFORMATION;

typedef DWORD *PSECURITY_INFORMATION;

typedef struct _RPC_SID
    {
    unsigned char Revision;
    unsigned char SubAuthorityCount;
    RPC_SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
    unsigned long SubAuthority[ 1 ];
    } 	RPC_SID;

typedef struct _RPC_SID *PRPC_SID;

//typedef struct _GUID
//    {
//    unsigned long Data1;
//    unsigned short Data2;
//    unsigned short Data3;
//    byte Data4[ 8 ];
//    } 	GUID;

typedef struct _GUID UUID;

typedef struct _GUID *PGUID;

//typedef struct _FILETIME
//    {
//    DWORD dwLowDateTime;
//    DWORD dwHighDateTime;
//    } 	FILETIME;

typedef struct _FILETIME *PFILETIME;

typedef struct _FILETIME *LPFILETIME;

//typedef struct _ULARGE_INTEGER
//    {
//    unsigned __int64 QuadPart;
//    } 	ULARGE_INTEGER;

//typedef struct _ULARGE_INTEGER *PULARGE_INTEGER;

//typedef struct _LARGE_INTEGER
//    {
//    __int64 QuadPart;
//    } 	LARGE_INTEGER;
//
//typedef struct _LARGE_INTEGER *PLARGE_INTEGER;



extern RPC_IF_HANDLE __MIDL_itf_ms2Ddtyp_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ms2Ddtyp_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


