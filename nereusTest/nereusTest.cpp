#include "nereus/nereus_api.h"
#include <iostream>
#include <string>

typedef struct
{
	int Age;
	float UnsecuredLines;
	int NumberOffTime30to59;
	int NumberOffTime60to89;
	int NumberOffTime90orMore;
} PersenInfo;
int main()
{
    	nereusError ret = nereusDeviceInit();
	if (ret != nereusError::nereusSuccess)
		return -1;

	NEREUSUSERNAME userA = "idea_test_user_a";
	NEREUSUSERNAME userB = "idea_test_user_b";
	NEREUSUSERNAME userB1 = "idea_test_user_b1";
	NEREUSUSERKEY userkeyA, userkeyB;
	ret = nereusUserRegist(userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	ret = nereusUserRegist(userB, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;
    std::cout<<"userkeyA= " << userkeyA<<std::endl;
    std::cout<<"userkeyB= " << userkeyB<<std::endl;

	ret = nereusUserUpdateKey(userkeyA, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	PersenInfo persen1{41, 0.617351763, 4, 0, 1};
	PersenInfo persen2{58, 0.084175501, 0, 0, 0};
	char *argvs0, *argvs1;
	argvs0 = (char *)(&persen1);
	argvs1 = (char *)(&persen2);

	DEVICEDATANAME memName[2];

	DEVICEDATA_SIZE size = sizeof(PersenInfo);

	char kernelFileName[] = "sourceClient.py";

	ret = nereusDataAlloc(memName[0], size, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	ret = nereusDataSet(memName[0], 0, size, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	ret = nereusDataCpy(memName[0], argvs0, size, nereusDatacpyKind::nereusDatacpyHostToDevice, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusDataAlloc(memName[1], size, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	ret = nereusDataSet(memName[1], 0, size, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	ret = nereusDataCpy(memName[1], argvs1, size, nereusDatacpyKind::nereusDatacpyHostToDevice, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	DEVICEKERNELNAME kerName;
	ret = nereusKernelDeploy(kerName, kernelFileName, nereusKernelType::nereusPython, userB, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusAuthorizeData(memName[0], userB,kerName, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	ret = nereusAuthorizeData(memName[1], userB,kerName, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
	//Get Lists to check data
	DEVICEDATANAME *dataNameListA = nullptr;
	
	int listSizeA = 0;
	nereusGetDataList(dataNameListA, listSizeA, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
    
    std::cout<<"listSizeA is " << listSizeA<<std::endl;//should be 2
	nereusFreeList(dataNameListA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	DEVICEDATANAME *dataNameListB = nullptr;
	int listSizeB = 0;
	ret = nereusGetDataList(dataNameListB, listSizeB, userB, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;
    std::cout<<"listSizeB is " << listSizeB<<std::endl;//should be 0
	ret = nereusFreeList(dataNameListB);
	if (ret != nereusError::nereusSuccess)
		return -1;

	DEVICEDATANAME *authorizedDataNameListA = nullptr;
	DEVICEDATANAME *authorizedKernelNameListA = nullptr;
	int authorizedListSizeA = 0;
	ret = nereusGetAuthorizedData(authorizedDataNameListA,authorizedKernelNameListA, authorizedListSizeA, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;
    std::cout<<"authorized listSizeA is " << authorizedListSizeA<<std::endl;//should be 0
	ret = nereusFreeList(authorizedDataNameListA);
	ret = nereusFreeList(authorizedKernelNameListA);

	if (ret != nereusError::nereusSuccess)
		return -1;
	DEVICEDATANAME *authorizedDataNameListB = nullptr;
	DEVICEDATANAME *authorizedKernelNameListB = nullptr;
	int authorizedListSizeB = 0;
	ret = nereusGetAuthorizedData(authorizedDataNameListA,authorizedKernelNameListB, authorizedListSizeB, userB, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;
    std::cout<<"authorized listSizeB is " << authorizedListSizeB<<std::endl;//should be 2
	ret = nereusFreeList(authorizedDataNameListB);
	ret = nereusFreeList(authorizedKernelNameListB);
	if (ret != nereusError::nereusSuccess)
		return -1;


	ret = nereusUserUpdateName(userB1,userB, userkeyB); 

	const char *paras[3];
	paras[0] = memName[0];
	paras[1] = memName[1];
	std::string par1 = "666";
	paras[2] = par1.c_str();
	ret = nereusKernelCall(kerName, 3, paras, nereusKernelType::nereusPython, userB1, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusKernelUndeploy(kerName, userB1, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusUnauthorizeData(memName[0], userB1,kerName, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusUnauthorizeData(memName[1], userB1,kerName, userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusDataFree(memName[0], userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusDataFree(memName[1], userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	//Get Lists to check data
	authorizedDataNameListB = nullptr;
	authorizedKernelNameListB = nullptr;
	authorizedListSizeB = 0;
	ret = nereusGetAuthorizedData(authorizedDataNameListB,authorizedKernelNameListB, authorizedListSizeB, userB1, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;
	std::cout<<"authorized listSizeB is " << authorizedListSizeB<<std::endl;//should be 0
	ret = nereusFreeList(authorizedDataNameListB);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusUserUnRegist(userA, userkeyA);
	if (ret != nereusError::nereusSuccess)
		return -1;

	ret = nereusUserUnRegist(userB1, userkeyB);
	if (ret != nereusError::nereusSuccess)
		return -1;
    return 0;
}