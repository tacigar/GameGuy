#include "register.hpp"

#include "../config/type.hpp"

namespace gameguy {

namespace cpu {

Register::Register()
        : m_regA((gameguy::Byte)0x01)
        , m_regB((gameguy::Byte)0x00)
        , m_regC((gameguy::Byte)0x13)
        , m_regD((gameguy::Byte)0x00)
        , m_regE((gameguy::Byte)0xD8)
        , m_regF((gameguy::Byte)0xB0)
        , m_regH((gameguy::Byte)0x01)
        , m_regL((gameguy::Byte)0x4D)
        , m_regPC((gameguy::Word)0x0100)
        , m_regSP((gameguy::Word)0xFFFE)
{
}

#define GEN_COMPOUND_REGISTER_ACCESSOR(name1, name2) \
    auto Register::reg##name1##name2() const -> gameguy::Word \
    { return (gameguy::Word)(m_reg##name1 << 8 + m_reg##name2); } \
    auto Register::reg##name1##name2(gameguy::Word value) -> void \
    { \
      m_reg##name1 = (gameguy::Byte)((value & 0xFF00) >> 8);  \
      m_reg##name2 = (gameguy::Byte)(value & 0xFF); \
    }

GEN_COMPOUND_REGISTER_ACCESSOR(A, F);
GEN_COMPOUND_REGISTER_ACCESSOR(B, C);
GEN_COMPOUND_REGISTER_ACCESSOR(D, E);
GEN_COMPOUND_REGISTER_ACCESSOR(H, L);

#undef GEN_COMPOUND_REGISTER_ACCESSOR


} // namespace cpu

} // namespace gameguy
