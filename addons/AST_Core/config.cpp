#include "script_component.hpp"

class CfgPatches
{
    class AST_Core
    {
        units[] = 
        {

        };
        weapons[] = 
        {
            "AST_SmokeGrenade_Throw"
        };
		requiredAddons[] =
		{
			"A3_Weapons_F",
		};
    };
};

#include "CfgEventHandlers.hpp"

class CfgCloudlets
{
    class Default;
    class AST_155_Explosion: Default
    {
        circleVelocity[] = {0,0,0};
		moveVelocity[] = {0,0,0};
		size[] = {10,10};
		color[] = {{ 0,0,0,0}};
		animationSpeed[] = {1000};
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {1.75,1.75,1.75};
		colorVar[] = {0,0,0,0.02};
		interval = "0.007 * interval + 0.007";
		circleRadius = "intensity";
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 2;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 0.05;
		lifeTime = 0.5;
		rotationVelocity = 0;
		weight = 4;
		volume = 1;
		rubbing = 0;
		randomDirectionPeriod = 0.01;
		randomDirectionIntensity = 0.08;
		onTimerScript = "\AST_Core\scripts\155HE.sqf";
		beforeDestroyScript = "";
		lifeTimeVar = 0;
		rotationVelocityVar = 1;
		sizeVar = 0;
		randomDirectionPeriodVar = 2;
		randomDirectionIntensityVar = 0.1;
    };
};

class AST_Explosion
{
    class AST_Crater
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "AST_155_Explosion";
		intensity = 1;
		interval = 0.25;
		lifeTime = 0.25;
		particleFSLoop = 0;
	};
};

class CfgAmmo
{
	class Default;
	class Grenade : Default {};
	class GrenadeHand : Grenade {};
	class GrenadeCore: Default {};
	class GrenadeBase: GrenadeCore {};
	class AST_SmokeGrenade_Ammo: GrenadeHand
	{
		CraterEffects = "AST_Explosion";
		model = "\A3\Weapons_f\ammo\smokegrenade_white_throw";
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 75;
		dangerRadiusHit = -1;
		suppressionRadiusHit = -1;
		typicalspeed = 22;
		cost = 100;
		simulation = "shotGrenade";
		explosive = 1;
		deflecting = 30;
		explosionTime = 2;
		timeToLive = 60;
		fuseDistance = 0;
		soundHit[] = {"",0,1};
		SmokeShellSoundHit1[] = {"A3\Sounds_F\weapons\smokeshell\smoke_1",1.2589254,1,100};
		SmokeShellSoundHit2[] = {"A3\Sounds_F\weapons\smokeshell\smoke_2",1.2589254,1,100};
		SmokeShellSoundHit3[] = {"A3\Sounds_F\weapons\smokeshell\smoke_3",1.2589254,1,100};
		SmokeShellSoundLoop1[] = {"A3\Sounds_F\weapons\smokeshell\smoke_loop1",0.12589253,1,70};
		SmokeShellSoundLoop2[] = {"A3\Sounds_F\weapons\smokeshell\smoke_loop2",0.12589253,1,70};
		grenadeFireSound[] = {"SmokeShellSoundHit1",0.25,"SmokeShellSoundHit2",0.25,"SmokeShellSoundHit3",0.5};
		grenadeBurningSound[] = {"SmokeShellSoundLoop1",0.5,"SmokeShellSoundLoop2",0.5};
		aiAmmoUsageFlags = "4 + 2";
		smokeColor[] = {0.8438,0.1383,0.1353,1};
		effectsSmoke = "SmokeShellRedEffect";
		whistleDist = 0;
	};
};

class CfgMagazines
{
	class Default;	
	class CA_Magazine : Default {};
	class HandGrenade : CA_Magazine {};
	class AST_SmokeGrenade_Mag: HandGrenade
	{
		author = "Queen";
		scope = 2;
		displayName = "Support Grenade (155)";
		displayNameShort = "CALL 155";
		picture = "\A3\Weapons_f\data\ui\gear_smokegrenade_red_ca.paa";
		model = "\A3\Weapons_f\ammo\smokegrenade_red";
		ammo = "AST_SmokeGrenade_Ammo";
	};
};

class CfgWeapons
{
	class Default;
	class GrenadeLauncher : Default {};
	class Throw : GrenadeLauncher 
	{
		muzzles[] = {"AST_Stratagem_Muzzle"};

		class AST_Stratagem_Muzzle: GrenadeLauncher
		{
			cursor = "EmptyCursor";
			cursorAim = "throw";
			sound[] = {"",0.00031622776,1};
			reloadSound[] = {"",0.00031622776,1};
			aiDispersionCoefX = 6;
			aiDispersionCoefY = 6;
			reloadTime = 0;
			magazineReloadTime = 2.5;
			enableAttack = 0;
			showEmpty = 0;
			autoReload = 1;
			modelOptics = "";
			minRange = 10;
			minRangeProbab = 0.2;
			midRange = 45;
			midRangeProbab = 0.9;
			maxRange = 60;
			maxRangeProbab = 0.03;
			keepInInventory = 1;
			magazines[] = {"AST_SmokeGrenade_Mag"};
		
		};
	};
};