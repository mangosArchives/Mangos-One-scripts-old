/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ONYXIA_H
#define DEF_ONYXIA_H

enum
{
    TYPE_ONYXIA                 = 0,

    // Special data fields for Onyxia
    DATA_LIFTOFF                = 4,
    DATA_PLAYER_TOASTED         = 5,

    NPC_ONYXIA_WHELP            = 11262,
    NPC_ONYXIA_TRIGGER          = 12758,
};

class MANGOS_DLL_DECL instance_onyxias_lair : public ScriptedInstance
{
    public:
        instance_onyxias_lair(Map* pMap);
        ~instance_onyxias_lair() {}

        void Initialize();

        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);

        void SetData(uint32 uiType, uint32 uiData);

    protected:
        uint32 m_uiEncounter;

        time_t m_tPhaseTwoStart;
};

#endif
