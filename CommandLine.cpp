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

// standard library
#include <string>
#include <iostream>

// boost
#include <boost/format.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;
using namespace boost;

void tanzanite::CommandLine()
{
	wcout << L"Tanzanite(shell mode)" << endl;
	wcout << L"Copyright 2018 Daiki Yoshida. All rights reserved." << endl;
	wcout << L"This program comes with ABSOLUTELY NO WARRANTY." << endl;
	wcout << L"This is free software, and you are welcome to redistribute it" << endl;
	wcout << L"under centain conditions." << endl;
	wcout << endl;

	while(true)
	{
		wstring command;
		wcout << L'>';
		getline(wcin, command);

		try { CommandProcess(command); }
		catch(tanzanite::exception& e) { wcerr << wformat{L"error: %1%."} % e.getMessage() << endl; }

		wcout << endl;
	}
}
