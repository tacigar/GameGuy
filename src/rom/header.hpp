#ifndef GAMEGUY_ROM_HEADER_HPP
#define GAMEGUY_ROM_HEADER_HPP

#include <cstddef>
#include <string>

namespace gameguy {

namespace rom {

class Header
{
  private:
    std::size_t m_romSize;
    std::size_t m_ramSize;
    std::string m_title;
    std::string m_manufacturerCode;
    bool m_cgbFlag;
    bool m_sgbFlag;
};

} // namespace rom

} // namespace gameguy

#endif // GAMEGUY_ROM_HEADER_HPP
