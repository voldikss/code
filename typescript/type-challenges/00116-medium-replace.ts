type Replace<
  S extends string,
  From extends string,
  To extends string
> = S extends `${infer Prefix}${From}${infer Suffix}` ? `${Prefix}${To}${Suffix}` : S

type replaced = Replace<'types are fun!', 'fun', 'awesome'> // expected to be 'types are awesome!'
