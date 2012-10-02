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

#ifndef SC_SYSTEM_H
#define SC_SYSTEM_H

extern DatabaseType SD2Database;
extern std::string  strSD2Version;                          //version info: database entry and revision

#define TEXT_SOURCE_RANGE -1000000                          //the amount of entries each text source has available

#define TEXT_SOURCE_TEXT_START      TEXT_SOURCE_RANGE
#define TEXT_SOURCE_TEXT_END        TEXT_SOURCE_RANGE*2 + 1

#define TEXT_SOURCE_CUSTOM_START    TEXT_SOURCE_RANGE*2
#define TEXT_SOURCE_CUSTOM_END      TEXT_SOURCE_RANGE*3 + 1

#define TEXT_SOURCE_GOSSIP_START    TEXT_SOURCE_RANGE*3
#define TEXT_SOURCE_GOSSIP_END      TEXT_SOURCE_RANGE*4 + 1

struct ScriptPointMove
{
    uint32 uiCreatureEntry;
    uint32 uiPointId;
    float  fX;
    float  fY;
    float  fZ;
    uint32 uiWaitTime;
};

struct StringTextData
{
    uint32 uiSoundId;
    uint8  uiType;
    uint32 uiLanguage;
    uint32 uiEmote;
};

#define pSystemMgr SystemMgr::Instance()

class SystemMgr
{
    public:
        SystemMgr();
        ~SystemMgr() {}

        static SystemMgr& Instance();

        //Maps and lists
        typedef UNORDERED_MAP<int32, StringTextData> TextDataMap;
        typedef UNORDERED_MAP<uint32, std::vector<ScriptPointMove> > PointMoveMap;

        //Database
        void LoadVersion();
        void LoadScriptTexts();
        void LoadScriptTextsCustom();
        void LoadScriptGossipTexts();
        void LoadScriptWaypoints();

        //Retrive from storage
        StringTextData const* GetTextData(int32 uiTextId) const
        {
            TextDataMap::const_iterator itr = m_mTextDataMap.find(uiTextId);

            if (itr == m_mTextDataMap.end())
                return NULL;

            return &itr->second;
        }

        std::vector<ScriptPointMove> const &GetPointMoveList(uint32 uiCreatureEntry) const
        {
            static std::vector<ScriptPointMove> vEmpty;

            PointMoveMap::const_iterator itr = m_mPointMoveMap.find(uiCreatureEntry);

            if (itr == m_mPointMoveMap.end())
                return vEmpty;

            return itr->second;
        }

    protected:
        TextDataMap     m_mTextDataMap;                     //additional data for text strings
        PointMoveMap    m_mPointMoveMap;                    //coordinates for waypoints
};

#endif
