# treenode.py
from __future__ import annotations

from collections import deque
from dataclasses import dataclass, field
from typing import Deque, Generic, List, Optional, Sequence, TypeVar

T = TypeVar("T")


@dataclass
class TreeNodeT(Generic[T]):
    val: T = 0  # default similar to C++ default ctor val(0)
    children: List["TreeNodeT[T]"] = field(default_factory=list)  # N-ary
    left: Optional["TreeNodeT[T]"] = None  # binary
    right: Optional["TreeNodeT[T]"] = None  # binary

    # ---- Constructors / factories ----
    @classmethod
    def from_value(cls, x: T) -> "TreeNodeT[T]":
        # Mirrors explicit TreeNodeT(int x) in spirit.
        return cls(val=x)

    @classmethod
    def from_children(
            cls,
            x: T,
            left: Optional["TreeNodeT[T]"] = None,
            right: Optional["TreeNodeT[T]"] = None,
    ) -> "TreeNodeT[T]":
        # Mirrors TreeNodeT(T x, TreeNodeT* left, TreeNodeT* right)
        return cls(val=x, left=left, right=right)

    @classmethod
    def from_level_order(cls, v: Sequence[Optional[T]]) -> Optional["TreeNodeT[T]"]:
        """
        Build a binary tree from a LeetCode-style level-order array where None means null.

        Matches your C++ ctor behavior closely:
        - v[0] must be not-None to create a root
        - then consumes pairs (left, right) while popping parents in BFS order
        """
        if not v:
            return None
        if v[0] is None:
            return None

        root = cls(val=v[0])
        q: Deque[TreeNodeT[T]] = deque([root])

        i = 1
        while q and i < len(v):
            node = q.popleft()

            # left
            if i < len(v) and v[i] is not None:
                node.left = cls(val=v[i])
                q.append(node.left)
            i += 1

            # right
            if i < len(v) and v[i] is not None:
                node.right = cls(val=v[i])
                q.append(node.right)
            i += 1

        return root

    # ---- Pretty print (binary) ----
    def print(self, prefix: str = "", is_left: bool = True) -> None:
        """
        Prints the binary tree using the same convention as your C++ version:
        - current node prints with either "├──" or "└──"
        - recurses left then right
        - prints explicit "nullptr"/None placeholders when a child is missing but the other exists
        """
        print(prefix + ("├──" if is_left else "└──") + str(self.val))

        if self.left is None and self.right is None:
            return

        child_prefix = prefix + ("│  " if is_left else "   ")

        if self.left is not None:
            self.left.print(child_prefix, True)
        else:
            # match your formatting: prefix + "   ├──nullptr"
            print(prefix + "   ├──nullptr")

        if self.right is not None:
            self.right.print(child_prefix, False)
        else:
            print(prefix + "   └──nullptr")

    @staticmethod
    def print_opt_vec(vec: Sequence[Optional[T]]) -> str:
        # Mirrors your C++ output style: "[x, null, y, ]"
        ret = "["
        for x in vec:
            ret += (str(x) if x is not None else "null") + ", "
        ret += "]"
        return ret

    @staticmethod
    def print_vec_vec(vecs: Sequence[Sequence[T]]) -> str:
        # Mirrors your C++ output style: "[[1, 2, ],[3, ],]"
        ret = "["
        for vec in vecs:
            ret += "["
            for x in vec:
                ret += str(x) + ", "
            ret += "],"
        ret += "]"
        return ret


# Convenience alias like `using TreeNode = TreeNodeT<int>;`
TreeNode = TreeNodeT[int]

if __name__ == "__main__":
    # Example usage (binary)
    root = TreeNode.from_level_order([1, 2, 3, None, 5])
    if root:
        root.print()
        print()

    # it will still run, but your static analysis may warn about this usage
    root = TreeNodeT[int]("asdf")
    if root:
        root.print()
        print()

    # Example usage of print helpers
    print(TreeNode.print_opt_vec([1, None, 3]))
    print(TreeNode.print_vec_vec([[1, 2], [3]]))
