class ListNode {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor(dataArray) {
    this.head = new ListNode(dataArray && dataArray.length ? dataArray[0] : 0);

    let previous = this.head;
    let current = null;
    for (let i = 1; i < dataArray.length; i++) {
      current = new ListNode(dataArray[i]);
      previous.next = current;
      previous = current;
    }
  }

  print() {
    let current = this.head;
    let list = [];
    while (current) {
      list.push(current.data);
      current = current.next;
    }

    console.log(list);
  }
}

module.exports = { LinkedList };
