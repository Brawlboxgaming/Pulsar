#include <kamek.hpp>

namespace Pulsar {
namespace Audio {
//disable TF music delay
kmWrite16(0x80711FE8, 0x00004800);
kmWrite16(0x80712024, 0x00004800);
kmWrite16(0x8071207C, 0x00004800);
kmWrite16(0x807120B8, 0x00004800);

//disable tf music reset
kmWrite32(0x80719920, 0x48000010);

//disable THP and demo by blring SingleSoundPlayer::CalcTitlePageNext
kmWrite32(0x806fa738, 0x4e800020);
}//namespace Audio
}//namespace Pulsar
