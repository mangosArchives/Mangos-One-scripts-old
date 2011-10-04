/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Areatrigger_Scripts
SD%Complete: 100
SDComment: Quest support: 6681, 10589/10604
SDCategory: Areatrigger
EndScriptData */

/* ContentData
at_coilfang_waterfall           4591
at_legion_teleporter            4560 Teleporter TO Invasion Point: Cataclysm
at_ravenholdt
at_childrens_week_spot          3546,3547,3548,3552,3549,3550
EndContentData */

#include "precompiled.h"

static uint32 TriggerOrphanSpell[6][3] =
{
    {3546, 14305, 65056},                                   // The Bough of the Eternals
    {3547, 14444, 65059},                                   // Lordaeron Throne Room
    {3548, 14305, 65055},                                   // The Stonewrought Dam
    {3549, 14444, 65058},                                   // Gateway to the Frontier
    {3550, 14444, 65057},                                   // Down at the Docks
    {3552, 14305, 65054}                                    // Spooky Lighthouse
};

bool AreaTrigger_at_childrens_week_spot(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    for (uint8 i = 0; i < 6; ++i)
    {
        if (pAt->id == TriggerOrphanSpell[i][0] &&
            pPlayer->GetMiniPet() && pPlayer->GetMiniPet()->GetEntry() == TriggerOrphanSpell[i][1])
        {
            pPlayer->CastSpell(pPlayer, TriggerOrphanSpell[i][2], true);
            return true;
        }
    }
    return false;
}

/*######
## at_coilfang_waterfall
######*/

enum
{
    GO_COILFANG_WATERFALL   = 184212
};

bool AreaTrigger_at_coilfang_waterfall(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (GameObject* pGo = GetClosestGameObjectWithEntry(pPlayer, GO_COILFANG_WATERFALL, 35.0f))
    {
        if (pGo->getLootState() == GO_READY)
            pGo->UseDoorOrButton();
    }
    return false;
}

/*######
## at_legion_teleporter
######*/

enum
{
    SPELL_TELE_A_TO         = 37387,
    QUEST_GAINING_ACCESS_A  = 10589,

    SPELL_TELE_H_TO         = 37389,
    QUEST_GAINING_ACCESS_H  = 10604
};

bool AreaTrigger_at_legion_teleporter(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pPlayer->isAlive() && !pPlayer->isInCombat())
    {
        if (pPlayer->GetTeam() == ALLIANCE && pPlayer->GetQuestRewardStatus(QUEST_GAINING_ACCESS_A))
        {
            pPlayer->CastSpell(pPlayer, SPELL_TELE_A_TO, false);
            return true;
        }

        if (pPlayer->GetTeam() == HORDE && pPlayer->GetQuestRewardStatus(QUEST_GAINING_ACCESS_H))
        {
            pPlayer->CastSpell(pPlayer, SPELL_TELE_H_TO, false);
            return true;
        }
        return false;
    }
    return false;
}

/*######
## at_ravenholdt
######*/

enum
{
    QUEST_MANOR_RAVENHOLDT  = 6681,
    NPC_RAVENHOLDT          = 13936
};

bool AreaTrigger_at_ravenholdt(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pPlayer->GetQuestStatus(QUEST_MANOR_RAVENHOLDT) == QUEST_STATUS_INCOMPLETE)
        pPlayer->KilledMonsterCredit(NPC_RAVENHOLDT);

    return false;
}

void AddSC_areatrigger_scripts()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "at_childrens_week_spot";
    pNewScript->pAreaTrigger = &AreaTrigger_at_childrens_week_spot;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_coilfang_waterfall";
    pNewScript->pAreaTrigger = &AreaTrigger_at_coilfang_waterfall;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_legion_teleporter";
    pNewScript->pAreaTrigger = &AreaTrigger_at_legion_teleporter;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_ravenholdt";
    pNewScript->pAreaTrigger = &AreaTrigger_at_ravenholdt;
    pNewScript->RegisterSelf();
}
