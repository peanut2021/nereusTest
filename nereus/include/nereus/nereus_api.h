/**
	Nererus Software Development Kit API
**/

#ifndef NEREUS_API_H
#define NEREUS_API_H

#define SODIUM_STATIC
#include "../nereusdef.h"
#include "../data_types.h"

#ifdef __cplusplus
extern "C"
{
#endif
	//device Management
	nereusError NEREUSAPI nereusDeviceInit();										   //device initialization: connect the device with host
	nereusError NEREUSAPI nereusDeviceGetAttribute(int *value, nereusDeviceAttr attr); //get the deivce attribute

	//memory management
	nereusError NEREUSAPI nereusDataFree(const DEVICEDATANAME &dataName, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);																		//Free memory on the device
	nereusError NEREUSAPI nereusDataAlloc(DEVICEDATANAME &dataName, const DEVICEDATA_SIZE size, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);												//Allocate memory on the device
	nereusError NEREUSAPI nereusDataCpy(const DEVICEDATANAME &dataName, void *src, const DEVICEDATA_SIZE size, const nereusDatacpyKind kind, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key); //copies data between host and device
	nereusError NEREUSAPI nereusDataSet(const DEVICEDATANAME &dataName, const int value, const DEVICEDATA_SIZE size, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);							//Initializes or sets device memory to a value
	nereusError NEREUSAPI nereusGetDataList(DEVICEDATANAME *&dataNameList, int &listSize, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);													//Get memory list on the device, use with nereusFreeList
	nereusError NEREUSAPI nereusDataReset(const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);																									//Free all Memory on the device

	//kernel management
	nereusError NEREUSAPI nereusKernelDeploy(DEVICEKERNELNAME &kernelName, const char *kernelSourceName, const nereusKernelType kernelType, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);	  //Free kernel on the device
	nereusError NEREUSAPI nereusKernelUndeploy(const DEVICEKERNELNAME &kernelName, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);															  //Allocate memory on the device
	nereusError NEREUSAPI nereusKernelCall(const DEVICEKERNELNAME &kernelName, int argc, const char **argv, const nereusKernelType kernelType, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key); //copies kernel between host and device
	nereusError NEREUSAPI nereusGetKernelList(DEVICEKERNELNAME *&kernelNameList, int &listSize, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);												  //Get kernel list on the device, use with nereusFreeList
	nereusError NEREUSAPI nereusKernelReset(const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);																									  //Free all Kernel on the device

	//user management
	nereusError NEREUSAPI nereusUserRegist(const NEREUSUSERNAME &user, NEREUSUSERKEY &key);											 //Regist user on the device
	nereusError NEREUSAPI nereusUserUnRegist(const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);									 //UnRegist user on the device
	nereusError NEREUSAPI nereusUserUpdateName(const NEREUSUSERNAME &newUser, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key); //Update user name on the device
	nereusError NEREUSAPI nereusUserUpdateKey(NEREUSUSERKEY &newKey, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);			 //Get new user key from the device

	nereusError NEREUSAPI nereusAuthorizeData(const DEVICEDATANAME &dataName, const NEREUSUSERNAME &user, const DEVICEKERNELNAME &authorizedKernelName, const NEREUSUSERNAME &owner, const NEREUSUSERKEY &key);		//Authorize data from owner to user kernel
	nereusError NEREUSAPI nereusAuthorizeKernel(const DEVICEKERNELNAME &kernelName, const NEREUSUSERNAME &user, const DEVICEDATANAME &authorizedDataName, const NEREUSUSERNAME &owner, const NEREUSUSERKEY &key);	//Authorize kernel from owner to user data
	nereusError NEREUSAPI nereusUnauthorizeData(const DEVICEDATANAME &dataName, const NEREUSUSERNAME &user, const DEVICEKERNELNAME &authorizedKernelName, const NEREUSUSERNAME &owner, const NEREUSUSERKEY &key);	//Unauthorize data from owner to user kernel
	nereusError NEREUSAPI nereusUnauthorizeKernel(const DEVICEKERNELNAME &kernelName, const NEREUSUSERNAME &user, const DEVICEDATANAME &authorizedDataName, const NEREUSUSERNAME &owner, const NEREUSUSERKEY &key); //Unauthorize kernel from owner to user data
	nereusError NEREUSAPI nereusGetAuthorizedData(DEVICEDATANAME *&dataNameList, DEVICEKERNELNAME *&kernelNameList, int &listSize, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);							//Get data list on the device, use with nereusFreeList
	nereusError NEREUSAPI nereusGetAuthorizedKernel(DEVICEKERNELNAME *&kernelNameList, DEVICEKERNELNAME *&dataNameList, int &listSize, const NEREUSUSERNAME &user, const NEREUSUSERKEY &key);						//Get kernel list on the device, use with nereusFreeList

	//Attestaton
	nereusError NEREUSAPI nereusAttestatonServerInit(); //set attestaton server address
	nereusError NEREUSAPI nereusAttestatonDevice();		//device attestation

	//Other
	nereusError NEREUSAPI nereusFreeList(DEVICEDATANAME *&nameList); //Free memory list
#ifdef __cplusplus
}
#endif
//TODO: NEREUSAPI nereusDataCpyAsync(const DEVICEDATANAME& devPtr, void* const src, DEVICEDATA_SIZE size, nereusDatacpyKind kind); //copies data between host and device async
//TODO: NEREUSAPI nereusDataSetAsync(const DEVICEDATANAME& devPtr, int value, DEVICEDATA_SIZE size); //Initilizes or sets device memory to a value async
#endif