#pragma once

enum ECstrike15UserMessages
{
    CS_UM_VGUIMenu = 1,
    CS_UM_Geiger = 2,
    CS_UM_Train = 3,
    CS_UM_HudText = 4,
    CS_UM_SayText = 5,
    CS_UM_SayText2 = 6,
    CS_UM_TextMsg = 7,
    CS_UM_HudMsg = 8,
    CS_UM_ResetHud = 9,
    CS_UM_GameTitle = 10,
    CS_UM_Shake = 12,
    CS_UM_Fade = 13,
    CS_UM_Rumble = 14,
    CS_UM_CloseCaption = 15,
    CS_UM_CloseCaptionDirect = 16,
    CS_UM_SendAudio = 17,
    CS_UM_RawAudio = 18,
    CS_UM_VoiceMask = 19,
    CS_UM_RequestState = 20,
    CS_UM_Damage = 21,
    CS_UM_RadioText = 22,
    CS_UM_HintText = 23,
    CS_UM_KeyHintText = 24,
    CS_UM_ProcessSpottedEntityUpdate = 25,
    CS_UM_ReloadEffect = 26,
    CS_UM_AdjustMoney = 27,
    CS_UM_UpdateTeamMoney = 28,
    CS_UM_StopSpectatorMode = 29,
    CS_UM_KillCam = 30,
    CS_UM_DesiredTimescale = 31,
    CS_UM_CurrentTimescale = 32,
    CS_UM_AchievementEvent = 33,
    CS_UM_MatchEndConditions = 34,
    CS_UM_DisconnectToLobby = 35,
    CS_UM_PlayerStatsUpdate = 36,
    CS_UM_DisplayInventory = 37,
    CS_UM_WarmupHasEnded = 38,
    CS_UM_ClientInfo = 39,
    CS_UM_XRankGet = 40,
    CS_UM_XRankUpd = 41,
    CS_UM_CallVoteFailed = 45,
    CS_UM_VoteStart = 46,
    CS_UM_VotePass = 47,
    CS_UM_VoteFailed = 48,
    CS_UM_VoteSetup = 49,
    CS_UM_ServerRankRevealAll = 50,
    CS_UM_SendLastKillerDamageToClient = 51,
    CS_UM_ServerRankUpdate = 52,
    CS_UM_ItemPickup = 53,
    CS_UM_ShowMenu = 54,
    CS_UM_BarTime = 55,
    CS_UM_AmmoDenied = 56,
    CS_UM_MarkAchievement = 57,
    CS_UM_MatchStatsUpdate = 58,
    CS_UM_ItemDrop = 59,
    CS_UM_GlowPropTurnOff = 60,
    CS_UM_SendPlayerItemDrops = 61,
    CS_UM_RoundBackupFilenames = 62,
    CS_UM_SendPlayerItemFound = 63,
    CS_UM_ReportHit = 64,
    CS_UM_XpUpdate = 65,
    CS_UM_QuestProgress = 66,
    CS_UM_ScoreLeaderboardData = 67,
    CS_UM_PlayerDecalDigitalSignature = 68,
    MAX_ECSTRIKE15USERMESSAGES
};


enum ItemDefinitionIndex
{
    ITEM_NONE = 0,
    WEAPON_DEAGLE = 1,
    WEAPON_ELITE = 2,
    WEAPON_FIVESEVEN = 3,
    WEAPON_GLOCK = 4,
    WEAPON_AK47 = 7,
    WEAPON_AUG = 8,
    WEAPON_AWP = 9,
    WEAPON_FAMAS = 10,
    WEAPON_G3SG1 = 11,
    WEAPON_GALILAR = 13,
    WEAPON_M249 = 14,
    WEAPON_M4A1 = 16,
    WEAPON_MAC10 = 17,
    WEAPON_P90 = 19,
    WEAPON_UMP45 = 20,
    WEAPON_XM1014 = 21,
    WEAPON_BIZON = 22,
    WEAPON_MAG7 = 23,
    WEAPON_NEGEV = 24,
    WEAPON_SAWEDOFF = 25,
    WEAPON_TEC9 = 26,
    WEAPON_TASER = 27,
    WEAPON_HKP2000 = 28,
    WEAPON_MP7 = 29,
    WEAPON_MP9 = 30,
    WEAPON_NOVA = 31,
    WEAPON_P250 = 32,
    WEAPON_SCAR20 = 33,
    WEAPON_SG556 = 34,
    WEAPON_SSG08 = 35,
    WEAPON_KNIFE = 36,
    WEAPON_FLASHBANG = 37,
    WEAPON_HEGRENADE = 38,
    WEAPON_SMOKEGRENADE = 39,
    WEAPON_MOLOTOV = 40,
    WEAPON_DECOY = 41,
    WEAPON_INCGRENADE = 42,
    WEAPON_C4 = 43,
    WEAPON_KNIFE_T = 44,
    WEAPON_M4A1_SILENCER = 45,
    WEAPON_USP_SILENCER = 46,
    WEAPON_CZ75A = 47,
    WEAPON_REVOLVER = 48,
    WEAPON_BAYONET = 500,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT = 506,
    WEAPON_KNIFE_KARAMBIT = 507,
    WEAPON_KNIFE_M9_BAYONET = 508,
    WEAPON_KNIFE_TACTICAL = 509,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY = 515,
    WEAPON_KNIFE_PUSH = 516,
    GLOVE_STUDDED_BLOODHOUND = 5027,
    GLOVE_T_SIDE = 5028,
    GLOVE_CT_SIDE = 5029,
    GLOVE_SPORTY = 5030,
    GLOVE_SLICK = 5031,
    GLOVE_LEATHER_WRAP = 5032,
    GLOVE_MOTORCYCLE = 5033,
    GLOVE_SPECIALIST = 5034,
    MAX_ITEMDEFINITIONINDEX
};

enum ClassId
{
	ClassId_NextBotCombatCharacter = 0,
	ClassId_CWeaponCubemap = 0,
	ClassId_CPropVehicleChoreoGeneric = 0,
	ClassId_CItemAssaultSuitUseable = 0,
	ClassId_CItem = 0,
	ClassId_CAI_BaseNPC = 0,
	ClassId_CAK47 = 1,
	ClassId_CBaseAnimating = 2,
	ClassId_CBaseAnimatingOverlay = 3,
	ClassId_CBaseAttributableItem = 4,
	ClassId_CBaseButton = 5,
	ClassId_CBaseCombatCharacter = 6,
	ClassId_CBaseCombatWeapon = 7,
	ClassId_CBaseCSGrenade = 8,
	ClassId_CBaseCSGrenadeProjectile = 9,
	ClassId_CBaseDoor = 10,
	ClassId_CBaseEntity = 11,
	ClassId_CBaseFlex = 12,
	ClassId_CBaseGrenade = 13,
	ClassId_CBaseParticleEntity = 14,
	ClassId_CBasePlayer = 15,
	ClassId_CBasePropDoor = 16,
	ClassId_CBaseTeamObjectiveResource = 17,
	ClassId_CBaseTempEntity = 18,
	ClassId_CBaseToggle = 19,
	ClassId_CBaseTrigger = 20,
	ClassId_CBaseViewModel = 21,
	ClassId_CBaseVPhysicsTrigger = 22,
	ClassId_CBeam = 24,
	ClassId_CBeamSpotlight = 25,
	ClassId_CBoneFollower = 26,
	ClassId_CBRC4Target = 27,
	ClassId_CBreachCharge = 28,
	ClassId_CBreachChargeProjectile = 29,
	ClassId_CBreakableProp = 30,
	ClassId_CBreakableSurface = 31,
	ClassId_CC4 = 32,
	ClassId_CCascadeLight = 33,
	ClassId_CChicken = 34,
	ClassId_CColorCorrection = 35,
	ClassId_CColorCorrectionVolume = 36,
	ClassId_CCSGameRulesProxy = 37,
	ClassId_CCSPlayer = 38,
	ClassId_CCSPlayerResource = 39,
	ClassId_CCSRagdoll = 40,
	ClassId_CCSTeam = 41,
	ClassId_CDangerZone = 42,
	ClassId_CDangerZoneController = 43,
	ClassId_CDEagle = 44,
	ClassId_CDecoyGrenade = 45,
	ClassId_CDecoyProjectile = 46,
	ClassId_CDrone = 47,
	ClassId_CDronegun = 48,
	ClassId_CDynamicLight = 49,
	ClassId_CDynamicProp = 50,
	ClassId_CEconEntity = 51,
	ClassId_CEconWearable = 52,
	ClassId_CEmbers = 53,
	ClassId_CEntityDissolve = 54,
	ClassId_CEntityFlame = 55,
	ClassId_CEntityFreezing = 56,
	ClassId_CEntityParticleTrail = 57,
	ClassId_CEnvAmbientLight = 58,
	ClassId_CEnvDetailController = 59,
	ClassId_CEnvDOFController = 60,
	ClassId_CEnvGasCanister = 61,
	ClassId_CEnvParticleScript = 62,
	ClassId_CEnvProjectedTexture = 63,
	ClassId_CEnvQuadraticBeam = 64,
	ClassId_CEnvScreenEffect = 65,
	ClassId_CEnvScreenOverlay = 66,
	ClassId_CEnvTonemapController = 67,
	ClassId_CEnvWind = 68,
	ClassId_CFEPlayerDecal = 69,
	ClassId_CFireCrackerBlast = 70,
	ClassId_CFireSmoke = 71,
	ClassId_CFireTrail = 72,
	ClassId_CFish = 73,
	ClassId_CFists = 74,
	ClassId_CFlashbang = 75,
	ClassId_CFogController = 76,
	ClassId_CFootstepControl = 77,
	ClassId_CFunc_Dust = 78,
	ClassId_CFunc_LOD = 79,
	ClassId_CFuncAreaPortalWindow = 80,
	ClassId_CFuncBrush = 81,
	ClassId_CFuncConveyor = 82,
	ClassId_CFuncLadder = 83,
	ClassId_CFuncMonitor = 84,
	ClassId_CFuncMoveLinear = 85,
	ClassId_CFuncOccluder = 86,
	ClassId_CFuncReflectiveGlass = 87,
	ClassId_CFuncRotating = 88,
	ClassId_CFuncSmokeVolume = 89,
	ClassId_CFuncTrackTrain = 90,
	ClassId_CGameRulesProxy = 91,
	ClassId_CGrassBurn = 92,
	ClassId_CHandleTest = 93,
	ClassId_CHEGrenade = 94,
	ClassId_CHostage = 95,
	ClassId_CHostageCarriableProp = 96,
	ClassId_CIncendiaryGrenade = 97,
	ClassId_CInferno = 98,
	ClassId_CInfoLadderDismount = 99,
	ClassId_CInfoMapRegion = 100,
	ClassId_CInfoOverlayAccessor = 101,
	ClassId_CItem_Healthshot = 102,
	ClassId_CItemCash = 103,
	ClassId_CItemDogtags = 104,
	ClassId_CKnife = 105,
	ClassId_CKnifeGG = 106,
	ClassId_CLightGlow = 107,
	ClassId_CMaterialModifyControl = 108,
	ClassId_CMelee = 109,
	ClassId_CMolotovGrenade = 110,
	ClassId_CMolotovProjectile = 111,
	ClassId_CMovieDisplay = 112,
	ClassId_CParadropChopper = 113,
	ClassId_CParticleFire = 114,
	ClassId_CParticlePerformanceMonitor = 115,
	ClassId_CParticleSystem = 116,
	ClassId_CPhysBox = 117,
	ClassId_CPhysBoxMultiplayer = 118,
	ClassId_CPhysicsProp = 119,
	ClassId_CPhysicsPropMultiplayer = 120,
	ClassId_CPhysMagnet = 121,
	ClassId_CPhysPropAmmoBox = 122,
	ClassId_CPhysPropLootCrate = 123,
	ClassId_CPhysPropRadarJammer = 124,
	ClassId_CPhysPropWeaponUpgrade = 125,
	ClassId_CPlantedC4 = 126,
	ClassId_CPlasma = 127,
	ClassId_CPlayerResource = 128,
	ClassId_CPointCamera = 129,
	ClassId_CPointCommentaryNode = 130,
	ClassId_CPointWorldText = 131,
	ClassId_CPoseController = 132,
	ClassId_CPostProcessController = 133,
	ClassId_CPrecipitation = 134,
	ClassId_CPrecipitationBlocker = 135,
	ClassId_CPredictedViewModel = 136,
	ClassId_CProp_Hallucination = 137,
	ClassId_CPropCounter = 138,
	ClassId_CPropDoorRotating = 139,
	ClassId_CPropJeep = 140,
	ClassId_CPropVehicleDriveable = 141,
	ClassId_CRagdollManager = 142,
	ClassId_CRagdollProp = 143,
	ClassId_CRagdollPropAttached = 144,
	ClassId_CRopeKeyframe = 145,
	ClassId_CSCAR17 = 146,
	ClassId_CSceneEntity = 147,
	ClassId_CSensorGrenade = 148,
	ClassId_CSensorGrenadeProjectile = 149,
	ClassId_CShadowControl = 150,
	ClassId_CSlideshowDisplay = 151,
	ClassId_CSmokeGrenade = 152,
	ClassId_CSmokeGrenadeProjectile = 153,
	ClassId_CSmokeStack = 154,
	ClassId_CSpatialEntity = 155,
	ClassId_CSpotlightEnd = 156,
	ClassId_CSprite = 157,
	ClassId_CSpriteOriented = 158,
	ClassId_CSpriteTrail = 159,
	ClassId_CStatueProp = 160,
	ClassId_CSteamJet = 161,
	ClassId_CSun = 162,
	ClassId_CSunlightShadowControl = 163,
	ClassId_CSurvivalSpawnChopper = 164,
	ClassId_CTablet = 165,
	ClassId_CTeam = 166,
	ClassId_CTeamplayRoundBasedRulesProxy = 167,
	ClassId_CTEArmorRicochet = 168,
	ClassId_CTEBaseBeam = 169,
	ClassId_CTEBeamEntPoint = 170,
	ClassId_CTEBeamEnts = 171,
	ClassId_CTEBeamFollow = 172,
	ClassId_CTEBeamLaser = 173,
	ClassId_CTEBeamPoints = 174,
	ClassId_CTEBeamRing = 175,
	ClassId_CTEBeamRingPoint = 176,
	ClassId_CTEBeamSpline = 177,
	ClassId_CTEBloodSprite = 178,
	ClassId_CTEBloodStream = 179,
	ClassId_CTEBreakModel = 180,
	ClassId_CTEBSPDecal = 181,
	ClassId_CTEBubbles = 182,
	ClassId_CTEBubbleTrail = 183,
	ClassId_CTEClientProjectile = 184,
	ClassId_CTEDecal = 185,
	ClassId_CTEDust = 186,
	ClassId_CTEDynamicLight = 187,
	ClassId_CTEEffectDispatch = 188,
	ClassId_CTEEnergySplash = 189,
	ClassId_CTEExplosion = 190,
	ClassId_CTEFireBullets = 191,
	ClassId_CTEFizz = 192,
	ClassId_CTEFootprintDecal = 193,
	ClassId_CTEFoundryHelpers = 194,
	ClassId_CTEGaussExplosion = 195,
	ClassId_CTEGlowSprite = 196,
	ClassId_CTEImpact = 197,
	ClassId_CTEKillPlayerAttachments = 198,
	ClassId_CTELargeFunnel = 199,
	ClassId_CTEMetalSparks = 200,
	ClassId_CTEMuzzleFlash = 201,
	ClassId_CTEParticleSystem = 202,
	ClassId_CTEPhysicsProp = 203,
	ClassId_CTEPlantBomb = 204,
	ClassId_CTEPlayerAnimEvent = 205,
	ClassId_CTEPlayerDecal = 206,
	ClassId_CTEProjectedDecal = 207,
	ClassId_CTERadioIcon = 208,
	ClassId_CTEShatterSurface = 209,
	ClassId_CTEShowLine = 210,
	ClassId_CTesla = 211,
	ClassId_CTESmoke = 212,
	ClassId_CTESparks = 213,
	ClassId_CTESprite = 214,
	ClassId_CTESpriteSpray = 215,
	ClassId_CTest_ProxyToggle_Networkable = 216,
	ClassId_CTestTraceline = 217,
	ClassId_CTEWorldDecal = 218,
	ClassId_CTriggerPlayerMovement = 219,
	ClassId_CTriggerSoundOperator = 220,
	ClassId_CVGuiScreen = 221,
	ClassId_CVoteController = 222,
	ClassId_CWaterBullet = 223,
	ClassId_CWaterLODControl = 224,
	ClassId_CWeaponAug = 225,
	ClassId_CWeaponAWP = 226,
	ClassId_CWeaponBaseItem = 227,
	ClassId_CWeaponBizon = 228,
	ClassId_CWeaponCSBase = 229,
	ClassId_CWeaponCSBaseGun = 230,
	ClassId_CWeaponCycler = 231,
	ClassId_CWeaponElite = 232,
	ClassId_CWeaponFamas = 233,
	ClassId_CWeaponFiveSeven = 234,
	ClassId_CWeaponG3SG1 = 235,
	ClassId_CWeaponGalil = 236,
	ClassId_CWeaponGalilAR = 237,
	ClassId_CWeaponGlock = 238,
	ClassId_CWeaponHKP2000 = 239,
	ClassId_CWeaponM249 = 240,
	ClassId_CWeaponM3 = 241,
	ClassId_CWeaponM4A1 = 242,
	ClassId_CWeaponMAC10 = 243,
	ClassId_CWeaponMag7 = 244,
	ClassId_CWeaponMP5Navy = 245,
	ClassId_CWeaponMP7 = 246,
	ClassId_CWeaponMP9 = 247,
	ClassId_CWeaponNegev = 248,
	ClassId_CWeaponNOVA = 249,
	ClassId_CWeaponP228 = 250,
	ClassId_CWeaponP250 = 251,
	ClassId_CWeaponP90 = 252,
	ClassId_CWeaponSawedoff = 253,
	ClassId_CWeaponSCAR20 = 254,
	ClassId_CWeaponScout = 255,
	ClassId_CWeaponSG550 = 256,
	ClassId_CWeaponSG552 = 257,
	ClassId_CWeaponSG556 = 258,
	ClassId_CWeaponSSG08 = 259,
	ClassId_CWeaponTaser = 260,
	ClassId_CWeaponTec9 = 261,
	ClassId_CWeaponTMP = 262,
	ClassId_CWeaponUMP45 = 263,
	ClassId_CWeaponUSP = 264,
	ClassId_CWeaponXM1014 = 265,
	ClassId_CWorld = 266,
	ClassId_CWorldVguiText = 267,
	ClassId_DustTrail = 268,
	ClassId_MovieExplosion = 269,
	ClassId_ParticleSmokeGrenade = 270,
	ClassId_RocketTrail = 271,
	ClassId_SmokeTrail = 272,
	ClassId_SporeExplosion = 273,
	ClassId_SporeTrail = 274,
};

enum ECSPlayerBones
{
    PELVIS = 0,
    SPINE_0,
    SPINE_1,
    SPINE_2,
    SPINE_3,
    NECK_0,
    HEAD_0,
    CLAVICLE_L,
    ARM_UPPER_L,
    ARM_LOWER_L,
    HAND_L,
    FINGER_MIDDLE_META_L,
    FINGER_MIDDLE_0_L,
    FINGER_MIDDLE_1_L,
    FINGER_MIDDLE_2_L,
    FINGER_PINKY_META_L,
    FINGER_PINKY_0_L,
    FINGER_PINKY_1_L,
    FINGER_PINKY_2_L,
    FINGER_INDEX_META_L,
    FINGER_INDEX_0_L,
    FINGER_INDEX_1_L,
    FINGER_INDEX_2_L,
    FINGER_THUMB_0_L,
    FINGER_THUMB_1_L,
    FINGER_THUMB_2_L,
    FINGER_RING_META_L,
    FINGER_RING_0_L,
    FINGER_RING_1_L,
    FINGER_RING_2_L,
    WEAPON_HAND_L,
    ARM_LOWER_L_TWIST,
    ARM_LOWER_L_TWIST1,
    ARM_UPPER_L_TWIST,
    ARM_UPPER_L_TWIST1,
    CLAVICLE_R,
    ARM_UPPER_R,
    ARM_LOWER_R,
    HAND_R,
    FINGER_MIDDLE_META_R,
    FINGER_MIDDLE_0_R,
    FINGER_MIDDLE_1_R,
    FINGER_MIDDLE_2_R,
    FINGER_PINKY_META_R,
    FINGER_PINKY_0_R,
    FINGER_PINKY_1_R,
    FINGER_PINKY_2_R,
    FINGER_INDEX_META_R,
    FINGER_INDEX_0_R,
    FINGER_INDEX_1_R,
    FINGER_INDEX_2_R,
    FINGER_THUMB_0_R,
    FINGER_THUMB_1_R,
    FINGER_THUMB_2_R,
    FINGER_RING_META_R,
    FINGER_RING_0_R,
    FINGER_RING_1_R,
    FINGER_RING_2_R,
    WEAPON_HAND_R,
    ARM_LOWER_R_TWIST,
    ARM_LOWER_R_TWIST1,
    ARM_UPPER_R_TWIST,
    ARM_UPPER_R_TWIST1,
    LEG_UPPER_L,
    LEG_LOWER_L,
    ANKLE_L,
    BALL_L,
    LFOOT_LOCK,
    LEG_UPPER_L_TWIST,
    LEG_UPPER_L_TWIST1,
    LEG_UPPER_R,
    LEG_LOWER_R,
    ANKLE_R,
    BALL_R,
    RFOOT_LOCK,
    LEG_UPPER_R_TWIST,
    LEG_UPPER_R_TWIST1,
    FINGER_PINKY_L_END,
    FINGER_PINKY_R_END,
    VALVEBIPED_WEAPON_BONE,
    LH_IK_DRIVER,
    PRIMARY_JIGGLE_JNT,
    MAX_ECSPLAYERBONES
};

enum EntityFlags
{
    FL_ONGROUND = (1 << 0),
    FL_DUCKING = (1 << 1),
    FL_WATERJUMP = (1 << 2),
    FL_ONTRAIN = (1 << 3),
    FL_INRAIN = (1 << 4),
    FL_FROZEN = (1 << 5),
    FL_ATCONTROLS = (1 << 6),
    FL_CLIENT = (1 << 7),
    FL_FAKECLIENT = (1 << 8),
    MAX_ENTITYFLAGS
};

enum LifeState : unsigned char
{
    LIFE_ALIVE = 0,// alive
    LIFE_DYING = 1, // playing death animation or still falling off of a ledge waiting to hit ground
    LIFE_DEAD = 2, // dead. lying still.
    MAX_LIFESTATE
};

enum WeaponSound_t
{
    EMPTY,
    SINGLE,
    SINGLE_NPC,
    WPN_DOUBLE, // Can't be "DOUBLE" because windows.h uses it.
    DOUBLE_NPC,
    BURST,
    RELOAD,
    RELOAD_NPC,
    MELEE_MISS,
    MELEE_HIT,
    MELEE_HIT_WORLD,
    SPECIAL1,
    SPECIAL2,
    SPECIAL3,
    TAUNT,
    FAST_RELOAD,
    // Add new shoot sound types here
    REVERSE_THE_NEW_SOUND,
    NUM_SHOOT_SOUND_TYPES,
    MAX_WEAPONSOUND
};

enum MoveType_t
{
    MOVETYPE_NONE = 0,
    MOVETYPE_ISOMETRIC,
    MOVETYPE_WALK,
    MOVETYPE_STEP,
    MOVETYPE_FLY,
    MOVETYPE_FLYGRAVITY,
    MOVETYPE_VPHYSICS,
    MOVETYPE_PUSH,
    MOVETYPE_NOCLIP,
    MOVETYPE_LADDER,
    MOVETYPE_OBSERVER,
    MOVETYPE_CUSTOM,
    MOVETYPE_LAST = MOVETYPE_CUSTOM,
    MOVETYPE_MAX_BITS = 4,
    MAX_MOVETYPE
};
