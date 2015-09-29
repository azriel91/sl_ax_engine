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

#ifndef __SL_AUTEXOUSIOUS_ENGINE__AUTEXOUSIOUSSERVICE_H
#define __SL_AUTEXOUSIOUS_ENGINE__AUTEXOUSIOUSSERVICE_H

#include <memory>
#include <string>

#include <azriel/cppmicroservices/core/include/usServiceInterface.h>
#include <azriel/cppmicroservices/core/include/usServiceTracker.h>
#include <azriel/sl_core_application/Application.h>
#include <azriel/sl_core_application/ActivityRegistration.h>

#include "sl_ax_engine/Block.h"

US_USE_NAMESPACE

using sl::core::application::ActivityRegistration;

namespace sl {
namespace ax {
namespace engine {

class SL_AX_ENGINE_EXPORT AutexousiousService {
private:
	std::shared_ptr<ServiceTracker<ActivityRegistration> > activityRegistrationTracker;

public:
	AutexousiousService(std::shared_ptr<ServiceTracker<ActivityRegistration> > activityRegistrationTracker);
	virtual ~AutexousiousService();

	/**
	 * Run the application.
	 *
	 * @param activityName the unique name of the activity to use as the starting activity
	 */
	const int runApplication(const std::string activityName) const;
};

} /* namespace engine */
} /* namespace ax */
} /* namespace sl */

#endif /* __SL_AUTEXOUSIOUS_ENGINE__AUTEXOUSIOUSSERVICE_H */
