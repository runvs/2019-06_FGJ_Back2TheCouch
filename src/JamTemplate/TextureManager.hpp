#ifndef JAMTEMPLATE_TEXTUREMANAGER_HPP_INCLUDEGUARD
#define JAMTEMPLATE_TEXTUREMANAGER_HPP_INCLUDEGUARD

#include <SFML/Graphics.hpp>
#include <assert.h>
#include <map>
#include <string>
#include <vector>

#include "SplitString.hpp"
#include "SpriteFunctions.hpp"

namespace JamTemplate {
class TextureManager {
public:
    TextureManager() = delete;

    static sf::Texture& get(std::string const& str)
    {
        if (m_textures.count(str) == 0) {
            if (str.at(0) != '#') {
                m_textures[str].loadFromFile(str);
            } else // special type of images
            {
                SplitString ss { str };
                auto ssv = ss.split('#');
                if (ssv.at(0) == "b") {
                    unsigned int w = std::stoul(ssv.at(1));
                    unsigned int h = std::stoul(ssv.at(2));
                    sf::Image img {};
                    SpriteFunctions::makeButtonImage(img, w, h);
                    m_textures[str].loadFromImage(img);
                } else if (ssv.at(0) == "r") {
                    // "#r#assets/player.png#0"
                    if (ssv.size() != 3) {
                        std::cout << str << std::endl;
                        //throw std::invalid_argument("not correct parameters for color replace");
                    }
                    std::string baseFileName = ssv.at(1);
                    sf::Image i {};
                    i.loadFromFile(baseFileName);

                    if (!m_selectiveColorReplace.empty()) {

                        auto idx = std::stoul(ssv.at(2));
                        if (!m_selectiveColorReplace.at(idx).empty()) {
                            for (unsigned int x = 0; x != i.getSize().x; ++x) {
                                for (unsigned int y = 0; y != i.getSize().y; ++y) {
                                    auto c = i.getPixel(x, y);
                                    for (auto const kvp : m_selectiveColorReplace.at(idx)) {
                                        if (c == kvp.first) {
                                            i.setPixel(x, y, kvp.second);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    m_textures[str].loadFromImage(i);
                } else {
                    throw std::invalid_argument("ERROR: cannot get texture with name " + str);
                }
            }

            sf::Image img { m_textures[str].copyToImage() };

            for (unsigned int i = 0; i != img.getSize().x; ++i)
                for (unsigned int j = 0; j != img.getSize().y; ++j) {
                    if (img.getPixel(i, j).a != 0) {
                        img.setPixel(i, j, sf::Color(255, 255, 255));
                    }
                }

            m_textures[getFlashName(str)].create(m_textures[str].getSize().x, m_textures[str].getSize().y);
            m_textures[getFlashName(str)].update(img);
        }

        return m_textures[str];
    }

    static std::string getFlashName(std::string str)
    {
        return str + "___flash__";
    }
    // This will chance all textures in m_textures and might thus not be revertible
    // Warning: due to slow copy process from graphics memory to ram and back to graphics this should not be called frequently!
    // Only works for textures obtained from this (not for colors of shapes or whatever)
    // \param in and out are used for lookups
    // if a color is used which is not contained in in, the color will be unchanged
    static void swapPalette(std::vector<sf::Color> in, std::vector<sf::Color> out)
    {
        assert(in.size() == out.size());
        for (auto& kvp : m_textures) {

            sf::Image img = kvp.second.copyToImage();

            for (unsigned i = 0; i != img.getSize().x; ++i)
                for (unsigned j = 0; j != img.getSize().x; ++j) {
                    auto col = img.getPixel(i, j);
                    // for this pixel check for each color in lookup
                    for (size_t idx = 0; idx != in.size(); ++idx) {
                        if (in[idx] == col) {
                            img.setPixel(i, j, out[idx]);
                            break;
                        }
                    }
                }
            kvp.second.loadFromImage(img);
        }
    }

    static bool isTextureLoaded(std::string filename)
    {
        return m_textures.count(filename) != 0;
    }

    static void addTexture(std::string name, sf::Texture& t)
    {
        m_textures[name] = (t);
    }

    static void addselectiveColorReplacement(int idx, std::vector<std::pair<sf::Color, sf::Color>> replace)
    {
        if (m_selectiveColorReplace.size() <= idx) {
            m_selectiveColorReplace.resize(idx + 1);
        }

        m_selectiveColorReplace.at(idx) = replace;
    }

private:
    static std::map<std::string, sf::Texture>
        m_textures;
    static std::vector<std::vector<std::pair<sf::Color, sf::Color>>> m_selectiveColorReplace;
};
} // namespace JamTemplate

#endif
