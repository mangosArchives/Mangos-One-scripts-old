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

#ifndef DEF_SCARLETM_H
#define DEF_SCARLETM_H

enum
{
    MAX_ENCOUNTER                   = 1,

    TYPE_MOGRAINE_AND_WHITE_EVENT   = 1,

    NPC_MOGRAINE                    = 3976,
    NPC_WHITEMANE                   = 3977,
    NPC_VORREL                      = 3981,
    NPC_INTERROGATOR_VISHAS         = 3983,

    GO_WHITEMANE_DOOR               = 104600,

    SAY_TRIGGER_VORREL              = -1189015,
};

class MANGOS_DLL_DECL instance_scarlet_monastery : public ScriptedInstance
{
    public:
        instance_scarlet_monastery(Map* pMap);

        void Initialize();

        void OnCreatureCreate(Creature* pCreature);
        void OnCreatureDeath(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiData);

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
};

#endif
