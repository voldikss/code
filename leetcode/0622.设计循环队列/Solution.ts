class MyCircularQueue {
  private buffer: number[]
  private pHead: number
  private pTail: number

  private equalCause: 'full' | 'empty'

  constructor(k: number) {
    this.buffer = new Array(k)
    this.pHead = 0
    this.pTail = 0
    this.equalCause = 'empty'
  }

  enQueue(value: number): boolean {
    if (this.isFull()) return false
    this.buffer[this.pHead++] = value
    this.pHead %= this.buffer.length
    console.log('pHead', this.pHead)
    if (this.pHead === this.pTail) {
      this.equalCause = 'full'
    }
    return true
  }

  deQueue(): boolean {
    if (this.isEmpty()) return false
    this.pTail++
    this.pTail %= this.buffer.length
    if (this.pTail === this.pHead) {
      this.equalCause = 'empty'
    }
    return true
  }

  Front(): number {
    if (this.isEmpty()) return -1
    return this.buffer[this.pTail]
  }

  Rear(): number {
    if (this.isEmpty()) return -1
    // console.log(this.buffer)
    return this.buffer[(this.pHead - 1 + this.buffer.length) % this.buffer.length]
  }

  isEmpty(): boolean {
    return this.pHead === this.pTail && this.equalCause === 'empty'
  }

  isFull(): boolean {
    return this.pHead === this.pTail && this.equalCause === 'full'
  }
}
