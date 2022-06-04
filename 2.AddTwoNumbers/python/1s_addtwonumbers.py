from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def addNode(l: ListNode, v: int) -> ListNode:
    """
    Sets the next node for l.
    """
    node = ListNode(v)
    l.next = node
    return l


def printListNode(l: ListNode) -> None:
    node = l
    while node is not None:
        print(node.val, end=" -> ")
        node = node.next
    print("None")


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        Adds two ListNodes and returns the result as a ListNode.
        """
        result = ListNode(0)
        node = result
        carry = 0
        while True:
            if not l1 is None:
                x = l1.val
                l1 = l1.next
                l1_n = True
            else:
                x = 0
                l1_n = False
            if not l2 is None:
                y = l2.val
                l2 = l2.next
                l2_n = True
            else:
                y = 0
                l2_n = False
            res = x + y + carry
            if res == 0 and not l1_n and not l2_n:
                return result.next
            if res > 9:
                res = res % 10
                carry = 1
            else:
                carry = 0

            addNode(node, res)
            node = node.next


def genExamples() -> List[ListNode]:
    l1 = ListNode(3)
    l2 = ListNode(4)
    l3 = ListNode(2)
    l2.next = l1
    l3.next = l2
    r1 = ListNode(4)
    r2 = ListNode(6)
    r3 = ListNode(5)
    r2.next = r1
    r3.next = r2
    return [r3, l3]


def main():
    solution = Solution()
    examples = genExamples()
    result = solution.addTwoNumbers(examples[0], examples[1])
    print('  ', end='')
    printListNode(examples[0])
    print('+ ', end='')
    printListNode(examples[1])
    print('= ', end='')
    printListNode(result)


if __name__ == "__main__":
    main()
