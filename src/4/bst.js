class TreeNode {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class BSTree {
  constructor(data) {
    this.head = null;

    if (data) {
      data.forEach((item) => {
        this.insert(item);
      });
    }
  }

  insert(data) {
    let current = this.head;
    let previous = null;

    while (current) {
      previous = current;
      current = data < current.data ? current.left : current.right;
    }

    if (previous) {
      previous[data < previous.data ? "left" : "right"] = new TreeNode(data);
    } else {
      this.head = new TreeNode(data);
    }
  }

  traverse(process, node = this.head) {
    if (!node) {
      return;
    }

    this.traverse(process, node.left);
    process && process(node);
    this.traverse(process, node.right);
  }

  print() {
    this.traverse((node) => {
      console.log(node.data);
    });
  }

  height(node = this.head) {
    if (!node) {
      return 0;
    }

    const leftHeight = this.height(node.left);
    const rightHeight = this.height(node.right);
    return Math.max(leftHeight, rightHeight) + 1;
  }
}

module.exports = { BSTree };
