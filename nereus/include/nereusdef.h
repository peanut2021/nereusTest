#pragma once
#ifndef NEREUSDEF_H
#define NEREUSDEF_H

#include <stdlib.h>

typedef char DEVICEDATANAME[256];
typedef char DEVICEDATAFULLFILENAME[256];
typedef char DEVICEKERNELNAME[256];
typedef char DEVICEKERNELFULLFILENAME[256];
typedef char NEREUSUSERNAME[256];
typedef char NEREUSUSERKEY[256];
typedef const char DEVICEPROVISIONNAME[10];

typedef size_t DEVICEDATA_SIZE;
typedef size_t DEVICEKERNEL_SIZE;

#define NEREUSMEMALLOC "nereusDataAlloc"
#define NEREUSMEMSET "nereusDataSet"
#define NEREUSMEMCPYTODEV "nereusDataCpyToDev"
#define NEREUSMEMCPYFROMDEV "nereusDataCpyFromDev"
#define NEREUSMEMFREE "nereusDataFree"
#define NEREUSCPPKERNELCALL "nereusCppKernelCall"
#define NEREUSPYKENELCALL "nereusPythonKernelCall"
#define NEREUSKENELDEPLOY "nereusKerneDeploy"
#define NEREUSKENELUNDEPLOY "nereusKerneUnDeploy"
#define NEREUSATTESTATION "nereusAttestation"
#define NEREUSUSERREGIST "nereusUserRegist"
#define NEREUSUSERUNREGIST "nereusUserUnRegist"
#define NEREUSAUTHORIZEDATA "nereusAuthorizeData"
#define NEREUSAUTHORIZEKERNEL "nereusAuthorizeKernel"
#define NEREUSUNAUTHORIZEDATA "nereusUnauthorizeData"
#define NEREUSUNAUTHORIZEKERNEL "nereusUnauthorizeKernel"

#define NEREUSGETDATALIST "nereusGetDataList"
#define NEREUSGETKERNELLIST "nereusGetKernelList"
#define NEREUSGETAUTHORIZEDDATA "nereusGetAuthorizedData"
#define NEREUSGETAUTHORIZEDKERNEL "nereusGetAuthorizedKernel"

#define NEREUSUSERUPDATENAME "nereusUserUpdateName"
#define NEREUSUSERUPDATEKEY "nereusUserUpdateKey"

#define NEREUSDATARESET "nereusDataReset"
#define NEREUSKERNELRESET "nereusKernelReset"

#define EXCHANGEKEYPLEASE "ExchangeKeyPlease"
#define ENCRYPTEDPK "EncryptedPk"

#define NEREUSSESSIONHEAD "NereusSession"
#define NEREUSSESSIONNULL "0000000000"

#define NEREUSEXCESSIVETHREAD "TooMuchConcurrency"

#define RESPMESSAGEMAXLENGTH 4096
#define CLIENT_MESSAGE_MAX_LENGTH 4096
#define ATTESTATION_MESSAGE_MAX_LENGTH 4096

#define SESSIONIDLEN 10

#include "data_types.h"

#ifdef _WIN32
#define NEREUSAPI __cdecl
#else
#define NEREUSAPI
#endif

#endif
