interface Todo {
  title: string
  description: string
  completed: boolean
}

type MyReadonly2<T, K extends keyof T> = Flatterned<
  Omit<T, K> & {
    readonly [KK in K]: T[KK]
  }
>

const todo: MyReadonly2<Todo, 'title' | 'description'> = {
  title: 'Hey',
  description: 'foobar',
  completed: false,
}

todo.title = 'Hello' // Error: cannot reassign a readonly property
todo.description = 'barFoo' // Error: cannot reassign a readonly property
todo.completed = true // OK

type A = {a: number} & {b: boolean}
type T = keyof A
type Flatterned<A> = {[K in keyof A]: A[K]}

type TT1 = {
  readonly x: string
} & {
  x: string
}

type TT2 = {
  x: string
} & {
  readonly x: string
}

let tt1: TT1 = {x: ''}
tt1.x = ''
let tt2: TT2 = {x: ''}
tt2.x = ''
