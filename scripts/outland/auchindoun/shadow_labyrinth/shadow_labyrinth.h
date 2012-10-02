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

#ifndef DEF_SHADOW_LABYRINTH_H
#define DEF_SHADOW_LABYRINTH_H

enum
{
    MAX_ENCOUNTER           = 5,

    TYPE_HELLMAW            = 1,
    TYPE_OVERSEER           = 2,
    TYPE_INCITER            = 3,
    TYPE_VORPIL             = 4,
    TYPE_MURMUR             = 5,

    NPC_HELLMAW             = 18731,
    NPC_VORPIL              = 18732,
    NPC_FEL_OVERSEER        = 18796,

    GO_REFECTORY_DOOR       = 183296,                       //door opened when blackheart the inciter dies
    GO_SCREAMING_HALL_DOOR  = 183295,                       //door opened when grandmaster vorpil dies

    SAY_HELLMAW_INTRO       = -1555000,

    SPELL_BANISH            = 30231,
};

class MANGOS_DLL_DECL instance_shadow_labyrinth : public ScriptedInstance
{
    public:
        instance_shadow_labyrinth(Map* pMap);

        void Initialize();

        void OnObjectCreate(GameObject* pGo);
        void OnCreatureCreate(Creature* pCreature);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        uint32 m_uiFelOverseerCount;
};

#endif
