#include "ZZTTagClasses.h"

#ifndef deathstar_ZZTTagData_h
#define deathstar_ZZTTagData_h

#pragma pack(1)

typedef struct {
    uint16_t tagTableIndex;
    uint16_t tableIndex;
} TagID;

typedef struct {
    char padding[0x24];
    uint16_t type;
} Shader;

typedef struct {
    uint32_t count;
    uint32_t offset;
    uint32_t zero;
} TagReflexive;

typedef struct {
	uint32_t integrityHead;
	uint32_t version;
	uint32_t length;
	uint32_t zero;
	uint32_t indexOffset;
	uint32_t metaSize;
	char padding[0x8];
	char name[0x20];
	char builddate[0x20];
	uint32_t type;
    char zeroes2[0x798];
    uint32_t integrityFoot;
} HaloMapHeader;

typedef struct {
	uint32_t tagIndexOffset;
	TagID scenarioTag;
	uint32_t mapId;
	uint32_t tagCount;
	uint32_t vertexCount;
	uint32_t vertexOffset;
	uint32_t indicesCount;
	uint32_t vertexSize;
	uint32_t modelSize;
	uint32_t tags;
} HaloMapIndex;


typedef struct {
	uint32_t classA;
	uint32_t classB;
	uint32_t classC;
	TagID identity;
	uint32_t nameOffset;
	uint32_t dataOffset;
    uint32_t notInsideMap;
	char padding[0x4];
} MapTag;

typedef struct {
    char mainClass[4];
    uint32_t nameOffset;
    uint32_t zero;
    TagID tagId;
} Dependency; //0x10

typedef struct {
    Dependency shader;           //0x0
    char padding[0x10];          //0x10
} Mod2ShaderDependencies;

typedef struct {
    char padding[0xDC];          //0x0
    TagReflexive mod2Shaders;    //0xDC
} Mod2Dependencies;

typedef struct {
    char padding[0xC];           //0x0
    Dependency equipment;        //0xC  eqip
} WeapMagazineMagazineDependencies; //0x1C

typedef struct {
    char padding[0x38];          //0x0
    Dependency reloadingEffect;  //0x38 effe
    Dependency chamberingEffect; //0x48 effe
    char padding1[0xC];          //0x58
    TagReflexive weapMagazineEquipment; //0x64
} WeapMagazineDependencies; //0x70

typedef struct {
    char padding[0x24];          //0x0
    Dependency firingEffect;     //0x24 effe
    Dependency misfireEffect;    //0x34 effe
    Dependency emptyEffect;      //0x44 effe
    Dependency firingDamage;     //0x54 jpt!
    Dependency misfireDamage;    //0x64 jpt!
    Dependency emptyDamage;      //0x74 jpt!
} WeapTriggerFiringEffects; //0x84

typedef struct {
    char padding[0x5C];          //0x0
    Dependency chargingEffect;   //0x5C effe
    char padding2[0x28];         //0x6C
    Dependency projectile;       //0x94 proj <-- obje
    char padding3[0x64];         //0xA4
    TagReflexive firingEffect;   //0x108
} WeapTriggerDependencies; //0x114

typedef struct {
    Dependency name;
    char padding[0x10];
} ObjeWidgets; //0x20
typedef struct {
    Dependency type;
    char padding[0x38];
} ObjeAttachments; //0x48
enum ResourceType {
    OBJE_TYPE_BITMAP = 0,
    OBJE_TYPE_SOUND = 1
};
typedef struct {
    uint16_t type; //0x0
    char padding[0x2]; //0x2
    TagID name; //0x4
} ObjeResources; //0x8
typedef struct {
    uint16_t tagObjectType;      //0x0
    char padding[0x26];          //0x2
    Dependency model;            //0x28 mod2
    Dependency animation;        //0x38 antr
    char padding2[0x28];         //0x48
    Dependency collision;        //0x70 coll
    Dependency physics;          //0x80 phys
    Dependency shader;           //0x90 shdr
    Dependency creationEffect;   //0xA0 effe
    char padding3[0x90];         //0xB0
    TagReflexive attachments;    //0x140
    TagReflexive widgets;        //0x14C
    char padding4[0x18];         //0x158
    TagReflexive resources;      //0x170
} ObjeDependencies; //0x17C
typedef struct {
    ObjeDependencies obje;       //0x0
    char padding[0xCC];          //0x17C
    Dependency materialEffects;  //0x248 foot
    Dependency collisionSound;   //0x258 snd!
    char padding2[0x80];         //0x268
    Dependency detonatingEffect; //0x2E8 effe
    Dependency detonationEffect; //0x2F8 effe
} ItemDependencies; //0x308
typedef struct {
    ItemDependencies item;       //0x0
    char padding[0x8];           //0x308
    Dependency pickupSound;      //0x310 snd!
} EqipDependencies; //0x320
typedef struct {
    Dependency cameraTrack;      //0x0
    char padding[0x10];          //0x10
} UnitCameraTrackDependencies; //0x18
typedef struct {
    Dependency weapon;           //0x0
    char padding[0x14];          //0x10
} UnitWeaponDependencies; //0x24
typedef struct {
    Dependency cameraTrack;      //0x0
    char padding[0xC];           //0x10
} UnitSeatCameraTrackDependencies; //0x1C
typedef struct {
    Dependency hud;              //0x0
    char padding[0x20];          //0x10
} UnitSeatHudInterface; //0x30
typedef struct {
    char padding[0xD0];          //0x0
    TagReflexive tracks;         //0xD0
    TagReflexive unhi;           //0xDC
    char padding1[0x10];         //0xE8
    Dependency gunner;           //0xF8  actv
    char padding2[0x14];         //0x108
} UnitSeatsDependencies;
typedef struct {
    Dependency unhi;             //0x0
    char padding[0x20];          //0x10
} UnitNewHUDDependencies; //0x30
typedef struct {
    char padding[0x8];           //0x0
    Dependency dialogue;         //0x8
} UnitDialogues; //0x18
typedef struct {
    ObjeDependencies obje;       //0x0
    char padding[0xC];           //0x17C
    Dependency integratedLight;  //0x188 ligh
    char padding2[0x5C];         //0x198
    TagReflexive cameraTrack;    //0x1F4
    char padding3[0x4C];         //0x200
    Dependency spawnedActor;     //0x24C actr
    char padding4[0x2C];         //0x25C
    Dependency meleeDamage;      //0x288 jpt!
    char padding5[0x10];         //0x298
    TagReflexive unitHud;        //0x2A8 -- not done yet
    TagReflexive unitDialogue;   //0x2B4 -- not done yet
    char padding6[0x18];         //0x2C0
    TagReflexive weapons;        //0x2D8
    TagReflexive seats;          //0x2E4
} UnitDependencies; //0x2F0
typedef struct {
    UnitDependencies unit;       //0x0
    char padding[0xC0];          //0x2F0
    Dependency suspensionSound;  //0x3B0
    Dependency crashSound;       //0x3C0
    Dependency materialEffects;  //0x3D0
    Dependency effect;           //0x3E0
} VehiDependencies;
typedef struct {
    UnitDependencies unit;       //0x0
    char padding[0x9C];          //0x2F0
    Dependency materialEffects;  //0x38C
} BipdDependencies;
typedef struct {
    char padding[0x4];           //0x0
    Dependency defaultResult;    //0x4   effe
    char padding1[0x28];         //0x14
    Dependency potentialResult;  //0x3C  effe
    char padding2[0x1C];         //0x4C  effe
    Dependency detonationEffect; //0x68  effe
    char padding3[0x28];         //0x78
} ProjMaterialResponseDependencies;
typedef struct {
    ObjeDependencies obje;       //0x0
    char padding[0x10];          //0x17C
    Dependency superDetonation;  //0x18C effe
    char padding1[0x10];         //0x19C
    Dependency detonationEffect; //0x1AC effe
    char padding2[0x38];         //0x1BC
    Dependency detonationStarted;//0x1F4 effe
    Dependency flybySound;       //0x204 effe
    Dependency attachedDamage;   //0x214 jpt!
    Dependency impactDamage;     //0x224 jpt!
    char padding3[0xC];          //0x234
    TagReflexive materialRespond;//0x240 effe's
} ProjDependencies; //incomplete
typedef struct {
    ItemDependencies item;       //0x0
    char padding[0x34];          //0x308
    Dependency readyEffect;      //0x33C effe
    char padding2[0x28];         //0x34C
    Dependency overheatedEffect; //0x374 effe
    Dependency detonationEffect; //0x384 effe
    Dependency meleeDamage;      //0x394 jpt!
    Dependency meleeResponse;    //0x3A4 jpt!
    char padding3[0x8];          //0x3B4
    Dependency firingParams;     //0x3BC actr
    char padding4[0x54];         //0x3CC
    Dependency lightOnEffect;    //0x420 effe
    Dependency lightOffEffect;   //0x430 effe
    char padding5[0x1C];         //0x440
    Dependency fpModel;          //0x45C mod2
    Dependency fpAnimation;      //0x46C antr
    char padding6[0x4];          //0x47C
    Dependency hud;              //0x480 wphi
    Dependency pickupSound;      //0x490 snd!
    Dependency zoomInSound;      //0x4A0 snd!
    Dependency zoomOutSound;     //0x4B0 snd!
    char padding7[0x30];         //0x4C0
    TagReflexive magazines;      //0x4F0
    TagReflexive triggers;       //0x4FC
} WeapDependencies; //0x508
typedef struct {
    char padding[0x24];
    Dependency dependency;
    char padding1[0x20];
} ItmcPermutationDependencies;
typedef struct {
    TagReflexive permutation;    //0x0;
} ItmcDependencies;
typedef struct {
    Dependency sky;              //0x0
} ScnrSkies; //0x10
typedef struct {
    Dependency shader;           //0x0
    uint32_t type;               //0x10
} SBSPCollisionMaterialsDependencies;
typedef struct {
    Dependency shader;           //0x0
    char padding[0xF0];          //0x10
} SBSPLightmapsMaterialsReflexives;
typedef struct {
    char padding[0x14];          //0x0
    TagReflexive materials;      //0x14
} SBSPLightmapsDependencies;
typedef struct {
    char padding[0x24]; //0x0
    Dependency shader; //0x24
    char padding1[0xC]; //0x34
} SBSPClusterShaders; //0x40
typedef struct {
    char padding[0x28]; //0x0
    TagReflexive lightmaps; //0x28
    char padding1[0x1C]; //0x34
    TagReflexive mirrors; //0x50
    char padding2[0xC];
} SBSPClusters;
typedef struct {
    char padding[0x20];
    Dependency fog;
    char padding1[0x58];
} SBSPFogPallete;
typedef struct {
    char padding[0x20]; //0x0
    Dependency particleSystem; //0x20
    char padding1[0x50]; //0x30
    Dependency wind; //0x80
    char padding2[0x13C]; //0x90
} SBSPWeatherPallete;
typedef struct {
    char padding[0x20]; //0x0
    Dependency sound; //0x20
    char padding1[0x44]; //0x30
} SBSPBackgroundSound;
typedef struct {
    char padding[0x20]; //0x0
    Dependency soundEnvironment; //0x20
    char padding1[0x20]; //0x30
} SBSPEnvironmentPallete;
typedef struct {
    char padding[0xBC];
    TagReflexive collMaterials;  //0xBC
    char padding1[0x54]; //0xC8
    TagReflexive lightmaps;      //0x11C
    char padding2[0xC]; //0x128
    TagReflexive lensFlares; //0x134
    char padding3[0xC]; //0x140
    TagReflexive clusters; //0x14C
    char padding4[0x50];         //0x158
    TagReflexive fog;            //0x1A8
    char padding5[0x18];         //0x1B4
    TagReflexive weather;        //0x1CC
    char padding6[0x3C];         //0x1D8
    TagReflexive backgroundSound;//0x214
    TagReflexive soundEnvironment;//0x220
} SBSPDependencies;
typedef struct {
    uint32_t fileOffset;         //0x0
    uint32_t tagSize;            //0x4
    uint32_t bspMagic;           //0x8
    uint32_t zero;               //0xC
    Dependency bsp;              //0x10
} ScnrBSPs;
typedef struct {
    Dependency object;           //0x0   obje <--
    char padding[0x20];          //0x10
} ScnrPaletteDependency; //0x30
typedef struct {
    char padding[0x50];          //0x0
    Dependency itemCollection;   //0x50
    char padding1[0x30];         //0x60
} ScnrNetgameItmcDependencies; //0x90
typedef struct {
    char padding[0x3C];          //0x0
    Dependency equipment[0x6];   //0x3C
    char padding1[0x30];         //0x9C
} ScnrStartingEquipment;

typedef struct {
    Dependency unknown[0x3];     //0x0   sbsp
    TagReflexive skies;          //0x30
    char padding[0x1E0];         //0x3C
    TagReflexive sceneryPalette; //0x21C
    char padding2[0xC];          //0x228
    TagReflexive bipedPalette;   //0x234
    char padding3[0xC];          //0x240
    TagReflexive vehiclePalette; //0x24C
    char padding4[0xC];          //0x258
    TagReflexive equipPalette;   //0x264
    char padding5[0xC];          //0x270
    TagReflexive weaponPalette;  //0x27C
    char padding6[0x18];         //0x288
    TagReflexive machinePalette; //0x2A0
    char padding7[0xC];          //0x2AC
    TagReflexive controlPalette; //0x2B8
    char padding8[0xC];          //0x2C4
    TagReflexive lifiPalette;    //0x2D0
    char padding9[0xC];          //0x2DC
    TagReflexive sscePalette;    //0x2E8
    char padding10[0xC];         //0x2F4
    char padding11[0x84];        //0x300
    TagReflexive netgameItmcs;   //0x384
    TagReflexive startingItmcs;  //0x390
    char padding12[0x18];        //0x39C
    TagReflexive decalPalette;   //0x3B4 //offset is dependency[]
    TagReflexive detailObjects;  //0x3C0 //object palette
    char padding13[0x54];        //0x3CC
    TagReflexive actorPalette;   //0x420 //offset is dependency[]
    char padding14[0x18];
    TagReflexive AIAnimationRef; //0x444
    char padding15[0x154];       //0x450
    TagReflexive BSPs;           //0x5A4
} ScnrDependencies;

typedef struct {
    Dependency tag;
} MatgTagCollectionDependencies;

typedef struct {
    char padding[0x4];           //0x0
    Dependency throwingEffect;   //0x4   effe
    Dependency hudInterface;     //0x14
    Dependency equipment;        //0x24  eqip
    Dependency projectile;       //0x34  proj <--
} MatgGrenadesDependencies; //0x44

typedef struct {
    Dependency unit;             //0x0   unit <--
    char padding[0xA8];          //0x10
    Dependency spawnEffect;      //0xB8  effe
    char padding1[0x2C];         //0xC8
} MatgPlayerInformationDependencies; //0xF4

typedef struct {
    Dependency flag;             //0x0   weap <--
    Dependency unit;             //0x10  unit <--
    TagReflexive vehicles;       //0x20  --TagCollection
    Dependency hillShader;       //0x2C  shdr
    Dependency flagShader;       //0x3C  shdr
    Dependency ball;             //0x4C  weap <--
    TagReflexive sounds;         //0x5C  --TagCollection
    char padding[0x38];          //0x68
} MatgMultiplayerInformationDependencies; //0xA0

typedef struct {
    Dependency fontSystem;
    Dependency fontTerminal;
    Dependency screenColorTable;
    Dependency hudColorTable;
    Dependency editorColorTable;
    Dependency dialogColorTable;
    Dependency hudGlobals;
    Dependency motionSensorSweepBitmap;
    Dependency motionSensorSweepBitmapMask;
    Dependency multiplayerHudBitmap;
    Dependency localization;
    Dependency hudDigits;
    Dependency motionSensorBlipBitmap;
    Dependency interfaceGoopMap1;
    Dependency interfaceGoopMap2;
    Dependency interfaceGoopMap3;
    char padding[0x2C];
} MatgInterfaceBitmapsDependencies;

typedef struct {
    Dependency fpHands; //0x0
    Dependency baseBitmap; //0x10
    Dependency shieldMeter; //0x20
    char padding[0x4]; //0x30
    Dependency bodyMeter; //0x34
    char padding1[0x4]; //0x44
    Dependency nightVisionOnEffect; //0x48
    Dependency nightVisionOffEffect; //0x58
    char padding2[0x58]; //0x68
} MatgFPInterface;

typedef struct {
    char padding[0x10]; //0x0
    Dependency fallingDamage; //0x10
    char padding1[0xC]; //0x20
    Dependency distanceDamage; //0x2C
    Dependency vehicleEnviroCollisionDamage; //0x3C
    Dependency vehicleKilledDamage; //0x4C
    Dependency vehicleCollisionDamage; //0x5C
    Dependency flameDeathDamage; //0x6C
} MatgFallingDamage;

typedef struct {
    char padding[0xF8];          //0x0
    TagReflexive sounds;         //0xF8  --TagCollection
    TagReflexive camera;         //0x104 --TagCollection
    char padding1[0x18];         //0x110
    TagReflexive grenades;       //0x128
    TagReflexive rasterizerData; //0x134 --incomplete
    TagReflexive interfaceBitm;  //0x140
    TagReflexive weapons;        //0x14C --TagCollection
    TagReflexive powerups;       //0x158 --TagCollection
    TagReflexive multiplayerInfo;//0x164
    TagReflexive playerInfo;     //0x170
    TagReflexive fpInterface;    //0x17C --incomplete
    TagReflexive fallingDamage;  //0x188 --incomplete
    TagReflexive materials;      //0x194 --incomplete
} MatgDependencies;

typedef struct {
    char padding[0xA4]; //0x0
    Dependency baseMap; //0xA4
    char padding1[0x8]; //0xB4
    Dependency multiMap; //0xBC
    char padding2[0x10]; //0xCC
    Dependency detailMap; //0xDC
    char padding3[0x78]; //0xEC
    Dependency reflectMap; //0x164
} ShaderSosoDependencies;

typedef struct {
    char padding[0xD4]; //0x0
    Dependency primaryNoiseMap; //0xD4
    char padding1[0x38]; //0xE4
    Dependency secondaryNoiseMap; //0x114
} ShaderSplaDependencies;

typedef struct {
    Dependency shader; //0x0
} ShaderShaderLayersDependencies;

typedef struct {
    char padding[0x1C]; //0x0
    Dependency map; //0x1C
    char padding1[0x38]; //0x2C
} ShaderSotrMapDependencies;

typedef struct {
    char padding[0x38]; //0x0
    Dependency lensflare; //0x38
    TagReflexive layers; //0x48
    TagReflexive maps; //0x54
} ShaderSotrDependencies;

typedef struct {
    char padding[0x4C]; //0x0
    Dependency map; //0x4C
} ShaderSmetDependencies;

typedef struct {
    char padding[0x6C]; //0x0
    Dependency map; //0x6C
    char padding1[0x60]; //0x7C
} ShaderSchiMapDependencies;

typedef struct {
    char padding[0x38]; //0x0
    Dependency lensflare; //0x38
    TagReflexive layers; //0x48
    TagReflexive maps; //0x54
} ShaderSchiDependencies;

typedef struct {
    char padding[0x30]; //0x0
    Dependency lensFlare; //0x30
    char padding1[0x48]; //0x40
    Dependency baseMap; //0x88
    char padding2[0x20]; //0x98
    Dependency primaryDetailMap; //0xB8
    char padding3[0x4]; //0xC8
    Dependency secondaryDetailMap; //0xCC
    char padding4[0x20]; //0xDC
    Dependency microDetailMap; //0xFC
    char padding5[0x1C]; //0x10C
    Dependency bumpMap; //0x128
    char padding6[0x11C]; //0x138
    Dependency illuminationMap; //0x254
    char padding7[0xC0]; //0x264
    Dependency reflectionCubeMap; //0x324
} ShaderSenvDependencies;

typedef struct {
    char padding[0x38]; //0x0
    Dependency lensflare; //0x38
    TagReflexive layers; //0x48
    TagReflexive stage4maps; //0x54
    TagReflexive stage2maps; //0x60
} ShaderScexDependencies;

typedef struct {
    char padding[0x4C]; //0x0
    Dependency baseMap; //0x4C
    char padding1[0x40]; //0x5C
    Dependency reflectionMap; //0x9C
    char padding2[0x1C]; //0xAC
    Dependency rippleMap; //0xC8
} ShaderSwatDependencies;

typedef struct {
    char padding[0x64]; //0x0
    Dependency bgTint; //0x64
    char padding1[0x38]; //0x74
    Dependency reflectionMap; //0xAC
    float padding2; //0xBC
    Dependency bumpMap; //0xC0
    char padding3[0x88]; //0xD0
    Dependency diffuseMap; //0x158
    float padding4; //0x168
    Dependency diffuseDetailMap; //0x16C
    char padding5[0x24]; //0x17C
    Dependency specularMap; //0x190
    float padding6; //0x1B0
    Dependency specularDetailMap; //0x1B4
} ShaderSglaDependencies;

typedef struct {
    char padding[0x54]; //0x0
    Dependency particle; //0x54
    char padding1[0x84]; //0x64
} EffeEventParticlesDependencies;

typedef struct {
    char padding[0x14]; //0x0
    char tagClass[4]; //0x14
    Dependency type; //0x18
    char padding1[0x40]; //0x28
} EffeEventPartsDependencies; //0x68

typedef struct {
    char padding[0x2C]; //0x0
    TagReflexive parts; //0x2C
    TagReflexive particles; //0x38
} EffeEvents; //0x44

typedef struct {
    char padding[0x34];
    TagReflexive events;
} EffeDependencies;

typedef struct {
    char padding[0x4]; //0x0
    Dependency bitmap; //0x4                bitm
    Dependency physics; //0x14              pphy
    Dependency materialEffects; //0x24      foot
    char padding1[0x14]; //0x34
    Dependency collisionEffect; //0x48      effe
    Dependency deathEffect; //0x58          effe
    char padding2[0x94]; //0x68
    Dependency secondaryBitmap; //FC        bitm
} PartDependencies;

typedef struct {
    Dependency effect; //0x0                effe
    Dependency sound; //0x10                snd!
    char padding[0x10];
} FootEffectsMaterials;

typedef struct {
    TagReflexive materials;
    char padding[0x10];
} FootEffects;

typedef struct {
    TagReflexive effects;
} FootDependencies;

typedef struct {
    char padding[0x64]; //0x0
    Dependency mapPrimary; //0x64
    Dependency mapSecondary; //0x74
    Dependency mapTertiary; //0x84
    char padding1[0x14C]; //0x94
} MultitextureOverlay;

typedef struct {
    Dependency sound; //0x0
    char padding[0x28]; //0x10
} UnhiHudWarningSoundsDependencies; //0x38

typedef struct {
    char padding[0x38]; //0x0
    Dependency interfaceBitmap; //0x38
    char padding1[0x58]; //0x48
    Dependency meterBitmap; //0xA0
    char padding2[0x94];
} UnhiHudMetersDependencies;

typedef struct {
    char padding[0x48]; //0x0
    Dependency hudinterfaceBitmap; //0x48    bitm
    char padding1[0x24]; //0x58
    TagReflexive hudBgMultitextureOverlay; //0x7C
    char padding2[0x28]; //0x88
    Dependency shieldInterfaceBitmap; //0xB0 bitm
    char padding3[0x24]; //0xE4
    TagReflexive shieldBgMultitextureOverlay; //0xE4
    char padding4[0x28]; //0xF0
    Dependency shieldMeterBitmap; //0x118
    char padding5[0x78]; //0x128
    Dependency healthInterfaceBitmap; //0x1A0
    char padding6[0x24]; //0x1B0
    TagReflexive healthBigMultitextureOverlay; //0x1D4
    char padding7[0x28]; //0x1E0
    Dependency healthMeterBitmap; //0x208   bitm
    char padding8[0x78]; //0x218
    Dependency motionSensorBgInterfaceBitmap; //0x290
    char padding9[0x24]; //0x2A0
    TagReflexive motionSensorBgMultitextureOverlay; //0x2C4
    char padding10[0x28]; //0x2D0
    Dependency motionSensorFgInterfaceBitmap; //0x2F8
    char padding11[0x24]; //0x308
    TagReflexive motionSensorFgMultitextureOverlay; //0x32C
    char padding12[0x6C]; //0x338
    TagReflexive auxOverlayMulitextureOverlay; //0x3A4
    char padding13[0x10]; //0x3B0
    TagReflexive hudWarningSounds; //0x3C0
    TagReflexive auxHudMeters; //0x3CC
} UnhiDependencies;

typedef struct {
    char padding[0x38]; //0x0
    Dependency destroyedEffect; //0x38
    char padding1[0xC];
} CollRegionsDependencies;


typedef struct {
    char padding[0x70]; //0x0
    Dependency localizedDamageEffect; //0x70
    char padding1[0x4]; //0x80
    Dependency areaDamageEffect; //0x84
    char padding2[0x4]; //0x94
    Dependency bodyDamagedEffect; //0x98
    Dependency bodyDepletedEffect; //0xA8
    char padding3[0x4]; //0xB8
    Dependency bodyDestroyedEffect; //0xBC
    char padding4[0xBC];
    Dependency shieldDamagedEffect; //0x188
    Dependency shieldDepletedEffect; //0x198
    Dependency shieldRechargingEffect; //0x1A8
    char padding5[0x88]; //0x1B8
    TagReflexive regions; //0x240
} CollDependencies;

typedef struct {
    char padding[0x48]; //0x0
    Dependency interfaceBitmap; //0x48
    char padding1[0x24]; //0x58
    TagReflexive bgMutlitextureOverlay; //0x7C
    char padding2[0x28]; //0x88
    Dependency bgInterfaceBitmap; //0xB0
    char padding3[0x24]; //0xC0
    TagReflexive fgMultitextureOverlay; //0xE4
    char padding4[0x5C]; //0xF0
    Dependency overlayBitmap; //0x14C

} GrhiDependencies;

typedef struct {
    char padding[0x3C];
    Dependency boldFont;
    Dependency italicFont;
    Dependency condenseFont;
    Dependency underlineFont;
} FontDependencies;

typedef struct {
    Dependency digitsBitmap;
} HudDependencies;

typedef struct {
    char padding[0x48]; //0x0
    Dependency singlePlayerFont; //0x48
    Dependency multiPlayerFont; //0x58
    char padding1[0x2C]; //0x68
    Dependency iconMessageText; //0x94
    Dependency iconBitmap; //0xA4
    Dependency alternateIconText; //0xB4
    char padding2[0x2C]; //0xC4
    Dependency hudMessages; //0xF0
    char padding3[0x50]; //0x100
    Dependency waypointArrowBitmap; //0x150
    char padding4[0x160]; //0x160
    Dependency defaultWeaponHud; //0x2C0
    char padding5[0x68]; //0x2D0
    Dependency damageIndicatorBitmap; //0x338
    char padding6[0x80]; //0x348
    Dependency carnageReport; //0x3C8
    char padding7[0x8]; //0x3D8
    Dependency checkpointSound; //0x3E0
} HudgDependencies;

typedef struct {
    Dependency lensFlare;
    char padding[0x64];
} SkyLensFlares;

typedef struct {
    Dependency model; //0x0
    Dependency animation; //0x10
    char padding[0x78];
    Dependency fog; //0x98
    char padding1[0x1C]; //0xA8
    TagReflexive lensFlares; //0xC4
} SkyDependencies;

typedef struct {
    char padding[0x8]; //0x0
    Dependency nextDecal; //0x8
    char padding1[0xC0]; //0x18
    Dependency shaderMap; //0xD8
} DecaDependencies;

typedef struct {
    char padding[0x48]; //0x0
    Dependency bitmap; //0x48
    char padding1[0x5C];
} WphiMeterElements; //0xB4
typedef struct {
    char padding[0x48]; //0x0
    Dependency bitmap; //0x48
    char padding1[0x24]; //0x58
    TagReflexive multitextureOverlay; //0x7C
    char padding2[0x2C];
} WphiStaticElements; //0xB4

typedef struct {
    char padding[0x24]; //0x0
    Dependency bitmap; //0x24
    char padding1[0x34]; //0x34
} WphiOverlayElements;

typedef struct {
    char padding[0x18]; //0x0
    Dependency maskFullscreen; //0x18
    Dependency maskSplitscreen; //0x28
    char padding1[0x104];
} WphiScreenEffects;

typedef struct {
    Dependency childHud; //0x0
    char padding[0x50]; //0x10
    TagReflexive staticElements; //0x60
    TagReflexive meterElements; //0x6C
    char padding1[0xC]; //0x78
    TagReflexive crosshairs; //0x84
    TagReflexive overlayElements; //0x90
    char padding2[0x10]; //0x9C
    TagReflexive screenEffect; //0xAC
} WphiDependencies;

typedef struct {
    Dependency sound;
    uint32_t padding;
} AntrSoundsDependencies;

typedef struct {
    char padding[0x54];
    TagReflexive sounds;
} AntrDependencies;

typedef struct {
    char padding[0x10]; //0x0
    Dependency sounds[0x3]; //0x10
    char padding1[0x30]; //0x40
    Dependency sounds1[0xE]; //0x70
    char padding2[0x10]; //0x150
    Dependency sounds2[0x4]; //0x160
    char padding3[0x40]; //0x1A0
    Dependency sounds3[0x11]; //0x1E0
    char padding4[0x30]; //0x2F0
    Dependency sounds4[0x1C]; //0x320
    char padding5[0x30]; //0x4E0
    Dependency sounds5[0xD]; //0x510
    char padding6[0x30]; //0x5E0
    Dependency sounds6[0xA]; //0x610
    char padding7[0x20]; //0x6B0
    Dependency sounds7[0xD]; //0x6D0
    char padding8[0x20];//0x7A0
    Dependency sounds8[0x15]; //0x7C0
    char padding9[0x40]; //0x910
    Dependency sounds9[0x17]; //0x950
    char padding10[0x60]; //0xAC0
    Dependency sounds10[0x7]; //0xB20
    char padding11[0x40]; //0xB90
    Dependency sounds11[0x5]; //0xBD0
    char padding12[0x40]; //0xC20
    Dependency sounds12[0x8]; //0xC60
} UdlgDependencies;

typedef struct {
    Dependency widget;
    char padding[0x40];
} DeLaChildWidgets;

typedef struct {
    char padding[0x8]; //0x0
    Dependency widgetTag; //0x8
    Dependency soundTag; //0x18
    char padding1[0x20];
} DeLaEventHandler;

typedef struct {
    char padding[0x38]; //0x0
    Dependency backgroundBitmap; //0x38
    char padding1[0xC]; //0x48
    TagReflexive eventHander; //0x54
    char padding2[0x8C]; //0x60
    Dependency unicodeStrings; //0xEC
    Dependency font; //0xFC
    char padding3[0x48]; //0x10C
    Dependency headerBitmap; //0x154
    Dependency footerBitmap; //0x164
    char padding4[0x30]; //0x174
    Dependency extendedDescriptionWidget; //0x1A4
    char padding5[0x120]; //0x1B4
    TagReflexive conditionalWidget; //0x2D4
    char padding6[0x100]; //0x2E0
    TagReflexive childWidget; //0x3E0
} DeLaDependencies;

typedef struct{
    char padding[0x10];
    Dependency pphys;
    char padding1[0x48];
} ContPointStatesDependencies;

typedef struct {
    char padding[0x30]; //0x0
    Dependency bitmap; //0x30
    char padding1[0x90]; //0x40
    Dependency bitmap2; //0xD0
    char padding2[0x58]; //0xE0
    TagReflexive pointStates; //0x138
} ContDependencies;

typedef struct {
    char padding[0x4];
    //Dependency stencilBitmaps;
    //Dependency sourceBitmaps;
} MetrDependencies;

typedef struct{
    char padding[0x18]; //0x0
    Dependency redShader; //0x18
    Dependency physics; //0x28
    char padding1[0xC]; //0x38
    Dependency blueShader; //0x44
} FlagDependencies;

typedef struct {
    char padding[0x114];
    Dependency sound;
} JptDependencies;

typedef struct {
    char padding[0x30]; //0x0
    Dependency start; //0x30
    Dependency loop; //0x40
    Dependency end; //0x50
    char padding1[0x20]; //0x60
    Dependency altLoop; //0x80
    Dependency altEnd; //0x90
} LsndTracks;

typedef struct {
    char padding[0x2C];
    Dependency cdmg;
    TagReflexive tracks;
} LsndDependencies;

typedef struct {
    char padding[0xAC]; //0x0
    Dependency pphys; //0xAC
    char padding1[0xD8]; //0xBC
    Dependency bitmap; //0x194
    char padding2[0x50]; //0x1A4
    Dependency bitmap1; //0x1F4
    char padding3[0x58];
} RainParticles;

typedef struct {
    char padding[0x24];
    TagReflexive particles;
} RainDependency;

typedef struct {
    char padding[0x64]; //0x0
    Dependency primaryCubeMap; //0x64
    char padding1[0x8]; //0x74
    Dependency secondaryCubeMap; //0x7C
    char padding2[0x20]; //0x8C
    Dependency lens;
} LighDependency;

typedef struct {
    char padding[0x20];
    Dependency bitmap;
} LensDependency;

typedef struct {
    char padding[0x20];
    Dependency bitmap;
    Dependency physics;
} AntDependency;

typedef struct {
    char padding[0x30]; //0x0
    Dependency bitmaps; //0x30
    char padding1[0x44]; //0x40
    Dependency pphys; //0x84
    char padding2[0x70]; //0x94
    Dependency bitmap2; //0x104
    char padding3[0x64]; //0x114
} PctlParticleStates;

typedef struct {
    char padding[0x74]; //0x0
    TagReflexive states; //0x74
} PctlParticleTypes;

typedef struct {
    char padding[0x38]; //0x0
    Dependency pphys; //0x38
    char padding1[0x14]; //0x48
    TagReflexive particles;
} PctlDependencies;

typedef struct {
    char padding[0x4]; //0x0
    Dependency actr; //0x4
    Dependency unit; //0x14
    Dependency actv; //0x24
    char padding1[0x30]; //0x34
    Dependency weap; //0x64
    char padding2[0x14C]; //0x74
    Dependency eqip; //0x1C0
} ActvDependencies;

#endif
