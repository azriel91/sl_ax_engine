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

#ifndef __SL_AX_ENGINE__AUTEXOUSIOUSENGINEACTIVATOR_H
#define __SL_AX_ENGINE__AUTEXOUSIOUSENGINEACTIVATOR_H

#include <memory>

#include <azriel/cppmicroservices/core/include/usModuleActivator.h>
#include <azriel/cppmicroservices/core/include/usModuleContext.h>
#include <azriel/cppmicroservices/core/include/usServiceTracker.h>

#include "../AutexousiousService.h"
#include "StartupActivityService.h"

US_USE_NAMESPACE

namespace sl {
namespace ax {
namespace engine {

class AutexousiousEngineActivator : public ModuleActivator {
private:
	std::unique_ptr<AutexousiousService> autexousiousService;
	std::unique_ptr<StartupActivityService> startupActivityService;

private:
	void Load(ModuleContext* context);
	void Unload(ModuleContext* context);

	AutexousiousService* createAutexousiousService(ModuleContext* context);
};

} /* namespace engine */
} /* namespace ax */
} /* namespace sl */

US_EXPORT_MODULE_ACTIVATOR(sl::ax::engine::AutexousiousEngineActivator)

#endif /* __SL_AX_ENGINE__AUTEXOUSIOUSENGINEACTIVATOR_H */
