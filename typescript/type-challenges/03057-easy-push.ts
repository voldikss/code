type Push<U extends unknown[], V> = [...U, V]

type Result = Push<[1, 2], '3'> // [1, 2, '3']
