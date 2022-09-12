type Capitalize2<S extends string> = S extends `${infer Head}${infer Tail}` ? `${Uppercase<Head>}${Tail}` : S

type capitalized = Capitalize2<'hello world'> // expected to be 'Hello world'
