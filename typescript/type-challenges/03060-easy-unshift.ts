type Unshift<U extends unknown[], V> = [V, ...U]

type Result = Unshift<[1, 2], 0> // [0, 1, 2,]
