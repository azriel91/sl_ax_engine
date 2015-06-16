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

#include <cstdio>

#include "StartupActivity.h"

namespace sl {
namespace ax {
namespace engine {

StartupActivity::StartupActivity() {
}

StartupActivity::~StartupActivity() {
}

StartupActivity::ExitCode StartupActivity::run() {
	printf("reading from stdin:\n");
	char str[80];
	scanf("%79s",str);
	return ExitCode::SUCCESS;
}

} /* namespace engine */
} /* namespace ax */
} /* namespace sl */
