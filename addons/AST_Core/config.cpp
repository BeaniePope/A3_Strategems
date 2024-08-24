class CfgPatches
{
    class AST_Core
    {
        units[] = 
        {

        };
        weapons[] = 
        {
            "CAS_A10",   
        };
    };
};

class CfgFunctions
{
	class AST
	{
		tag = "AST";
		class functions
		{
			class moduleSupportVirtual {};
		};
	};
};

class CfgCloudlets
{
    class Default;
    class FS_105_HE_Eff: Default
    {
        circleVelocity[] = {0,0,0};\
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
		onTimerScript = ""; 
		beforeDestroyScript = "\AST_Core\scripts\105HE.sqf";
		lifeTimeVar = 0;
		rotationVelocityVar = 1;
		sizeVar = 0;
		randomDirectionPeriodVar = 2;
		randomDirectionIntensityVar = 0.1;
    };
};

class AST_Explosion
{
    class GrenadeExp1
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "CAS_A10_Eff";
		intensity = 1;
		interval = 0.25;
		lifeTime = 0.25;
		particleFSLoop = 0;
	};
}