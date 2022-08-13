type arr1 = ['a', 'b', 'c']
type arr2 = [3, 2, 1]

type Last<T extends unknown[]> = T extends [...any, infer TT] ? TT : never
type Last2<T extends unknown[]> = [any, ...T][T['length']]

type tail1 = Last<arr1> // expected to be 'c'
type tail2 = Last<arr2> // expected to be 1

// type tail1 = Last2<arr1> // expected to be 'c'
// type tail2 = Last2<arr2> // expected to be 1

