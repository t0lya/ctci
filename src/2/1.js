const { LinkedList } = require("./linked-list.js");

// O(n) space, O(n) time if 'seen' insert/search is O(1)
const removeDupes = (list) => {
  const seen = [];

  let previous = null;
  let current = list.head;
  while (current) {
    if (seen.includes(current.data)) {
      previous.next = current.next;
    } else {
      previous = current;
      seen.push(current.data);
    }

    current = current.next;
  }
};

// O(1) space, O(n^2) time
const removeDupes2 = (list) => {
  let currentStart = list.head;

  while (currentStart) {
    let current = currentStart.next;
    let previous = currentStart;

    while (current) {
      if (current.data === currentStart.data) {
        previous.next = current.next;
      } else {
        previous = current;
      }

      current = current.next;
    }

    currentStart = currentStart.next;
  }
};

const test = (arr, implementation) => {
  const list = new LinkedList(arr);
  list.print();
  implementation(list);
  list.print();
};

(() => {
  test([34, 51, 15, 34, 6, 6, 5, 34, 51, 4, 2, 34, 34], removeDupes);
  test([34, 51, 15, 34, 6, 6, 5, 34, 51, 4, 2, 34, 34], removeDupes2);
})();
