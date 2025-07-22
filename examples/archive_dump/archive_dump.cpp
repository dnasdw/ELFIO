/*
Copyright (C) 2025-present by Serge Lamikhov-Center

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <ario/ario.hpp>

using namespace ARIO;

int main( int argc, char** argv )
{
    if ( argc != 2 ) {
        printf( "Usage: archive_dump <file_name>\n" );
        return 1;
    }

    ario archive;

    auto result = archive.load( argv[1] );
    if ( !result.ok() ) {
        std::cerr << "Error loading archive: " << result.what() << std::endl;
        return 1;
    }

    for ( const auto& member : archive.members ) {
        std::cout << "Member: " << std::setw( 40 ) << std::left << member.name
                  << " Size: " << std::setw( 8 ) << std::right << member.size
                  << " Mode: " << std::setw( 3 ) << std::oct << member.mode
                  << " Data: " << member.data().substr( 1, 3 ) << std::endl;
        std::vector<std::string> symbols;
        result = archive.get_symbols_for_member( member, symbols );
        if ( result.ok() ) {
            auto first_time = true;
            for ( const auto& symbol : symbols ) {
                if ( first_time ) {
                    std::cout << "    ";
                    first_time = false;
                }
                else {
                    std::cout << ", ";
                }
                std::cout << symbol;
            }
            if ( !first_time ) {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
