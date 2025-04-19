# Leetcode-1203.-Sort-Items-by-Groups-Respecting-Dependencies
# Sort Items by Groups Respecting Dependencies

This repository contains a solution to the problem of sorting items with interdependencies, while respecting group boundaries. The challenge is commonly encountered in task scheduling and dependency resolution scenarios, especially when grouping constraints are involved.

## Problem Statement

You are given `n` items labeled from `0` to `n - 1` and an array `group` where `group[i]` is the group that the `i-th` item belongs to. Items with the same group must be adjacent in the final sorted list.

You're also given a list of dependencies, where `beforeItems[i]` is a list of items that must come before item `i`.

Your goal is to return any sorted list of the items that satisfies the following conditions:
- The items are sorted such that each item appears after all the items in its `beforeItems` list.
- Items that belong to the same group must appear together.

## Key Concepts
- **Topological Sort**: Used to sort items based on dependency graphs.
- **Graph Construction**: One graph for individual items, and another for groups.
- **Cycle Detection**: If a topological sort fails, it means there is a cycle and a valid ordering is not possible.

## Approach

1. **Assign Groups**: If any item doesn't belong to a group (`group[i] == -1`), assign it a new unique group ID.
2. **Create Two Graphs**:
   - One for individual item dependencies.
   - One for group dependencies, based on item dependencies across groups.
3. **Topological Sort**:
   - Perform a topological sort on the group graph to determine group order.
   - Perform another topological sort on the item graph to determine the order of items.
4. **Assemble Output**:
   - Using the individual item order, map items to their respective groups.
   - Arrange groups according to group topological order and concatenate items accordingly.

## Code Summary
- `topological()` function: Returns a topological ordering for a directed graph represented by an adjacency list.
- `sortItems()` function: Coordinates the overall sorting logic by applying topological sorts and assembling the final result.

## Time & Space Complexity
- **Time Complexity**: `O(N + E)`, where `N` is the number of items and `E` is the number of dependencies.
- **Space Complexity**: `O(N + E)` for storing graphs and intermediate results.

## Example
```cpp
Input:
n = 8, m = 2,
group = [-1,-1,1,0,0,1,0,-1],
beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]

Output:
[6,3,4,5,2,0,7,1] (one possible valid order)
```

## Applications
- Build systems with module dependencies
- Task scheduling with grouped resource constraints
- Course prerequisite planning



## License
This project is open-source and free to use.
