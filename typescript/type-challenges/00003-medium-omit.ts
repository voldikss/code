interface Todo {
  title: string
  description: string
  completed: boolean
}

type MyExclude<U, V> = U extends V ? never : U

type T = MyExclude<'a' | 'b', 'b'>

type MyOmit<T, K extends keyof T> = {
  [KK in MyExclude<keyof T, K>]: T[KK]
}

type MyOmit2<T, K extends keyof T> = {
  [KK in keyof T as KK extends K ? never : KK]: T[KK]
}

type TodoPreview = MyOmit<Todo, 'description' | 'title'>
type TodoPreview2 = MyOmit2<Todo, 'description' | 'title'>

const todo: TodoPreview = {
  completed: false,
}
