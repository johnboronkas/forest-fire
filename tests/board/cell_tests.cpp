#include "tests/catch.hpp"

#include <limits.h>

#include "src/board/cell.h"

TEST_CASE("Cell")
{
    SECTION("handles min parameters correctly")
    {
        Cell cellMin(0, 0);
        REQUIRE(cellMin.getX() == 0);
        REQUIRE(cellMin.getY() == 0);
    }

    SECTION("handles max parameters correctly")
    {
        Cell cellMax(USHRT_MAX, USHRT_MAX);
        REQUIRE(cellMax.getX() == USHRT_MAX);
        REQUIRE(cellMax.getY() == USHRT_MAX);
    }

    SECTION("handles random (valid) parameters correctly")
    {
        Cell cellRand(12345, 63452);
        REQUIRE(cellRand.getX() == 12345);
        REQUIRE(cellRand.getY() == 63452);
    }

    SECTION("cellState defaults to CellState::Empty")
    {
        Cell cell(0, 0);
        REQUIRE(cell.getCellState() == CellState::Empty);
    }

    SECTION("get/set cell state operates correctly")
    {
        Cell cell(0, 0);

        cell.setCellState(CellState::Tree);
        REQUIRE(cell.getCellState() == CellState::Tree);

        cell.setCellState(CellState::Fire);
        REQUIRE(cell.getCellState() == CellState::Fire);

        // Setting the same CellState twice doesn't cause issues?
        cell.setCellState(CellState::Fire);
        REQUIRE(cell.getCellState() == CellState::Fire);

        cell.setCellState(CellState::Empty);
        REQUIRE(cell.getCellState() == CellState::Empty);
    }
}
