class TreeNode {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class Tree {
  constructor(data) {
    this.head = data !== undefined ? new TreeNode(data) : null;
  }

  insert(data, path = []) {
    if (path.length < 1) {
      return;
    }

    let current = this.head;
    let pathIndex = 0;
    while (pathIndex < path.length - 1) {
      if (!current) {
        return;
      }

      if (path[pathIndex] === 1) {
        current = current.right;
      } else {
        current = current.left;
      }

      pathIndex++;
    }

    if (path[path.length - 1] === 1) {
      current.right = new TreeNode(data);
    } else {
      current.left = new TreeNode(data);
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
}

module.exports = { Tree };
