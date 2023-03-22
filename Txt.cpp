#include "Txt.h"
#include <fstream>

using namespace l1;

Txt::Txt() :
	sz(0), text(nullptr) {}

Txt::Txt(const char* filename) {
	sz = 0;
	text = nullptr;
	std::ifstream ifs(filename);
	size_t tmp_sz = 0;
	std::string tmp_text;
	while(ifs >> tmp_text) {
		tmp_sz++;
	}
	if(ifs.eof()) {
		sz = tmp_sz;
		text = new std::string[sz];
		ifs.clear();
		ifs.seekg(0);
		for(size_t i = 0; i < sz; i++) {
			ifs >> text[i];
		}
	}
	ifs.close();
}


Txt::Txt(const Txt& obj) {
	sz = obj.sz;
	text = new std::string[sz];
	std::copy(obj.text, obj.text + sz, text);
}

Txt& Txt::operator=(const Txt& obj) {
	sz = obj.sz;
	text = new std::string[sz];
	std::copy(obj.text, obj.text + sz, text);
	return *this;
}

Txt::Txt(Txt&& obj) noexcept {
	sz = obj.sz;
	text = obj.text;
	obj.text = nullptr;
	obj.sz = 0;
}

Txt& Txt::operator=(Txt&& obj) noexcept {
	sz = obj.sz;
	text = obj.text;
	obj.text = nullptr;
	obj.sz = 0;
	return *this;
}

size_t Txt::size() const {
	return sz;
}

Txt::~Txt() {
	delete[] text;
	text = nullptr;
	sz = 0;
}