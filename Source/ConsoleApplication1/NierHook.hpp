#ifndef NIERHOOK_H
#define NIERHOOK_H
class NieRHook;

enum GameVersion{STEAM,UWP};
class NieRHook
{
private:
	//Attributes
	DWORD _pID;
	uintptr_t _baseAddress;
	uintptr_t _entityAddress;
	bool _hooked;
	//Game Version
	GameVersion GameVersion;
	//Player Attributes
	int Level;
	int Health;
	int MaxHealth;
	float Xpos;
	float Ypos;
	float Zpos;
	int Funds;
	int EXP;
	//Methods
	void _hook(void);
	void _unHook(void);
	DWORD _getProcessID(void);
	uintptr_t _getModuleBaseAddress(DWORD procId, const wchar_t *modName);
	void _updatePosition(void);
	void _updateHealth(void);
	void _updateEntity(void);
	void _updateLevel(void);
	void _updateFunds(void);
	void _updateEXP(void);
	void Nop(BYTE *destination, unsigned int size, HANDLE hProcess);
	void Patch(BYTE *destination, BYTE *src, unsigned int size, HANDLE hProcess);

	void checkGameVersion(DWORD PID);

public:
	NieRHook();
	~NieRHook();
	void start(void); //Start hook
	void stop(void);  //Reset hook
	bool isHooked(void);
	void hookStatus(void);
	DWORD getProcessID(void); //Returns process id

	void update(void); //Update Player Attributes

	//Getters
	int getLevel(void);
	int getHealth(void);
	int getMaxHealth(void);
	int getFunds(void);
	int getEXP(void);
	float getXPosition(void);
	float getYPosition(void);
	float getZPosition(void);
	inline int getGameVersion() {return this->GameVersion;}

	//Setters
	void setPosition(float X, float Y, float Z);
	void setHealth(int health);

	//Cheats
	void NoCLip(bool enabled);
	void InfiniteDoubleJump(bool enabled);
	void setGameSpeed(float speed);
	void NoCooldown(bool enabled);
	void InfiniteAirDash(bool enabled);
	void IgnoreUpgradeMaterials(bool enabled);
	void FreeCamera(bool enabled);

	//Inventory
	bool addItem(int ID, int number);
	bool removeItem(int ID);
	bool addWeapon(int ID, int level);
	bool removeWeapon(int ID);

	//Misc
	void setHUDOpacity(float opacity);
	void setColor(float R, float G, float B);
};

#endif