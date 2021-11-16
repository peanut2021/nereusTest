#pragma once
#ifndef NEREUS_DATA_TYPES_H
#define NEREUS_DATA_TYPES_H

#include <stdint.h>
#include <inttypes.h>

enum class nereusDeviceAttr
{
	nereusTotalMemory = 1,
	nereusAvailableMemory = 2,
	nereusMaxThreads = 3,
	nereusCores = 4,
	nereusPCIeMaxBandwidth = 5
};

enum class nereusError
{
	nereusSuccess = 0,
	nereusErrorInvalidValue = 1,
	nereusErrorDataAllocation = 2,
	nereusErrorInitializationError = 3,
	nereusErrorInvalidConfuguration = 4,
	nereusErrorInvalidSymbol = 5,
	nereusErrorInvalidDeviceFunction = 6,
	nereusErrorInvalidDevice = 7,
	nereusErrorDeviceUninitialized = 8,
	nereusErrorDeviceTimeout = 9,
	nereusErrorDeviceInternalError = 10,
	nereusErrorDataName = 11,
	nereusErrorDataSize = 12,
	nereusErrorKeyError = 13,
	nereusErrorTypeError = 14,
	nereusErrorAttestationError = 15,
	nereusErrorPythonCallError = 16,
	nereusErrorKernelDeploy = 17,
	nereusErrorKernelUndeploy = 18,
	nereusErrorKernelCall = 19,
	nereusErrorDataSetting = 20,
	nereusErrorUserAlreadyExisted = 21,
	nereusErrorUserNonExisted = 22,
	nereusErrorUserRegist = 23,
	nereusErrorUserUnregist = 24,
	nereusErrorDataAuthorize = 25,
	nereusErrorDataUnauthorize = 26,
	nereusErrorKeyValidation = 27,
	nereusErrorKernelAuthorize = 28,
	nereusErrorKernelUnauthorize = 29,
	nereusErrorDataNonExisted = 30,
	nereusErrorKernelNonExisted = 31,
	nereusErrorUserNotOwnData = 32,
	nereusErrorUserNotOwnKernel = 33,
	nereusErrorMessageForm = 34,
	nereusErrorExcessiveThread = 35,
	nereusErrorMessageLength = 36,
	nereusErrorKernelName = 37,
	nereusErrorOtherError = 38
};

enum class nereusDatacpyKind
{
	nereusDatacpyHostToDevice = 0,
	nereusDatacpyDeviceToHost = 1,
};

enum class nereusSymCryptoMethod
{
	AES = 0
};

enum class nereusAsymCryptoMethod
{
	RSA = 0
};

enum class nereusRequestType
{
	nereusDataAlloc = 0,
	nereusDataCpy = 1,
	nereusDataSet = 2,
	nereusDataFree = 3,
	nereusKerneDeploy = 4,
	nereusKernelUndeploy = 5,
	nereusKernelReset = 6,
	nereusKernelCall = 7,
	attestationToDevice = 8,
	attestationToNAS = 9
};

enum class nereusKernelType
{
	nereusPython = 0,
	nereusCplusplus = 1
};
#endif
