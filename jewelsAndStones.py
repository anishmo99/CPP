class Solution(object):
def numJewelsInStones(self, J, S):
    """
    :type J: str
    :type S: str
    :rtype: int
    """
    c=0
    for i in range(len(S)):
        if S[i] in J:
            c+=1
    return c;
    
