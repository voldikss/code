interface Cat {
  type: 'cat'
  breeds: 'Abyssinian' | 'Shorthair' | 'Curl' | 'Bengal'
}

interface Dog {
  type: 'dog'
  breeds: 'Hound' | 'Brittany' | 'Bulldog' | 'Boxer'
  color: 'brown' | 'white' | 'black'
}

// not work
// type LookUp<T extends {type: string}, K extends string> = T['type'] extends K
//   ? T
//   : never

type LookUp<T extends {type: string}, K extends T['type']> = T extends {type: K}
  ? T
  : never

type MyDogType = LookUp<Cat | Dog, 'dog'> // expected to be `Dog`
