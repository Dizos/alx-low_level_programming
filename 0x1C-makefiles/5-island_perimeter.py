#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.

This module provides a function to determine the perimeter of an island
represented in a 2D grid where 1 represents land and 0 represents water.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island in the given grid.

    Args:
        grid (list of list of int): A rectangular grid representing land and water.
                                    1 represents land, 0 represents water.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0

    
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            
            if grid[r][c] == 1:
                
                
                if r == 0 or grid[r-1][c] == 0:
                    perimeter += 1
                
                if r == len(grid) - 1 or grid[r+1][c] == 0:
                    perimeter += 1
                
                if c == 0 or grid[r][c-1] == 0:
                    perimeter += 1
                
                if c == len(grid[0]) - 1 or grid[r][c+1] == 0:
                    perimeter += 1

    return perimeter
