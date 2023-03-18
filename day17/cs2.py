class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        ts=sum(candidates)
        def perm(arr,candidates,target,s,start_idx,cs):
            if s == target:
                if arr not in res:
                    res.append(arr.copy())
                return
            if s+ts-cs < target:
                return
            s2 = 0
            lc = float('inf')
            for i in range(start_idx,len(candidates)):
                s2 += candidates[i]
                if s + candidates[i] <= target and lc != candidates[i]:
                    arr.append(candidates[i])
                    perm(arr,candidates,target,s+candidates[i],i+1,cs+s2)
                    arr.pop()
                    lc = candidates[i]
        candidates.sort()
        perm([],candidates,target,0,0,0)        
        return res
