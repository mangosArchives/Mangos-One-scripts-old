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

#ifndef DEF_ULDAMAN_H
#define DEF_ULDAMAN_H

enum
{
    MAX_ENCOUNTER               = 2,

    TYPE_ALTAR_EVENT            = 1,
    TYPE_ARCHAEDAS              = 2,
    DATA_EVENT_STARTER          = 3,

    GO_TEMPLE_DOOR_UPPER        = 124367,
    GO_TEMPLE_DOOR_LOWER        = 141869,
    GO_ANCIENT_VAULT            = 124369,

    NPC_CUSTODIAN               = 7309,
    NPC_HALLSHAPER              = 7077,
    NPC_GUARDIAN                = 7076,
    NPC_VAULT_WARDER            = 10120,
    NPC_STONE_KEEPER            = 4857,

    PHASE_ARCHA_1               = 1,
    PHASE_ARCHA_2               = 2,
    PHASE_ARCHA_3               = 3,

    SPELL_STONED                = 10255,

    EVENT_ID_ALTAR_KEEPER       = 2228,                     // spell 11568
    EVENT_ID_ALTAR_ARCHAEDAS    = 2268                      // spell 10340
};

class MANGOS_DLL_DECL instance_uldaman : public ScriptedInstance
{
    public:
        instance_uldaman(Map* pMap);
        ~instance_uldaman() {}

        void Initialize();

        void OnObjectCreate(GameObject* pGo);
        void OnCreatureCreate(Creature* pCreature);

        void Update(uint32 uiDiff);

        void SetData(uint32 uiType, uint32 uiData);
        void SetData64(uint32 uiData, uint64 uiGuid);
        uint32 GetData(uint32 uiType);
        uint64 GetData64(uint32 uiData);

        void StartEvent(uint32 uiEventId, Player* pPlayer);

        void DoResetKeeperEvent();

        Creature* GetClosestDwarfNotInCombat(Creature* pSearcher, uint32 uiPhase);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

    protected:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        ObjectGuid m_playerGuid;

        uint32 m_uiKeeperCooldown;
        uint32 m_uiStoneKeepersFallen;

        GuidList m_lWardens;
        std::map<ObjectGuid, bool> m_mKeeperMap;
};

#endif
