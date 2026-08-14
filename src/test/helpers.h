/* helpers.h */

#include <vector>
#include <Shapes.h>
#include <Block.h>

std::vector<Shape> to_vector_4(std::span<const Shape, 4> span);
std::vector<Shape> to_vector_4(Shape c, std::vector<uint8_t> s);
std::vector<Shape> to_vector_16(std::span<const Shape, 16> span);
std::vector<Shape> to_vector_16(Shape c, std::vector<uint8_t> s);
std::vector<uint16_t> to_vec(const Block* data, size_t length);
std::vector<uint16_t> to_vec(std::string str, Block value);
