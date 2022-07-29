type Concat<U extends unknown[], V extends unknown[]> = [...U, ...V]

type Result = Concat<[1], [2]> // expected to be [1, 2]
