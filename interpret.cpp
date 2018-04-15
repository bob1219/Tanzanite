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
#include <fstream>
#include <iterator>
#include <algorithm>

// boost
#include <boost/tokenizer.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;
using namespace boost;

void tanzanite::interpret(const wstring& filename)
{
	using wseparator = char_separator<wchar_t, char_traits<wchar_t>>;
	using wtokenizer = tokenizer<wseparator, wstring::const_iterator, wstring>;

	wifstream file;
	file.imbue(locale{""});
	file.open(filename);
	if(file.fail())
		throw tanzanite::exception{L"failed open file"};

	wtokenizer LineSpliter{wstring{istreambuf_iterator{file}, istreambuf_iterator{}}, wseparator{L"\n"}}
	for(const auto& line: vector<wstring>{begin(LineSpliter), end(LineSpliter)})
	{
		wtokenizer Tokenizer{line, wseparator{L"", L"()\"'"}};
		vector<wstring> tokens{begin(Tokenizer), end(Tokenizer)};
		try
		{
			if(tokens.at(0) == L"print")
			{
				wstring s;
				if(tokens.at(1) == L"(")
					if(tokens.at(2) == L"'" || tokens.at(2) == L"\"")
					{
						if(tokens.size() < 4)
							throw tanzanite::exception{L"invalid source-code"};

						auto i{3};
						for(const auto& token: vector<wstring>{begin(tokens) + 3, end(tokens)})
						{
							if(token == tokens.at(2))
								break;
							s += token;
							++i;
						}

						if(tokens.at(i) == L")" && i + 1 < tokens.size())
							throw tanzanite::exception{L"invalid source-code"};

						wcout << s;
					}
					else
						throw tanzanite::exception{L"invalid source-code"};
				else
					throw tanzanite::exception{L"invalid source-code"};
			}
			else
				throw tanzanite::exception{L"invalid source-code"};
		}
		catch(out_of_range)
		{
			throw tanzanite::exception{L"invalid source-code"};
		}
	}
}
