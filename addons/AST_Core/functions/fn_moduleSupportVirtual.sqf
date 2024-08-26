/* 
 * Author: Bohemia Interactive (Modified by Queen)
 * original function is BIS_fnc_moduleProjectile
 * Used by AST Stratagem system 
 * Modified to handle all stratagems, both air and ground support
 *
 * Arguments:
 * 0: position ATL <LOGIC> 
 * 1: type <ARRAY>
 * 2: isCAS <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [LOGIC, [bob, kevin], true] call ace_zeus_fnc_bi_moduleProjectile
 *
 * Public: No
 */


_pos = _this select 0;
_provider = _this select 1;
_isCAS = _this select 2;
if (_provider != "") then {
    _cfgAmmo = configfile >> "cfgammo" >> _provider;
    _posAmmo = +_pos;
    _posAmmo set [2,0];
    //_dir = direction _logic;
    _simulation = toLowerANSI gettext (configfile >> "cfgammo" >> _provider >> "simulation");
    _altitude = 0;
    _velocity = [];
    _attach = false;
    _radio = "";
    _delay = 60;
    _sound = "";
    _soundSourceClass = "";
    _hint = [];
    _shakeStrength = 0;
    _shakeRadius = 0;
    switch (_simulation) do {
        case "shotshell": {
            _altitude = 1000;
            _velocity = [0,0,-100];
            _radio = "SentGenIncoming";
            _sounds = if (getnumber (_cfgAmmo >> "hit") < 200) then {["mortar1","mortar2"]} else {["shell1","shell2","shell3","shell4"]};
            _sound = selectRandom _sounds;
            //_hint = ["Curator","PlaceOrdnance"];
            _shakeStrength = 0.01;
            _shakeRadius = 300;
        };
        case "shotsubmunitions": {
            _posAmmo = [_posAmmo,500,_dir + 180] call bis_fnc_relpos;
            _altitude = 1000 - ((getterrainheightasl _posAmmo) - (getterrainheightasl _pos));
            _posAmmo set [2,_altitude];
            _velocity = [sin _dir * 68,cos _dir * 68,-100];
            _radio = "SentGenIncoming";
            _hint = ["Curator","PlaceOrdnance"];
            _shakeStrength = 0.02;
            _shakeRadius = 500;
        };
        case "shotilluminating": {
            _altitude = 66;
            _velocity = [wind select 0,wind select 1,30];
            _sound = "SN_Flare_Fired_4";
            _soundSourceClass = "SoundFlareLoop_F";
        };
        case "shotnvgmarker";
        case "shotsmokex": {
            _altitude = 0;
            _velocity = [0,0,0];
            _attach = true;
        };
        default {["Ammo simulation '%1' is not supported",_simulation] call bis_fnc_error;};
    };
    if (count _velocity == 3) then {
        _altitude = _pos select 2;

        //--- Create projectile
        _posAmmo set [2,_altitude];
        _projectile = createvehicle [_provider,_posAmmo,[],0,"none"];
        _projectile setpos _posAmmo;
        _projectile setvelocity _velocity;
        //if (_attach) then {_projectile attachto [_logic,[0,0,_altitude]];};


        //--- Update
        if (_attach) then {
            waituntil {
                //_soundSource setposatl getposatl _projectile;
                sleep 1;
                isnull _projectile
            };
        }; 
        deletevehicle _projectile;
        //deletevehicle _soundSource;
        /*
        if (count objectcurators _logic > 0) then {
            deletevehicle _logic;
        } else {

            //--- Repeat to achieve permanent effect
            _repeat = _logic getvariable ["repeat",0] > 0;
            if (_repeat) then {
                [_logic,_units,_activated] call bis_fnc_moduleprojectile;
            } else {
                deletevehicle _logic;
            };
        };
        */
    } else {
        deletevehicle _logic;
    };
} else {
    ["Cannot create projectile, 'ammo' config attribute is missing in %1",typeof _logic] call bis_fnc_error;
};
