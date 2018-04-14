// Copyright 2018 Daiki Yoshida. All rights reserved.
//
// This file is part of Tanzanite.
//
// Tanzanite is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tanzanite is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Generaal Public License
// along with Tanzanite. If not, see <http://www.gnu.org/licenses/>.

#ifndef FUNCTION_H
#define FUNCTION_H

// standard library
#include <string>

namespace tanzanite
{
	void interpret(const std::wstring& filename);
	void CommandProcess(const std::wstring& command);
}

#endif
