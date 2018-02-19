#pragma once

#include <optional>
#include <vector>

/// This class responsibility is to store the game board.
/// It's stupid in the sense that it doesn't make any checks
/// or provide any invariants.
///
/// \tparam ElementType Type of the elements stored in board cells.
template<class ElementType>
class Board {
public:
    /// Creates an empty board with specified sizes
    Board(size_t height, size_t width);
    /// Returns width of the board
    /// \sa getHeight
    size_t getWidth() const;
    /// Returns height of the board
    /// \sa getWidth
    size_t getHeight() const;
    /// Returns element stored in the cell (x, y)
    /// \param x number of the row
    /// \param y number of the column
    std::optional<ElementType>& operator[](size_t x, size_t y);
    /// Returns element stored in the cell (x, y)
    /// \param x number of the row
    /// \param y number of the column
    const std::optional<ElementType>& operator[](size_t x, size_t y) const;

private:
    /// The board itself
    std::vector<std::vector<ElementType>> data;
};

template<class ElementType>
Board::Board(size_t height, size_t width) {
    data.resize(height);
    for (auto& row : data) {
        row.resize(width);
    }
}

template<class ElementType>
size_t Board::getHeight() const {
    return data.size();
}

template<class ElementType>
std::optional<ElementType>& Board<ElementType>::operator[](size_t x, size_t y)
{
    return data[x][y];
}

template<class ElementType>
const std::optional<ElementType>& Board<ElementType>::operator[](size_t x, size_t y) const
{
    return data[x][y];
}

template<class ElementType>
size_t Board::getWidth() const {
    return data[0].size();
}
