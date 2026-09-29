class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()


    def addWord(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.children:
                curr.children[char] = TrieNode()
            
            curr = curr.children[char]
        curr.is_end_of_word = True

    def search(self, word: str) -> bool:
        #dfs to handle '.'
        def dfs(index, node):
            curr = node
            #iterate through the characters of the word. if it is '.' then move to the bottom layer (call dfs on i+1). otherwise, continue searching
            for i in range(index, len(word)):
                char = word[i]
        
                if (char == '.'):
                    #the next char can be anything
                    for child in curr.children.values():
                        if dfs(i+1, child):
                            return True

                    return False
                
                else:
                    if char not in curr.children:
                        return False
                    else:
                        curr = curr.children[char]


            return curr.is_end_of_word
        return dfs(0, self.root)





