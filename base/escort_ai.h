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

#ifndef SC_ESCORTAI_H
#define SC_ESCORTAI_H

struct Escort_Waypoint
{
    Escort_Waypoint(uint32 uiId, float fX, float fY, float fZ, uint32 uiWaitTime) :
        uiId(uiId),
        fX(fX),
        fY(fY),
        fZ(fZ),
        uiWaitTime(uiWaitTime)
    {}

    uint32 uiId;
    float  fX;
    float  fY;
    float  fZ;
    uint32 uiWaitTime;
};

enum EscortState
{
    STATE_ESCORT_NONE       = 0x000,                        //nothing in progress
    STATE_ESCORT_ESCORTING  = 0x001,                        //escort are in progress
    STATE_ESCORT_RETURNING  = 0x002,                        //escort is returning after being in combat
    STATE_ESCORT_PAUSED     = 0x004                         //will not proceed with waypoints before state is removed
};

struct MANGOS_DLL_DECL npc_escortAI : public ScriptedAI
{
public:
    explicit npc_escortAI(Creature* pCreature);
    ~npc_escortAI() {}

    void GetAIInformation(ChatHandler& reader);

    virtual void Aggro(Unit*);

    virtual void Reset() = 0;

    // CreatureAI functions
    bool IsVisible(Unit*) const;

    void AttackStart(Unit*);

    void EnterCombat(Unit*);

    void MoveInLineOfSight(Unit*);

    void JustDied(Unit*);

    void JustRespawned();

    void EnterEvadeMode();

    void UpdateAI(const uint32);                        //the "internal" update, calls UpdateEscortAI()
    virtual void UpdateEscortAI(const uint32);          //used when it's needed to add code in update (abilities, scripted events, etc)

    void MovementInform(uint32, uint32);

    // EscortAI functions
    //void AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs = 0);

    virtual void WaypointReached(uint32 uiPointId) = 0;
    virtual void WaypointStart(uint32 uiPointId) {}

    void Start(bool bRun = false, const Player* pPlayer = NULL, const Quest* pQuest = NULL, bool bInstantRespawn = false, bool bCanLoopPath = false);

    void SetRun(bool bRun = true);
    void SetEscortPaused(bool uPaused);

    bool HasEscortState(uint32 uiEscortState) { return (m_uiEscortState & uiEscortState); }

    // update current point
    void SetCurrentWaypoint(uint32 uiPointId);

protected:
    Player* GetPlayerForEscort() { return m_creature->GetMap()->GetPlayer(m_playerGuid); }
    virtual void JustStartedEscort() {}

private:
    bool AssistPlayerInCombat(Unit* pWho);
    bool IsPlayerOrGroupInRange();
    bool MoveToNextWaypoint();
    void FillPointMovementListForCreature();

    void AddEscortState(uint32 uiEscortState) { m_uiEscortState |= uiEscortState; }
    void RemoveEscortState(uint32 uiEscortState) { m_uiEscortState &= ~uiEscortState; }

    ObjectGuid m_playerGuid;
    uint32 m_uiWPWaitTimer;
    uint32 m_uiPlayerCheckTimer;
    uint32 m_uiEscortState;

    const Quest* m_pQuestForEscort;                     //generally passed in Start() when regular escort script.

    std::list<Escort_Waypoint> WaypointList;
    std::list<Escort_Waypoint>::iterator CurrentWP;

    bool m_bIsRunning;                                  //all creatures are walking by default (has flag SPLINEFLAG_WALKMODE)
    bool m_bCanInstantRespawn;                          //if creature should respawn instantly after escort over (if not, database respawntime are used)
    bool m_bCanReturnToStart;                           //if creature can walk same path (loop) without despawn. Not for regular escort quests.
};
#endif
