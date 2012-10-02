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

#ifndef DEF_GRUULS_LAIR_H
#define DEF_GRUULS_LAIR_H

enum
{
    MAX_ENCOUNTER                   = 2,
    MAX_COUNCIL                     = 5,

    // Encounter Status
    TYPE_MAULGAR_EVENT              = 0,
    TYPE_GRUUL_EVENT                = 1,

    GO_PORT_GRONN_1                 = 183817,               // 184468 not in use
    GO_PORT_GRONN_2                 = 184662,

    // NPC GUIDs
    NPC_MAULGAR                     = 18831,
    //NPC_BLINDEYE                  = 18836,
    //NPC_KIGGLER                   = 18835,
    //NPC_KROSH                     = 18832,
    //NPC_OLM                       = 18834,
};

class MANGOS_DLL_DECL instance_gruuls_lair : public ScriptedInstance
{
    public:
        instance_gruuls_lair(Map *pMap);

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strSaveData.c_str(); }
        void Load(const char* chrIn);

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strSaveData;

        uint8 m_uiCouncilMembersDied;
};

#endif
