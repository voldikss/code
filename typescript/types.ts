/** No `never` keys */
type NoNeverKeys<T> = {
  [Key in keyof T]: T[Key] extends never ? never : Key
}[keyof T]
// type Test = NoNeverKeys<{
//   a: never
//   b: string
//   c: () => number
// }>
