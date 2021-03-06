#ifndef GAMEGUY_ROM_ROM_HPP
#define GAMEGUY_ROM_ROM_HPP

#include <istream>
#include <memory>
#include <string>
#include <vector>

namespace gameguy {

namespace rom {

class Header;

class Rom
{
  public:
    Rom(const std::shared_ptr<gameguy::rom::Header> header);

    static auto load(std::istream& is) -> std::shared_ptr<Rom>;
    static auto loadFile(const std::string& fileName) -> std::shared_ptr<Rom>;

    auto header() -> std::shared_ptr<gameguy::rom::Header>
    {
        return m_header;
    }

    auto rawData() -> std::vector<gameguy::Byte>
    {
        return m_rawData;
    }

  private:
    std::vector<gameguy::Byte> m_rawData;
    std::shared_ptr<gameguy::rom::Header> m_header;
};

} // namespace rom

} // namespace gameguy

#endif // GAMEGUY_ROM_ROM_HPP
