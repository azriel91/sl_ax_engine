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

#include <azriel/sl_core_application/ActivityRegistration.h>

#include "AutexousiousEngineActivator.h"

namespace sl {
namespace ax {
namespace engine {

void AutexousiousEngineActivator::Load(ModuleContext* context) {
	this->autexousiousService.reset(createAutexousiousService(context));
	context->RegisterService<AutexousiousService>(this->autexousiousService.get());

	this->startupActivityService.reset(new StartupActivityService());
	context->RegisterService<ActivityRegistration>(this->startupActivityService.get());
}

void AutexousiousEngineActivator::Unload(ModuleContext* context) {
	// services are automatically unregistered
}

AutexousiousService* AutexousiousEngineActivator::createAutexousiousService(ModuleContext* context) {
	std::shared_ptr<ServiceTracker<ActivityRegistration> > serviceTracker(
			new ServiceTracker<ActivityRegistration>(context));
	return new AutexousiousService(serviceTracker);
}

} /* namespace engine */
} /* namespace ax */
} /* namespace sl */
