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

#ifndef DEF_ZULFARRAK_H
#define DEF_ZULFARRAK_H

enum
{
    MAX_ENCOUNTER                   = 8,

    TYPE_VELRATHA                   = 0,
    TYPE_GAHZRILLA                  = 1,
    TYPE_ANTUSUL                    = 2,
    TYPE_THEKA                      = 3,
    TYPE_ZUMRAH                     = 4,
    TYPE_NEKRUM                     = 5,
    TYPE_SEZZZIZ                    = 6,
    TYPE_CHIEF_SANDSCALP            = 7,

    NPC_VELRATHA                    = 7795,
    NPC_GAHZRILLA                   = 7273,
    NPC_ANTUSUL                     = 8127,
    NPC_THEKA                       = 7272,
    NPC_ZUMRAH                      = 7271,
    NPC_NEKRUM                      = 7796,
    NPC_SEZZZIZ                     = 7275,
    NPC_CHIEF_SANDSCALP             = 7267,

    AREATRIGGER_ANTUSUL             = 1447,
};

class MANGOS_DLL_DECL instance_zulfarrak : public ScriptedInstance
{
public:
    instance_zulfarrak(Map* pMap);
    ~instance_zulfarrak() {}

    void Initialize();

    void OnCreatureEnterCombat(Creature* pCreature);
    void OnCreatureEvade(Creature* pCreature);
    void OnCreatureDeath(Creature* pCreature);

    void OnCreatureCreate(Creature* pCreature);

    void SetData(uint32 uiType, uint32 uiData);
    uint32 GetData(uint32 uiType);

    const char* Save() { return m_strInstData.c_str(); }
    void Load(const char* chrIn);

protected:
    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string m_strInstData;
};

#endif
