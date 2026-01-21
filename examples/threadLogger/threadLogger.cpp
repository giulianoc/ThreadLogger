
/*
 Copyright (C) Giuliano Catrambone (giuliano.catrambone@catrasoftware.it)

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either
 version 2 of the License, or (at your option) any later
 version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 Commercial use other than under the terms of the GNU General Public
 License is allowed only after express negotiation of conditions
 with the authors.
*/

#include "ThreadLogger.h"
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "ThreadLogger.h"

using namespace std;

int main()
{
	// Per usare un log diverso dal default logger per un thread specifico
	{
		const auto threadLog = spdlog::stdout_color_mt("aaaa");
		ThreadLogger requestLog(threadLog);

		LOG_INFO("Test using the default logger");
	}

	// uso del default global logger
	LOG_INFO("Test using the default logger");
}
