
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

#pragma once

#include <memory>

namespace spdlog {
class logger;
}

extern thread_local std::shared_ptr<spdlog::logger> gThreadLocalLogger;

class ThreadLogger {
	std::shared_ptr<spdlog::logger> _prev;
public:
	explicit ThreadLogger(std::shared_ptr<spdlog::logger> next);
	~ThreadLogger();

	ThreadLogger(const ThreadLogger&) = delete;
	ThreadLogger& operator=(const ThreadLogger&) = delete;

	ThreadLogger(ThreadLogger&&) = delete;
	ThreadLogger& operator=(ThreadLogger&&) = delete;

	static std::shared_ptr<spdlog::logger> get();
	static void set(std::shared_ptr<spdlog::logger>);
};

#define LOG_TRACE(...)  SPDLOG_LOGGER_TRACE(ThreadLogger::get(), __VA_ARGS__)
#define LOG_DEBUG(...)  SPDLOG_LOGGER_DEBUG(ThreadLogger::get(), __VA_ARGS__)
#define LOG_INFO(...)   SPDLOG_LOGGER_INFO (ThreadLogger::get(), __VA_ARGS__)
#define LOG_WARN(...)   SPDLOG_LOGGER_WARN (ThreadLogger::get(), __VA_ARGS__)
#define LOG_ERROR(...)  SPDLOG_LOGGER_ERROR(ThreadLogger::get(), __VA_ARGS__)
#define LOG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(ThreadLogger::get(), __VA_ARGS__)

