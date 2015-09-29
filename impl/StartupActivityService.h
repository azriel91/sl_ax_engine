/*=============================================================================

	Library: Silver

	Copyright (c) Azriel Hoh

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

=============================================================================*/

#ifndef __SL_AX_ENGINE__STARTUPACTIVITYSERVICE_H
#define __SL_AX_ENGINE__STARTUPACTIVITYSERVICE_H

#include <string>

#include <azriel/sl_core_application/Activity.h>
#include <azriel/sl_core_application/ActivityRegistration.h>

#include "sl_ax_engine/Block.h"

namespace sl {
namespace ax {
namespace engine {

class SL_AX_ENGINE_EXPORT StartupActivityService : public sl::core::application::ActivityRegistration {
private:
	sl::core::application::ActivityPointer startupActivity;

public:
	StartupActivityService();
	virtual ~StartupActivityService();

	std::string getName() const override;
	sl::core::application::ActivityPointer getActivity() const override;
};

} /* namespace engine */
} /* namespace ax */
} /* namespace sl */

#endif /* __SL_AX_ENGINE__STARTUPACTIVITYSERVICE_H */
