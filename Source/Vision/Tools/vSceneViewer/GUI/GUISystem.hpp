/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef GUI_SYSTEM_HPP_INCLUDED
#define GUI_SYSTEM_HPP_INCLUDED

#if defined(EMULATE_DEVICE) || !defined(WIN32) || defined(_VISION_WINRT)

#include <Vision/Runtime/EnginePlugins/VisionEnginePlugin/GUI/VMenuIncludes.hpp>

class SceneViewerMainMenu;
typedef VSmartPtr<SceneViewerMainMenu> SceneViewerMainMenuPtr;

class SceneViewerMainMenu : public VDialog
{
public:
  SceneViewerMainMenu();
  ~SceneViewerMainMenu();
  VOVERRIDE void OnInitDialog();
  VOVERRIDE void OnTick(float dtime);

  VOVERRIDE void OnItemClicked(VMenuEventDataObject *pEvent);
  VOVERRIDE void OnValueChanged(VItemValueChangedEvent *pEvent);

  void ToggleView(VisBaseEntity_cl * pCamera);
  bool IsLoadNewScene() {return m_bLoadNewScene;}
  bool IsRefreshSceneListSet() { return m_bRefreshSceneList; }
  void ResetLoadNewScene() {m_bLoadNewScene=false;}
  void ResetRefreshSceneList() { m_bRefreshSceneList = false; }
  const char *GetScenePath() const {return ( m_pSceneList->GetSelectedItem() != NULL ) ? ( m_pSceneList->GetSelectedItem()->m_sTooltipText.AsChar() ) : NULL; }

protected:
  #define EMPTY
  V_DECLARE_SERIAL( SceneViewerMainMenu, EMPTY )
  VOVERRIDE void Serialize( VArchive &ar ) {}

  bool m_bButtonBHit;
  bool m_bButtonXHit;

  bool m_bLoadNewScene;
  bool m_bRefreshSceneList;
  VListControl *m_pSceneList;
  VPushButton* m_pLoadButton;
  VPushButton* m_pContinueButton;
  VPushButton* m_pRefreshButton;

  VisBaseEntity_cl* m_pCamera;
};

#endif

#endif // GUI_SYSTEM_HPP_INCLUDED

/*
 * Havok SDK - Base file, BUILD(#20131019)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2013
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available from salesteam@havok.com.
 * 
 */
