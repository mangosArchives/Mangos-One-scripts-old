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

#ifndef DEF_THE_EYE_H
#define DEF_THE_EYE_H

enum
{
    MAX_ENCOUNTER               = 4,
    MAX_ADVISORS                = 4,

    TYPE_ALAR                   = 0,
    TYPE_SOLARIAN               = 1,
    TYPE_VOIDREAVER             = 2,
    TYPE_KAELTHAS               = 3,

    //NPC_ASTROMANCER           = 18805,
    NPC_KAELTHAS                = 19622,

    NPC_CAPERNIAN               = 20062,
    NPC_SANGUINAR               = 20060,
    NPC_TELONICUS               = 20063,
    NPC_THALADRED               = 20064,

    GO_ARCANE_DOOR_HORIZ_3      = 184325,               // combat doors for Kael
    GO_ARCANE_DOOR_HORIZ_4      = 184324,
    //GO_RAID_DOOR_4            = 184329,               // encounter doors - no longer used since 2.4.0
    //GO_RAID_DOOR_3            = 184327,
    //GO_ARCANE_DOOR_VERT_3     = 184326,
    //GO_ARCANE_DOOR_VERT_4     = 184328,
    GO_KAEL_STATUE_LEFT         = 184597,               // cosmetic objects for Kael encounter
    GO_KAEL_STATUE_RIGHT        = 184596,
    GO_BRIDGE_WINDOW            = 184069,
};

static const uint32 aAdvisors[MAX_ADVISORS] = {NPC_CAPERNIAN, NPC_SANGUINAR, NPC_TELONICUS, NPC_THALADRED};

class MANGOS_DLL_DECL instance_the_eye : public ScriptedInstance
{
    public:
        instance_the_eye(Map* pMap);

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        // No Save or Load needed to current knowledge

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint32 m_uiKaelthasEventPhase;
};

#endif
