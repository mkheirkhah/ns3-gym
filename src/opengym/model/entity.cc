/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2018 Piotr Gawlowicz
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Piotr Gawlowicz <gawlowicz.p@gmail.com>
 *
 */

#include <algorithm>
#include "ns3/log.h"
#include "ns3/type-name.h"
#include "entity.h"
#include "container.h"
#include "spaces.h"
#include "opengym.h"

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (OpenGymEntity);

NS_LOG_COMPONENT_DEFINE ("OpenGymEntity");

TypeId
OpenGymEntity::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::OpenGymEntity")
    .SetParent<Object> ()
    .SetGroupName ("OpenGym")
    ;
  return tid;
}

OpenGymEntity::OpenGymEntity()
{
  NS_LOG_FUNCTION (this);
}

OpenGymEntity::~OpenGymEntity ()
{
  NS_LOG_FUNCTION (this);
}

void
OpenGymEntity::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
}

void
OpenGymEntity::DoInitialize (void)
{
  NS_LOG_FUNCTION (this);
}

void
OpenGymEntity::SetOpenGymEnv(Ptr<OpenGymEnv> openGymEnv)
{
  NS_LOG_FUNCTION (this);
  m_openGymEnv = openGymEnv;
  openGymEnv->SetGetActionSpaceCb( MakeCallback (&OpenGymEntity::GetActionSpace, this) );
  openGymEnv->SetGetObservationSpaceCb( MakeCallback (&OpenGymEntity::GetObservationSpace, this) );
  openGymEnv->SetGetGameOverCb( MakeCallback (&OpenGymEntity::GetGameOver, this) );
  openGymEnv->SetGetObservationCb( MakeCallback (&OpenGymEntity::GetObservation, this) );
  openGymEnv->SetGetRewardCb( MakeCallback (&OpenGymEntity::GetReward, this) );
  openGymEnv->SetGetExtraInfoCb( MakeCallback (&OpenGymEntity::GetExtraInfo, this) );
  openGymEnv->SetExecuteActionsCb( MakeCallback (&OpenGymEntity::ExecuteActions, this) );
}

void
OpenGymEntity::Notify()
{
  NS_LOG_FUNCTION (this);
  if (m_openGymEnv)
  {
    m_openGymEnv->Notify(this);
  }
}

}