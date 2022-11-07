#ifndef COLOR_H
#define COLOR_H

#include "vec3.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Color write_color(color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(r * scale);
    g = sqrt(g * scale);
    b = sqrt(b * scale);

    r = static_cast<int>(256 * clamp(r, 0.0, 0.999));
    g = static_cast<int>(256 * clamp(g, 0.0, 0.999));
    b = static_cast<int>(256 * clamp(b, 0.0, 0.999));

    return sf::Color(r, g, b);
}

#endif
