class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        R, C = len(heights), len(heights[0])

        def reach(starts):
            seen = set(starts)
            stack = list(seen)
            while stack:
                r, c = stack.pop()
                for nr, nc in ((r+1, c), (r-1, c), (r, c+1), (r, c-1)):
                    if (0 <= nr < R and 0 <= nc < C and (nr, nc) not in seen
                            and heights[nr][nc] >= heights[r][c]):
                        seen.add((nr, nc))
                        stack.append((nr, nc))
            return seen

        pacific  = reach([(0, c) for c in range(C)] + [(r, 0) for r in range(R)])
        atlantic = reach([(R-1, c) for c in range(C)] + [(r, C-1) for r in range(R)])
        return [list(cell) for cell in pacific & atlantic]