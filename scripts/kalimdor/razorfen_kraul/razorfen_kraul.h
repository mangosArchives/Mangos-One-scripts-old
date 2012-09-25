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

#ifndef DEF_RFK_H
#define DEF_RFK_H

enum
{
    MAX_ENCOUNTER     = 1,

    TYPE_AGATHELOS    = 1,

    GO_AGATHELOS_WARD = 21099,

    NPC_WARD_KEEPER   = 4625
};

class MANGOS_DLL_DECL instance_razorfen_kraul : public ScriptedInstance
{
public:
    instance_razorfen_kraul(Map* pMap);
    ~instance_razorfen_kraul() {}

    void Initialize();

    void OnObjectCreate(GameObject* pGo);
    void OnCreatureCreate(Creature* pCreature);

    void SetData(uint32 uiType, uint32 uiData);
    uint32 GetData(uint32 uiType);

    const char* Save() { return m_strInstData.c_str(); }
    void Load(const char* chrIn);

protected:
    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string m_strInstData;

    uint8 m_uiWardKeepersRemaining;
};
#endif
