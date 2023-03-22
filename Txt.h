#pragma once

#include <cstddef>
#include <iostream>

namespace l1 {
	class Txt;
}

class l1::Txt {
private:
	size_t sz;
	std::string* text;
public:
	Txt();
	Txt(const char* filename);

	Txt(const Txt&);
	Txt& operator=(const Txt&);

	Txt(Txt&&) noexcept;
	Txt& operator=(Txt&&) noexcept;
	size_t size() const;

	~Txt();
};