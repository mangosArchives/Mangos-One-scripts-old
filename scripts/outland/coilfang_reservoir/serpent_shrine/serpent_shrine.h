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

#ifndef DEF_SERPENT_SHRINE_H
#define DEF_SERPENT_SHRINE_H

enum
{
    MAX_ENCOUNTER                   = 6,
    MAX_GENERATOR                   = 4,
    MAX_SPELLBINDERS                = 3,

    TYPE_HYDROSS_EVENT              = 1,
    TYPE_KARATHRESS_EVENT           = 2,
    TYPE_LADYVASHJ_EVENT            = 3,
    TYPE_LEOTHERAS_EVENT            = 4,
    TYPE_MOROGRIM_EVENT             = 5,
    TYPE_THELURKER_EVENT            = 6,
    TYPE_VASHJ_PHASE3_CHECK         = 7,

    TYPE_SHIELDGENERATOR1           = 8,
    TYPE_SHIELDGENERATOR2           = TYPE_SHIELDGENERATOR1 + 1,
    TYPE_SHIELDGENERATOR3           = TYPE_SHIELDGENERATOR1 + 2,
    TYPE_SHIELDGENERATOR4           = TYPE_SHIELDGENERATOR1 + 3,

    //NPC_KARATHRESS                = 21214,
    NPC_CARIBDIS                    = 21964,
    NPC_SHARKKIS                    = 21966,
    NPC_TIDALVESS                   = 21965,
    NPC_LEOTHERAS                   = 21215,
    NPC_LADYVASHJ                   = 21212,
    NPC_GREYHEART_SPELLBINDER       = 21806,
    NPC_HYDROSS_BEAM_HELPER         = 21933,

    SPELL_LEOTHERAS_BANISH          = 37546,
};

class MANGOS_DLL_DECL instance_serpentshrine_cavern : public ScriptedInstance
{
    public:
        instance_serpentshrine_cavern(Map* pMap);

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);
        void OnCreatureEnterCombat(Creature* pCreature);
        void OnCreatureDeath(Creature* pCreature);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        void GetBeamHelpersGUIDList(GuidList &lList) { lList = m_lBeamHelpersGUIDList; }

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 m_auiShieldGenerator[MAX_GENERATOR];
        std::string m_strInstData;

        uint32 m_uiSpellBinderCount;

        GuidList m_lSpellBindersGUIDList;
        GuidList m_lBeamHelpersGUIDList;
};

#endif
