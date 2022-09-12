type ReplaceAll<S extends string, From extends string, To extends string> = S extends `${infer Prefix}${From}${infer Suffix}` ? ReplaceAll<`${Prefix}${To}${Suffix}`, From, To> : S

type replaced = ReplaceAll<'t y p e s', ' ', ''> // expected to be 'types'
