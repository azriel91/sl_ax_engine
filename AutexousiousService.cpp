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

#include "AutexousiousService.h"
#include "impl/StartupActivity.h"

namespace sl {
namespace ax {
namespace engine {

AutexousiousService::AutexousiousService() :
		app(std::unique_ptr<sl::core::application::Application>(createApplication())) {
}

AutexousiousService::~AutexousiousService() {
}

const int AutexousiousService::runApplication() {
	return this->app->run();
}

std::unique_ptr<sl::core::application::Application> AutexousiousService::createApplication() {
	sl::core::application::ActivityPointer startupActivity(new sl::ax::engine::StartupActivity());

	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(startupActivity);

	auto app = new sl::core::application::Application(activityStack);
	return std::unique_ptr<sl::core::application::Application>(app);
}

} /* namespace engine */
} /* namespace ax */
} /* namespace sl */
