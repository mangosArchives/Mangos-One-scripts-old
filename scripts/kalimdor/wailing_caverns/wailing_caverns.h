/*
 * Copyright (C) 2006-2012 ScriptDev2 <http://www.scriptdev2.com/>
 *
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

#ifndef DEF_WAILING_CAVERNS_H
#define DEF_WAILING_CAVERNS_H

enum
{
    MAX_ENCOUNTER   = 6,

    TYPE_ANACONDRA  = 0,
    TYPE_COBRAHN    = 1,
    TYPE_PYTHAS     = 2,
    TYPE_SERPENTIS  = 3,
    TYPE_DISCIPLE   = 4,
    TYPE_MUTANUS    = 5,

    NPC_NARALEX     = 3679,
    NPC_DISCIPLE    = 3678,

    SAY_INTRO       = -1043000,                             // Say when the first 4 encounter are DONE

    GO_MYSTERIOUS_CHEST     = 180055,                       // used for quest 7944; spawns in the instance only if one of the players has the quest

    QUEST_FORTUNE_AWAITS    = 7944,
};

class MANGOS_DLL_DECL instance_wailing_caverns : public ScriptedInstance
{
    public:
        instance_wailing_caverns(Map* pMap);
        ~instance_wailing_caverns() {}

        void Initialize();

        void OnPlayerEnter(Player* pPlayer);
        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

    protected:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;
};
#endif
