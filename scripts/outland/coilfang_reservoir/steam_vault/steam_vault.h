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

#ifndef DEF_STEAM_VAULT_H
#define DEF_STEAM_VAULT_H

enum
{
    MAX_ENCOUNTER                   = 3,

    TYPE_HYDROMANCER_THESPIA        = 0,
    TYPE_MEKGINEER_STEAMRIGGER      = 1,
    TYPE_WARLORD_KALITHRESH         = 2,

    NPC_NAGA_DISTILLER              = 17954,
    NPC_STEAMRIGGER                 = 17796,
    NPC_KALITHRESH                  = 17798,
    //NPC_THESPIA                   = 17797,

    GO_MAIN_CHAMBERS_DOOR           = 183049,
    GO_ACCESS_PANEL_HYDRO           = 184125,
    GO_ACCESS_PANEL_MEK             = 184126,
};

class MANGOS_DLL_DECL instance_steam_vault : public ScriptedInstance
{
    public:
        instance_steam_vault(Map* pMap);

        void Initialize();

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void OnCreatureDeath(Creature* pCreature);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        GuidList m_lNagaDistillerGuidList;
};

#endif
