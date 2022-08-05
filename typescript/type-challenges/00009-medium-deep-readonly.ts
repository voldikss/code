type X = {
  x: {
    a: 1
    b: 'hi'
  }
  y: 'hey'
}

type Expected = {
  readonly x: {
    readonly a: 1
    readonly b: 'hi'
  }
  readonly y: 'hey'
}

type DeepReadonly<T extends Record<string, unknown>> = {
  readonly [K in keyof T]: T[K] extends Record<string, unknown>
    ? DeepReadonly<T[K]>
    : T[K]
}

type DeepReadonly2<T> = keyof T extends never ? T : {
  readonly [K in keyof T]: DeepReadonly2<T[K]>
}

type Todo = DeepReadonly<X> // should be same as `Expected`
let t: Todo
t.x.a = 0

type Todo2 = DeepReadonly2<X>
let t2:Todo2
t2.x.a = 0
