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
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <exception>
#include <cstring>
#include <memory>

// boost
#include <boost/format.hpp>
#include <boost/system/system_error.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;
using namespace tanzanite;
using namespace boost;

int wmain(int argc, wchar_t** argv)
{
	try
	{
		wcout.imbue(locale{""});
		wcerr.imbue(locale{""});
		wcin.imbue(locale{""});
		setlocale(LC_ALL, "");

		if(argc != 2)
		{
			wcerr << wformat{L"Usage: %1% [filename]"} % argv[0] << endl;
			return EXIT_FAILURE;
		}

		interpret(argc[1]);

		return EXIT_SUCCESS;
	}
	catch(boost::system::system_error& e)
	{
		const auto		mess_c{e.what()};
		const auto		mess_len{strlen(mess_c)};
		unique_ptr<wchar_t[]>	mess{new wchar_t[mess_len + 1]};
		mbstowcs(mess.get(), mess_c, mess_len + 1);

		wcerr << L"error:" << endl;
		wcerr << mess.get() << endl;
		wcerr << wformat{L"(error code: %1%)"} % e.code().value() << endl;
	}
	catch(std::exception& e)
	{
		const auto		mess_c{e.what()};
		const auto		mess_len{strlen(mess_c)};
		unique_ptr<wchar_t[]>	mess{new wchar_t[mess_len + 1]};
		mbstowcs(mess.get(), mess_c, mess_len + 1);

		wcerr << L"error:" << endl;
		wcerr << mess.get() << endl;
	}
	catch(tanzanite::exception& e)
	{
		wcerr << L"error:" << endl;
		wcerr << e.getMessage() << endl;
	}

	return EXIT_FAILURE;
}
