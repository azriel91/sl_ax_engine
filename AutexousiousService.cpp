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

#include <memory>
#include <stack>
#include <cstdio>

#include <azriel/sl_core_application/ActivityRegistration.h>

#include "AutexousiousService.h"
#include "impl/StartupActivity.h"

namespace sl {
namespace ax {
namespace engine {

AutexousiousService::AutexousiousService(
		std::shared_ptr<ServiceTracker<ActivityRegistration> > activityRegistrationTracker) :
		activityRegistrationTracker(activityRegistrationTracker) {
}

AutexousiousService::~AutexousiousService() {
}

const int AutexousiousService::runApplication(const std::string activityName) const {
	this->activityRegistrationTracker->Open();

	auto activityRegistrations = this->activityRegistrationTracker->GetServices();

	sl::core::application::ActivityPointer activityPtr;
	for (auto activityRegistration : activityRegistrations) {

		if (activityName.compare(activityRegistration->getName()) == 0) {
			activityPtr = activityRegistration->getActivity();
		}
	}
	this->activityRegistrationTracker->Close();

	if (activityPtr) {
		printf("Found activity: %s\n", activityName.c_str());
		std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
		activityStack->push(activityPtr);

		std::unique_ptr<sl::core::application::Application> app(new sl::core::application::Application(activityStack));

		const int exitCode = app->run();
		return exitCode;
	}

	printf("Could not find activity: %s\n", activityName.c_str());

	// command line doesn't understand exit codes not in the range 0~255; it will return the exit code % 256.
	return 1; // can't find the activity in services. we should probably wait a while instead of instantly failing
}

} /* namespace engine */
} /* namespace ax */
} /* namespace sl */
