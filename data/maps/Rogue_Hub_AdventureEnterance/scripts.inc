Rogue_Hub_AdventureEnterance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Rogue_Adventure_RedrawMap
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Rogue_Hub_AdventureEnterance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Rogue_Hub_AdventureEnterance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, Rogue_Adventure_WarpState0
	.2byte 0


Rogue_Adventure_WarpState0::
	goto_if_set FLAG_ROGUE_LEFT_ON_RUN, Rogue_Adventure_WarpState0_2
	goto_if_set FLAG_ROGUE_MET_POKABBIE, Rogue_Adventure_WarpState0_7
Rogue_Adventure_WarpState0_6:
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq Rogue_Adventure_WarpState0_4
	checkitem ITEM_QUEST_LOG
	compare VAR_RESULT, NO
	goto_if_eq Rogue_Adventure_WarpState0_13
Rogue_Adventure_WarpState0_1:
	setvar VAR_TEMP_0, 1
	return

Rogue_Adventure_WarpState0_2:
	call Rogue_ReturnAdventureCommon
	goto Rogue_Adventure_WarpState0_1

Rogue_Adventure_WarpState0_3:
	call Rogue_Adventure_ScottGift
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq Rogue_Adventure_WarpState0_11
	goto Rogue_Adventure_WarpState0_1

Rogue_Adventure_WarpState0_4:
	call Rogue_Adventure_ScottIntro
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	goto Rogue_Adventure_WarpState0_1

Rogue_Adventure_WarpState0_7:
	goto_if_unset FLAG_ROGUE_SCOTT_GIFTED_EXTRAS, Rogue_Adventure_WarpState0_3
	goto Rogue_Adventure_WarpState0_6

Rogue_Adventure_WarpState0_11:
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	goto Rogue_Adventure_WarpState0_1

Rogue_Adventure_WarpState0_13:
	call Rogue_Adventure_ScottOldSaveQuestLog
	goto Rogue_Adventure_WarpState0_1


Rogue_Adventure_RedrawMap::
	goto_if_set FLAG_ROGUE_SCOTT_GIFTED_EXTRAS, Rogue_Adventure_RedrawMap_1
	goto_if_set FLAG_ROGUE_MET_POKABBIE, Rogue_Adventure_RedrawMap_5
Rogue_Adventure_RedrawMap_2:
	setflag FLAG_ROGUE_TRAINER0
	fillmetatile 10, 0, 17, 8, 0x001, TRUE
	return

Rogue_Adventure_RedrawMap_1:
	clearflag FLAG_ROGUE_TRAINER0
	return

Rogue_Adventure_RedrawMap_5:
	goto_if_unset FLAG_ROGUE_SCOTT_GIFTED_EXTRAS, Rogue_Adventure_RedrawMap_1
	goto Rogue_Adventure_RedrawMap_2


Rogue_Adventure_ScottGiveQuestLog::
	giveitem ITEM_QUEST_LOG, 1
	msgbox Rogue_Adventure_ScottGiveQuestLog_Text_0
	return


Rogue_Adventure_ScottIntro::
	lockall
	applymovement 1, Rogue_Adventure_ScottIntroMovement0
	waitmovement 0
	msgbox Rogue_Adventure_ScottIntro_Text_0
	call Rogue_Adventure_ScottGiveQuestLog
	msgbox Rogue_Adventure_ScottIntro_Text_1
	releaseall
	return


Rogue_Adventure_ScottOldSaveQuestLog::
	lockall
	applymovement 1, Rogue_Adventure_ScottIntroMovement0
	waitmovement 0
	msgbox Rogue_Adventure_ScottOldSaveQuestLog_Text_0
	call Rogue_Adventure_ScottGiveQuestLog
	msgbox Rogue_Adventure_ScottOldSaveQuestLog_Text_1
	releaseall
	return


Rogue_Adventure_ScottGift::
	lockall
	setflag FLAG_ROGUE_SCOTT_GIFTED_EXTRAS
	applymovement 1, Rogue_Adventure_ScottIntroMovement0
	waitmovement 0
	msgbox Rogue_Adventure_ScottGift_Text_0, MSGBOX_DEFAULT
	checkitem ITEM_QUEST_LOG
	compare VAR_RESULT, NO
	goto_if_eq Rogue_Adventure_ScottGift_2
Rogue_Adventure_ScottGift_1:
	releaseall
	return

Rogue_Adventure_ScottGift_2:
	msgbox Rogue_Adventure_ScottGift_Text_1
	call Rogue_Adventure_ScottGiveQuestLog
	msgbox Rogue_Adventure_ScottOldSaveQuestLog_Text_1
	goto Rogue_Adventure_ScottGift_1


Rogue_Adventure_SpeakScott::
	lock
	faceplayer
	checkitem ITEM_QUEST_LOG
	compare VAR_RESULT, NO
	goto_if_eq Rogue_Adventure_SpeakScott_2
	nextquestreward
	compare VAR_RESULT, TRUE
	goto_if_eq Rogue_Adventure_SpeakScott_5
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_le Rogue_Adventure_SpeakScott_6
	msgbox Rogue_Adventure_SpeakScott_Text_7
Rogue_Adventure_SpeakScott_1:
	release
	return

Rogue_Adventure_SpeakScott_2:
	msgbox Rogue_Adventure_SpeakScott_Text_0
	call Rogue_Adventure_ScottGiveQuestLog
	msgbox Rogue_Adventure_ScottOldSaveQuestLog_Text_1
	goto Rogue_Adventure_SpeakScott_1

Rogue_Adventure_SpeakScott_5:
	msgbox Rogue_Adventure_SpeakScott_Text_1
Rogue_Adventure_SpeakScott_11:
	compare VAR_RESULT, TRUE
	goto_if_eq Rogue_Adventure_SpeakScott_12
	msgbox Rogue_Adventure_SpeakScott_Text_3
	checkitemspace ITEM_REVIVE
	compare VAR_RESULT, NO
	goto_if_eq Rogue_Adventure_SpeakScott_15
Rogue_Adventure_SpeakScott_14:
	msgbox Rogue_Adventure_SpeakScott_Text_5
	goto Rogue_Adventure_SpeakScott_1

Rogue_Adventure_SpeakScott_6:
	msgbox Rogue_Adventure_SpeakScott_Text_6
	goto Rogue_Adventure_SpeakScott_1

Rogue_Adventure_SpeakScott_12:
	compare VAR_0x8000, QUEST_REWARD_CUSTOM_TEXT
	goto_if_eq Rogue_Adventure_SpeakScott_18
	playse SE_SHOP
Rogue_Adventure_SpeakScott_17:
	msgbox Rogue_Adventure_SpeakScott_Text_2
	compare VAR_0x8000, QUEST_REWARD_CUSTOM_TEXT
	goto_if_eq Rogue_Adventure_SpeakScott_22
	waitse
Rogue_Adventure_SpeakScott_21:
	nextquestreward
	goto Rogue_Adventure_SpeakScott_11

Rogue_Adventure_SpeakScott_15:
	msgbox Rogue_Adventure_SpeakScott_Text_4
	goto Rogue_Adventure_SpeakScott_14

Rogue_Adventure_SpeakScott_18:
	playfanfare MUS_OBTAIN_ITEM
	goto Rogue_Adventure_SpeakScott_17

Rogue_Adventure_SpeakScott_22:
	waitfanfare
	goto Rogue_Adventure_SpeakScott_21


Rogue_Adventure_ScottIntroMovement0:
	face_down
	emote_exclamation_mark
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Rogue_Adventure_StatsSign::
	buffernumberstring STR_VAR_1, VAR_ROGUE_FURTHEST_DIFFICULTY
	msgbox Rogue_Adventure_StatsSign_Text_0, MSGBOX_SIGN
	return


Rogue_Adventure_StartStandard::
	call Rogue_ResetAdventureFlags
	lock
	faceplayer
	msgbox Rogue_Adventure_StartStandard_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Rogue_Adventure_StartStandard_2
	msgbox Rogue_Adventure_StartStandard_Text_1, MSGBOX_DEFAULT
Rogue_Adventure_StartStandard_1:
	release
	return

Rogue_Adventure_StartStandard_2:
	call Rogue_ResetAdventureFlags
	call Rogue_StartAdventureCommon
	goto Rogue_Adventure_StartStandard_1


Rogue_Adventure_StartGauntlet::
	call Rogue_ResetAdventureFlags
	lock
	faceplayer
	message Rogue_Adventure_StartGauntlet_Text_0
	waitmessage
	multichoice 20, 6, MULTI_YESNOINFO, NO
	switch VAR_RESULT
	case 0, Rogue_Adventure_StartGauntlet_3
	case 1, Rogue_Adventure_StartGauntlet_4
	case 2, Rogue_Adventure_StartGauntlet_5
	case MULTI_B_PRESSED, Rogue_Adventure_StartGauntlet_6
Rogue_Adventure_StartGauntlet_1:
	release
	return

Rogue_Adventure_StartGauntlet_3:
	call Rogue_ResetAdventureFlags
	setflag FLAG_ROGUE_GAUNTLET_MODE
	call Rogue_StartAdventureCommon
	goto Rogue_Adventure_StartGauntlet_1

Rogue_Adventure_StartGauntlet_4:
	msgbox Rogue_Adventure_StartStandard_Text_1, MSGBOX_DEFAULT
	goto Rogue_Adventure_StartGauntlet_1

Rogue_Adventure_StartGauntlet_5:
	msgbox Rogue_Adventure_StartGauntlet_Text_1, MSGBOX_DEFAULT
	goto Rogue_Adventure_StartGauntlet_1

Rogue_Adventure_StartGauntlet_6:
	msgbox Rogue_Adventure_StartStandard_Text_1, MSGBOX_DEFAULT
	goto Rogue_Adventure_StartGauntlet_1


Rogue_Adventure_StartRainbow::
	call Rogue_ResetAdventureFlags
	lock
	faceplayer
	message Rogue_Adventure_StartRainbow_Text_0
	waitmessage
	multichoice 20, 6, MULTI_YESNOINFO, NO
	switch VAR_RESULT
	case 0, Rogue_Adventure_StartRainbow_3
	case 1, Rogue_Adventure_StartRainbow_4
	case 2, Rogue_Adventure_StartRainbow_5
	case MULTI_B_PRESSED, Rogue_Adventure_StartRainbow_6
Rogue_Adventure_StartRainbow_1:
	release
	return

Rogue_Adventure_StartRainbow_3:
	call Rogue_ResetAdventureFlags
	setflag FLAG_ROGUE_RAINBOW_MODE
	call Rogue_StartAdventureCommon
	goto Rogue_Adventure_StartRainbow_1

Rogue_Adventure_StartRainbow_4:
	msgbox Rogue_Adventure_StartStandard_Text_1, MSGBOX_DEFAULT
	goto Rogue_Adventure_StartRainbow_1

Rogue_Adventure_StartRainbow_5:
	msgbox Rogue_Adventure_StartRainbow_Text_1, MSGBOX_DEFAULT
	goto Rogue_Adventure_StartRainbow_1

Rogue_Adventure_StartRainbow_6:
	msgbox Rogue_Adventure_StartStandard_Text_1, MSGBOX_DEFAULT
	goto Rogue_Adventure_StartRainbow_1


Rogue_ResetAdventureFlags::
	clearflag FLAG_ROGUE_DOUBLE_BATTLES
	clearflag FLAG_ROGUE_GAUNTLET_MODE
	clearflag FLAG_ROGUE_RAINBOW_MODE
	return


Rogue_StartAdventureCommon::
	special Rogue_AnyNewQuestsPending
	compare VAR_RESULT, TRUE
	goto_if_eq Rogue_StartAdventureCommon_2
Rogue_StartAdventureCommon_1:
	goto_if_set FLAG_ROGUE_MET_POKABBIE, Rogue_StartAdventureCommon_5
Rogue_StartAdventureCommon_4:
	getpartysize
	goto_if_set FLAG_ROGUE_GAUNTLET_MODE, Rogue_StartAdventureCommon_10
	goto_if_set FLAG_ROGUE_DOUBLE_BATTLES, Rogue_StartAdventureCommon_11
	compare VAR_RESULT, 1
	goto_if_gt Rogue_StartAdventureCommon_24
	setvar VAR_RESULT, YES
Rogue_StartAdventureCommon_9:
	compare VAR_RESULT, YES
	goto_if_eq Rogue_StartAdventureCommon_19
	return

Rogue_StartAdventureCommon_2:
	msgbox Rogue_StartAdventureCommon_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Rogue_StartAdventureCommon_7
	goto Rogue_StartAdventureCommon_1

Rogue_StartAdventureCommon_5:
	message Rogue_StartAdventureCommon_Text_1
	waitmessage
	multichoice 20, 8, MULTI_BATTLE_MODE, NO
	switch VAR_RESULT
	case 0, Rogue_StartAdventureCommon_16
	case 1, Rogue_StartAdventureCommon_17
	case MULTI_B_PRESSED, Rogue_StartAdventureCommon_18
	goto Rogue_StartAdventureCommon_4

Rogue_StartAdventureCommon_7:
	return

Rogue_StartAdventureCommon_10:
	setvar VAR_RESULT, YES
	goto Rogue_StartAdventureCommon_9

Rogue_StartAdventureCommon_11:
	compare VAR_RESULT, 2
	goto_if_gt Rogue_StartAdventureCommon_21
	setvar VAR_RESULT, YES
	goto Rogue_StartAdventureCommon_9

Rogue_StartAdventureCommon_16:
	clearflag FLAG_ROGUE_DOUBLE_BATTLES
	setvar VAR_RESULT, YES
	goto Rogue_StartAdventureCommon_4

Rogue_StartAdventureCommon_17:
	setflag FLAG_ROGUE_DOUBLE_BATTLES
	setvar VAR_RESULT, YES
	goto Rogue_StartAdventureCommon_4

Rogue_StartAdventureCommon_18:
	setvar VAR_RESULT, NO
	goto Rogue_StartAdventureCommon_4

Rogue_StartAdventureCommon_19:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 0
	specialvar VAR_RESULT, GetLeadMonLevel
	goto_if_unset FLAG_SET_SEED_ENABLED, Rogue_StartAdventureCommon_30
Rogue_StartAdventureCommon_27:
	compare VAR_ROGUE_SKIP_TO_DIFFICULTY, 0
	goto_if_ne Rogue_StartAdventureCommon_35
Rogue_StartAdventureCommon_34:
	call Common_EventScript_SaveGame
	compare VAR_RESULT, YES
	goto_if_eq Rogue_StartAdventureCommon_53
	msgbox Rogue_StartAdventureCommon_Text_7, MSGBOX_DEFAULT
	return

Rogue_StartAdventureCommon_21:
	msgbox Rogue_StartAdventureCommon_Text_2, MSGBOX_DEFAULT
	setvar VAR_RESULT, NO
	goto Rogue_StartAdventureCommon_9

Rogue_StartAdventureCommon_24:
	msgbox Rogue_StartAdventureCommon_Text_3, MSGBOX_DEFAULT
	setvar VAR_RESULT, NO
	goto Rogue_StartAdventureCommon_9

Rogue_StartAdventureCommon_28:
	compare VAR_RESULT, 85
	goto_if_gt Rogue_StartAdventureCommon_37
	compare VAR_RESULT, 75
	goto_if_gt Rogue_StartAdventureCommon_38
	compare VAR_RESULT, 65
	goto_if_gt Rogue_StartAdventureCommon_39
	compare VAR_RESULT, 55
	goto_if_gt Rogue_StartAdventureCommon_40
	compare VAR_RESULT, 45
	goto_if_gt Rogue_StartAdventureCommon_41
	compare VAR_RESULT, 35
	goto_if_gt Rogue_StartAdventureCommon_42
	compare VAR_RESULT, 25
	goto_if_gt Rogue_StartAdventureCommon_43
	compare VAR_RESULT, 15
	goto_if_gt Rogue_StartAdventureCommon_44
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_29:
	compare VAR_ROGUE_DESIRED_CAMPAIGN, ROGUE_CAMPAIGN_NONE
	goto_if_eq Rogue_StartAdventureCommon_28
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_30:
	goto_if_unset FLAG_ROGUE_GAUNTLET_MODE, Rogue_StartAdventureCommon_29
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_35:
	msgbox Rogue_StartAdventureCommon_Text_4, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_ROGUE_SKIP_TO_DIFFICULTY
	message Rogue_StartAdventureCommon_Text_5
	waitmessage
	multichoice 20, 8, MULTI_FULL_OR_SKIP, NO
	switch VAR_RESULT
	case 0, Rogue_StartAdventureCommon_57
	case 1, Rogue_StartAdventureCommon_58
	case MULTI_B_PRESSED, Rogue_StartAdventureCommon_59
	goto Rogue_StartAdventureCommon_34

Rogue_StartAdventureCommon_37:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 8
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_38:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 7
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_39:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 6
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_40:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 5
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_41:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 4
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_42:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 3
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_43:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 2
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_44:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 1
	goto Rogue_StartAdventureCommon_27

Rogue_StartAdventureCommon_53:
	msgbox Rogue_StartAdventureCommon_Text_6, MSGBOX_DEFAULT
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq Rogue_StartAdventureCommon_61
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
Rogue_StartAdventureCommon_60:
	setflag FLAG_ROGUE_LEFT_ON_RUN
	setrespawn HEAL_LOCATION_ROGUE_HUB
	warp MAP_ROGUE_HUB_TRANSITION, 0
	waitstate
	return

Rogue_StartAdventureCommon_57:
	setvar VAR_ROGUE_SKIP_TO_DIFFICULTY, 0
	setvar VAR_RESULT, YES
	goto Rogue_StartAdventureCommon_34

Rogue_StartAdventureCommon_58:
	setvar VAR_RESULT, YES
	goto Rogue_StartAdventureCommon_34

Rogue_StartAdventureCommon_59:
	setvar VAR_RESULT, NO
	goto Rogue_StartAdventureCommon_34

Rogue_StartAdventureCommon_61:
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	goto Rogue_StartAdventureCommon_60


Rogue_ReturnAdventureCommon::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Rogue_ReturnAdventureCommon_Text_0, MSGBOX_DEFAULT
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_eq Rogue_ReturnAdventureCommon_2
Rogue_ReturnAdventureCommon_1:
	buffernumberstring STR_VAR_1, VAR_ROGUE_REWARD_MONEY
	message Rogue_ReturnAdventureCommon_Text_4
	playfanfare MUS_OBTAIN_ITEM
	waitmessage
	waitfanfare
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_eq Rogue_ReturnAdventureCommon_5
Rogue_ReturnAdventureCommon_4:
	clearflag FLAG_ROGUE_LEFT_ON_RUN
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_set FLAG_SET_SEED_ENABLED, Rogue_ReturnAdventureCommon_8
Rogue_ReturnAdventureCommon_7:
	msgbox Rogue_ReturnAdventureCommon_Text_10, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Rogue_ReturnAdventureCommon_11
Rogue_ReturnAdventureCommon_10:
	msgbox Rogue_ReturnAdventureCommon_Text_11, MSGBOX_DEFAULT
	releaseall
	return

Rogue_ReturnAdventureCommon_2:
	msgbox Rogue_ReturnAdventureCommon_Text_1, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_ROGUE_CURRENT_ROOM_IDX
	msgbox Rogue_ReturnAdventureCommon_Text_2, MSGBOX_DEFAULT
	msgbox Rogue_ReturnAdventureCommon_Text_3, MSGBOX_DEFAULT
	goto Rogue_ReturnAdventureCommon_1

Rogue_ReturnAdventureCommon_5:
	bufferitemname STR_VAR_2, ITEM_RARE_CANDY
	msgbox Rogue_ReturnAdventureCommon_Text_5, MSGBOX_DEFAULT
	msgbox Rogue_ReturnAdventureCommon_Text_6, MSGBOX_DEFAULT
	goto Rogue_ReturnAdventureCommon_4

Rogue_ReturnAdventureCommon_8:
	msgbox Rogue_ReturnAdventureCommon_Text_7, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Rogue_ReturnAdventureCommon_13
	msgbox Rogue_ReturnAdventureCommon_Text_9, MSGBOX_DEFAULT
	clearflag FLAG_SET_SEED_ENABLED
	goto Rogue_ReturnAdventureCommon_7

Rogue_ReturnAdventureCommon_11:
	call Common_EventScript_SaveGame
	goto Rogue_ReturnAdventureCommon_10

Rogue_ReturnAdventureCommon_13:
	msgbox Rogue_ReturnAdventureCommon_Text_8, MSGBOX_DEFAULT
	goto Rogue_ReturnAdventureCommon_7


Rogue_Adventure_ScottGiveQuestLog_Text_0:
	.string "That log has a lot of optional Quests\n"
	.string "for you to complete whilst you're out\l"
	.string "on an Adventure.\p"
	.string "Completing Quests can give you some\n"
	.string "nice rewards too.\p"
	.string "Once you complete any, come and chat to\n"
	.string "me and I'll give your rewards.$"

Rogue_Adventure_ScottIntro_Text_0:
	.string "SCOTT: Hey {PLAYER}!\p"
	.string "Looks like you got yourself a partner\n"
	.string "POKéMON, so you're all ready to go on an\l"
	.string "Adventure!\p"
	.string "Before you head off you should take\n"
	.string "this.$"

Rogue_Adventure_ScottIntro_Text_1:
	.string "Looks like you're all good to go now!\p"
	.string "Just go chat to the nurse over there\n"
	.string "and you can start exploring!$"

Rogue_Adventure_ScottOldSaveQuestLog_Text_0:
	.string "SCOTT: Hey {PLAYER}!\p"
	.string "Before you head off your next\n"
	.string "Adventure, you should take this.$"

Rogue_Adventure_ScottOldSaveQuestLog_Text_1:
	.string "Looks like you're all good to go now!$"

Rogue_Adventure_ScottGift_Text_0:
	.string "SCOTT: Oh hey {PLAYER}!\n"
	.string "POKABBIE has gone and added some\l"
	.string "extra modes here for you to try!$"

Rogue_Adventure_ScottGift_Text_1:
	.string "Before you head off your next\n"
	.string "Adventure, you should also take this.$"

Rogue_Adventure_SpeakScott_Text_0:
	.string "SCOTT: Hey {PLAYER}!\p"
	.string "Before you head off your next\n"
	.string "Adventure, you should also take this.$"

Rogue_Adventure_SpeakScott_Text_1:
	.string "SCOTT: Hey {PLAYER}!\p"
	.string "I have some Quest Rewards for you!$"

Rogue_Adventure_SpeakScott_Text_2:
	.string "{STR_VAR_3}$"

Rogue_Adventure_SpeakScott_Text_3:
	.string "And that's all for the moment!$"

Rogue_Adventure_SpeakScott_Text_4:
	.string "Looks like you have a full bag there.\p"
	.string "Be sure to check your PC as some\n"
	.string "rewards may turn up there.$"

Rogue_Adventure_SpeakScott_Text_5:
	.string "Good luck with your next Adventure\n"
	.string "champ!$"

Rogue_Adventure_SpeakScott_Text_6:
	.string "SCOTT: Hey {PLAYER}!\p"
	.string "Just go chat to the nurse over there\n"
	.string "and you can start exploring!$"

Rogue_Adventure_SpeakScott_Text_7:
	.string "SCOTT: Hey {PLAYER}!\p"
	.string "Be sure to come and chat with me once\n"
	.string "you complete Quests so I can give you\l"
	.string "your rewards!$"

Rogue_Adventure_StatsSign_Text_0:
	.string "Furthest Progress:\n"
	.string "Gained {STR_VAR_1} BADGES...\p"
	.string "A note from the dev..\p"
	.string "-Run stats to come in a future update!$"

Rogue_Adventure_StartStandard_Text_0:
	.string "Would you like to go on an adventure?$"

Rogue_Adventure_StartStandard_Text_1:
	.string "Feel free to speak with me again, if you\n"
	.string "change your mind.$"

Rogue_Adventure_StartGauntlet_Text_0:
	.string "Would you like to go on a GAUNTLET\n"
	.string "adventure?$"

Rogue_Adventure_StartGauntlet_Text_1:
	.string "In GAUNTLET adventures, you will get\n"
	.string "given a few routes to capture POKéMON\l"
	.string "and collect items.\p"
	.string "After that you will fight every BOSS\n"
	.string "back to back with no chance to get any\l"
	.string "more POKéMON or items.\p"
	.string "This is a high stakes mode intended for\n"
	.string "faster more difficult battles,\l"
	.string "although almost all Quests are\l"
	.string "disabled in this mode.$"

Rogue_Adventure_StartRainbow_Text_0:
	.string "Would you like to go on a RAINBOW\n"
	.string "adventure?$"

Rogue_Adventure_StartRainbow_Text_1:
	.string "RAINBOW adventures are very similar to\n"
	.string "a normal adventure.\p"
	.string "The main difference is that any and all\n"
	.string "types can appear for Boss fights.\p"
	.string "For example Wallace could appear as the\n"
	.string "first GYM leader or ROXANNE could end\l"
	.string "up being the CHAMPION!\p"
	.string "You will even encounter Boss trainers\n"
	.string "sporting types not usually seen in\l"
	.string "normal adventures.\p"
	.string "In this mode trainers from all regions\n"
	.string "will be enabled.\n"
	.string "In other words your settings in the\l"
	.string "Config Lab will be ignored.$"

Rogue_StartAdventureCommon_Text_0:
	.string "Before you head out, I should mention,\n"
	.string "Scott was looking for you.\p"
	.string "He mentioned something about having\n"
	.string "some new Quest ready to unlock?\p"
	.string "Do you still want to continue?$"

Rogue_StartAdventureCommon_Text_1:
	.string "Which battle-style would you like to\n"
	.string "play?$"

Rogue_StartAdventureCommon_Text_2:
	.string "Looks like you have too many POKéMON.\p"
	.string "You can only take in 2 POKéMON into this\n"
	.string "mode.\n"
	.string "You should use the PC to deposit some\l"
	.string "before I can let you on an adventure.$"

Rogue_StartAdventureCommon_Text_3:
	.string "Looks like you have too many POKéMON.\p"
	.string "You can only take in 1 POKéMON into this\n"
	.string "mode.\n"
	.string "You should use the PC to deposit some\l"
	.string "before I can let you on an adventure.$"

Rogue_StartAdventureCommon_Text_4:
	.string "You've leveled up your PARTNER enough\n"
	.string "to skip ahead!$"

Rogue_StartAdventureCommon_Text_5:
	.string "Would you like to skip ahead and start\n"
	.string "just after BADGE {STR_VAR_1}?$"

Rogue_StartAdventureCommon_Text_6:
	.string "Good luck {PLAYER}!$"

Rogue_StartAdventureCommon_Text_7:
	.string "OK. Come speak to me once you're ready.$"

Rogue_ReturnAdventureCommon_Text_0:
	.string "Welcome back {PLAYER}!$"

Rogue_ReturnAdventureCommon_Text_1:
	.string "Whenever you return from an adventure\n"
	.string "you earn rewards based on how well you\l"
	.string "did.$"

Rogue_ReturnAdventureCommon_Text_2:
	.string "Lets have a look now...\p"
	.string "You managed to complete{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
	.string "{STR_VAR_1} routes...{PAUSE 15}$"

Rogue_ReturnAdventureCommon_Text_3:
	.string "So hmm...\n"
	.string "Your rewards should be{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

Rogue_ReturnAdventureCommon_Text_4:
	.string "You recieve ¥{STR_VAR_1}$"

Rogue_ReturnAdventureCommon_Text_5:
	.string "Since you're back from your first\n"
	.string "adventure, you should speak to Scott\l"
	.string "and collect any rewards for Quests\l"
	.string "you've completed.$"

Rogue_ReturnAdventureCommon_Text_6:
	.string "Quests will often reward you with\n"
	.string "{STR_VAR_2}.\p"
	.string "By leveling up your PARTNER with these\n"
	.string "you will gain the option to skip over\l"
	.string "GYM badges in future Adventures.$"

Rogue_ReturnAdventureCommon_Text_7:
	.string "Would you like to keep the same SEED\n"
	.string "enabled for your next Adventure?$"

Rogue_ReturnAdventureCommon_Text_8:
	.string "OK.\n"
	.string "I'll remember the same SEED then.$"

Rogue_ReturnAdventureCommon_Text_9:
	.string "OK.\n"
	.string "The SEED will be removed for the next\l"
	.string "Adventure.$"

Rogue_ReturnAdventureCommon_Text_10:
	.string "Would you like to SAVE your progress?$"

Rogue_ReturnAdventureCommon_Text_11:
	.string "Come speak to me once you're ready for\n"
	.string "your next adventure.$"
