
#include "Charset.h"

namespace msdf_atlas {

static Charset createAsciiCharset() {
    Charset ascii;
    for (unicode_t cp = 0x20; cp < 0x7f; ++cp)
        ascii.add(cp);
    return ascii;
}

const Charset Charset::ASCII = createAsciiCharset();

void Charset::add(unicode_t cp) {
    codepoints.push_back(cp);
}

void Charset::remove(unicode_t cp) {
	auto r = std::find( std::begin(codepoints), std::end(codepoints), cp );
	if ( r != codepoints.end() )
	{
		codepoints.erase( r );
	}
}

size_t Charset::size() const {
    return codepoints.size();
}

bool Charset::empty() const {
    return codepoints.empty();
}

std::vector<unicode_t>::const_iterator Charset::begin() const {
    return codepoints.begin();
}

std::vector<unicode_t>::const_iterator Charset::end() const {
    return codepoints.end();
}

}
