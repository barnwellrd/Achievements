#include <API/ARK/Ark.h>

//Add additional Hooks and Commands as their own files
#include "Hook_HandleNewPlayer.h"


#pragma comment(lib, "ArkApi.lib")

//Set all hooks here
void InitHooks()
{
	ArkApi::GetHooks().SetHook("AShooterGameMode.HandleNewPlayer_Implementation", &Hook_AShooterGameMode_HandleNewPlayer, &AShooterGameMode_HandleNewPlayer_original);
}

//Remove all hooks here
void RemoveHooks()
{
	ArkApi::GetHooks().DisableHook("AShooterGameMode.HandleNewPlayer_Implementation", &Hook_AShooterGameMode_HandleNewPlayer);
}

//Set all commands here
void InitCommands()
{

}

//Remove all commands here
void RemoveCommands()
{

}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Log::Get().Init("Achievements");
		InitHooks();
		InitCommands();
		break;
	case DLL_PROCESS_DETACH:
		RemoveHooks();
		RemoveCommands();
		break;
	}
	return TRUE;
}


