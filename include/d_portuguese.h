// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
// 
// Copyricht (C) 2022 by André Guilherme
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//	Printed strings for translation in 
// brazilian portuguese language
//
//-----------------------------------------------------------------------------

#ifndef __D_PORTUGUESE__
#define __D_PORTUGUESE__

//
//	frases printadas para tradução
//

//
// d_main.c
//
#define D_DEVSTR	"Modo de Desenvolvimento LIGADO.\n"
#define D_CDROM	"Versão de CD-ROM: default.cfg de c:\\doomdata\n"

//
//	m_menu.c
//
#define PRESSKEY 	"aperte um botão."
#define PRESSYN 	"aperte y ou n."
#define QUITMSG	"tem certeza que você quer\nsair desse ótimo jogo?"
#define LOADNET 	"você não pode carregar emquanto estiver em um jogo na rede local!\n\n"PRESSKEY
#define QLOADNET	"você não pode carregar rápido durante um jogo na rede local!\n\n"PRESSKEY
#define QSAVESPOT	"você ainda não pegou um slot de save rápido!\n\n"PRESSKEY
#define SAVEDEAD 	"você não pode salvar enquanto não estiver jogando!\n\n"PRESSKEY
#define QSPROMPT 	"desseja usar um save rápido em cima do seu jogo nomeado\n\n'%s'?\n\n"PRESSYN
#define QLPROMPT	"você quer fazer um carregamento rápido do jogo nomeado\n\n'%s'?\n\n"PRESSYN

#define NEWGAME	\
"Você não pode iniciar um novo jogo\n"\
"enquanto em jogo na rede local.\n\n"PRESSKEY

#define NIGHTMARE	\
"Você tem certeza? em usar esse nivel de dificuldade \n"\
"isso nem é remotamente justo.\n\n"PRESSYN

#define SWSTRING	\
"essa é uma versão código aberto do doom.\n\n"\
"você não precisa pagar toda trilogia já que é de graça.\n\n"PRESSKEY

#define MSGOFF	 "Mensagens DESLIGADAS"
#define MSGON		"Mensagens LIGADAS"
#define NETEND	"você não pode encerrar um jogo de rede local!\n\n"PRESSKEY
#define ENDGAME	"você tem certeza de que você quer acabar o jogo?\n\n"PRESSYN

#define DOSY		"(aperte y para sair)"

#define DETAILHI	"Alto detalhe High detail"
#define DETAILLO	"Baixo detalhe"
#define GAMMALVL0	"Correção de Gama DESLIGADA"
#define GAMMALVL1	"Correcão de Gama nível 1"
#define GAMMALVL2	"Correção de Gama nível 2"
#define GAMMALVL3	"Correção de Gama nível 3"
#define GAMMALVL4	"Correção de Game nível 4"
#define EMPTYSTRING	"slot vazio"

//
//	p_inter.c
//
#define GOTARMOR	"Pegou uma armadura."
#define GOTMEGA	"Pegou uma MegaArmadura!"
#define GOTHTHBONUS	"Pegou um bônus de vida."
#define GOTARMBONUS	"Pegou um bônus de armadura."
#define GOTSTIM	"Pegou uma agulha."
#define GOTMEDINEED	"Pegou um kit médico que você REALMENTE precisa!"
#define GOTMEDIKIT	"Pegou um kit médico."
#define GOTSUPER	"Supercarga!"

#define GOTBLUECARD	"Pegou um cartão azul."
#define GOTYELWCARD	"Pegou um cartão amarelo."
#define GOTREDCARD	"Pegou um cartão vermelho."
#define GOTBLUESKUL	"Pegou uma chave craniana azul."
#define GOTYELWSKUL	"Pegou uma chave craniana amarela."
#define GOTREDSKULL	"Pegou uma chave craniana vermelha."

#define GOTINVUL	"Invulnerabilidade!"
#define GOTBERSERK	"Berserk!"
#define GOTINVIS	"Invisibilidade parcial"
#define GOTSUIT	"Traje de proteção a radiação"
#define GOTMAP	"Mapa da area de computação"
#define GOTVISOR	"Visor de ampliciação de luz"
#define GOTMSPHERE	"MegaEsfera!"

#define GOTCLIP	"Pegou um pente."
#define GOTCLIPBOX	"Pegou uma caixa de balas."
#define GOTROCKET	"Pegou um míssil."
#define GOTROCKBOX	"Pegou uma caixa de mísseis."
#define GOTCELL	"Pegou uma célula de energia."
#define GOTCELLBOX	"Pegou um pacote de célula de energia."
#define GOTSHELLS	"Pegou 4 cartuchos de escopeta."
#define GOTSHELLBOX	"Pegou uma caixa com cartuchos de escopeta."
#define GOTBACKPACK	"Pegou uma mochila cheia de munição!"

#define GOTBFG9000	"Ah sim, Você pegou a BFG9000!"
#define GOTCHAINGUN	"Você pegou uma metralhadora giratória!"
#define GOTCHAINSAW	"Encontre alguma carne com a MOTOSERRA!"
#define GOTLAUNCHER	"Você conseguiu um lançador de mísseis!"
#define GOTPLASMA	"Você conseguiu uma arma de plasma!"
#define GOTSHOTGUN	"Você pegou a escopeta!"
#define GOTSHOTGUN2	"Você pegou a super escopeta!"

//
// p_doors.c
//
#define PD_BLUEO	"Você precisa da chave azul para ativar este objeto"
#define PD_REDO	"Você precisa da chave vermelha para ativar este objeto"
#define PD_YELLOWO	"Você precisa de chave amarela para ativar este objeto"
#define PD_BLUEK	"Você precisa da chave azul para abrir essa porta"
#define PD_REDK	"Você precisa da chave vermelha para abrir essa porta"
#define PD_YELLOWK	"Você precisa da chave amarela para abrir essa porta"

//
//	g_game.c
//
#define GGSAVED	"jogo salvo."

//
//	hu_stuff.c
//
#define HUSTR_MSGU	"[Mensagem não enviada]"

#define HUSTR_E1M1	"E1M1: Hangar"
#define HUSTR_E1M2	"E1M2: Usina Nuclear"
#define HUSTR_E1M3	"E1M3: Refinaria de toxina"
#define HUSTR_E1M4	"E1M4: Controle de comando"
#define HUSTR_E1M5	"E1M5: Laborátorio de phobos"
#define HUSTR_E1M6	"E1M6: Central de processamento"
#define HUSTR_E1M7	"E1M7: Estação de pomputação"
#define HUSTR_E1M8	"E1M8: Anomália de Phobos"
#define HUSTR_E1M9	"E1M9: Base Militar"

#define HUSTR_E2M1	"E2M1: Anomália de Deimos"
#define HUSTR_E2M2	"E2M2: Área de Contenção"
#define HUSTR_E2M3	"E2M3: Refinária"
#define HUSTR_E2M4	"E2M4: Láboratório de Deimos"
#define HUSTR_E2M5	"E2M5: Centro de comando"
#define HUSTR_E2M6	"E2M6: Corredoores dos Amaldiçoados"
#define HUSTR_E2M7	"E2M7: Aparições de Cubas"
#define HUSTR_E2M8	"E2M8: Torre De Babel"
#define HUSTR_E2M9	"E2M9: Fortaleza do Mistério"

#define HUSTR_E3M1	"E3M1: Guarda do Inferno"
#define HUSTR_E3M2	"E3M2: Desmoronamento do Desespero"
#define HUSTR_E3M3	"E3M3: Pandemonium"
#define HUSTR_E3M4	"E3M4: Casa do Sofrimento"
#define HUSTR_E3M5	"E3M5: Catedral Impiedosa"
#define HUSTR_E3M6	"E3M6: Mt. Erebus"
#define HUSTR_E3M7	"E3M7: Limbo"
#define HUSTR_E3M8	"E3M8: Dis"
#define HUSTR_E3M9	"E3M9: Warrens"

#define HUSTR_E4M1	"E4M1: Inferno Abaixo"
#define HUSTR_E4M2	"E4M2: O perfeito ódio"
#define HUSTR_E4M3	"E4M3: Sever o Malvado"
#define HUSTR_E4M4	"E4M4: O mal sem rumo"
#define HUSTR_E4M5	"E4M5: Eles irão se Arrepender"
#define HUSTR_E4M6	"E4M6: Contra o Ti Perverso"
#define HUSTR_E4M7	"E4M7: E o Inferno Seguiu"
#define HUSTR_E4M8	"E4M8: Dentro do Cruel"
#define HUSTR_E4M9	"E4M9: Medo"

#define HUSTR_1	"nível 1: entrada"
#define HUSTR_2	"nível 2: abaixo dos corredores"
#define HUSTR_3	"nível 3: a manopola"
#define HUSTR_4	"nível 4: o foco"
#define HUSTR_5	"nível 5: os túneis de descarte"
#define HUSTR_6	"nível 6: o esmagador"
#define HUSTR_7	"nível 7: morte simples"
#define HUSTR_8	"nível 8: manobras e armadilhas"
#define HUSTR_9	"nível 9: o poço"
#define HUSTR_10	"nível 10: base de recarga"
#define HUSTR_11	"nível 11: 'd' de destruição!"
//
#define HUSTR_12	"nível 12: A fábrica"
#define HUSTR_13	"level 13: cidade"
#define HUSTR_14	"level 14: the inmost dens"
#define HUSTR_15	"level 15: zona industrial"
#define HUSTR_16	"level 16: súburbios"
#define HUSTR_17	"level 17: cortiços"
#define HUSTR_18	"level 18: o pátio"
#define HUSTR_19	"level 19: a cidadela"
#define HUSTR_20	"level 20: peguei você!"

#define HUSTR_21	"level 21: nirvana"
#define HUSTR_22	"level 22: as catacumbas"
#define HUSTR_23	"level 23: barris de diversão"
#define HUSTR_24	"level 24: o chasm"
#define HUSTR_25	"level 25: queda de sangue"
#define HUSTR_26	"level 26: as minas abandonadas"
#define HUSTR_27	"level 27: condo monstruoso"
#define HUSTR_28	"level 28: o mundo espiritual"
#define HUSTR_29	"level 29: o final vivo"
#define HUSTR_30	"level 30: ícone do pecado"

#define HUSTR_31	"level 31: wolfenstein"
#define HUSTR_32	"level 32: nojeira"

#define PHUSTR_1	"level 1: congo"
#define PHUSTR_2	"level 2: well of souls"
#define PHUSTR_3	"level 3: aztec"
#define PHUSTR_4	"level 4: caged"
#define PHUSTR_5	"level 5: ghost town"
#define PHUSTR_6	"level 6: baron's lair"
#define PHUSTR_7	"level 7: caughtyard"
#define PHUSTR_8	"level 8: realm"
#define PHUSTR_9	"level 9: abattoire"
#define PHUSTR_10	"level 10: onslaught"
#define PHUSTR_11	"level 11: hunted"

#define PHUSTR_12	"level 12: speed"
#define PHUSTR_13	"level 13: the crypt"
#define PHUSTR_14	"level 14: genesis"
#define PHUSTR_15	"level 15: the twilight"
#define PHUSTR_16	"level 16: the omen"
#define PHUSTR_17	"level 17: compound"
#define PHUSTR_18	"level 18: neurosphere"
#define PHUSTR_19	"level 19: nme"
#define PHUSTR_20	"level 20: the death domain"

#define PHUSTR_21	"level 21: slayer"
#define PHUSTR_22	"level 22: impossible mission"
#define PHUSTR_23	"level 23: tombstone"
#define PHUSTR_24	"level 24: the final frontier"
#define PHUSTR_25	"level 25: the temple of darkness"
#define PHUSTR_26	"level 26: bunker"
#define PHUSTR_27	"level 27: anti-christ"
#define PHUSTR_28	"level 28: the sewers"
#define PHUSTR_29	"level 29: odyssey of noises"
#define PHUSTR_30	"level 30: the gateway of hell"

#define PHUSTR_31	"level 31: cyberden"
#define PHUSTR_32	"level 32: go 2 it"

#define THUSTR_1	"level 1: system control"
#define THUSTR_2	"level 2: human bbq"
#define THUSTR_3	"level 3: power control"
#define THUSTR_4	"level 4: wormhole"
#define THUSTR_5	"level 5: hanger"
#define THUSTR_6	"level 6: open season"
#define THUSTR_7	"level 7: prison"
#define THUSTR_8	"level 8: metal"
#define THUSTR_9	"level 9: stronghold"
#define THUSTR_10	"level 10: redemption"
#define THUSTR_11	"level 11: storage facility"

#define THUSTR_12	"level 12: crater"
#define THUSTR_13	"level 13: nukage processing"
#define THUSTR_14	"level 14: steel works"
#define THUSTR_15	"level 15: dead zone"
#define THUSTR_16	"level 16: deepest reaches"
#define THUSTR_17	"level 17: processing area"
#define THUSTR_18	"level 18: mill"
#define THUSTR_19	"level 19: shipping/respawning"
#define THUSTR_20	"level 20: central processing"

#define THUSTR_21	"level 21: administration center"
#define THUSTR_22	"level 22: habitat"
#define THUSTR_23	"level 23: lunar mining project"
#define THUSTR_24	"level 24: quarry"
#define THUSTR_25	"level 25: baron's den"
#define THUSTR_26	"level 26: ballistyx"
#define THUSTR_27	"level 27: mount pain"
#define THUSTR_28	"level 28: heck"
#define THUSTR_29	"level 29: river styx"
#define THUSTR_30	"level 30: last call"

#define THUSTR_31	"level 31: pharaoh"
#define THUSTR_32	"level 32: caribbean"

#define HUSTR_CHATMACRO1	"Eu estou pronto para foder!"
#define HUSTR_CHATMACRO2	"Eu estou bem."
#define HUSTR_CHATMACRO3	"Me parece que eu não estou muito bem!"
#define HUSTR_CHATMACRO4	"Ajuda!"
#define HUSTR_CHATMACRO5	"Você é chato!"
#define HUSTR_CHATMACRO6	"Na próxima vez, seu merda..."
#define HUSTR_CHATMACRO7	"Venha cá!"
#define HUSTR_CHATMACRO8	"Eu vou cuidar disso."
#define HUSTR_CHATMACRO9	"Sim"
#define HUSTR_CHATMACRO0	"Não"

#define HUSTR_TALKTOSELF1	"Você resmunga para si mesmo"
#define HUSTR_TALKTOSELF2	"Quem está aí?"
#define HUSTR_TALKTOSELF3	"Você assusta a si mesmo"
#define HUSTR_TALKTOSELF4	"Você começa a delirar"
#define HUSTR_TALKTOSELF5	"Você ficou louco..."

#define HUSTR_MESSAGESENT	"[Mensagem enviada]"

// The following should NOT be changed unless it seems
// just AWFULLY necessary

#define HUSTR_PLRGREEN	"Verde: "
#define HUSTR_PLRINDIGO	"Indigo: "
#define HUSTR_PLRBROWN	"Marrom: "
#define HUSTR_PLRRED		"Vermelho: "

#define HUSTR_KEYGREEN	'g'
#define HUSTR_KEYINDIGO	'i'
#define HUSTR_KEYBROWN	'b'
#define HUSTR_KEYRED	'r'

//
//	am_map.c
//

#define AMSTR_FOLLOWON	"Modo De Seguir LIGADO"
#define AMSTR_FOLLOWOFF	"Modo De Seguir DESLIGADO"

#define AMSTR_GRIDON	"Grid LIGADA"
#define AMSTR_GRIDOFF	"Grid DESLIGADA"

#define AMSTR_MARKEDSPOT	"Lugar marcado"
#define AMSTR_MARKSCLEARED	"Todas as marcações limpas"

//
//	st_stuff.c
//

#define STSTR_MUS		"Mudança de Música"
#define STSTR_NOMUS		"SELEÇÃO IMPÓSSIVEL"
#define STSTR_DQDON		"Modo Degreelessness Ligado"
#define STSTR_DQDOFF	"Modo Degreelessness Desligado"

#define STSTR_KFAADDED	"Munição muito feliz adicionada"
#define STSTR_FAADDED	"Munição (sem chaves) Adicionada"

#define STSTR_NCON		"Modo Sem Corte LIGADO"
#define STSTR_NCOFF		"Modo Sem Corte DESLIGADO"

#define STSTR_BEHOLD	"inVuln, Str, Inviso, Rad, Allmap, ou Lite-amp"
#define STSTR_BEHOLDX	"Ligar pressionado"

#define STSTR_CHOPPERS	"... não seja ruim - GM"
#define STSTR_CLEV		"Mudando nível..."

//
//	f_finale.c
//
#define E1TEXT \
"Once you beat the big badasses and\n"\
"clean out the moon base you're supposed\n"\
"to win, aren't you? Aren't you? Where's\n"\
"your fat reward and ticket home? What\n"\
"the hell is this? It's not supposed to\n"\
"end this way!\n"\
"\n" \
"It stinks like rotten meat, but looks\n"\
"like the lost Deimos base.  Looks like\n"\
"you're stuck on The Shores of Hell.\n"\
"The only way out is through.\n"\
"\n"\
"To continue the DOOM experience, play\n"\
"The Shores of Hell and its amazing\n"\
"sequel, Inferno!\n"


#define E2TEXT \
"You've done it! The hideous cyber-\n"\
"demon lord that ruled the lost Deimos\n"\
"moon base has been slain and you\n"\
"are triumphant! But ... where are\n"\
"you? You clamber to the edge of the\n"\
"moon and look down to see the awful\n"\
"truth.\n" \
"\n"\
"Deimos floats above Hell itself!\n"\
"You've never heard of anyone escaping\n"\
"from Hell, but you'll make the bastards\n"\
"sorry they ever heard of you! Quickly,\n"\
"you rappel down to  the surface of\n"\
"Hell.\n"\
"\n" \
"Now, it's on to the final chapter of\n"\
"DOOM! -- Inferno."


#define E3TEXT \
"The loathsome spiderdemon that\n"\
"masterminded the invasion of the moon\n"\
"bases and caused so much death has had\n"\
"its ass kicked for all time.\n"\
"\n"\
"A hidden doorway opens and you enter.\n"\
"You've proven too tough for Hell to\n"\
"contain, and now Hell at last plays\n"\
"fair -- for you emerge from the door\n"\
"to see the green fields of Earth!\n"\
"Home at last.\n" \
"\n"\
"You wonder what's been happening on\n"\
"Earth while you were battling evil\n"\
"unleashed. It's good that no Hell-\n"\
"spawn could have come through that\n"\
"door with you ..."


#define E4TEXT \
"the spider mastermind must have sent forth\n"\
"its legions of hellspawn before your\n"\
"final confrontation with that terrible\n"\
"beast from hell.  but you stepped forward\n"\
"and brought forth eternal damnation and\n"\
"suffering upon the horde as a true hero\n"\
"would in the face of something so evil.\n"\
"\n"\
"besides, someone was gonna pay for what\n"\
"happened to daisy, your pet rabbit.\n"\
"\n"\
"but now, you see spread before you more\n"\
"potential pain and gibbitude as a nation\n"\
"of demons run amok among our cities.\n"\
"\n"\
"next stop, hell on earth!"


// after level 6, put this:

#define C1TEXT \
"YOU HAVE ENTERED DEEPLY INTO THE INFESTED\n" \
"STARPORT. BUT SOMETHING IS WRONG. THE\n" \
"MONSTERS HAVE BROUGHT THEIR OWN REALITY\n" \
"WITH THEM, AND THE STARPORT'S TECHNOLOGY\n" \
"IS BEING SUBVERTED BY THEIR PRESENCE.\n" \
"\n"\
"AHEAD, YOU SEE AN OUTPOST OF HELL, A\n" \
"FORTIFIED ZONE. IF YOU CAN GET PAST IT,\n" \
"YOU CAN PENETRATE INTO THE HAUNTED HEART\n" \
"OF THE STARBASE AND FIND THE CONTROLLING\n" \
"SWITCH WHICH HOLDS EARTH'S POPULATION\n" \
"HOSTAGE."

// After level 11, put this:

#define C2TEXT \
"YOU HAVE WON! YOUR VICTORY HAS ENABLED\n" \
"HUMANKIND TO EVACUATE EARTH AND ESCAPE\n"\
"THE NIGHTMARE.  NOW YOU ARE THE ONLY\n"\
"HUMAN LEFT ON THE FACE OF THE PLANET.\n"\
"CANNIBAL MUTATIONS, CARNIVOROUS ALIENS,\n"\
"AND EVIL SPIRITS ARE YOUR ONLY NEIGHBORS.\n"\
"YOU SIT BACK AND WAIT FOR DEATH, CONTENT\n"\
"THAT YOU HAVE SAVED YOUR SPECIES.\n"\
"\n"\
"BUT THEN, EARTH CONTROL BEAMS DOWN A\n"\
"MESSAGE FROM SPACE: \"SENSORS HAVE LOCATED\n"\
"THE SOURCE OF THE ALIEN INVASION. IF YOU\n"\
"GO THERE, YOU MAY BE ABLE TO BLOCK THEIR\n"\
"ENTRY.  THE ALIEN BASE IS IN THE HEART OF\n"\
"YOUR OWN HOME CITY, NOT FAR FROM THE\n"\
"STARPORT.\" SLOWLY AND PAINFULLY YOU GET\n"\
"UP AND RETURN TO THE FRAY."


// After level 20, put this:

#define C3TEXT \
"YOU ARE AT THE CORRUPT HEART OF THE CITY,\n"\
"SURROUNDED BY THE CORPSES OF YOUR ENEMIES.\n"\
"YOU SEE NO WAY TO DESTROY THE CREATURES'\n"\
"ENTRYWAY ON THIS SIDE, SO YOU CLENCH YOUR\n"\
"TEETH AND PLUNGE THROUGH IT.\n"\
"\n"\
"THERE MUST BE A WAY TO CLOSE IT ON THE\n"\
"OTHER SIDE. WHAT DO YOU CARE IF YOU'VE\n"\
"GOT TO GO THROUGH HELL TO GET TO IT?"


// After level 29, put this:

#define C4TEXT \
"THE HORRENDOUS VISAGE OF THE BIGGEST\n"\
"DEMON YOU'VE EVER SEEN CRUMBLES BEFORE\n"\
"YOU, AFTER YOU PUMP YOUR ROCKETS INTO\n"\
"HIS EXPOSED BRAIN. THE MONSTER SHRIVELS\n"\
"UP AND DIES, ITS THRASHING LIMBS\n"\
"DEVASTATING UNTOLD MILES OF HELL'S\n"\
"SURFACE.\n"\
"\n"\
"YOU'VE DONE IT. THE INVASION IS OVER.\n"\
"EARTH IS SAVED. HELL IS A WRECK. YOU\n"\
"WONDER WHERE BAD FOLKS WILL GO WHEN THEY\n"\
"DIE, NOW. WIPING THE SWEAT FROM YOUR\n"\
"FOREHEAD YOU BEGIN THE LONG TREK BACK\n"\
"HOME. REBUILDING EARTH OUGHT TO BE A\n"\
"LOT MORE FUN THAN RUINING IT WAS.\n"



// Before level 31, put this:

#define C5TEXT \
"CONGRATULATIONS, YOU'VE FOUND THE SECRET\n"\
"LEVEL! LOOKS LIKE IT'S BEEN BUILT BY\n"\
"HUMANS, RATHER THAN DEMONS. YOU WONDER\n"\
"WHO THE INMATES OF THIS CORNER OF HELL\n"\
"WILL BE."


// Before level 32, put this:

#define C6TEXT \
"CONGRATULATIONS, YOU'VE FOUND THE\n"\
"SUPER SECRET LEVEL!  YOU'D BETTER\n"\
"BLAZE THROUGH THIS ONE!\n"


// after map 06	

#define P1TEXT  \
"You gloat over the steaming carcass of the\n"\
"Guardian.  With its death, you've wrested\n"\
"the Accelerator from the stinking claws\n"\
"of Hell.  You relax and glance around the\n"\
"room.  Damn!  There was supposed to be at\n"\
"least one working prototype, but you can't\n"\
"see it. The demons must have taken it.\n"\
"\n"\
"You must find the prototype, or all your\n"\
"struggles will have been wasted. Keep\n"\
"moving, keep fighting, keep killing.\n"\
"Oh yes, keep living, too."


// after map 11

#define P2TEXT \
"Even the deadly Arch-Vile labyrinth could\n"\
"not stop you, and you've gotten to the\n"\
"prototype Accelerator which is soon\n"\
"efficiently and permanently deactivated.\n"\
"\n"\
"You're good at that kind of thing."


// after map 20

#define P3TEXT \
"You've bashed and battered your way into\n"\
"the heart of the devil-hive.  Time for a\n"\
"Search-and-Destroy mission, aimed at the\n"\
"Gatekeeper, whose foul offspring is\n"\
"cascading to Earth.  Yeah, he's bad. But\n"\
"you know who's worse!\n"\
"\n"\
"Grinning evilly, you check your gear, and\n"\
"get ready to give the bastard a little Hell\n"\
"of your own making!"

// after map 30

#define P4TEXT \
"The Gatekeeper's evil face is splattered\n"\
"all over the place.  As its tattered corpse\n"\
"collapses, an inverted Gate forms and\n"\
"sucks down the shards of the last\n"\
"prototype Accelerator, not to mention the\n"\
"few remaining demons.  You're done. Hell\n"\
"has gone back to pounding bad dead folks \n"\
"instead of good live ones.  Remember to\n"\
"tell your grandkids to put a rocket\n"\
"launcher in your coffin. If you go to Hell\n"\
"when you die, you'll need it for some\n"\
"final cleaning-up ..."

// before map 31

#define P5TEXT \
"You've found the second-hardest level we\n"\
"got. Hope you have a saved game a level or\n"\
"two previous.  If not, be prepared to die\n"\
"aplenty. For master marines only."

// before map 32

#define P6TEXT \
"Betcha wondered just what WAS the hardest\n"\
"level we had ready for ya?  Now you know.\n"\
"No one gets out alive."


#define T1TEXT \
"You've fought your way out of the infested\n"\
"experimental labs.   It seems that UAC has\n"\
"once again gulped it down.  With their\n"\
"high turnover, it must be hard for poor\n"\
"old UAC to buy corporate health insurance\n"\
"nowadays..\n"\
"\n"\
"Ahead lies the military complex, now\n"\
"swarming with diseased horrors hot to get\n"\
"their teeth into you. With luck, the\n"\
"complex still has some warlike ordnance\n"\
"laying around."


#define T2TEXT \
"You hear the grinding of heavy machinery\n"\
"ahead.  You sure hope they're not stamping\n"\
"out new hellspawn, but you're ready to\n"\
"ream out a whole herd if you have to.\n"\
"They might be planning a blood feast, but\n"\
"you feel about as mean as two thousand\n"\
"maniacs packed into one mad killer.\n"\
"\n"\
"You don't plan to go down easy."


#define T3TEXT \
"The vista opening ahead looks real damn\n"\
"familiar. Smells familiar, too -- like\n"\
"fried excrement. You didn't like this\n"\
"place before, and you sure as hell ain't\n"\
"planning to like it now. The more you\n"\
"brood on it, the madder you get.\n"\
"Hefting your gun, an evil grin trickles\n"\
"onto your face. Time to take some names."

#define T4TEXT \
"Suddenly, all is silent, from one horizon\n"\
"to the other. The agonizing echo of Hell\n"\
"fades away, the nightmare sky turns to\n"\
"blue, the heaps of monster corpses start \n"\
"to evaporate along with the evil stench \n"\
"that filled the air. Jeeze, maybe you've\n"\
"done it. Have you really won?\n"\
"\n"\
"Something rumbles in the distance.\n"\
"A blue light begins to glow inside the\n"\
"ruined skull of the demon-spitter."


#define T5TEXT \
"What now? Looks totally different. Kind\n"\
"of like King Tut's condo. Well,\n"\
"whatever's here can't be any worse\n"\
"than usual. Can it?  Or maybe it's best\n"\
"to let sleeping gods lie.."


#define T6TEXT \
"Time for a vacation. You've burst the\n"\
"bowels of hell and by golly you're ready\n"\
"for a break. You mutter to yourself,\n"\
"Maybe someone else can kick Hell's ass\n"\
"next time around. Ahead lies a quiet town,\n"\
"with peaceful flowing water, quaint\n"\
"buildings, and presumably no Hellspawn.\n"\
"\n"\
"As you step off the transport, you hear\n"\
"the stomp of a cyberdemon's iron shoe."



//
// Character cast strings f_finale.c
//
#define CC_ZOMBIE	"HOMEM ZUMBI"
#define CC_SHOTGUN	"CAMARADA DA ESCOPETA"
#define CC_HEAVY	"MANO DA ARMA PESADA"
#define CC_IMP	"IMP"
#define CC_DEMON	"DEMÔNIO"
#define CC_LOST	"ALMA PERDIDA"
#define CC_CACO	"CACODEMÔNIO"
#define CC_HELL	"CAVALEIRO INFERNAL"
#define CC_BARON	"BARÃO DO INFERNO"
#define CC_ARACH	"ARACHNOTRON"
#define CC_PAIN	"DOR ELEMENTAL"
#define CC_REVEN	"REVENANT"
#define CC_MANCU	"MANCUBUS"
#define CC_ARCH	"ARCH-VILE"
#define CC_SPIDER	"A ARANHA MESTRE"
#define CC_CYBER	"O CYBERDEMÔNIO"
#define CC_HERO	"NOSSO HERÓI"


#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------


