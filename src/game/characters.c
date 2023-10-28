#include "sm64.h"
#include "types.h"
#include "characters.h"
#include "hud.h"
#include "model_ids.h"
#include "object_constants.h"
#include "sounds.h"
#include "luigi_sounds.h"
#include "wario_sounds.h"
#include "pc/configfile.h"
#include "audio/external.h"
#include "engine/graph_node.h"
#include "characters_bass_sounds.h"
#include "pc/lua/smlua.h"

extern Gfx mario_cap_seg3_dl_03022F48[];
extern Gfx mario_cap_m_logo_decal_dl[];
extern Gfx luigi_cap_seg3_dl_03022F48[];
extern Gfx luigi_cap_l_logo_decal_dl[];
extern Gfx toad_player_dl_cap[];
extern Gfx toad_player_dl_cap_decal[];
extern Gfx waluigi_cap_seg3_dl_03022F48[];
extern Gfx wario_cap_seg3_dl_03022F48[];

extern ALIGNED8 const u8 texture_hud_char_mario_head[];
extern ALIGNED8 const u8 texture_hud_char_luigi_head[];
extern ALIGNED8 const u8 texture_hud_char_toad_head[];
extern ALIGNED8 const u8 texture_hud_char_waluigi_head[];
extern ALIGNED8 const u8 texture_hud_char_wario_head[];

struct Character gCharacters[CT_MAX] = {
    [CT_MARIO] = {
        .type                  = CT_MARIO,
        .name                  = "Mario",
        .hudHead               = '(',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_mario_head, .bitSize = 8, .width = 16, .height = 16 },
        .cameraHudHead         = GLYPH_CAM_MARIO_HEAD,
        .modelId               = MODEL_MARIO,
        .capModelId            = MODEL_MARIOS_CAP,
        .capMetalModelId       = MODEL_MARIOS_METAL_CAP,
        .capWingModelId        = MODEL_MARIOS_WING_CAP,
        .capMetalWingModelId   = MODEL_MARIOS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_TRANSPARENT,
        .capEnemyGfx           = mario_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = mario_cap_m_logo_decal_dl,
        .torsoRotMult          = 1.0f,
        // anim
        .animOffsetEnabled     = false,

        // character anims
        .animSlowLedgeGrab =                    MARIO_ANIM_SLOW_LEDGE_GRAB,
        .animFallOverBackwards =                MARIO_ANIM_FALL_OVER_BACKWARDS,
        .animBackwardAirKb =                    MARIO_ANIM_BACKWARD_AIR_KB,
        .animDyingOnBack =                      MARIO_ANIM_DYING_ON_BACK,
        .animBackflip =                         MARIO_ANIM_BACKFLIP,
        .animClimbUpPole =                      MARIO_ANIM_CLIMB_UP_POLE,
        .animGrabPoleShort =                    MARIO_ANIM_GRAB_POLE_SHORT,
        .animGrabPoleSwingPart1 =               MARIO_ANIM_GRAB_POLE_SWING_PART1,
        .animGrabPoleSwingPart2 =               MARIO_ANIM_GRAB_POLE_SWING_PART2,
        .animHandstandIdle =                    MARIO_ANIM_HANDSTAND_IDLE,
        .animHandstandJump =                    MARIO_ANIM_HANDSTAND_JUMP,
        .animStartHandstand =                   MARIO_ANIM_START_HANDSTAND,
        .animReturnFromHandstand =              MARIO_ANIM_RETURN_FROM_HANDSTAND,
        .animIdleOnPole =                       MARIO_ANIM_IDLE_ON_POLE,
        .animAPose =                            MARIO_ANIM_A_POSE,
        .animSkidOnGround =                     MARIO_ANIM_SKID_ON_GROUND,
        .animStopSkid =                         MARIO_ANIM_STOP_SKID,
        .animCrouchFromFastLongjump =           MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP,
        .animCrouchFromSlowLongjump =           MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
        .animFastLongjump =                     MARIO_ANIM_FAST_LONGJUMP,
        .animSlowLongjump =                     MARIO_ANIM_SLOW_LONGJUMP,
        .animAirborneOnStomach =                MARIO_ANIM_AIRBORNE_ON_STOMACH,
        .animWalkWithLightObj =                 MARIO_ANIM_WALK_WITH_LIGHT_OBJ,
        .animRunWithLightObj =                  MARIO_ANIM_RUN_WITH_LIGHT_OBJ,
        .animSlowWalkWithLightObj =             MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ,
        .animShiveringWarmingHand =             MARIO_ANIM_SHIVERING_WARMING_HAND,
        .animShiveringReturnToIdle =            MARIO_ANIM_SHIVERING_RETURN_TO_IDLE,
        .animShivering =                        MARIO_ANIM_SHIVERING,
        .animClimbDownLedge =                   MARIO_ANIM_CLIMB_DOWN_LEDGE,
        .animCreditsWaving =                    MARIO_ANIM_CREDITS_WAVING,
        .animCreditsLookUp =                    MARIO_ANIM_CREDITS_LOOK_UP,
        .animCreditsReturnFromLookUp =          MARIO_ANIM_CREDITS_RETURN_FROM_LOOK_UP,
        .animCreditsRaiseHand =                 MARIO_ANIM_CREDITS_RAISE_HAND,
        .animCreditsLowerHand =                 MARIO_ANIM_CREDITS_LOWER_HAND,
        .animCreditsTakeOffCap =                MARIO_ANIM_CREDITS_TAKE_OFF_CAP,
        .animCreditsStartWalkLookUp =           MARIO_ANIM_CREDITS_START_WALK_LOOK_UP,
        .animCreditsLookBackThenRun =           MARIO_ANIM_CREDITS_LOOK_BACK_THEN_RUN,
        .animFinalBowserRaiseHandSpin =         MARIO_ANIM_FINAL_BOWSER_RAISE_HAND_SPIN,
        .animFinalBowserWingCapTakeOff =        MARIO_ANIM_FINAL_BOWSER_WING_CAP_TAKE_OFF,
        .animCreditsPeaceSign =                 MARIO_ANIM_CREDITS_PEACE_SIGN,
        .animStandUpFromLavaBoost =             MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST,
        .animFireLavaBurn =                     MARIO_ANIM_FIRE_LAVA_BURN,
        .animWingCapFly =                       MARIO_ANIM_WING_CAP_FLY,
        .animHangOnOwl =                        MARIO_ANIM_HANG_ON_OWL,
        .animLandOnStomach =                    MARIO_ANIM_LAND_ON_STOMACH,
        .animAirForwardKb =                     MARIO_ANIM_AIR_FORWARD_KB,
        .animDyingOnStomach =                   MARIO_ANIM_DYING_ON_STOMACH,
        .animSuffocating =                      MARIO_ANIM_SUFFOCATING,
        .animCoughing =                         MARIO_ANIM_COUGHING,
        .animThrowCatchKey =                    MARIO_ANIM_THROW_CATCH_KEY,
        .animDyingFallOver =                    MARIO_ANIM_DYING_FALL_OVER,
        .animIdleOnLedge =                      MARIO_ANIM_IDLE_ON_LEDGE,
        .animFastLedgeGrab =                    MARIO_ANIM_FAST_LEDGE_GRAB,
        .animHangOnCeiling =                    MARIO_ANIM_HANG_ON_CEILING,
        .animPutCapOn =                         MARIO_ANIM_PUT_CAP_ON,
        .animTakeCapOffThenOn =                 MARIO_ANIM_TAKE_CAP_OFF_THEN_ON,
        .animQuicklyPutCapOn =                  MARIO_ANIM_QUICKLY_PUT_CAP_ON,
        .animHeadStuckInGround =                MARIO_ANIM_HEAD_STUCK_IN_GROUND,
        .animGroundPoundLanding =               MARIO_ANIM_GROUND_POUND_LANDING,
        .animTripleJumpGroundPound =            MARIO_ANIM_TRIPLE_JUMP_GROUND_POUND,
        .animStartGroundPound =                 MARIO_ANIM_START_GROUND_POUND,
        .animGroundPound =                      MARIO_ANIM_GROUND_POUND,
        .animBottomStuckInGround =              MARIO_ANIM_BOTTOM_STUCK_IN_GROUND,
        .animIdleWithLightObj =                 MARIO_ANIM_IDLE_WITH_LIGHT_OBJ,
        .animJumpLandWithLightObj =             MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ,
        .animJumpWithLightObj =                 MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,
        .animFallLandWithLightObj =             MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ,
        .animFallWithLightObj =                 MARIO_ANIM_FALL_WITH_LIGHT_OBJ,
        .animFallFromSlidingWithLightObj =      MARIO_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animSlidingOnBottomWithLightObj =      MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ,
        .animStandUpFromSlidingWithLightObj =   MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animRidingShell =                      MARIO_ANIM_RIDING_SHELL,
        .animWalking =                          MARIO_ANIM_WALKING,
        .animForwardFlip =                      MARIO_ANIM_FORWARD_FLIP,
        .animJumpRidingShell =                  MARIO_ANIM_JUMP_RIDING_SHELL,
        .animLandFromDoubleJump =               MARIO_ANIM_LAND_FROM_DOUBLE_JUMP,
        .animDoubleJumpFall =                   MARIO_ANIM_DOUBLE_JUMP_FALL,
        .animSingleJump =                       MARIO_ANIM_SINGLE_JUMP,
        .animLandFromSingleJump =               MARIO_ANIM_LAND_FROM_SINGLE_JUMP,
        .animAirKick =                          MARIO_ANIM_AIR_KICK,
        .animDoubleJumpRise =                   MARIO_ANIM_DOUBLE_JUMP_RISE,
        .animStartForwardSpinning =             MARIO_ANIM_START_FORWARD_SPINNING,
        .animThrowLightObject =                 MARIO_ANIM_THROW_LIGHT_OBJECT,
        .animFallFromSlideKick =                MARIO_ANIM_FALL_FROM_SLIDE_KICK,
        .animBendKnessRidingShell =             MARIO_ANIM_BEND_KNESS_RIDING_SHELL,
        .animLegsStuckInGround =                MARIO_ANIM_LEGS_STUCK_IN_GROUND,
        .animGeneralFall =                      MARIO_ANIM_GENERAL_FALL,
        .animGeneralLand =                      MARIO_ANIM_GENERAL_LAND,
        .animBeingGrabbed =                     MARIO_ANIM_BEING_GRABBED,
        .animGrabHeavyObject =                  MARIO_ANIM_GRAB_HEAVY_OBJECT,
        .animSlowLandFromDive =                 MARIO_ANIM_SLOW_LAND_FROM_DIVE,
        .animFlyFromCannon =                    MARIO_ANIM_FLY_FROM_CANNON,
        .animMoveOnWireNetRight =               MARIO_ANIM_MOVE_ON_WIRE_NET_RIGHT,
        .animMoveOnWireNetLeft =                MARIO_ANIM_MOVE_ON_WIRE_NET_LEFT,
        .animMissingCap =                       MARIO_ANIM_MISSING_CAP,
        .animPullDoorWalkIn =                   MARIO_ANIM_PULL_DOOR_WALK_IN,
        .animPushDoorWalkIn =                   MARIO_ANIM_PUSH_DOOR_WALK_IN,
        .animUnlockDoor =                       MARIO_ANIM_UNLOCK_DOOR,
        .animStartReachPocket =                 MARIO_ANIM_START_REACH_POCKET,
        .animReachPocket =                      MARIO_ANIM_REACH_POCKET,
        .animStopReachPocket =                  MARIO_ANIM_STOP_REACH_POCKET,
        .animGroundThrow =                      MARIO_ANIM_GROUND_THROW,
        .animGroundKick =                       MARIO_ANIM_GROUND_KICK,
        .animFirstPunch =                       MARIO_ANIM_FIRST_PUNCH,
        .animSecondPunch =                      MARIO_ANIM_SECOND_PUNCH,
        .animFirstPunchFast =                   MARIO_ANIM_FIRST_PUNCH_FAST,
        .animSecondPunchFast =                  MARIO_ANIM_SECOND_PUNCH_FAST,
        .animPickUpLightObj =                   MARIO_ANIM_PICK_UP_LIGHT_OBJ,
        .animPushing =                          MARIO_ANIM_PUSHING,
        .animStartRidingShell =                 MARIO_ANIM_START_RIDING_SHELL,
        .animPlaceLightObj =                    MARIO_ANIM_PLACE_LIGHT_OBJ,
        .animForwardSpinning =                  MARIO_ANIM_FORWARD_SPINNING,
        .animBackwardSpinning =                 MARIO_ANIM_BACKWARD_SPINNING,
        .animBreakdance =                       MARIO_ANIM_BREAKDANCE,
        .animRunning =                          MARIO_ANIM_RUNNING,
        .animRunningUnused =                    MARIO_ANIM_RUNNING_UNUSED,
        .animSoftBackKb =                       MARIO_ANIM_SOFT_BACK_KB,
        .animSoftFrontKb =                      MARIO_ANIM_SOFT_FRONT_KB,
        .animDyingInQuicksand =                 MARIO_ANIM_DYING_IN_QUICKSAND,
        .animIdleInQuicksand =                  MARIO_ANIM_IDLE_IN_QUICKSAND,
        .animMoveInQuicksand =                  MARIO_ANIM_MOVE_IN_QUICKSAND,
        .animElectrocution =                    MARIO_ANIM_ELECTROCUTION,
        .animShocked =                          MARIO_ANIM_SHOCKED,
        .animBackwardKb =                       MARIO_ANIM_BACKWARD_KB,
        .animForwardKb =                        MARIO_ANIM_FORWARD_KB,
        .animIdleHeavyObj =                     MARIO_ANIM_IDLE_HEAVY_OBJ,
        .animStandAgainstWall =                 MARIO_ANIM_STAND_AGAINST_WALL,
        .animSidestepLeft =                     MARIO_ANIM_SIDESTEP_LEFT,
        .animSidestepRight =                    MARIO_ANIM_SIDESTEP_RIGHT,
        .animStartSleepIdle =                   MARIO_ANIM_START_SLEEP_IDLE,
        .animStartSleepScratch =                MARIO_ANIM_START_SLEEP_SCRATCH,
        .animStartSleepYawn =                   MARIO_ANIM_START_SLEEP_YAWN,
        .animStartSleepSitting =                MARIO_ANIM_START_SLEEP_SITTING,
        .animSleepIdle =                        MARIO_ANIM_SLEEP_IDLE,
        .animSleepStartLying =                  MARIO_ANIM_SLEEP_START_LYING,
        .animSleepLying =                       MARIO_ANIM_SLEEP_LYING,
        .animDive =                             MARIO_ANIM_DIVE,
        .animSlideDive =                        MARIO_ANIM_SLIDE_DIVE,
        .animGroundBonk =                       MARIO_ANIM_GROUND_BONK,
        .animStopSlideLightObj =                MARIO_ANIM_STOP_SLIDE_LIGHT_OBJ,
        .animSlideKick =                        MARIO_ANIM_SLIDE_KICK,
        .animCrouchFromSlideKick =              MARIO_ANIM_CROUCH_FROM_SLIDE_KICK,
        .animSlideMotionless =                  MARIO_ANIM_SLIDE_MOTIONLESS,
        .animStopSlide =                        MARIO_ANIM_STOP_SLIDE,
        .animFallFromSlide =                    MARIO_ANIM_FALL_FROM_SLIDE,
        .animSlide =                            MARIO_ANIM_SLIDE,
        .animTiptoe =                           MARIO_ANIM_TIPTOE,
        .animTwirlLand =                        MARIO_ANIM_TWIRL_LAND,
        .animTwirl =                            MARIO_ANIM_TWIRL,
        .animStartTwirl =                       MARIO_ANIM_START_TWIRL,
        .animStopCrouching =                    MARIO_ANIM_STOP_CROUCHING,
        .animStartCrouching =                   MARIO_ANIM_START_CROUCHING,
        .animCrouching =                        MARIO_ANIM_CROUCHING,
        .animCrawling =                         MARIO_ANIM_CRAWLING,
        .animStopCrawling =                     MARIO_ANIM_STOP_CRAWLING,
        .animStartCrawling =                    MARIO_ANIM_START_CRAWLING,
        .animSummonStar =                       MARIO_ANIM_SUMMON_STAR,
        .animReturnStarApproachDoor =           MARIO_ANIM_RETURN_STAR_APPROACH_DOOR,
        .animBackwardsWaterKb =                 MARIO_ANIM_BACKWARDS_WATER_KB,
        .animSwimWithObjPart1 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART1,
        .animSwimWithObjPart2 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART2,
        .animFlutterkickWithObj =               MARIO_ANIM_FLUTTERKICK_WITH_OBJ,
        .animWaterActionEndWithObj =            MARIO_ANIM_WATER_ACTION_END_WITH_OBJ,
        .animStopGrabObjWater =                 MARIO_ANIM_STOP_GRAB_OBJ_WATER,
        .animWaterIdleWithObj =                 MARIO_ANIM_WATER_IDLE_WITH_OBJ,
        .animDrowningPart1 =                    MARIO_ANIM_DROWNING_PART1,
        .animDrowningPart2 =                    MARIO_ANIM_DROWNING_PART2,
        .animWaterDying =                       MARIO_ANIM_WATER_DYING,
        .animWaterForwardKb =                   MARIO_ANIM_WATER_FORWARD_KB,
        .animFallFromWater =                    MARIO_ANIM_FALL_FROM_WATER,
        .animSwimPart1 =                        MARIO_ANIM_SWIM_PART1,
        .animSwimPart2 =                        MARIO_ANIM_SWIM_PART2,
        .animFlutterkick =                      MARIO_ANIM_FLUTTERKICK,
        .animWaterActionEnd =                   MARIO_ANIM_WATER_ACTION_END,
        .animWaterPickUpObj =                   MARIO_ANIM_WATER_PICK_UP_OBJ,
        .animWaterGrabObjPart2 =                MARIO_ANIM_WATER_GRAB_OBJ_PART2,
        .animWaterGrabObjPart1 =                MARIO_ANIM_WATER_GRAB_OBJ_PART1,
        .animWaterThrowObj =                    MARIO_ANIM_WATER_THROW_OBJ,
        .animWaterIdle =                        MARIO_ANIM_WATER_IDLE,
        .animWaterStarDance =                   MARIO_ANIM_WATER_STAR_DANCE,
        .animReturnFromWaterStarDance =         MARIO_ANIM_RETURN_FROM_WATER_STAR_DANCE,
        .animGrabBowser =                       MARIO_ANIM_GRAB_BOWSER,
        .animSwingingBowser =                   MARIO_ANIM_SWINGING_BOWSER,
        .animReleaseBowser =                    MARIO_ANIM_RELEASE_BOWSER,
        .animHoldingBowser =                    MARIO_ANIM_HOLDING_BOWSER,
        .animHeavyThrow =                       MARIO_ANIM_HEAVY_THROW,
        .animWalkPanting =                      MARIO_ANIM_WALK_PANTING,
        .animWalkWithHeavyObj =                 MARIO_ANIM_WALK_WITH_HEAVY_OBJ,
        .animTurningPart1 =                     MARIO_ANIM_TURNING_PART1,
        .animTurningPart2 =                     MARIO_ANIM_TURNING_PART2,
        .animSlideflipLand =                    MARIO_ANIM_SLIDEFLIP_LAND,
        .animSlideflip =                        MARIO_ANIM_SLIDEFLIP,
        .animTripleJumpLand =                   MARIO_ANIM_TRIPLE_JUMP_LAND,
        .animTripleJump =                       MARIO_ANIM_TRIPLE_JUMP,
        .animFirstPerson =                      MARIO_ANIM_FIRST_PERSON,
        .animIdleHeadLeft =                     MARIO_ANIM_IDLE_HEAD_LEFT,
        .animIdleHeadRight =                    MARIO_ANIM_IDLE_HEAD_RIGHT,
        .animIdleHeadCenter =                   MARIO_ANIM_IDLE_HEAD_CENTER,
        .animHandstandLeft =                    MARIO_ANIM_HANDSTAND_LEFT,
        .animHandstandRight =                   MARIO_ANIM_HANDSTAND_RIGHT,
        .animWakeFromSleep =                    MARIO_ANIM_WAKE_FROM_SLEEP,
        .animWakeFromLying =                    MARIO_ANIM_WAKE_FROM_LYING,
        .animStartTiptoe =                      MARIO_ANIM_START_TIPTOE,
        .animSlidejump =                        MARIO_ANIM_SLIDEJUMP,
        .animStartWallkick =                    MARIO_ANIM_START_WALLKICK,
        .animStarDance =                        MARIO_ANIM_STAR_DANCE,
        .animReturnFromStarDance =              MARIO_ANIM_RETURN_FROM_STAR_DANCE,
        .animForwardSpinningFlip =              MARIO_ANIM_FORWARD_SPINNING_FLIP,
        .animTripleJumpFly =                    MARIO_ANIM_TRIPLE_JUMP_FLY,

        // sounds
        .soundFreqScale        = 1.0f,
        .soundYahWahHoo        = SOUND_MARIO_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_MARIO_HOOHOO,
        .soundYahoo            = SOUND_MARIO_YAHOO,
        .soundUh               = SOUND_MARIO_UH,
        .soundHrmm             = SOUND_MARIO_HRMM,
        .soundWah2             = SOUND_MARIO_WAH2,
        .soundWhoa             = SOUND_MARIO_WHOA,
        .soundEeuh             = SOUND_MARIO_EEUH,
        .soundAttacked         = SOUND_MARIO_ATTACKED,
        .soundOoof             = SOUND_MARIO_OOOF,
        .soundOoof2            = SOUND_MARIO_OOOF2,
        .soundHereWeGo         = SOUND_MARIO_HERE_WE_GO,
        .soundYawning          = SOUND_MARIO_YAWNING,
        .soundSnoring1         = SOUND_MARIO_SNORING1,
        .soundSnoring2         = SOUND_MARIO_SNORING2,
        .soundWaaaooow         = SOUND_MARIO_WAAAOOOW,
        .soundHaha             = SOUND_MARIO_HAHA,
        .soundHaha_2           = SOUND_MARIO_HAHA_2,
        .soundUh2              = SOUND_MARIO_UH2,
        .soundUh2_2            = SOUND_MARIO_UH2_2,
        .soundOnFire           = SOUND_MARIO_ON_FIRE,
        .soundDying            = SOUND_MARIO_DYING,
        .soundPantingCold      = SOUND_MARIO_PANTING_COLD,
        .soundPanting          = SOUND_MARIO_PANTING,
        .soundCoughing1        = SOUND_MARIO_COUGHING1,
        .soundCoughing2        = SOUND_MARIO_COUGHING2,
        .soundCoughing3        = SOUND_MARIO_COUGHING3,
        .soundPunchYah         = SOUND_MARIO_PUNCH_YAH,
        .soundPunchHoo         = SOUND_MARIO_PUNCH_HOO,
        .soundMamaMia          = SOUND_MARIO_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_MARIO_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_MARIO_DROWNING,
        .soundPunchWah         = SOUND_MARIO_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_MARIO_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_MARIO_DOH,
        .soundGameOver         = SOUND_MARIO_GAME_OVER,
        .soundHello            = SOUND_MARIO_HELLO,
        .soundPressStartToPlay = SOUND_MARIO_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_MARIO_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_MARIO_SNORING3,
        .soundSoLongaBowser    = SOUND_MARIO_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_MARIO_IMA_TIRED,
        .soundLetsAGo          = CHAR_BASS_SOUND(SOUND_MARIO_LETS_A_GO),
        .soundOkeyDokey        = CHAR_BASS_SOUND(SOUND_MARIO_OKEY_DOKEY),
    },

    [CT_LUIGI] = {
        .type                  = CT_LUIGI,
        .name                  = "Luigi",
        .hudHead               = ')',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_luigi_head, .bitSize = 8, .width = 16, .height = 16 },
        .cameraHudHead         = GLYPH_CAM_LUIGI_HEAD,
        .modelId               = MODEL_LUIGI,
        .capModelId            = MODEL_LUIGIS_CAP,
        .capMetalModelId       = MODEL_LUIGIS_METAL_CAP,
        .capWingModelId        = MODEL_LUIGIS_WING_CAP,
        .capMetalWingModelId   = MODEL_LUIGIS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_TRANSPARENT,
        .capEnemyGfx           = luigi_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = luigi_cap_l_logo_decal_dl,
        .torsoRotMult          = 1.0f,
        // anim
        .animOffsetEnabled     = false,
        
        // character anims
        .animSlowLedgeGrab =                    MARIO_ANIM_SLOW_LEDGE_GRAB,
        .animFallOverBackwards =                MARIO_ANIM_FALL_OVER_BACKWARDS,
        .animBackwardAirKb =                    MARIO_ANIM_BACKWARD_AIR_KB,
        .animDyingOnBack =                      MARIO_ANIM_DYING_ON_BACK,
        .animBackflip =                         MARIO_ANIM_BACKFLIP,
        .animClimbUpPole =                      MARIO_ANIM_CLIMB_UP_POLE,
        .animGrabPoleShort =                    MARIO_ANIM_GRAB_POLE_SHORT,
        .animGrabPoleSwingPart1 =               MARIO_ANIM_GRAB_POLE_SWING_PART1,
        .animGrabPoleSwingPart2 =               MARIO_ANIM_GRAB_POLE_SWING_PART2,
        .animHandstandIdle =                    MARIO_ANIM_HANDSTAND_IDLE,
        .animHandstandJump =                    MARIO_ANIM_HANDSTAND_JUMP,
        .animStartHandstand =                   MARIO_ANIM_START_HANDSTAND,
        .animReturnFromHandstand =              MARIO_ANIM_RETURN_FROM_HANDSTAND,
        .animIdleOnPole =                       MARIO_ANIM_IDLE_ON_POLE,
        .animAPose =                            MARIO_ANIM_A_POSE,
        .animSkidOnGround =                     MARIO_ANIM_SKID_ON_GROUND,
        .animStopSkid =                         MARIO_ANIM_STOP_SKID,
        .animCrouchFromFastLongjump =           MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP,
        .animCrouchFromSlowLongjump =           MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
        .animFastLongjump =                     MARIO_ANIM_FAST_LONGJUMP,
        .animSlowLongjump =                     MARIO_ANIM_SLOW_LONGJUMP,
        .animAirborneOnStomach =                MARIO_ANIM_AIRBORNE_ON_STOMACH,
        .animWalkWithLightObj =                 MARIO_ANIM_WALK_WITH_LIGHT_OBJ,
        .animRunWithLightObj =                  MARIO_ANIM_RUN_WITH_LIGHT_OBJ,
        .animSlowWalkWithLightObj =             MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ,
        .animShiveringWarmingHand =             MARIO_ANIM_SHIVERING_WARMING_HAND,
        .animShiveringReturnToIdle =            MARIO_ANIM_SHIVERING_RETURN_TO_IDLE,
        .animShivering =                        MARIO_ANIM_SHIVERING,
        .animClimbDownLedge =                   MARIO_ANIM_CLIMB_DOWN_LEDGE,
        .animCreditsWaving =                    MARIO_ANIM_CREDITS_WAVING,
        .animCreditsLookUp =                    MARIO_ANIM_CREDITS_LOOK_UP,
        .animCreditsReturnFromLookUp =          MARIO_ANIM_CREDITS_RETURN_FROM_LOOK_UP,
        .animCreditsRaiseHand =                 MARIO_ANIM_CREDITS_RAISE_HAND,
        .animCreditsLowerHand =                 MARIO_ANIM_CREDITS_LOWER_HAND,
        .animCreditsTakeOffCap =                MARIO_ANIM_CREDITS_TAKE_OFF_CAP,
        .animCreditsStartWalkLookUp =           MARIO_ANIM_CREDITS_START_WALK_LOOK_UP,
        .animCreditsLookBackThenRun =           MARIO_ANIM_CREDITS_LOOK_BACK_THEN_RUN,
        .animFinalBowserRaiseHandSpin =         MARIO_ANIM_FINAL_BOWSER_RAISE_HAND_SPIN,
        .animFinalBowserWingCapTakeOff =        MARIO_ANIM_FINAL_BOWSER_WING_CAP_TAKE_OFF,
        .animCreditsPeaceSign =                 MARIO_ANIM_CREDITS_PEACE_SIGN,
        .animStandUpFromLavaBoost =             MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST,
        .animFireLavaBurn =                     MARIO_ANIM_FIRE_LAVA_BURN,
        .animWingCapFly =                       MARIO_ANIM_WING_CAP_FLY,
        .animHangOnOwl =                        MARIO_ANIM_HANG_ON_OWL,
        .animLandOnStomach =                    MARIO_ANIM_LAND_ON_STOMACH,
        .animAirForwardKb =                     MARIO_ANIM_AIR_FORWARD_KB,
        .animDyingOnStomach =                   MARIO_ANIM_DYING_ON_STOMACH,
        .animSuffocating =                      MARIO_ANIM_SUFFOCATING,
        .animCoughing =                         MARIO_ANIM_COUGHING,
        .animThrowCatchKey =                    MARIO_ANIM_THROW_CATCH_KEY,
        .animDyingFallOver =                    MARIO_ANIM_DYING_FALL_OVER,
        .animIdleOnLedge =                      MARIO_ANIM_IDLE_ON_LEDGE,
        .animFastLedgeGrab =                    MARIO_ANIM_FAST_LEDGE_GRAB,
        .animHangOnCeiling =                    MARIO_ANIM_HANG_ON_CEILING,
        .animPutCapOn =                         MARIO_ANIM_PUT_CAP_ON,
        .animTakeCapOffThenOn =                 MARIO_ANIM_TAKE_CAP_OFF_THEN_ON,
        .animQuicklyPutCapOn =                  MARIO_ANIM_QUICKLY_PUT_CAP_ON,
        .animHeadStuckInGround =                MARIO_ANIM_HEAD_STUCK_IN_GROUND,
        .animGroundPoundLanding =               MARIO_ANIM_GROUND_POUND_LANDING,
        .animTripleJumpGroundPound =            MARIO_ANIM_TRIPLE_JUMP_GROUND_POUND,
        .animStartGroundPound =                 MARIO_ANIM_START_GROUND_POUND,
        .animGroundPound =                      MARIO_ANIM_GROUND_POUND,
        .animBottomStuckInGround =              MARIO_ANIM_BOTTOM_STUCK_IN_GROUND,
        .animIdleWithLightObj =                 MARIO_ANIM_IDLE_WITH_LIGHT_OBJ,
        .animJumpLandWithLightObj =             MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ,
        .animJumpWithLightObj =                 MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,
        .animFallLandWithLightObj =             MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ,
        .animFallWithLightObj =                 MARIO_ANIM_FALL_WITH_LIGHT_OBJ,
        .animFallFromSlidingWithLightObj =      MARIO_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animSlidingOnBottomWithLightObj =      MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ,
        .animStandUpFromSlidingWithLightObj =   MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animRidingShell =                      MARIO_ANIM_RIDING_SHELL,
        .animWalking =                          MARIO_ANIM_WALKING,
        .animForwardFlip =                      MARIO_ANIM_FORWARD_FLIP,
        .animJumpRidingShell =                  MARIO_ANIM_JUMP_RIDING_SHELL,
        .animLandFromDoubleJump =               MARIO_ANIM_LAND_FROM_DOUBLE_JUMP,
        .animDoubleJumpFall =                   MARIO_ANIM_DOUBLE_JUMP_FALL,
        .animSingleJump =                       MARIO_ANIM_SINGLE_JUMP,
        .animLandFromSingleJump =               MARIO_ANIM_LAND_FROM_SINGLE_JUMP,
        .animAirKick =                          MARIO_ANIM_AIR_KICK,
        .animDoubleJumpRise =                   MARIO_ANIM_DOUBLE_JUMP_RISE,
        .animStartForwardSpinning =             MARIO_ANIM_START_FORWARD_SPINNING,
        .animThrowLightObject =                 MARIO_ANIM_THROW_LIGHT_OBJECT,
        .animFallFromSlideKick =                MARIO_ANIM_FALL_FROM_SLIDE_KICK,
        .animBendKnessRidingShell =             MARIO_ANIM_BEND_KNESS_RIDING_SHELL,
        .animLegsStuckInGround =                MARIO_ANIM_LEGS_STUCK_IN_GROUND,
        .animGeneralFall =                      MARIO_ANIM_GENERAL_FALL,
        .animGeneralLand =                      MARIO_ANIM_GENERAL_LAND,
        .animBeingGrabbed =                     MARIO_ANIM_BEING_GRABBED,
        .animGrabHeavyObject =                  MARIO_ANIM_GRAB_HEAVY_OBJECT,
        .animSlowLandFromDive =                 MARIO_ANIM_SLOW_LAND_FROM_DIVE,
        .animFlyFromCannon =                    MARIO_ANIM_FLY_FROM_CANNON,
        .animMoveOnWireNetRight =               MARIO_ANIM_MOVE_ON_WIRE_NET_RIGHT,
        .animMoveOnWireNetLeft =                MARIO_ANIM_MOVE_ON_WIRE_NET_LEFT,
        .animMissingCap =                       MARIO_ANIM_MISSING_CAP,
        .animPullDoorWalkIn =                   MARIO_ANIM_PULL_DOOR_WALK_IN,
        .animPushDoorWalkIn =                   MARIO_ANIM_PUSH_DOOR_WALK_IN,
        .animUnlockDoor =                       MARIO_ANIM_UNLOCK_DOOR,
        .animStartReachPocket =                 MARIO_ANIM_START_REACH_POCKET,
        .animReachPocket =                      MARIO_ANIM_REACH_POCKET,
        .animStopReachPocket =                  MARIO_ANIM_STOP_REACH_POCKET,
        .animGroundThrow =                      MARIO_ANIM_GROUND_THROW,
        .animGroundKick =                       MARIO_ANIM_GROUND_KICK,
        .animFirstPunch =                       MARIO_ANIM_FIRST_PUNCH,
        .animSecondPunch =                      MARIO_ANIM_SECOND_PUNCH,
        .animFirstPunchFast =                   MARIO_ANIM_FIRST_PUNCH_FAST,
        .animSecondPunchFast =                  MARIO_ANIM_SECOND_PUNCH_FAST,
        .animPickUpLightObj =                   MARIO_ANIM_PICK_UP_LIGHT_OBJ,
        .animPushing =                          MARIO_ANIM_PUSHING,
        .animStartRidingShell =                 MARIO_ANIM_START_RIDING_SHELL,
        .animPlaceLightObj =                    MARIO_ANIM_PLACE_LIGHT_OBJ,
        .animForwardSpinning =                  MARIO_ANIM_FORWARD_SPINNING,
        .animBackwardSpinning =                 MARIO_ANIM_BACKWARD_SPINNING,
        .animBreakdance =                       MARIO_ANIM_BREAKDANCE,
        .animRunning =                          MARIO_ANIM_RUNNING,
        .animRunningUnused =                    MARIO_ANIM_RUNNING_UNUSED,
        .animSoftBackKb =                       MARIO_ANIM_SOFT_BACK_KB,
        .animSoftFrontKb =                      MARIO_ANIM_SOFT_FRONT_KB,
        .animDyingInQuicksand =                 MARIO_ANIM_DYING_IN_QUICKSAND,
        .animIdleInQuicksand =                  MARIO_ANIM_IDLE_IN_QUICKSAND,
        .animMoveInQuicksand =                  MARIO_ANIM_MOVE_IN_QUICKSAND,
        .animElectrocution =                    MARIO_ANIM_ELECTROCUTION,
        .animShocked =                          MARIO_ANIM_SHOCKED,
        .animBackwardKb =                       MARIO_ANIM_BACKWARD_KB,
        .animForwardKb =                        MARIO_ANIM_FORWARD_KB,
        .animIdleHeavyObj =                     MARIO_ANIM_IDLE_HEAVY_OBJ,
        .animStandAgainstWall =                 MARIO_ANIM_STAND_AGAINST_WALL,
        .animSidestepLeft =                     MARIO_ANIM_SIDESTEP_LEFT,
        .animSidestepRight =                    MARIO_ANIM_SIDESTEP_RIGHT,
        .animStartSleepIdle =                   MARIO_ANIM_START_SLEEP_IDLE,
        .animStartSleepScratch =                MARIO_ANIM_START_SLEEP_SCRATCH,
        .animStartSleepYawn =                   MARIO_ANIM_START_SLEEP_YAWN,
        .animStartSleepSitting =                MARIO_ANIM_START_SLEEP_SITTING,
        .animSleepIdle =                        MARIO_ANIM_SLEEP_IDLE,
        .animSleepStartLying =                  MARIO_ANIM_SLEEP_START_LYING,
        .animSleepLying =                       MARIO_ANIM_SLEEP_LYING,
        .animDive =                             MARIO_ANIM_DIVE,
        .animSlideDive =                        MARIO_ANIM_SLIDE_DIVE,
        .animGroundBonk =                       MARIO_ANIM_GROUND_BONK,
        .animStopSlideLightObj =                MARIO_ANIM_STOP_SLIDE_LIGHT_OBJ,
        .animSlideKick =                        MARIO_ANIM_SLIDE_KICK,
        .animCrouchFromSlideKick =              MARIO_ANIM_CROUCH_FROM_SLIDE_KICK,
        .animSlideMotionless =                  MARIO_ANIM_SLIDE_MOTIONLESS,
        .animStopSlide =                        MARIO_ANIM_STOP_SLIDE,
        .animFallFromSlide =                    MARIO_ANIM_FALL_FROM_SLIDE,
        .animSlide =                            MARIO_ANIM_SLIDE,
        .animTiptoe =                           MARIO_ANIM_TIPTOE,
        .animTwirlLand =                        MARIO_ANIM_TWIRL_LAND,
        .animTwirl =                            MARIO_ANIM_TWIRL,
        .animStartTwirl =                       MARIO_ANIM_START_TWIRL,
        .animStopCrouching =                    MARIO_ANIM_STOP_CROUCHING,
        .animStartCrouching =                   MARIO_ANIM_START_CROUCHING,
        .animCrouching =                        MARIO_ANIM_CROUCHING,
        .animCrawling =                         MARIO_ANIM_CRAWLING,
        .animStopCrawling =                     MARIO_ANIM_STOP_CRAWLING,
        .animStartCrawling =                    MARIO_ANIM_START_CRAWLING,
        .animSummonStar =                       MARIO_ANIM_SUMMON_STAR,
        .animReturnStarApproachDoor =           MARIO_ANIM_RETURN_STAR_APPROACH_DOOR,
        .animBackwardsWaterKb =                 MARIO_ANIM_BACKWARDS_WATER_KB,
        .animSwimWithObjPart1 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART1,
        .animSwimWithObjPart2 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART2,
        .animFlutterkickWithObj =               MARIO_ANIM_FLUTTERKICK_WITH_OBJ,
        .animWaterActionEndWithObj =            MARIO_ANIM_WATER_ACTION_END_WITH_OBJ,
        .animStopGrabObjWater =                 MARIO_ANIM_STOP_GRAB_OBJ_WATER,
        .animWaterIdleWithObj =                 MARIO_ANIM_WATER_IDLE_WITH_OBJ,
        .animDrowningPart1 =                    MARIO_ANIM_DROWNING_PART1,
        .animDrowningPart2 =                    MARIO_ANIM_DROWNING_PART2,
        .animWaterDying =                       MARIO_ANIM_WATER_DYING,
        .animWaterForwardKb =                   MARIO_ANIM_WATER_FORWARD_KB,
        .animFallFromWater =                    MARIO_ANIM_FALL_FROM_WATER,
        .animSwimPart1 =                        MARIO_ANIM_SWIM_PART1,
        .animSwimPart2 =                        MARIO_ANIM_SWIM_PART2,
        .animFlutterkick =                      MARIO_ANIM_FLUTTERKICK,
        .animWaterActionEnd =                   MARIO_ANIM_WATER_ACTION_END,
        .animWaterPickUpObj =                   MARIO_ANIM_WATER_PICK_UP_OBJ,
        .animWaterGrabObjPart2 =                MARIO_ANIM_WATER_GRAB_OBJ_PART2,
        .animWaterGrabObjPart1 =                MARIO_ANIM_WATER_GRAB_OBJ_PART1,
        .animWaterThrowObj =                    MARIO_ANIM_WATER_THROW_OBJ,
        .animWaterIdle =                        MARIO_ANIM_WATER_IDLE,
        .animWaterStarDance =                   MARIO_ANIM_WATER_STAR_DANCE,
        .animReturnFromWaterStarDance =         MARIO_ANIM_RETURN_FROM_WATER_STAR_DANCE,
        .animGrabBowser =                       MARIO_ANIM_GRAB_BOWSER,
        .animSwingingBowser =                   MARIO_ANIM_SWINGING_BOWSER,
        .animReleaseBowser =                    MARIO_ANIM_RELEASE_BOWSER,
        .animHoldingBowser =                    MARIO_ANIM_HOLDING_BOWSER,
        .animHeavyThrow =                       MARIO_ANIM_HEAVY_THROW,
        .animWalkPanting =                      MARIO_ANIM_WALK_PANTING,
        .animWalkWithHeavyObj =                 MARIO_ANIM_WALK_WITH_HEAVY_OBJ,
        .animTurningPart1 =                     MARIO_ANIM_TURNING_PART1,
        .animTurningPart2 =                     MARIO_ANIM_TURNING_PART2,
        .animSlideflipLand =                    MARIO_ANIM_SLIDEFLIP_LAND,
        .animSlideflip =                        MARIO_ANIM_SLIDEFLIP,
        .animTripleJumpLand =                   MARIO_ANIM_TRIPLE_JUMP_LAND,
        .animTripleJump =                       MARIO_ANIM_TRIPLE_JUMP,
        .animFirstPerson =                      MARIO_ANIM_FIRST_PERSON,
        .animIdleHeadLeft =                     MARIO_ANIM_IDLE_HEAD_LEFT,
        .animIdleHeadRight =                    MARIO_ANIM_IDLE_HEAD_RIGHT,
        .animIdleHeadCenter =                   MARIO_ANIM_IDLE_HEAD_CENTER,
        .animHandstandLeft =                    MARIO_ANIM_HANDSTAND_LEFT,
        .animHandstandRight =                   MARIO_ANIM_HANDSTAND_RIGHT,
        .animWakeFromSleep =                    MARIO_ANIM_WAKE_FROM_SLEEP,
        .animWakeFromLying =                    MARIO_ANIM_WAKE_FROM_LYING,
        .animStartTiptoe =                      MARIO_ANIM_START_TIPTOE,
        .animSlidejump =                        MARIO_ANIM_SLIDEJUMP,
        .animStartWallkick =                    MARIO_ANIM_START_WALLKICK,
        .animStarDance =                        MARIO_ANIM_STAR_DANCE,
        .animReturnFromStarDance =              MARIO_ANIM_RETURN_FROM_STAR_DANCE,
        .animForwardSpinningFlip =              MARIO_ANIM_FORWARD_SPINNING_FLIP,
        .animTripleJumpFly =                    MARIO_ANIM_TRIPLE_JUMP_FLY,

        // sounds
        .soundFreqScale        = 1.0f,
        .soundYahWahHoo        = SOUND_LUIGI_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_LUIGI_HOOHOO,
        .soundYahoo            = SOUND_LUIGI_YAHOO,
        .soundUh               = SOUND_LUIGI_UH,
        .soundHrmm             = SOUND_LUIGI_HRMM,
        .soundWah2             = SOUND_LUIGI_WAH2,
        .soundWhoa             = SOUND_LUIGI_WHOA,
        .soundEeuh             = SOUND_LUIGI_EEUH,
        .soundAttacked         = SOUND_LUIGI_ATTACKED,
        .soundOoof             = SOUND_LUIGI_OOOF,
        .soundOoof2            = SOUND_LUIGI_OOOF2,
        .soundHereWeGo         = SOUND_LUIGI_HERE_WE_GO,
        .soundYawning          = SOUND_LUIGI_YAWNING,
        .soundSnoring1         = SOUND_LUIGI_SNORING1,
        .soundSnoring2         = SOUND_LUIGI_SNORING2,
        .soundWaaaooow         = SOUND_LUIGI_WAAAOOOW,
        .soundHaha             = SOUND_LUIGI_HAHA,
        .soundHaha_2           = SOUND_LUIGI_HAHA_2,
        .soundUh2              = SOUND_LUIGI_UH2,
        .soundUh2_2            = SOUND_LUIGI_UH2_2,
        .soundOnFire           = SOUND_LUIGI_ON_FIRE,
        .soundDying            = SOUND_LUIGI_DYING,
        .soundPantingCold      = SOUND_LUIGI_PANTING_COLD,
        .soundPanting          = SOUND_LUIGI_PANTING,
        .soundCoughing1        = SOUND_LUIGI_COUGHING1,
        .soundCoughing2        = SOUND_LUIGI_COUGHING2,
        .soundCoughing3        = SOUND_LUIGI_COUGHING3,
        .soundPunchYah         = SOUND_LUIGI_PUNCH_YAH,
        .soundPunchHoo         = SOUND_LUIGI_PUNCH_HOO,
        .soundMamaMia          = SOUND_LUIGI_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_LUIGI_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_LUIGI_DROWNING,
        .soundPunchWah         = SOUND_LUIGI_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_LUIGI_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_LUIGI_DOH,
        .soundGameOver         = SOUND_LUIGI_GAME_OVER,
        .soundHello            = SOUND_LUIGI_HELLO,
        .soundPressStartToPlay = SOUND_LUIGI_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_LUIGI_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_LUIGI_SNORING3,
        .soundSoLongaBowser    = SOUND_LUIGI_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_LUIGI_IMA_TIRED,
        .soundLetsAGo          = CHAR_BASS_SOUND(SOUND_LUIGI_LETS_A_GO),
        .soundOkeyDokey        = CHAR_BASS_SOUND(SOUND_LUIGI_OKEY_DOKEY),
    },

    [CT_TOAD] = {
        .type                  = CT_TOAD,
        .name                  = "Toad",
        .hudHead               = '|',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_toad_head, .bitSize = 8, .width = 16, .height = 16 },
        .cameraHudHead         = GLYPH_CAM_TOAD_HEAD,
        .modelId               = MODEL_TOAD_PLAYER,
        .capModelId            = MODEL_TOADS_CAP,
        .capMetalModelId       = MODEL_TOADS_METAL_CAP,
        .capWingModelId        = MODEL_TOADS_WING_CAP,
        .capMetalWingModelId   = MODEL_TOADS_WING_CAP,
        .capEnemyLayer         = LAYER_TRANSPARENT,
        .capEnemyGfx           = toad_player_dl_cap,
        .capEnemyDecalGfx      = toad_player_dl_cap_decal,
        .torsoRotMult          = 1.0f,
        // anim
        .animOffsetEnabled     = false,
        
        // character anims
        .animSlowLedgeGrab =                    MARIO_ANIM_SLOW_LEDGE_GRAB,
        .animFallOverBackwards =                MARIO_ANIM_FALL_OVER_BACKWARDS,
        .animBackwardAirKb =                    MARIO_ANIM_BACKWARD_AIR_KB,
        .animDyingOnBack =                      MARIO_ANIM_DYING_ON_BACK,
        .animBackflip =                         MARIO_ANIM_BACKFLIP,
        .animClimbUpPole =                      MARIO_ANIM_CLIMB_UP_POLE,
        .animGrabPoleShort =                    MARIO_ANIM_GRAB_POLE_SHORT,
        .animGrabPoleSwingPart1 =               MARIO_ANIM_GRAB_POLE_SWING_PART1,
        .animGrabPoleSwingPart2 =               MARIO_ANIM_GRAB_POLE_SWING_PART2,
        .animHandstandIdle =                    MARIO_ANIM_HANDSTAND_IDLE,
        .animHandstandJump =                    MARIO_ANIM_HANDSTAND_JUMP,
        .animStartHandstand =                   MARIO_ANIM_START_HANDSTAND,
        .animReturnFromHandstand =              MARIO_ANIM_RETURN_FROM_HANDSTAND,
        .animIdleOnPole =                       MARIO_ANIM_IDLE_ON_POLE,
        .animAPose =                            MARIO_ANIM_A_POSE,
        .animSkidOnGround =                     MARIO_ANIM_SKID_ON_GROUND,
        .animStopSkid =                         MARIO_ANIM_STOP_SKID,
        .animCrouchFromFastLongjump =           MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP,
        .animCrouchFromSlowLongjump =           MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
        .animFastLongjump =                     MARIO_ANIM_FAST_LONGJUMP,
        .animSlowLongjump =                     MARIO_ANIM_SLOW_LONGJUMP,
        .animAirborneOnStomach =                MARIO_ANIM_AIRBORNE_ON_STOMACH,
        .animWalkWithLightObj =                 MARIO_ANIM_WALK_WITH_LIGHT_OBJ,
        .animRunWithLightObj =                  MARIO_ANIM_RUN_WITH_LIGHT_OBJ,
        .animSlowWalkWithLightObj =             MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ,
        .animShiveringWarmingHand =             MARIO_ANIM_SHIVERING_WARMING_HAND,
        .animShiveringReturnToIdle =            MARIO_ANIM_SHIVERING_RETURN_TO_IDLE,
        .animShivering =                        MARIO_ANIM_SHIVERING,
        .animClimbDownLedge =                   MARIO_ANIM_CLIMB_DOWN_LEDGE,
        .animCreditsWaving =                    MARIO_ANIM_CREDITS_WAVING,
        .animCreditsLookUp =                    MARIO_ANIM_CREDITS_LOOK_UP,
        .animCreditsReturnFromLookUp =          MARIO_ANIM_CREDITS_RETURN_FROM_LOOK_UP,
        .animCreditsRaiseHand =                 MARIO_ANIM_CREDITS_RAISE_HAND,
        .animCreditsLowerHand =                 MARIO_ANIM_CREDITS_LOWER_HAND,
        .animCreditsTakeOffCap =                MARIO_ANIM_CREDITS_TAKE_OFF_CAP,
        .animCreditsStartWalkLookUp =           MARIO_ANIM_CREDITS_START_WALK_LOOK_UP,
        .animCreditsLookBackThenRun =           MARIO_ANIM_CREDITS_LOOK_BACK_THEN_RUN,
        .animFinalBowserRaiseHandSpin =         MARIO_ANIM_FINAL_BOWSER_RAISE_HAND_SPIN,
        .animFinalBowserWingCapTakeOff =        MARIO_ANIM_FINAL_BOWSER_WING_CAP_TAKE_OFF,
        .animCreditsPeaceSign =                 MARIO_ANIM_CREDITS_PEACE_SIGN,
        .animStandUpFromLavaBoost =             MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST,
        .animFireLavaBurn =                     MARIO_ANIM_FIRE_LAVA_BURN,
        .animWingCapFly =                       MARIO_ANIM_WING_CAP_FLY,
        .animHangOnOwl =                        MARIO_ANIM_HANG_ON_OWL,
        .animLandOnStomach =                    MARIO_ANIM_LAND_ON_STOMACH,
        .animAirForwardKb =                     MARIO_ANIM_AIR_FORWARD_KB,
        .animDyingOnStomach =                   MARIO_ANIM_DYING_ON_STOMACH,
        .animSuffocating =                      MARIO_ANIM_SUFFOCATING,
        .animCoughing =                         MARIO_ANIM_COUGHING,
        .animThrowCatchKey =                    MARIO_ANIM_THROW_CATCH_KEY,
        .animDyingFallOver =                    MARIO_ANIM_DYING_FALL_OVER,
        .animIdleOnLedge =                      MARIO_ANIM_IDLE_ON_LEDGE,
        .animFastLedgeGrab =                    MARIO_ANIM_FAST_LEDGE_GRAB,
        .animHangOnCeiling =                    MARIO_ANIM_HANG_ON_CEILING,
        .animPutCapOn =                         MARIO_ANIM_PUT_CAP_ON,
        .animTakeCapOffThenOn =                 MARIO_ANIM_TAKE_CAP_OFF_THEN_ON,
        .animQuicklyPutCapOn =                  MARIO_ANIM_QUICKLY_PUT_CAP_ON,
        .animHeadStuckInGround =                MARIO_ANIM_HEAD_STUCK_IN_GROUND,
        .animGroundPoundLanding =               MARIO_ANIM_GROUND_POUND_LANDING,
        .animTripleJumpGroundPound =            MARIO_ANIM_TRIPLE_JUMP_GROUND_POUND,
        .animStartGroundPound =                 MARIO_ANIM_START_GROUND_POUND,
        .animGroundPound =                      MARIO_ANIM_GROUND_POUND,
        .animBottomStuckInGround =              MARIO_ANIM_BOTTOM_STUCK_IN_GROUND,
        .animIdleWithLightObj =                 MARIO_ANIM_IDLE_WITH_LIGHT_OBJ,
        .animJumpLandWithLightObj =             MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ,
        .animJumpWithLightObj =                 MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,
        .animFallLandWithLightObj =             MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ,
        .animFallWithLightObj =                 MARIO_ANIM_FALL_WITH_LIGHT_OBJ,
        .animFallFromSlidingWithLightObj =      MARIO_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animSlidingOnBottomWithLightObj =      MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ,
        .animStandUpFromSlidingWithLightObj =   MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animRidingShell =                      MARIO_ANIM_RIDING_SHELL,
        .animWalking =                          MARIO_ANIM_WALKING,
        .animForwardFlip =                      MARIO_ANIM_FORWARD_FLIP,
        .animJumpRidingShell =                  MARIO_ANIM_JUMP_RIDING_SHELL,
        .animLandFromDoubleJump =               MARIO_ANIM_LAND_FROM_DOUBLE_JUMP,
        .animDoubleJumpFall =                   MARIO_ANIM_DOUBLE_JUMP_FALL,
        .animSingleJump =                       MARIO_ANIM_SINGLE_JUMP,
        .animLandFromSingleJump =               MARIO_ANIM_LAND_FROM_SINGLE_JUMP,
        .animAirKick =                          MARIO_ANIM_AIR_KICK,
        .animDoubleJumpRise =                   MARIO_ANIM_DOUBLE_JUMP_RISE,
        .animStartForwardSpinning =             MARIO_ANIM_START_FORWARD_SPINNING,
        .animThrowLightObject =                 MARIO_ANIM_THROW_LIGHT_OBJECT,
        .animFallFromSlideKick =                MARIO_ANIM_FALL_FROM_SLIDE_KICK,
        .animBendKnessRidingShell =             MARIO_ANIM_BEND_KNESS_RIDING_SHELL,
        .animLegsStuckInGround =                MARIO_ANIM_LEGS_STUCK_IN_GROUND,
        .animGeneralFall =                      MARIO_ANIM_GENERAL_FALL,
        .animGeneralLand =                      MARIO_ANIM_GENERAL_LAND,
        .animBeingGrabbed =                     MARIO_ANIM_BEING_GRABBED,
        .animGrabHeavyObject =                  MARIO_ANIM_GRAB_HEAVY_OBJECT,
        .animSlowLandFromDive =                 MARIO_ANIM_SLOW_LAND_FROM_DIVE,
        .animFlyFromCannon =                    MARIO_ANIM_FLY_FROM_CANNON,
        .animMoveOnWireNetRight =               MARIO_ANIM_MOVE_ON_WIRE_NET_RIGHT,
        .animMoveOnWireNetLeft =                MARIO_ANIM_MOVE_ON_WIRE_NET_LEFT,
        .animMissingCap =                       MARIO_ANIM_MISSING_CAP,
        .animPullDoorWalkIn =                   MARIO_ANIM_PULL_DOOR_WALK_IN,
        .animPushDoorWalkIn =                   MARIO_ANIM_PUSH_DOOR_WALK_IN,
        .animUnlockDoor =                       MARIO_ANIM_UNLOCK_DOOR,
        .animStartReachPocket =                 MARIO_ANIM_START_REACH_POCKET,
        .animReachPocket =                      MARIO_ANIM_REACH_POCKET,
        .animStopReachPocket =                  MARIO_ANIM_STOP_REACH_POCKET,
        .animGroundThrow =                      MARIO_ANIM_GROUND_THROW,
        .animGroundKick =                       MARIO_ANIM_GROUND_KICK,
        .animFirstPunch =                       MARIO_ANIM_FIRST_PUNCH,
        .animSecondPunch =                      MARIO_ANIM_SECOND_PUNCH,
        .animFirstPunchFast =                   MARIO_ANIM_FIRST_PUNCH_FAST,
        .animSecondPunchFast =                  MARIO_ANIM_SECOND_PUNCH_FAST,
        .animPickUpLightObj =                   MARIO_ANIM_PICK_UP_LIGHT_OBJ,
        .animPushing =                          MARIO_ANIM_PUSHING,
        .animStartRidingShell =                 MARIO_ANIM_START_RIDING_SHELL,
        .animPlaceLightObj =                    MARIO_ANIM_PLACE_LIGHT_OBJ,
        .animForwardSpinning =                  MARIO_ANIM_FORWARD_SPINNING,
        .animBackwardSpinning =                 MARIO_ANIM_BACKWARD_SPINNING,
        .animBreakdance =                       MARIO_ANIM_BREAKDANCE,
        .animRunning =                          MARIO_ANIM_RUNNING,
        .animRunningUnused =                    MARIO_ANIM_RUNNING_UNUSED,
        .animSoftBackKb =                       MARIO_ANIM_SOFT_BACK_KB,
        .animSoftFrontKb =                      MARIO_ANIM_SOFT_FRONT_KB,
        .animDyingInQuicksand =                 MARIO_ANIM_DYING_IN_QUICKSAND,
        .animIdleInQuicksand =                  MARIO_ANIM_IDLE_IN_QUICKSAND,
        .animMoveInQuicksand =                  MARIO_ANIM_MOVE_IN_QUICKSAND,
        .animElectrocution =                    MARIO_ANIM_ELECTROCUTION,
        .animShocked =                          MARIO_ANIM_SHOCKED,
        .animBackwardKb =                       MARIO_ANIM_BACKWARD_KB,
        .animForwardKb =                        MARIO_ANIM_FORWARD_KB,
        .animIdleHeavyObj =                     MARIO_ANIM_IDLE_HEAVY_OBJ,
        .animStandAgainstWall =                 MARIO_ANIM_STAND_AGAINST_WALL,
        .animSidestepLeft =                     MARIO_ANIM_SIDESTEP_LEFT,
        .animSidestepRight =                    MARIO_ANIM_SIDESTEP_RIGHT,
        .animStartSleepIdle =                   MARIO_ANIM_START_SLEEP_IDLE,
        .animStartSleepScratch =                MARIO_ANIM_START_SLEEP_SCRATCH,
        .animStartSleepYawn =                   MARIO_ANIM_START_SLEEP_YAWN,
        .animStartSleepSitting =                MARIO_ANIM_START_SLEEP_SITTING,
        .animSleepIdle =                        MARIO_ANIM_SLEEP_IDLE,
        .animSleepStartLying =                  MARIO_ANIM_SLEEP_START_LYING,
        .animSleepLying =                       MARIO_ANIM_SLEEP_LYING,
        .animDive =                             MARIO_ANIM_DIVE,
        .animSlideDive =                        MARIO_ANIM_SLIDE_DIVE,
        .animGroundBonk =                       MARIO_ANIM_GROUND_BONK,
        .animStopSlideLightObj =                MARIO_ANIM_STOP_SLIDE_LIGHT_OBJ,
        .animSlideKick =                        MARIO_ANIM_SLIDE_KICK,
        .animCrouchFromSlideKick =              MARIO_ANIM_CROUCH_FROM_SLIDE_KICK,
        .animSlideMotionless =                  MARIO_ANIM_SLIDE_MOTIONLESS,
        .animStopSlide =                        MARIO_ANIM_STOP_SLIDE,
        .animFallFromSlide =                    MARIO_ANIM_FALL_FROM_SLIDE,
        .animSlide =                            MARIO_ANIM_SLIDE,
        .animTiptoe =                           MARIO_ANIM_TIPTOE,
        .animTwirlLand =                        MARIO_ANIM_TWIRL_LAND,
        .animTwirl =                            MARIO_ANIM_TWIRL,
        .animStartTwirl =                       MARIO_ANIM_START_TWIRL,
        .animStopCrouching =                    MARIO_ANIM_STOP_CROUCHING,
        .animStartCrouching =                   MARIO_ANIM_START_CROUCHING,
        .animCrouching =                        MARIO_ANIM_CROUCHING,
        .animCrawling =                         MARIO_ANIM_CRAWLING,
        .animStopCrawling =                     MARIO_ANIM_STOP_CRAWLING,
        .animStartCrawling =                    MARIO_ANIM_START_CRAWLING,
        .animSummonStar =                       MARIO_ANIM_SUMMON_STAR,
        .animReturnStarApproachDoor =           MARIO_ANIM_RETURN_STAR_APPROACH_DOOR,
        .animBackwardsWaterKb =                 MARIO_ANIM_BACKWARDS_WATER_KB,
        .animSwimWithObjPart1 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART1,
        .animSwimWithObjPart2 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART2,
        .animFlutterkickWithObj =               MARIO_ANIM_FLUTTERKICK_WITH_OBJ,
        .animWaterActionEndWithObj =            MARIO_ANIM_WATER_ACTION_END_WITH_OBJ,
        .animStopGrabObjWater =                 MARIO_ANIM_STOP_GRAB_OBJ_WATER,
        .animWaterIdleWithObj =                 MARIO_ANIM_WATER_IDLE_WITH_OBJ,
        .animDrowningPart1 =                    MARIO_ANIM_DROWNING_PART1,
        .animDrowningPart2 =                    MARIO_ANIM_DROWNING_PART2,
        .animWaterDying =                       MARIO_ANIM_WATER_DYING,
        .animWaterForwardKb =                   MARIO_ANIM_WATER_FORWARD_KB,
        .animFallFromWater =                    MARIO_ANIM_FALL_FROM_WATER,
        .animSwimPart1 =                        MARIO_ANIM_SWIM_PART1,
        .animSwimPart2 =                        MARIO_ANIM_SWIM_PART2,
        .animFlutterkick =                      MARIO_ANIM_FLUTTERKICK,
        .animWaterActionEnd =                   MARIO_ANIM_WATER_ACTION_END,
        .animWaterPickUpObj =                   MARIO_ANIM_WATER_PICK_UP_OBJ,
        .animWaterGrabObjPart2 =                MARIO_ANIM_WATER_GRAB_OBJ_PART2,
        .animWaterGrabObjPart1 =                MARIO_ANIM_WATER_GRAB_OBJ_PART1,
        .animWaterThrowObj =                    MARIO_ANIM_WATER_THROW_OBJ,
        .animWaterIdle =                        MARIO_ANIM_WATER_IDLE,
        .animWaterStarDance =                   MARIO_ANIM_WATER_STAR_DANCE,
        .animReturnFromWaterStarDance =         MARIO_ANIM_RETURN_FROM_WATER_STAR_DANCE,
        .animGrabBowser =                       MARIO_ANIM_GRAB_BOWSER,
        .animSwingingBowser =                   MARIO_ANIM_SWINGING_BOWSER,
        .animReleaseBowser =                    MARIO_ANIM_RELEASE_BOWSER,
        .animHoldingBowser =                    MARIO_ANIM_HOLDING_BOWSER,
        .animHeavyThrow =                       MARIO_ANIM_HEAVY_THROW,
        .animWalkPanting =                      MARIO_ANIM_WALK_PANTING,
        .animWalkWithHeavyObj =                 MARIO_ANIM_WALK_WITH_HEAVY_OBJ,
        .animTurningPart1 =                     MARIO_ANIM_TURNING_PART1,
        .animTurningPart2 =                     MARIO_ANIM_TURNING_PART2,
        .animSlideflipLand =                    MARIO_ANIM_SLIDEFLIP_LAND,
        .animSlideflip =                        MARIO_ANIM_SLIDEFLIP,
        .animTripleJumpLand =                   MARIO_ANIM_TRIPLE_JUMP_LAND,
        .animTripleJump =                       MARIO_ANIM_TRIPLE_JUMP,
        .animFirstPerson =                      MARIO_ANIM_FIRST_PERSON,
        .animIdleHeadLeft =                     MARIO_ANIM_IDLE_HEAD_LEFT,
        .animIdleHeadRight =                    MARIO_ANIM_IDLE_HEAD_RIGHT,
        .animIdleHeadCenter =                   MARIO_ANIM_IDLE_HEAD_CENTER,
        .animHandstandLeft =                    MARIO_ANIM_HANDSTAND_LEFT,
        .animHandstandRight =                   MARIO_ANIM_HANDSTAND_RIGHT,
        .animWakeFromSleep =                    MARIO_ANIM_WAKE_FROM_SLEEP,
        .animWakeFromLying =                    MARIO_ANIM_WAKE_FROM_LYING,
        .animStartTiptoe =                      MARIO_ANIM_START_TIPTOE,
        .animSlidejump =                        MARIO_ANIM_SLIDEJUMP,
        .animStartWallkick =                    MARIO_ANIM_START_WALLKICK,
        .animStarDance =                        MARIO_ANIM_STAR_DANCE,
        .animReturnFromStarDance =              MARIO_ANIM_RETURN_FROM_STAR_DANCE,
        .animForwardSpinningFlip =              MARIO_ANIM_FORWARD_SPINNING_FLIP,
        .animTripleJumpFly =                    MARIO_ANIM_TRIPLE_JUMP_FLY,

        // sounds
        .soundFreqScale        = 1.25f,
        .soundYahWahHoo        = SOUND_MARIO_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_MARIO_HOOHOO,
        .soundYahoo            = SOUND_MARIO_YAHOO,
        .soundUh               = SOUND_MARIO_UH,
        .soundHrmm             = SOUND_MARIO_HRMM,
        .soundWah2             = SOUND_MARIO_WAH2,
        .soundWhoa             = SOUND_MARIO_WHOA,
        .soundEeuh             = SOUND_MARIO_EEUH,
        .soundAttacked         = SOUND_MARIO_ATTACKED,
        .soundOoof             = SOUND_MARIO_OOOF,
        .soundOoof2            = SOUND_MARIO_OOOF2,
        .soundHereWeGo         = SOUND_MARIO_HERE_WE_GO,
        .soundYawning          = SOUND_MARIO_YAWNING,
        .soundSnoring1         = SOUND_MARIO_SNORING1,
        .soundSnoring2         = SOUND_MARIO_SNORING2,
        .soundWaaaooow         = SOUND_MARIO_WAAAOOOW,
        .soundHaha             = SOUND_MARIO_HAHA,
        .soundHaha_2           = SOUND_MARIO_HAHA_2,
        .soundUh2              = SOUND_MARIO_UH2,
        .soundUh2_2            = SOUND_MARIO_UH2_2,
        .soundOnFire           = SOUND_MARIO_ON_FIRE,
        .soundDying            = SOUND_MARIO_DYING,
        .soundPantingCold      = SOUND_MARIO_PANTING_COLD,
        .soundPanting          = SOUND_MARIO_PANTING,
        .soundCoughing1        = SOUND_MARIO_COUGHING1,
        .soundCoughing2        = SOUND_MARIO_COUGHING2,
        .soundCoughing3        = SOUND_MARIO_COUGHING3,
        .soundPunchYah         = SOUND_MARIO_PUNCH_YAH,
        .soundPunchHoo         = SOUND_MARIO_PUNCH_HOO,
        .soundMamaMia          = SOUND_MARIO_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_MARIO_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_MARIO_DROWNING,
        .soundPunchWah         = SOUND_MARIO_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_MARIO_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_MARIO_DOH,
        .soundGameOver         = SOUND_MARIO_GAME_OVER,
        .soundHello            = SOUND_MARIO_HELLO,
        .soundPressStartToPlay = SOUND_MARIO_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_MARIO_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_MARIO_SNORING3,
        .soundSoLongaBowser    = SOUND_MARIO_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_MARIO_IMA_TIRED,
        .soundLetsAGo          = CHAR_BASS_SOUND(SOUND_MARIO_LETS_A_GO),
        .soundOkeyDokey        = CHAR_BASS_SOUND(SOUND_MARIO_OKEY_DOKEY),
    },

    [CT_WALUIGI] = {
        .type                  = CT_WALUIGI,
        .name                  = "Waluigi",
        .hudHead               = ']',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_waluigi_head, .bitSize = 8, .width = 16, .height = 16 },
        .cameraHudHead         = GLYPH_CAM_WALUIGI_HEAD,
        .modelId               = MODEL_WALUIGI,
        .capModelId            = MODEL_WALUIGIS_CAP,
        .capMetalModelId       = MODEL_WALUIGIS_METAL_CAP,
        .capWingModelId        = MODEL_WALUIGIS_WING_CAP,
        .capMetalWingModelId   = MODEL_WALUIGIS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_OPAQUE,
        .capEnemyGfx           = waluigi_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = NULL,
        .torsoRotMult          = 0.5f,
        // anim
        .animOffsetEnabled     = true,
        .animOffsetLowYPoint   = 11,
        .animOffsetFeet        = 25,
        .animOffsetHand        = -10,
        
        // character anims
        .animSlowLedgeGrab =                    MARIO_ANIM_SLOW_LEDGE_GRAB,
        .animFallOverBackwards =                MARIO_ANIM_FALL_OVER_BACKWARDS,
        .animBackwardAirKb =                    MARIO_ANIM_BACKWARD_AIR_KB,
        .animDyingOnBack =                      MARIO_ANIM_DYING_ON_BACK,
        .animBackflip =                         MARIO_ANIM_BACKFLIP,
        .animClimbUpPole =                      MARIO_ANIM_CLIMB_UP_POLE,
        .animGrabPoleShort =                    MARIO_ANIM_GRAB_POLE_SHORT,
        .animGrabPoleSwingPart1 =               MARIO_ANIM_GRAB_POLE_SWING_PART1,
        .animGrabPoleSwingPart2 =               MARIO_ANIM_GRAB_POLE_SWING_PART2,
        .animHandstandIdle =                    MARIO_ANIM_HANDSTAND_IDLE,
        .animHandstandJump =                    MARIO_ANIM_HANDSTAND_JUMP,
        .animStartHandstand =                   MARIO_ANIM_START_HANDSTAND,
        .animReturnFromHandstand =              MARIO_ANIM_RETURN_FROM_HANDSTAND,
        .animIdleOnPole =                       MARIO_ANIM_IDLE_ON_POLE,
        .animAPose =                            MARIO_ANIM_A_POSE,
        .animSkidOnGround =                     MARIO_ANIM_SKID_ON_GROUND,
        .animStopSkid =                         MARIO_ANIM_STOP_SKID,
        .animCrouchFromFastLongjump =           MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP,
        .animCrouchFromSlowLongjump =           MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
        .animFastLongjump =                     MARIO_ANIM_FAST_LONGJUMP,
        .animSlowLongjump =                     MARIO_ANIM_SLOW_LONGJUMP,
        .animAirborneOnStomach =                MARIO_ANIM_AIRBORNE_ON_STOMACH,
        .animWalkWithLightObj =                 MARIO_ANIM_WALK_WITH_LIGHT_OBJ,
        .animRunWithLightObj =                  MARIO_ANIM_RUN_WITH_LIGHT_OBJ,
        .animSlowWalkWithLightObj =             MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ,
        .animShiveringWarmingHand =             MARIO_ANIM_SHIVERING_WARMING_HAND,
        .animShiveringReturnToIdle =            MARIO_ANIM_SHIVERING_RETURN_TO_IDLE,
        .animShivering =                        MARIO_ANIM_SHIVERING,
        .animClimbDownLedge =                   MARIO_ANIM_CLIMB_DOWN_LEDGE,
        .animCreditsWaving =                    MARIO_ANIM_CREDITS_WAVING,
        .animCreditsLookUp =                    MARIO_ANIM_CREDITS_LOOK_UP,
        .animCreditsReturnFromLookUp =          MARIO_ANIM_CREDITS_RETURN_FROM_LOOK_UP,
        .animCreditsRaiseHand =                 MARIO_ANIM_CREDITS_RAISE_HAND,
        .animCreditsLowerHand =                 MARIO_ANIM_CREDITS_LOWER_HAND,
        .animCreditsTakeOffCap =                MARIO_ANIM_CREDITS_TAKE_OFF_CAP,
        .animCreditsStartWalkLookUp =           MARIO_ANIM_CREDITS_START_WALK_LOOK_UP,
        .animCreditsLookBackThenRun =           MARIO_ANIM_CREDITS_LOOK_BACK_THEN_RUN,
        .animFinalBowserRaiseHandSpin =         MARIO_ANIM_FINAL_BOWSER_RAISE_HAND_SPIN,
        .animFinalBowserWingCapTakeOff =        MARIO_ANIM_FINAL_BOWSER_WING_CAP_TAKE_OFF,
        .animCreditsPeaceSign =                 MARIO_ANIM_CREDITS_PEACE_SIGN,
        .animStandUpFromLavaBoost =             MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST,
        .animFireLavaBurn =                     MARIO_ANIM_FIRE_LAVA_BURN,
        .animWingCapFly =                       MARIO_ANIM_WING_CAP_FLY,
        .animHangOnOwl =                        MARIO_ANIM_HANG_ON_OWL,
        .animLandOnStomach =                    MARIO_ANIM_LAND_ON_STOMACH,
        .animAirForwardKb =                     MARIO_ANIM_AIR_FORWARD_KB,
        .animDyingOnStomach =                   MARIO_ANIM_DYING_ON_STOMACH,
        .animSuffocating =                      MARIO_ANIM_SUFFOCATING,
        .animCoughing =                         MARIO_ANIM_COUGHING,
        .animThrowCatchKey =                    MARIO_ANIM_THROW_CATCH_KEY,
        .animDyingFallOver =                    MARIO_ANIM_DYING_FALL_OVER,
        .animIdleOnLedge =                      MARIO_ANIM_IDLE_ON_LEDGE,
        .animFastLedgeGrab =                    MARIO_ANIM_FAST_LEDGE_GRAB,
        .animHangOnCeiling =                    MARIO_ANIM_HANG_ON_CEILING,
        .animPutCapOn =                         MARIO_ANIM_PUT_CAP_ON,
        .animTakeCapOffThenOn =                 MARIO_ANIM_TAKE_CAP_OFF_THEN_ON,
        .animQuicklyPutCapOn =                  MARIO_ANIM_QUICKLY_PUT_CAP_ON,
        .animHeadStuckInGround =                MARIO_ANIM_HEAD_STUCK_IN_GROUND,
        .animGroundPoundLanding =               MARIO_ANIM_GROUND_POUND_LANDING,
        .animTripleJumpGroundPound =            MARIO_ANIM_TRIPLE_JUMP_GROUND_POUND,
        .animStartGroundPound =                 MARIO_ANIM_START_GROUND_POUND,
        .animGroundPound =                      MARIO_ANIM_GROUND_POUND,
        .animBottomStuckInGround =              MARIO_ANIM_BOTTOM_STUCK_IN_GROUND,
        .animIdleWithLightObj =                 MARIO_ANIM_IDLE_WITH_LIGHT_OBJ,
        .animJumpLandWithLightObj =             MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ,
        .animJumpWithLightObj =                 MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,
        .animFallLandWithLightObj =             MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ,
        .animFallWithLightObj =                 MARIO_ANIM_FALL_WITH_LIGHT_OBJ,
        .animFallFromSlidingWithLightObj =      MARIO_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animSlidingOnBottomWithLightObj =      MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ,
        .animStandUpFromSlidingWithLightObj =   MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animRidingShell =                      MARIO_ANIM_RIDING_SHELL,
        .animWalking =                          WALUIGI_ANIM_WALKING,
        .animForwardFlip =                      MARIO_ANIM_FORWARD_FLIP,
        .animJumpRidingShell =                  MARIO_ANIM_JUMP_RIDING_SHELL,
        .animLandFromDoubleJump =               MARIO_ANIM_LAND_FROM_DOUBLE_JUMP,
        .animDoubleJumpFall =                   MARIO_ANIM_DOUBLE_JUMP_FALL,
        .animSingleJump =                       MARIO_ANIM_SINGLE_JUMP,
        .animLandFromSingleJump =               MARIO_ANIM_LAND_FROM_SINGLE_JUMP,
        .animAirKick =                          MARIO_ANIM_AIR_KICK,
        .animDoubleJumpRise =                   MARIO_ANIM_DOUBLE_JUMP_RISE,
        .animStartForwardSpinning =             MARIO_ANIM_START_FORWARD_SPINNING,
        .animThrowLightObject =                 MARIO_ANIM_THROW_LIGHT_OBJECT,
        .animFallFromSlideKick =                MARIO_ANIM_FALL_FROM_SLIDE_KICK,
        .animBendKnessRidingShell =             MARIO_ANIM_BEND_KNESS_RIDING_SHELL,
        .animLegsStuckInGround =                MARIO_ANIM_LEGS_STUCK_IN_GROUND,
        .animGeneralFall =                      MARIO_ANIM_GENERAL_FALL,
        .animGeneralLand =                      MARIO_ANIM_GENERAL_LAND,
        .animBeingGrabbed =                     MARIO_ANIM_BEING_GRABBED,
        .animGrabHeavyObject =                  MARIO_ANIM_GRAB_HEAVY_OBJECT,
        .animSlowLandFromDive =                 MARIO_ANIM_SLOW_LAND_FROM_DIVE,
        .animFlyFromCannon =                    MARIO_ANIM_FLY_FROM_CANNON,
        .animMoveOnWireNetRight =               MARIO_ANIM_MOVE_ON_WIRE_NET_RIGHT,
        .animMoveOnWireNetLeft =                MARIO_ANIM_MOVE_ON_WIRE_NET_LEFT,
        .animMissingCap =                       MARIO_ANIM_MISSING_CAP,
        .animPullDoorWalkIn =                   MARIO_ANIM_PULL_DOOR_WALK_IN,
        .animPushDoorWalkIn =                   MARIO_ANIM_PUSH_DOOR_WALK_IN,
        .animUnlockDoor =                       MARIO_ANIM_UNLOCK_DOOR,
        .animStartReachPocket =                 MARIO_ANIM_START_REACH_POCKET,
        .animReachPocket =                      MARIO_ANIM_REACH_POCKET,
        .animStopReachPocket =                  MARIO_ANIM_STOP_REACH_POCKET,
        .animGroundThrow =                      MARIO_ANIM_GROUND_THROW,
        .animGroundKick =                       MARIO_ANIM_GROUND_KICK,
        .animFirstPunch =                       MARIO_ANIM_FIRST_PUNCH,
        .animSecondPunch =                      MARIO_ANIM_SECOND_PUNCH,
        .animFirstPunchFast =                   MARIO_ANIM_FIRST_PUNCH_FAST,
        .animSecondPunchFast =                  MARIO_ANIM_SECOND_PUNCH_FAST,
        .animPickUpLightObj =                   MARIO_ANIM_PICK_UP_LIGHT_OBJ,
        .animPushing =                          MARIO_ANIM_PUSHING,
        .animStartRidingShell =                 MARIO_ANIM_START_RIDING_SHELL,
        .animPlaceLightObj =                    MARIO_ANIM_PLACE_LIGHT_OBJ,
        .animForwardSpinning =                  MARIO_ANIM_FORWARD_SPINNING,
        .animBackwardSpinning =                 MARIO_ANIM_BACKWARD_SPINNING,
        .animBreakdance =                       MARIO_ANIM_BREAKDANCE,
        .animRunning =                          WALUIGI_ANIM_RUNNING,
        .animRunningUnused =                    MARIO_ANIM_RUNNING_UNUSED,
        .animSoftBackKb =                       MARIO_ANIM_SOFT_BACK_KB,
        .animSoftFrontKb =                      MARIO_ANIM_SOFT_FRONT_KB,
        .animDyingInQuicksand =                 MARIO_ANIM_DYING_IN_QUICKSAND,
        .animIdleInQuicksand =                  MARIO_ANIM_IDLE_IN_QUICKSAND,
        .animMoveInQuicksand =                  MARIO_ANIM_MOVE_IN_QUICKSAND,
        .animElectrocution =                    MARIO_ANIM_ELECTROCUTION,
        .animShocked =                          MARIO_ANIM_SHOCKED,
        .animBackwardKb =                       MARIO_ANIM_BACKWARD_KB,
        .animForwardKb =                        MARIO_ANIM_FORWARD_KB,
        .animIdleHeavyObj =                     MARIO_ANIM_IDLE_HEAVY_OBJ,
        .animStandAgainstWall =                 MARIO_ANIM_STAND_AGAINST_WALL,
        .animSidestepLeft =                     MARIO_ANIM_SIDESTEP_LEFT,
        .animSidestepRight =                    MARIO_ANIM_SIDESTEP_RIGHT,
        .animStartSleepIdle =                   MARIO_ANIM_START_SLEEP_IDLE,
        .animStartSleepScratch =                MARIO_ANIM_START_SLEEP_SCRATCH,
        .animStartSleepYawn =                   MARIO_ANIM_START_SLEEP_YAWN,
        .animStartSleepSitting =                MARIO_ANIM_START_SLEEP_SITTING,
        .animSleepIdle =                        MARIO_ANIM_SLEEP_IDLE,
        .animSleepStartLying =                  MARIO_ANIM_SLEEP_START_LYING,
        .animSleepLying =                       MARIO_ANIM_SLEEP_LYING,
        .animDive =                             MARIO_ANIM_DIVE,
        .animSlideDive =                        MARIO_ANIM_SLIDE_DIVE,
        .animGroundBonk =                       MARIO_ANIM_GROUND_BONK,
        .animStopSlideLightObj =                MARIO_ANIM_STOP_SLIDE_LIGHT_OBJ,
        .animSlideKick =                        MARIO_ANIM_SLIDE_KICK,
        .animCrouchFromSlideKick =              MARIO_ANIM_CROUCH_FROM_SLIDE_KICK,
        .animSlideMotionless =                  MARIO_ANIM_SLIDE_MOTIONLESS,
        .animStopSlide =                        MARIO_ANIM_STOP_SLIDE,
        .animFallFromSlide =                    MARIO_ANIM_FALL_FROM_SLIDE,
        .animSlide =                            MARIO_ANIM_SLIDE,
        .animTiptoe =                           MARIO_ANIM_TIPTOE,
        .animTwirlLand =                        MARIO_ANIM_TWIRL_LAND,
        .animTwirl =                            MARIO_ANIM_TWIRL,
        .animStartTwirl =                       MARIO_ANIM_START_TWIRL,
        .animStopCrouching =                    MARIO_ANIM_STOP_CROUCHING,
        .animStartCrouching =                   MARIO_ANIM_START_CROUCHING,
        .animCrouching =                        MARIO_ANIM_CROUCHING,
        .animCrawling =                         MARIO_ANIM_CRAWLING,
        .animStopCrawling =                     MARIO_ANIM_STOP_CRAWLING,
        .animStartCrawling =                    MARIO_ANIM_START_CRAWLING,
        .animSummonStar =                       MARIO_ANIM_SUMMON_STAR,
        .animReturnStarApproachDoor =           MARIO_ANIM_RETURN_STAR_APPROACH_DOOR,
        .animBackwardsWaterKb =                 MARIO_ANIM_BACKWARDS_WATER_KB,
        .animSwimWithObjPart1 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART1,
        .animSwimWithObjPart2 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART2,
        .animFlutterkickWithObj =               MARIO_ANIM_FLUTTERKICK_WITH_OBJ,
        .animWaterActionEndWithObj =            MARIO_ANIM_WATER_ACTION_END_WITH_OBJ,
        .animStopGrabObjWater =                 MARIO_ANIM_STOP_GRAB_OBJ_WATER,
        .animWaterIdleWithObj =                 MARIO_ANIM_WATER_IDLE_WITH_OBJ,
        .animDrowningPart1 =                    MARIO_ANIM_DROWNING_PART1,
        .animDrowningPart2 =                    MARIO_ANIM_DROWNING_PART2,
        .animWaterDying =                       MARIO_ANIM_WATER_DYING,
        .animWaterForwardKb =                   MARIO_ANIM_WATER_FORWARD_KB,
        .animFallFromWater =                    MARIO_ANIM_FALL_FROM_WATER,
        .animSwimPart1 =                        MARIO_ANIM_SWIM_PART1,
        .animSwimPart2 =                        MARIO_ANIM_SWIM_PART2,
        .animFlutterkick =                      MARIO_ANIM_FLUTTERKICK,
        .animWaterActionEnd =                   MARIO_ANIM_WATER_ACTION_END,
        .animWaterPickUpObj =                   MARIO_ANIM_WATER_PICK_UP_OBJ,
        .animWaterGrabObjPart2 =                MARIO_ANIM_WATER_GRAB_OBJ_PART2,
        .animWaterGrabObjPart1 =                MARIO_ANIM_WATER_GRAB_OBJ_PART1,
        .animWaterThrowObj =                    MARIO_ANIM_WATER_THROW_OBJ,
        .animWaterIdle =                        MARIO_ANIM_WATER_IDLE,
        .animWaterStarDance =                   MARIO_ANIM_WATER_STAR_DANCE,
        .animReturnFromWaterStarDance =         MARIO_ANIM_RETURN_FROM_WATER_STAR_DANCE,
        .animGrabBowser =                       MARIO_ANIM_GRAB_BOWSER,
        .animSwingingBowser =                   MARIO_ANIM_SWINGING_BOWSER,
        .animReleaseBowser =                    MARIO_ANIM_RELEASE_BOWSER,
        .animHoldingBowser =                    MARIO_ANIM_HOLDING_BOWSER,
        .animHeavyThrow =                       MARIO_ANIM_HEAVY_THROW,
        .animWalkPanting =                      MARIO_ANIM_WALK_PANTING,
        .animWalkWithHeavyObj =                 MARIO_ANIM_WALK_WITH_HEAVY_OBJ,
        .animTurningPart1 =                     MARIO_ANIM_TURNING_PART1,
        .animTurningPart2 =                     MARIO_ANIM_TURNING_PART2,
        .animSlideflipLand =                    MARIO_ANIM_SLIDEFLIP_LAND,
        .animSlideflip =                        MARIO_ANIM_SLIDEFLIP,
        .animTripleJumpLand =                   MARIO_ANIM_TRIPLE_JUMP_LAND,
        .animTripleJump =                       MARIO_ANIM_TRIPLE_JUMP,
        .animFirstPerson =                      MARIO_ANIM_FIRST_PERSON,
        .animIdleHeadLeft =                     MARIO_ANIM_IDLE_HEAD_LEFT,
        .animIdleHeadRight =                    MARIO_ANIM_IDLE_HEAD_RIGHT,
        .animIdleHeadCenter =                   MARIO_ANIM_IDLE_HEAD_CENTER,
        .animHandstandLeft =                    MARIO_ANIM_HANDSTAND_LEFT,
        .animHandstandRight =                   MARIO_ANIM_HANDSTAND_RIGHT,
        .animWakeFromSleep =                    MARIO_ANIM_WAKE_FROM_SLEEP,
        .animWakeFromLying =                    MARIO_ANIM_WAKE_FROM_LYING,
        .animStartTiptoe =                      MARIO_ANIM_START_TIPTOE,
        .animSlidejump =                        MARIO_ANIM_SLIDEJUMP,
        .animStartWallkick =                    MARIO_ANIM_START_WALLKICK,
        .animStarDance =                        MARIO_ANIM_STAR_DANCE,
        .animReturnFromStarDance =              MARIO_ANIM_RETURN_FROM_STAR_DANCE,
        .animForwardSpinningFlip =              MARIO_ANIM_FORWARD_SPINNING_FLIP,
        .animTripleJumpFly =                    MARIO_ANIM_TRIPLE_JUMP_FLY,

        // sounds
        .soundFreqScale        = 0.99f,
        .soundYahWahHoo        = SOUND_LUIGI_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_LUIGI_HOOHOO,
        .soundYahoo            = SOUND_LUIGI_YAHOO,
        .soundUh               = SOUND_LUIGI_UH,
        .soundHrmm             = SOUND_LUIGI_HRMM,
        .soundWah2             = SOUND_LUIGI_WAH2,
        .soundWhoa             = SOUND_LUIGI_WHOA,
        .soundEeuh             = SOUND_LUIGI_EEUH,
        .soundAttacked         = SOUND_LUIGI_ATTACKED,
        .soundOoof             = SOUND_LUIGI_OOOF,
        .soundOoof2            = SOUND_LUIGI_OOOF2,
        .soundHereWeGo         = SOUND_LUIGI_HERE_WE_GO,
        .soundYawning          = SOUND_LUIGI_YAWNING,
        .soundSnoring1         = SOUND_LUIGI_SNORING1,
        .soundSnoring2         = SOUND_LUIGI_SNORING2,
        .soundWaaaooow         = SOUND_LUIGI_WAAAOOOW,
        .soundHaha             = SOUND_LUIGI_HAHA,
        .soundHaha_2           = SOUND_LUIGI_HAHA_2,
        .soundUh2              = SOUND_LUIGI_UH2,
        .soundUh2_2            = SOUND_LUIGI_UH2_2,
        .soundOnFire           = SOUND_LUIGI_ON_FIRE,
        .soundDying            = SOUND_LUIGI_DYING,
        .soundPantingCold      = SOUND_LUIGI_PANTING_COLD,
        .soundPanting          = SOUND_LUIGI_PANTING,
        .soundCoughing1        = SOUND_LUIGI_COUGHING1,
        .soundCoughing2        = SOUND_LUIGI_COUGHING2,
        .soundCoughing3        = SOUND_LUIGI_COUGHING3,
        .soundPunchYah         = SOUND_LUIGI_PUNCH_YAH,
        .soundPunchHoo         = SOUND_LUIGI_PUNCH_HOO,
        .soundMamaMia          = SOUND_LUIGI_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_LUIGI_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_LUIGI_DROWNING,
        .soundPunchWah         = SOUND_LUIGI_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_LUIGI_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_LUIGI_DOH,
        .soundGameOver         = SOUND_LUIGI_GAME_OVER,
        .soundHello            = SOUND_LUIGI_HELLO,
        .soundPressStartToPlay = SOUND_LUIGI_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_LUIGI_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_LUIGI_SNORING3,
        .soundSoLongaBowser    = SOUND_LUIGI_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_LUIGI_IMA_TIRED,
        .soundLetsAGo          = CHAR_BASS_SOUND(SOUND_LUIGI_LETS_A_GO),
        .soundOkeyDokey        = CHAR_BASS_SOUND(SOUND_LUIGI_OKEY_DOKEY),
    },

    [CT_WARIO] = {
        .type                  = CT_WARIO,
        .name                  = "Wario",
        .hudHead               = '[',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_wario_head, .bitSize = 8, .width = 16, .height = 16 },
        .cameraHudHead         = GLYPH_CAM_WARIO_HEAD,
        .modelId               = MODEL_WARIO,
        .capModelId            = MODEL_WARIOS_CAP,
        .capMetalModelId       = MODEL_WARIOS_METAL_CAP,
        .capWingModelId        = MODEL_WARIOS_WING_CAP,
        .capMetalWingModelId   = MODEL_WARIOS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_OPAQUE,
        .capEnemyGfx           = wario_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = NULL,
        .torsoRotMult          = 3.0f / 5.0f,
        // anim
        .animOffsetEnabled     = true,
        
        // character anims
        .animSlowLedgeGrab =                    MARIO_ANIM_SLOW_LEDGE_GRAB,
        .animFallOverBackwards =                MARIO_ANIM_FALL_OVER_BACKWARDS,
        .animBackwardAirKb =                    MARIO_ANIM_BACKWARD_AIR_KB,
        .animDyingOnBack =                      MARIO_ANIM_DYING_ON_BACK,
        .animBackflip =                         MARIO_ANIM_BACKFLIP,
        .animClimbUpPole =                      MARIO_ANIM_CLIMB_UP_POLE,
        .animGrabPoleShort =                    MARIO_ANIM_GRAB_POLE_SHORT,
        .animGrabPoleSwingPart1 =               MARIO_ANIM_GRAB_POLE_SWING_PART1,
        .animGrabPoleSwingPart2 =               MARIO_ANIM_GRAB_POLE_SWING_PART2,
        .animHandstandIdle =                    MARIO_ANIM_HANDSTAND_IDLE,
        .animHandstandJump =                    MARIO_ANIM_HANDSTAND_JUMP,
        .animStartHandstand =                   MARIO_ANIM_START_HANDSTAND,
        .animReturnFromHandstand =              MARIO_ANIM_RETURN_FROM_HANDSTAND,
        .animIdleOnPole =                       MARIO_ANIM_IDLE_ON_POLE,
        .animAPose =                            MARIO_ANIM_A_POSE,
        .animSkidOnGround =                     MARIO_ANIM_SKID_ON_GROUND,
        .animStopSkid =                         MARIO_ANIM_STOP_SKID,
        .animCrouchFromFastLongjump =           MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP,
        .animCrouchFromSlowLongjump =           MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
        .animFastLongjump =                     MARIO_ANIM_FAST_LONGJUMP,
        .animSlowLongjump =                     MARIO_ANIM_SLOW_LONGJUMP,
        .animAirborneOnStomach =                MARIO_ANIM_AIRBORNE_ON_STOMACH,
        .animWalkWithLightObj =                 MARIO_ANIM_WALK_WITH_LIGHT_OBJ,
        .animRunWithLightObj =                  MARIO_ANIM_RUN_WITH_LIGHT_OBJ,
        .animSlowWalkWithLightObj =             MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ,
        .animShiveringWarmingHand =             MARIO_ANIM_SHIVERING_WARMING_HAND,
        .animShiveringReturnToIdle =            MARIO_ANIM_SHIVERING_RETURN_TO_IDLE,
        .animShivering =                        MARIO_ANIM_SHIVERING,
        .animClimbDownLedge =                   MARIO_ANIM_CLIMB_DOWN_LEDGE,
        .animCreditsWaving =                    MARIO_ANIM_CREDITS_WAVING,
        .animCreditsLookUp =                    MARIO_ANIM_CREDITS_LOOK_UP,
        .animCreditsReturnFromLookUp =          MARIO_ANIM_CREDITS_RETURN_FROM_LOOK_UP,
        .animCreditsRaiseHand =                 MARIO_ANIM_CREDITS_RAISE_HAND,
        .animCreditsLowerHand =                 MARIO_ANIM_CREDITS_LOWER_HAND,
        .animCreditsTakeOffCap =                MARIO_ANIM_CREDITS_TAKE_OFF_CAP,
        .animCreditsStartWalkLookUp =           MARIO_ANIM_CREDITS_START_WALK_LOOK_UP,
        .animCreditsLookBackThenRun =           MARIO_ANIM_CREDITS_LOOK_BACK_THEN_RUN,
        .animFinalBowserRaiseHandSpin =         MARIO_ANIM_FINAL_BOWSER_RAISE_HAND_SPIN,
        .animFinalBowserWingCapTakeOff =        MARIO_ANIM_FINAL_BOWSER_WING_CAP_TAKE_OFF,
        .animCreditsPeaceSign =                 MARIO_ANIM_CREDITS_PEACE_SIGN,
        .animStandUpFromLavaBoost =             MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST,
        .animFireLavaBurn =                     MARIO_ANIM_FIRE_LAVA_BURN,
        .animWingCapFly =                       MARIO_ANIM_WING_CAP_FLY,
        .animHangOnOwl =                        MARIO_ANIM_HANG_ON_OWL,
        .animLandOnStomach =                    MARIO_ANIM_LAND_ON_STOMACH,
        .animAirForwardKb =                     MARIO_ANIM_AIR_FORWARD_KB,
        .animDyingOnStomach =                   MARIO_ANIM_DYING_ON_STOMACH,
        .animSuffocating =                      MARIO_ANIM_SUFFOCATING,
        .animCoughing =                         MARIO_ANIM_COUGHING,
        .animThrowCatchKey =                    MARIO_ANIM_THROW_CATCH_KEY,
        .animDyingFallOver =                    MARIO_ANIM_DYING_FALL_OVER,
        .animIdleOnLedge =                      MARIO_ANIM_IDLE_ON_LEDGE,
        .animFastLedgeGrab =                    MARIO_ANIM_FAST_LEDGE_GRAB,
        .animHangOnCeiling =                    MARIO_ANIM_HANG_ON_CEILING,
        .animPutCapOn =                         MARIO_ANIM_PUT_CAP_ON,
        .animTakeCapOffThenOn =                 MARIO_ANIM_TAKE_CAP_OFF_THEN_ON,
        .animQuicklyPutCapOn =                  MARIO_ANIM_QUICKLY_PUT_CAP_ON,
        .animHeadStuckInGround =                MARIO_ANIM_HEAD_STUCK_IN_GROUND,
        .animGroundPoundLanding =               MARIO_ANIM_GROUND_POUND_LANDING,
        .animTripleJumpGroundPound =            MARIO_ANIM_TRIPLE_JUMP_GROUND_POUND,
        .animStartGroundPound =                 MARIO_ANIM_START_GROUND_POUND,
        .animGroundPound =                      MARIO_ANIM_GROUND_POUND,
        .animBottomStuckInGround =              MARIO_ANIM_BOTTOM_STUCK_IN_GROUND,
        .animIdleWithLightObj =                 MARIO_ANIM_IDLE_WITH_LIGHT_OBJ,
        .animJumpLandWithLightObj =             MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ,
        .animJumpWithLightObj =                 MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,
        .animFallLandWithLightObj =             MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ,
        .animFallWithLightObj =                 MARIO_ANIM_FALL_WITH_LIGHT_OBJ,
        .animFallFromSlidingWithLightObj =      MARIO_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animSlidingOnBottomWithLightObj =      MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ,
        .animStandUpFromSlidingWithLightObj =   MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animRidingShell =                      MARIO_ANIM_RIDING_SHELL,
        .animWalking =                          MARIO_ANIM_WALKING,
        .animForwardFlip =                      MARIO_ANIM_FORWARD_FLIP,
        .animJumpRidingShell =                  MARIO_ANIM_JUMP_RIDING_SHELL,
        .animLandFromDoubleJump =               MARIO_ANIM_LAND_FROM_DOUBLE_JUMP,
        .animDoubleJumpFall =                   MARIO_ANIM_DOUBLE_JUMP_FALL,
        .animSingleJump =                       MARIO_ANIM_SINGLE_JUMP,
        .animLandFromSingleJump =               MARIO_ANIM_LAND_FROM_SINGLE_JUMP,
        .animAirKick =                          MARIO_ANIM_AIR_KICK,
        .animDoubleJumpRise =                   MARIO_ANIM_DOUBLE_JUMP_RISE,
        .animStartForwardSpinning =             MARIO_ANIM_START_FORWARD_SPINNING,
        .animThrowLightObject =                 MARIO_ANIM_THROW_LIGHT_OBJECT,
        .animFallFromSlideKick =                MARIO_ANIM_FALL_FROM_SLIDE_KICK,
        .animBendKnessRidingShell =             MARIO_ANIM_BEND_KNESS_RIDING_SHELL,
        .animLegsStuckInGround =                MARIO_ANIM_LEGS_STUCK_IN_GROUND,
        .animGeneralFall =                      MARIO_ANIM_GENERAL_FALL,
        .animGeneralLand =                      MARIO_ANIM_GENERAL_LAND,
        .animBeingGrabbed =                     MARIO_ANIM_BEING_GRABBED,
        .animGrabHeavyObject =                  MARIO_ANIM_GRAB_HEAVY_OBJECT,
        .animSlowLandFromDive =                 MARIO_ANIM_SLOW_LAND_FROM_DIVE,
        .animFlyFromCannon =                    MARIO_ANIM_FLY_FROM_CANNON,
        .animMoveOnWireNetRight =               MARIO_ANIM_MOVE_ON_WIRE_NET_RIGHT,
        .animMoveOnWireNetLeft =                MARIO_ANIM_MOVE_ON_WIRE_NET_LEFT,
        .animMissingCap =                       MARIO_ANIM_MISSING_CAP,
        .animPullDoorWalkIn =                   MARIO_ANIM_PULL_DOOR_WALK_IN,
        .animPushDoorWalkIn =                   MARIO_ANIM_PUSH_DOOR_WALK_IN,
        .animUnlockDoor =                       MARIO_ANIM_UNLOCK_DOOR,
        .animStartReachPocket =                 MARIO_ANIM_START_REACH_POCKET,
        .animReachPocket =                      MARIO_ANIM_REACH_POCKET,
        .animStopReachPocket =                  MARIO_ANIM_STOP_REACH_POCKET,
        .animGroundThrow =                      MARIO_ANIM_GROUND_THROW,
        .animGroundKick =                       MARIO_ANIM_GROUND_KICK,
        .animFirstPunch =                       MARIO_ANIM_FIRST_PUNCH,
        .animSecondPunch =                      MARIO_ANIM_SECOND_PUNCH,
        .animFirstPunchFast =                   MARIO_ANIM_FIRST_PUNCH_FAST,
        .animSecondPunchFast =                  MARIO_ANIM_SECOND_PUNCH_FAST,
        .animPickUpLightObj =                   MARIO_ANIM_PICK_UP_LIGHT_OBJ,
        .animPushing =                          MARIO_ANIM_PUSHING,
        .animStartRidingShell =                 MARIO_ANIM_START_RIDING_SHELL,
        .animPlaceLightObj =                    MARIO_ANIM_PLACE_LIGHT_OBJ,
        .animForwardSpinning =                  MARIO_ANIM_FORWARD_SPINNING,
        .animBackwardSpinning =                 MARIO_ANIM_BACKWARD_SPINNING,
        .animBreakdance =                       MARIO_ANIM_BREAKDANCE,
        .animRunning =                          MARIO_ANIM_RUNNING,
        .animRunningUnused =                    MARIO_ANIM_RUNNING_UNUSED,
        .animSoftBackKb =                       MARIO_ANIM_SOFT_BACK_KB,
        .animSoftFrontKb =                      MARIO_ANIM_SOFT_FRONT_KB,
        .animDyingInQuicksand =                 MARIO_ANIM_DYING_IN_QUICKSAND,
        .animIdleInQuicksand =                  MARIO_ANIM_IDLE_IN_QUICKSAND,
        .animMoveInQuicksand =                  MARIO_ANIM_MOVE_IN_QUICKSAND,
        .animElectrocution =                    MARIO_ANIM_ELECTROCUTION,
        .animShocked =                          MARIO_ANIM_SHOCKED,
        .animBackwardKb =                       MARIO_ANIM_BACKWARD_KB,
        .animForwardKb =                        MARIO_ANIM_FORWARD_KB,
        .animIdleHeavyObj =                     MARIO_ANIM_IDLE_HEAVY_OBJ,
        .animStandAgainstWall =                 MARIO_ANIM_STAND_AGAINST_WALL,
        .animSidestepLeft =                     MARIO_ANIM_SIDESTEP_LEFT,
        .animSidestepRight =                    MARIO_ANIM_SIDESTEP_RIGHT,
        .animStartSleepIdle =                   MARIO_ANIM_START_SLEEP_IDLE,
        .animStartSleepScratch =                MARIO_ANIM_START_SLEEP_SCRATCH,
        .animStartSleepYawn =                   MARIO_ANIM_START_SLEEP_YAWN,
        .animStartSleepSitting =                MARIO_ANIM_START_SLEEP_SITTING,
        .animSleepIdle =                        MARIO_ANIM_SLEEP_IDLE,
        .animSleepStartLying =                  MARIO_ANIM_SLEEP_START_LYING,
        .animSleepLying =                       MARIO_ANIM_SLEEP_LYING,
        .animDive =                             MARIO_ANIM_DIVE,
        .animSlideDive =                        MARIO_ANIM_SLIDE_DIVE,
        .animGroundBonk =                       MARIO_ANIM_GROUND_BONK,
        .animStopSlideLightObj =                MARIO_ANIM_STOP_SLIDE_LIGHT_OBJ,
        .animSlideKick =                        MARIO_ANIM_SLIDE_KICK,
        .animCrouchFromSlideKick =              MARIO_ANIM_CROUCH_FROM_SLIDE_KICK,
        .animSlideMotionless =                  MARIO_ANIM_SLIDE_MOTIONLESS,
        .animStopSlide =                        MARIO_ANIM_STOP_SLIDE,
        .animFallFromSlide =                    MARIO_ANIM_FALL_FROM_SLIDE,
        .animSlide =                            MARIO_ANIM_SLIDE,
        .animTiptoe =                           MARIO_ANIM_TIPTOE,
        .animTwirlLand =                        MARIO_ANIM_TWIRL_LAND,
        .animTwirl =                            MARIO_ANIM_TWIRL,
        .animStartTwirl =                       MARIO_ANIM_START_TWIRL,
        .animStopCrouching =                    MARIO_ANIM_STOP_CROUCHING,
        .animStartCrouching =                   MARIO_ANIM_START_CROUCHING,
        .animCrouching =                        MARIO_ANIM_CROUCHING,
        .animCrawling =                         MARIO_ANIM_CRAWLING,
        .animStopCrawling =                     MARIO_ANIM_STOP_CRAWLING,
        .animStartCrawling =                    MARIO_ANIM_START_CRAWLING,
        .animSummonStar =                       MARIO_ANIM_SUMMON_STAR,
        .animReturnStarApproachDoor =           MARIO_ANIM_RETURN_STAR_APPROACH_DOOR,
        .animBackwardsWaterKb =                 MARIO_ANIM_BACKWARDS_WATER_KB,
        .animSwimWithObjPart1 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART1,
        .animSwimWithObjPart2 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART2,
        .animFlutterkickWithObj =               MARIO_ANIM_FLUTTERKICK_WITH_OBJ,
        .animWaterActionEndWithObj =            MARIO_ANIM_WATER_ACTION_END_WITH_OBJ,
        .animStopGrabObjWater =                 MARIO_ANIM_STOP_GRAB_OBJ_WATER,
        .animWaterIdleWithObj =                 MARIO_ANIM_WATER_IDLE_WITH_OBJ,
        .animDrowningPart1 =                    MARIO_ANIM_DROWNING_PART1,
        .animDrowningPart2 =                    MARIO_ANIM_DROWNING_PART2,
        .animWaterDying =                       MARIO_ANIM_WATER_DYING,
        .animWaterForwardKb =                   MARIO_ANIM_WATER_FORWARD_KB,
        .animFallFromWater =                    MARIO_ANIM_FALL_FROM_WATER,
        .animSwimPart1 =                        MARIO_ANIM_SWIM_PART1,
        .animSwimPart2 =                        MARIO_ANIM_SWIM_PART2,
        .animFlutterkick =                      MARIO_ANIM_FLUTTERKICK,
        .animWaterActionEnd =                   MARIO_ANIM_WATER_ACTION_END,
        .animWaterPickUpObj =                   MARIO_ANIM_WATER_PICK_UP_OBJ,
        .animWaterGrabObjPart2 =                MARIO_ANIM_WATER_GRAB_OBJ_PART2,
        .animWaterGrabObjPart1 =                MARIO_ANIM_WATER_GRAB_OBJ_PART1,
        .animWaterThrowObj =                    MARIO_ANIM_WATER_THROW_OBJ,
        .animWaterIdle =                        MARIO_ANIM_WATER_IDLE,
        .animWaterStarDance =                   MARIO_ANIM_WATER_STAR_DANCE,
        .animReturnFromWaterStarDance =         MARIO_ANIM_RETURN_FROM_WATER_STAR_DANCE,
        .animGrabBowser =                       MARIO_ANIM_GRAB_BOWSER,
        .animSwingingBowser =                   MARIO_ANIM_SWINGING_BOWSER,
        .animReleaseBowser =                    MARIO_ANIM_RELEASE_BOWSER,
        .animHoldingBowser =                    MARIO_ANIM_HOLDING_BOWSER,
        .animHeavyThrow =                       MARIO_ANIM_HEAVY_THROW,
        .animWalkPanting =                      MARIO_ANIM_WALK_PANTING,
        .animWalkWithHeavyObj =                 MARIO_ANIM_WALK_WITH_HEAVY_OBJ,
        .animTurningPart1 =                     MARIO_ANIM_TURNING_PART1,
        .animTurningPart2 =                     MARIO_ANIM_TURNING_PART2,
        .animSlideflipLand =                    MARIO_ANIM_SLIDEFLIP_LAND,
        .animSlideflip =                        MARIO_ANIM_SLIDEFLIP,
        .animTripleJumpLand =                   MARIO_ANIM_TRIPLE_JUMP_LAND,
        .animTripleJump =                       MARIO_ANIM_TRIPLE_JUMP,
        .animFirstPerson =                      MARIO_ANIM_FIRST_PERSON,
        .animIdleHeadLeft =                     MARIO_ANIM_IDLE_HEAD_LEFT,
        .animIdleHeadRight =                    MARIO_ANIM_IDLE_HEAD_RIGHT,
        .animIdleHeadCenter =                   MARIO_ANIM_IDLE_HEAD_CENTER,
        .animHandstandLeft =                    MARIO_ANIM_HANDSTAND_LEFT,
        .animHandstandRight =                   MARIO_ANIM_HANDSTAND_RIGHT,
        .animWakeFromSleep =                    MARIO_ANIM_WAKE_FROM_SLEEP,
        .animWakeFromLying =                    MARIO_ANIM_WAKE_FROM_LYING,
        .animStartTiptoe =                      MARIO_ANIM_START_TIPTOE,
        .animSlidejump =                        MARIO_ANIM_SLIDEJUMP,
        .animStartWallkick =                    MARIO_ANIM_START_WALLKICK,
        .animStarDance =                        MARIO_ANIM_STAR_DANCE,
        .animReturnFromStarDance =              MARIO_ANIM_RETURN_FROM_STAR_DANCE,
        .animForwardSpinningFlip =              MARIO_ANIM_FORWARD_SPINNING_FLIP,
        .animTripleJumpFly =                    MARIO_ANIM_TRIPLE_JUMP_FLY,

        // sounds
        .soundFreqScale        = 1.0f,
        .soundYahWahHoo        = SOUND_WARIO_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_WARIO_HOOHOO,
        .soundYahoo            = SOUND_WARIO_YAHOO,
        .soundUh               = SOUND_WARIO_UH,
        .soundHrmm             = SOUND_WARIO_HRMM,
        .soundWah2             = SOUND_WARIO_WAH2,
        .soundWhoa             = SOUND_WARIO_WHOA,
        .soundEeuh             = SOUND_WARIO_EEUH,
        .soundAttacked         = SOUND_WARIO_ATTACKED,
        .soundOoof             = SOUND_WARIO_OOOF,
        .soundOoof2            = SOUND_WARIO_OOOF2,
        .soundHereWeGo         = SOUND_WARIO_HERE_WE_GO,
        .soundYawning          = SOUND_WARIO_YAWNING,
        .soundSnoring1         = SOUND_WARIO_SNORING1,
        .soundSnoring2         = SOUND_WARIO_SNORING2,
        .soundWaaaooow         = SOUND_WARIO_WAAAOOOW,
        .soundHaha             = SOUND_WARIO_HAHA,
        .soundHaha_2           = SOUND_WARIO_HAHA_2,
        .soundUh2              = SOUND_WARIO_UH2,
        .soundUh2_2            = SOUND_WARIO_UH2_2,
        .soundOnFire           = SOUND_WARIO_ON_FIRE,
        .soundDying            = SOUND_WARIO_DYING,
        .soundPantingCold      = SOUND_WARIO_PANTING_COLD,
        .soundPanting          = SOUND_WARIO_PANTING,
        .soundCoughing1        = SOUND_WARIO_COUGHING1,
        .soundCoughing2        = SOUND_WARIO_COUGHING2,
        .soundCoughing3        = SOUND_WARIO_COUGHING3,
        .soundPunchYah         = SOUND_WARIO_PUNCH_YAH,
        .soundPunchHoo         = SOUND_WARIO_PUNCH_HOO,
        .soundMamaMia          = SOUND_WARIO_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_WARIO_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_WARIO_DROWNING,
        .soundPunchWah         = SOUND_WARIO_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_WARIO_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_WARIO_DOH,
        .soundGameOver         = SOUND_WARIO_GAME_OVER,
        .soundHello            = SOUND_WARIO_HELLO,
        .soundPressStartToPlay = SOUND_WARIO_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_WARIO_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_WARIO_SNORING3,
        .soundSoLongaBowser    = SOUND_WARIO_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_WARIO_IMA_TIRED,
        .soundLetsAGo          = CHAR_BASS_SOUND(SOUND_WARIO_LETS_A_GO),
        .soundOkeyDokey        = CHAR_BASS_SOUND(SOUND_WARIO_OKEY_DOKEY),
    },
};

const struct PlayerPalette DEFAULT_MARIO_PALETTE =
{{{ 0x00, 0x00, 0xff }, { 0xff, 0x00, 0x00 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xff, 0x00, 0x00 }}};

const struct PlayerPalette gPalettePresets[PALETTE_PRESET_MAX] = {
/*  ---- PANTS -----      ---- SHIRT -----      ---- GLOVES ----      ---- SHOES -----      ----- HAIR -----      ----- SKIN -----      ----- CAP ------  */
{{{ 0x00, 0x00, 0xff }, { 0xff, 0x00, 0x00 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xff, 0x00, 0x00 }}}, // Mario
{{{ 0x00, 0x00, 0xff }, { 0x00, 0x98, 0x00 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x00, 0x98, 0x00 }}}, // Luigi
{{{ 0x16, 0x16, 0x27 }, { 0x61, 0x26, 0xb0 }, { 0xff, 0xff, 0xff }, { 0xfe, 0x76, 0x00 }, { 0x73, 0x53, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x61, 0x26, 0xb0 }}}, // Waluigi
{{{ 0x7f, 0x20, 0x7a }, { 0xe3, 0xa9, 0x01 }, { 0xff, 0xff, 0xff }, { 0x0e, 0x72, 0x1c }, { 0x73, 0x53, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xe3, 0xa9, 0x01 }}}, // Wario
{{{ 0xff, 0x00, 0x00 }, { 0x7b, 0x00, 0xde }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x7b, 0x00, 0xde }}}, // Chuckya
{{{ 0xc6, 0xb1, 0x32 }, { 0x95, 0x43, 0x01 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x95, 0x43, 0x01 }}}, // Goomba
{{{ 0x07, 0x09, 0x07 }, { 0x4c, 0x5f, 0x20 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x4c, 0x5f, 0x20 }}}, // Clover
{{{ 0xbf, 0xde, 0xff }, { 0x00, 0x2f, 0xc8 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x00, 0x2f, 0xc8 }}}, // Cobalt
{{{ 0xf8, 0x3b, 0x05 }, { 0x11, 0x11, 0x11 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x11, 0x11, 0x11 }}}, // Fury
{{{ 0x34, 0x16, 0x0d }, { 0xc1, 0x2c, 0x72 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xc1, 0x2c, 0x72 }}}, // Hot Pink
{{{ 0xff, 0x00, 0x00 }, { 0xff, 0x96, 0xc8 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xff, 0x96, 0xc8 }}}, // Nice Pink
{{{ 0x81, 0x00, 0x00 }, { 0x4c, 0xff, 0x4c }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x4c, 0xff, 0x4c }}}, // Seafoam
{{{ 0x61, 0x3d, 0x2e }, { 0xa9, 0x78, 0xfc }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xa9, 0x78, 0xfc }}}, // Lilac
{{{ 0x00, 0x46, 0x5c }, { 0x84, 0x60, 0x00 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x84, 0x60, 0x00 }}}, // Copper
{{{ 0x4f, 0x31, 0x8b }, { 0x5a, 0x94, 0xff }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x5a, 0x94, 0xff }}}, // Azure
{{{ 0x23, 0x11, 0x03 }, { 0x68, 0x0a, 0x17 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x68, 0x0a, 0x17 }}}, // Burgundy
{{{ 0x53, 0x39, 0x3d }, { 0x95, 0xd0, 0x8f }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x95, 0xd0, 0x8f }}}, // Mint
{{{ 0xe6, 0xe3, 0xff }, { 0x37, 0x32, 0x42 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x37, 0x32, 0x42 }}}, // Eggplant
{{{ 0x00, 0x51, 0x10 }, { 0xff, 0x8a, 0x00 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xff, 0x8a, 0x00 }}}, // Orange
{{{ 0x4c, 0x1e, 0x3f }, { 0x65, 0xfa, 0xff }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x65, 0xfa, 0xff }}}, // Arctic
{{{ 0xbf, 0x00, 0x00 }, { 0xef, 0xef, 0x9f }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xef, 0xef, 0x9f }}}, // Fire Mario
{{{ 0x00, 0x98, 0x00 }, { 0xef, 0xef, 0x9f }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xef, 0xef, 0x9f }}}, // Fire Luigi
{{{ 0x61, 0x26, 0xb0 }, { 0xef, 0xef, 0x9f }, { 0xff, 0xff, 0xff }, { 0xfe, 0x76, 0x00 }, { 0x73, 0x53, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xef, 0xef, 0x9f }}}, // Fire Waluigi
{{{ 0xe3, 0xa9, 0x01 }, { 0xef, 0xef, 0x9f }, { 0xff, 0xff, 0xff }, { 0x0e, 0x72, 0x1c }, { 0x73, 0x53, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xef, 0xef, 0x9f }}}, // Fire Wario
{{{ 0x17, 0x18, 0x15 }, { 0xe7, 0xe7, 0x21 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xe7, 0xe7, 0x21 }}}, // Busy Bee
{{{ 0xf7, 0x9a, 0x47 }, { 0xaa, 0x27, 0x31 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xaa, 0x27, 0x31 }}}, // Fortress
{{{ 0xf7, 0xc2, 0x45 }, { 0x55, 0x92, 0xb2 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x55, 0x92, 0xb2 }}}, // Battlements
{{{ 0xeb, 0x8a, 0x4b }, { 0x10, 0x1b, 0x2e }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x10, 0x1b, 0x2e }}}, // Blueberry Pie
{{{ 0xd6, 0x35, 0x4d }, { 0x3b, 0x8f, 0xf7 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x3b, 0x8f, 0xf7 }}}, // Raspberry
{{{ 0xd6, 0x35, 0x4d }, { 0xff, 0x8e, 0xb2 }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0xff, 0x8e, 0xb2 }}}, // Bubblegum
{{{ 0xb2, 0x28, 0x18 }, { 0x47, 0xc5, 0xff }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x47, 0xc5, 0xff }}}, // Ice Mario
{{{ 0x00, 0x98, 0x00 }, { 0x47, 0xc5, 0xff }, { 0xff, 0xff, 0xff }, { 0x72, 0x1c, 0x0e }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xc1, 0x79 }, { 0x47, 0xc5, 0xff }}}, // Ice Luigi
{{{ 0x4c, 0x2c, 0xd3 }, { 0xff, 0xff, 0xff }, { 0xff, 0xff, 0xff }, { 0x68, 0x40, 0x1b }, { 0x73, 0x06, 0x00 }, { 0xfe, 0xd5, 0xa1 }, { 0xff, 0x00, 0x00 }}}, // Toad
};

enum AnimType {
    ANIM_TYPE_NONE,
    ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET,
    ANIM_TYPE_HAND,
};

#define ANIM_TYPE_MAX 211
u8 sAnimTypes[ANIM_TYPE_MAX] = {
    ANIM_TYPE_HAND, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_FEET,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_HAND, ANIM_TYPE_LOWY,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_HAND, ANIM_TYPE_FEET, ANIM_TYPE_HAND, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_HAND, ANIM_TYPE_HAND, ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_FEET,
    ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_HAND, ANIM_TYPE_HAND,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_FEET,
    ANIM_TYPE_FEET,
};

struct Character* get_character(struct MarioState* m) {
    return (m == NULL || m->character == NULL)
        ? &gCharacters[CT_MARIO]
        : m->character;
}

static s32 get_character_sound(struct MarioState* m, enum CharacterSound characterSound) {
    if (m == NULL || m->marioObj == NULL) { return 0; }
	
    s32 override = 0;
    if (smlua_call_event_hooks_mario_character_sound_param_ret_int(HOOK_CHARACTER_SOUND, m, characterSound, &override)) {
        return override;
    }
	
    struct Character* character = ((m == NULL || m->character == NULL) ? &gCharacters[CT_MARIO] : m->character);
    switch (characterSound) {
        case CHAR_SOUND_YAH_WAH_HOO:         return character->soundYahWahHoo;
        case CHAR_SOUND_HOOHOO:              return character->soundHoohoo;
        case CHAR_SOUND_YAHOO:               return character->soundYahoo;
        case CHAR_SOUND_UH:                  return character->soundUh;
        case CHAR_SOUND_HRMM:                return character->soundHrmm;
        case CHAR_SOUND_WAH2:                return character->soundWah2;
        case CHAR_SOUND_WHOA:                return character->soundWhoa;
        case CHAR_SOUND_EEUH:                return character->soundEeuh;
        case CHAR_SOUND_ATTACKED:            return character->soundAttacked;
        case CHAR_SOUND_OOOF:                return character->soundOoof;
        case CHAR_SOUND_OOOF2:               return character->soundOoof2;
        case CHAR_SOUND_HERE_WE_GO:          return character->soundHereWeGo;
        case CHAR_SOUND_YAWNING:             return character->soundYawning;
        case CHAR_SOUND_SNORING1:            return character->soundSnoring1;
        case CHAR_SOUND_SNORING2:            return character->soundSnoring2;
        case CHAR_SOUND_WAAAOOOW:            return character->soundWaaaooow;
        case CHAR_SOUND_HAHA:                return character->soundHaha;
        case CHAR_SOUND_HAHA_2:              return character->soundHaha_2;
        case CHAR_SOUND_UH2:                 return character->soundUh2;
        case CHAR_SOUND_UH2_2:               return character->soundUh2_2;
        case CHAR_SOUND_ON_FIRE:             return character->soundOnFire;
        case CHAR_SOUND_DYING:               return character->soundDying;
        case CHAR_SOUND_PANTING_COLD:        return character->soundPantingCold;
        case CHAR_SOUND_PANTING:             return character->soundPanting;
        case CHAR_SOUND_COUGHING1:           return character->soundCoughing1;
        case CHAR_SOUND_COUGHING2:           return character->soundCoughing2;
        case CHAR_SOUND_COUGHING3:           return character->soundCoughing3;
        case CHAR_SOUND_PUNCH_YAH:           return character->soundPunchYah;
        case CHAR_SOUND_PUNCH_HOO:           return character->soundPunchHoo;
        case CHAR_SOUND_MAMA_MIA:            return character->soundMamaMia;
        case CHAR_SOUND_GROUND_POUND_WAH:    return character->soundGroundPoundWah;
        case CHAR_SOUND_DROWNING:            return character->soundDrowning;
        case CHAR_SOUND_PUNCH_WAH:           return character->soundPunchWah;
        case CHAR_SOUND_YAHOO_WAHA_YIPPEE:   return character->soundYahooWahaYippee;
        case CHAR_SOUND_DOH:                 return character->soundDoh;
        case CHAR_SOUND_GAME_OVER:           return character->soundGameOver;
        case CHAR_SOUND_HELLO:               return character->soundHello;
        case CHAR_SOUND_PRESS_START_TO_PLAY: return character->soundPressStartToPlay;
        case CHAR_SOUND_TWIRL_BOUNCE:        return character->soundTwirlBounce;
        case CHAR_SOUND_SNORING3:            return character->soundSnoring3;
        case CHAR_SOUND_SO_LONGA_BOWSER:     return character->soundSoLongaBowser;
        case CHAR_SOUND_IMA_TIRED:           return character->soundImaTired;
        case CHAR_SOUND_LETS_A_GO:           return character->soundLetsAGo;
        case CHAR_SOUND_OKEY_DOKEY:          return character->soundOkeyDokey;
        default:                             return 0;
    }
}

static void play_character_sound_internal(struct MarioState *m, enum CharacterSound characterSound, u32 offset, u32 flags) {
    if (m != NULL && (m->flags & flags) == 0) {
        s32 sound = get_character_sound(m, characterSound);
        if (sound != 0) {
            struct Character* character = get_character(m);
            f32 *pos = (m->marioObj != NULL ? m->marioObj->header.gfx.cameraToObject : gGlobalSoundSource);
            if ((u32) (sound & CHAR_BASS_MAGIC) == CHAR_BASS_MAGIC) {
                CharacterBassSound *cbs = get_character_bass_sound(sound);
                if (cbs != NULL) {
                    play_character_bass_sound(cbs, pos, character->soundFreqScale);
                }
            } else {
                play_sound_with_freq_scale(sound + offset, pos, character->soundFreqScale);
            }
        }
        m->flags |= flags;
    }
}

void play_character_sound(struct MarioState* m, enum CharacterSound characterSound) {
    play_character_sound_internal(m, characterSound, 0, 0);
}

void play_character_sound_offset(struct MarioState* m, enum CharacterSound characterSound, u32 offset) {
    play_character_sound_internal(m, characterSound, offset, 0);
}

void play_character_sound_if_no_flag(struct MarioState* m, enum CharacterSound characterSound, u32 flags) {
    play_character_sound_internal(m, characterSound, 0, flags);
}

f32 get_character_anim_offset(struct MarioState* m) {
    if (m == NULL || m->marioObj == NULL) { return 0; }
    struct Object* marioObj = m->marioObj;
    struct Character* c = get_character(m);
    if (!c->animOffsetEnabled) { return 0; }
    s32 animID = marioObj->header.gfx.animInfo.animID;
    if (animID < 0 || animID >= ANIM_TYPE_MAX) { return 0; }

    switch (sAnimTypes[animID]) {
        case ANIM_TYPE_LOWY:
            if (m->minimumBoneY < c->animOffsetLowYPoint) {
                return c->animOffsetLowYPoint - m->minimumBoneY;
            }
            break;
        case ANIM_TYPE_FEET:
            return c->animOffsetFeet;
            break;
        case ANIM_TYPE_HAND:
            return c->animOffsetHand;
            break;
    }
    return 0;
}

void update_character_anim_offset(struct MarioState* m) {
    if (m == NULL || m->marioObj == NULL) { return; }
    struct Object* marioObj = m->marioObj;
    struct Character* c = get_character(m);
    if (!c->animOffsetEnabled) { return; }

    f32 targetOffset = get_character_anim_offset(m);

    // smooth
    f32 alpha = (fabs(targetOffset - m->curAnimOffset) / 80.0f) + 0.5f;
    alpha = (alpha + 0.5f) / 2.0f;
    alpha *= alpha;
    m->curAnimOffset = (m->curAnimOffset * alpha) + (targetOffset * (1.0f - alpha));
    if (m->curAnimOffset > 40)  { m->curAnimOffset = 40; }
    if (m->curAnimOffset < -40) { m->curAnimOffset = -40; }

    marioObj->header.gfx.pos[1] = m->pos[1] + m->curAnimOffset;
    marioObj->header.gfx.node.flags |= GRAPH_RENDER_PLAYER;
}

s32 get_character_anim(struct MarioState* m, enum CharacterAnimID characterAnim) {
    if (m == NULL || m->marioObj == NULL) { return 0; }
	
    struct Character* character = ((m == NULL || m->character == NULL) ? &gCharacters[CT_MARIO] : m->character);
    switch (characterAnim) {
        case CHAR_ANIM_SLOW_LEDGE_GRAB:                     return character->animSlowLedgeGrab;
        case CHAR_ANIM_FALL_OVER_BACKWARDS:                 return character->animFallOverBackwards;
        case CHAR_ANIM_BACKWARD_AIR_KB:                     return character->animBackwardAirKb;
        case CHAR_ANIM_DYING_ON_BACK:                       return character->animDyingOnBack;
        case CHAR_ANIM_BACKFLIP:                            return character->animBackflip;
        case CHAR_ANIM_CLIMB_UP_POLE:                       return character->animClimbUpPole;
        case CHAR_ANIM_GRAB_POLE_SHORT:                     return character->animGrabPoleShort;
        case CHAR_ANIM_GRAB_POLE_SWING_PART1:               return character->animGrabPoleSwingPart1;
        case CHAR_ANIM_GRAB_POLE_SWING_PART2:               return character->animGrabPoleSwingPart2;
        case CHAR_ANIM_HANDSTAND_IDLE:                      return character->animHandstandIdle;
        case CHAR_ANIM_HANDSTAND_JUMP:                      return character->animHandstandJump;
        case CHAR_ANIM_START_HANDSTAND:                     return character->animStartHandstand;
        case CHAR_ANIM_RETURN_FROM_HANDSTAND:               return character->animReturnFromHandstand;
        case CHAR_ANIM_IDLE_ON_POLE:                        return character->animIdleOnPole;
        case CHAR_ANIM_A_POSE:                              return character->animAPose;
        case CHAR_ANIM_SKID_ON_GROUND:                      return character->animSkidOnGround;
        case CHAR_ANIM_STOP_SKID:                           return character->animStopSkid;
        case CHAR_ANIM_CROUCH_FROM_FAST_LONGJUMP:           return character->animCrouchFromFastLongjump;
        case CHAR_ANIM_CROUCH_FROM_SLOW_LONGJUMP:           return character->animCrouchFromSlowLongjump;
        case CHAR_ANIM_FAST_LONGJUMP:                       return character->animFastLongjump;
        case CHAR_ANIM_SLOW_LONGJUMP:                       return character->animSlowLongjump;
        case CHAR_ANIM_AIRBORNE_ON_STOMACH:                 return character->animAirborneOnStomach;
        case CHAR_ANIM_WALK_WITH_LIGHT_OBJ:                 return character->animWalkWithLightObj;
        case CHAR_ANIM_RUN_WITH_LIGHT_OBJ:                  return character->animRunWithLightObj;
        case CHAR_ANIM_SLOW_WALK_WITH_LIGHT_OBJ:            return character->animSlowWalkWithLightObj;
        case CHAR_ANIM_SHIVERING_WARMING_HAND:              return character->animShiveringWarmingHand;
        case CHAR_ANIM_SHIVERING_RETURN_TO_IDLE:            return character->animShiveringReturnToIdle;
        case CHAR_ANIM_SHIVERING:                           return character->animShivering;
        case CHAR_ANIM_CLIMB_DOWN_LEDGE:                    return character->animClimbDownLedge;
        case CHAR_ANIM_CREDITS_WAVING:                      return character->animCreditsWaving;
        case CHAR_ANIM_CREDITS_LOOK_UP:                     return character->animCreditsLookUp;
        case CHAR_ANIM_CREDITS_RETURN_FROM_LOOK_UP:         return character->animCreditsReturnFromLookUp;
        case CHAR_ANIM_CREDITS_RAISE_HAND:                  return character->animCreditsRaiseHand;
        case CHAR_ANIM_CREDITS_LOWER_HAND:                  return character->animCreditsLowerHand;
        case CHAR_ANIM_CREDITS_TAKE_OFF_CAP:                return character->animCreditsTakeOffCap;
        case CHAR_ANIM_CREDITS_START_WALK_LOOK_UP:          return character->animCreditsStartWalkLookUp;
        case CHAR_ANIM_CREDITS_LOOK_BACK_THEN_RUN:          return character->animCreditsLookBackThenRun;
        case CHAR_ANIM_FINAL_BOWSER_RAISE_HAND_SPIN:        return character->animFinalBowserRaiseHandSpin;
        case CHAR_ANIM_FINAL_BOWSER_WING_CAP_TAKE_OFF:      return character->animFinalBowserWingCapTakeOff;
        case CHAR_ANIM_CREDITS_PEACE_SIGN:                  return character->animCreditsPeaceSign;
        case CHAR_ANIM_STAND_UP_FROM_LAVA_BOOST:            return character->animStandUpFromLavaBoost;
        case CHAR_ANIM_FIRE_LAVA_BURN:                      return character->animFireLavaBurn;
        case CHAR_ANIM_WING_CAP_FLY:                        return character->animWingCapFly;
        case CHAR_ANIM_HANG_ON_OWL:                         return character->animHangOnOwl;
        case CHAR_ANIM_LAND_ON_STOMACH:                     return character->animLandOnStomach;
        case CHAR_ANIM_AIR_FORWARD_KB:                      return character->animAirForwardKb;
        case CHAR_ANIM_DYING_ON_STOMACH:                    return character->animDyingOnStomach;
        case CHAR_ANIM_SUFFOCATING:                         return character->animSuffocating;
        case CHAR_ANIM_COUGHING:                            return character->animCoughing;
        case CHAR_ANIM_THROW_CATCH_KEY:                     return character->animThrowCatchKey;
        case CHAR_ANIM_DYING_FALL_OVER:                     return character->animDyingFallOver;
        case CHAR_ANIM_IDLE_ON_LEDGE:                       return character->animIdleOnLedge;
        case CHAR_ANIM_FAST_LEDGE_GRAB:                     return character->animFastLedgeGrab;
        case CHAR_ANIM_HANG_ON_CEILING:                     return character->animHangOnCeiling;
        case CHAR_ANIM_PUT_CAP_ON:                          return character->animPutCapOn;
        case CHAR_ANIM_TAKE_CAP_OFF_THEN_ON:                return character->animTakeCapOffThenOn;
        case CHAR_ANIM_QUICKLY_PUT_CAP_ON:                  return character->animQuicklyPutCapOn;
        case CHAR_ANIM_HEAD_STUCK_IN_GROUND:                return character->animHeadStuckInGround;
        case CHAR_ANIM_GROUND_POUND_LANDING:                return character->animGroundPoundLanding;
        case CHAR_ANIM_TRIPLE_JUMP_GROUND_POUND:            return character->animTripleJumpGroundPound;
        case CHAR_ANIM_START_GROUND_POUND:                  return character->animStartGroundPound;
        case CHAR_ANIM_GROUND_POUND:                        return character->animGroundPound;
        case CHAR_ANIM_BOTTOM_STUCK_IN_GROUND:              return character->animBottomStuckInGround;
        case CHAR_ANIM_IDLE_WITH_LIGHT_OBJ:                 return character->animIdleWithLightObj;
        case CHAR_ANIM_JUMP_LAND_WITH_LIGHT_OBJ:            return character->animJumpLandWithLightObj;
        case CHAR_ANIM_JUMP_WITH_LIGHT_OBJ:                 return character->animJumpWithLightObj;
        case CHAR_ANIM_FALL_LAND_WITH_LIGHT_OBJ:            return character->animFallLandWithLightObj;
        case CHAR_ANIM_FALL_WITH_LIGHT_OBJ:                 return character->animFallWithLightObj;
        case CHAR_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ:    return character->animFallFromSlidingWithLightObj;
        case CHAR_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ:    return character->animSlidingOnBottomWithLightObj;
        case CHAR_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ:return character->animStandUpFromSlidingWithLightObj;
        case CHAR_ANIM_RIDING_SHELL:                        return character->animRidingShell;
        case CHAR_ANIM_WALKING:                             return character->animWalking;
        case CHAR_ANIM_FORWARD_FLIP:                        return character->animForwardFlip;
        case CHAR_ANIM_JUMP_RIDING_SHELL:                   return character->animJumpRidingShell;
        case CHAR_ANIM_LAND_FROM_DOUBLE_JUMP:               return character->animLandFromDoubleJump;
        case CHAR_ANIM_DOUBLE_JUMP_FALL:                    return character->animDoubleJumpFall;
        case CHAR_ANIM_SINGLE_JUMP:                         return character->animSingleJump;
        case CHAR_ANIM_LAND_FROM_SINGLE_JUMP:               return character->animLandFromSingleJump;
        case CHAR_ANIM_AIR_KICK:                            return character->animAirKick;
        case CHAR_ANIM_DOUBLE_JUMP_RISE:                    return character->animDoubleJumpRise;
        case CHAR_ANIM_START_FORWARD_SPINNING:              return character->animStartForwardSpinning;
        case CHAR_ANIM_THROW_LIGHT_OBJECT:                  return character->animThrowLightObject;
        case CHAR_ANIM_FALL_FROM_SLIDE_KICK:                return character->animFallFromSlideKick;
        case CHAR_ANIM_BEND_KNESS_RIDING_SHELL:             return character->animBendKnessRidingShell;
        case CHAR_ANIM_LEGS_STUCK_IN_GROUND:                return character->animLegsStuckInGround;
        case CHAR_ANIM_GENERAL_FALL:                        return character->animGeneralFall;
        case CHAR_ANIM_GENERAL_LAND:                        return character->animGeneralLand;
        case CHAR_ANIM_BEING_GRABBED:                       return character->animBeingGrabbed;
        case CHAR_ANIM_GRAB_HEAVY_OBJECT:                   return character->animGrabHeavyObject;
        case CHAR_ANIM_SLOW_LAND_FROM_DIVE:                 return character->animSlowLandFromDive;
        case CHAR_ANIM_FLY_FROM_CANNON:                     return character->animFlyFromCannon;
        case CHAR_ANIM_MOVE_ON_WIRE_NET_RIGHT:              return character->animMoveOnWireNetRight;
        case CHAR_ANIM_MOVE_ON_WIRE_NET_LEFT:               return character->animMoveOnWireNetLeft;
        case CHAR_ANIM_MISSING_CAP:                         return character->animMissingCap;
        case CHAR_ANIM_PULL_DOOR_WALK_IN:                   return character->animPullDoorWalkIn;
        case CHAR_ANIM_PUSH_DOOR_WALK_IN:                   return character->animPushDoorWalkIn;
        case CHAR_ANIM_UNLOCK_DOOR:                         return character->animUnlockDoor;
        case CHAR_ANIM_START_REACH_POCKET:                  return character->animStartReachPocket;
        case CHAR_ANIM_REACH_POCKET:                        return character->animReachPocket;
        case CHAR_ANIM_STOP_REACH_POCKET:                   return character->animStopReachPocket;
        case CHAR_ANIM_GROUND_THROW:                        return character->animGroundThrow;
        case CHAR_ANIM_GROUND_KICK:                         return character->animGroundKick;
        case CHAR_ANIM_FIRST_PUNCH:                         return character->animFirstPunch;
        case CHAR_ANIM_SECOND_PUNCH:                        return character->animSecondPunch;
        case CHAR_ANIM_FIRST_PUNCH_FAST:                    return character->animFirstPunchFast;
        case CHAR_ANIM_SECOND_PUNCH_FAST:                   return character->animSecondPunchFast;
        case CHAR_ANIM_PICK_UP_LIGHT_OBJ:                   return character->animPickUpLightObj;
        case CHAR_ANIM_PUSHING:                             return character->animPushing;
        case CHAR_ANIM_START_RIDING_SHELL:                  return character->animStartRidingShell;
        case CHAR_ANIM_PLACE_LIGHT_OBJ:                     return character->animPlaceLightObj;
        case CHAR_ANIM_FORWARD_SPINNING:                    return character->animForwardSpinning;
        case CHAR_ANIM_BACKWARD_SPINNING:                   return character->animBackwardSpinning;
        case CHAR_ANIM_BREAKDANCE:                          return character->animBreakdance;
        case CHAR_ANIM_RUNNING:                             return character->animRunning;
        case CHAR_ANIM_RUNNING_UNUSED:                      return character->animRunningUnused;
        case CHAR_ANIM_SOFT_BACK_KB:                        return character->animSoftBackKb;
        case CHAR_ANIM_SOFT_FRONT_KB:                       return character->animSoftFrontKb;
        case CHAR_ANIM_DYING_IN_QUICKSAND:                  return character->animDyingInQuicksand;
        case CHAR_ANIM_IDLE_IN_QUICKSAND:                   return character->animIdleInQuicksand;
        case CHAR_ANIM_MOVE_IN_QUICKSAND:                   return character->animMoveInQuicksand;
        case CHAR_ANIM_ELECTROCUTION:                       return character->animElectrocution;
        case CHAR_ANIM_SHOCKED:                             return character->animShocked;
        case CHAR_ANIM_BACKWARD_KB:                         return character->animBackwardKb;
        case CHAR_ANIM_FORWARD_KB:                          return character->animForwardKb;
        case CHAR_ANIM_IDLE_HEAVY_OBJ:                      return character->animIdleHeavyObj;
        case CHAR_ANIM_STAND_AGAINST_WALL:                  return character->animStandAgainstWall;
        case CHAR_ANIM_SIDESTEP_LEFT:                       return character->animSidestepLeft;
        case CHAR_ANIM_SIDESTEP_RIGHT:                      return character->animSidestepRight;
        case CHAR_ANIM_START_SLEEP_IDLE:                    return character->animStartSleepIdle;
        case CHAR_ANIM_START_SLEEP_SCRATCH:                 return character->animStartSleepScratch;
        case CHAR_ANIM_START_SLEEP_YAWN:                    return character->animStartSleepYawn;
        case CHAR_ANIM_START_SLEEP_SITTING:                 return character->animStartSleepSitting;
        case CHAR_ANIM_SLEEP_IDLE:                          return character->animSleepIdle;
        case CHAR_ANIM_SLEEP_START_LYING:                   return character->animSleepStartLying;
        case CHAR_ANIM_SLEEP_LYING:                         return character->animSleepLying;
        case CHAR_ANIM_DIVE:                                return character->animDive;
        case CHAR_ANIM_SLIDE_DIVE:                          return character->animSlideDive;
        case CHAR_ANIM_GROUND_BONK:                         return character->animGroundBonk;
        case CHAR_ANIM_STOP_SLIDE_LIGHT_OBJ:                return character->animStopSlideLightObj;
        case CHAR_ANIM_SLIDE_KICK:                          return character->animSlideKick;
        case CHAR_ANIM_CROUCH_FROM_SLIDE_KICK:              return character->animCrouchFromSlideKick;
        case CHAR_ANIM_SLIDE_MOTIONLESS:                    return character->animSlideMotionless;
        case CHAR_ANIM_STOP_SLIDE:                          return character->animStopSlide;
        case CHAR_ANIM_FALL_FROM_SLIDE:                     return character->animFallFromSlide;
        case CHAR_ANIM_SLIDE:                               return character->animSlide;
        case CHAR_ANIM_TIPTOE:                              return character->animTiptoe;
        case CHAR_ANIM_TWIRL_LAND:                          return character->animTwirlLand;
        case CHAR_ANIM_TWIRL:                               return character->animTwirl;
        case CHAR_ANIM_START_TWIRL:                         return character->animStartTwirl;
        case CHAR_ANIM_STOP_CROUCHING:                      return character->animStopCrouching;
        case CHAR_ANIM_START_CROUCHING:                     return character->animStartCrouching;
        case CHAR_ANIM_CROUCHING:                           return character->animCrouching;
        case CHAR_ANIM_CRAWLING:                            return character->animCrawling;
        case CHAR_ANIM_STOP_CRAWLING:                       return character->animStopCrawling;
        case CHAR_ANIM_START_CRAWLING:                      return character->animStartCrawling;
        case CHAR_ANIM_SUMMON_STAR:                         return character->animSummonStar;
        case CHAR_ANIM_RETURN_STAR_APPROACH_DOOR:           return character->animReturnStarApproachDoor;
        case CHAR_ANIM_BACKWARDS_WATER_KB:                  return character->animBackwardsWaterKb;
        case CHAR_ANIM_SWIM_WITH_OBJ_PART1:                 return character->animSwimWithObjPart1;
        case CHAR_ANIM_SWIM_WITH_OBJ_PART2:                 return character->animSwimWithObjPart2;
        case CHAR_ANIM_FLUTTERKICK_WITH_OBJ:                return character->animFlutterkickWithObj;
        case CHAR_ANIM_WATER_ACTION_END_WITH_OBJ:           return character->animWaterActionEndWithObj;
        case CHAR_ANIM_STOP_GRAB_OBJ_WATER:                 return character->animStopGrabObjWater;
        case CHAR_ANIM_WATER_IDLE_WITH_OBJ:                 return character->animWaterIdleWithObj;
        case CHAR_ANIM_DROWNING_PART1:                      return character->animDrowningPart1;
        case CHAR_ANIM_DROWNING_PART2:                      return character->animDrowningPart2;
        case CHAR_ANIM_WATER_DYING:                         return character->animWaterDying;
        case CHAR_ANIM_WATER_FORWARD_KB:                    return character->animWaterForwardKb;
        case CHAR_ANIM_FALL_FROM_WATER:                     return character->animFallFromWater;
        case CHAR_ANIM_SWIM_PART1:                          return character->animSwimPart1;
        case CHAR_ANIM_SWIM_PART2:                          return character->animSwimPart2;
        case CHAR_ANIM_FLUTTERKICK:                         return character->animFlutterkick;
        case CHAR_ANIM_WATER_ACTION_END:                    return character->animWaterActionEnd;
        case CHAR_ANIM_WATER_PICK_UP_OBJ:                   return character->animWaterPickUpObj;
        case CHAR_ANIM_WATER_GRAB_OBJ_PART2:                return character->animWaterGrabObjPart2;
        case CHAR_ANIM_WATER_GRAB_OBJ_PART1:                return character->animWaterGrabObjPart1;
        case CHAR_ANIM_WATER_THROW_OBJ:                     return character->animWaterThrowObj;
        case CHAR_ANIM_WATER_IDLE:                          return character->animWaterIdle;
        case CHAR_ANIM_WATER_STAR_DANCE:                    return character->animWaterStarDance;
        case CHAR_ANIM_RETURN_FROM_WATER_STAR_DANCE:        return character->animReturnFromWaterStarDance;
        case CHAR_ANIM_GRAB_BOWSER:                         return character->animGrabBowser;
        case CHAR_ANIM_SWINGING_BOWSER:                     return character->animSwingingBowser;
        case CHAR_ANIM_RELEASE_BOWSER:                      return character->animReleaseBowser;
        case CHAR_ANIM_HOLDING_BOWSER:                      return character->animHoldingBowser;
        case CHAR_ANIM_HEAVY_THROW:                         return character->animHeavyThrow;
        case CHAR_ANIM_WALK_PANTING:                        return character->animWalkPanting;
        case CHAR_ANIM_WALK_WITH_HEAVY_OBJ:                 return character->animWalkWithHeavyObj;
        case CHAR_ANIM_TURNING_PART1:                       return character->animTurningPart1;
        case CHAR_ANIM_TURNING_PART2:                       return character->animTurningPart2;
        case CHAR_ANIM_SLIDEFLIP_LAND:                      return character->animSlideflipLand;
        case CHAR_ANIM_SLIDEFLIP:                           return character->animSlideflip;
        case CHAR_ANIM_TRIPLE_JUMP_LAND:                    return character->animTripleJumpLand;
        case CHAR_ANIM_TRIPLE_JUMP:                         return character->animTripleJump;
        case CHAR_ANIM_FIRST_PERSON:                        return character->animFirstPerson;
        case CHAR_ANIM_IDLE_HEAD_LEFT:                      return character->animIdleHeadLeft;
        case CHAR_ANIM_IDLE_HEAD_RIGHT:                     return character->animIdleHeadRight;
        case CHAR_ANIM_IDLE_HEAD_CENTER:                    return character->animIdleHeadCenter;
        case CHAR_ANIM_HANDSTAND_LEFT:                      return character->animHandstandLeft;
        case CHAR_ANIM_HANDSTAND_RIGHT:                     return character->animHandstandRight;
        case CHAR_ANIM_WAKE_FROM_SLEEP:                     return character->animWakeFromSleep;
        case CHAR_ANIM_WAKE_FROM_LYING:                     return character->animWakeFromLying;
        case CHAR_ANIM_START_TIPTOE:                        return character->animStartTiptoe;
        case CHAR_ANIM_SLIDEJUMP:                           return character->animSlidejump;
        case CHAR_ANIM_START_WALLKICK:                      return character->animStartWallkick;
        case CHAR_ANIM_STAR_DANCE:                          return character->animStarDance;
        case CHAR_ANIM_RETURN_FROM_STAR_DANCE:              return character->animReturnFromStarDance;
        case CHAR_ANIM_FORWARD_SPINNING_FLIP:               return character->animForwardSpinningFlip;
        case CHAR_ANIM_TRIPLE_JUMP_FLY:                     return character->animTripleJumpFly;
        default:                                            return 0;
    }
}
