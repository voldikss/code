type ExampleType = Promise<string>

type MyAwaited<T> = T extends Promise<infer U> ? U : never

type Result = MyAwaited<ExampleType> // string
