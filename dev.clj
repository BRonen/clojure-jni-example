(ns dev
  (:import [Accumulator Acc]))

(def acc (Acc.))

(comment

  (.accumulate acc 1)

  (.getValue acc)

  nil)
