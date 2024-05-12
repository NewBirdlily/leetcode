class Solution:
    def trans(self , s: str, n: int) -> str:
        if ' 'not in s:
            return s.swapcase()
        words =s.split(' ')
        words.reverse()
        transformed_words = [word.swapcase() for word in words]
        return ' '.join(transformed_words)


s1="This is a sample"
n=16
s=Solution()
print(s.trans(s1,n))