const foo = (arg1: string, arg2: number): void => {}

type MyParameters<T> = T extends (...args: infer A) => unknown ? A : never

type FunctionParamsType = MyParameters<typeof foo> // [arg1: string, arg2: number]
