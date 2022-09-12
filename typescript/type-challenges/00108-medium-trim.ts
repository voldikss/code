type Trim<T extends string> = T extends ` ${infer Tail}`
  ? Trim<Tail>
  : T extends `${infer Head} `
  ? Trim<Head>
  : T

type trimmed = Trim<'  Hello World  '> // expected to be 'Hello World'

// better
type Trim2<T extends string> = T extends ` ${infer U}` | `${infer U} ` ? Trim2<U> : T
type trimmed2 = Trim2<'  Hello World  '> // expected to be 'Hello World'
