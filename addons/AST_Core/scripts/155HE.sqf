private _check = missionNamespace getVariable "AST_initialParticle";

if (_check) then 
{
    [_this, "Sh_155mm_AMOS", 1] spawn BIS_fnc_fireSupportVirtual;
}
else
{
    AST_initialParticle = true;
    publicVariable = "AST_initialParticle";
    publicVariableClient "AST_initialParticle";
    publicVariableServer "AST_initialParticle";
};