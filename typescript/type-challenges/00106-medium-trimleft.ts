type TrimLeft<T extends string> = T extends ` ${infer Tail}` ? TrimLeft<Tail> : T

type trimed = TrimLeft<'  Hello World  '> // expected to be 'Hello World  '
