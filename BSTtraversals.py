def inOrderTraverse(tree, array):
    # Write your code here.
    if tree:
        inOrderTraverse(tree.left,array)
        array.append(tree.value)
        inOrderTraverse(tree.right, array)
    return array

def preOrderTraverse(tree, array):
    # Write your code here.
    stack = []
    discovered = {}
    stack.append(tree)
    while len(stack) > 0:
        current = stack.pop()
        #print(current.value)
        array.append(current.value)
        if current not in discovered.keys():
            discovered[current] = True
        if current.right not in discovered.keys() and current.right != None:
            stack.append(current.right)
        if current.left not in discovered.keys() and current.left != None:
            stack.append(current.left)
    return array


def postOrderTraverse(tree, array):
    # Write your code here.
    if tree is not None:
        postOrderTraverse(tree.left, array)
        postOrderTraverse(tree.right, array)
        array.append(tree.value)
    return array
