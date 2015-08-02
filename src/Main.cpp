/*
 *******************************************************************************
 *
 * Purpose: Main function.
 *
 *******************************************************************************
 * Copyright Monstrenyatko 2014.
 *
 * Distributed under the MIT License.
 * (See accompanying file LICENSE or copy at http://opensource.org/licenses/MIT)
 *******************************************************************************
 */

/* Internal Includes */
#include "Application.h"
#include "Logger.h"
#include "LogManager.h"
/* External Includes */
/* System Includes */


int main(int argc, char* argv[]) {
	Utils::Logger log("Main");
	try {
		Application::initialize();
		//testThread.start();
		Application::get().run();
		//testThread.stop();
		Application::destroy();
	} catch (std::exception& e) {
		*log.error() << e.what();
	}
	*log.info() << "EXIT";
	// It was the last log => flush everything in logger
	Utils::LogManager::destroy();
	return 0;
}
