Rogue_Special_Raikou_MapScripts::
	.byte 0


Rogue_Special_TalkRaikou::
	lockall
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_RAIKOU, 5
	setflag FLAG_TEMP_1
	special BattleSetup_StartLegendaryBattle
	waitstate
	removeobject 1
	releaseall
	return

