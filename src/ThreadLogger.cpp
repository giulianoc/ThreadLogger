/*
 Copyright (C) Giuliano Catrambone (giulianocatrambone@gmail.com)

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
#include <stdexcept>
#include <spdlog/spdlog.h>

#include <utility>

thread_local std::shared_ptr<spdlog::logger> gThreadLocalLogger = nullptr;


ThreadLogger::ThreadLogger(std::shared_ptr<spdlog::logger> next)
		: _prev(gThreadLocalLogger)
{
	gThreadLocalLogger = std::move(next);
}

ThreadLogger::~ThreadLogger()
{
	gThreadLocalLogger = _prev;
}

std::shared_ptr<spdlog::logger> ThreadLogger::get()
{
	if (auto lg = gThreadLocalLogger)
		return lg;
	if (auto def = spdlog::default_logger())
		return def;
	throw std::runtime_error("No logger configured");
}

void ThreadLogger::set(std::shared_ptr<spdlog::logger> logger)
{
	gThreadLocalLogger = std::move(logger);
};
